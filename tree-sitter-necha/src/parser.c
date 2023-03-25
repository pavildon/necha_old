#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 66
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 61
#define ALIAS_COUNT 0
#define TOKEN_COUNT 45
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 10
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 19

enum {
  anon_sym_true = 1,
  anon_sym_false = 2,
  anon_sym_let = 3,
  anon_sym_and = 4,
  anon_sym_EQ = 5,
  anon_sym_in = 6,
  anon_sym_import = 7,
  anon_sym_BSLASH = 8,
  anon_sym_DOT = 9,
  anon_sym_LBRACK = 10,
  anon_sym_RBRACK = 11,
  anon_sym_LBRACE = 12,
  anon_sym_RBRACE = 13,
  anon_sym_if = 14,
  anon_sym_else = 15,
  anon_sym_COLON = 16,
  anon_sym_COMMA = 17,
  anon_sym_for = 18,
  anon_sym_while = 19,
  anon_sym_LPAREN = 20,
  anon_sym_RPAREN = 21,
  sym_pub = 22,
  sym_var = 23,
  sym_const = 24,
  anon_sym_DQUOTE = 25,
  anon_sym_SQUOTE = 26,
  sym_eq = 27,
  sym_neq = 28,
  sym_geq = 29,
  sym_leq = 30,
  sym_greater = 31,
  sym_less = 32,
  anon_sym_AMP_AMP = 33,
  anon_sym_PIPE_PIPE = 34,
  anon_sym_or = 35,
  sym_bang = 36,
  sym_exp = 37,
  sym_minus = 38,
  sym_plus = 39,
  sym_mul = 40,
  sym_div = 41,
  sym_mod = 42,
  sym_identifier = 43,
  aux_sym_number_token1 = 44,
  sym_source_file = 45,
  sym_boolean = 46,
  sym_let_expr = 47,
  sym_def = 48,
  sym__callable = 49,
  sym__args = 50,
  sym__exprz = 51,
  sym_fn_call = 52,
  sym__calc = 53,
  sym_calc = 54,
  sym_let_in_expr = 55,
  sym_number = 56,
  aux_sym_source_file_repeat1 = 57,
  aux_sym_let_expr_repeat1 = 58,
  aux_sym_fn_call_repeat1 = 59,
  aux_sym_calc_repeat1 = 60,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_let] = "let",
  [anon_sym_and] = "and",
  [anon_sym_EQ] = "=",
  [anon_sym_in] = "in",
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
  [sym_number] = "number",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_let_expr_repeat1] = "let_expr_repeat1",
  [aux_sym_fn_call_repeat1] = "fn_call_repeat1",
  [aux_sym_calc_repeat1] = "calc_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_in] = anon_sym_in,
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
  [sym_number] = sym_number,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_let_expr_repeat1] = aux_sym_let_expr_repeat1,
  [aux_sym_fn_call_repeat1] = aux_sym_fn_call_repeat1,
  [aux_sym_calc_repeat1] = aux_sym_calc_repeat1,
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
};

