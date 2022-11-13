const std = @import("std");

// Tree Sitter
const ts = @cImport(@cInclude("tree_sitter/api.h"));

// QuickJS
const qjs = @cImport(@cInclude("quickjs-libc.h"));

const Alloc = std.mem.Allocator;
// const string to shut the lsp warning

extern fn tree_sitter_necha() *const ts.TSLanguage;

const ImportFn = *const fn (name: []const u8) []const u8;

const ErrorType = enum {
    SyntaxError,
};

const SynError = struct {
    loc: usize,
    ty: ErrorType,
};

const ParseError = error{
    InvalidSource,
};

const InstData = union(enum) {
    nop: void,
    block: struct { last: usize },
    block_inline: struct { last: usize },
    brk: struct { ins: usize },
    loop: struct { last: usize },
    number: u64,
    string: struct { start: usize, end: usize },
    decl_val: struct { start: usize, end: usize },
    param: struct { start: usize, end: usize },
    fn_def: struct { body: usize },

    alloc: void,
    load: struct { src: usize },
    store: struct { src: usize, dst: usize },

    exp: struct { lhs: usize, rhs: usize },
    div: struct { lhs: usize, rhs: usize },
    mul: struct { lhs: usize, rhs: usize },
    sub: struct { lhs: usize, rhs: usize },
    add: struct { lhs: usize, rhs: usize },

    geq: struct { lhs: usize, rhs: usize },
    leq: struct { lhs: usize, rhs: usize },
    gt: struct { lhs: usize, rhs: usize },
    lt: struct { lhs: usize, rhs: usize },
    eq: struct { lhs: usize, rhs: usize },
    neq: struct { lhs: usize, rhs: usize },
    and_: struct { lhs: usize, rhs: usize },
    or_: struct { lhs: usize, rhs: usize },

    uminus: struct { val: usize },
    ubang: struct { val: usize },
    uplus: struct { val: usize },

    cnd_br: struct { cnd: usize, t: usize, f: usize },
    cnd_loop: struct { cnd: usize, loop: usize },
    fn_call: struct { func: usize, last: usize },

    push: struct { src: usize, dst: usize },
    offset: struct { src: usize, index: usize },

    field: struct { src: usize, start: usize, end: usize },

    pop: struct { src: usize },
};

const Inst = struct {
    data: InstData,
    node: ?ts.TSNode,
};

