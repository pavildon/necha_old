const std = @import("std");

// Tree Sitter
const ts = @cImport(@cInclude("tree_sitter/api.h"));

const Alloc = std.mem.Allocator;

const ErrorType = enum {
    SyntaxError,
};

const SynError = struct {
    loc: usize,
    ty: ErrorType,
};

// TODO change usize to u32 for indices
// TODO change string for one index
pub const InstData = union(enum) {
    nop: void,
    block: struct { last: usize },
    block_inline: struct { last: usize },
    brk: struct { ins: usize },
    loop: struct { last: usize },
    number: u64,
    string: struct { start: usize, end: usize },
    decl_val: struct { start: usize, end: usize },
    param: struct { start: usize, end: usize },
    fn_def: struct { body: usize },

    alloc: void,
    load: struct { src: usize },
    store: struct { src: usize, dst: usize },

    exp: struct { lhs: usize, rhs: usize },
    div: struct { lhs: usize, rhs: usize },
    mul: struct { lhs: usize, rhs: usize },
    sub: struct { lhs: usize, rhs: usize },
    add: struct { lhs: usize, rhs: usize },

    geq: struct { lhs: usize, rhs: usize },
    leq: struct { lhs: usize, rhs: usize },
    gt: struct { lhs: usize, rhs: usize },
    lt: struct { lhs: usize, rhs: usize },
    eq: struct { lhs: usize, rhs: usize },
    neq: struct { lhs: usize, rhs: usize },
    and_: struct { lhs: usize, rhs: usize },
    or_: struct { lhs: usize, rhs: usize },

    uminus: struct { val: usize },
    ubang: struct { val: usize },
    uplus: struct { val: usize },

    cnd_br: struct { cnd: usize, t: usize, f: usize },
    cnd_loop: struct { cnd: usize, loop: usize },
    fn_call: struct { func: usize, last: usize },

    push: struct { src: usize, dst: usize },
    offset: struct { src: usize, index: usize },

    field: struct { src: usize, start: usize, end: usize },
    // TODO change accessor for unified call in the grammar
    unified_call: struct { lhs: usize, rhs: usize },

    pop: struct { src: usize },

    len: struct { src: usize },
    import_file: struct { start: usize },
};

pub const Inst = struct {
    data: InstData,
    node: ?ts.TSNode,
};

