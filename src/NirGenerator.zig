const std = @import("std");
const tst = std.testing;

const nir = @import("Nir.zig");
const SymbolTable = @import("SymbolTable.zig").SymbolTable;

const ts = @cImport(@cInclude("tree_sitter/api.h"));

var f_ident: ts.TSFieldId = undefined;
var f_expr: ts.TSFieldId = undefined;
var f_number: ts.TSFieldId = undefined;
var f_def: ts.TSFieldId = undefined;
var f_let_in: ts.TSFieldId = undefined;

const ParseError = error{
    InvalidSource,
};

extern fn tree_sitter_necha() *const ts.TSLanguage;

const Context = struct {
    code: std.ArrayList(nir.Instr),
    table: SymbolTable,
};

fn setFieldIds() void {
    f_ident = ts.ts_language_field_id_for_name(tree_sitter_necha(), "ident", "ident".len);
    f_expr = ts.ts_language_field_id_for_name(tree_sitter_necha(), "expr", "expr".len);
    f_number = ts.ts_language_field_id_for_name(tree_sitter_necha(), "number", "number".len);
    f_def = ts.ts_language_field_id_for_name(tree_sitter_necha(), "def", "def".len);
    f_let_in = ts.ts_language_field_id_for_name(tree_sitter_necha(), "let_in", "let_in".len);
}

fn getNodeName(node: ts.TSNode, source: []const u8) []const u8 {
    const start = ts.ts_node_start_byte(node);
    const end = ts.ts_node_end_byte(node);
    return source[start..end];
}

const Generator = struct {
    const Self = @This();

    instructions: std.ArrayList(nir.Instr),
    table: SymbolTable,
    cursor: ts.TSTreeCursor,
    source: []const u8,

    pub fn run(self: *Self) !void {
        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const node = ts.ts_tree_cursor_current_node(&self.cursor);
            const node_type = ts.ts_node_type(node);
            if (std.mem.eql(u8, std.mem.span(node_type), "ERROR")) {
                unreachable;
            } else if (std.mem.eql(u8, std.mem.span(node_type), "let_expr")) {
                try self.let_root();
            } else {
                std.debug.print("other !\n", .{});
            }
        }
    }

    pub fn let_root(self: *Self) !void {
        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == f_def) {
                try self.def();
                std.debug.print("--- \n", .{});
            } else {
                const name = getNodeName(ts.ts_tree_cursor_current_node(&self.cursor), self.source);
                std.debug.print(")) keywords {s}\n", .{name});
            }
        }
    }

    pub fn def(self: *Self) !void {
        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        var name: ?[]const u8 = null;
        var ip: usize = undefined;
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (field_id > 0) {
                if (name) |n| {
                    ip = try self.expr(field_id);
                    try self.table.put(n, ip, true);
                    _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
                    return;
                } else {
                    name = getNodeName(
                        ts.ts_tree_cursor_current_node(&self.cursor),
                        self.source,
                    );
                }
            }
        }
    }

    pub fn expr(self: *Self, field_id: u64) !usize {
        if (field_id == f_number) {
            const num_str = getNodeName(
                ts.ts_tree_cursor_current_node(&self.cursor),
                self.source,
            );
            const result = std.zig.parseNumberLiteral(num_str);
            switch (result) {
                .int => |n| {
                    try self.instructions.append(.{ .number = n });
                },
                else => unreachable,
            }
        } else if (field_id == f_ident) {
            try self.instructions.append(.{ .number = 22 });
        } else if (field_id == f_let_in) {
            try self.instructions.append(.{ .number = 33 });
        } else {
            try self.instructions.append(.{ .number = 11 });
        }

        return self.instructions.items.len - 1;
    }

    pub fn deinit(self: *Self) void {
        ts.ts_tree_cursor_delete(&self.cursor);
    }
};

pub fn genOwnedCtx(allocator: std.mem.Allocator, src: []const u8) !Context {
    setFieldIds();
    var parser = ts.ts_parser_new().?;
    defer ts.ts_parser_delete(parser);
    _ = ts.ts_parser_set_language(parser, tree_sitter_necha());

    var tree = ts.ts_parser_parse_string(
        parser,
        null,
        src.ptr,
        @intCast(u32, src.len),
    ).?;
    defer ts.ts_tree_delete(tree);

    var root_node = ts.ts_tree_root_node(tree);
    const root_node_type = ts.ts_node_type(root_node);

    if (!std.mem.eql(u8, "source_file", std.mem.span(root_node_type)))
        return ParseError.InvalidSource;

    var generator = Generator{
        .instructions = std.ArrayList(nir.Instr).init(allocator),
        .table = try SymbolTable.init(allocator, 1024),
        .cursor = ts.ts_tree_cursor_new(root_node),
        .source = src,
    };
    defer ts.ts_tree_cursor_delete(&generator.cursor);

    try generator.run();

    return .{
        .code = generator.instructions,
        .table = generator.table,
    };
}

test "generator" {
    const source =
        \\ let main =
        \\   let a = 2
        \\   and b = 10
        \\   in  mul a b
    ;

    std.debug.print("\n", .{});
    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.code.deinit();
    defer ctx.table.deinit();

    const str = try nir.toString(tst.allocator, ctx.code.items);
    defer tst.allocator.free(str);

    std.debug.print("{s}\n", .{str});
    const a = ctx.table.get("main").?;

    std.debug.print("{d} \n", .{a.ins});
    try tst.expectEqual(a.ins, 0);
}
