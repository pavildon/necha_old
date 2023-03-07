const std = @import("std");

const log = std.debug.print;
const ph = "parser.h";
const p = @cImport(@cInclude(ph));

// const string to shut the lsp warning
const tsh = "tree_sitter/api.h";
const ts = @cImport(@cInclude(tsh));

const qjstdh = "quickjs-libc.h";
const qjsstd = @cImport(@cInclude(qjstdh));

const MAX_FILE_SIZE: usize = 1024 * 1024;

extern fn tree_sitter_necha() *const ts.TSLanguage;

const fs = std.fs;
const mem = std.mem;

const NechaError = error{
    InvalidSource,
};

fn nechaToJs(allocator: std.mem.Allocator, necha_src: []u8) ![]u8 {
    const parser: *ts.TSParser = ts.ts_parser_new().?;
    defer ts.ts_parser_delete(parser);

    _ = ts.ts_parser_set_language(parser, tree_sitter_necha());

    const tree: *ts.TSTree = ts.ts_parser_parse_string(
        parser,
        null,
        necha_src.ptr,
        @intCast(u32, necha_src.len),
    ).?;
    defer ts.ts_tree_delete(tree);

    const root_node = ts.ts_tree_root_node(tree);
    const root_node_type = ts.ts_node_type(root_node);

    // TODO more information about the error in the upcomming struct
    if (!mem.eql(u8, "source_file", mem.span(root_node_type)))
        return NechaError.InvalidSource;

    var js_src = std.ArrayList(u8).init(allocator);
    //
    // TODO tune this size
    // try js_src.ensureTotalCapacity(necha_src.len * 2);
    var js_wtr = js_src.writer();
    _ = try js_wtr.write("const log = console.log;\n");

    var current_node = ts.ts_node_child(root_node, 0);
    while (!ts.ts_node_is_null(current_node)) {
        const node_type = (ts.ts_node_type(current_node));
        if (mem.eql(u8, "assignment", mem.span(node_type))) {
            try writeAssignment(js_wtr, necha_src, current_node);
        } else {
            log("error {s} \n", .{node_type});
            return NechaError.InvalidSource;
        }

        current_node = ts.ts_node_next_sibling(current_node);
    }

    // TODO prelude idea??
    // the \x00 character to avoid an suspected error in quickjs
    _ = try js_wtr.write("if(main != undefined) { main(); } else { console.log(\"no main function!\"); }\x00");
    const srcs = js_src.toOwnedSlice();
    return srcs;
}

fn writeExpr(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    const node_type = mem.span(ts.ts_node_type(node));

    if (mem.eql(u8, "assignment", node_type)) {
        try writeAssignment(writer, src, node);
    } else if (mem.eql(u8, "function_call", node_type)) {
        try writeFunctionCall(writer, src, node);
    } else if (mem.eql(u8, "function_def", node_type)) {
        try writeFunctionDef(writer, src, node);
    } else if (mem.eql(u8, "math_expr", node_type)) {
        try writeMathExpr(writer, src, node);
    } else if (mem.eql(u8, "boolean_expr", node_type)) {
        try writeBooleanExpr(writer, src, node);
    } else if (mem.eql(u8, "if_expr", node_type)) {
        try writeIfExpr(writer, src, node);
    } else if (mem.eql(u8, "brace_expr", node_type)) {
        try writeBraceExpr(writer, src, node);
    } else if (mem.eql(u8, "unary_expr", node_type)) {
        try writeUnaryExpr(writer, src, node);
    } else if (mem.eql(u8, "bracket_expr", node_type)) {
        try writeBracketExpr(writer, src, node);
    } else if (mem.eql(u8, ")", node_type)) {
        return;
    } else if (mem.eql(u8, "(", node_type)) {
        // TODO paren should be a named expr
        _ = try writer.write("(");
        const n = ts.ts_node_next_sibling(node);
        try writeExpr(writer, src, n);
        _ = try writer.write(")");
    } else if (mem.eql(u8, "string", node_type) or
        mem.eql(u8, "number", node_type) or
        mem.eql(u8, "identifier", node_type) or
        mem.eql(u8, "minus", node_type) or
        mem.eql(u8, "plus", node_type) or
        mem.eql(u8, "bang", node_type))
    {
        try writeSimple(writer, src, node);
    } else {
        log("error {s} \n", .{node_type});
        return NechaError.InvalidSource;
    }
}

fn writeFunctionCall(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    // TODO return naked expr
    {
        const id = ts.ts_node_child_by_field_name(
            node,
            "id",
            2,
        );

        try checkNotNull(id);

        try writeExpr(writer, src, id);
        _ = try writer.write("(");
    }

    {
        // TODO rename arg
        var arg = ts.ts_node_child_by_field_name(
            node,
            "arg",
            3,
        );
        while (checkNotNullNoFail(arg)) {
            if (ts.ts_node_is_named(arg)) {
                try writeExpr(writer, src, arg);
                _ = try writer.write(",");
            }
            arg = ts.ts_node_next_sibling(arg);
        }
    }
    _ = try writer.write(")");
}

