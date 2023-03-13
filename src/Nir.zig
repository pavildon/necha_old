const std = @import("std");

pub const Instr = union(enum) {
    number: u64,

    add: struct { lhs: u64, rhs: u64 },
    mul: struct { lhs: u64, rhs: u64 },

    fun: struct { end: u64 },
    pop_param: struct { nop: u64 },
    ret: struct { reg: u64 },

    begin_call: struct { end: u64 },
    push_param: struct { reg: u64 },
    call: struct { reg: u64 },

    undef: struct { start: u64, end: u64 },
};

pub fn toString(allocator: std.mem.Allocator, instr: []const Instr, source: ?[]const u8) ![]const u8 {
    var result = try std.ArrayListUnmanaged(u8).initCapacity(allocator, 4096);
    var writer = result.writer(allocator);
    for (instr, 0..) |ins, n| {
        switch (ins) {
            .number => |no| _ = try writer.print(
                "{d}. number {d}\n",
                .{ n, no },
            ),
            .add => |a| try writer.print(
                "{d}. add %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .mul => |a| try writer.print(
                "{d}. mul %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .begin_call => |a| try writer.print(
                "{d}. begin_call %{d}\n",
                .{ n, a.end },
            ),
            .push_param => |p| try writer.print(
                "{d}. push_param %{d}\n",
                .{ n, p.reg },
            ),
            .call => |c| try writer.print(
                "{d}. call %{d}\n",
                .{ n, c.reg },
            ),
            .undef => |u| {
                if (source) |src| {
                    try writer.print(
                        "{d}. undef {s}\n",
                        .{ n, src[u.start..u.end] },
                    );
                } else {
                    try writer.print(
                        "{d}. undef source[{d} .. {d}]\n",
                        .{ n, u.start, u.end },
                    );
                }
            },
            else => _ = try writer.print("{d}. unknown\n", .{n}),
        }
    }
    return result.toOwnedSlice(allocator);
}
