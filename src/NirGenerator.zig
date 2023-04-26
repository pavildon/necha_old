const std = @import("std");
const tst = std.testing;

const nir = @import("Nir.zig");
const nr = @import("NirRunner.zig");

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
var f_lambda: ts.TSFieldId = undefined;
var f_arrow: ts.TSFieldId = undefined;

var f_bool: ts.TSFieldId = undefined;
var f_if: ts.TSFieldId = undefined;
var f_then: ts.TSFieldId = undefined;
var f_else: ts.TSFieldId = undefined;

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
    f_lambda = ts.ts_language_field_id_for_name(tree_sitter_necha(), "lambda", "lambda".len);
    f_arrow = ts.ts_language_field_id_for_name(tree_sitter_necha(), "arrow", "arrow".len);
    f_bool = ts.ts_language_field_id_for_name(tree_sitter_necha(), "boolean", "boolean".len);
    f_if = ts.ts_language_field_id_for_name(tree_sitter_necha(), "if", "if".len);
    f_then = ts.ts_language_field_id_for_name(tree_sitter_necha(), "then", "then".len);
    f_else = ts.ts_language_field_id_for_name(tree_sitter_necha(), "else", "else".len);
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
            }
        }
    }

    fn let_root(self: *Self) ParseError!usize {
        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (field_id == f_def) {
                try self.def();
            } else if (field_id > 0) {
                return try self.expr();
            }
        }
        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return 0;
    }

    fn if_expr(self: *Self) ParseError!usize {
        // if
        if (!ts.ts_tree_cursor_goto_first_child(&self.cursor)) unreachable;

        if (!ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) unreachable;
        const condition = try self.expr();
        try self.instructions.append(.{ .cnd = .{ .reg = condition, .f = 0 } });
        const cnd_ins = self.instructions.items.len - 1;

        // then
        if (!ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) unreachable;

        if (!ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) unreachable;
        const t = try self.expr();
        try self.instructions.append(.{ .brk = .{ .reg = t, .end = 0 } });
        const tb_ins = self.instructions.items.len - 1;

        // else
        if (!ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) unreachable;

        if (!ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) unreachable;
        const f = try self.expr();
        try self.instructions.append(.{ .brk = .{ .reg = f, .end = 0 } });
        const fb_ins = self.instructions.items.len - 1;

        const end = self.instructions.items.len - 1;

        self.instructions.items[cnd_ins] = .{ .cnd = .{ .reg = condition, .f = f } };
        self.instructions.items[tb_ins] = .{ .brk = .{ .reg = t, .end = end } };
        self.instructions.items[fb_ins] = .{ .brk = .{ .reg = f, .end = end } };

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);

        return condition;
    }

    fn let_in(self: *Self) ParseError!usize {
        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (field_id == f_def) {
                try self.def();
            } else if (field_id > 0 and field_id != f_def) {
                const r = try self.expr();
                _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
                return r;
            }
        }
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
            } else {
                var unk = getNodeName(ts.ts_tree_cursor_current_node(&self.cursor), self.source);
                _ = unk;
            }
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
                try self.instructions.append(.{ .U64 = n });
            },
            else => unreachable,
        }
        return self.instructions.items.len - 1;
    }

    fn boolean(self: *Self) !usize {
        const bool_str = getNodeName(
            ts.ts_tree_cursor_current_node(&self.cursor),
            self.source,
        );
        const result = std.mem.eql(u8, bool_str, "true");
        if (result) {
            try self.instructions.append(.{ .Bool = true });
        } else {
            try self.instructions.append(.{ .Bool = false });
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
        } else if (field_id == f_bool) {
            return try self.boolean();
        } else if (field_id == f_if) {
            try self.table.push();
            const r = try self.if_expr();
            try self.table.pop();
            return r;
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
        } else if (field_id == f_lambda) {
            try self.table.push();
            const r = try self.lambda();
            try self.table.pop();
            return r;
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

        var args: [10]usize = [_]usize{0} ** 10;
        var arg_n: usize = 9;

        cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor);
        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (id > 0) {
                args[arg_n] = try self.expr();
                arg_n -= 1;
            }
        }

        for (args[arg_n + 1 ..]) |arg| {
            try self.instructions.append(.{ .push_param = .{ .reg = arg } });
        }

        try self.instructions.append(.{ .call = .{ .reg = function } });
        self.instructions.items[begin] = .{ .begin_call = .{ .end = self.instructions.items.len - 1 } };
        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return begin;
    }

    fn lambda(self: *Self) ParseError!u64 {
        try self.instructions.append(.{ .fun = .{ .end = 0 } });
        const fun = self.instructions.items.len - 1;

        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        var id = ts.ts_tree_cursor_current_field_id(&self.cursor);
        cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor);
        while (id != f_arrow) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const name = getNodeName(ts.ts_tree_cursor_current_node(&self.cursor), self.source);
            id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (id == f_ident) {
                try self.instructions.append(.{ .pop_param = .{ .nop = 0 } });
                //                const name = getNodeName(ts.ts_tree_cursor_current_node(&self.cursor), self.source);
                const ip = self.instructions.items.len - 1;
                try self.table.put(name, ip, true);
            }
        }

        const ret = try self.expr();

        try self.instructions.append(.{ .ret = .{ .reg = ret } });
        self.instructions.items[fun] = .{ .fun = .{ .end = self.instructions.items.len - 1 } };
        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return fun;
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
    std.debug.print("f_lambda {d}\n", .{f_lambda});
    std.debug.print("f_arrow {d}\n", .{f_arrow});
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
    try tst.expectEqual(@intCast(u64, 1), ins.U64);
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
    try tst.expectEqual(@intCast(u64, 2), ins.U64);
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
    try tst.expectEqual(@intCast(u64, 2), ins.U64);
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
    try tst.expectEqual(@intCast(u64, 2), ins.U64);
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

    try tst.expectEqual(@intCast(u64, 1), one.U64);
    try tst.expectEqual(@intCast(u64, 3), three.U64);

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

    try tst.expectEqual(@intCast(u64, 3), a.U64);
    try tst.expectEqual(@intCast(u64, 2), b.U64);

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

    try tst.expectEqual(@intCast(u64, 0), i_write.U64);
    try tst.expectEqual(@intCast(u64, 2), i_a.U64);
    try tst.expectEqual(@intCast(u64, 10), i_b.U64);
    try tst.expectEqual(@intCast(u64, 6), i_main.begin_call.end);
    // swapped
    try tst.expectEqual(@intCast(u64, 2), i_push1.push_param.reg);
    try tst.expectEqual(@intCast(u64, 1), i_push2.push_param.reg);
    try tst.expectEqual(@intCast(u64, 0), i_call.call.reg);

    try tst.expectEqual(@intCast(u64, 0), v_write.ins);
    try tst.expectEqual(@intCast(u64, 1), v_a.ins);
    try tst.expectEqual(@intCast(u64, 2), v_b.ins);
    try tst.expectEqual(@intCast(u64, 3), v_main.ins);
}

