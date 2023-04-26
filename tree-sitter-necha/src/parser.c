#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 221
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 67
#define ALIAS_COUNT 0
#define TOKEN_COUNT 48
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 15
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 28

enum {
  anon_sym_let = 1,
  anon_sym_and = 2,
  anon_sym_EQ = 3,
  anon_sym_in = 4,
  sym_arrow = 5,
  anon_sym_fn = 6,
  anon_sym_true = 7,
  anon_sym_false = 8,
  anon_sym_if = 9,
  anon_sym_LPAREN = 10,
  anon_sym_RPAREN = 11,
  anon_sym_then = 12,
  anon_sym_else = 13,
  anon_sym_import = 14,
  anon_sym_BSLASH = 15,
  anon_sym_DOT = 16,
  anon_sym_LBRACK = 17,
  anon_sym_RBRACK = 18,
  anon_sym_LBRACE = 19,
  anon_sym_RBRACE = 20,
  anon_sym_COLON = 21,
  anon_sym_COMMA = 22,
  anon_sym_for = 23,
  anon_sym_while = 24,
  sym_pub = 25,
  sym_var = 26,
  sym_const = 27,
  anon_sym_DQUOTE = 28,
  anon_sym_SQUOTE = 29,
  sym_eq = 30,
  sym_neq = 31,
  sym_geq = 32,
  sym_leq = 33,
  sym_greater = 34,
  sym_less = 35,
  anon_sym_AMP_AMP = 36,
  anon_sym_PIPE_PIPE = 37,
  anon_sym_or = 38,
  sym_bang = 39,
  sym_exp = 40,
  sym_minus = 41,
  sym_plus = 42,
  sym_mul = 43,
  sym_div = 44,
  sym_mod = 45,
  sym_identifier = 46,
  aux_sym_number_token1 = 47,
  sym_source_file = 48,
  sym_let_expr = 49,
  sym_fn_call = 50,
  sym_def = 51,
  sym_calc = 52,
  sym_let_in_expr = 53,
  sym_lambda = 54,
  sym_boolean = 55,
  sym_if_expr = 56,
  sym__callable = 57,
  sym__value = 58,
  sym__exprz = 59,
  sym__calc = 60,
  sym_number = 61,
  aux_sym_source_file_repeat1 = 62,
  aux_sym_let_expr_repeat1 = 63,
  aux_sym_fn_call_repeat1 = 64,
  aux_sym_calc_repeat1 = 65,
  aux_sym_lambda_repeat1 = 66,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_let] = "let",
  [anon_sym_and] = "and",
  [anon_sym_EQ] = "=",
  [anon_sym_in] = "in",
  [sym_arrow] = "arrow",
  [anon_sym_fn] = "fn",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_if] = "if",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_then] = "then",
  [anon_sym_else] = "else",
  [anon_sym_import] = "import",
  [anon_sym_BSLASH] = "\\",
  [anon_sym_DOT] = ".",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_COLON] = ":",
  [anon_sym_COMMA] = ",",
  [anon_sym_for] = "for",
  [anon_sym_while] = "while",
  [sym_pub] = "pub",
  [sym_var] = "var",
  [sym_const] = "const",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_eq] = "eq",
  [sym_neq] = "neq",
  [sym_geq] = "geq",
  [sym_leq] = "leq",
  [sym_greater] = "greater",
  [sym_less] = "less",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_or] = "or",
  [sym_bang] = "bang",
  [sym_exp] = "exp",
  [sym_minus] = "minus",
  [sym_plus] = "plus",
  [sym_mul] = "mul",
  [sym_div] = "div",
  [sym_mod] = "mod",
  [sym_identifier] = "identifier",
  [aux_sym_number_token1] = "number_token1",
  [sym_source_file] = "source_file",
  [sym_let_expr] = "let_expr",
  [sym_fn_call] = "fn_call",
  [sym_def] = "def",
  [sym_calc] = "calc",
  [sym_let_in_expr] = "let_in_expr",
  [sym_lambda] = "lambda",
  [sym_boolean] = "boolean",
  [sym_if_expr] = "if_expr",
  [sym__callable] = "_callable",
  [sym__value] = "_value",
  [sym__exprz] = "_exprz",
  [sym__calc] = "_calc",
  [sym_number] = "number",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_let_expr_repeat1] = "let_expr_repeat1",
  [aux_sym_fn_call_repeat1] = "fn_call_repeat1",
  [aux_sym_calc_repeat1] = "calc_repeat1",
  [aux_sym_lambda_repeat1] = "lambda_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_in] = anon_sym_in,
  [sym_arrow] = sym_arrow,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_then] = anon_sym_then,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_while] = anon_sym_while,
  [sym_pub] = sym_pub,
  [sym_var] = sym_var,
  [sym_const] = sym_const,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_eq] = sym_eq,
  [sym_neq] = sym_neq,
  [sym_geq] = sym_geq,
  [sym_leq] = sym_leq,
  [sym_greater] = sym_greater,
  [sym_less] = sym_less,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_or] = anon_sym_or,
  [sym_bang] = sym_bang,
  [sym_exp] = sym_exp,
  [sym_minus] = sym_minus,
  [sym_plus] = sym_plus,
  [sym_mul] = sym_mul,
  [sym_div] = sym_div,
  [sym_mod] = sym_mod,
  [sym_identifier] = sym_identifier,
  [aux_sym_number_token1] = aux_sym_number_token1,
  [sym_source_file] = sym_source_file,
  [sym_let_expr] = sym_let_expr,
  [sym_fn_call] = sym_fn_call,
  [sym_def] = sym_def,
  [sym_calc] = sym_calc,
  [sym_let_in_expr] = sym_let_in_expr,
  [sym_lambda] = sym_lambda,
  [sym_boolean] = sym_boolean,
  [sym_if_expr] = sym_if_expr,
  [sym__callable] = sym__callable,
  [sym__value] = sym__value,
  [sym__exprz] = sym__exprz,
  [sym__calc] = sym__calc,
  [sym_number] = sym_number,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_let_expr_repeat1] = aux_sym_let_expr_repeat1,
  [aux_sym_fn_call_repeat1] = aux_sym_fn_call_repeat1,
  [aux_sym_calc_repeat1] = aux_sym_calc_repeat1,
  [aux_sym_lambda_repeat1] = aux_sym_lambda_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
    .visible = true,
    .named = false,
  },
  [sym_arrow] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_then] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [sym_pub] = {
    .visible = true,
    .named = true,
  },
  [sym_var] = {
    .visible = true,
    .named = true,
  },
  [sym_const] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_eq] = {
    .visible = true,
    .named = true,
  },
  [sym_neq] = {
    .visible = true,
    .named = true,
  },
  [sym_geq] = {
    .visible = true,
    .named = true,
  },
  [sym_leq] = {
    .visible = true,
    .named = true,
  },
  [sym_greater] = {
    .visible = true,
    .named = true,
  },
  [sym_less] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [sym_bang] = {
    .visible = true,
    .named = true,
  },
  [sym_exp] = {
    .visible = true,
    .named = true,
  },
  [sym_minus] = {
    .visible = true,
    .named = true,
  },
  [sym_plus] = {
    .visible = true,
    .named = true,
  },
  [sym_mul] = {
    .visible = true,
    .named = true,
  },
  [sym_div] = {
    .visible = true,
    .named = true,
  },
  [sym_mod] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_number_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_let_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_fn_call] = {
    .visible = true,
    .named = true,
  },
  [sym_def] = {
    .visible = true,
    .named = true,
  },
  [sym_calc] = {
    .visible = true,
    .named = true,
  },
  [sym_let_in_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_lambda] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_if_expr] = {
    .visible = true,
    .named = true,
  },
  [sym__callable] = {
    .visible = false,
    .named = true,
  },
  [sym__value] = {
    .visible = false,
    .named = true,
  },
  [sym__exprz] = {
    .visible = false,
    .named = true,
  },
  [sym__calc] = {
    .visible = false,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_let_expr_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_fn_call_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_calc_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_lambda_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_add = 1,
  field_arrow = 2,
  field_boolean = 3,
  field_calc = 4,
  field_def = 5,
  field_expr = 6,
  field_false = 7,
  field_fn_call = 8,
  field_ident = 9,
  field_if = 10,
  field_lambda = 11,
  field_let_in = 12,
  field_mul = 13,
  field_number = 14,
  field_true = 15,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_add] = "add",
  [field_arrow] = "arrow",
  [field_boolean] = "boolean",
  [field_calc] = "calc",
  [field_def] = "def",
  [field_expr] = "expr",
  [field_false] = "false",
  [field_fn_call] = "fn_call",
  [field_ident] = "ident",
  [field_if] = "if",
  [field_lambda] = "lambda",
  [field_let_in] = "let_in",
  [field_mul] = "mul",
  [field_number] = "number",
  [field_true] = "true",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 1},
  [5] = {.index = 5, .length = 1},
  [6] = {.index = 6, .length = 1},
  [7] = {.index = 7, .length = 1},
  [8] = {.index = 8, .length = 1},
  [9] = {.index = 9, .length = 1},
  [10] = {.index = 10, .length = 1},
  [11] = {.index = 11, .length = 1},
  [12] = {.index = 12, .length = 1},
  [13] = {.index = 13, .length = 3},
  [14] = {.index = 16, .length = 10},
  [15] = {.index = 26, .length = 1},
  [16] = {.index = 27, .length = 4},
  [17] = {.index = 31, .length = 4},
  [18] = {.index = 35, .length = 2},
  [19] = {.index = 37, .length = 6},
  [20] = {.index = 43, .length = 4},
  [21] = {.index = 47, .length = 10},
  [22] = {.index = 57, .length = 10},
  [23] = {.index = 67, .length = 11},
  [24] = {.index = 78, .length = 19},
  [25] = {.index = 97, .length = 19},
  [26] = {.index = 116, .length = 19},
  [27] = {.index = 135, .length = 26},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_def, 1},
  [1] =
    {field_def, 1},
    {field_def, 2},
  [3] =
    {field_add, 0},
  [4] =
    {field_mul, 0},
  [5] =
    {field_ident, 0},
  [6] =
    {field_fn_call, 0},
  [7] =
    {field_calc, 0},
  [8] =
    {field_let_in, 0},
  [9] =
    {field_lambda, 0},
  [10] =
    {field_boolean, 0},
  [11] =
    {field_if, 0},
  [12] =
    {field_ident, 0, .inherited = true},
  [13] =
    {field_boolean, 0, .inherited = true},
    {field_ident, 0, .inherited = true},
    {field_number, 0, .inherited = true},
  [16] =
    {field_boolean, 2, .inherited = true},
    {field_calc, 2, .inherited = true},
    {field_expr, 2},
    {field_fn_call, 2, .inherited = true},
    {field_ident, 0},
    {field_ident, 2, .inherited = true},
    {field_if, 2, .inherited = true},
    {field_lambda, 2, .inherited = true},
    {field_let_in, 2, .inherited = true},
    {field_number, 2, .inherited = true},
  [26] =
    {field_number, 0},
  [27] =
    {field_boolean, 1, .inherited = true},
    {field_ident, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_number, 1, .inherited = true},
  [31] =
    {field_add, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_mul, 0, .inherited = true},
    {field_number, 1, .inherited = true},
  [35] =
    {field_ident, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
  [37] =
    {field_boolean, 0, .inherited = true},
    {field_boolean, 1, .inherited = true},
    {field_ident, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_number, 0, .inherited = true},
    {field_number, 1, .inherited = true},
  [43] =
    {field_ident, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_number, 0, .inherited = true},
    {field_number, 1, .inherited = true},
  [47] =
    {field_boolean, 3, .inherited = true},
    {field_calc, 3, .inherited = true},
    {field_def, 1},
    {field_expr, 3},
    {field_fn_call, 3, .inherited = true},
    {field_ident, 3, .inherited = true},
    {field_if, 3, .inherited = true},
    {field_lambda, 3, .inherited = true},
    {field_let_in, 3, .inherited = true},
    {field_number, 3, .inherited = true},
  [57] =
    {field_arrow, 2},
    {field_boolean, 3, .inherited = true},
    {field_calc, 3, .inherited = true},
    {field_fn_call, 3, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_ident, 3, .inherited = true},
    {field_if, 3, .inherited = true},
    {field_lambda, 3, .inherited = true},
    {field_let_in, 3, .inherited = true},
    {field_number, 3, .inherited = true},
  [67] =
    {field_boolean, 4, .inherited = true},
    {field_calc, 4, .inherited = true},
    {field_def, 1},
    {field_def, 2},
    {field_expr, 4},
    {field_fn_call, 4, .inherited = true},
    {field_ident, 4, .inherited = true},
    {field_if, 4, .inherited = true},
    {field_lambda, 4, .inherited = true},
    {field_let_in, 4, .inherited = true},
    {field_number, 4, .inherited = true},
  [78] =
    {field_boolean, 3, .inherited = true},
    {field_boolean, 5, .inherited = true},
    {field_calc, 3, .inherited = true},
    {field_calc, 5, .inherited = true},
    {field_false, 5},
    {field_fn_call, 3, .inherited = true},
    {field_fn_call, 5, .inherited = true},
    {field_ident, 1},
    {field_ident, 3, .inherited = true},
    {field_ident, 5, .inherited = true},
    {field_if, 3, .inherited = true},
    {field_if, 5, .inherited = true},
    {field_lambda, 3, .inherited = true},
    {field_lambda, 5, .inherited = true},
    {field_let_in, 3, .inherited = true},
    {field_let_in, 5, .inherited = true},
    {field_number, 3, .inherited = true},
    {field_number, 5, .inherited = true},
    {field_true, 3},
  [97] =
    {field_boolean, 3, .inherited = true},
    {field_boolean, 5, .inherited = true},
    {field_calc, 3, .inherited = true},
    {field_calc, 5, .inherited = true},
    {field_false, 5},
    {field_fn_call, 1},
    {field_fn_call, 3, .inherited = true},
    {field_fn_call, 5, .inherited = true},
    {field_ident, 3, .inherited = true},
    {field_ident, 5, .inherited = true},
    {field_if, 3, .inherited = true},
    {field_if, 5, .inherited = true},
    {field_lambda, 3, .inherited = true},
    {field_lambda, 5, .inherited = true},
    {field_let_in, 3, .inherited = true},
    {field_let_in, 5, .inherited = true},
    {field_number, 3, .inherited = true},
    {field_number, 5, .inherited = true},
    {field_true, 3},
  [116] =
    {field_boolean, 1},
    {field_boolean, 3, .inherited = true},
    {field_boolean, 5, .inherited = true},
    {field_calc, 3, .inherited = true},
    {field_calc, 5, .inherited = true},
    {field_false, 5},
    {field_fn_call, 3, .inherited = true},
    {field_fn_call, 5, .inherited = true},
    {field_ident, 3, .inherited = true},
    {field_ident, 5, .inherited = true},
    {field_if, 3, .inherited = true},
    {field_if, 5, .inherited = true},
    {field_lambda, 3, .inherited = true},
    {field_lambda, 5, .inherited = true},
    {field_let_in, 3, .inherited = true},
    {field_let_in, 5, .inherited = true},
    {field_number, 3, .inherited = true},
    {field_number, 5, .inherited = true},
    {field_true, 3},
  [135] =
    {field_boolean, 2, .inherited = true},
    {field_boolean, 5, .inherited = true},
    {field_boolean, 7, .inherited = true},
    {field_calc, 2, .inherited = true},
    {field_calc, 5, .inherited = true},
    {field_calc, 7, .inherited = true},
    {field_false, 7},
    {field_fn_call, 2, .inherited = true},
    {field_fn_call, 5, .inherited = true},
    {field_fn_call, 7, .inherited = true},
    {field_ident, 2, .inherited = true},
    {field_ident, 5, .inherited = true},
    {field_ident, 7, .inherited = true},
    {field_if, 2, .inherited = true},
    {field_if, 5, .inherited = true},
    {field_if, 7, .inherited = true},
    {field_lambda, 2, .inherited = true},
    {field_lambda, 5, .inherited = true},
    {field_lambda, 7, .inherited = true},
    {field_let_in, 2, .inherited = true},
    {field_let_in, 5, .inherited = true},
    {field_let_in, 7, .inherited = true},
    {field_number, 2, .inherited = true},
    {field_number, 5, .inherited = true},
    {field_number, 7, .inherited = true},
    {field_true, 5},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 5,
  [11] = 6,
  [12] = 4,
  [13] = 9,
  [14] = 5,
  [15] = 15,
  [16] = 3,
  [17] = 9,
  [18] = 18,
  [19] = 2,
  [20] = 15,
  [21] = 7,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 15,
  [26] = 8,
  [27] = 7,
  [28] = 5,
  [29] = 23,
  [30] = 24,
  [31] = 18,
  [32] = 18,
  [33] = 2,
  [34] = 6,
  [35] = 4,
  [36] = 3,
  [37] = 22,
  [38] = 2,
  [39] = 22,
  [40] = 15,
  [41] = 24,
  [42] = 4,
  [43] = 23,
  [44] = 18,
  [45] = 6,
  [46] = 24,
  [47] = 3,
  [48] = 23,
  [49] = 22,
  [50] = 7,
  [51] = 9,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 54,
  [56] = 53,
  [57] = 52,
  [58] = 52,
  [59] = 53,
  [60] = 54,
  [61] = 52,
  [62] = 54,
  [63] = 53,
  [64] = 53,
  [65] = 52,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 71,
  [73] = 73,
  [74] = 71,
  [75] = 68,
  [76] = 71,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 78,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 77,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 80,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 79,
  [98] = 68,
  [99] = 73,
  [100] = 67,
  [101] = 77,
  [102] = 80,
  [103] = 78,
  [104] = 69,
  [105] = 70,
  [106] = 80,
  [107] = 107,
  [108] = 73,
  [109] = 67,
  [110] = 68,
  [111] = 79,
  [112] = 80,
  [113] = 78,
  [114] = 77,
  [115] = 69,
  [116] = 70,
  [117] = 117,
  [118] = 79,
  [119] = 69,
  [120] = 120,
  [121] = 70,
  [122] = 107,
  [123] = 107,
  [124] = 68,
  [125] = 80,
  [126] = 78,
  [127] = 107,
  [128] = 77,
  [129] = 70,
  [130] = 77,
  [131] = 78,
  [132] = 73,
  [133] = 68,
  [134] = 67,
  [135] = 79,
  [136] = 80,
  [137] = 69,
  [138] = 120,
  [139] = 139,
  [140] = 117,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 80,
  [145] = 139,
  [146] = 146,
  [147] = 147,
  [148] = 139,
  [149] = 149,
  [150] = 150,
  [151] = 139,
  [152] = 152,
  [153] = 80,
  [154] = 152,
  [155] = 155,
  [156] = 156,
  [157] = 155,
  [158] = 156,
  [159] = 159,
  [160] = 149,
  [161] = 117,
  [162] = 152,
  [163] = 117,
  [164] = 120,
  [165] = 155,
  [166] = 156,
  [167] = 120,
  [168] = 80,
  [169] = 156,
  [170] = 155,
  [171] = 152,
  [172] = 172,
  [173] = 173,
  [174] = 174,
  [175] = 175,
  [176] = 176,
  [177] = 176,
  [178] = 175,
  [179] = 175,
  [180] = 173,
  [181] = 176,
  [182] = 175,
  [183] = 183,
  [184] = 176,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 187,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 186,
  [195] = 189,
  [196] = 196,
  [197] = 188,
  [198] = 193,
  [199] = 189,
  [200] = 188,
  [201] = 201,
  [202] = 196,
  [203] = 188,
  [204] = 186,
  [205] = 201,
  [206] = 196,
  [207] = 187,
  [208] = 193,
  [209] = 201,
  [210] = 196,
  [211] = 187,
  [212] = 193,
  [213] = 191,
  [214] = 186,
  [215] = 191,
  [216] = 189,
  [217] = 191,
  [218] = 192,
  [219] = 201,
  [220] = 220,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(79);
      if (lookahead == '!') ADVANCE(128);
      if (lookahead == '"') ADVANCE(117);
      if (lookahead == '%') ADVANCE(134);
      if (lookahead == '&') ADVANCE(9);
      if (lookahead == '\'') ADVANCE(118);
      if (lookahead == '(') ADVANCE(97);
      if (lookahead == ')') ADVANCE(98);
      if (lookahead == '*') ADVANCE(132);
      if (lookahead == '+') ADVANCE(131);
      if (lookahead == ',') ADVANCE(111);
      if (lookahead == '-') ADVANCE(130);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == '/') ADVANCE(133);
      if (lookahead == ':') ADVANCE(110);
      if (lookahead == '<') ADVANCE(124);
      if (lookahead == '=') ADVANCE(85);
      if (lookahead == '>') ADVANCE(123);
      if (lookahead == '[') ADVANCE(106);
      if (lookahead == '\\') ADVANCE(104);
      if (lookahead == ']') ADVANCE(107);
      if (lookahead == '^') ADVANCE(129);
      if (lookahead == '_') SKIP(71)
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'c') ADVANCE(39);
      if (lookahead == 'e') ADVANCE(33);
      if (lookahead == 'f') ADVANCE(20);
      if (lookahead == 'i') ADVANCE(29);
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 'o') ADVANCE(42);
      if (lookahead == 'p') ADVANCE(52);
      if (lookahead == 't') ADVANCE(31);
      if (lookahead == 'v') ADVANCE(19);
      if (lookahead == 'w') ADVANCE(30);
      if (lookahead == '{') ADVANCE(108);
      if (lookahead == '|') ADVANCE(54);
      if (lookahead == '}') ADVANCE(109);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(57)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(58)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(59)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(60)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(61)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(62)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(63)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(64)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      END_STATE();
    case 9:
      if (lookahead == '&') ADVANCE(125);
      END_STATE();
    case 10:
      if (lookahead == '(') ADVANCE(97);
      if (lookahead == ')') ADVANCE(98);
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(4)
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 't') ADVANCE(150);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 11:
      if (lookahead == ')') ADVANCE(98);
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(7)
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 12:
      if (lookahead == '*') ADVANCE(132);
      if (lookahead == '+') ADVANCE(131);
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '=') ADVANCE(84);
      if (lookahead == '_') SKIP(1)
      if (lookahead == 'f') ADVANCE(135);
      if (lookahead == 'i') ADVANCE(143);
      if (lookahead == 'l') ADVANCE(138);
      if (lookahead == 't') ADVANCE(150);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 13:
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(2)
      if (lookahead == 'a') ADVANCE(147);
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 'i') ADVANCE(148);
      if (lookahead == 't') ADVANCE(150);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 14:
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(3)
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 't') ADVANCE(144);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 15:
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(5)
      if (lookahead == 'e') ADVANCE(146);
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 't') ADVANCE(150);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 16:
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(6)
      if (lookahead == 'a') ADVANCE(147);
      if (lookahead == 'i') ADVANCE(148);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 17:
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(8)
      if (lookahead == 'e') ADVANCE(146);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 18:
      if (lookahead == '>') ADVANCE(88);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(44);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(35);
      if (lookahead == 'n') ADVANCE(89);
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 21:
      if (lookahead == 'b') ADVANCE(114);
      END_STATE();
    case 22:
      if (lookahead == 'd') ADVANCE(82);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(101);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(91);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(93);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(113);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(37);
      END_STATE();
    case 29:
      if (lookahead == 'f') ADVANCE(95);
      if (lookahead == 'm') ADVANCE(41);
      if (lookahead == 'n') ADVANCE(86);
      END_STATE();
    case 30:
      if (lookahead == 'h') ADVANCE(32);
      END_STATE();
    case 31:
      if (lookahead == 'h') ADVANCE(28);
      if (lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 32:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(47);
      END_STATE();
    case 34:
      if (lookahead == 'l') ADVANCE(27);
      END_STATE();
    case 35:
      if (lookahead == 'l') ADVANCE(48);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(99);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(46);
      END_STATE();
    case 39:
      if (lookahead == 'o') ADVANCE(38);
      END_STATE();
    case 40:
      if (lookahead == 'o') ADVANCE(45);
      END_STATE();
    case 41:
      if (lookahead == 'p') ADVANCE(40);
      END_STATE();
    case 42:
      if (lookahead == 'r') ADVANCE(127);
      END_STATE();
    case 43:
      if (lookahead == 'r') ADVANCE(112);
      END_STATE();
    case 44:
      if (lookahead == 'r') ADVANCE(115);
      END_STATE();
    case 45:
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 46:
      if (lookahead == 's') ADVANCE(50);
      END_STATE();
    case 47:
      if (lookahead == 's') ADVANCE(24);
      END_STATE();
    case 48:
      if (lookahead == 's') ADVANCE(26);
      END_STATE();
    case 49:
      if (lookahead == 't') ADVANCE(80);
      END_STATE();
    case 50:
      if (lookahead == 't') ADVANCE(116);
      END_STATE();
    case 51:
      if (lookahead == 't') ADVANCE(103);
      END_STATE();
    case 52:
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 53:
      if (lookahead == 'u') ADVANCE(25);
      END_STATE();
    case 54:
      if (lookahead == '|') ADVANCE(126);
      END_STATE();
    case 55:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(163);
      END_STATE();
    case 56:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(159);
      END_STATE();
    case 57:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(57)
      if (lookahead == '*') ADVANCE(132);
      if (lookahead == '+') ADVANCE(131);
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '=') ADVANCE(84);
      if (lookahead == '_') SKIP(1)
      if (lookahead == 'f') ADVANCE(135);
      if (lookahead == 'i') ADVANCE(143);
      if (lookahead == 'l') ADVANCE(138);
      if (lookahead == 't') ADVANCE(150);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 58:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(58)
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(2)
      if (lookahead == 'a') ADVANCE(147);
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 'i') ADVANCE(148);
      if (lookahead == 't') ADVANCE(150);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 59:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(59)
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(3)
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 't') ADVANCE(144);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 60:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(60)
      if (lookahead == '(') ADVANCE(97);
      if (lookahead == ')') ADVANCE(98);
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(4)
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 't') ADVANCE(150);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 61:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(61)
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(5)
      if (lookahead == 'e') ADVANCE(146);
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 't') ADVANCE(150);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 62:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(62)
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(6)
      if (lookahead == 'a') ADVANCE(147);
      if (lookahead == 'i') ADVANCE(148);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 63:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(63)
      if (lookahead == ')') ADVANCE(98);
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(7)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 64:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(64)
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(8)
      if (lookahead == 'e') ADVANCE(146);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 65:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(160);
      END_STATE();
    case 66:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(158);
      END_STATE();
    case 67:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(164);
      END_STATE();
    case 68:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(162);
      END_STATE();
    case 69:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(163);
      END_STATE();
    case 70:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 71:
      if (eof) ADVANCE(79);
      if (lookahead == '\n') SKIP(76)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(71)
      END_STATE();
    case 72:
      if (eof) ADVANCE(79);
      if (lookahead == '\n') SKIP(77)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(72)
      END_STATE();
    case 73:
      if (eof) ADVANCE(79);
      if (lookahead == '\n') SKIP(78)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(73)
      END_STATE();
    case 74:
      if (eof) ADVANCE(79);
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(72)
      if (lookahead == 'a') ADVANCE(147);
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 'l') ADVANCE(138);
      if (lookahead == 't') ADVANCE(150);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(74)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 75:
      if (eof) ADVANCE(79);
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(73)
      if (lookahead == 'a') ADVANCE(147);
      if (lookahead == 'l') ADVANCE(138);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(75)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 76:
      if (eof) ADVANCE(79);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(76)
      if (lookahead == '!') ADVANCE(128);
      if (lookahead == '"') ADVANCE(117);
      if (lookahead == '%') ADVANCE(134);
      if (lookahead == '&') ADVANCE(9);
      if (lookahead == '\'') ADVANCE(118);
      if (lookahead == '(') ADVANCE(97);
      if (lookahead == ')') ADVANCE(98);
      if (lookahead == '*') ADVANCE(132);
      if (lookahead == '+') ADVANCE(131);
      if (lookahead == ',') ADVANCE(111);
      if (lookahead == '-') ADVANCE(130);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == '/') ADVANCE(133);
      if (lookahead == ':') ADVANCE(110);
      if (lookahead == '<') ADVANCE(124);
      if (lookahead == '=') ADVANCE(85);
      if (lookahead == '>') ADVANCE(123);
      if (lookahead == '[') ADVANCE(106);
      if (lookahead == '\\') ADVANCE(104);
      if (lookahead == ']') ADVANCE(107);
      if (lookahead == '^') ADVANCE(129);
      if (lookahead == '_') SKIP(71)
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'c') ADVANCE(39);
      if (lookahead == 'e') ADVANCE(33);
      if (lookahead == 'f') ADVANCE(20);
      if (lookahead == 'i') ADVANCE(29);
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 'o') ADVANCE(42);
      if (lookahead == 'p') ADVANCE(52);
      if (lookahead == 't') ADVANCE(31);
      if (lookahead == 'v') ADVANCE(19);
      if (lookahead == 'w') ADVANCE(30);
      if (lookahead == '{') ADVANCE(108);
      if (lookahead == '|') ADVANCE(54);
      if (lookahead == '}') ADVANCE(109);
      END_STATE();
    case 77:
      if (eof) ADVANCE(79);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(77)
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(72)
      if (lookahead == 'a') ADVANCE(147);
      if (lookahead == 'f') ADVANCE(136);
      if (lookahead == 'l') ADVANCE(138);
      if (lookahead == 't') ADVANCE(150);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 78:
      if (eof) ADVANCE(79);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(78)
      if (lookahead == '.') ADVANCE(67);
      if (lookahead == '0') ADVANCE(157);
      if (lookahead == '_') SKIP(73)
      if (lookahead == 'a') ADVANCE(147);
      if (lookahead == 'l') ADVANCE(138);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_and);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(119);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_in);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_arrow);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_fn);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_then);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_then);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_else);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_pub);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_var);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_const);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_eq);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_neq);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_geq);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_leq);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_greater);
      if (lookahead == '=') ADVANCE(121);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_less);
      if (lookahead == '=') ADVANCE(122);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_bang);
      if (lookahead == '=') ADVANCE(120);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_exp);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_minus);
      if (lookahead == '>') ADVANCE(88);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_plus);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_mul);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_div);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_mod);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(145);
      if (lookahead == 'n') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(87);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_number_token1);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(165);
      if (lookahead == '0') ADVANCE(162);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(56);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(55);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(65);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(70);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == 'n') ADVANCE(156);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(158);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(165);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(55);
      if (lookahead == '_') ADVANCE(66);
      if (lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(158);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(56);
      if (lookahead == 'n') ADVANCE(156);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(65);
      if (lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(70);
      if (lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(161);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(68);
      if (lookahead == 'n') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(162);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(163);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(55);
      if (lookahead == '_') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(164);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(164);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 12},
  [3] = {.lex_state = 12},
  [4] = {.lex_state = 12},
  [5] = {.lex_state = 12},
  [6] = {.lex_state = 12},
  [7] = {.lex_state = 12},
  [8] = {.lex_state = 12},
  [9] = {.lex_state = 12},
  [10] = {.lex_state = 12},
  [11] = {.lex_state = 12},
  [12] = {.lex_state = 12},
  [13] = {.lex_state = 12},
  [14] = {.lex_state = 12},
  [15] = {.lex_state = 12},
  [16] = {.lex_state = 12},
  [17] = {.lex_state = 12},
  [18] = {.lex_state = 12},
  [19] = {.lex_state = 12},
  [20] = {.lex_state = 12},
  [21] = {.lex_state = 12},
  [22] = {.lex_state = 12},
  [23] = {.lex_state = 12},
  [24] = {.lex_state = 12},
  [25] = {.lex_state = 12},
  [26] = {.lex_state = 12},
  [27] = {.lex_state = 12},
  [28] = {.lex_state = 12},
  [29] = {.lex_state = 12},
  [30] = {.lex_state = 12},
  [31] = {.lex_state = 12},
  [32] = {.lex_state = 12},
  [33] = {.lex_state = 12},
  [34] = {.lex_state = 12},
  [35] = {.lex_state = 12},
  [36] = {.lex_state = 12},
  [37] = {.lex_state = 12},
  [38] = {.lex_state = 12},
  [39] = {.lex_state = 12},
  [40] = {.lex_state = 12},
  [41] = {.lex_state = 12},
  [42] = {.lex_state = 12},
  [43] = {.lex_state = 12},
  [44] = {.lex_state = 12},
  [45] = {.lex_state = 12},
  [46] = {.lex_state = 12},
  [47] = {.lex_state = 12},
  [48] = {.lex_state = 12},
  [49] = {.lex_state = 12},
  [50] = {.lex_state = 12},
  [51] = {.lex_state = 12},
  [52] = {.lex_state = 74},
  [53] = {.lex_state = 74},
  [54] = {.lex_state = 74},
  [55] = {.lex_state = 13},
  [56] = {.lex_state = 13},
  [57] = {.lex_state = 13},
  [58] = {.lex_state = 14},
  [59] = {.lex_state = 10},
  [60] = {.lex_state = 10},
  [61] = {.lex_state = 10},
  [62] = {.lex_state = 15},
  [63] = {.lex_state = 14},
  [64] = {.lex_state = 15},
  [65] = {.lex_state = 15},
  [66] = {.lex_state = 10},
  [67] = {.lex_state = 75},
  [68] = {.lex_state = 74},
  [69] = {.lex_state = 74},
  [70] = {.lex_state = 74},
  [71] = {.lex_state = 10},
  [72] = {.lex_state = 10},
  [73] = {.lex_state = 75},
  [74] = {.lex_state = 10},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 10},
  [77] = {.lex_state = 74},
  [78] = {.lex_state = 74},
  [79] = {.lex_state = 74},
  [80] = {.lex_state = 74},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 13},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 13},
  [98] = {.lex_state = 13},
  [99] = {.lex_state = 16},
  [100] = {.lex_state = 16},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 13},
  [103] = {.lex_state = 13},
  [104] = {.lex_state = 13},
  [105] = {.lex_state = 13},
  [106] = {.lex_state = 15},
  [107] = {.lex_state = 14},
  [108] = {.lex_state = 11},
  [109] = {.lex_state = 11},
  [110] = {.lex_state = 14},
  [111] = {.lex_state = 14},
  [112] = {.lex_state = 75},
  [113] = {.lex_state = 14},
  [114] = {.lex_state = 14},
  [115] = {.lex_state = 10},
  [116] = {.lex_state = 10},
  [117] = {.lex_state = 75},
  [118] = {.lex_state = 10},
  [119] = {.lex_state = 14},
  [120] = {.lex_state = 75},
  [121] = {.lex_state = 15},
  [122] = {.lex_state = 14},
  [123] = {.lex_state = 14},
  [124] = {.lex_state = 10},
  [125] = {.lex_state = 14},
  [126] = {.lex_state = 10},
  [127] = {.lex_state = 14},
  [128] = {.lex_state = 10},
  [129] = {.lex_state = 14},
  [130] = {.lex_state = 15},
  [131] = {.lex_state = 15},
  [132] = {.lex_state = 17},
  [133] = {.lex_state = 15},
  [134] = {.lex_state = 17},
  [135] = {.lex_state = 15},
  [136] = {.lex_state = 10},
  [137] = {.lex_state = 15},
  [138] = {.lex_state = 16},
  [139] = {.lex_state = 11},
  [140] = {.lex_state = 16},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 16},
  [145] = {.lex_state = 11},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 11},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 11},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 17},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 11},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 11},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 11},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 11},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 17},
  [164] = {.lex_state = 11},
  [165] = {.lex_state = 11},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 17},
  [168] = {.lex_state = 11},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 11},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 11},
  [173] = {.lex_state = 11},
  [174] = {.lex_state = 11},
  [175] = {.lex_state = 11},
  [176] = {.lex_state = 11},
  [177] = {.lex_state = 11},
  [178] = {.lex_state = 11},
  [179] = {.lex_state = 11},
  [180] = {.lex_state = 11},
  [181] = {.lex_state = 11},
  [182] = {.lex_state = 11},
  [183] = {.lex_state = 11},
  [184] = {.lex_state = 11},
  [185] = {.lex_state = 11},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 12},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 12},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [sym_arrow] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_then] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [sym_pub] = ACTIONS(1),
    [sym_var] = ACTIONS(1),
    [sym_const] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_eq] = ACTIONS(1),
    [sym_neq] = ACTIONS(1),
    [sym_geq] = ACTIONS(1),
    [sym_leq] = ACTIONS(1),
    [sym_greater] = ACTIONS(1),
    [sym_less] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [sym_bang] = ACTIONS(1),
    [sym_exp] = ACTIONS(1),
    [sym_minus] = ACTIONS(1),
    [sym_plus] = ACTIONS(1),
    [sym_mul] = ACTIONS(1),
    [sym_div] = ACTIONS(1),
    [sym_mod] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(220),
    [sym_let_expr] = STATE(150),
    [aux_sym_source_file_repeat1] = STATE(150),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_let] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 19,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_if,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    STATE(55), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(87), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(151), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [59] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(199), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [118] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    STATE(213), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [177] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(193), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [236] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(194), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [295] = 19,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_if,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    STATE(55), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(85), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(151), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [354] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(39), 1,
      anon_sym_let,
    ACTIONS(41), 1,
      anon_sym_fn,
    ACTIONS(43), 1,
      anon_sym_if,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(54), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(139), 1,
      sym__calc,
    STATE(147), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [413] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(197), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [472] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(198), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [531] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(186), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [590] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    STATE(191), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [649] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(200), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [708] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(212), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [767] = 19,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_if,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    STATE(55), 1,
      sym__callable,
    STATE(81), 1,
      sym__exprz,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(151), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [826] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(216), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [885] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(203), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [944] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(88), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1003] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(87), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1062] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(81), 1,
      sym__exprz,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1121] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(85), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1180] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(83), 1,
      sym__exprz,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1239] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(93), 1,
      sym__exprz,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1298] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(89), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1357] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(39), 1,
      anon_sym_let,
    ACTIONS(41), 1,
      anon_sym_fn,
    ACTIONS(43), 1,
      anon_sym_if,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(54), 1,
      sym__callable,
    STATE(81), 1,
      sym__exprz,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(139), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1416] = 19,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_if,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    STATE(55), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(147), 1,
      sym__exprz,
    STATE(151), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1475] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(39), 1,
      anon_sym_let,
    ACTIONS(41), 1,
      anon_sym_fn,
    ACTIONS(43), 1,
      anon_sym_if,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(54), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(85), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(139), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1534] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(208), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1593] = 19,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_if,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    STATE(55), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(93), 1,
      sym__exprz,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(151), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1652] = 19,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_if,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    STATE(55), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(89), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(151), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1711] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(88), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1770] = 19,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_if,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    STATE(55), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(88), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(151), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1829] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(39), 1,
      anon_sym_let,
    ACTIONS(41), 1,
      anon_sym_fn,
    ACTIONS(43), 1,
      anon_sym_if,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(54), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(87), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(139), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1888] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(214), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [1947] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    STATE(215), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2006] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(195), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2065] = 19,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(9), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      anon_sym_if,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    STATE(55), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(83), 1,
      sym__exprz,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(151), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2124] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(87), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2183] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(39), 1,
      anon_sym_let,
    ACTIONS(41), 1,
      anon_sym_fn,
    ACTIONS(43), 1,
      anon_sym_if,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(54), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(83), 1,
      sym__exprz,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(139), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2242] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(81), 1,
      sym__exprz,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2301] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(89), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2360] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    STATE(217), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2419] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(93), 1,
      sym__exprz,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2478] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(39), 1,
      anon_sym_let,
    ACTIONS(41), 1,
      anon_sym_fn,
    ACTIONS(43), 1,
      anon_sym_if,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(54), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(88), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(139), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2537] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(204), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2596] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(39), 1,
      anon_sym_let,
    ACTIONS(41), 1,
      anon_sym_fn,
    ACTIONS(43), 1,
      anon_sym_if,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(54), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(89), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(139), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2655] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(189), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2714] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(39), 1,
      anon_sym_let,
    ACTIONS(41), 1,
      anon_sym_fn,
    ACTIONS(43), 1,
      anon_sym_if,
    ACTIONS(45), 1,
      sym_identifier,
    STATE(54), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(93), 1,
      sym__exprz,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(139), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2773] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(83), 1,
      sym__exprz,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2832] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      anon_sym_let,
    ACTIONS(33), 1,
      anon_sym_fn,
    ACTIONS(35), 1,
      anon_sym_if,
    ACTIONS(37), 1,
      sym_identifier,
    STATE(60), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(85), 1,
      sym__exprz,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(148), 1,
      sym__calc,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2891] = 19,
    ACTIONS(15), 1,
      sym_plus,
    ACTIONS(17), 1,
      sym_mul,
    ACTIONS(21), 1,
      aux_sym_number_token1,
    ACTIONS(23), 1,
      anon_sym_let,
    ACTIONS(25), 1,
      anon_sym_fn,
    ACTIONS(27), 1,
      anon_sym_if,
    ACTIONS(29), 1,
      sym_identifier,
    STATE(62), 1,
      sym__callable,
    STATE(82), 1,
      sym_boolean,
    STATE(84), 1,
      sym_let_in_expr,
    STATE(90), 1,
      sym_lambda,
    STATE(91), 1,
      sym_fn_call,
    STATE(94), 1,
      sym_calc,
    STATE(95), 1,
      sym_if_expr,
    STATE(96), 1,
      sym__value,
    STATE(101), 1,
      sym_number,
    STATE(145), 1,
      sym__calc,
    STATE(188), 1,
      sym__exprz,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [2950] = 10,
    ACTIONS(47), 1,
      ts_builtin_sym_end,
    ACTIONS(54), 1,
      sym_identifier,
    ACTIONS(57), 1,
      aux_sym_number_token1,
    STATE(52), 1,
      aux_sym_fn_call_repeat1,
    STATE(69), 1,
      sym__callable,
    STATE(70), 1,
      sym__value,
    STATE(77), 1,
      sym_number,
    STATE(78), 1,
      sym_boolean,
    ACTIONS(49), 2,
      anon_sym_let,
      anon_sym_and,
    ACTIONS(51), 2,
      anon_sym_true,
      anon_sym_false,
  [2983] = 10,
    ACTIONS(45), 1,
      sym_identifier,
    ACTIONS(60), 1,
      ts_builtin_sym_end,
    ACTIONS(66), 1,
      aux_sym_number_token1,
    STATE(52), 1,
      aux_sym_fn_call_repeat1,
    STATE(69), 1,
      sym__callable,
    STATE(70), 1,
      sym__value,
    STATE(77), 1,
      sym_number,
    STATE(78), 1,
      sym_boolean,
    ACTIONS(62), 2,
      anon_sym_let,
      anon_sym_and,
    ACTIONS(64), 2,
      anon_sym_true,
      anon_sym_false,
  [3016] = 10,
    ACTIONS(45), 1,
      sym_identifier,
    ACTIONS(66), 1,
      aux_sym_number_token1,
    ACTIONS(68), 1,
      ts_builtin_sym_end,
    STATE(53), 1,
      aux_sym_fn_call_repeat1,
    STATE(69), 1,
      sym__callable,
    STATE(70), 1,
      sym__value,
    STATE(77), 1,
      sym_number,
    STATE(78), 1,
      sym_boolean,
    ACTIONS(64), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(70), 2,
      anon_sym_let,
      anon_sym_and,
  [3049] = 9,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(74), 1,
      aux_sym_number_token1,
    STATE(56), 1,
      aux_sym_fn_call_repeat1,
    STATE(86), 1,
      sym_number,
    STATE(103), 1,
      sym_boolean,
    STATE(104), 1,
      sym__callable,
    STATE(105), 1,
      sym__value,
    ACTIONS(70), 2,
      anon_sym_and,
      anon_sym_in,
    ACTIONS(72), 2,
      anon_sym_true,
      anon_sym_false,
  [3079] = 9,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(74), 1,
      aux_sym_number_token1,
    STATE(57), 1,
      aux_sym_fn_call_repeat1,
    STATE(86), 1,
      sym_number,
    STATE(103), 1,
      sym_boolean,
    STATE(104), 1,
      sym__callable,
    STATE(105), 1,
      sym__value,
    ACTIONS(62), 2,
      anon_sym_and,
      anon_sym_in,
    ACTIONS(72), 2,
      anon_sym_true,
      anon_sym_false,
  [3109] = 9,
    ACTIONS(79), 1,
      sym_identifier,
    ACTIONS(82), 1,
      aux_sym_number_token1,
    STATE(57), 1,
      aux_sym_fn_call_repeat1,
    STATE(86), 1,
      sym_number,
    STATE(103), 1,
      sym_boolean,
    STATE(104), 1,
      sym__callable,
    STATE(105), 1,
      sym__value,
    ACTIONS(49), 2,
      anon_sym_and,
      anon_sym_in,
    ACTIONS(76), 2,
      anon_sym_true,
      anon_sym_false,
  [3139] = 9,
    ACTIONS(49), 1,
      anon_sym_then,
    ACTIONS(88), 1,
      sym_identifier,
    ACTIONS(91), 1,
      aux_sym_number_token1,
    STATE(58), 1,
      aux_sym_fn_call_repeat1,
    STATE(113), 1,
      sym_boolean,
    STATE(114), 1,
      sym_number,
    STATE(119), 1,
      sym__callable,
    STATE(129), 1,
      sym__value,
    ACTIONS(85), 2,
      anon_sym_true,
      anon_sym_false,
  [3168] = 9,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(60), 1,
      anon_sym_RPAREN,
    ACTIONS(96), 1,
      aux_sym_number_token1,
    STATE(61), 1,
      aux_sym_fn_call_repeat1,
    STATE(115), 1,
      sym__callable,
    STATE(116), 1,
      sym__value,
    STATE(126), 1,
      sym_boolean,
    STATE(128), 1,
      sym_number,
    ACTIONS(94), 2,
      anon_sym_true,
      anon_sym_false,
  [3197] = 9,
    ACTIONS(37), 1,
      sym_identifier,
    ACTIONS(68), 1,
      anon_sym_RPAREN,
    ACTIONS(96), 1,
      aux_sym_number_token1,
    STATE(59), 1,
      aux_sym_fn_call_repeat1,
    STATE(115), 1,
      sym__callable,
    STATE(116), 1,
      sym__value,
    STATE(126), 1,
      sym_boolean,
    STATE(128), 1,
      sym_number,
    ACTIONS(94), 2,
      anon_sym_true,
      anon_sym_false,
  [3226] = 9,
    ACTIONS(47), 1,
      anon_sym_RPAREN,
    ACTIONS(101), 1,
      sym_identifier,
    ACTIONS(104), 1,
      aux_sym_number_token1,
    STATE(61), 1,
      aux_sym_fn_call_repeat1,
    STATE(115), 1,
      sym__callable,
    STATE(116), 1,
      sym__value,
    STATE(126), 1,
      sym_boolean,
    STATE(128), 1,
      sym_number,
    ACTIONS(98), 2,
      anon_sym_true,
      anon_sym_false,
  [3255] = 9,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(70), 1,
      anon_sym_else,
    ACTIONS(109), 1,
      aux_sym_number_token1,
    STATE(64), 1,
      aux_sym_fn_call_repeat1,
    STATE(121), 1,
      sym__value,
    STATE(130), 1,
      sym_number,
    STATE(131), 1,
      sym_boolean,
    STATE(137), 1,
      sym__callable,
    ACTIONS(107), 2,
      anon_sym_true,
      anon_sym_false,
  [3284] = 9,
    ACTIONS(62), 1,
      anon_sym_then,
    ACTIONS(113), 1,
      sym_identifier,
    ACTIONS(115), 1,
      aux_sym_number_token1,
    STATE(58), 1,
      aux_sym_fn_call_repeat1,
    STATE(113), 1,
      sym_boolean,
    STATE(114), 1,
      sym_number,
    STATE(119), 1,
      sym__callable,
    STATE(129), 1,
      sym__value,
    ACTIONS(111), 2,
      anon_sym_true,
      anon_sym_false,
  [3313] = 9,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(62), 1,
      anon_sym_else,
    ACTIONS(109), 1,
      aux_sym_number_token1,
    STATE(65), 1,
      aux_sym_fn_call_repeat1,
    STATE(121), 1,
      sym__value,
    STATE(130), 1,
      sym_number,
    STATE(131), 1,
      sym_boolean,
    STATE(137), 1,
      sym__callable,
    ACTIONS(107), 2,
      anon_sym_true,
      anon_sym_false,
  [3342] = 9,
    ACTIONS(49), 1,
      anon_sym_else,
    ACTIONS(120), 1,
      sym_identifier,
    ACTIONS(123), 1,
      aux_sym_number_token1,
    STATE(65), 1,
      aux_sym_fn_call_repeat1,
    STATE(121), 1,
      sym__value,
    STATE(130), 1,
      sym_number,
    STATE(131), 1,
      sym_boolean,
    STATE(137), 1,
      sym__callable,
    ACTIONS(117), 2,
      anon_sym_true,
      anon_sym_false,
  [3371] = 8,
    ACTIONS(113), 1,
      sym_identifier,
    ACTIONS(115), 1,
      aux_sym_number_token1,
    STATE(63), 1,
      aux_sym_fn_call_repeat1,
    STATE(113), 1,
      sym_boolean,
    STATE(114), 1,
      sym_number,
    STATE(119), 1,
      sym__callable,
    STATE(129), 1,
      sym__value,
    ACTIONS(111), 2,
      anon_sym_true,
      anon_sym_false,
  [3397] = 6,
    ACTIONS(126), 1,
      ts_builtin_sym_end,
    ACTIONS(130), 1,
      sym_identifier,
    ACTIONS(133), 1,
      aux_sym_number_token1,
    STATE(67), 1,
      aux_sym_calc_repeat1,
    STATE(120), 1,
      sym_number,
    ACTIONS(128), 2,
      anon_sym_let,
      anon_sym_and,
  [3417] = 2,
    ACTIONS(136), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(138), 5,
      anon_sym_let,
      anon_sym_and,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3429] = 2,
    ACTIONS(68), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(70), 5,
      anon_sym_let,
      anon_sym_and,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3441] = 2,
    ACTIONS(140), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(142), 5,
      anon_sym_let,
      anon_sym_and,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3453] = 6,
    ACTIONS(144), 1,
      anon_sym_LPAREN,
    ACTIONS(146), 1,
      sym_identifier,
    STATE(66), 1,
      sym__callable,
    STATE(209), 1,
      sym_fn_call,
    STATE(210), 1,
      sym_boolean,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [3473] = 6,
    ACTIONS(148), 1,
      anon_sym_LPAREN,
    ACTIONS(150), 1,
      sym_identifier,
    STATE(66), 1,
      sym__callable,
    STATE(205), 1,
      sym_fn_call,
    STATE(206), 1,
      sym_boolean,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [3493] = 6,
    ACTIONS(152), 1,
      ts_builtin_sym_end,
    ACTIONS(156), 1,
      sym_identifier,
    ACTIONS(158), 1,
      aux_sym_number_token1,
    STATE(67), 1,
      aux_sym_calc_repeat1,
    STATE(120), 1,
      sym_number,
    ACTIONS(154), 2,
      anon_sym_let,
      anon_sym_and,
  [3513] = 6,
    ACTIONS(160), 1,
      anon_sym_LPAREN,
    ACTIONS(162), 1,
      sym_identifier,
    STATE(66), 1,
      sym__callable,
    STATE(201), 1,
      sym_fn_call,
    STATE(202), 1,
      sym_boolean,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [3533] = 1,
    ACTIONS(136), 7,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_then,
      anon_sym_else,
  [3543] = 6,
    ACTIONS(164), 1,
      anon_sym_LPAREN,
    ACTIONS(166), 1,
      sym_identifier,
    STATE(66), 1,
      sym__callable,
    STATE(196), 1,
      sym_boolean,
    STATE(219), 1,
      sym_fn_call,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
  [3563] = 2,
    ACTIONS(168), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(170), 5,
      anon_sym_let,
      anon_sym_and,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3575] = 2,
    ACTIONS(172), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(174), 5,
      anon_sym_let,
      anon_sym_and,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3587] = 2,
    ACTIONS(176), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(178), 5,
      anon_sym_let,
      anon_sym_and,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3599] = 2,
    ACTIONS(180), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(182), 5,
      anon_sym_let,
      anon_sym_and,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3611] = 1,
    ACTIONS(184), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3620] = 1,
    ACTIONS(172), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3629] = 1,
    ACTIONS(186), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3638] = 1,
    ACTIONS(188), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3647] = 1,
    ACTIONS(190), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3656] = 2,
    ACTIONS(168), 1,
      aux_sym_number_token1,
    ACTIONS(170), 5,
      anon_sym_and,
      anon_sym_in,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3667] = 1,
    ACTIONS(192), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3676] = 1,
    ACTIONS(194), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3685] = 1,
    ACTIONS(196), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3694] = 1,
    ACTIONS(198), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3703] = 1,
    ACTIONS(200), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3712] = 1,
    ACTIONS(180), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3721] = 1,
    ACTIONS(202), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3730] = 1,
    ACTIONS(204), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3739] = 1,
    ACTIONS(206), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3748] = 1,
    ACTIONS(208), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3757] = 2,
    ACTIONS(176), 1,
      aux_sym_number_token1,
    ACTIONS(178), 5,
      anon_sym_and,
      anon_sym_in,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3768] = 2,
    ACTIONS(136), 1,
      aux_sym_number_token1,
    ACTIONS(138), 5,
      anon_sym_and,
      anon_sym_in,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3779] = 5,
    ACTIONS(210), 1,
      sym_identifier,
    ACTIONS(212), 1,
      aux_sym_number_token1,
    STATE(100), 1,
      aux_sym_calc_repeat1,
    STATE(138), 1,
      sym_number,
    ACTIONS(154), 2,
      anon_sym_and,
      anon_sym_in,
  [3796] = 5,
    ACTIONS(214), 1,
      sym_identifier,
    ACTIONS(217), 1,
      aux_sym_number_token1,
    STATE(100), 1,
      aux_sym_calc_repeat1,
    STATE(138), 1,
      sym_number,
    ACTIONS(128), 2,
      anon_sym_and,
      anon_sym_in,
  [3813] = 1,
    ACTIONS(168), 6,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
      anon_sym_RPAREN,
      anon_sym_else,
  [3822] = 2,
    ACTIONS(180), 1,
      aux_sym_number_token1,
    ACTIONS(182), 5,
      anon_sym_and,
      anon_sym_in,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3833] = 2,
    ACTIONS(172), 1,
      aux_sym_number_token1,
    ACTIONS(174), 5,
      anon_sym_and,
      anon_sym_in,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3844] = 2,
    ACTIONS(68), 1,
      aux_sym_number_token1,
    ACTIONS(70), 5,
      anon_sym_and,
      anon_sym_in,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3855] = 2,
    ACTIONS(140), 1,
      aux_sym_number_token1,
    ACTIONS(142), 5,
      anon_sym_and,
      anon_sym_in,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3866] = 2,
    ACTIONS(180), 1,
      aux_sym_number_token1,
    ACTIONS(182), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_else,
      sym_identifier,
  [3876] = 3,
    ACTIONS(176), 1,
      aux_sym_number_token1,
    ACTIONS(220), 1,
      anon_sym_then,
    ACTIONS(178), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3888] = 5,
    ACTIONS(152), 1,
      anon_sym_RPAREN,
    ACTIONS(222), 1,
      sym_identifier,
    ACTIONS(224), 1,
      aux_sym_number_token1,
    STATE(109), 1,
      aux_sym_calc_repeat1,
    STATE(164), 1,
      sym_number,
  [3904] = 5,
    ACTIONS(126), 1,
      anon_sym_RPAREN,
    ACTIONS(226), 1,
      sym_identifier,
    ACTIONS(229), 1,
      aux_sym_number_token1,
    STATE(109), 1,
      aux_sym_calc_repeat1,
    STATE(164), 1,
      sym_number,
  [3920] = 2,
    ACTIONS(136), 1,
      aux_sym_number_token1,
    ACTIONS(138), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_then,
      sym_identifier,
  [3930] = 2,
    ACTIONS(176), 1,
      aux_sym_number_token1,
    ACTIONS(178), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_then,
      sym_identifier,
  [3940] = 2,
    ACTIONS(180), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(182), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [3950] = 2,
    ACTIONS(172), 1,
      aux_sym_number_token1,
    ACTIONS(174), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_then,
      sym_identifier,
  [3960] = 2,
    ACTIONS(168), 1,
      aux_sym_number_token1,
    ACTIONS(170), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_then,
      sym_identifier,
  [3970] = 2,
    ACTIONS(68), 2,
      anon_sym_RPAREN,
      aux_sym_number_token1,
    ACTIONS(70), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3980] = 2,
    ACTIONS(140), 2,
      anon_sym_RPAREN,
      aux_sym_number_token1,
    ACTIONS(142), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [3990] = 2,
    ACTIONS(232), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(234), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [4000] = 2,
    ACTIONS(176), 2,
      anon_sym_RPAREN,
      aux_sym_number_token1,
    ACTIONS(178), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [4010] = 2,
    ACTIONS(68), 1,
      aux_sym_number_token1,
    ACTIONS(70), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_then,
      sym_identifier,
  [4020] = 2,
    ACTIONS(236), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(238), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [4030] = 2,
    ACTIONS(140), 1,
      aux_sym_number_token1,
    ACTIONS(142), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_else,
      sym_identifier,
  [4040] = 3,
    ACTIONS(176), 1,
      aux_sym_number_token1,
    ACTIONS(240), 1,
      anon_sym_then,
    ACTIONS(178), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [4052] = 3,
    ACTIONS(176), 1,
      aux_sym_number_token1,
    ACTIONS(242), 1,
      anon_sym_then,
    ACTIONS(178), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [4064] = 2,
    ACTIONS(136), 2,
      anon_sym_RPAREN,
      aux_sym_number_token1,
    ACTIONS(138), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [4074] = 2,
    ACTIONS(180), 1,
      aux_sym_number_token1,
    ACTIONS(182), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_then,
      sym_identifier,
  [4084] = 2,
    ACTIONS(172), 2,
      anon_sym_RPAREN,
      aux_sym_number_token1,
    ACTIONS(174), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [4094] = 3,
    ACTIONS(176), 1,
      aux_sym_number_token1,
    ACTIONS(244), 1,
      anon_sym_then,
    ACTIONS(178), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [4106] = 2,
    ACTIONS(168), 2,
      anon_sym_RPAREN,
      aux_sym_number_token1,
    ACTIONS(170), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [4116] = 2,
    ACTIONS(140), 1,
      aux_sym_number_token1,
    ACTIONS(142), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_then,
      sym_identifier,
  [4126] = 2,
    ACTIONS(168), 1,
      aux_sym_number_token1,
    ACTIONS(170), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_else,
      sym_identifier,
  [4136] = 2,
    ACTIONS(172), 1,
      aux_sym_number_token1,
    ACTIONS(174), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_else,
      sym_identifier,
  [4146] = 5,
    ACTIONS(154), 1,
      anon_sym_else,
    ACTIONS(246), 1,
      sym_identifier,
    ACTIONS(248), 1,
      aux_sym_number_token1,
    STATE(134), 1,
      aux_sym_calc_repeat1,
    STATE(167), 1,
      sym_number,
  [4162] = 2,
    ACTIONS(136), 1,
      aux_sym_number_token1,
    ACTIONS(138), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_else,
      sym_identifier,
  [4172] = 5,
    ACTIONS(128), 1,
      anon_sym_else,
    ACTIONS(250), 1,
      sym_identifier,
    ACTIONS(253), 1,
      aux_sym_number_token1,
    STATE(134), 1,
      aux_sym_calc_repeat1,
    STATE(167), 1,
      sym_number,
  [4188] = 2,
    ACTIONS(176), 1,
      aux_sym_number_token1,
    ACTIONS(178), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_else,
      sym_identifier,
  [4198] = 2,
    ACTIONS(180), 2,
      anon_sym_RPAREN,
      aux_sym_number_token1,
    ACTIONS(182), 3,
      anon_sym_true,
      anon_sym_false,
      sym_identifier,
  [4208] = 2,
    ACTIONS(68), 1,
      aux_sym_number_token1,
    ACTIONS(70), 4,
      anon_sym_true,
      anon_sym_false,
      anon_sym_else,
      sym_identifier,
  [4218] = 2,
    ACTIONS(236), 1,
      aux_sym_number_token1,
    ACTIONS(238), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [4227] = 4,
    ACTIONS(158), 1,
      aux_sym_number_token1,
    ACTIONS(256), 1,
      sym_identifier,
    STATE(73), 1,
      aux_sym_calc_repeat1,
    STATE(120), 1,
      sym_number,
  [4240] = 2,
    ACTIONS(232), 1,
      aux_sym_number_token1,
    ACTIONS(234), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [4249] = 3,
    ACTIONS(260), 1,
      anon_sym_and,
    STATE(149), 1,
      aux_sym_let_expr_repeat1,
    ACTIONS(258), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [4260] = 1,
    ACTIONS(262), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [4267] = 3,
    ACTIONS(264), 1,
      ts_builtin_sym_end,
    ACTIONS(266), 1,
      anon_sym_let,
    STATE(143), 2,
      sym_let_expr,
      aux_sym_source_file_repeat1,
  [4278] = 2,
    ACTIONS(180), 1,
      aux_sym_number_token1,
    ACTIONS(182), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [4287] = 4,
    ACTIONS(248), 1,
      aux_sym_number_token1,
    ACTIONS(269), 1,
      sym_identifier,
    STATE(132), 1,
      aux_sym_calc_repeat1,
    STATE(167), 1,
      sym_number,
  [4300] = 3,
    ACTIONS(260), 1,
      anon_sym_and,
    STATE(141), 1,
      aux_sym_let_expr_repeat1,
    ACTIONS(271), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [4311] = 1,
    ACTIONS(273), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [4318] = 4,
    ACTIONS(222), 1,
      sym_identifier,
    ACTIONS(224), 1,
      aux_sym_number_token1,
    STATE(108), 1,
      aux_sym_calc_repeat1,
    STATE(164), 1,
      sym_number,
  [4331] = 3,
    ACTIONS(275), 1,
      anon_sym_and,
    STATE(149), 1,
      aux_sym_let_expr_repeat1,
    ACTIONS(262), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [4342] = 3,
    ACTIONS(5), 1,
      anon_sym_let,
    ACTIONS(278), 1,
      ts_builtin_sym_end,
    STATE(143), 2,
      sym_let_expr,
      aux_sym_source_file_repeat1,
  [4353] = 4,
    ACTIONS(212), 1,
      aux_sym_number_token1,
    ACTIONS(280), 1,
      sym_identifier,
    STATE(99), 1,
      aux_sym_calc_repeat1,
    STATE(138), 1,
      sym_number,
  [4366] = 3,
    ACTIONS(282), 1,
      anon_sym_and,
    ACTIONS(284), 1,
      anon_sym_in,
    STATE(166), 1,
      aux_sym_let_expr_repeat1,
  [4376] = 2,
    ACTIONS(180), 1,
      aux_sym_number_token1,
    ACTIONS(182), 2,
      anon_sym_else,
      sym_identifier,
  [4384] = 3,
    ACTIONS(282), 1,
      anon_sym_and,
    ACTIONS(286), 1,
      anon_sym_in,
    STATE(156), 1,
      aux_sym_let_expr_repeat1,
  [4394] = 3,
    ACTIONS(288), 1,
      sym_arrow,
    ACTIONS(290), 1,
      sym_identifier,
    STATE(159), 1,
      aux_sym_lambda_repeat1,
  [4404] = 3,
    ACTIONS(282), 1,
      anon_sym_and,
    ACTIONS(292), 1,
      anon_sym_in,
    STATE(160), 1,
      aux_sym_let_expr_repeat1,
  [4414] = 3,
    ACTIONS(290), 1,
      sym_identifier,
    ACTIONS(294), 1,
      sym_arrow,
    STATE(159), 1,
      aux_sym_lambda_repeat1,
  [4424] = 3,
    ACTIONS(282), 1,
      anon_sym_and,
    ACTIONS(296), 1,
      anon_sym_in,
    STATE(160), 1,
      aux_sym_let_expr_repeat1,
  [4434] = 3,
    ACTIONS(298), 1,
      sym_arrow,
    ACTIONS(300), 1,
      sym_identifier,
    STATE(159), 1,
      aux_sym_lambda_repeat1,
  [4444] = 3,
    ACTIONS(262), 1,
      anon_sym_in,
    ACTIONS(303), 1,
      anon_sym_and,
    STATE(160), 1,
      aux_sym_let_expr_repeat1,
  [4454] = 1,
    ACTIONS(232), 3,
      anon_sym_RPAREN,
      sym_identifier,
      aux_sym_number_token1,
  [4460] = 3,
    ACTIONS(282), 1,
      anon_sym_and,
    ACTIONS(306), 1,
      anon_sym_in,
    STATE(158), 1,
      aux_sym_let_expr_repeat1,
  [4470] = 2,
    ACTIONS(232), 1,
      aux_sym_number_token1,
    ACTIONS(234), 2,
      anon_sym_else,
      sym_identifier,
  [4478] = 1,
    ACTIONS(236), 3,
      anon_sym_RPAREN,
      sym_identifier,
      aux_sym_number_token1,
  [4484] = 3,
    ACTIONS(290), 1,
      sym_identifier,
    ACTIONS(308), 1,
      sym_arrow,
    STATE(159), 1,
      aux_sym_lambda_repeat1,
  [4494] = 3,
    ACTIONS(282), 1,
      anon_sym_and,
    ACTIONS(310), 1,
      anon_sym_in,
    STATE(160), 1,
      aux_sym_let_expr_repeat1,
  [4504] = 2,
    ACTIONS(236), 1,
      aux_sym_number_token1,
    ACTIONS(238), 2,
      anon_sym_else,
      sym_identifier,
  [4512] = 1,
    ACTIONS(180), 3,
      anon_sym_RPAREN,
      sym_identifier,
      aux_sym_number_token1,
  [4518] = 3,
    ACTIONS(282), 1,
      anon_sym_and,
    ACTIONS(312), 1,
      anon_sym_in,
    STATE(160), 1,
      aux_sym_let_expr_repeat1,
  [4528] = 3,
    ACTIONS(290), 1,
      sym_identifier,
    ACTIONS(314), 1,
      sym_arrow,
    STATE(159), 1,
      aux_sym_lambda_repeat1,
  [4538] = 3,
    ACTIONS(282), 1,
      anon_sym_and,
    ACTIONS(316), 1,
      anon_sym_in,
    STATE(169), 1,
      aux_sym_let_expr_repeat1,
  [4548] = 2,
    ACTIONS(318), 1,
      sym_identifier,
    STATE(146), 1,
      sym_def,
  [4555] = 2,
    ACTIONS(318), 1,
      sym_identifier,
    STATE(142), 1,
      sym_def,
  [4562] = 1,
    ACTIONS(320), 2,
      sym_identifier,
      aux_sym_number_token1,
  [4567] = 2,
    ACTIONS(290), 1,
      sym_identifier,
    STATE(170), 1,
      aux_sym_lambda_repeat1,
  [4574] = 2,
    ACTIONS(322), 1,
      sym_identifier,
    STATE(171), 1,
      sym_def,
  [4581] = 2,
    ACTIONS(322), 1,
      sym_identifier,
    STATE(162), 1,
      sym_def,
  [4588] = 2,
    ACTIONS(290), 1,
      sym_identifier,
    STATE(157), 1,
      aux_sym_lambda_repeat1,
  [4595] = 2,
    ACTIONS(290), 1,
      sym_identifier,
    STATE(165), 1,
      aux_sym_lambda_repeat1,
  [4602] = 2,
    ACTIONS(322), 1,
      sym_identifier,
    STATE(142), 1,
      sym_def,
  [4609] = 2,
    ACTIONS(322), 1,
      sym_identifier,
    STATE(154), 1,
      sym_def,
  [4616] = 2,
    ACTIONS(290), 1,
      sym_identifier,
    STATE(155), 1,
      aux_sym_lambda_repeat1,
  [4623] = 1,
    ACTIONS(324), 2,
      sym_arrow,
      sym_identifier,
  [4628] = 2,
    ACTIONS(322), 1,
      sym_identifier,
    STATE(152), 1,
      sym_def,
  [4635] = 1,
    ACTIONS(326), 2,
      sym_identifier,
      aux_sym_number_token1,
  [4640] = 1,
    ACTIONS(328), 1,
      anon_sym_else,
  [4644] = 1,
    ACTIONS(330), 1,
      anon_sym_then,
  [4648] = 1,
    ACTIONS(332), 1,
      anon_sym_else,
  [4652] = 1,
    ACTIONS(334), 1,
      anon_sym_else,
  [4656] = 1,
    ACTIONS(336), 1,
      anon_sym_then,
  [4660] = 1,
    ACTIONS(338), 1,
      anon_sym_RPAREN,
  [4664] = 1,
    ACTIONS(340), 1,
      anon_sym_EQ,
  [4668] = 1,
    ACTIONS(342), 1,
      anon_sym_else,
  [4672] = 1,
    ACTIONS(344), 1,
      anon_sym_else,
  [4676] = 1,
    ACTIONS(346), 1,
      anon_sym_else,
  [4680] = 1,
    ACTIONS(348), 1,
      anon_sym_then,
  [4684] = 1,
    ACTIONS(350), 1,
      anon_sym_else,
  [4688] = 1,
    ACTIONS(352), 1,
      anon_sym_else,
  [4692] = 1,
    ACTIONS(354), 1,
      anon_sym_else,
  [4696] = 1,
    ACTIONS(356), 1,
      anon_sym_else,
  [4700] = 1,
    ACTIONS(358), 1,
      anon_sym_then,
  [4704] = 1,
    ACTIONS(360), 1,
      anon_sym_then,
  [4708] = 1,
    ACTIONS(362), 1,
      anon_sym_else,
  [4712] = 1,
    ACTIONS(364), 1,
      anon_sym_else,
  [4716] = 1,
    ACTIONS(366), 1,
      anon_sym_then,
  [4720] = 1,
    ACTIONS(368), 1,
      anon_sym_then,
  [4724] = 1,
    ACTIONS(370), 1,
      anon_sym_then,
  [4728] = 1,
    ACTIONS(372), 1,
      anon_sym_else,
  [4732] = 1,
    ACTIONS(374), 1,
      anon_sym_then,
  [4736] = 1,
    ACTIONS(376), 1,
      anon_sym_then,
  [4740] = 1,
    ACTIONS(378), 1,
      anon_sym_then,
  [4744] = 1,
    ACTIONS(380), 1,
      anon_sym_else,
  [4748] = 1,
    ACTIONS(382), 1,
      anon_sym_RPAREN,
  [4752] = 1,
    ACTIONS(384), 1,
      anon_sym_else,
  [4756] = 1,
    ACTIONS(386), 1,
      anon_sym_RPAREN,
  [4760] = 1,
    ACTIONS(388), 1,
      anon_sym_else,
  [4764] = 1,
    ACTIONS(390), 1,
      anon_sym_RPAREN,
  [4768] = 1,
    ACTIONS(392), 1,
      anon_sym_EQ,
  [4772] = 1,
    ACTIONS(394), 1,
      anon_sym_then,
  [4776] = 1,
    ACTIONS(396), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 59,
  [SMALL_STATE(4)] = 118,
  [SMALL_STATE(5)] = 177,
  [SMALL_STATE(6)] = 236,
  [SMALL_STATE(7)] = 295,
  [SMALL_STATE(8)] = 354,
  [SMALL_STATE(9)] = 413,
  [SMALL_STATE(10)] = 472,
  [SMALL_STATE(11)] = 531,
  [SMALL_STATE(12)] = 590,
  [SMALL_STATE(13)] = 649,
  [SMALL_STATE(14)] = 708,
  [SMALL_STATE(15)] = 767,
  [SMALL_STATE(16)] = 826,
  [SMALL_STATE(17)] = 885,
  [SMALL_STATE(18)] = 944,
  [SMALL_STATE(19)] = 1003,
  [SMALL_STATE(20)] = 1062,
  [SMALL_STATE(21)] = 1121,
  [SMALL_STATE(22)] = 1180,
  [SMALL_STATE(23)] = 1239,
  [SMALL_STATE(24)] = 1298,
  [SMALL_STATE(25)] = 1357,
  [SMALL_STATE(26)] = 1416,
  [SMALL_STATE(27)] = 1475,
  [SMALL_STATE(28)] = 1534,
  [SMALL_STATE(29)] = 1593,
  [SMALL_STATE(30)] = 1652,
  [SMALL_STATE(31)] = 1711,
  [SMALL_STATE(32)] = 1770,
  [SMALL_STATE(33)] = 1829,
  [SMALL_STATE(34)] = 1888,
  [SMALL_STATE(35)] = 1947,
  [SMALL_STATE(36)] = 2006,
  [SMALL_STATE(37)] = 2065,
  [SMALL_STATE(38)] = 2124,
  [SMALL_STATE(39)] = 2183,
  [SMALL_STATE(40)] = 2242,
  [SMALL_STATE(41)] = 2301,
  [SMALL_STATE(42)] = 2360,
  [SMALL_STATE(43)] = 2419,
  [SMALL_STATE(44)] = 2478,
  [SMALL_STATE(45)] = 2537,
  [SMALL_STATE(46)] = 2596,
  [SMALL_STATE(47)] = 2655,
  [SMALL_STATE(48)] = 2714,
  [SMALL_STATE(49)] = 2773,
  [SMALL_STATE(50)] = 2832,
  [SMALL_STATE(51)] = 2891,
  [SMALL_STATE(52)] = 2950,
  [SMALL_STATE(53)] = 2983,
  [SMALL_STATE(54)] = 3016,
  [SMALL_STATE(55)] = 3049,
  [SMALL_STATE(56)] = 3079,
  [SMALL_STATE(57)] = 3109,
  [SMALL_STATE(58)] = 3139,
  [SMALL_STATE(59)] = 3168,
  [SMALL_STATE(60)] = 3197,
  [SMALL_STATE(61)] = 3226,
  [SMALL_STATE(62)] = 3255,
  [SMALL_STATE(63)] = 3284,
  [SMALL_STATE(64)] = 3313,
  [SMALL_STATE(65)] = 3342,
  [SMALL_STATE(66)] = 3371,
  [SMALL_STATE(67)] = 3397,
  [SMALL_STATE(68)] = 3417,
  [SMALL_STATE(69)] = 3429,
  [SMALL_STATE(70)] = 3441,
  [SMALL_STATE(71)] = 3453,
  [SMALL_STATE(72)] = 3473,
  [SMALL_STATE(73)] = 3493,
  [SMALL_STATE(74)] = 3513,
  [SMALL_STATE(75)] = 3533,
  [SMALL_STATE(76)] = 3543,
  [SMALL_STATE(77)] = 3563,
  [SMALL_STATE(78)] = 3575,
  [SMALL_STATE(79)] = 3587,
  [SMALL_STATE(80)] = 3599,
  [SMALL_STATE(81)] = 3611,
  [SMALL_STATE(82)] = 3620,
  [SMALL_STATE(83)] = 3629,
  [SMALL_STATE(84)] = 3638,
  [SMALL_STATE(85)] = 3647,
  [SMALL_STATE(86)] = 3656,
  [SMALL_STATE(87)] = 3667,
  [SMALL_STATE(88)] = 3676,
  [SMALL_STATE(89)] = 3685,
  [SMALL_STATE(90)] = 3694,
  [SMALL_STATE(91)] = 3703,
  [SMALL_STATE(92)] = 3712,
  [SMALL_STATE(93)] = 3721,
  [SMALL_STATE(94)] = 3730,
  [SMALL_STATE(95)] = 3739,
  [SMALL_STATE(96)] = 3748,
  [SMALL_STATE(97)] = 3757,
  [SMALL_STATE(98)] = 3768,
  [SMALL_STATE(99)] = 3779,
  [SMALL_STATE(100)] = 3796,
  [SMALL_STATE(101)] = 3813,
  [SMALL_STATE(102)] = 3822,
  [SMALL_STATE(103)] = 3833,
  [SMALL_STATE(104)] = 3844,
  [SMALL_STATE(105)] = 3855,
  [SMALL_STATE(106)] = 3866,
  [SMALL_STATE(107)] = 3876,
  [SMALL_STATE(108)] = 3888,
  [SMALL_STATE(109)] = 3904,
  [SMALL_STATE(110)] = 3920,
  [SMALL_STATE(111)] = 3930,
  [SMALL_STATE(112)] = 3940,
  [SMALL_STATE(113)] = 3950,
  [SMALL_STATE(114)] = 3960,
  [SMALL_STATE(115)] = 3970,
  [SMALL_STATE(116)] = 3980,
  [SMALL_STATE(117)] = 3990,
  [SMALL_STATE(118)] = 4000,
  [SMALL_STATE(119)] = 4010,
  [SMALL_STATE(120)] = 4020,
  [SMALL_STATE(121)] = 4030,
  [SMALL_STATE(122)] = 4040,
  [SMALL_STATE(123)] = 4052,
  [SMALL_STATE(124)] = 4064,
  [SMALL_STATE(125)] = 4074,
  [SMALL_STATE(126)] = 4084,
  [SMALL_STATE(127)] = 4094,
  [SMALL_STATE(128)] = 4106,
  [SMALL_STATE(129)] = 4116,
  [SMALL_STATE(130)] = 4126,
  [SMALL_STATE(131)] = 4136,
  [SMALL_STATE(132)] = 4146,
  [SMALL_STATE(133)] = 4162,
  [SMALL_STATE(134)] = 4172,
  [SMALL_STATE(135)] = 4188,
  [SMALL_STATE(136)] = 4198,
  [SMALL_STATE(137)] = 4208,
  [SMALL_STATE(138)] = 4218,
  [SMALL_STATE(139)] = 4227,
  [SMALL_STATE(140)] = 4240,
  [SMALL_STATE(141)] = 4249,
  [SMALL_STATE(142)] = 4260,
  [SMALL_STATE(143)] = 4267,
  [SMALL_STATE(144)] = 4278,
  [SMALL_STATE(145)] = 4287,
  [SMALL_STATE(146)] = 4300,
  [SMALL_STATE(147)] = 4311,
  [SMALL_STATE(148)] = 4318,
  [SMALL_STATE(149)] = 4331,
  [SMALL_STATE(150)] = 4342,
  [SMALL_STATE(151)] = 4353,
  [SMALL_STATE(152)] = 4366,
  [SMALL_STATE(153)] = 4376,
  [SMALL_STATE(154)] = 4384,
  [SMALL_STATE(155)] = 4394,
  [SMALL_STATE(156)] = 4404,
  [SMALL_STATE(157)] = 4414,
  [SMALL_STATE(158)] = 4424,
  [SMALL_STATE(159)] = 4434,
  [SMALL_STATE(160)] = 4444,
  [SMALL_STATE(161)] = 4454,
  [SMALL_STATE(162)] = 4460,
  [SMALL_STATE(163)] = 4470,
  [SMALL_STATE(164)] = 4478,
  [SMALL_STATE(165)] = 4484,
  [SMALL_STATE(166)] = 4494,
  [SMALL_STATE(167)] = 4504,
  [SMALL_STATE(168)] = 4512,
  [SMALL_STATE(169)] = 4518,
  [SMALL_STATE(170)] = 4528,
  [SMALL_STATE(171)] = 4538,
  [SMALL_STATE(172)] = 4548,
  [SMALL_STATE(173)] = 4555,
  [SMALL_STATE(174)] = 4562,
  [SMALL_STATE(175)] = 4567,
  [SMALL_STATE(176)] = 4574,
  [SMALL_STATE(177)] = 4581,
  [SMALL_STATE(178)] = 4588,
  [SMALL_STATE(179)] = 4595,
  [SMALL_STATE(180)] = 4602,
  [SMALL_STATE(181)] = 4609,
  [SMALL_STATE(182)] = 4616,
  [SMALL_STATE(183)] = 4623,
  [SMALL_STATE(184)] = 4628,
  [SMALL_STATE(185)] = 4635,
  [SMALL_STATE(186)] = 4640,
  [SMALL_STATE(187)] = 4644,
  [SMALL_STATE(188)] = 4648,
  [SMALL_STATE(189)] = 4652,
  [SMALL_STATE(190)] = 4656,
  [SMALL_STATE(191)] = 4660,
  [SMALL_STATE(192)] = 4664,
  [SMALL_STATE(193)] = 4668,
  [SMALL_STATE(194)] = 4672,
  [SMALL_STATE(195)] = 4676,
  [SMALL_STATE(196)] = 4680,
  [SMALL_STATE(197)] = 4684,
  [SMALL_STATE(198)] = 4688,
  [SMALL_STATE(199)] = 4692,
  [SMALL_STATE(200)] = 4696,
  [SMALL_STATE(201)] = 4700,
  [SMALL_STATE(202)] = 4704,
  [SMALL_STATE(203)] = 4708,
  [SMALL_STATE(204)] = 4712,
  [SMALL_STATE(205)] = 4716,
  [SMALL_STATE(206)] = 4720,
  [SMALL_STATE(207)] = 4724,
  [SMALL_STATE(208)] = 4728,
  [SMALL_STATE(209)] = 4732,
  [SMALL_STATE(210)] = 4736,
  [SMALL_STATE(211)] = 4740,
  [SMALL_STATE(212)] = 4744,
  [SMALL_STATE(213)] = 4748,
  [SMALL_STATE(214)] = 4752,
  [SMALL_STATE(215)] = 4756,
  [SMALL_STATE(216)] = 4760,
  [SMALL_STATE(217)] = 4764,
  [SMALL_STATE(218)] = 4768,
  [SMALL_STATE(219)] = 4772,
  [SMALL_STATE(220)] = 4776,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(184),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(179),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(176),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(175),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(181),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(177),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(178),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(68),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(79),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(80),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_call, 2, .production_id = 16),
  [62] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fn_call, 2, .production_id = 16),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1, .production_id = 12),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1, .production_id = 12),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(98),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(97),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(102),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(110),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(111),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(125),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [98] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(124),
  [101] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(118),
  [104] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(136),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [117] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(133),
  [120] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(135),
  [123] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 19), SHIFT_REPEAT(106),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20),
  [130] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20), SHIFT_REPEAT(117),
  [133] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20), SHIFT_REPEAT(112),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean, 1),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 1, .production_id = 13),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 1, .production_id = 13),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_calc, 2, .production_id = 17),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_calc, 2, .production_id = 17),
  [156] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1, .production_id = 15),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1, .production_id = 15),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1, .production_id = 10),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1, .production_id = 10),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__callable, 1, .production_id = 5),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__callable, 1, .production_id = 5),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 1),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_expr, 6, .production_id = 25),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_in_expr, 5, .production_id = 23),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 8),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_expr, 6, .production_id = 24),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_expr, 6, .production_id = 26),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_expr, 8, .production_id = 27),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_in_expr, 4, .production_id = 21),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 9),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 6),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lambda, 4, .production_id = 22),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 7),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 11),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 13),
  [210] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [214] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20), SHIFT_REPEAT(140),
  [217] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20), SHIFT_REPEAT(144),
  [220] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [226] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20), SHIFT_REPEAT(161),
  [229] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20), SHIFT_REPEAT(168),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 5),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 5),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 15),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 15),
  [240] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [244] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [250] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20), SHIFT_REPEAT(163),
  [253] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 20), SHIFT_REPEAT(153),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expr, 3, .production_id = 2),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [266] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(172),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expr, 2, .production_id = 1),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_def, 3, .production_id = 14),
  [275] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2), SHIFT_REPEAT(173),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lambda_repeat1, 2, .production_id = 18),
  [300] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_lambda_repeat1, 2, .production_id = 18), SHIFT_REPEAT(183),
  [303] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2), SHIFT_REPEAT(180),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__calc, 1, .production_id = 4),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lambda_repeat1, 1, .production_id = 5),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__calc, 1, .production_id = 3),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [396] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_necha(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
