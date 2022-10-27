const std = @import("std");

// Tree Sitter
const ts = @cImport(@cInclude("tree_sitter/api.h"));

// QuickJS
const qjs = @cImport(@cInclude("quickjs-libc.h"));

const Alloc = std.mem.Allocator;
// const string to shut the lsp warning

extern fn tree_sitter_necha() *const ts.TSLanguage;

const ErrorType = enum {
    SyntaxError,
};

const SynError = struct {
    col: usize,
    row: usize,
    byte: usize,
    t: ErrorType,
};

const ParseError = error{
    InvalidSource,
};

const InstData = union {
    block: struct { start: usize, end: usize },
};

const Inst = struct {
    register: usize,
    data: InstData,
    loc: struct { start: usize, end: usize },
};

const Nir = struct {
    instructions: []const Inst,
};

const SymbolInfo = struct {
    name: []const u8,
    ins: usize,
    next: usize,
};

fn add(a: u32, b: u32) u32 {
    std.debug.print("SSS", .{});
    return a + b;
}

const SymbolTable = struct {
    const Self = @This();
    const PosNextArr = std.ArrayList(SymbolInfo);
    const b = add(1, 3);

    locations: PosNextArr,
    stack_pointer: usize,
    names: std.StringHashMap(usize),

    pub fn init(allocator: Alloc, init_size: usize) !Self {
        var self = Self{
            .locations = try PosNextArr.initCapacity(allocator, init_size),
            .stack_pointer = 0,
            .names = std.StringHashMap(usize).init(allocator),
        };

        try self.locations.append(.{ .name = "root", .ins = 0, .next = 0 });
        return self;
    }

    pub fn put(self: *Self, name: []const u8, instruction: usize) !void {
        const i = self.names.get(name) orelse 0;
        try self.locations.append(.{ .name = name, .ins = instruction, .next = i });
        try self.names.put(name, self.locations.items.len - 1);
    }

    pub fn get(self: *Self, name: []const u8) ?SymbolInfo {
        if (self.names.get(name)) |i| {
            return self.locations.items[i];
        }

        return null;
    }

    pub fn push(self: *Self) !void {
        try self.locations.append(.{ .name = "", .ins = 0, .next = self.stack_pointer });
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

pub const Transpiler = struct {
    const Self = @This();

    allocator: Alloc,
    parser: *ts.TSParser,
    sources: std.StringHashMap([]const u8),
    js_src: ?[]const u8,
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
            .js_src = undefined,
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

    pub fn run(self: *Self) ![]const u8 {
        const src = self.sources.get("root") orelse unreachable;
        const tree: *ts.TSTree = ts.ts_parser_parse_string(
            self.parser,
            null,
            src.ptr,
            @intCast(u32, src.len),
        ).?;
        defer ts.ts_tree_delete(tree);

        const root_node = ts.ts_tree_root_node(tree);
        const root_node_type = ts.ts_node_type(root_node);

        if (!std.mem.eql(u8, "source_file", std.mem.span(root_node_type)))
            return ParseError.InvalidSource;

        var cursor = ts.ts_tree_cursor_new(root_node);
        defer ts.ts_tree_cursor_delete(&cursor);

        var js_src = std.ArrayList(u8).init(self.allocator);
        // TODO tune it
        try js_src.ensureTotalCapacity(src.len * 2);
        defer js_src.deinit();

        var writer = js_src.writer();
        _ = try writer.write("const log = console.log;\n");
        _ = try writer.write("\x00");
        self.js_src = js_src.toOwnedSlice();

        return self.js_src.?;
    }
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

fn load(name: []const u8) []const u8 {
    if (std.mem.eql(u8, "root", name)) {
        return "console.log('the root');";
    }

    return "";
}

test "init/deinit" {
    const alloc = std.testing.allocator;
    const src = "const main = \\. log \"Hello world!\"";

    var runner = try JsRunner.init();
    defer runner.deinit();

    var transpiler = try Transpiler.init(alloc, src, load);
    defer transpiler.deinit();

    // try runner.run("console.log('\\nlala\\n')");

    const js_src = try transpiler.run();
    try runner.run(js_src);
}

test "hashstack" {
    var sh = try SymbolTable.init(std.testing.allocator, 100);
    defer sh.deinit();
    try sh.put("hola", 10);
    try sh.put("chao", 11);

    {
        const hola = sh.get("hola") orelse unreachable;
        const chao = sh.get("chao") orelse unreachable;
        try std.testing.expectEqual(hola.ins, 10);
        try std.testing.expectEqual(chao.ins, 11);
        try std.testing.expectEqual(sh.locations.items.len, 3);
    }

    try sh.push();
    try std.testing.expectEqual(sh.stack_pointer, 3);

    try sh.put("hola", 111);
    try sh.put("chao", 112);
    try sh.put("nihao", 112);
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
        try sh.put("hola", 1000);
        const hola = sh.get("hola") orelse unreachable;
        try std.testing.expectEqual(hola.ins, 1000);

        try sh.push();
        try sh.put("hola", 2000);
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
