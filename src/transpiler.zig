const std = @import("std");

const nir_ = @import("Nir");
const gen = @import("NirGenerator");

const Nir = nir_.Nir;
const Inst = nir_.Inst;
const InstData = nir_.InstData;
const NirGenerator = gen.NirGenerator;

const Alloc = std.mem.Allocator;
// const string to shut the lsp warning

const ImportFn = *const fn (name: []const u8) []const u8;

pub const Transpiler = struct {
    const Self = @This();

    allocator: Alloc,
    sources: std.StringHashMap([]const u8),
    js_src: ?[]const u8 = null,
    importFn: *const fn (name: []const u8) []const u8,

    pub fn init(
        allocator: Alloc,
        necha_src: []const u8,
        importFn: *const fn (name: []const u8) []const u8,
    ) !Self {
        var self = Self{
            .allocator = allocator,
            .sources = std.StringHashMap([]const u8).init(allocator),
            .js_src = null,
            .importFn = importFn,
        };

        try self.sources.ensureTotalCapacity(@intCast(u32, necha_src.len * 2));
        try self.sources.put("root", necha_src);

        return self;
    }

    pub fn run(self: *Self) !void {
        const nir = NirGenerator.gen(self.allocator, self.sources.get("root"));
        for (nir.instructions.items, 0..) |ins, i| {
            std.debug.print("{d} {s}\n", .{ i, ins });
        }
    }

    pub fn deinit(self: *Self) void {
        self.sources.deinit();
        if (self.js_src) |s| {
            self.allocator.free(s);
        }
    }

    // TODO create an structure nir generator
};

fn load1(name: []const u8) []const u8 {
    if (std.mem.eql(u8, "root", name)) {
        return "console.log('the root');";
    }

    return "";
}
