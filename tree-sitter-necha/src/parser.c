#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 76
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 65
#define ALIAS_COUNT 0
#define TOKEN_COUNT 47
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 12
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 22

enum {
  anon_sym_true = 1,
  anon_sym_false = 2,
  anon_sym_let = 3,
  anon_sym_and = 4,
  anon_sym_EQ = 5,
  anon_sym_in = 6,
  sym_arrow = 7,
  anon_sym_fn = 8,
  anon_sym_import = 9,
  anon_sym_BSLASH = 10,
  anon_sym_DOT = 11,
  anon_sym_LBRACK = 12,
  anon_sym_RBRACK = 13,
  anon_sym_LBRACE = 14,
  anon_sym_RBRACE = 15,
  anon_sym_if = 16,
  anon_sym_else = 17,
  anon_sym_COLON = 18,
  anon_sym_COMMA = 19,
  anon_sym_for = 20,
  anon_sym_while = 21,
  anon_sym_LPAREN = 22,
  anon_sym_RPAREN = 23,
  sym_pub = 24,
  sym_var = 25,
  sym_const = 26,
  anon_sym_DQUOTE = 27,
  anon_sym_SQUOTE = 28,
  sym_eq = 29,
  sym_neq = 30,
  sym_geq = 31,
  sym_leq = 32,
  sym_greater = 33,
  sym_less = 34,
  anon_sym_AMP_AMP = 35,
  anon_sym_PIPE_PIPE = 36,
  anon_sym_or = 37,
  sym_bang = 38,
  sym_exp = 39,
  sym_minus = 40,
  sym_plus = 41,
  sym_mul = 42,
  sym_div = 43,
  sym_mod = 44,
  sym_identifier = 45,
  aux_sym_number_token1 = 46,
  sym_source_file = 47,
  sym_boolean = 48,
  sym_let_expr = 49,
  sym_def = 50,
  sym__callable = 51,
  sym__args = 52,
  sym__exprz = 53,
  sym_fn_call = 54,
  sym__calc = 55,
  sym_calc = 56,
  sym_let_in_expr = 57,
  sym_lambda = 58,
  sym_number = 59,
  aux_sym_source_file_repeat1 = 60,
  aux_sym_let_expr_repeat1 = 61,
  aux_sym_fn_call_repeat1 = 62,
  aux_sym_calc_repeat1 = 63,
  aux_sym_lambda_repeat1 = 64,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_let] = "let",
  [anon_sym_and] = "and",
  [anon_sym_EQ] = "=",
  [anon_sym_in] = "in",
  [sym_arrow] = "arrow",
  [anon_sym_fn] = "fn",
  [anon_sym_import] = "import",
  [anon_sym_BSLASH] = "\\",
  [anon_sym_DOT] = ".",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_COLON] = ":",
  [anon_sym_COMMA] = ",",
  [anon_sym_for] = "for",
  [anon_sym_while] = "while",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
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
  [sym_boolean] = "boolean",
  [sym_let_expr] = "let_expr",
  [sym_def] = "def",
  [sym__callable] = "_callable",
  [sym__args] = "_args",
  [sym__exprz] = "_exprz",
  [sym_fn_call] = "fn_call",
  [sym__calc] = "_calc",
  [sym_calc] = "calc",
  [sym_let_in_expr] = "let_in_expr",
  [sym_lambda] = "lambda",
  [sym_number] = "number",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_let_expr_repeat1] = "let_expr_repeat1",
  [aux_sym_fn_call_repeat1] = "fn_call_repeat1",
  [aux_sym_calc_repeat1] = "calc_repeat1",
  [aux_sym_lambda_repeat1] = "lambda_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_in] = anon_sym_in,
  [sym_arrow] = sym_arrow,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
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
  [sym_boolean] = sym_boolean,
  [sym_let_expr] = sym_let_expr,
  [sym_def] = sym_def,
  [sym__callable] = sym__callable,
  [sym__args] = sym__args,
  [sym__exprz] = sym__exprz,
  [sym_fn_call] = sym_fn_call,
  [sym__calc] = sym__calc,
  [sym_calc] = sym_calc,
  [sym_let_in_expr] = sym_let_in_expr,
  [sym_lambda] = sym_lambda,
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
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
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
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
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
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
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
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_let_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_def] = {
    .visible = true,
    .named = true,
  },
  [sym__callable] = {
    .visible = false,
    .named = true,
  },
  [sym__args] = {
    .visible = false,
    .named = true,
  },
  [sym__exprz] = {
    .visible = false,
    .named = true,
  },
  [sym_fn_call] = {
    .visible = true,
    .named = true,
  },
  [sym__calc] = {
    .visible = false,
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
  field_fn_call = 7,
  field_ident = 8,
  field_lambda = 9,
  field_let_in = 10,
  field_mul = 11,
  field_number = 12,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_add] = "add",
  [field_arrow] = "arrow",
  [field_boolean] = "boolean",
  [field_calc] = "calc",
  [field_def] = "def",
  [field_expr] = "expr",
  [field_fn_call] = "fn_call",
  [field_ident] = "ident",
  [field_lambda] = "lambda",
  [field_let_in] = "let_in",
  [field_mul] = "mul",
  [field_number] = "number",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 1},
  [5] = {.index = 5, .length = 1},
  [6] = {.index = 6, .length = 1},
  [7] = {.index = 7, .length = 1},
  [8] = {.index = 8, .length = 2},
  [9] = {.index = 10, .length = 9},
  [10] = {.index = 19, .length = 1},
  [11] = {.index = 20, .length = 1},
  [12] = {.index = 21, .length = 1},
  [13] = {.index = 22, .length = 1},
  [14] = {.index = 23, .length = 1},
  [15] = {.index = 24, .length = 3},
  [16] = {.index = 27, .length = 4},
  [17] = {.index = 31, .length = 2},
  [18] = {.index = 33, .length = 4},
  [19] = {.index = 37, .length = 9},
  [20] = {.index = 46, .length = 9},
  [21] = {.index = 55, .length = 10},
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
    {field_boolean, 0},
  [7] =
    {field_ident, 0, .inherited = true},
  [8] =
    {field_ident, 0, .inherited = true},
    {field_number, 0, .inherited = true},
  [10] =
    {field_boolean, 2, .inherited = true},
    {field_calc, 2, .inherited = true},
    {field_expr, 2},
    {field_fn_call, 2, .inherited = true},
    {field_ident, 0},
    {field_ident, 2, .inherited = true},
    {field_lambda, 2, .inherited = true},
    {field_let_in, 2, .inherited = true},
    {field_number, 2, .inherited = true},
  [19] =
    {field_fn_call, 0},
  [20] =
    {field_calc, 0},
  [21] =
    {field_let_in, 0},
  [22] =
    {field_lambda, 0},
  [23] =
    {field_number, 0},
  [24] =
    {field_ident, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_number, 1, .inherited = true},
  [27] =
    {field_add, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_mul, 0, .inherited = true},
    {field_number, 1, .inherited = true},
  [31] =
    {field_ident, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
  [33] =
    {field_ident, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_number, 0, .inherited = true},
    {field_number, 1, .inherited = true},
  [37] =
    {field_boolean, 3, .inherited = true},
    {field_calc, 3, .inherited = true},
    {field_def, 1},
    {field_expr, 3},
    {field_fn_call, 3, .inherited = true},
    {field_ident, 3, .inherited = true},
    {field_lambda, 3, .inherited = true},
    {field_let_in, 3, .inherited = true},
    {field_number, 3, .inherited = true},
  [46] =
    {field_arrow, 2},
    {field_boolean, 3, .inherited = true},
    {field_calc, 3, .inherited = true},
    {field_fn_call, 3, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_ident, 3, .inherited = true},
    {field_lambda, 3, .inherited = true},
    {field_let_in, 3, .inherited = true},
    {field_number, 3, .inherited = true},
  [55] =
    {field_boolean, 4, .inherited = true},
    {field_calc, 4, .inherited = true},
    {field_def, 1},
    {field_def, 2},
    {field_expr, 4},
    {field_fn_call, 4, .inherited = true},
    {field_ident, 4, .inherited = true},
    {field_lambda, 4, .inherited = true},
    {field_let_in, 4, .inherited = true},
    {field_number, 4, .inherited = true},
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
  [4] = 2,
  [5] = 5,
  [6] = 6,
  [7] = 3,
  [8] = 5,
  [9] = 6,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 12,
  [14] = 11,
  [15] = 10,
  [16] = 16,
  [17] = 17,
  [18] = 17,
  [19] = 16,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 23,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 23,
  [33] = 21,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 31,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 21,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 20,
  [50] = 22,
  [51] = 26,
  [52] = 52,
  [53] = 25,
  [54] = 24,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 56,
  [60] = 58,
  [61] = 55,
  [62] = 30,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 66,
  [71] = 65,
  [72] = 64,
  [73] = 73,
  [74] = 74,
  [75] = 73,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(59);
      if (lookahead == '!') ADVANCE(104);
      if (lookahead == '"') ADVANCE(93);
      if (lookahead == '%') ADVANCE(110);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '\'') ADVANCE(94);
      if (lookahead == '(') ADVANCE(88);
      if (lookahead == ')') ADVANCE(89);
      if (lookahead == '*') ADVANCE(108);
      if (lookahead == '+') ADVANCE(107);
      if (lookahead == ',') ADVANCE(85);
      if (lookahead == '-') ADVANCE(106);
      if (lookahead == '.') ADVANCE(77);
      if (lookahead == '/') ADVANCE(109);
      if (lookahead == ':') ADVANCE(84);
      if (lookahead == '<') ADVANCE(100);
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '>') ADVANCE(99);
      if (lookahead == '[') ADVANCE(78);
      if (lookahead == '\\') ADVANCE(76);
      if (lookahead == ']') ADVANCE(79);
      if (lookahead == '^') ADVANCE(105);
      if (lookahead == '_') SKIP(54)
      if (lookahead == 'a') ADVANCE(24);
      if (lookahead == 'c') ADVANCE(26);
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'i') ADVANCE(18);
      if (lookahead == 'l') ADVANCE(13);
      if (lookahead == 'o') ADVANCE(29);
      if (lookahead == 'p') ADVANCE(40);
      if (lookahead == 't') ADVANCE(32);
      if (lookahead == 'v') ADVANCE(9);
      if (lookahead == 'w') ADVANCE(19);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '|') ADVANCE(42);
      if (lookahead == '}') ADVANCE(81);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(45)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(46)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(47)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      END_STATE();
    case 4:
      if (lookahead == '&') ADVANCE(101);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(108);
      if (lookahead == '+') ADVANCE(107);
      if (lookahead == '.') ADVANCE(50);
      if (lookahead == '0') ADVANCE(125);
      if (lookahead == '=') ADVANCE(68);
      if (lookahead == '_') SKIP(1)
      if (lookahead == 'f') ADVANCE(111);
      if (lookahead == 'l') ADVANCE(113);
      if (lookahead == 't') ADVANCE(119);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == '.') ADVANCE(50);
      if (lookahead == '0') ADVANCE(125);
      if (lookahead == '_') SKIP(3)
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(50);
      if (lookahead == '0') ADVANCE(125);
      if (lookahead == '_') SKIP(2)
      if (lookahead == 'a') ADVANCE(117);
      if (lookahead == 'i') ADVANCE(118);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 8:
      if (lookahead == '>') ADVANCE(72);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(31);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(23);
      if (lookahead == 'n') ADVANCE(73);
      if (lookahead == 'o') ADVANCE(30);
      END_STATE();
    case 11:
      if (lookahead == 'b') ADVANCE(90);
      END_STATE();
    case 12:
      if (lookahead == 'd') ADVANCE(66);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(37);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(83);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(60);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(87);
      END_STATE();
    case 18:
      if (lookahead == 'f') ADVANCE(82);
      if (lookahead == 'm') ADVANCE(28);
      if (lookahead == 'n') ADVANCE(70);
      END_STATE();
    case 19:
      if (lookahead == 'h') ADVANCE(20);
      END_STATE();
    case 20:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 21:
      if (lookahead == 'l') ADVANCE(34);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(17);
      END_STATE();
    case 23:
      if (lookahead == 'l') ADVANCE(36);
      END_STATE();
    case 24:
      if (lookahead == 'n') ADVANCE(12);
      END_STATE();
    case 25:
      if (lookahead == 'n') ADVANCE(35);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 27:
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 28:
      if (lookahead == 'p') ADVANCE(27);
      END_STATE();
    case 29:
      if (lookahead == 'r') ADVANCE(103);
      END_STATE();
    case 30:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(91);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(41);
      END_STATE();
    case 33:
      if (lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 34:
      if (lookahead == 's') ADVANCE(14);
      END_STATE();
    case 35:
      if (lookahead == 's') ADVANCE(38);
      END_STATE();
    case 36:
      if (lookahead == 's') ADVANCE(16);
      END_STATE();
    case 37:
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 38:
      if (lookahead == 't') ADVANCE(92);
      END_STATE();
    case 39:
      if (lookahead == 't') ADVANCE(75);
      END_STATE();
    case 40:
      if (lookahead == 'u') ADVANCE(11);
      END_STATE();
    case 41:
      if (lookahead == 'u') ADVANCE(15);
      END_STATE();
    case 42:
      if (lookahead == '|') ADVANCE(102);
      END_STATE();
    case 43:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 44:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(127);
      END_STATE();
    case 45:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(45)
      if (lookahead == '*') ADVANCE(108);
      if (lookahead == '+') ADVANCE(107);
      if (lookahead == '.') ADVANCE(50);
      if (lookahead == '0') ADVANCE(125);
      if (lookahead == '=') ADVANCE(68);
      if (lookahead == '_') SKIP(1)
      if (lookahead == 'f') ADVANCE(111);
      if (lookahead == 'l') ADVANCE(113);
      if (lookahead == 't') ADVANCE(119);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 46:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (lookahead == '.') ADVANCE(50);
      if (lookahead == '0') ADVANCE(125);
      if (lookahead == '_') SKIP(2)
      if (lookahead == 'a') ADVANCE(117);
      if (lookahead == 'i') ADVANCE(118);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 47:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(47)
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == '.') ADVANCE(50);
      if (lookahead == '0') ADVANCE(125);
      if (lookahead == '_') SKIP(3)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(128);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(126);
      END_STATE();
    case 50:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 51:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 52:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 53:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(129);
      END_STATE();
    case 54:
      if (eof) ADVANCE(59);
      if (lookahead == '\n') SKIP(57)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(54)
      END_STATE();
    case 55:
      if (eof) ADVANCE(59);
      if (lookahead == '\n') SKIP(58)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(55)
      END_STATE();
    case 56:
      if (eof) ADVANCE(59);
      if (lookahead == '.') ADVANCE(50);
      if (lookahead == '0') ADVANCE(125);
      if (lookahead == '_') SKIP(55)
      if (lookahead == 'a') ADVANCE(117);
      if (lookahead == 'l') ADVANCE(113);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(56)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 57:
      if (eof) ADVANCE(59);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(57)
      if (lookahead == '!') ADVANCE(104);
      if (lookahead == '"') ADVANCE(93);
      if (lookahead == '%') ADVANCE(110);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '\'') ADVANCE(94);
      if (lookahead == '(') ADVANCE(88);
      if (lookahead == ')') ADVANCE(89);
      if (lookahead == '*') ADVANCE(108);
      if (lookahead == '+') ADVANCE(107);
      if (lookahead == ',') ADVANCE(85);
      if (lookahead == '-') ADVANCE(106);
      if (lookahead == '.') ADVANCE(77);
      if (lookahead == '/') ADVANCE(109);
      if (lookahead == ':') ADVANCE(84);
      if (lookahead == '<') ADVANCE(100);
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '>') ADVANCE(99);
      if (lookahead == '[') ADVANCE(78);
      if (lookahead == '\\') ADVANCE(76);
      if (lookahead == ']') ADVANCE(79);
      if (lookahead == '^') ADVANCE(105);
      if (lookahead == '_') SKIP(54)
      if (lookahead == 'a') ADVANCE(24);
      if (lookahead == 'c') ADVANCE(26);
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'i') ADVANCE(18);
      if (lookahead == 'l') ADVANCE(13);
      if (lookahead == 'o') ADVANCE(29);
      if (lookahead == 'p') ADVANCE(40);
      if (lookahead == 't') ADVANCE(32);
      if (lookahead == 'v') ADVANCE(9);
      if (lookahead == 'w') ADVANCE(19);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '|') ADVANCE(42);
      if (lookahead == '}') ADVANCE(81);
      END_STATE();
    case 58:
      if (eof) ADVANCE(59);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(58)
      if (lookahead == '.') ADVANCE(50);
      if (lookahead == '0') ADVANCE(125);
      if (lookahead == '_') SKIP(55)
      if (lookahead == 'a') ADVANCE(117);
      if (lookahead == 'l') ADVANCE(113);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_and);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(95);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_in);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_arrow);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_fn);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_pub);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_var);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_const);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_eq);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_neq);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_geq);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_leq);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_greater);
      if (lookahead == '=') ADVANCE(97);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_less);
      if (lookahead == '=') ADVANCE(98);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_bang);
      if (lookahead == '=') ADVANCE(96);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_exp);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_minus);
      if (lookahead == '>') ADVANCE(72);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_plus);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_mul);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_div);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_mod);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(116);
      if (lookahead == 'n') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(123);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_number_token1);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(133);
      if (lookahead == '0') ADVANCE(130);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(44);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(43);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(48);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(53);
      if (lookahead == '_') ADVANCE(51);
      if (lookahead == 'n') ADVANCE(124);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(126);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(133);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(43);
      if (lookahead == '_') ADVANCE(49);
      if (lookahead == 'n') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(126);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(44);
      if (lookahead == 'n') ADVANCE(124);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(127);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(48);
      if (lookahead == 'n') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(128);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(53);
      if (lookahead == 'n') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(129);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(51);
      if (lookahead == 'n') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(43);
      if (lookahead == '_') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 5},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 56},
  [11] = {.lex_state = 56},
  [12] = {.lex_state = 56},
  [13] = {.lex_state = 7},
  [14] = {.lex_state = 7},
  [15] = {.lex_state = 7},
  [16] = {.lex_state = 56},
  [17] = {.lex_state = 56},
  [18] = {.lex_state = 7},
  [19] = {.lex_state = 7},
  [20] = {.lex_state = 56},
  [21] = {.lex_state = 56},
  [22] = {.lex_state = 56},
  [23] = {.lex_state = 56},
  [24] = {.lex_state = 56},
  [25] = {.lex_state = 56},
  [26] = {.lex_state = 56},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 6},
  [32] = {.lex_state = 7},
  [33] = {.lex_state = 7},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 6},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 7},
  [50] = {.lex_state = 7},
  [51] = {.lex_state = 7},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 7},
  [54] = {.lex_state = 7},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 6},
  [58] = {.lex_state = 6},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 6},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 6},
  [64] = {.lex_state = 6},
  [65] = {.lex_state = 6},
  [66] = {.lex_state = 6},
  [67] = {.lex_state = 6},
  [68] = {.lex_state = 6},
  [69] = {.lex_state = 6},
  [70] = {.lex_state = 6},
  [71] = {.lex_state = 6},
  [72] = {.lex_state = 6},
  [73] = {.lex_state = 5},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 5},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [sym_arrow] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
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
    [sym_source_file] = STATE(74),
    [sym_let_expr] = STATE(34),
    [aux_sym_source_file_repeat1] = STATE(34),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_let] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 17,
    ACTIONS(9), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      sym_plus,
    ACTIONS(15), 1,
      sym_mul,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 1,
      aux_sym_number_token1,
    STATE(14), 1,
      sym__callable,
    STATE(27), 1,
      sym_boolean,
    STATE(28), 1,
      sym_number,
    STATE(31), 1,
      sym__calc,
    STATE(35), 1,
      sym_lambda,
    STATE(36), 1,
      sym_let_in_expr,
    STATE(37), 1,
      sym_calc,
    STATE(39), 1,
      sym_fn_call,
    STATE(43), 1,
      sym__args,
    STATE(47), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [53] = 17,
    ACTIONS(13), 1,
      sym_plus,
    ACTIONS(15), 1,
      sym_mul,
    ACTIONS(19), 1,
      aux_sym_number_token1,
    ACTIONS(21), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_fn,
    ACTIONS(25), 1,
      sym_identifier,
    STATE(11), 1,
      sym__callable,
    STATE(27), 1,
      sym_boolean,
    STATE(28), 1,
      sym_number,
    STATE(35), 1,
      sym_lambda,
    STATE(36), 1,
      sym_let_in_expr,
    STATE(37), 1,
      sym_calc,
    STATE(38), 1,
      sym__calc,
    STATE(39), 1,
      sym_fn_call,
    STATE(43), 1,
      sym__args,
    STATE(45), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [106] = 17,
    ACTIONS(13), 1,
      sym_plus,
    ACTIONS(15), 1,
      sym_mul,
    ACTIONS(19), 1,
      aux_sym_number_token1,
    ACTIONS(21), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_fn,
    ACTIONS(25), 1,
      sym_identifier,
    STATE(11), 1,
      sym__callable,
    STATE(27), 1,
      sym_boolean,
    STATE(28), 1,
      sym_number,
    STATE(35), 1,
      sym_lambda,
    STATE(36), 1,
      sym_let_in_expr,
    STATE(37), 1,
      sym_calc,
    STATE(38), 1,
      sym__calc,
    STATE(39), 1,
      sym_fn_call,
    STATE(43), 1,
      sym__args,
    STATE(47), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [159] = 17,
    ACTIONS(9), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      sym_plus,
    ACTIONS(15), 1,
      sym_mul,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 1,
      aux_sym_number_token1,
    STATE(14), 1,
      sym__callable,
    STATE(27), 1,
      sym_boolean,
    STATE(28), 1,
      sym_number,
    STATE(31), 1,
      sym__calc,
    STATE(35), 1,
      sym_lambda,
    STATE(36), 1,
      sym_let_in_expr,
    STATE(37), 1,
      sym_calc,
    STATE(39), 1,
      sym_fn_call,
    STATE(41), 1,
      sym__exprz,
    STATE(43), 1,
      sym__args,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [212] = 17,
    ACTIONS(13), 1,
      sym_plus,
    ACTIONS(15), 1,
      sym_mul,
    ACTIONS(19), 1,
      aux_sym_number_token1,
    ACTIONS(21), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_fn,
    ACTIONS(25), 1,
      sym_identifier,
    STATE(11), 1,
      sym__callable,
    STATE(27), 1,
      sym_boolean,
    STATE(28), 1,
      sym_number,
    STATE(35), 1,
      sym_lambda,
    STATE(36), 1,
      sym_let_in_expr,
    STATE(37), 1,
      sym_calc,
    STATE(38), 1,
      sym__calc,
    STATE(39), 1,
      sym_fn_call,
    STATE(43), 1,
      sym__args,
    STATE(48), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [265] = 17,
    ACTIONS(9), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      sym_plus,
    ACTIONS(15), 1,
      sym_mul,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 1,
      aux_sym_number_token1,
    STATE(14), 1,
      sym__callable,
    STATE(27), 1,
      sym_boolean,
    STATE(28), 1,
      sym_number,
    STATE(31), 1,
      sym__calc,
    STATE(35), 1,
      sym_lambda,
    STATE(36), 1,
      sym_let_in_expr,
    STATE(37), 1,
      sym_calc,
    STATE(39), 1,
      sym_fn_call,
    STATE(43), 1,
      sym__args,
    STATE(45), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [318] = 17,
    ACTIONS(13), 1,
      sym_plus,
    ACTIONS(15), 1,
      sym_mul,
    ACTIONS(19), 1,
      aux_sym_number_token1,
    ACTIONS(21), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      anon_sym_fn,
    ACTIONS(25), 1,
      sym_identifier,
    STATE(11), 1,
      sym__callable,
    STATE(27), 1,
      sym_boolean,
    STATE(28), 1,
      sym_number,
    STATE(35), 1,
      sym_lambda,
    STATE(36), 1,
      sym_let_in_expr,
    STATE(37), 1,
      sym_calc,
    STATE(38), 1,
      sym__calc,
    STATE(39), 1,
      sym_fn_call,
    STATE(41), 1,
      sym__exprz,
    STATE(43), 1,
      sym__args,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [371] = 17,
    ACTIONS(9), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      anon_sym_fn,
    ACTIONS(13), 1,
      sym_plus,
    ACTIONS(15), 1,
      sym_mul,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 1,
      aux_sym_number_token1,
    STATE(14), 1,
      sym__callable,
    STATE(27), 1,
      sym_boolean,
    STATE(28), 1,
      sym_number,
    STATE(31), 1,
      sym__calc,
    STATE(35), 1,
      sym_lambda,
    STATE(36), 1,
      sym_let_in_expr,
    STATE(37), 1,
      sym_calc,
    STATE(39), 1,
      sym_fn_call,
    STATE(43), 1,
      sym__args,
    STATE(48), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [424] = 8,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(31), 1,
      sym_identifier,
    ACTIONS(34), 1,
      aux_sym_number_token1,
    STATE(10), 1,
      aux_sym_fn_call_repeat1,
    STATE(22), 1,
      sym__callable,
    STATE(23), 1,
      sym_number,
    STATE(26), 1,
      sym__args,
    ACTIONS(29), 2,
      anon_sym_let,
      anon_sym_and,
  [450] = 8,
    ACTIONS(25), 1,
      sym_identifier,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(41), 1,
      aux_sym_number_token1,
    STATE(12), 1,
      aux_sym_fn_call_repeat1,
    STATE(22), 1,
      sym__callable,
    STATE(23), 1,
      sym_number,
    STATE(26), 1,
      sym__args,
    ACTIONS(39), 2,
      anon_sym_let,
      anon_sym_and,
  [476] = 8,
    ACTIONS(25), 1,
      sym_identifier,
    ACTIONS(41), 1,
      aux_sym_number_token1,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    STATE(10), 1,
      aux_sym_fn_call_repeat1,
    STATE(22), 1,
      sym__callable,
    STATE(23), 1,
      sym_number,
    STATE(26), 1,
      sym__args,
    ACTIONS(45), 2,
      anon_sym_let,
      anon_sym_and,
  [502] = 7,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(47), 1,
      aux_sym_number_token1,
    STATE(15), 1,
      aux_sym_fn_call_repeat1,
    STATE(32), 1,
      sym_number,
    STATE(50), 1,
      sym__callable,
    STATE(51), 1,
      sym__args,
    ACTIONS(45), 2,
      anon_sym_and,
      anon_sym_in,
  [525] = 7,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(47), 1,
      aux_sym_number_token1,
    STATE(13), 1,
      aux_sym_fn_call_repeat1,
    STATE(32), 1,
      sym_number,
    STATE(50), 1,
      sym__callable,
    STATE(51), 1,
      sym__args,
    ACTIONS(39), 2,
      anon_sym_and,
      anon_sym_in,
  [548] = 7,
    ACTIONS(49), 1,
      sym_identifier,
    ACTIONS(52), 1,
      aux_sym_number_token1,
    STATE(15), 1,
      aux_sym_fn_call_repeat1,
    STATE(32), 1,
      sym_number,
    STATE(50), 1,
      sym__callable,
    STATE(51), 1,
      sym__args,
    ACTIONS(29), 2,
      anon_sym_and,
      anon_sym_in,
  [571] = 6,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(59), 1,
      sym_identifier,
    ACTIONS(62), 1,
      aux_sym_number_token1,
    STATE(16), 1,
      aux_sym_calc_repeat1,
    STATE(24), 1,
      sym_number,
    ACTIONS(57), 2,
      anon_sym_let,
      anon_sym_and,
  [591] = 6,
    ACTIONS(41), 1,
      aux_sym_number_token1,
    ACTIONS(65), 1,
      ts_builtin_sym_end,
    ACTIONS(69), 1,
      sym_identifier,
    STATE(16), 1,
      aux_sym_calc_repeat1,
    STATE(24), 1,
      sym_number,
    ACTIONS(67), 2,
      anon_sym_let,
      anon_sym_and,
  [611] = 5,
    ACTIONS(47), 1,
      aux_sym_number_token1,
    ACTIONS(71), 1,
      sym_identifier,
    STATE(19), 1,
      aux_sym_calc_repeat1,
    STATE(54), 1,
      sym_number,
    ACTIONS(67), 2,
      anon_sym_and,
      anon_sym_in,
  [628] = 5,
    ACTIONS(73), 1,
      sym_identifier,
    ACTIONS(76), 1,
      aux_sym_number_token1,
    STATE(19), 1,
      aux_sym_calc_repeat1,
    STATE(54), 1,
      sym_number,
    ACTIONS(57), 2,
      anon_sym_and,
      anon_sym_in,
  [645] = 2,
    ACTIONS(79), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(81), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [655] = 2,
    ACTIONS(83), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(85), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [665] = 2,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(39), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [675] = 2,
    ACTIONS(87), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(89), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [685] = 2,
    ACTIONS(91), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(93), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [695] = 2,
    ACTIONS(95), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(97), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [705] = 2,
    ACTIONS(99), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(101), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [715] = 1,
    ACTIONS(103), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [722] = 1,
    ACTIONS(87), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [729] = 1,
    ACTIONS(105), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [736] = 3,
    ACTIONS(107), 1,
      anon_sym_and,
    STATE(30), 1,
      aux_sym_let_expr_repeat1,
    ACTIONS(105), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [747] = 4,
    ACTIONS(47), 1,
      aux_sym_number_token1,
    ACTIONS(110), 1,
      sym_identifier,
    STATE(18), 1,
      aux_sym_calc_repeat1,
    STATE(54), 1,
      sym_number,
  [760] = 2,
    ACTIONS(87), 1,
      aux_sym_number_token1,
    ACTIONS(89), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [769] = 2,
    ACTIONS(83), 1,
      aux_sym_number_token1,
    ACTIONS(85), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [778] = 3,
    ACTIONS(5), 1,
      anon_sym_let,
    ACTIONS(112), 1,
      ts_builtin_sym_end,
    STATE(46), 2,
      sym_let_expr,
      aux_sym_source_file_repeat1,
  [789] = 1,
    ACTIONS(114), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [796] = 1,
    ACTIONS(116), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [803] = 1,
    ACTIONS(118), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [810] = 4,
    ACTIONS(41), 1,
      aux_sym_number_token1,
    ACTIONS(120), 1,
      sym_identifier,
    STATE(17), 1,
      aux_sym_calc_repeat1,
    STATE(24), 1,
      sym_number,
  [823] = 1,
    ACTIONS(122), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [830] = 3,
    ACTIONS(126), 1,
      anon_sym_and,
    STATE(30), 1,
      aux_sym_let_expr_repeat1,
    ACTIONS(124), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [841] = 1,
    ACTIONS(128), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [848] = 3,
    ACTIONS(126), 1,
      anon_sym_and,
    STATE(40), 1,
      aux_sym_let_expr_repeat1,
    ACTIONS(130), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [859] = 1,
    ACTIONS(132), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [866] = 1,
    ACTIONS(83), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [873] = 1,
    ACTIONS(134), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [880] = 3,
    ACTIONS(136), 1,
      ts_builtin_sym_end,
    ACTIONS(138), 1,
      anon_sym_let,
    STATE(46), 2,
      sym_let_expr,
      aux_sym_source_file_repeat1,
  [891] = 1,
    ACTIONS(141), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [898] = 1,
    ACTIONS(143), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [905] = 2,
    ACTIONS(79), 1,
      aux_sym_number_token1,
    ACTIONS(81), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [914] = 2,
    ACTIONS(37), 1,
      aux_sym_number_token1,
    ACTIONS(39), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [923] = 2,
    ACTIONS(99), 1,
      aux_sym_number_token1,
    ACTIONS(101), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [932] = 1,
    ACTIONS(145), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [939] = 2,
    ACTIONS(95), 1,
      aux_sym_number_token1,
    ACTIONS(97), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [948] = 2,
    ACTIONS(91), 1,
      aux_sym_number_token1,
    ACTIONS(93), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [957] = 3,
    ACTIONS(147), 1,
      anon_sym_and,
    ACTIONS(149), 1,
      anon_sym_in,
    STATE(62), 1,
      aux_sym_let_expr_repeat1,
  [967] = 3,
    ACTIONS(147), 1,
      anon_sym_and,
    ACTIONS(151), 1,
      anon_sym_in,
    STATE(55), 1,
      aux_sym_let_expr_repeat1,
  [977] = 3,
    ACTIONS(153), 1,
      sym_arrow,
    ACTIONS(155), 1,
      sym_identifier,
    STATE(57), 1,
      aux_sym_lambda_repeat1,
  [987] = 3,
    ACTIONS(158), 1,
      sym_arrow,
    ACTIONS(160), 1,
      sym_identifier,
    STATE(57), 1,
      aux_sym_lambda_repeat1,
  [997] = 3,
    ACTIONS(147), 1,
      anon_sym_and,
    ACTIONS(162), 1,
      anon_sym_in,
    STATE(61), 1,
      aux_sym_let_expr_repeat1,
  [1007] = 3,
    ACTIONS(160), 1,
      sym_identifier,
    ACTIONS(164), 1,
      sym_arrow,
    STATE(57), 1,
      aux_sym_lambda_repeat1,
  [1017] = 3,
    ACTIONS(147), 1,
      anon_sym_and,
    ACTIONS(166), 1,
      anon_sym_in,
    STATE(62), 1,
      aux_sym_let_expr_repeat1,
  [1027] = 3,
    ACTIONS(105), 1,
      anon_sym_in,
    ACTIONS(168), 1,
      anon_sym_and,
    STATE(62), 1,
      aux_sym_let_expr_repeat1,
  [1037] = 1,
    ACTIONS(171), 2,
      sym_identifier,
      aux_sym_number_token1,
  [1042] = 2,
    ACTIONS(160), 1,
      sym_identifier,
    STATE(58), 1,
      aux_sym_lambda_repeat1,
  [1049] = 2,
    ACTIONS(173), 1,
      sym_identifier,
    STATE(56), 1,
      sym_def,
  [1056] = 2,
    ACTIONS(175), 1,
      sym_identifier,
    STATE(29), 1,
      sym_def,
  [1063] = 1,
    ACTIONS(177), 2,
      sym_identifier,
      aux_sym_number_token1,
  [1068] = 2,
    ACTIONS(175), 1,
      sym_identifier,
    STATE(42), 1,
      sym_def,
  [1075] = 1,
    ACTIONS(179), 2,
      sym_arrow,
      sym_identifier,
  [1080] = 2,
    ACTIONS(173), 1,
      sym_identifier,
    STATE(29), 1,
      sym_def,
  [1087] = 2,
    ACTIONS(173), 1,
      sym_identifier,
    STATE(59), 1,
      sym_def,
  [1094] = 2,
    ACTIONS(160), 1,
      sym_identifier,
    STATE(60), 1,
      aux_sym_lambda_repeat1,
  [1101] = 1,
    ACTIONS(181), 1,
      anon_sym_EQ,
  [1105] = 1,
    ACTIONS(183), 1,
      ts_builtin_sym_end,
  [1109] = 1,
    ACTIONS(185), 1,
      anon_sym_EQ,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 53,
  [SMALL_STATE(4)] = 106,
  [SMALL_STATE(5)] = 159,
  [SMALL_STATE(6)] = 212,
  [SMALL_STATE(7)] = 265,
  [SMALL_STATE(8)] = 318,
  [SMALL_STATE(9)] = 371,
  [SMALL_STATE(10)] = 424,
  [SMALL_STATE(11)] = 450,
  [SMALL_STATE(12)] = 476,
  [SMALL_STATE(13)] = 502,
  [SMALL_STATE(14)] = 525,
  [SMALL_STATE(15)] = 548,
  [SMALL_STATE(16)] = 571,
  [SMALL_STATE(17)] = 591,
  [SMALL_STATE(18)] = 611,
  [SMALL_STATE(19)] = 628,
  [SMALL_STATE(20)] = 645,
  [SMALL_STATE(21)] = 655,
  [SMALL_STATE(22)] = 665,
  [SMALL_STATE(23)] = 675,
  [SMALL_STATE(24)] = 685,
  [SMALL_STATE(25)] = 695,
  [SMALL_STATE(26)] = 705,
  [SMALL_STATE(27)] = 715,
  [SMALL_STATE(28)] = 722,
  [SMALL_STATE(29)] = 729,
  [SMALL_STATE(30)] = 736,
  [SMALL_STATE(31)] = 747,
  [SMALL_STATE(32)] = 760,
  [SMALL_STATE(33)] = 769,
  [SMALL_STATE(34)] = 778,
  [SMALL_STATE(35)] = 789,
  [SMALL_STATE(36)] = 796,
  [SMALL_STATE(37)] = 803,
  [SMALL_STATE(38)] = 810,
  [SMALL_STATE(39)] = 823,
  [SMALL_STATE(40)] = 830,
  [SMALL_STATE(41)] = 841,
  [SMALL_STATE(42)] = 848,
  [SMALL_STATE(43)] = 859,
  [SMALL_STATE(44)] = 866,
  [SMALL_STATE(45)] = 873,
  [SMALL_STATE(46)] = 880,
  [SMALL_STATE(47)] = 891,
  [SMALL_STATE(48)] = 898,
  [SMALL_STATE(49)] = 905,
  [SMALL_STATE(50)] = 914,
  [SMALL_STATE(51)] = 923,
  [SMALL_STATE(52)] = 932,
  [SMALL_STATE(53)] = 939,
  [SMALL_STATE(54)] = 948,
  [SMALL_STATE(55)] = 957,
  [SMALL_STATE(56)] = 967,
  [SMALL_STATE(57)] = 977,
  [SMALL_STATE(58)] = 987,
  [SMALL_STATE(59)] = 997,
  [SMALL_STATE(60)] = 1007,
  [SMALL_STATE(61)] = 1017,
  [SMALL_STATE(62)] = 1027,
  [SMALL_STATE(63)] = 1037,
  [SMALL_STATE(64)] = 1042,
  [SMALL_STATE(65)] = 1049,
  [SMALL_STATE(66)] = 1056,
  [SMALL_STATE(67)] = 1063,
  [SMALL_STATE(68)] = 1068,
  [SMALL_STATE(69)] = 1075,
  [SMALL_STATE(70)] = 1080,
  [SMALL_STATE(71)] = 1087,
  [SMALL_STATE(72)] = 1094,
  [SMALL_STATE(73)] = 1101,
  [SMALL_STATE(74)] = 1105,
  [SMALL_STATE(75)] = 1109,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 18),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 18),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 18), SHIFT_REPEAT(20),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 18), SHIFT_REPEAT(21),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__args, 1, .production_id = 7),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__args, 1, .production_id = 7),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_call, 2, .production_id = 15),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fn_call, 2, .production_id = 15),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 18), SHIFT_REPEAT(49),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 18), SHIFT_REPEAT(33),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 18),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 18),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 18), SHIFT_REPEAT(25),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 18), SHIFT_REPEAT(21),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_calc, 2, .production_id = 16),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_calc, 2, .production_id = 16),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 18), SHIFT_REPEAT(53),
  [76] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 18), SHIFT_REPEAT(33),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__callable, 1, .production_id = 5),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__callable, 1, .production_id = 5),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 1),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__args, 1, .production_id = 14),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__args, 1, .production_id = 14),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 14),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 14),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 5),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 5),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 1, .production_id = 8),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 1, .production_id = 8),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 6),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2),
  [107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2), SHIFT_REPEAT(66),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 13),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 12),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 11),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 10),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expr, 3, .production_id = 2),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_def, 3, .production_id = 9),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expr, 2, .production_id = 1),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 8),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_in_expr, 4, .production_id = 19),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [138] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(68),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lambda, 4, .production_id = 20),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_in_expr, 5, .production_id = 21),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lambda_repeat1, 2, .production_id = 17),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_lambda_repeat1, 2, .production_id = 17), SHIFT_REPEAT(69),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [168] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2), SHIFT_REPEAT(70),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__calc, 1, .production_id = 3),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__calc, 1, .production_id = 4),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lambda_repeat1, 1, .production_id = 5),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [183] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
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
