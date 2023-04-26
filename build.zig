const std = @import("std");
const log = std.debug.print;

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});

    // Standard release options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall.
    const mode = b.standardOptimizeOption(.{});

    const tree_sitter = b.addStaticLibrary(.{
        .name = "tree-sitter",
        .root_source_file = .{ .path = "src/dummy.zig" },
        .target = target,
        .optimize = mode,
    });
    tree_sitter.addIncludePath("deps/tree-sitter/include");
    tree_sitter.addIncludePath("deps/tree-sitter/src");
    tree_sitter.addCSourceFile("deps/tree-sitter/src/lib.c", &.{"-g"});
    tree_sitter.linkLibC();
    b.installArtifact(tree_sitter);

    const quickjs = b.addStaticLibrary(.{
        .name = "quickjs",
        .root_source_file = .{ .path = "src/dummy.zig" },
        .target = target,
        .optimize = mode,
    });
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
    b.installArtifact(quickjs);

    const exe = b.addExecutable(.{
        .name = "necha",
        .root_source_file = .{ .path = "src/main.zig" },
        .target = target,
        .optimize = mode,
    });
    exe.addIncludePath("deps/tree-sitter/include");
    exe.addIncludePath("deps/quickjs");
    exe.addCSourceFile("tree-sitter-necha/src/parser.c", &.{});
    exe.linkLibC();
    exe.linkLibrary(tree_sitter);
    exe.linkLibrary(quickjs);
    b.installArtifact(exe);

    if (target.getOsTag() == .windows) {
        quickjs.addIncludePath("deps/mingw-w64-winpthreads/include");
        exe.addObjectFile("deps/mingw-w64-winpthreads/lib/libpthread.a");
    }

    const run_cmd = b.addRunArtifact(exe);

    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    const exe_tests = b.addTest(.{
        .name = "test",
        .root_source_file = .{ .path = "src/tests.zig" },
    });
    exe_tests.addIncludePath("deps/tree-sitter/include");
    exe_tests.addIncludePath("deps/quickjs");
    exe_tests.addCSourceFile("tree-sitter-necha/src/parser.c", &.{});
    exe_tests.linkLibC();
    exe_tests.linkLibrary(tree_sitter);
    exe_tests.linkLibrary(quickjs);
    exe_tests.setExecCmd(&.{"echo \"hello\""});

    if (target.getOsTag() == .windows) {
        quickjs.addIncludePath("deps/mingw-w64-winpthreads/include");
        exe_tests.addObjectFile("deps/mingw-w64-winpthreads/lib/libpthread.a");
    }
    const test_step = b.step("test", "Run unit tests");
    test_step.dependOn(&exe_tests.step);
    //    test_step.dependOn(&b.addRunArtifact(exe_tests).step);

    exe.linkLibrary(tree_sitter);

    const deps_step = b.step("deps", "build dependencies as libraries");
    deps_step.dependOn(&tree_sitter.step);
}
