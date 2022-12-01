// QuickJS
const qjs = @cImport(@cInclude("quickjs-libc.h"));

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