pub const Nir = struct {
    instructions: std.ArrayListUnmanaged(Inst),
    imports: std.ArrayListUnmanaged(u8),

    // TODO make string \0x00 terminated string
    strings: std.ArrayListUnmanaged(u8),

    pub fn toString(self: *Nir, allocator: Alloc) ![]const u8 {
        var src = try std.ArrayListUnmanaged(u8).initCapacity(allocator, 4096);
        var writer = src.writer(allocator);

        for (self.instructions.items, 0..) |ins, n| {
            switch (ins.data) {
                .string => |s| _ =
                    try writer.print("%{d}. string \"{s}\"\n", .{
                    n,
                    self.strings.items[s.start..s.end],
                }),
                .number => |no| _ =
                    try writer.print("%{d}. number {d}\n", .{
                    n,
                    no,
                }),
                .alloc => _ =
                    try writer.print("%{d}. alloc\n", .{
                    n,
                }),
                .store => |i| _ =
                    try writer.print("%{d}. store %{d} %{d}\n", .{
                    n,
                    i.src,
                    i.dst,
                }),
                .load => |i| _ =
                    try writer.print("%{d}. load %{d} \n", .{
                    n,
                    i.src,
                }),
                .decl_val => |v| _ =
                    try writer.print("%{d}. decl_val \"{s}\"\n", .{
                    n,
                    self.strings.items[v.start..v.end],
                }),
                .block_inline => |bi| _ =
                    try writer.print("%{d}. block_inline %{d}\n", .{
                    n,
                    bi.last,
                }),
                .block => |b| _ =
                    try writer.print("%{d}. block %{d}\n", .{
                    n,
                    b.last,
                }),
                .brk => |brk| _ =
                    try writer.print("%{d}. break %{d}\n", .{
                    n,
                    brk.ins,
                }),
                .param => |param| _ =
                    try writer.print("%{d}. param \"{s}\"\n", .{
                    n,
                    self.strings.items[param.start..param.end],
                }),
                .fn_def => |fn_def| _ =
                    try writer.print("%{d}. fn %{d}\n", .{
                    n,
                    fn_def.body,
                }),
                .exp => |exp| _ =
                    try writer.print("%{d}. exp %{d} %{d}\n", .{
                    n,
                    exp.lhs,
                    exp.rhs,
                }),
                .div => |div| _ =
                    try writer.print("%{d}. div %{d} %{d}\n", .{
                    n,
                    div.lhs,
                    div.rhs,
                }),
                .mul => |mul| _ =
                    try writer.print("%{d}. mul %{d} %{d}\n", .{
                    n,
                    mul.lhs,
                    mul.rhs,
                }),
                .sub => |sub| _ =
                    try writer.print("%{d}. sub %{d} %{d}\n", .{
                    n,
                    sub.lhs,
                    sub.rhs,
                }),
                .add => |add| _ =
                    try writer.print("%{d}. add %{d} %{d}\n", .{
                    n,
                    add.lhs,
                    add.rhs,
                }),
                .geq => |bin| _ =
                    try writer.print("%{d}. geq %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                .leq => |bin| _ =
                    try writer.print("%{d}. leq %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                .gt => |bin| _ =
                    try writer.print("%{d}. gt %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                .lt => |bin| _ =
                    try writer.print("%{d}. lt %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                .eq => |bin| _ =
                    try writer.print("%{d}. eq %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                .neq => |bin| _ =
                    try writer.print("%{d}. neq %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                .and_ => |bin| _ =
                    try writer.print("%{d}. and %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                .or_ => |bin| _ =
                    try writer.print("%{d}. or %{d} %{d}\n", .{
                    n,
                    bin.lhs,
                    bin.rhs,
                }),
                .cnd_br => |cnd| _ =
                    try writer.print("%{d}. cnd_br %{d} %{d} %{d}\n", .{
                    n,
                    cnd.cnd,
                    cnd.t,
                    cnd.f,
                }),
                .uminus => |u| _ =
                    try writer.print("%{d}. uminus %{d}\n", .{
                    n,
                    u.val,
                }),
                .fn_call => |fc| _ =
                    try writer.print("%{d}. fn_call %{d} %{d}\n", .{
                    n,
                    fc.func,
                    fc.last,
                }),
                .loop => |loop| _ =
                    try writer.print("%{d}. loop %{d}\n", .{
                    n,
                    loop.last,
                }),
                .cnd_loop => |cnd_loop| _ =
                    try writer.print("%{d}. cnd_loop %{d} %{d}\n", .{
                    n,
                    cnd_loop.cnd,
                    cnd_loop.loop,
                }),
                .field => |f| _ =
                    try writer.print("%{d}. field %{d} \"{s}\"\n", .{
                    n,
                    f.src,
                    self.strings.items[f.start..f.end],
                }),
                .push => |pi| _ =
                    try writer.print("%{d}. push %{d} %{d}\n", .{
                    n,
                    pi.src,
                    pi.dst,
                }),
                .len => |l| _ =
                    try writer.print("%{d}. len %{d}\n", .{
                    n,
                    l.src,
                }),
                .offset => |ofs| _ =
                    try writer.print("%{d}. offset %{d} %{d}\n", .{
                    n,
                    ofs.src,
                    ofs.index,
                }),
                .unified_call => |fc| _ =
                    try writer.print("%{d}. u_fn_call %{d} %{d}\n", .{
                    n,
                    fc.lhs,
                    fc.rhs,
                }),
                .import_file => |i| _ =
                    try writer.print("%{d}. import {s}\n", .{
                    n,
                    @ptrCast([*:0]const u8, &self.imports.items[i.start]),
                }),
                else => _ = try writer.print("%{d}. unknown\n", .{n}),
            }
        }
        return src.toOwnedSlice(allocator);
    }
};