const Nir = struct {
    instructions: std.ArrayListUnmanaged(Inst),
    extra: std.ArrayListUnmanaged(usize),
    strings: std.ArrayListUnmanaged(u8),

    pub fn toString(self: *Nir, allocator: Alloc) ![]const u8 {
        var src = try std.ArrayListUnmanaged(u8).initCapacity(allocator, 4096);
        var writer = src.writer(allocator);

        for (self.instructions.items) |ins, n| {
            switch (ins.data) {
                InstData.string => |s| _ =
                    try writer.print("%{d}. string \"{s}\"\n", .{
                    n,
                    self.strings.items[s.start..s.end],
                }),
                InstData.number => |no| _ =
                    try writer.print("%{d}. number {d}\n", .{
                    n,
                    no,
                }),
                InstData.alloc => _ =
                    try writer.print("%{d}. alloc\n", .{
                    n,
                }),
                InstData.store => |i| _ =
                    try writer.print("%{d}. store %{d} %{d}\n", .{
                    n,
                    i.src,
                    i.dst,
                }),
                InstData.load => |i| _ =
                    try writer.print("%{d}. load %{d} \n", .{
                    n,
                    i.src,
                }),
                InstData.decl_val => |v| _ =
                    try writer.print("%{d}. decl_val \"{s}\"\n", .{
                    n,
                    self.strings.items[v.start..v.end],
                }),
                InstData.block_inline => |bi| _ =
                    try writer.print("%{d}. block_inline %{d}\n", .{
                    n,
                    bi.last,
                }),
                InstData.block => |b| _ =
                    try writer.print("%{d}. block %{d}\n", .{
                    n,
                    b.last,
                }),
                InstData.brk => |brk| _ =
                    try writer.print("%{d}. break %{d}\n", .{
                    n,
                    brk.ins,
                }),
                InstData.param => |param| _ =
                    try writer.print("%{d}. param \"{s}\"\n", .{
                    n,
                    self.strings.items[param.start..param.end],
                }),
                InstData.fn_def => |fn_def| _ =
                    try writer.print("%{d}. fn %{d}\n", .{
                    n,
                    fn_def.body,
                }),
                InstData.exp => |exp| _ =
                    try writer.print("%{d}. exp %{d} %{d}\n", .{
                    n,
                    exp.lhs,
                    exp.rhs,
                }),
                InstData.div => |div| _ =
                    try writer.print("%{d}. div %{d} %{d}\n", .{
                    n,
                    div.lhs,
                    div.rhs,
                }),
                InstData.mul => |mul| _ =
                    try writer.print("%{d}. mul %{d} %{d}\n", .{
                    n,
                    mul.lhs,
                    mul.rhs,
                }),
                InstData.sub => |sub| _ =
                    try writer.print("%{d}. sub %{d} %{d}\n", .{
                    n,
                    sub.lhs,
                    sub.rhs,
                }),
                InstData.add => |add| _ =
                    try writer.print("%{d}. add %{d} %{d}\n", .{
                    n,
                    add.lhs,
                    add.rhs,
                }),
                InstData.geq => |bin| _ =
                    try writer.print("%{d}. geq %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                InstData.leq => |bin| _ =
                    try writer.print("%{d}. leq %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                InstData.gt => |bin| _ =
                    try writer.print("%{d}. gt %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                InstData.lt => |bin| _ =
                    try writer.print("%{d}. lt %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                InstData.eq => |bin| _ =
                    try writer.print("%{d}. eq %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                InstData.neq => |bin| _ =
                    try writer.print("%{d}. neq %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                InstData.and_ => |bin| _ =
                    try writer.print("%{d}. and %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                InstData.or_ => |bin| _ =
                    try writer.print("%{d}. or %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                InstData.cnd_br => |cnd| _ =
                    try writer.print("%{d}. cnd_br %{d} %{d} %{d}\n", .{
                    n,
                    cnd.cnd,
                    cnd.t,
                    cnd.f,
                }),
                InstData.uminus => |u| _ =
                    try writer.print("%{d}. uminus %{d}\n", .{
                    n,
                    u.val,
                }),
                InstData.fn_call => |fc| _ =
                    try writer.print("%{d}. fn_call %{d} %{d}\n", .{
                    n,
                    fc.func,
                    fc.last,
                }),
                InstData.loop => |loop| _ =
                    try writer.print("%{d}. loop %{d}\n", .{
                    n,
                    loop.last,
                }),
                InstData.cnd_loop => |cnd_loop| _ =
                    try writer.print("%{d}. cnd_loop %{d} %{d}\n", .{
                    n,
                    cnd_loop.cnd,
                    cnd_loop.loop,
                }),
                InstData.push => |pi| _ =
                    try writer.print("%{d}. push %{d} %{d}\n", .{
                    n,
                    pi.src,
                    pi.dst,
                }),
                InstData.offset => |ofs| _ =
                    try writer.print("%{d}. offset %{d} %{d}\n", .{
                    n,
                    ofs.src,
                    ofs.index,
                }),
                else => _ = try writer.print("%{d}. unknown\n", .{n}),
            }
        }

        return src.toOwnedSlice(allocator);
    }
};

const SymbolInfo = struct {
    name: []const u8,
    ins: usize,
    is_const: bool,
    next: usize,
};

const SymbolTable = struct {
    const Self = @This();
    const PosNextArr = std.ArrayList(SymbolInfo);
    locations: PosNextArr,
    stack_pointer: usize,
    names: std.StringHashMap(usize),

    pub fn init(allocator: Alloc, init_size: usize) !Self {
        var self = Self{
            .locations = try PosNextArr.initCapacity(allocator, init_size),
            .stack_pointer = 0,
            .names = std.StringHashMap(usize).init(allocator),
        };

        try self.locations.append(.{
            .name = "root",
            .ins = 0,
            .is_const = true,
            .next = 0,
        });
        return self;
    }

    pub fn put(self: *Self, name: []const u8, instruction: usize, is_const: bool) !void {
        const i = self.names.get(name) orelse 0;
        try self.locations.append(.{ .name = name, .ins = instruction, .is_const = is_const, .next = i });
        try self.names.put(name, self.locations.items.len - 1);
    }

    pub fn get(self: *Self, name: []const u8) ?SymbolInfo {
        if (self.names.get(name)) |i| {
            return self.locations.items[i];
        }

        return null;
    }

    pub fn push(self: *Self) !void {
        try self.locations.append(.{
            .name = "",
            .ins = 0,
            .is_const = false,
            .next = self.stack_pointer,
        });
        self.stack_pointer = self.locations.items.len - 1;
    }

    pub fn pop(self: *Self) !void {
        const new_sp = self.locations.items[self.stack_pointer].next;
        while (self.locations.items.len > self.stack_pointer) {
            const v = self.locations.pop();
            try self.names.put(v.name, v.next);
        }
        self.stack_pointer = new_sp;
    }

    pub fn deinit(self: *Self) void {
        self.locations.deinit();
        self.names.deinit();
    }
};

const ArrList = std.ArrayList;

// TODO define these elsewhere
var decl_name: ts.TSFieldId = undefined;
var decl_value: ts.TSFieldId = undefined;
var decl_visibility: ts.TSFieldId = undefined;
var decl_mutability: ts.TSFieldId = undefined;
var assig_name: ts.TSFieldId = undefined;
var assig_value: ts.TSFieldId = undefined;

// TODO reaname to param?
var fn_def_arg: ts.TSFieldId = undefined;
var fn_def_body: ts.TSFieldId = undefined;
var while_body: ts.TSFieldId = undefined;
var bin_lhs: ts.TSFieldId = undefined;
var bin_op: ts.TSFieldId = undefined;
var expr_field: ts.TSFieldId = undefined;
var bin_rhs: ts.TSFieldId = undefined;
var if_cond: ts.TSFieldId = undefined;
var while_cond: ts.TSFieldId = undefined;
var if_true: ts.TSFieldId = undefined;
var if_false: ts.TSFieldId = undefined;
var fn_call_arg: ts.TSFieldId = undefined;
var fn_call_id: ts.TSFieldId = undefined;

var array_acc_id: ts.TSFieldId = undefined;
var array_acc_index: ts.TSFieldId = undefined;

const NirGenerator = struct {
    const Self = @This();

    allocator: Alloc,
    nir: Nir,
    cursor: ts.TSTreeCursor = undefined,
    table: SymbolTable = undefined,
    source: []const u8,
    // TODO uhmmm...
    block_inline: bool = false,

    pub fn gen(alloc: Alloc, source: []const u8) !Nir {
        decl_name = ts.ts_language_field_id_for_name(tree_sitter_necha(), "name", "name".len);
        decl_value = ts.ts_language_field_id_for_name(tree_sitter_necha(), "value", "value".len);
        decl_mutability = ts.ts_language_field_id_for_name(tree_sitter_necha(), "mutability", "mutability".len);
        decl_visibility = ts.ts_language_field_id_for_name(tree_sitter_necha(), "visibility", "visibility".len);

        assig_name = ts.ts_language_field_id_for_name(tree_sitter_necha(), "name", "name".len);
        assig_value = ts.ts_language_field_id_for_name(tree_sitter_necha(), "value", "value".len);
        fn_def_arg = ts.ts_language_field_id_for_name(tree_sitter_necha(), "arg", "arg".len);
        fn_def_body = ts.ts_language_field_id_for_name(tree_sitter_necha(), "body", "body".len);
        while_body = fn_def_body;

        bin_lhs = ts.ts_language_field_id_for_name(tree_sitter_necha(), "lhs", "lhs".len);
        bin_op = ts.ts_language_field_id_for_name(tree_sitter_necha(), "op", "op".len);
        bin_rhs = ts.ts_language_field_id_for_name(tree_sitter_necha(), "rhs", "rhs".len);

        if_cond = ts.ts_language_field_id_for_name(tree_sitter_necha(), "condition", "condition".len);
        while_cond = if_cond;

        if_true = ts.ts_language_field_id_for_name(tree_sitter_necha(), "true", "true".len);
        if_false = ts.ts_language_field_id_for_name(tree_sitter_necha(), "false", "false".len);

        expr_field = ts.ts_language_field_id_for_name(tree_sitter_necha(), "expr", "expr".len);

        fn_call_arg = ts.ts_language_field_id_for_name(tree_sitter_necha(), "arg", "arg".len);
        fn_call_id = ts.ts_language_field_id_for_name(tree_sitter_necha(), "id", "id".len);

        array_acc_id = fn_call_id;
        array_acc_index = ts.ts_language_field_id_for_name(tree_sitter_necha(), "index", "index".len);

        var generator: NirGenerator = .{
            .allocator = alloc,
            .source = source,
            .cursor = undefined,
            .table = undefined,
            .nir = Nir{
                .instructions = std.ArrayListUnmanaged(Inst){},
                .extra = std.ArrayListUnmanaged(usize){},
                .strings = std.ArrayListUnmanaged(u8){},
            },
        };

        return try generator.genNir();
    }

    pub fn genNir(self: *Self) !Nir {
        var parser = ts.ts_parser_new().?;
        defer ts.ts_parser_delete(parser);
        _ = ts.ts_parser_set_language(parser, tree_sitter_necha());

        var tree = ts.ts_parser_parse_string(
            parser,
            null,
            self.source.ptr,
            @intCast(u32, self.source.len),
        ).?;
        defer ts.ts_tree_delete(tree);

        var root_node = ts.ts_tree_root_node(tree);
        const root_node_type = ts.ts_node_type(root_node);

        if (!std.mem.eql(u8, "source_file", std.mem.span(root_node_type)))
            return ParseError.InvalidSource;

        self.cursor = ts.ts_tree_cursor_new(root_node);
        defer ts.ts_tree_cursor_delete(&self.cursor);

        var cursor_moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        self.nir = Nir{
            .instructions = std.ArrayListUnmanaged(Inst){},
            .extra = std.ArrayListUnmanaged(usize){},
            .strings = std.ArrayListUnmanaged(u8){},
        };

        self.table = try SymbolTable.init(self.allocator, 1024);
        defer self.table.deinit();

        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const node = ts.ts_tree_cursor_current_node(&self.cursor);
            const node_type = ts.ts_node_type(node);
            std.debug.print("\n{s}\n", .{node_type});
            if (std.mem.eql(u8, std.mem.span(node_type), "ERROR")) {
                std.debug.print("syntax error!\n", .{});
            } else if (std.mem.eql(u8, std.mem.span(node_type), "declaration")) {
                _ = try self.decl();
            } else {
                std.debug.print("other!\n", .{});
            }
        }

        return self.nir;
    }

    fn expr(self: *Self) anyerror!usize {
        var node = ts.ts_tree_cursor_current_node(&self.cursor);

        if (!ts.ts_node_is_named(node)) {
            _ = ts.ts_tree_cursor_goto_next_sibling(&self.cursor);
            node = ts.ts_tree_cursor_current_node(&self.cursor);
        }

        const node_type = std.mem.span(ts.ts_node_type(node));
        std.debug.print("{s}\n", .{node_type});

        if (std.mem.eql(u8, std.mem.span(node_type), "ERROR")) {
            return ParseError.InvalidSource;
        } else if (std.mem.eql(u8, node_type, "declaration")) {
            return try self.decl();
        } else if (std.mem.eql(u8, node_type, "number")) {
            return try self.number();
        } else if (std.mem.eql(u8, node_type, "string")) {
            return try self.string();
        } else if (std.mem.eql(u8, node_type, "identifier")) {
            return try self.identifier();
        } else if (std.mem.eql(u8, node_type, "assignment")) {
            return try self.assignment();
        } else if (std.mem.eql(u8, node_type, "brace_expr")) {
            return try self.brace();
        } else if (std.mem.eql(u8, node_type, "bracket_expr")) {
            return try self.bracket();
        } else if (std.mem.eql(u8, node_type, "function_def")) {
            return try self.fnDef();
        } else if (std.mem.eql(u8, node_type, "function_call")) {
            return try self.fnCall();
        } else if (std.mem.eql(u8, node_type, "math_expr") or std.mem.eql(u8, node_type, "boolean_expr")) {
            return try self.binExpr();
        } else if (std.mem.eql(u8, node_type, "unary_expr")) {
            return try self.unaryExpr();
        } else if (std.mem.eql(u8, node_type, "if_expr")) {
            return try self.ifExpr();
        } else if (std.mem.eql(u8, node_type, "while_stmt")) {
            return try self.whileStmt();
        } else if (std.mem.eql(u8, node_type, "array_accessor")) {
            return try self.arrayAccess();
        } else {
            return ParseError.InvalidSource;
        }
    }

    fn identifier(self: *Self) anyerror!usize {
        const identifier_node = ts.ts_tree_cursor_current_node(&self.cursor);
        const start = ts.ts_node_start_byte(identifier_node);
        const end = ts.ts_node_end_byte(identifier_node);

        const src = self.source;
        var pos = self.table.get(src[start..end]);
        var location: usize = undefined;
        if (pos) |p| {
            if (p.is_const) {
                location = p.ins;
            } else {
                try self.nir.instructions.append(self.allocator, Inst{
                    .data = InstData{ .load = .{ .src = p.ins } },
                    .node = identifier_node,
                });
            }
        } else {
            const str_loc = try self.copyStrFromSource(identifier_node);
            const n_ins = Inst{
                .data = .{
                    .decl_val = .{ .start = str_loc[0], .end = str_loc[1] },
                },
                .node = identifier_node,
            };

            try self.nir.instructions.append(self.allocator, n_ins);
            location = self.nir.instructions.items.len - 1;
        }

        return self.nir.instructions.items.len - 1;
    }

    fn string(self: *Self) anyerror!usize {
        if (!ts.ts_tree_cursor_goto_first_child(&self.cursor) or
            !ts.ts_tree_cursor_goto_next_sibling(&self.cursor))
        {
            return ParseError.InvalidSource;
        }

        const string_node = ts.ts_tree_cursor_current_node(&self.cursor);
        const start = ts.ts_node_start_byte(string_node);
        const end = ts.ts_node_end_byte(string_node);

        const src = self.source;
        const start_n = self.nir.strings.items.len;

        try self.nir.strings.appendSlice(self.allocator, src[start..end]);
        const end_n = self.nir.strings.items.len;
        const n_ins = Inst{
            .data = .{ .string = .{ .start = start_n, .end = end_n } },
            .node = string_node,
        };

        try self.nir.instructions.append(self.allocator, n_ins);

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.nir.instructions.items.len - 1;
    }

    fn number(self: *Self) anyerror!usize {
        const number_node = ts.ts_tree_cursor_current_node(&self.cursor);
        const start = ts.ts_node_start_byte(number_node);
        const end = ts.ts_node_end_byte(number_node);

        const src = self.source;
        const result = std.zig.parseNumberLiteral(src[start..end]);
        switch (result) {
            .int => |i| {
                const n_ins = Inst{
                    .data = .{ .number = i },
                    .node = number_node,
                };
                try self.nir.instructions.append(self.allocator, n_ins);
            },
            else => {
                std.debug.print("Large numbers not implemented yet!\n", .{});
                return ParseError.InvalidSource;
            },
        }

        return self.nir.instructions.items.len - 1;
    }

    fn bracket(self: *Self) !usize {
        const bracket_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        var last = self.nir.instructions.items.len;

        try self.nir.instructions.append(self.allocator, Inst{
            .data = .{ .alloc = undefined },
            .node = bracket_node,
        });

        const array = self.nir.instructions.items.len - 1;

        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const curr = ts.ts_tree_cursor_current_node(&self.cursor);

            const old_inline = self.block_inline;
            self.block_inline = true;
            if (ts.ts_node_is_named(curr)) {
                last = try self.expr();
                try self.nir.instructions.append(self.allocator, Inst{
                    .data = InstData{
                        .push = .{ .src = last, .dst = array },
                    },
                    .node = curr,
                });
            }
            self.block_inline = old_inline;
        }

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return array;
    }

    fn brace(self: *Self) !usize {
        const block_node = ts.ts_tree_cursor_current_node(&self.cursor);

        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        var last = self.nir.instructions.items.len;

        const block_inline = InstData{ .block_inline = .{
            .last = last,
        } };

        try self.nir.instructions.append(self.allocator, Inst{
            .data = block_inline,
            .node = block_node,
        });

        const block_begin = self.nir.instructions.items.len - 1;

        try self.table.push();
        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const curr = ts.ts_tree_cursor_current_node(&self.cursor);
            const old_inline = self.block_inline;
            self.block_inline = true;
            if (ts.ts_node_is_named(curr))
                last = try self.expr();
            self.block_inline = old_inline;
        }
        try self.table.pop();

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{ .brk = .{ .ins = last } },
            .node = block_node,
        });

        var block_i: InstData = undefined;
        if (self.block_inline) {
            block_i = InstData{ .block_inline = .{
                .last = self.nir.instructions.items.len - 1,
            } };
        } else {
            block_i = InstData{ .block = .{
                .last = self.nir.instructions.items.len - 1,
            } };
        }
        self.nir.instructions.items[block_begin].data = block_i;

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return block_begin;
    }

    fn assignment(self: *Self) !usize {
        const decl_node = ts.ts_tree_cursor_current_node(&self.cursor);

        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        var name: ?[]const u8 = null;

        const old_inline = self.block_inline;

        self.block_inline = false;
        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;
            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == decl_name) {
                const name_node = ts.ts_tree_cursor_current_node(&self.cursor);
                const start = ts.ts_node_start_byte(name_node);
                const end = ts.ts_node_end_byte(name_node);
                name = self.source[start..end];
            } else if (field_id == decl_value) {
                if (name) |n| {
                    const value_idx = try self.expr();
                    const dst = self.table.get(n);
                    if (dst) |d| {
                        const store = Inst{
                            .data = InstData{ .store = .{
                                .src = value_idx,
                                .dst = d.ins,
                            } },
                            .node = decl_node,
                        };
                        try self.nir.instructions.append(self.allocator, store);
                        break;
                    } else {
                        return ParseError.InvalidSource;
                    }
                }
            }
        }
        self.block_inline = old_inline;

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.nir.instructions.items.len - 1;
    }

    fn decl(self: *Self) !usize {
        const decl_node = ts.ts_tree_cursor_current_node(&self.cursor);

        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        var name: ?[]const u8 = null;
        var mutable: bool = false;
        var index: usize = 0;

        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == decl_mutability) {
                const mutability_node = ts.ts_tree_cursor_current_node(&self.cursor);
                if (std.mem.eql(u8, std.mem.span(ts.ts_node_type(mutability_node)), "var")) {
                    mutable = true;
                }
            } else if (field_id == decl_name) {
                const name_node = ts.ts_tree_cursor_current_node(&self.cursor);
                const start = ts.ts_node_start_byte(name_node);
                const end = ts.ts_node_end_byte(name_node);
                name = self.source[start..end];
            } else if (field_id == decl_value) {
                if (name) |n| {
                    if (mutable) {
                        const mem = Inst{
                            .data = InstData{ .alloc = undefined },
                            .node = decl_node,
                        };
                        index = self.nir.instructions.items.len;
                        try self.nir.instructions.append(self.allocator, mem);
                    }
                    const value_idx = try self.expr();
                    const con = value_idx;

                    if (mutable) {
                        const store = Inst{
                            .data = InstData{ .store = .{
                                .src = con,
                                .dst = index,
                            } },
                            .node = decl_node,
                        };
                        try self.nir.instructions.append(self.allocator, store);
                    } else {
                        index = value_idx;
                    }

                    try self.table.put(n, index, !mutable);
                }
            }
        }

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return index;
    }

    fn fnDef(self: *Self) !usize {
        const fn_def_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        const body_block = InstData{ .block_inline = .{
            .last = 0,
        } };

        try self.nir.instructions.append(self.allocator, Inst{
            .data = body_block,
            .node = fn_def_node,
        });

        const block_index = self.nir.instructions.items.len - 1;
        var last = block_index;

        try self.table.push();
        const old_inline = self.block_inline;
        self.block_inline = true;
        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == fn_def_arg) {
                const start = ts.ts_node_start_byte(current);
                const end = ts.ts_node_end_byte(current);
                const str_loc = try self.copyStrFromSource(current);
                try self.nir.instructions.append(self.allocator, Inst{
                    .data = InstData{ .param = .{
                        .start = str_loc[0],
                        .end = str_loc[1],
                    } },
                    .node = current,
                });
                try self.table.put(self.source[start..end], self.nir.instructions.items.len - 1, true);
            } else if (field_id == fn_def_body) {
                last = try self.expr();
            }
        }
        self.block_inline = old_inline;
        try self.table.pop();

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{ .brk = .{ .ins = last } },
            .node = fn_def_node,
        });

        self.nir.instructions.items[block_index].data = InstData{
            .block = .{ .last = self.nir.instructions.items.len - 1 },
        };
        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{ .fn_def = .{ .body = block_index } },
            .node = fn_def_node,
        });

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.nir.instructions.items.len - 1;
    }

    fn fnCall(self: *Self) !usize {
        const fn_call_node = ts.ts_tree_cursor_current_node(&self.cursor);

        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        var last = self.nir.instructions.items.len;

        var fn_call_begin: usize = undefined;

        var func_inst: usize = 0;
        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const curr = ts.ts_tree_cursor_current_node(&self.cursor);
            const old_inline = self.block_inline;
            self.block_inline = true;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == fn_call_id) {
                func_inst = try self.expr();
                try self.nir.instructions.append(self.allocator, Inst{
                    .data = InstData{ .nop = undefined },
                    .node = fn_call_node,
                });
                fn_call_begin = self.nir.instructions.items.len - 1;
            } else if (ts.ts_node_is_named(curr)) {
                last = try self.expr();
                try self.nir.instructions.append(self.allocator, Inst{
                    .data = InstData{ .brk = .{ .ins = last } },
                    .node = fn_call_node,
                });
            }

            self.block_inline = old_inline;
        }

        const fn_call_2 = InstData{ .fn_call = .{
            .func = func_inst,
            .last = self.nir.instructions.items.len - 1,
        } };

        self.nir.instructions.items[fn_call_begin].data = fn_call_2;

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return fn_call_begin;
    }

    fn binExpr(self: *Self) !usize {
        const bin_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        var lhs_i: usize = undefined;
        var rhs_i: usize = undefined;
        var op_node: ts.TSNode = undefined;

        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == bin_lhs) {
                lhs_i = try self.expr();
            } else if (field_id == bin_op) {
                op_node = current;
            } else if (field_id == bin_rhs) {
                rhs_i = try self.expr();
            }
        }

        const op_type = std.mem.span(ts.ts_node_type(op_node));
        var ins_data: InstData = undefined;

        if (std.mem.eql(u8, op_type, "exp")) {
            ins_data = InstData{ .exp = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "div")) {
            ins_data = InstData{ .div = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "mul")) {
            ins_data = InstData{ .mul = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "minus")) {
            ins_data = InstData{ .sub = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "plus")) {
            ins_data = InstData{ .add = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "geq")) {
            ins_data = InstData{ .geq = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "leq")) {
            ins_data = InstData{ .leq = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "greater")) {
            ins_data = InstData{ .gt = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "less")) {
            ins_data = InstData{ .lt = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "eq")) {
            ins_data = InstData{ .eq = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "neq")) {
            ins_data = InstData{ .neq = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "and")) {
            ins_data = InstData{ .and_ = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "or")) {
            ins_data = InstData{ .or_ = .{ .lhs = lhs_i, .rhs = rhs_i } };
        } else {
            return ParseError.InvalidSource;
        }

        try self.nir.instructions.append(self.allocator, Inst{
            .data = ins_data,
            .node = bin_node,
        });

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.nir.instructions.items.len - 1;
    }

    fn unaryExpr(self: *Self) !usize {
        const unary_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        var rhs_i: usize = undefined;
        var op_node: ts.TSNode = undefined;

        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == bin_op) {
                op_node = current;
            } else if (field_id == expr_field) {
                rhs_i = try self.expr();
            }
        }

        const op_type = std.mem.span(ts.ts_node_type(op_node));
        var ins_data: InstData = undefined;

        if (std.mem.eql(u8, op_type, "bang")) {
            ins_data = InstData{ .ubang = .{ .val = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "minus")) {
            ins_data = InstData{ .uminus = .{ .val = rhs_i } };
        } else if (std.mem.eql(u8, op_type, "plus")) {
            ins_data = InstData{ .uplus = .{ .val = rhs_i } };
        } else {
            return ParseError.InvalidSource;
        }

        try self.nir.instructions.append(self.allocator, Inst{
            .data = ins_data,
            .node = unary_node,
        });

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.nir.instructions.items.len - 1;
    }

    fn ifExpr(self: *Self) !usize {
        const if_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        var cond_i: usize = undefined;
        var true_i: usize = undefined;
        var false_i: usize = undefined;

        const old_inline = self.block_inline;
        self.block_inline = false;
        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == if_cond) {
                cond_i = try self.expr();
            } else if (field_id == if_true) {
                true_i = try self.expr();
            } else if (field_id == if_false) {
                false_i = try self.expr();
            }
        }
        self.block_inline = old_inline;

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .cnd_br = .{ .cnd = cond_i, .t = true_i, .f = false_i },
            },
            .node = if_node,
        });

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.nir.instructions.items.len - 1;
    }

    fn whileStmt(self: *Self) !usize {
        const while_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{ .nop = undefined },
            .node = null,
        });

        var loop_i: usize = self.nir.instructions.items.len - 1;
        var cond_i: usize = undefined;
        var body_i: usize = undefined;

        const old_inline = self.block_inline;
        self.block_inline = false;

        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (field_id == while_cond) {
                cond_i = try self.expr();
            } else if (field_id == while_body) {
                body_i = try self.expr();
            }
        }

        self.block_inline = old_inline;

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .cnd_loop = .{ .cnd = cond_i, .loop = loop_i },
            },
            .node = while_node,
        });

        const loop = Inst{
            .data = InstData{
                .loop = .{ .last = self.nir.instructions.items.len - 1 },
            },
            .node = while_node,
        };

        self.nir.instructions.items[loop_i] = loop;
        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.nir.instructions.items.len - 1;
    }

    fn arrayAccess(self: *Self) !usize {
        const aa_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        var id_i: usize = undefined;
        var index_i: usize = undefined;

        const old_inline = self.block_inline;
        self.block_inline = true;
        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == array_acc_id) {
                id_i = try self.expr();
            } else if (field_id == array_acc_index) {
                index_i = try self.expr();
            }
        }
        self.block_inline = old_inline;

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .offset = .{ .src = id_i, .index = index_i },
            },
            .node = aa_node,
        });

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.nir.instructions.items.len - 1;
    }

    fn copyStrFromSource(self: *Self, node: ts.TSNode) ![2]usize {
        const start = ts.ts_node_start_byte(node);
        const end = ts.ts_node_end_byte(node);
        const start_n = self.nir.strings.items.len;
        try self.nir.strings.appendSlice(self.allocator, self.source[start..end]);
        return .{ start_n, self.nir.strings.items.len };
    }
};

