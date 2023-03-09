const std = @import("std");

const Alloc = std.mem.Allocator;

pub const SymbolInfo = struct {
    name: []const u8,
    ins: usize,
    is_const: bool,
    next: usize,
};

pub const SymbolTable = struct {
    const Self = @This();
    const PosNextArr = std.ArrayList(SymbolInfo);

    locations: PosNextArr,
    stack_pointer: usize,
    names: std.StringHashMap(usize),

    pub fn init(allocator: Alloc, init_size: usize) !Self {
        var self = Self{
            .locations = try PosNextArr.initCapacity(allocator, init_size),
            .stack_pointer = 0,
            .names = std.StringHashMap(usize).init(allocator),
        };

        try self.locations.append(.{
            .name = "root",
            .ins = 0,
            .is_const = true,
            .next = 0,
        });
        return self;
    }

    pub fn put(self: *Self, name: []const u8, instruction: usize, is_const: bool) !void {
        const i = self.names.get(name) orelse 0;
        try self.locations.append(.{ .name = name, .ins = instruction, .is_const = is_const, .next = i });
        try self.names.put(name, self.locations.items.len - 1);
    }

    pub fn get(self: *Self, name: []const u8) ?SymbolInfo {
        if (self.names.get(name)) |i| {
            return self.locations.items[i];
        }

        return null;
    }

    pub fn push(self: *Self) !void {
        try self.locations.append(.{
            .name = "",
            .ins = 0,
            .is_const = false,
            .next = self.stack_pointer,
        });
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

test "hashstack" {
    var sh = try SymbolTable.init(std.testing.allocator, 100);
    defer sh.deinit();
    try sh.put("hola", 10, true);
    try sh.put("chao", 11, true);

    {
        const hola = sh.get("hola") orelse unreachable;
        const chao = sh.get("chao") orelse unreachable;
        try std.testing.expectEqual(hola.ins, 10);
        try std.testing.expectEqual(chao.ins, 11);
        try std.testing.expectEqual(sh.locations.items.len, 3);
    }

    try sh.push();
    try std.testing.expectEqual(sh.stack_pointer, 3);

    try sh.put("hola", 111, true);
    try sh.put("chao", 112, true);
    try sh.put("nihao", 112, true);
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
        try sh.put("hola", 1000, true);
        const hola = sh.get("hola") orelse unreachable;
        try std.testing.expectEqual(hola.ins, 1000);

        try sh.push();
        try sh.put("hola", 2000, true);
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
