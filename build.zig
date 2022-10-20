const std = @import("std");
const log = std.debug.print;

pub fn build(b: *std.build.Builder) void {
    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = b.standardTargetOptions(.{});

    // Standard release options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall.
    const mode = b.standardReleaseOptions();

    const tree_sitter = b.addStaticLibrary("tree-sitter", "src/dummy.zig");
    tree_sitter.addIncludePath("deps/tree-sitter/include");
    tree_sitter.addIncludePath("deps/tree-sitter/src");
    tree_sitter.addCSourceFile("deps/tree-sitter/src/lib.c", &.{"-g"});
    tree_sitter.linkLibC();
    tree_sitter.install();
    tree_sitter.setTarget(target);
    tree_sitter.setBuildMode(mode);

    const quickjs = b.addStaticLibrary("quickjs", "src/dummy.zig");
    quickjs.addIncludePath("deps/quickjs");
    quickjs.disable_sanitize_c = true;
    quickjs.addCSourceFiles(&.{
        "deps/quickjs/cutils.c",
        "deps/quickjs/libbf.c",
        "deps/quickjs/libunicode.c",
        "deps/quickjs/quickjs-libc.c",
        "deps/quickjs/quickjs.c",
        "deps/quickjs/libregexp.c",
    }, &.{
        "-g",
        "-Wall",
        "-D_GNU_SOURCE",
        "-DCONFIG_VERSION=\"2021-03-27\"",
        "-DCONFIG_BIGNUM",
    });
    quickjs.linkLibC();
    quickjs.install();
    quickjs.setTarget(target);
    quickjs.setBuildMode(mode);

    const exe = b.addExecutable("necha", "src/main.zig");
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.addIncludePath("deps/tree-sitter/include");
    exe.addIncludePath("deps/quickjs");
    exe.addCSourceFile("tree-sitter-necha/src/parser.c", &.{});
    exe.linkLibC();
    exe.linkLibrary(tree_sitter);
    exe.linkLibrary(quickjs);
    exe.install();

    if (target.getOsTag() == .windows) {
        quickjs.addIncludePath("deps/mingw-w64-winpthreads/include");
        exe.addObjectFile("deps/mingw-w64-winpthreads/lib/libpthread.a");
    }

    const run_cmd = exe.run();
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    const exe_tests = b.addTest("src/main.zig");
    exe_tests.setTarget(target);
    exe_tests.setBuildMode(mode);

    const test_step = b.step("test", "Run unit tests");
    test_step.dependOn(&exe_tests.step);

    exe.linkLibrary(tree_sitter);

    const deps_step = b.step("deps", "build dependencies as libraries");
    deps_step.dependOn(&tree_sitter.step);
}
