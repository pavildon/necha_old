const std = @import("std");
const tst = std.testing;
const HashMap = std.AutoHashMapUnmanaged(u64, RegValue);

const Instr = union(enum) {
    number: i64,
    add: struct { lhs: u64, rhs: u64 },
    mul: struct { lhs: u64, rhs: u64 },
    begin_fn: struct { end: u64 },
    end_fn: struct { ret: u64 },
    pop_param: struct { reg: u64 },
    push_param: struct { reg: u64 },
};

const RegValue = union(enum) {
    number: i64,
    reference: u64,
};

const State = struct {
    ip: u64,
    reg: HashMap,
};

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
            },
        };
        return self;
    }

    pub fn run(self: *Self, code: []const Instr) !void {
        while (self._state.ip < code.len) {
            const inst = code[self._state.ip];
            switch (inst) {
                .number => |n| {
                    try self._state.reg.put(self.allocator, self._state.ip, .{ .number = n });
                },
                .add => |m| {
                    const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                    switch (lhs) {
                        .number => |l| {
                            const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                            switch (rhs) {
                                .number => |r| {
                                    try self._state.reg.put(
                                        self.allocator,
                                        self._state.ip,
                                        .{ .number = l + r },
                                    );
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
                },
                .mul => |m| {
                    const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                    switch (lhs) {
                        .number => |l| {
                            const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                            switch (rhs) {
                                .number => |r| {
                                    try self._state.reg.put(
                                        self.allocator,
                                        self._state.ip,
                                        .{ .number = l * r },
                                    );
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
                },
                else => {
                    unreachable;
                },
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
    }
};

test "nothing" {
    const code = [_]Instr{
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
