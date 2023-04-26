const std = @import("std");

pub const Instr = union(enum) {
    U64: u64,
    I64: i64,
    Bool: bool,

    add: struct { lhs: u64, rhs: u64 },
    mul: struct { lhs: u64, rhs: u64 },
    sub: struct { lhs: u64, rhs: u64 },
    div: struct { lhs: u64, rhs: u64 },
    mod: struct { lhs: u64, rhs: u64 },
    pow: struct { lhs: u64, rhs: u64 },

    not_: struct { reg: u64 },
    nor_: struct { lhs: u64, rhs: u64 },
    or_: struct { lhs: u64, rhs: u64 },
    and_: struct { lhs: u64, rhs: u64 },
    xor_: struct { lhs: u64, rhs: u64 },

    fun: struct { end: u64 },
    pop_param: struct { nop: u64 },
    ret: struct { reg: u64 },

    begin_call: struct { end: u64 },
    push_param: struct { reg: u64 },
    call: struct { reg: u64 },

    cnd: struct { reg: u64, f: u64 },
    brk: struct { reg: u64, end: u64 },

    undef: struct { start: u64, end: u64 },
};

pub fn toString(allocator: std.mem.Allocator, instr: []const Instr, source: ?[]const u8) ![]const u8 {
    var result = try std.ArrayListUnmanaged(u8).initCapacity(allocator, 4096);
    var writer = result.writer(allocator);
    for (instr, 0..) |ins, n| {
        switch (ins) {
            .U64 => |no| _ = try writer.print(
                "{d}. U64 {d}\n",
                .{ n, no },
            ),
            .I64 => |no| _ = try writer.print(
                "{d}. I64 {d}\n",
                .{ n, no },
            ),
            .Bool => |b| _ = try writer.print(
                "{d}. Bool {?}\n",
                .{ n, b },
            ),
            .add => |a| try writer.print(
                "{d}. add %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .mul => |a| try writer.print(
                "{d}. mul %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .sub => |a| try writer.print(
                "{d}. sub %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .div => |a| try writer.print(
                "{d}. div %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .mod => |a| try writer.print(
                "{d}. mod %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .pow => |a| try writer.print(
                "{d}. pow %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .not_ => |a| try writer.print(
                "{d}. not %{d}\n",
                .{ n, a.reg },
            ),
            .nor_ => |a| try writer.print(
                "{d}. nor %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .or_ => |a| try writer.print(
                "{d}. or %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .and_ => |a| try writer.print(
                "{d}. and %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .xor_ => |a| try writer.print(
                "{d}. xor %{d} %{d}\n",
                .{ n, a.lhs, a.rhs },
            ),
            .cnd => |a| try writer.print(
                "{d}. cnd %{d} %{d}\n",
                .{ n, a.reg, a.f },
            ),
            .brk => |a| try writer.print(
                "{d}. brk %{d}\n",
                .{ n, a.reg },
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
            .fun => |f| try writer.print(
                "{d}. fun %{d}\n",
                .{ n, f.end },
            ),
            .pop_param => try writer.print(
                "{d}. pop_param\n",
                .{n},
            ),
            .ret => |r| try writer.print(
                "{d}. ret %{d}\n",
                .{ n, r.reg },
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
            //            else => _ = try writer.print("{d}. unknown\n", .{n}),
        }
    }
    return result.toOwnedSlice(allocator);
}
