const std = @import("std");

pub const Instr = union(enum) {
    number: u64,
    add: struct { lhs: u64, rhs: u64 },
    mul: struct { lhs: u64, rhs: u64 },
    begin_fn: struct { end: u64 },
    end_fn: struct { ret: u64 },
    pop_param: struct { reg: u64 },
    push_param: struct { reg: u64 },
};

pub fn toString(allocator: std.mem.Allocator, instr: []const Instr) ![]const u8 {
    var src = try std.ArrayListUnmanaged(u8).initCapacity(allocator, 4096);
    var writer = src.writer(allocator);
    for (instr, 0..) |ins, n| {
        switch (ins) {
            .number => |no| _ =
                try writer.print("{d}. number {d}\n", .{
                n,
                no,
            }),
            else => _ = try writer.print("{d}. unknown\n", .{n}),
        }
    }
    return src.toOwnedSlice(allocator);
}
const ts = @cImport(@cInclude("tree_sitter/api.h"));

const Alloc = std.mem.Allocator;

const ErrorType = enum {
    SyntaxError,
};

const SynError = struct {
    loc: usize,
    ty: ErrorType,
};