pub const Transpiler = struct {
    const Self = @This();

    allocator: Alloc,
    parser: *ts.TSParser,
    sources: std.StringHashMap([]const u8),
    js_src: ?[]const u8 = null,
    errors: ArrList(SynError),
    importFn: *const fn (name: []const u8) []const u8,

    pub fn init(
        allocator: Alloc,
        necha_src: []const u8,
        importFn: *const fn (name: []const u8) []const u8,
    ) !Self {
        var self = Self{
            .allocator = allocator,
            .parser = ts.ts_parser_new() orelse unreachable,
            .sources = std.StringHashMap([]const u8).init(allocator),
            .js_src = null,
            .importFn = importFn,
            .errors = ArrList(SynError).init(allocator),
        };

        _ = ts.ts_parser_set_language(self.parser, tree_sitter_necha());

        try self.sources.ensureTotalCapacity(@intCast(u32, necha_src.len * 2));
        try self.sources.put("root", necha_src);

        return self;
    }

    pub fn deinit(self: *Self) void {
        ts.ts_parser_delete(self.parser);
        self.sources.deinit();
        if (self.js_src) |s| {
            self.allocator.free(s);
        }
    }

    // TODO create an structure nir generator

};

const JSRunnerError = error{
    RuntimeFail,
    ContextFail,
    RunFail,
};