fn writeUnaryExpr(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    const op = ts.ts_node_child(node, 0);
    if (ts.ts_node_is_named(op)) {
        _ = try writer.write("(");
        try writeExpr(writer, src, op);
    }

    const next = ts.ts_node_next_sibling(op);
    if (ts.ts_node_is_named(next)) {
        try writeExpr(writer, src, next);
        _ = try writer.write(")");
    }
}

fn writeBracketExpr(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    var cursor = ts.ts_tree_cursor_new(node);
    defer ts.ts_tree_cursor_delete(&cursor);
    var moved = ts.ts_tree_cursor_goto_first_child(&cursor);

    _ = try writer.write("[");
    var arg_count: u8 = 0;

    while (moved) {
        // investigate why sometimes start == end
        const cur_node = ts.ts_tree_cursor_current_node(&cursor);
        moved = ts.ts_tree_cursor_goto_next_sibling(&cursor);

        if (ts.ts_node_is_named(cur_node)) {
            moved = ts.ts_tree_cursor_goto_next_sibling(&cursor);
            if (arg_count > 0) _ = try writer.write(",");
            arg_count = arg_count + 1;
            try writeExpr(writer, src, cur_node);
        }
    }
    _ = try writer.write("]");
}

fn writeBraceExpr(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    var cursor = ts.ts_tree_cursor_new(node);
    defer ts.ts_tree_cursor_delete(&cursor);
    var moved = ts.ts_tree_cursor_goto_first_child(&cursor);

    _ = try writer.write("(()=>{\n");

    while (moved) {
        // investigate why sometimes start == end
        const cur_node = ts.ts_tree_cursor_current_node(&cursor);
        moved = ts.ts_tree_cursor_goto_next_sibling(&cursor);
        const next_node = ts.ts_tree_cursor_current_node(&cursor);

        if (ts.ts_node_is_named(cur_node)) {
            if (ts.ts_node_is_named(next_node)) {
                try writeExpr(writer, src, cur_node);
                _ = try writer.write(";\n");
            } else {
                if (!mem.eql(
                    u8,
                    "assignment",
                    mem.span(ts.ts_node_type(cur_node)),
                ))
                    _ = try writer.write("return ");
                try writeExpr(writer, src, cur_node);
                _ = try writer.write(";\n");
            }
        }
    }
    _ = try writer.write("})()");
}

fn writeIfExpr(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    var cursor = ts.ts_tree_cursor_new(node);
    defer ts.ts_tree_cursor_delete(&cursor);

    var moved = ts.ts_tree_cursor_goto_first_child(&cursor);
    moved = ts.ts_tree_cursor_goto_next_sibling(&cursor);

    var cur_node = ts.ts_tree_cursor_current_node(&cursor);
    _ = try writer.write("(()=>{\n");
    if (ts.ts_node_is_named(cur_node)) {
        _ = try writer.write("const cond = (");
        try writeExpr(writer, src, cur_node);
        _ = try writer.write(");\n");
    }
    moved = ts.ts_tree_cursor_goto_next_sibling(&cursor);
    var ok = ts.ts_tree_cursor_current_node(&cursor);
    while (moved and !ts.ts_node_is_named(ok)) {
        moved = ts.ts_tree_cursor_goto_next_sibling(&cursor);
        ok = ts.ts_tree_cursor_current_node(&cursor);
    }
    moved = ts.ts_tree_cursor_goto_next_sibling(&cursor);
    var ee = ts.ts_tree_cursor_current_node(&cursor);
    while (moved and !ts.ts_node_is_named(ee)) {
        moved = ts.ts_tree_cursor_goto_next_sibling(&cursor);
        ee = ts.ts_tree_cursor_current_node(&cursor);
    }

    _ = try writer.write("if(cond) { return ");
    try writeExpr(writer, src, ok);
    _ = try writer.write(";} else { return ");
    try writeExpr(writer, src, ee);
    _ = try writer.write(";}})()");
}

fn writeFunctionDef(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    var cursor = ts.ts_tree_cursor_new(node);
    defer ts.ts_tree_cursor_delete(&cursor);
    var moved = ts.ts_tree_cursor_goto_first_child(&cursor);

    _ = try writer.write("(");
    var fat_arrow = false;
    var arg_count: u8 = 0;

    while (moved) {
        // investigate why sometimes start == end
        const cur_node = ts.ts_tree_cursor_current_node(&cursor);
        const field_id = ts.ts_tree_cursor_current_field_id(&cursor);
        moved = ts.ts_tree_cursor_goto_next_sibling(&cursor);

        if (field_id == 2 and ts.ts_node_is_named(cur_node)) {
            const start = ts.ts_node_start_byte(cur_node);
            const end = ts.ts_node_end_byte(cur_node);
            if (start != end) {
                arg_count = arg_count + 1;
                _ = try writer.print("{s} ", .{src[start..end]});
                if (arg_count > 0) _ = try writer.write(",");
            }
        } else if (field_id == 3 and ts.ts_node_is_named(cur_node)) {
            if (!fat_arrow) {
                _ = try writer.write(") => {");
                fat_arrow = true;
            }

            const next = ts.ts_tree_cursor_current_node(&cursor);
            if (!moved or ts.ts_node_is_null(next) or !ts.ts_node_is_named(next))
                _ = try writer.write("return ");

            try writeExpr(writer, src, cur_node);
            _ = try writer.write(";");
        }
    }
    _ = try writer.write("}");
    //_ = writer;
}