enum {
  field_add = 1,
  field_boolean = 2,
  field_calc = 3,
  field_def = 4,
  field_expr = 5,
  field_fn_call = 6,
  field_ident = 7,
  field_let_in = 8,
  field_mul = 9,
  field_number = 10,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_add] = "add",
  [field_boolean] = "boolean",
  [field_calc] = "calc",
  [field_def] = "def",
  [field_expr] = "expr",
  [field_fn_call] = "fn_call",
  [field_ident] = "ident",
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
  [9] = {.index = 10, .length = 8},
  [10] = {.index = 18, .length = 1},
  [11] = {.index = 19, .length = 1},
  [12] = {.index = 20, .length = 1},
  [13] = {.index = 21, .length = 1},
  [14] = {.index = 22, .length = 3},
  [15] = {.index = 25, .length = 4},
  [16] = {.index = 29, .length = 4},
  [17] = {.index = 33, .length = 8},
  [18] = {.index = 41, .length = 9},
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
    {field_let_in, 2, .inherited = true},
    {field_number, 2, .inherited = true},
  [18] =
    {field_fn_call, 0},
  [19] =
    {field_calc, 0},
  [20] =
    {field_let_in, 0},
  [21] =
    {field_number, 0},
  [22] =
    {field_ident, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_number, 1, .inherited = true},
  [25] =
    {field_add, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_mul, 0, .inherited = true},
    {field_number, 1, .inherited = true},
  [29] =
    {field_ident, 0, .inherited = true},
    {field_ident, 1, .inherited = true},
    {field_number, 0, .inherited = true},
    {field_number, 1, .inherited = true},
  [33] =
    {field_boolean, 3, .inherited = true},
    {field_calc, 3, .inherited = true},
    {field_def, 1},
    {field_expr, 3},
    {field_fn_call, 3, .inherited = true},
    {field_ident, 3, .inherited = true},
    {field_let_in, 3, .inherited = true},
    {field_number, 3, .inherited = true},
  [41] =
    {field_boolean, 4, .inherited = true},
    {field_calc, 4, .inherited = true},
    {field_def, 1},
    {field_def, 2},
    {field_expr, 4},
    {field_fn_call, 4, .inherited = true},
    {field_ident, 4, .inherited = true},
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
  [3] = 2,
  [4] = 4,
  [5] = 5,
  [6] = 5,
  [7] = 4,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 10,
  [12] = 8,
  [13] = 9,
  [14] = 14,
  [15] = 15,
  [16] = 14,
  [17] = 15,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 19,
  [26] = 19,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 18,
  [31] = 31,
  [32] = 32,
  [33] = 29,
  [34] = 34,
  [35] = 35,
  [36] = 18,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 20,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 21,
  [47] = 24,
  [48] = 48,
  [49] = 23,
  [50] = 22,
  [51] = 51,
  [52] = 52,
  [53] = 52,
  [54] = 51,
  [55] = 28,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 56,
  [62] = 57,
  [63] = 63,
  [64] = 64,
  [65] = 63,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(58);
      if (lookahead == '!') ADVANCE(100);
      if (lookahead == '"') ADVANCE(89);
      if (lookahead == '%') ADVANCE(106);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '\'') ADVANCE(90);
      if (lookahead == '(') ADVANCE(84);
      if (lookahead == ')') ADVANCE(85);
      if (lookahead == '*') ADVANCE(104);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(81);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == '.') ADVANCE(73);
      if (lookahead == '/') ADVANCE(105);
      if (lookahead == ':') ADVANCE(80);
      if (lookahead == '<') ADVANCE(96);
      if (lookahead == '=') ADVANCE(68);
      if (lookahead == '>') ADVANCE(95);
      if (lookahead == '[') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(72);
      if (lookahead == ']') ADVANCE(75);
      if (lookahead == '^') ADVANCE(101);
      if (lookahead == '_') SKIP(53)
      if (lookahead == 'a') ADVANCE(23);
      if (lookahead == 'c') ADVANCE(25);
      if (lookahead == 'e') ADVANCE(20);
      if (lookahead == 'f') ADVANCE(9);
      if (lookahead == 'i') ADVANCE(17);
      if (lookahead == 'l') ADVANCE(12);
      if (lookahead == 'o') ADVANCE(28);
      if (lookahead == 'p') ADVANCE(39);
      if (lookahead == 't') ADVANCE(31);
      if (lookahead == 'v') ADVANCE(8);
      if (lookahead == 'w') ADVANCE(18);
      if (lookahead == '{') ADVANCE(76);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '}') ADVANCE(77);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(44)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(45)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(46)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      END_STATE();
    case 4:
      if (lookahead == '&') ADVANCE(97);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(104);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == '.') ADVANCE(49);
      if (lookahead == '0') ADVANCE(121);
      if (lookahead == '=') ADVANCE(67);
      if (lookahead == '_') SKIP(1)
      if (lookahead == 'f') ADVANCE(107);
      if (lookahead == 'l') ADVANCE(109);
      if (lookahead == 't') ADVANCE(115);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 6:
      if (lookahead == '.') ADVANCE(49);
      if (lookahead == '0') ADVANCE(121);
      if (lookahead == '_') SKIP(2)
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'i') ADVANCE(114);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(49);
      if (lookahead == '0') ADVANCE(121);
      if (lookahead == '_') SKIP(3)
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(30);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(22);
      if (lookahead == 'o') ADVANCE(29);
      END_STATE();
    case 10:
      if (lookahead == 'b') ADVANCE(86);
      END_STATE();
    case 11:
      if (lookahead == 'd') ADVANCE(65);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(36);
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(79);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(61);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(83);
      END_STATE();
    case 17:
      if (lookahead == 'f') ADVANCE(78);
      if (lookahead == 'm') ADVANCE(27);
      if (lookahead == 'n') ADVANCE(69);
      END_STATE();
    case 18:
      if (lookahead == 'h') ADVANCE(19);
      END_STATE();
    case 19:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 20:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 21:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(35);
      END_STATE();
    case 23:
      if (lookahead == 'n') ADVANCE(11);
      END_STATE();
    case 24:
      if (lookahead == 'n') ADVANCE(34);
      END_STATE();
    case 25:
      if (lookahead == 'o') ADVANCE(24);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(32);
      END_STATE();
    case 27:
      if (lookahead == 'p') ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead == 'r') ADVANCE(99);
      END_STATE();
    case 29:
      if (lookahead == 'r') ADVANCE(82);
      END_STATE();
    case 30:
      if (lookahead == 'r') ADVANCE(87);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 33:
      if (lookahead == 's') ADVANCE(13);
      END_STATE();
    case 34:
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 35:
      if (lookahead == 's') ADVANCE(15);
      END_STATE();
    case 36:
      if (lookahead == 't') ADVANCE(63);
      END_STATE();
    case 37:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 38:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 39:
      if (lookahead == 'u') ADVANCE(10);
      END_STATE();
    case 40:
      if (lookahead == 'u') ADVANCE(14);
      END_STATE();
    case 41:
      if (lookahead == '|') ADVANCE(98);
      END_STATE();
    case 42:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(127);
      END_STATE();
    case 43:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(123);
      END_STATE();
    case 44:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (lookahead == '*') ADVANCE(104);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == '.') ADVANCE(49);
      if (lookahead == '0') ADVANCE(121);
      if (lookahead == '=') ADVANCE(67);
      if (lookahead == '_') SKIP(1)
      if (lookahead == 'f') ADVANCE(107);
      if (lookahead == 'l') ADVANCE(109);
      if (lookahead == 't') ADVANCE(115);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 45:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(45)
      if (lookahead == '.') ADVANCE(49);
      if (lookahead == '0') ADVANCE(121);
      if (lookahead == '_') SKIP(2)
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'i') ADVANCE(114);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 46:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (lookahead == '.') ADVANCE(49);
      if (lookahead == '0') ADVANCE(121);
      if (lookahead == '_') SKIP(3)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(124);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(128);
      END_STATE();
    case 50:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(126);
      END_STATE();
    case 51:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(127);
      END_STATE();
    case 52:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(125);
      END_STATE();
    case 53:
      if (eof) ADVANCE(58);
      if (lookahead == '\n') SKIP(56)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(53)
      END_STATE();
    case 54:
      if (eof) ADVANCE(58);
      if (lookahead == '\n') SKIP(57)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(54)
      END_STATE();
    case 55:
      if (eof) ADVANCE(58);
      if (lookahead == '.') ADVANCE(49);
      if (lookahead == '0') ADVANCE(121);
      if (lookahead == '_') SKIP(54)
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'l') ADVANCE(109);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(55)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 56:
      if (eof) ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(56)
      if (lookahead == '!') ADVANCE(100);
      if (lookahead == '"') ADVANCE(89);
      if (lookahead == '%') ADVANCE(106);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '\'') ADVANCE(90);
      if (lookahead == '(') ADVANCE(84);
      if (lookahead == ')') ADVANCE(85);
      if (lookahead == '*') ADVANCE(104);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(81);
      if (lookahead == '-') ADVANCE(102);
      if (lookahead == '.') ADVANCE(73);
      if (lookahead == '/') ADVANCE(105);
      if (lookahead == ':') ADVANCE(80);
      if (lookahead == '<') ADVANCE(96);
      if (lookahead == '=') ADVANCE(68);
      if (lookahead == '>') ADVANCE(95);
      if (lookahead == '[') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(72);
      if (lookahead == ']') ADVANCE(75);
      if (lookahead == '^') ADVANCE(101);
      if (lookahead == '_') SKIP(53)
      if (lookahead == 'a') ADVANCE(23);
      if (lookahead == 'c') ADVANCE(25);
      if (lookahead == 'e') ADVANCE(20);
      if (lookahead == 'f') ADVANCE(9);
      if (lookahead == 'i') ADVANCE(17);
      if (lookahead == 'l') ADVANCE(12);
      if (lookahead == 'o') ADVANCE(28);
      if (lookahead == 'p') ADVANCE(39);
      if (lookahead == 't') ADVANCE(31);
      if (lookahead == 'v') ADVANCE(8);
      if (lookahead == 'w') ADVANCE(18);
      if (lookahead == '{') ADVANCE(76);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '}') ADVANCE(77);
      END_STATE();
    case 57:
      if (eof) ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(57)
      if (lookahead == '.') ADVANCE(49);
      if (lookahead == '0') ADVANCE(121);
      if (lookahead == '_') SKIP(54)
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'l') ADVANCE(109);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_and);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(91);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_in);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_pub);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_var);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_const);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_eq);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_neq);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_geq);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_leq);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_greater);
      if (lookahead == '=') ADVANCE(93);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_less);
      if (lookahead == '=') ADVANCE(94);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_bang);
      if (lookahead == '=') ADVANCE(92);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_exp);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_minus);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_plus);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_mul);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_div);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_mod);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(119);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(aux_sym_number_token1);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(129);
      if (lookahead == '0') ADVANCE(126);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(43);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(42);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(47);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(52);
      if (lookahead == '_') ADVANCE(50);
      if (lookahead == 'n') ADVANCE(120);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(129);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(42);
      if (lookahead == '_') ADVANCE(48);
      if (lookahead == 'n') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(43);
      if (lookahead == 'n') ADVANCE(120);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(123);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(47);
      if (lookahead == 'n') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(124);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(52);
      if (lookahead == 'n') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(125);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(50);
      if (lookahead == 'n') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(126);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(127);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(42);
      if (lookahead == '_') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(128);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(128);
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
  [8] = {.lex_state = 55},
  [9] = {.lex_state = 55},
  [10] = {.lex_state = 55},
  [11] = {.lex_state = 6},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 55},
  [15] = {.lex_state = 55},
  [16] = {.lex_state = 6},
  [17] = {.lex_state = 6},
  [18] = {.lex_state = 55},
  [19] = {.lex_state = 55},
  [20] = {.lex_state = 55},
  [21] = {.lex_state = 55},
  [22] = {.lex_state = 55},
  [23] = {.lex_state = 55},
  [24] = {.lex_state = 55},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 6},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 7},
  [30] = {.lex_state = 6},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 7},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 6},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 6},
  [47] = {.lex_state = 6},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 6},
  [50] = {.lex_state = 6},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 7},
  [57] = {.lex_state = 7},
  [58] = {.lex_state = 7},
  [59] = {.lex_state = 7},
  [60] = {.lex_state = 7},
  [61] = {.lex_state = 7},
  [62] = {.lex_state = 7},
  [63] = {.lex_state = 5},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 5},
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
    [sym_source_file] = STATE(64),
    [sym_let_expr] = STATE(40),
    [aux_sym_source_file_repeat1] = STATE(40),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_let] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 15,
    ACTIONS(9), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      sym_plus,
    ACTIONS(13), 1,
      sym_mul,
    ACTIONS(15), 1,
      sym_identifier,
    ACTIONS(17), 1,
      aux_sym_number_token1,
    STATE(8), 1,
      sym__callable,
    STATE(31), 1,
      sym_let_in_expr,
    STATE(32), 1,
      sym_calc,
    STATE(33), 1,
      sym__calc,
    STATE(34), 1,
      sym_fn_call,
    STATE(35), 1,
      sym__exprz,
    STATE(36), 1,
      sym_number,
    STATE(37), 1,
      sym__args,
    STATE(38), 1,
      sym_boolean,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [47] = 15,
    ACTIONS(11), 1,
      sym_plus,
    ACTIONS(13), 1,
      sym_mul,
    ACTIONS(17), 1,
      aux_sym_number_token1,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_identifier,
    STATE(12), 1,
      sym__callable,
    STATE(29), 1,
      sym__calc,
    STATE(31), 1,
      sym_let_in_expr,
    STATE(32), 1,
      sym_calc,
    STATE(34), 1,
      sym_fn_call,
    STATE(35), 1,
      sym__exprz,
    STATE(36), 1,
      sym_number,
    STATE(37), 1,
      sym__args,
    STATE(38), 1,
      sym_boolean,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [94] = 15,
    ACTIONS(11), 1,
      sym_plus,
    ACTIONS(13), 1,
      sym_mul,
    ACTIONS(17), 1,
      aux_sym_number_token1,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_identifier,
    STATE(12), 1,
      sym__callable,
    STATE(29), 1,
      sym__calc,
    STATE(31), 1,
      sym_let_in_expr,
    STATE(32), 1,
      sym_calc,
    STATE(34), 1,
      sym_fn_call,
    STATE(36), 1,
      sym_number,
    STATE(37), 1,
      sym__args,
    STATE(38), 1,
      sym_boolean,
    STATE(41), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [141] = 15,
    ACTIONS(9), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      sym_plus,
    ACTIONS(13), 1,
      sym_mul,
    ACTIONS(15), 1,
      sym_identifier,
    ACTIONS(17), 1,
      aux_sym_number_token1,
    STATE(8), 1,
      sym__callable,
    STATE(31), 1,
      sym_let_in_expr,
    STATE(32), 1,
      sym_calc,
    STATE(33), 1,
      sym__calc,
    STATE(34), 1,
      sym_fn_call,
    STATE(36), 1,
      sym_number,
    STATE(37), 1,
      sym__args,
    STATE(38), 1,
      sym_boolean,
    STATE(39), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [188] = 15,
    ACTIONS(11), 1,
      sym_plus,
    ACTIONS(13), 1,
      sym_mul,
    ACTIONS(17), 1,
      aux_sym_number_token1,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_identifier,
    STATE(12), 1,
      sym__callable,
    STATE(29), 1,
      sym__calc,
    STATE(31), 1,
      sym_let_in_expr,
    STATE(32), 1,
      sym_calc,
    STATE(34), 1,
      sym_fn_call,
    STATE(36), 1,
      sym_number,
    STATE(37), 1,
      sym__args,
    STATE(38), 1,
      sym_boolean,
    STATE(39), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [235] = 15,
    ACTIONS(9), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      sym_plus,
    ACTIONS(13), 1,
      sym_mul,
    ACTIONS(15), 1,
      sym_identifier,
    ACTIONS(17), 1,
      aux_sym_number_token1,
    STATE(8), 1,
      sym__callable,
    STATE(31), 1,
      sym_let_in_expr,
    STATE(32), 1,
      sym_calc,
    STATE(33), 1,
      sym__calc,
    STATE(34), 1,
      sym_fn_call,
    STATE(36), 1,
      sym_number,
    STATE(37), 1,
      sym__args,
    STATE(38), 1,
      sym_boolean,
    STATE(41), 1,
      sym__exprz,
    ACTIONS(7), 2,
      anon_sym_true,
      anon_sym_false,
  [282] = 8,
    ACTIONS(15), 1,
      sym_identifier,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 1,
      aux_sym_number_token1,
    STATE(10), 1,
      aux_sym_fn_call_repeat1,
    STATE(18), 1,
      sym_number,
    STATE(21), 1,
      sym__callable,
    STATE(24), 1,
      sym__args,
    ACTIONS(25), 2,
      anon_sym_let,
      anon_sym_and,
  [308] = 8,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      sym_identifier,
    ACTIONS(36), 1,
      aux_sym_number_token1,
    STATE(9), 1,
      aux_sym_fn_call_repeat1,
    STATE(18), 1,
      sym_number,
    STATE(21), 1,
      sym__callable,
    STATE(24), 1,
      sym__args,
    ACTIONS(31), 2,
      anon_sym_let,
      anon_sym_and,
  [334] = 8,
    ACTIONS(15), 1,
      sym_identifier,
    ACTIONS(27), 1,
      aux_sym_number_token1,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    STATE(9), 1,
      aux_sym_fn_call_repeat1,
    STATE(18), 1,
      sym_number,
    STATE(21), 1,
      sym__callable,
    STATE(24), 1,
      sym__args,
    ACTIONS(41), 2,
      anon_sym_let,
      anon_sym_and,
  [360] = 7,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(43), 1,
      aux_sym_number_token1,
    STATE(13), 1,
      aux_sym_fn_call_repeat1,
    STATE(30), 1,
      sym_number,
    STATE(46), 1,
      sym__callable,
    STATE(47), 1,
      sym__args,
    ACTIONS(41), 2,
      anon_sym_and,
      anon_sym_in,
  [383] = 7,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(43), 1,
      aux_sym_number_token1,
    STATE(11), 1,
      aux_sym_fn_call_repeat1,
    STATE(30), 1,
      sym_number,
    STATE(46), 1,
      sym__callable,
    STATE(47), 1,
      sym__args,
    ACTIONS(25), 2,
      anon_sym_and,
      anon_sym_in,
  [406] = 7,
    ACTIONS(45), 1,
      sym_identifier,
    ACTIONS(48), 1,
      aux_sym_number_token1,
    STATE(13), 1,
      aux_sym_fn_call_repeat1,
    STATE(30), 1,
      sym_number,
    STATE(46), 1,
      sym__callable,
    STATE(47), 1,
      sym__args,
    ACTIONS(31), 2,
      anon_sym_and,
      anon_sym_in,
  [429] = 6,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
    ACTIONS(55), 1,
      sym_identifier,
    ACTIONS(58), 1,
      aux_sym_number_token1,
    STATE(14), 1,
      aux_sym_calc_repeat1,
    STATE(22), 1,
      sym_number,
    ACTIONS(53), 2,
      anon_sym_let,
      anon_sym_and,
  [449] = 6,
    ACTIONS(27), 1,
      aux_sym_number_token1,
    ACTIONS(61), 1,
      ts_builtin_sym_end,
    ACTIONS(65), 1,
      sym_identifier,
    STATE(14), 1,
      aux_sym_calc_repeat1,
    STATE(22), 1,
      sym_number,
    ACTIONS(63), 2,
      anon_sym_let,
      anon_sym_and,
  [469] = 5,
    ACTIONS(67), 1,
      sym_identifier,
    ACTIONS(70), 1,
      aux_sym_number_token1,
    STATE(16), 1,
      aux_sym_calc_repeat1,
    STATE(50), 1,
      sym_number,
    ACTIONS(53), 2,
      anon_sym_and,
      anon_sym_in,
  [486] = 5,
    ACTIONS(43), 1,
      aux_sym_number_token1,
    ACTIONS(73), 1,
      sym_identifier,
    STATE(16), 1,
      aux_sym_calc_repeat1,
    STATE(50), 1,
      sym_number,
    ACTIONS(63), 2,
      anon_sym_and,
      anon_sym_in,
  [503] = 2,
    ACTIONS(75), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(77), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [513] = 2,
    ACTIONS(79), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(81), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [523] = 2,
    ACTIONS(83), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(85), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [533] = 2,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(25), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [543] = 2,
    ACTIONS(87), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(89), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [553] = 2,
    ACTIONS(91), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(93), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [563] = 2,
    ACTIONS(95), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(97), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [573] = 1,
    ACTIONS(79), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [580] = 2,
    ACTIONS(79), 1,
      aux_sym_number_token1,
    ACTIONS(81), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [589] = 1,
    ACTIONS(99), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [596] = 3,
    ACTIONS(101), 1,
      anon_sym_and,
    STATE(28), 1,
      aux_sym_let_expr_repeat1,
    ACTIONS(99), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [607] = 4,
    ACTIONS(43), 1,
      aux_sym_number_token1,
    ACTIONS(104), 1,
      sym_identifier,
    STATE(17), 1,
      aux_sym_calc_repeat1,
    STATE(50), 1,
      sym_number,
  [620] = 2,
    ACTIONS(75), 1,
      aux_sym_number_token1,
    ACTIONS(77), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [629] = 1,
    ACTIONS(106), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [636] = 1,
    ACTIONS(108), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [643] = 4,
    ACTIONS(27), 1,
      aux_sym_number_token1,
    ACTIONS(110), 1,
      sym_identifier,
    STATE(15), 1,
      aux_sym_calc_repeat1,
    STATE(22), 1,
      sym_number,
  [656] = 1,
    ACTIONS(112), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [663] = 1,
    ACTIONS(114), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [670] = 1,
    ACTIONS(75), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [677] = 1,
    ACTIONS(116), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [684] = 1,
    ACTIONS(118), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [691] = 1,
    ACTIONS(120), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [698] = 3,
    ACTIONS(5), 1,
      anon_sym_let,
    ACTIONS(122), 1,
      ts_builtin_sym_end,
    STATE(44), 2,
      sym_let_expr,
      aux_sym_source_file_repeat1,
  [709] = 1,
    ACTIONS(124), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [716] = 2,
    ACTIONS(83), 1,
      aux_sym_number_token1,
    ACTIONS(85), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [725] = 3,
    ACTIONS(128), 1,
      anon_sym_and,
    STATE(48), 1,
      aux_sym_let_expr_repeat1,
    ACTIONS(126), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [736] = 3,
    ACTIONS(130), 1,
      ts_builtin_sym_end,
    ACTIONS(132), 1,
      anon_sym_let,
    STATE(44), 2,
      sym_let_expr,
      aux_sym_source_file_repeat1,
  [747] = 1,
    ACTIONS(135), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [754] = 2,
    ACTIONS(23), 1,
      aux_sym_number_token1,
    ACTIONS(25), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [763] = 2,
    ACTIONS(95), 1,
      aux_sym_number_token1,
    ACTIONS(97), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [772] = 3,
    ACTIONS(128), 1,
      anon_sym_and,
    STATE(28), 1,
      aux_sym_let_expr_repeat1,
    ACTIONS(137), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [783] = 2,
    ACTIONS(91), 1,
      aux_sym_number_token1,
    ACTIONS(93), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [792] = 2,
    ACTIONS(87), 1,
      aux_sym_number_token1,
    ACTIONS(89), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [801] = 3,
    ACTIONS(139), 1,
      anon_sym_and,
    ACTIONS(141), 1,
      anon_sym_in,
    STATE(55), 1,
      aux_sym_let_expr_repeat1,
  [811] = 3,
    ACTIONS(139), 1,
      anon_sym_and,
    ACTIONS(143), 1,
      anon_sym_in,
    STATE(51), 1,
      aux_sym_let_expr_repeat1,
  [821] = 3,
    ACTIONS(139), 1,
      anon_sym_and,
    ACTIONS(145), 1,
      anon_sym_in,
    STATE(54), 1,
      aux_sym_let_expr_repeat1,
  [831] = 3,
    ACTIONS(139), 1,
      anon_sym_and,
    ACTIONS(147), 1,
      anon_sym_in,
    STATE(55), 1,
      aux_sym_let_expr_repeat1,
  [841] = 3,
    ACTIONS(99), 1,
      anon_sym_in,
    ACTIONS(149), 1,
      anon_sym_and,
    STATE(55), 1,
      aux_sym_let_expr_repeat1,
  [851] = 2,
    ACTIONS(152), 1,
      sym_identifier,
    STATE(27), 1,
      sym_def,
  [858] = 2,
    ACTIONS(154), 1,
      sym_identifier,
    STATE(52), 1,
      sym_def,
  [865] = 1,
    ACTIONS(156), 2,
      sym_identifier,
      aux_sym_number_token1,
  [870] = 1,
    ACTIONS(158), 2,
      sym_identifier,
      aux_sym_number_token1,
  [875] = 2,
    ACTIONS(152), 1,
      sym_identifier,
    STATE(43), 1,
      sym_def,
  [882] = 2,
    ACTIONS(154), 1,
      sym_identifier,
    STATE(27), 1,
      sym_def,
  [889] = 2,
    ACTIONS(154), 1,
      sym_identifier,
    STATE(53), 1,
      sym_def,
  [896] = 1,
    ACTIONS(160), 1,
      anon_sym_EQ,
  [900] = 1,
    ACTIONS(162), 1,
      ts_builtin_sym_end,
  [904] = 1,
    ACTIONS(164), 1,
      anon_sym_EQ,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 94,
  [SMALL_STATE(5)] = 141,
  [SMALL_STATE(6)] = 188,
  [SMALL_STATE(7)] = 235,
  [SMALL_STATE(8)] = 282,
  [SMALL_STATE(9)] = 308,
  [SMALL_STATE(10)] = 334,
  [SMALL_STATE(11)] = 360,
  [SMALL_STATE(12)] = 383,
  [SMALL_STATE(13)] = 406,
  [SMALL_STATE(14)] = 429,
  [SMALL_STATE(15)] = 449,
  [SMALL_STATE(16)] = 469,
  [SMALL_STATE(17)] = 486,
  [SMALL_STATE(18)] = 503,
  [SMALL_STATE(19)] = 513,
  [SMALL_STATE(20)] = 523,
  [SMALL_STATE(21)] = 533,
  [SMALL_STATE(22)] = 543,
  [SMALL_STATE(23)] = 553,
  [SMALL_STATE(24)] = 563,
  [SMALL_STATE(25)] = 573,
  [SMALL_STATE(26)] = 580,
  [SMALL_STATE(27)] = 589,
  [SMALL_STATE(28)] = 596,
  [SMALL_STATE(29)] = 607,
  [SMALL_STATE(30)] = 620,
  [SMALL_STATE(31)] = 629,
  [SMALL_STATE(32)] = 636,
  [SMALL_STATE(33)] = 643,
  [SMALL_STATE(34)] = 656,
  [SMALL_STATE(35)] = 663,
  [SMALL_STATE(36)] = 670,
  [SMALL_STATE(37)] = 677,
  [SMALL_STATE(38)] = 684,
  [SMALL_STATE(39)] = 691,
  [SMALL_STATE(40)] = 698,
  [SMALL_STATE(41)] = 709,
  [SMALL_STATE(42)] = 716,
  [SMALL_STATE(43)] = 725,
  [SMALL_STATE(44)] = 736,
  [SMALL_STATE(45)] = 747,
  [SMALL_STATE(46)] = 754,
  [SMALL_STATE(47)] = 763,
  [SMALL_STATE(48)] = 772,
  [SMALL_STATE(49)] = 783,
  [SMALL_STATE(50)] = 792,
  [SMALL_STATE(51)] = 801,
  [SMALL_STATE(52)] = 811,
  [SMALL_STATE(53)] = 821,
  [SMALL_STATE(54)] = 831,
  [SMALL_STATE(55)] = 841,
  [SMALL_STATE(56)] = 851,
  [SMALL_STATE(57)] = 858,
  [SMALL_STATE(58)] = 865,
  [SMALL_STATE(59)] = 870,
  [SMALL_STATE(60)] = 875,
  [SMALL_STATE(61)] = 882,
  [SMALL_STATE(62)] = 889,
  [SMALL_STATE(63)] = 896,
  [SMALL_STATE(64)] = 900,
  [SMALL_STATE(65)] = 904,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__args, 1, .production_id = 7),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__args, 1, .production_id = 7),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 16),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 16),
  [33] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 16), SHIFT_REPEAT(20),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 16), SHIFT_REPEAT(19),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_call, 2, .production_id = 14),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fn_call, 2, .production_id = 14),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 16), SHIFT_REPEAT(42),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2, .production_id = 16), SHIFT_REPEAT(26),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 16),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 16),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 16), SHIFT_REPEAT(23),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 16), SHIFT_REPEAT(19),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_calc, 2, .production_id = 15),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_calc, 2, .production_id = 15),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 16), SHIFT_REPEAT(49),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 2, .production_id = 16), SHIFT_REPEAT(26),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__args, 1, .production_id = 13),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__args, 1, .production_id = 13),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 1),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__callable, 1, .production_id = 5),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__callable, 1, .production_id = 5),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 13),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 13),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 5),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_calc_repeat1, 1, .production_id = 5),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 1, .production_id = 8),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 1, .production_id = 8),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2), SHIFT_REPEAT(56),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 12),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 11),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 10),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_def, 3, .production_id = 9),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 8),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 6),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_in_expr, 4, .production_id = 17),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_in_expr, 5, .production_id = 18),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expr, 2, .production_id = 1),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [132] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(60),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expr, 3, .production_id = 2),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [149] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2), SHIFT_REPEAT(61),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__calc, 1, .production_id = 3),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__calc, 1, .production_id = 4),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [162] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
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
