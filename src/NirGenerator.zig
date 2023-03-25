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
var f_calc: ts.TSFieldId = undefined;
var f_mul: ts.TSFieldId = undefined;
var f_add: ts.TSFieldId = undefined;
var f_arg: ts.TSFieldId = undefined;

const ParseError = error{
    InvalidSource,
    OutOfMemory,
};

extern fn tree_sitter_necha() *const ts.TSLanguage;

const Context = struct {
    const Self = @This();

    code: std.ArrayList(nir.Instr),
    table: SymbolTable,

    fn deinit(self: *Self) void {
        self.code.deinit();
        self.table.deinit();
    }
};

fn setFieldIds() void {
    f_ident = ts.ts_language_field_id_for_name(tree_sitter_necha(), "ident", "ident".len);
    f_expr = ts.ts_language_field_id_for_name(tree_sitter_necha(), "expr", "expr".len);
    f_number = ts.ts_language_field_id_for_name(tree_sitter_necha(), "number", "number".len);
    f_def = ts.ts_language_field_id_for_name(tree_sitter_necha(), "def", "def".len);
    f_let_in = ts.ts_language_field_id_for_name(tree_sitter_necha(), "let_in", "let_in".len);
    f_fn_call = ts.ts_language_field_id_for_name(tree_sitter_necha(), "fn_call", "fn_call".len);
    f_function = ts.ts_language_field_id_for_name(tree_sitter_necha(), "function", "function".len);
    f_calc = ts.ts_language_field_id_for_name(tree_sitter_necha(), "calc", "calc".len);
    f_mul = ts.ts_language_field_id_for_name(tree_sitter_necha(), "mul", "mul".len);
    f_add = ts.ts_language_field_id_for_name(tree_sitter_necha(), "add", "add".len);
    f_arg = ts.ts_language_field_id_for_name(tree_sitter_necha(), "arg", "arg".len);
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

    fn let_root(self: *Self) ParseError!usize {
        _ = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        var cursor_moved = true;
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (field_id == f_def) {
                try self.def();
            } else if (field_id > 0) {
                return try self.expr();
            } else {
                const name = getNodeName(ts.ts_tree_cursor_current_node(&self.cursor), self.source);
                std.debug.print("Keyword : {s} \n", .{name});
            }
        }
        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return 0;
    }

    fn let_in(self: *Self) ParseError!usize {
        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (field_id == f_def) {
                try self.def();
            } else if (field_id > 0 and field_id != f_def) {
                _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
                return try self.expr();
            } else {
                const name = getNodeName(ts.ts_tree_cursor_current_node(&self.cursor), self.source);
                std.debug.print("keywords {s}\n", .{name});
            }
        }

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return 0;
    }

    fn def(self: *Self) ParseError!void {
        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        var name: ?[]const u8 = null;
        var ip: usize = undefined;
        var field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (field_id > 0) {
                if (name) |n| {
                    ip = try self.expr();
                    try self.table.put(n, ip, true);
                    _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
                    return;
                } else {
                    name = getNodeName(ts.ts_tree_cursor_current_node(&self.cursor), self.source);
                }
            }
            //            else {
            //                var unk = getNodeName(ts.ts_tree_cursor_current_node(&self.cursor), self.source);
            //                std.debug.print("{s}\n", .{unk});
            //            }
        }
    }

    fn number(self: *Self) !usize {
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
        return self.instructions.items.len - 1;
    }

    fn ident(self: *Self) !usize {
        const current = ts.ts_tree_cursor_current_node(&self.cursor);
        const name = getNodeName(
            current,
            self.source,
        );
        const r = self.table.get(name);
        if (r) |reg| {
            return reg.ins;
        } else {
            return try self.insert_undef();
        }
    }

    fn expr(self: *Self) ParseError!usize {
        const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

        if (field_id == f_number) {
            return try self.number();
        } else if (field_id == f_ident) {
            return try self.ident();
        } else if (field_id == f_let_in) {
            try self.table.push();
            const r = try self.let_in();
            try self.table.pop();
            return r;
        } else if (field_id == f_calc) {
            return try self.calc();
        } else if (field_id == f_fn_call) {
            return try self.fn_call();
        } else {
            return try self.insert_undef();
        }
    }

    fn calc(self: *Self) ParseError!usize {
        if (!ts.ts_tree_cursor_goto_first_child(&self.cursor)) {
            return ParseError.InvalidSource;
        }
        const op_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

        var moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor);
        if (!moved) return ParseError.InvalidSource;

        var lhs = try self.expr();

        moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor);
        if (!moved) return ParseError.InvalidSource;

        var rhs = try self.expr();

        if (op_id == f_mul) {
            try self.instructions.append(.{ .mul = .{ .lhs = lhs, .rhs = rhs } });
        } else {
            try self.instructions.append(.{ .add = .{ .lhs = lhs, .rhs = rhs } });
        }
        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.instructions.items.len - 1;
    }

    fn fn_call(self: *Self) ParseError!u64 {
        try self.instructions.append(.{ .begin_call = .{ .end = 0 } });
        const begin = self.instructions.items.len - 1;

        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        // TODO: ummm..
        const function: u64 = try self.expr();

        var id = ts.ts_tree_cursor_current_field_id(&self.cursor);

        cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor);
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (id > 0) {
                const i = try self.expr();
                try self.instructions.append(.{ .push_param = .{ .reg = i } });
            }
        }
        try self.instructions.append(.{ .call = .{ .reg = function } });
        self.instructions.items[begin] = .{ .begin_call = .{ .end = self.instructions.items.len - 1 } };
        return begin;
    }

    pub fn insert_undef(self: *Self) !usize {
        const current = ts.ts_tree_cursor_current_node(&self.cursor);
        const s = ts.ts_node_start_byte(current);
        const e = ts.ts_node_end_byte(current);

        try self.instructions.append(.{ .undef = .{ .start = s, .end = e } });
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

fn printFieldIds() void {
    std.debug.print("f_ident {d}\n", .{f_ident});
    std.debug.print("f_expr {d}\n", .{f_expr});
    std.debug.print("f_number {d}\n", .{f_number});
    std.debug.print("f_def {d}\n", .{f_def});
    std.debug.print("f_let_in {d}\n", .{f_let_in});
    std.debug.print("f_fn_call {d}\n", .{f_fn_call});
    std.debug.print("f_function {d}\n", .{f_function});
    std.debug.print("f_calc {d}\n", .{f_calc});
    std.debug.print("f_mul {d}\n", .{f_mul});
    std.debug.print("f_add {d}\n", .{f_add});
    std.debug.print("f_arg {d}\n", .{f_arg});
}

fn printSource(instr: []const nir.Instr, source: ?[]const u8) !void {
    const src = try nir.toString(tst.allocator, instr, source);
    defer tst.allocator.free(src);
    std.debug.print("\n--\n{s}--\n", .{src});
}

test "root let number" {
    const source =
        \\ let main = 1
    ;
    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const main = ctx.table.get("main").?;
    const ins = ctx.code.items[0];

    try tst.expectEqual(@intCast(u64, 1), ctx.code.items.len);
    try tst.expectEqual(@intCast(u64, 1), ins.number);
    try tst.expectEqual(@intCast(u64, 0), main.ins);
}

test "multiple root let" {
    const source =
        \\ let two = 2
        \\ let main = two
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const main = ctx.table.get("main").?;
    const two = ctx.table.get("main").?;
    const ins = ctx.code.items[0];

    try tst.expectEqual(@intCast(u64, 1), ctx.code.items.len);
    try tst.expectEqual(@intCast(u64, 2), ins.number);
    try tst.expectEqual(@intCast(u64, 0), main.ins);
    try tst.expectEqual(@intCast(u64, 0), two.ins);
}

test "let root with ands" {
    const source =
        \\ let two = 2
        \\ and main = two
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const main = ctx.table.get("main").?;
    const two = ctx.table.get("two").?;
    const ins = ctx.code.items[0];

    try tst.expectEqual(@intCast(u64, 1), ctx.code.items.len);
    try tst.expectEqual(@intCast(u64, 2), ins.number);
    try tst.expectEqual(@intCast(u64, 0), main.ins);
    try tst.expectEqual(@intCast(u64, 0), two.ins);
}

test "let ands and roots" {
    const source =
        \\ let two = 2
        \\
        \\ let also_two = two
        \\ and main = also_two
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const main = ctx.table.get("main").?;
    const two = ctx.table.get("two").?;
    const also_two = ctx.table.get("also_two").?;
    const ins = ctx.code.items[0];

    try tst.expectEqual(@intCast(u64, 1), ctx.code.items.len);
    try tst.expectEqual(@intCast(u64, 2), ins.number);
    try tst.expectEqual(@intCast(u64, 0), main.ins);
    try tst.expectEqual(@intCast(u64, 0), two.ins);
    try tst.expectEqual(@intCast(u64, 0), also_two.ins);
}

test "calc expr" {
    const source =
        \\ let main = + 1 3
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const main = ctx.table.get("main").?;
    const one = ctx.code.items[0];
    const three = ctx.code.items[1];
    const add = ctx.code.items[2];

    try tst.expectEqual(@intCast(u64, 3), ctx.code.items.len);

    try tst.expectEqual(@intCast(u64, 1), one.number);
    try tst.expectEqual(@intCast(u64, 3), three.number);

    try tst.expectEqual(@intCast(u64, 0), add.add.lhs);
    try tst.expectEqual(@intCast(u64, 1), add.add.rhs);

    try tst.expectEqual(@intCast(u64, 2), main.ins);
}

test "calc #2" {
    const source =
        \\ let a = 3
        \\
        \\ let b = 2
        \\ and main = * a b
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const main = ctx.table.get("main").?;
    const na = ctx.table.get("a").?;
    const nb = ctx.table.get("b").?;

    const a = ctx.code.items[0];
    const b = ctx.code.items[1];
    const mul = ctx.code.items[2];

    try tst.expectEqual(@intCast(u64, 3), ctx.code.items.len);

    try tst.expectEqual(@intCast(u64, 3), a.number);
    try tst.expectEqual(@intCast(u64, 2), b.number);

    try tst.expectEqual(@intCast(u64, 0), mul.mul.lhs);
    try tst.expectEqual(@intCast(u64, 1), mul.mul.rhs);

    try tst.expectEqual(@intCast(u64, 0), na.ins);
    try tst.expectEqual(@intCast(u64, 1), nb.ins);
    try tst.expectEqual(@intCast(u64, 2), main.ins);
}

test "fn call" {
    const source =
        \\ let write = 0
        \\ let a = 2
        \\ let b = 10
        \\ let main = write a b
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    try printSource(ctx.code.items, source);
    const v_write = ctx.table.get("write").?;
    const v_a = ctx.table.get("a").?;
    const v_b = ctx.table.get("b").?;
    const v_main = ctx.table.get("main").?;

    const i_write = ctx.code.items[0];
    const i_a = ctx.code.items[1];
    const i_b = ctx.code.items[2];
    const i_main = ctx.code.items[3];
    const i_push1 = ctx.code.items[4];
    const i_push2 = ctx.code.items[5];
    const i_call = ctx.code.items[6];

    try tst.expectEqual(@intCast(u64, 7), ctx.code.items.len);

    try tst.expectEqual(@intCast(u64, 0), i_write.number);
    try tst.expectEqual(@intCast(u64, 2), i_a.number);
    try tst.expectEqual(@intCast(u64, 10), i_b.number);
    try tst.expectEqual(@intCast(u64, 6), i_main.begin_call.end);
    try tst.expectEqual(@intCast(u64, 1), i_push1.push_param.reg);
    try tst.expectEqual(@intCast(u64, 2), i_push2.push_param.reg);
    try tst.expectEqual(@intCast(u64, 0), i_call.call.reg);

    try tst.expectEqual(@intCast(u64, 0), v_write.ins);
    try tst.expectEqual(@intCast(u64, 1), v_a.ins);
    try tst.expectEqual(@intCast(u64, 2), v_b.ins);
    try tst.expectEqual(@intCast(u64, 3), v_main.ins);
}