test "let in #1" {
    const source =
        \\ let main = let a = 1 in a
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const v_main = ctx.table.get("main").?;

    const i_main = ctx.code.items[0];

    try tst.expectEqual(@intCast(u64, 1), ctx.code.items.len);
    try tst.expectEqual(@intCast(u64, 1), i_main.U64);
    try tst.expectEqual(@intCast(u64, 0), v_main.ins);
}

test "let in #2" {
    const source =
        \\ let nine = 9
        \\ let main = let a = nine in a
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const v_nine = ctx.table.get("nine").?;
    const v_main = ctx.table.get("main").?;

    const i_main = ctx.code.items[0];

    try tst.expectEqual(@intCast(u64, 1), ctx.code.items.len);
    try tst.expectEqual(@intCast(u64, 9), i_main.U64);
    try tst.expectEqual(@intCast(u64, 0), v_main.ins);
    try tst.expectEqual(@intCast(u64, 0), v_nine.ins);
}

test "fn" {
    const source =
        \\ let double = fn a -> * a 2
        \\ let main = double 10
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const v_double = ctx.table.get("double").?;
    const i_double = ctx.code.items[0];
    const i_pop = ctx.code.items[1];
    const i_ret = ctx.code.items[4];

    const v_main = ctx.table.get("main").?;

    try tst.expectEqual(@intCast(u64, 9), ctx.code.items.len);
    try tst.expectEqual(@intCast(u64, 4), i_double.fun.end);
    try tst.expectEqual(@intCast(u64, 0), i_pop.pop_param.nop);
    try tst.expectEqual(@intCast(u64, 3), i_ret.ret.reg);
    try tst.expectEqual(@intCast(u64, 0), v_double.ins);
    try tst.expectEqual(@intCast(u64, 5), v_main.ins);

    var runner = try nr.NirRunner.init(tst.allocator);
    defer runner.deinit();
}