const JsRunner = struct {
    const Self = @This();

    runtime: *qjs.JSRuntime,
    context: *qjs.JSContext,

    pub fn init() JSRunnerError!Self {
        const load_std =
            \\ import * as std from 'std';
            \\ import * as os from 'os';
            \\ globalThis.std = std;
            \\ globalThis.os = os;
        ;
        var runtime = qjs.JS_NewRuntime() orelse return JSRunnerError.RuntimeFail;

        var js_context = qjs.JS_NewContext(runtime) orelse return JSRunnerError.ContextFail;

        qjs.js_std_init_handlers(runtime);
        _ = qjs.js_init_module_std(js_context, "std");
        _ = qjs.js_init_module_os(js_context, "os");
        qjs.JS_SetModuleLoaderFunc(runtime, null, qjs.js_module_loader, null);
        qjs.js_std_add_helpers(js_context, 0, null);
        const val = qjs.JS_Eval(
            js_context,
            load_std,
            load_std.len,
            "<input>",
            qjs.JS_EVAL_TYPE_MODULE,
        );

        if (qjs.JS_IsException(val) > 0) {
            qjs.js_std_dump_error(js_context);
        }

        return Self{ .runtime = runtime, .context = js_context };
    }

    pub fn deinit(self: *Self) void {
        qjs.JS_FreeContext(self.context);
        qjs.js_std_free_handlers(self.runtime);
        qjs.JS_FreeRuntime(self.runtime);
    }

    pub fn run(self: *Self, js_src: []const u8) !void {
        const val2 = qjs.JS_Eval(self.context, js_src.ptr, js_src.len - 1, "<file>", qjs.JS_EVAL_TYPE_GLOBAL);

        if (qjs.JS_IsException(val2) > 0) {
            qjs.js_std_dump_error(self.context);

            return JSRunnerError.RunFail;
        }

        qjs.js_std_loop(self.context);
    }
};

