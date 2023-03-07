const std = @import("std");
// Tree Sitter
const nir = @import("Nir.zig");
const Nir = nir.Nir;
const Inst = nir.Inst;
const InstData = nir.InstData;

const SymbolTable = @import("SymbolTable.zig").SymbolTable;

const ts = @cImport(@cInclude("tree_sitter/api.h"));

const ParseError = error{
    InvalidSource,
};

const Alloc = std.mem.Allocator;

const ArrList = std.ArrayList;

// TODO define these elsewhere
var decl_name: ts.TSFieldId = undefined;
var import_file: ts.TSFieldId = undefined;
var decl_value: ts.TSFieldId = undefined;
var decl_visibility: ts.TSFieldId = undefined;
var decl_mutability: ts.TSFieldId = undefined;
var assig_name: ts.TSFieldId = undefined;
var assig_value: ts.TSFieldId = undefined;

// TODO reaname to param?
var fn_def_arg: ts.TSFieldId = undefined;
var fn_def_body: ts.TSFieldId = undefined;
var while_body: ts.TSFieldId = undefined;

var for_var: ts.TSFieldId = undefined;
var for_expr: ts.TSFieldId = undefined;
var for_body: ts.TSFieldId = undefined;

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

var record_entry_key: ts.TSFieldId = undefined;
var record_entry_value: ts.TSFieldId = undefined;

var array_acc_id: ts.TSFieldId = undefined;
var array_acc_index: ts.TSFieldId = undefined;

