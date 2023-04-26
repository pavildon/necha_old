const std = @import("std");
const tst = std.testing;
const HashMap = std.AutoHashMapUnmanaged(u64, RegValue);

const RunnerError = error{
    NotImplemented,
};

const nir = @import("Nir.zig");

const RegValue = union(enum) {
    U64: u64,
    I64: i64,
    Bool: bool,
    reference: u64,
};

const State = struct {
    ip: u64,
    reg: HashMap,
    stack: std.ArrayListUnmanaged(RegValue),
};

const Fn = struct {
    call: fn (state: *State) void,
};

const BinFn = fn (l: u64, r: u64) u64;
const BinBFn = fn (l: bool, r: bool) bool;
const UnaryBFn = fn (l: bool) bool;

fn add(l: u64, r: u64) u64 {
    return l + r;
}

fn mul(l: u64, r: u64) u64 {
    return l * r;
}

fn sub(l: u64, r: u64) u64 {
    return l - r;
}

fn div(l: u64, r: u64) u64 {
    return l / r;
}

fn mod(l: u64, r: u64) u64 {
    return l % r;
}

fn pow(l: u64, r: u64) u64 {
    return std.math.pow(u64, l, r);
}

fn binFn(lhs: RegValue, rhs: RegValue, f: *const BinFn) RegValue {
    switch (lhs) {
        .U64 => |l| {
            switch (rhs) {
                .U64 => |r| {
                    return .{ .U64 = f(l, r) };
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

fn not_(l: bool) bool {
    return !l;
}

fn and_(l: bool, r: bool) bool {
    return l and r;
}

fn or_(l: bool, r: bool) bool {
    return l or r;
}

fn xor_(l: bool, r: bool) bool {
    return l != r;
}

fn nor_(l: bool, r: bool) bool {
    return (!l and !r);
}

fn binBFn(lhs: RegValue, rhs: RegValue, f: *const BinBFn) RegValue {
    switch (lhs) {
        .Bool => |l| {
            switch (rhs) {
                .Bool => |r| {
                    return .{ .Bool = f(l, r) };
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

fn unaryBFn(lhs: RegValue, f: *const UnaryBFn) RegValue {
    switch (lhs) {
        .Bool => |l| {
            return .{ .Bool = f(l) };
        },
        else => {
            unreachable;
        },
    }
}

fn undefn(ctx: *usize, runner: *NirMachine(usize)) void {
    const i = runner._state.ip;
    runner._state.reg.put(runner.allocator, i, .{ .U64 = 20 }) catch unreachable;
    runner._state.ip = ctx.*;
}

pub fn NirMachine(comptime C: type) type {
    return struct {
        const Self = @This();
        const Ctx = C;

        allocator: std.mem.Allocator,
        ctx: *C,
        undef: *const fn (ctx: *C, runner: *Self) void,
        _state: State,

        pub fn init(alloc: std.mem.Allocator, ctx: *C) !Self {
            var self = Self{
                .allocator = alloc,
                .ctx = ctx,
                .undef = undefn,
                ._state = State{
                    .ip = 0,
                    .reg = .{},
                    .stack = try std.ArrayListUnmanaged(RegValue).initCapacity(alloc, 1024),
                },
            };
            return self;
        }

        pub fn run(self: *Self, code: []const nir.Instr) !void {
            while (self._state.ip < code.len) {
                const inst = code[self._state.ip];

                //const i = try nir.toString(self.allocator, &.{inst}, null);
                //defer self.allocator.free(i);
                //std.debug.print("{d} {s}\n", .{ self._state.ip, i });
                switch (inst) {
                    .U64 => |n| {
                        try self._state.reg.put(self.allocator, self._state.ip, .{ .U64 = n });
                    },
                    .I64 => |n| {
                        try self._state.reg.put(self.allocator, self._state.ip, .{ .I64 = n });
                    },
                    .Bool => |b| {
                        try self._state.reg.put(self.allocator, self._state.ip, .{ .Bool = b });
                    },
                    // TODO generalize this for [ui]NN
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
                    .sub => |m| {
                        const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                        const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                        try self._state.reg.put(self.allocator, self._state.ip, binFn(lhs, rhs, sub));
                    },
                    .div => |m| {
                        const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                        const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                        try self._state.reg.put(self.allocator, self._state.ip, binFn(lhs, rhs, div));
                    },
                    .mod => |m| {
                        const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                        const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                        try self._state.reg.put(self.allocator, self._state.ip, binFn(lhs, rhs, mod));
                    },
                    .pow => |m| {
                        const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                        const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                        try self._state.reg.put(self.allocator, self._state.ip, binFn(lhs, rhs, pow));
                    },
                    .not_ => |m| {
                        const lhs = self._state.reg.get(m.reg) orelse unreachable;
                        try self._state.reg.put(self.allocator, self._state.ip, unaryBFn(lhs, not_));
                    },
                    .nor_ => |m| {
                        const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                        const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                        try self._state.reg.put(self.allocator, self._state.ip, binBFn(lhs, rhs, nor_));
                    },
                    .or_ => |m| {
                        const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                        const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                        try self._state.reg.put(self.allocator, self._state.ip, binBFn(lhs, rhs, or_));
                    },
                    .and_ => |m| {
                        const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                        const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                        try self._state.reg.put(self.allocator, self._state.ip, binBFn(lhs, rhs, and_));
                    },
                    .xor_ => |m| {
                        const lhs = self._state.reg.get(m.lhs) orelse unreachable;
                        const rhs = self._state.reg.get(m.rhs) orelse unreachable;
                        try self._state.reg.put(self.allocator, self._state.ip, binBFn(lhs, rhs, xor_));
                    },
                    .fun => |f| {
                        self._state.ip = f.end + 1;
                        continue;
                    },
                    .pop_param => {
                        const reg = self._state.stack.pop();
                        switch (reg) {
                            .reference => |r| {
                                if (self._state.reg.get(r)) |v| {
                                    try self._state.reg.put(
                                        self.allocator,
                                        self._state.ip,
                                        v,
                                    );
                                } else {
                                    try self._state.reg.put(
                                        self.allocator,
                                        self._state.ip,
                                        .{ .reference = r },
                                    );
                                }
                            },
                            else => unreachable,
                        }
                    },
                    .ret => |r| {
                        const dst = self._state.stack.pop();

                        switch (dst) {
                            .reference => |ref| {
                                if (self._state.reg.get(r.reg)) |v| {
                                    try self._state.reg.put(
                                        self.allocator,
                                        ref,
                                        v,
                                    );
                                }
                                self._state.ip = ref + 1;
                                continue;
                            },
                            else => unreachable,
                        }
                    },

                    .begin_call => |bc| {
                        try self._state.stack.append(
                            self.allocator,
                            .{ .reference = bc.end },
                        );
                    },
                    .push_param => |p| {
                        try self._state.stack.append(
                            self.allocator,
                            .{ .reference = p.reg },
                        );
                    },
                    .call => |c| {
                        if (self._state.reg.get(c.reg)) |v| {
                            switch (v) {
                                .reference => |r| {
                                    self._state.ip = r + 1;
                                    continue;
                                },
                                else => unreachable,
                            }
                        } else {
                            switch (code[c.reg]) {
                                .undef => {
                                    self.undef(self.ctx, self);
                                },
                                else => {
                                    self._state.ip = c.reg + 1;
                                },
                            }
                            continue;
                        }
                    },
                    .cnd => |c| {
                        try self._state.stack.append(
                            self.allocator,
                            .{ .reference = self._state.ip },
                        );
                        if (self._state.reg.get(c.reg)) |v| {
                            switch (v) {
                                .Bool => |r| {
                                    if (!r) {
                                        self._state.ip = c.f;
                                    } else {
                                        self._state.ip += 1;
                                    }
                                    continue;
                                },
                                else => unreachable,
                            }
                        } else unreachable;
                    },
                    .brk => |r| {
                        const dst = self._state.stack.pop();
                        switch (dst) {
                            .reference => |ref| {
                                if (self._state.reg.get(r.reg)) |v| {
                                    try self._state.reg.put(
                                        self.allocator,
                                        ref,
                                        v,
                                    );
                                }
                                self._state.ip = r.end + 1;
                                continue;
                            },
                            else => unreachable,
                        }
                    },
                    .undef => {},
                    //                    else => return RunnerError.NotImplemented,
                }

                self._state.ip = self._state.ip + 1;
            }
            return;
        }

        pub fn addUndefFn(self: *Self, f: *const fn (ctx: *C, state: *Self) void) void {
            self.undef = f;
        }

        pub fn state(self: Self) State {
            return self._state;
        }

        pub fn deinit(self: *Self) void {
            self._state.reg.deinit(self.allocator);
            self._state.stack.deinit(self.allocator);
        }

        pub fn printRegs(self: *Self) void {
            for (self._state.keyIterator().items[0..state.reg.size]) |k| {
                std.debug.print("{d}\n", .{k});
            }
        }
    };
}

test "simple" {
    const code = [_]nir.Instr{
        .{ .U64 = 4 },
        .{ .U64 = 10 },
        .{ .add = .{ .lhs = 0, .rhs = 1 } },
        .{ .U64 = 2 },
        .{ .U64 = 3 },
        .{ .mul = .{ .lhs = 3, .rhs = 4 } },
        .{ .Bool = true },
        .{ .Bool = false },
        .{ .xor_ = .{ .lhs = 6, .rhs = 7 } },
        .{ .nor_ = .{ .lhs = 6, .rhs = 7 } },
        .{ .and_ = .{ .lhs = 6, .rhs = 7 } },
        .{ .not_ = .{ .reg = 7 } },
    };

    var ctx: usize = 999;
    var runner = try NirMachine(usize).init(tst.allocator, &ctx);
    defer runner.deinit();

    try runner.run(&code);
    const state = runner.state();

    const sum = state.reg.get(2) orelse unreachable;
    switch (sum) {
        .U64 => |n| {
            try tst.expectEqual(n, 14);
        },
        else => {
            unreachable;
        },
    }
    const prod = state.reg.get(5) orelse unreachable;
    switch (prod) {
        .U64 => |n| {
            try tst.expectEqual(n, 6);
        },
        else => {
            unreachable;
        },
    }
    const b1 = state.reg.get(8) orelse unreachable;
    const b2 = state.reg.get(9) orelse unreachable;
    const b3 = state.reg.get(10) orelse unreachable;
    const b4 = state.reg.get(11) orelse unreachable;
    switch (b1) {
        .Bool => |b| {
            try tst.expectEqual(true, b);
        },
        else => {
            unreachable;
        },
    }
    switch (b2) {
        .Bool => |b| {
            try tst.expectEqual(false, b);
        },
        else => {
            unreachable;
        },
    }
    switch (b3) {
        .Bool => |b| {
            try tst.expectEqual(false, b);
        },
        else => {
            unreachable;
        },
    }
    switch (b4) {
        .Bool => |b| {
            try tst.expectEqual(true, b);
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
        .{ .U64 = 2 }, // 2
        .{ .pow = .{ .lhs = 1, .rhs = 2 } }, // 3
        .{ .ret = .{ .reg = 3 } }, // 4
        .{ .U64 = 10 }, // 5
        .{ .begin_call = .{ .end = 8 } }, // 6
        .{ .push_param = .{ .reg = 5 } }, // 7
        .{ .call = .{ .reg = 0 } }, // 8
    };

    var ctx: usize = 999;
    var runner = try NirMachine(usize).init(tst.allocator, &ctx);
    defer runner.deinit();

    try runner.run(&code);
    const state = runner.state();

    const cv = state.reg.get(8) orelse unreachable;
    switch (cv) {
        .U64 => |n| {
            try tst.expectEqual(n, 100);
        },
        else => {
            unreachable;
        },
    }
}

test "fn apply" {
    const code = [_]nir.Instr{
        .{ .fun = .{ .end = 4 } }, // 0
        .{ .pop_param = .{ .nop = 0 } }, // 1
        .{ .U64 = 2 }, // 2
        .{ .mul = .{ .lhs = 1, .rhs = 2 } }, //3
        .{ .ret = .{ .reg = 3 } }, // 4
        .{ .fun = .{ .end = 11 } }, //5
        .{ .pop_param = .{ .nop = 0 } }, //6
        .{ .pop_param = .{ .nop = 0 } }, //7
        .{ .begin_call = .{ .end = 10 } }, //8
        .{ .push_param = .{ .reg = 7 } }, //9
        .{ .call = .{ .reg = 6 } }, //10
        .{ .ret = .{ .reg = 10 } }, //11
        .{ .begin_call = .{ .end = 16 } }, //12
        .{ .U64 = 10 }, //13
        .{ .push_param = .{ .reg = 13 } }, //14
        .{ .push_param = .{ .reg = 0 } }, //15
        .{ .call = .{ .reg = 5 } }, //16
    };

    var ctx: usize = 999;
    var runner = try NirMachine(usize).init(tst.allocator, &ctx);
    defer runner.deinit();
    runner.addUndefFn(undefn);

    try runner.run(&code);
    const state = runner.state();

    const cv = state.reg.get(16) orelse unreachable;
    switch (cv) {
        .U64 => |n| {
            try tst.expectEqual(@intCast(u64, 20), n);
        },
        else => {
            unreachable;
        },
    }
}

test "undef" {
    const code = [_]nir.Instr{
        .{ .begin_call = .{ .end = 6 } },
        .{ .undef = .{ .start = 0, .end = 10 } },
        .{ .U64 = 10 }, // 2
        .{ .I64 = -2 }, // 3
        .{ .Bool = true }, // 4
        .{ .push_param = .{ .reg = 3 } },
        .{ .push_param = .{ .reg = 2 } },
        .{ .call = .{ .reg = 1 } },
    };

    var ctx: usize = 999;
    var runner = try NirMachine(usize).init(tst.allocator, &ctx);
    defer runner.deinit();
    runner.addUndefFn(undefn);
    try runner.run(&code);
    const state = runner.state();

    const cv = state.reg.get(7) orelse unreachable;
    switch (cv) {
        .U64 => |n| {
            try tst.expectEqual(@intCast(u64, 20), n);
        },
        else => {
            unreachable;
        },
    }
}

test "cnd" {
    const code = [_]nir.Instr{
        .{ .Bool = true }, //0
        .{ .cnd = .{ .reg = 0, .f = 4 } }, //1
        .{ .U64 = 42 }, // 2
        .{ .brk = .{ .reg = 2, .end = 5 } }, // 3
        .{ .U64 = 20 }, // 4
        .{ .brk = .{ .reg = 3, .end = 5 } }, // 5
        .{ .Bool = false }, // 6
        .{ .cnd = .{ .reg = 6, .f = 10 } }, //7
        .{ .U64 = 0 }, // 8
        .{ .brk = .{ .reg = 8, .end = 11 } }, //9
        .{ .U64 = 1337 }, // 10
        .{ .brk = .{ .reg = 10, .end = 11 } }, // 11
    };

    var ctx: usize = 999;
    var runner = try NirMachine(usize).init(tst.allocator, &ctx);
    defer runner.deinit();
    try runner.run(&code);
    const state = runner.state();

    const cnd0 = state.reg.get(1) orelse unreachable;
    const cnd1 = state.reg.get(7) orelse unreachable;
    switch (cnd0) {
        .U64 => |n| {
            try tst.expectEqual(@intCast(u64, 42), n);
        },
        else => {
            unreachable;
        },
    }

    switch (cnd1) {
        .U64 => |n| {
            try tst.expectEqual(@intCast(u64, 1337), n);
        },
        else => {
            unreachable;
        },
    }
}
