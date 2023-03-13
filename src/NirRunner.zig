const std = @import("std");
const tst = std.testing;
const HashMap = std.AutoHashMapUnmanaged(u64, RegValue);

const nir = @import("Nir.zig");

const RegValue = union(enum) {
    number: u64,
    reference: u64,
};

const State = struct {
    ip: u64,
    reg: HashMap,
    stack: std.ArrayListUnmanaged(u64),
};

const BinFn = fn (l: u64, r: u64) u64;

fn add(l: u64, r: u64) u64 {
    return l + r;
}

fn mul(l: u64, r: u64) u64 {
    return l * r;
}

fn binFn(lhs: RegValue, rhs: RegValue, f: *const BinFn) RegValue {
    switch (lhs) {
        .number => |l| {
            switch (rhs) {
                .number => |r| {
                    return .{ .number = f(l, r) };
                },
                else => {
                    unreachable;
                },
            }
        },
        else => {
            unreachable;
        },
    }
}

// TODO: NirMachine?
pub const NirRunner = struct {
    const Self = @This();

    allocator: std.mem.Allocator,
    _state: State,

    pub fn init(alloc: std.mem.Allocator) !Self {
        var self = Self{
            .allocator = alloc,
            ._state = State{
                .ip = 0,
                .reg = .{},
                .stack = try std.ArrayListUnmanaged(u64).initCapacity(alloc, 1024),
            },
        };
        return self;
    }

    pub fn run(self: *Self, code: []const nir.Instr) !void {
        while (self._state.ip < code.len) {
            const inst = code[self._state.ip];
            switch (inst) {
                .number => |n| {
                    try self._state.reg.put(self.allocator, self._state.ip, .{ .number = n });
                },
                .add => |m| {
                    const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                    const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                    try self._state.reg.put(self.allocator, self._state.ip, binFn(lhs, rhs, add));
                },
                .mul => |m| {
                    const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                    const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                    try self._state.reg.put(self.allocator, self._state.ip, binFn(lhs, rhs, mul));
                },
                .fun => |f| {
                    self._state.ip = f.end + 1;
                    continue;
                },
                .pop_param => {
                    const reg = self._state.stack.pop();
                    if (self._state.reg.get(reg)) |v| {
                        try self._state.reg.put(
                            self.allocator,
                            self._state.ip,
                            v,
                        );
                    }
                },
                .ret => |r| {
                    const dst = self._state.stack.pop();
                    if (self._state.reg.get(r.reg)) |v| {
                        try self._state.reg.put(
                            self.allocator,
                            dst,
                            v,
                        );
                    }
                    self._state.ip = dst + 1;
                    continue;
                },
                .begin_call => |bc| {
                    try self._state.stack.append(
                        self.allocator,
                        bc.end,
                    );
                },
                .push_param => |p| {
                    try self._state.stack.append(
                        self.allocator,
                        p.reg,
                    );
                },
                .call => |c| {
                    self._state.ip = c.reg + 1;
                    continue;
                },
                .undef => {},
            }

            self._state.ip = self._state.ip + 1;
        }
        return;
    }

    pub fn state(self: Self) State {
        return self._state;
    }

    pub fn deinit(self: *Self) void {
        self._state.reg.deinit(self.allocator);
        self._state.stack.deinit(self.allocator);
    }
};

test "simple" {
    const code = [_]nir.Instr{
        .{ .number = 4 },
        .{ .number = 10 },
        .{ .add = .{ .lhs = 0, .rhs = 1 } },
        .{ .number = 2 },
        .{ .number = 3 },
        .{ .mul = .{ .lhs = 3, .rhs = 4 } },
    };

    var runner = try NirRunner.init(tst.allocator);
    defer runner.deinit();

    try runner.run(&code);
    const state = runner.state();

    const sum = state.reg.get(2) orelse unreachable;
    switch (sum) {
        .number => |n| {
            try tst.expectEqual(n, 14);
        },
        else => {
            unreachable;
        },
    }
    const prod = state.reg.get(5) orelse unreachable;
    switch (prod) {
        .number => |n| {
            try tst.expectEqual(n, 6);
        },
        else => {
            unreachable;
        },
    }
}

test "fn_def" {
    const code = [_]nir.Instr{
        .{ .fun = .{ .end = 4 } }, // 0
        .{ .pop_param = .{ .nop = 0 } }, // 1
        .{ .number = 2 }, // 2
        .{ .mul = .{ .lhs = 1, .rhs = 2 } }, // 3
        .{ .ret = .{ .reg = 3 } }, // 4
        .{ .number = 10 }, // 5
        .{ .begin_call = .{ .end = 8 } }, // 6
        .{ .push_param = .{ .reg = 5 } }, // 7
        .{ .call = .{ .reg = 0 } }, // 8
    };

    var runner = try NirRunner.init(tst.allocator);
    defer runner.deinit();

    try runner.run(&code);
    const state = runner.state();

    const cv = state.reg.get(8) orelse unreachable;
    switch (cv) {
        .number => |n| {
            try tst.expectEqual(n, 20);
        },
        else => {
            unreachable;
        },
    }
}