extern fn tree_sitter_necha() *const ts.TSLanguage;

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
        import_file = ts.ts_language_field_id_for_name(tree_sitter_necha(), "file", "file".len);
        decl_value = ts.ts_language_field_id_for_name(tree_sitter_necha(), "value", "value".len);
        decl_mutability = ts.ts_language_field_id_for_name(tree_sitter_necha(), "mutability", "mutability".len);
        decl_visibility = ts.ts_language_field_id_for_name(tree_sitter_necha(), "visibility", "visibility".len);

        assig_name = ts.ts_language_field_id_for_name(tree_sitter_necha(), "name", "name".len);
        assig_value = ts.ts_language_field_id_for_name(tree_sitter_necha(), "value", "value".len);
        fn_def_arg = ts.ts_language_field_id_for_name(tree_sitter_necha(), "arg", "arg".len);
        fn_def_body = ts.ts_language_field_id_for_name(tree_sitter_necha(), "body", "body".len);
        while_body = fn_def_body;

        expr_field = ts.ts_language_field_id_for_name(tree_sitter_necha(), "expr", "expr".len);

        for_var = ts.ts_language_field_id_for_name(tree_sitter_necha(), "var", "var".len);
        for_expr = expr_field;
        for_body = fn_def_body;

        bin_lhs = ts.ts_language_field_id_for_name(tree_sitter_necha(), "lhs", "lhs".len);
        bin_op = ts.ts_language_field_id_for_name(tree_sitter_necha(), "op", "op".len);
        bin_rhs = ts.ts_language_field_id_for_name(tree_sitter_necha(), "rhs", "rhs".len);

        if_cond = ts.ts_language_field_id_for_name(tree_sitter_necha(), "condition", "condition".len);
        while_cond = if_cond;

        if_true = ts.ts_language_field_id_for_name(tree_sitter_necha(), "true", "true".len);
        if_false = ts.ts_language_field_id_for_name(tree_sitter_necha(), "false", "false".len);

        fn_call_arg = ts.ts_language_field_id_for_name(tree_sitter_necha(), "arg", "arg".len);
        fn_call_id = ts.ts_language_field_id_for_name(tree_sitter_necha(), "id", "id".len);

        record_entry_key = ts.ts_language_field_id_for_name(tree_sitter_necha(), "key", "key".len);
        record_entry_value = ts.ts_language_field_id_for_name(tree_sitter_necha(), "value", "value".len);

        array_acc_id = fn_call_id;
        array_acc_index = ts.ts_language_field_id_for_name(tree_sitter_necha(), "index", "index".len);

        var generator: NirGenerator = .{
            .allocator = alloc,
            .source = source,
            .cursor = undefined,
            .table = undefined,
            .nir = Nir{
                .instructions = std.ArrayListUnmanaged(Inst){},
                .imports = std.ArrayListUnmanaged(u8){},
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
            .imports = std.ArrayListUnmanaged(u8){},
            .strings = std.ArrayListUnmanaged(u8){},
        };

        self.table = try SymbolTable.init(self.allocator, 1024);
        defer self.table.deinit();

        while (cursor_moved) : (cursor_moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const node = ts.ts_tree_cursor_current_node(&self.cursor);
            const node_type = ts.ts_node_type(node);
            if (std.mem.eql(u8, std.mem.span(node_type), "ERROR")) {
                std.debug.print("Error!", .{});
            } else if (std.mem.eql(u8, std.mem.span(node_type), "declaration")) {
                _ = try self.decl();
            } else if (std.mem.eql(u8, std.mem.span(node_type), "import_decl")) {
                _ = try self.importDecl();
            } else {
                std.debug.print("other!", .{});
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

        if (std.mem.eql(u8, (node_type), "ERROR")) {
            return ParseError.InvalidSource;
        } else if (std.mem.eql(u8, node_type, "declaration")) {
            return try self.decl();
        } else if (std.mem.eql(u8, node_type, "import_decl")) {
            return try self.importDecl();
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
        } else if (std.mem.eql(u8, node_type, "record_expr")) {
            return try self.record();
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
        } else if (std.mem.eql(u8, node_type, "for_stmt")) {
            return try self.forStmt();
        } else if (std.mem.eql(u8, node_type, "while_stmt")) {
            return try self.whileStmt();
        } else if (std.mem.eql(u8, node_type, "array_accessor")) {
            return try self.arrayAccess();
        } else if (std.mem.eql(u8, node_type, "accessor")) {
            return try self.unified();
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
                return location;
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

    fn record(self: *Self) !usize {
        const record_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        try self.nir.instructions.append(self.allocator, Inst{
            .data = .{ .alloc = undefined },
            .node = record_node,
        });

        const record_i = self.nir.instructions.items.len - 1;

        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const curr = ts.ts_tree_cursor_current_node(&self.cursor);

            const old_inline = self.block_inline;
            self.block_inline = true;
            if (ts.ts_node_is_named(curr)) {
                _ = try self.recordEntry(record_i);
            }
            self.block_inline = old_inline;
        }

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return record_i;
    }

    fn recordEntry(self: *Self, record_i: usize) !void {
        const record_entry_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        const old_inline = self.block_inline;
        self.block_inline = true;
        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;
            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == record_entry_key) {
                const key_node = ts.ts_tree_cursor_current_node(&self.cursor);
                const str = try self.copyStrFromSource(key_node);
                try self.nir.instructions.append(self.allocator, Inst{
                    .data = InstData{ .field = .{
                        .src = record_i,
                        .start = str[0],
                        .end = str[1],
                    } },
                    .node = key_node,
                });
            } else if (field_id == record_entry_value) {
                const entry = try self.expr();
                const store = Inst{
                    .data = InstData{ .store = .{
                        .src = entry,
                        .dst = record_i,
                    } },
                    .node = record_entry_node,
                };
                try self.nir.instructions.append(self.allocator, store);
            } else {
                return ParseError.InvalidSource;
            }
        }
        self.block_inline = old_inline;

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
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
        self.block_inline = true;
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

            // TODO pub?
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
                    const old_inline = self.block_inline;
                    self.block_inline = true;
                    const value_idx = try self.expr();
                    self.block_inline = old_inline;
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

    fn importDecl(self: *Self) !usize {
        const decl_node = ts.ts_tree_cursor_current_node(&self.cursor);

        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);
        var name: ?[]const u8 = null;
        var index: usize = 0;

        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            // TODO pub?
            if (field_id == decl_mutability) {
                const mutability_node = ts.ts_tree_cursor_current_node(&self.cursor);
                if (std.mem.eql(u8, std.mem.span(ts.ts_node_type(mutability_node)), "var")) {
                    return ParseError.InvalidSource;
                }
            } else if (field_id == decl_name) {
                const name_node = ts.ts_tree_cursor_current_node(&self.cursor);
                const start = ts.ts_node_start_byte(name_node);
                const end = ts.ts_node_end_byte(name_node);
                name = self.source[start..end];
            } else if (field_id == import_file) {
                if (name) |n| {
                    const start = ts.ts_node_start_byte(current);
                    const end = ts.ts_node_end_byte(current);
                    const store = Inst{
                        .data = InstData{ .import_file = .{
                            .start = self.nir.imports.items.len,
                        } },
                        .node = decl_node,
                    };
                    try self.nir.instructions.append(self.allocator, store);

                    try self.nir.imports.appendSlice(self.allocator, self.source[start..end]);
                    try self.nir.imports.append(self.allocator, 0);

                    try self.table.put(n, index, true);
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
        self.block_inline = true;

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
        return loop_i;
    }

    fn forStmt(self: *Self) !usize {
        const for_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        var loop_i: usize = undefined;

        var item_i: usize = undefined;
        var index_i: usize = undefined;
        var expr_i: usize = undefined;
        var body_i: usize = undefined;

        // TODO var and index in for statement
        try self.table.push();
        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);
            if (field_id == for_var) {
                // item
                try self.nir.instructions.append(
                    self.allocator,
                    Inst{
                        .data = InstData{
                            .alloc = undefined,
                        },
                        .node = current,
                    },
                );
                const start = ts.ts_node_start_byte(current);
                const end = ts.ts_node_start_byte(current);
                item_i = self.nir.instructions.items.len - 1;
                try self.table.put(self.source[start..end], item_i, false);

                // index
                try self.nir.instructions.append(
                    self.allocator,
                    Inst{
                        .data = InstData{
                            .alloc = undefined,
                        },
                        .node = current,
                    },
                );
                index_i = self.nir.instructions.items.len - 1;
            } else if (field_id == for_expr) {
                const old_inline = self.block_inline;
                self.block_inline = true;
                expr_i = try self.expr();
                self.block_inline = old_inline;
            } else if (field_id == for_body) {
                try self.nir.instructions.append(self.allocator, Inst{
                    .data = InstData{ .nop = undefined },
                    .node = null,
                });
                loop_i = self.nir.instructions.items.len - 1;

                const old_inline = self.block_inline;
                self.block_inline = true;
                body_i = try self.expr();
                self.block_inline = old_inline;
            }
        }
        try self.table.pop();

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .load = .{ .src = index_i },
            },
            .node = for_node,
        });
        const l = self.nir.instructions.items.len - 1;

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .number = 1,
            },
            .node = for_node,
        });
        const one = self.nir.instructions.items.len - 1;

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .add = .{ .rhs = l, .lhs = one },
            },
            .node = for_node,
        });
        const sum = self.nir.instructions.items.len - 1;

        // TODO more granularity on the referenced node
        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .len = .{ .src = expr_i },
            },
            .node = for_node,
        });
        const len = self.nir.instructions.items.len - 1;

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .lt = .{ .lhs = sum, .rhs = len },
            },
            .node = for_node,
        });
        const cond_i = self.nir.instructions.items.len - 1;

        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .cnd_loop = .{ .cnd = cond_i, .loop = loop_i },
            },
            .node = for_node,
        });

        const loop = Inst{
            .data = InstData{
                .loop = .{ .last = self.nir.instructions.items.len - 1 },
            },
            .node = for_node,
        };

        self.nir.instructions.items[loop_i] = loop;
        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return loop_i;
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
        const last = self.nir.instructions.items.len - 1;
        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .load = .{ .src = last },
            },
            .node = aa_node,
        });

        _ = ts.ts_tree_cursor_goto_parent(&self.cursor);
        return self.nir.instructions.items.len - 1;
    }

    // TODO rework how field access and function call unify
    fn unified(self: *Self) !usize {
        const fa_node = ts.ts_tree_cursor_current_node(&self.cursor);
        var moved = ts.ts_tree_cursor_goto_first_child(&self.cursor);

        var lhs_i: usize = undefined;
        var rhs_i: usize = undefined;

        const old_inline = self.block_inline;
        self.block_inline = true;
        while (moved) : (moved = ts.ts_tree_cursor_goto_next_sibling(&self.cursor)) {
            const current = ts.ts_tree_cursor_current_node(&self.cursor);
            if (!ts.ts_node_is_named(current)) continue;

            const field_id = ts.ts_tree_cursor_current_field_id(&self.cursor);

            if (field_id == bin_lhs) {
                lhs_i = try self.expr();
            } else if (field_id == bin_rhs) {
                rhs_i = try self.expr();
            }
        }
        self.block_inline = old_inline;

        try self.nir.instructions.append(self.allocator, Inst{
            // WE SWAP RHS AND LHS
            .data = InstData{
                .unified_call = .{ .lhs = rhs_i, .rhs = lhs_i },
            },
            .node = fa_node,
        });

        const last = self.nir.instructions.items.len - 1;
        try self.nir.instructions.append(self.allocator, Inst{
            .data = InstData{
                .load = .{ .src = last },
            },
            .node = fa_node,
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

test "init/deinit" {
    const alloc = std.testing.allocator;
    const src =
        \\const a = import "std"
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
        \\var c = { x: 0, y: 1, z: -1}
        \\var d = {
        \\  for i in a {
        \\      log i
        \\  }
        \\}
    ;

    var nir_ = try NirGenerator.gen(alloc, src);
    defer {
        nir_.instructions.deinit(alloc);
        nir_.imports.deinit(alloc);
        nir_.strings.deinit(alloc);
    }

    const nir_src = try nir_.toString(alloc);
    defer alloc.free(nir_src);
    std.debug.print("\n{s}\n\n", .{nir_src});

    try std.testing.expectEqual(nir_.instructions.items.len, 136);
    try std.testing.expectEqual(nir_.strings.items.len, 31);
}

test "simple" {
    const alloc = std.testing.allocator;
    const src =
        \\const a = 1
        \\const b = 2
        \\const res = a + b
        \\const main = \. log res
    ;

    var nir_ = try NirGenerator.gen(alloc, src);
    defer {
        nir_.instructions.deinit(alloc);
        nir_.imports.deinit(alloc);
        nir_.strings.deinit(alloc);
    }

    const nir_src = try nir_.toString(alloc);
    defer alloc.free(nir_src);

    std.debug.print("\n{s}\n\n", .{nir_src});
}