fn load1(name: []const u8) []const u8 {
    if (std.mem.eql(u8, "root", name)) {
        return "console.log('the root');";
    }

    return "";
}

test "init/deinit" {
    const alloc = std.testing.allocator;
    const src =
        \\var garbage = 1
        \\const b = 2002
        \\var str = "a"
        \\const a = "aa"
        \\var zzz = "world!"
        \\
        \\var br = {
        \\  const z = zzz
        \\  z
        \\}
        \\
        \\var str2 = (a)
        \\var f1 = \abc, abc2. {
        \\  var rrr = abc
        \\  rrr = b
        \\  var zzs = \t. rrr = t
        \\  garbage = 1 + 3 * 5
        \\  b = garbage == 1 and a != "zz"
        \\  zzz = if a == "aa" {
        \\          const p0 = 1
        \\          p0 + garbage
        \\        } else
        \\          0
        \\  rrr = -b
        \\  rrr
        \\}
        \\
        \\var zz = {
        \\  var zrh = 1
        \\  while zrh > 1 {
        \\      log zrh
        \\  }
        \\}
        \\
        \\var a = [1, 2, 3]
        \\var z = a[0]
        \\
        \\var oo = 100
        \\var dd = oo
    ;

    var runner = try JsRunner.init();
    defer runner.deinit();

    var nir = try NirGenerator.gen(alloc, src);
    defer {
        nir.instructions.deinit(alloc);
        nir.strings.deinit(alloc);
        nir.extra.deinit(alloc);
    }

    const nir_src = try nir.toString(alloc);
    defer alloc.free(nir_src);

    std.debug.print("\n{s}\n\n", .{nir_src});
    try std.testing.expectEqual(nir.instructions.items.len, 101);
    try std.testing.expectEqual(nir.strings.items.len, 24);
}