test "fn" {
    const source =
        \\ let double = fn a b -> * a b
        \\ let main = double 2 10
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();
}

test "fn2" {
    const source =
        \\ let double = fn a -> * a 2
        \\ let apply = fn f a -> f a
        \\ let main = apply double 10
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const v_double = ctx.table.get("double").?;
    const i_double = ctx.code.items[0];
    const v_apply = ctx.table.get("apply").?;
    const i_apply = ctx.code.items[5];

    const v_main = ctx.table.get("main").?;

    try tst.expectEqual(@intCast(u64, 17), ctx.code.items.len);
    try tst.expectEqual(@intCast(u64, 4), i_double.fun.end);
    try tst.expectEqual(@intCast(u64, 0), v_double.ins);
    try tst.expectEqual(@intCast(u64, 11), i_apply.fun.end);
    try tst.expectEqual(@intCast(u64, 5), v_apply.ins);

    try tst.expectEqual(@intCast(u64, 12), v_main.ins);

    var sctx: usize = 999;
    var runner = try nr.NirMachine(usize).init(tst.allocator, &sctx);
    defer runner.deinit();

    try runner.run(ctx.code.items);
    const state = runner.state();
    const cv = state.reg.get(10) orelse unreachable;
    try tst.expectEqual(@intCast(u64, 20), cv.U64);
}

test "frame pointer" {
    const source =
        \\ let double = fn a -> let t = 2 and zz = a in * zz t
        \\
        \\ let main =
        \\   let a = 5 and
        \\       a1 = + a 16 and
        \\       r = double a1 in
        \\       r
        \\
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    var sctx: usize = 999;

    const v_main = ctx.table.get("main").?;

    try tst.expectEqual(@intCast(u64, 8), v_main.ins);

    var runner = try nr.NirMachine(usize).init(tst.allocator, &sctx);
    defer runner.deinit();

    try runner.run(ctx.code.items);
    const state = runner.state();
    const cv = state.reg.get(10) orelse unreachable;

    try tst.expectEqual(@intCast(u64, 42), cv.U64);
}

test "booleans" {
    const source =
        \\ let t = true
        \\ let f = false
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();

    const v_t = ctx.table.get("t").?;
    const v_f = ctx.table.get("f").?;

    const i_t = ctx.code.items[0];
    const i_f = ctx.code.items[1];

    try tst.expectEqual(@intCast(u64, 0), v_t.ins);
    try tst.expectEqual(@intCast(u64, 1), v_f.ins);

    try tst.expectEqual(true, i_t.Bool);
    try tst.expectEqual(false, i_f.Bool);
}

test "if_then_else" {
    const source =
        \\ let t = true
        \\ let aa  = if t then 1 else 0
        \\ let bb = if false then 1 else 0
    ;

    var ctx = try genOwnedCtx(tst.allocator, source);
    defer ctx.deinit();
    try printSource(ctx.code.items, source);

    const v_t = ctx.table.get("aa").?;
    const i_t = ctx.code.items[1];

    try tst.expectEqual(@intCast(u64, 0), v_t.ins);
    try tst.expectEqual(@intCast(u64, 4), i_t.cnd.f);

    var sctx: usize = 999;
    var runner = try nr.NirMachine(usize).init(tst.allocator, &sctx);
    defer runner.deinit();

    try runner.run(ctx.code.items);
    const state = runner.state();
    const cv1 = state.reg.get(1) orelse unreachable;
    const cv2 = state.reg.get(7) orelse unreachable;

    try tst.expectEqual(@intCast(u64, 1), cv1.U64);
    try tst.expectEqual(@intCast(u64, 0), cv2.U64);
}
