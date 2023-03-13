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
var f_fn_call: ts.TSFieldId = undefined;
var f_function: ts.TSFieldId = undefined;

const ParseError = error{
    InvalidSource,
    OutOfMemory,
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
    f_fn_call = ts.ts_language_field_id_for_name(tree_sitter_necha(), "fn_call", "fn_call".len);
    f_function = ts.ts_language_field_id_for_name(tree_sitter_necha(), "function", "function".len);
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
                _ = try self.let_root();
            } else {
                std.debug.print("other !\n", .{});
            }
        }
    }

    pub fn let_root(self: *Self) ParseError!usize {
        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == f_def) {
                try self.def();
            } else if (field_id > 0 and field_id != f_def) {
                return try self.expr(field_id);
            } else {
                const name = getNodeName(ts.ts_tree_cursor_current_node(&self.cursor), self.source);
                std.debug.print("keywords {s}\n", .{name});
            }
        }
        return 0;
    }

    pub fn def(self: *Self) ParseError!void {
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

    pub fn expr(self: *Self, field_id: u64) ParseError!usize {
        const src = try nir.toString(self.instructions.allocator, self.instructions.items, self.source);
        defer self.instructions.allocator.free(src);

        const current = ts.ts_tree_cursor_current_node(&self.cursor);

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
            const name = getNodeName(
                current,
                self.source,
            );
            const r = self.table.get(name);
            if (r) |reg| {
                return reg.ins;
            } else {
                const s = ts.ts_node_start_byte(
                    current,
                );

                const e = ts.ts_node_end_byte(
                    current,
                );
                try self.instructions.append(
                    .{ .undef = .{ .start = s, .end = e } },
                );
            }
        } else if (field_id == f_let_in) {
            try self.table.push();
            const r = try self.let_root();
            try self.table.pop();
            return r;
        } else if (field_id == f_fn_call) {
            try self.instructions.append(.{ .begin_call = .{ .end = 0 } });
            const begin = self.instructions.items.len - 1;

            var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
            // TODO: ummm..
            const function: u64 = try self.expr(f_ident);

            cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor);
            while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
                const id = ts.ts_tree_cursor_current_field_id(&self.cursor);
                if (id > 0) {
                    std.debug.print("LL {d}\n", .{id});
                    const i = try self.expr(id);
                    try self.instructions.append(.{ .push_param = .{ .reg = i } });
                }
            }
            try self.instructions.append(.{ .call = .{ .reg = function } });
            self.instructions.items[begin] = .{ .begin_call = .{ .end = self.instructions.items.len - 1 } };
        } else {
            try self.instructions.append(.{ .number = 11 });
        }

        return self.instructions.items.len - 1;
    }

    pub fn fn_call(self: *Self) ParseError!void {
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
        \\   and mul = 10
        \\   in  mul a b
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.code.deinit();
    defer ctx.table.deinit();

    const str = try nir.toString(tst.allocator, ctx.code.items, source);
    defer tst.allocator.free(str);

    std.debug.print("{s}\n", .{str});
    const main = ctx.table.get("main").?;
    try tst.expectEqual(main.ins, 8);
}