test "hashstack" {
    var sh = try SymbolTable.init(std.testing.allocator, 100);
    defer sh.deinit();
    try sh.put("hola", 10, true);
    try sh.put("chao", 11, true);

    {
        const hola = sh.get("hola") orelse unreachable;
        const chao = sh.get("chao") orelse unreachable;
        try std.testing.expectEqual(hola.ins, 10);
        try std.testing.expectEqual(chao.ins, 11);
        try std.testing.expectEqual(sh.locations.items.len, 3);
    }

    try sh.push();
    try std.testing.expectEqual(sh.stack_pointer, 3);

    try sh.put("hola", 111, true);
    try sh.put("chao", 112, true);
    try sh.put("nihao", 112, true);
    try std.testing.expectEqual(sh.locations.items.len, 7);

    {
        const hola = sh.get("hola") orelse unreachable;
        const chao = sh.get("chao") orelse unreachable;
        try std.testing.expectEqual(hola.ins, 111);
        try std.testing.expectEqual(chao.ins, 112);
        try sh.pop();
        try std.testing.expectEqual(sh.locations.items.len, 3);
        try std.testing.expectEqual(sh.stack_pointer, 0);
    }

    try sh.push();
    try sh.push();
    try sh.pop();
    try sh.pop();

    {
        const hola = sh.get("hola") orelse unreachable;
        const chao = sh.get("chao") orelse unreachable;
        try std.testing.expectEqual(hola.ins, 10);
        try std.testing.expectEqual(chao.ins, 11);
        try std.testing.expectEqual(sh.locations.items.len, 3);
    }

    {
        try sh.push();
        try sh.put("hola", 1000, true);
        const hola = sh.get("hola") orelse unreachable;
        try std.testing.expectEqual(hola.ins, 1000);

        try sh.push();
        try sh.put("hola", 2000, true);
        const hola2 = sh.get("hola") orelse unreachable;
        try std.testing.expectEqual(hola2.ins, 2000);

        try sh.pop();
        const hola3 = sh.get("hola") orelse unreachable;
        try std.testing.expectEqual(hola3.ins, 1000);

        try sh.pop();
        const hola4 = sh.get("hola") orelse unreachable;
        try std.testing.expectEqual(hola4.ins, 10);
    }
}