fn writeSimple(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    const start = ts.ts_node_start_byte(node);
    const end = ts.ts_node_end_byte(node);
    _ = try writer.print("{s}", .{src[start..end]});
}

fn writeBooleanExpr(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    {
        const lhs = ts.ts_node_child_by_field_name(
            node,
            "lhs",
            3,
        );
        const op = ts.ts_node_child_by_field_name(
            node,
            "op",
            2,
        );
        const rhs = ts.ts_node_child_by_field_name(
            node,
            "rhs",
            3,
        );

        try checkNotNull(lhs);
        try checkNotNull(op);
        try checkNotNull(rhs);
        try writeExpr(writer, src, lhs);
        try writeSimple(writer, src, op);
        try writeExpr(writer, src, rhs);
    }
}

fn writeMathExpr(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    // TODO mutable pub
    // TODO errors in the tree
    // TODO field names with ints
    {
        const lhs = ts.ts_node_child_by_field_name(
            node,
            "lhs",
            3,
        );
        const op = ts.ts_node_child_by_field_name(
            node,
            "op",
            2,
        );
        const rhs = ts.ts_node_child_by_field_name(
            node,
            "rhs",
            3,
        );

        try checkNotNull(lhs);
        try checkNotNull(op);
        try checkNotNull(rhs);
        try writeExpr(writer, src, lhs);
        try writeSimple(writer, src, op);
        try writeExpr(writer, src, rhs);
    }
}

fn writeAssignment(
    writer: std.ArrayList(u8).Writer,
    src: []u8,
    node: ts.TSNode,
) anyerror!void {
    // TODO mutable pub
    // TODO errors in the tree
    // TODO field names with ints
    {
        const var_name = ts.ts_node_child_by_field_name(
            node,
            "name",
            4,
        );

        try checkNotNull(var_name);

        const start = ts.ts_node_start_byte(var_name);
        const end = ts.ts_node_end_byte(var_name);
        _ = try writer.print("{s} = ", .{src[start..end]});
    }

    {
        const value = ts.ts_node_child_by_field_name(node, "value", 5);
        try checkNotNull(value);
        try writeExpr(writer, src, value);
    }

    _ = try writer.write(";\n");
}

fn checkNotNull(node: ts.TSNode) !void {
    if (ts.ts_node_is_null(node)) return NechaError.InvalidSource;
}

fn checkNotNullNoFail(node: ts.TSNode) bool {
    return !ts.ts_node_is_null(node);
}

pub fn main() !void {
    const allocator = std.heap.c_allocator;
    var argIter = try std.process.argsWithAllocator(allocator);
    _ = argIter.next();

    const file = (argIter.next()) orelse return error.InvalidSource;

    const cwd = fs.cwd();
    const necha_src = try cwd
        .readFileAlloc(allocator, file, MAX_FILE_SIZE);
    defer allocator.free(necha_src);

    const js_src = try nechaToJs(allocator, necha_src);
    defer allocator.free(js_src);

    {
        const load_std =
            \\ import * as std from 'std';
            \\ import * as os from 'os';
            \\ globalThis.std = std;
            \\ globalThis.os = os;
        ;

        var js_runtime: *qjsstd.JSRuntime = qjsstd.JS_NewRuntime().?;
        defer qjsstd.JS_FreeRuntime(js_runtime);

        var js_context = qjsstd.JS_NewContext(js_runtime);
        defer qjsstd.JS_FreeContext(js_context);

        _ = qjsstd.js_init_module_std(js_context, "std");
        _ = qjsstd.js_init_module_os(js_context, "os");

        qjsstd.js_std_init_handlers(js_runtime);
        defer qjsstd.js_std_free_handlers(js_runtime);

        qjsstd.JS_SetModuleLoaderFunc(js_runtime, null, qjsstd.js_module_loader, null);

        qjsstd.js_std_add_helpers(js_context, 0, null);
        const val = qjsstd.JS_Eval(js_context, load_std, load_std.len, "<input>", qjsstd.JS_EVAL_TYPE_MODULE);
        if (qjsstd.JS_IsException(val) > 0) {
            qjsstd.js_std_dump_error(js_context);
        }

        const val2 = qjsstd.JS_Eval(js_context, js_src.ptr, js_src.len - 1, "<file>", qjsstd.JS_EVAL_TYPE_GLOBAL);
        if (qjsstd.JS_IsException(val2) > 0) {
            qjsstd.js_std_dump_error(js_context);
        }

        qjsstd.js_std_loop(js_context);
    }
}
