#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 57
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 56
#define ALIAS_COUNT 0
#define TOKEN_COUNT 45
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 12

enum {
  anon_sym_let = 1,
  anon_sym_and = 2,
  anon_sym_EQ = 3,
  anon_sym_true = 4,
  anon_sym_false = 5,
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
  sym_let_expr = 46,
  sym_def = 47,
  sym__exprz = 48,
  sym_boolean = 49,
  sym_fn_call = 50,
  sym_let_in_expr = 51,
  sym_number = 52,
  aux_sym_source_file_repeat1 = 53,
  aux_sym_let_expr_repeat1 = 54,
  aux_sym_fn_call_repeat1 = 55,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_let] = "let",
  [anon_sym_and] = "and",
  [anon_sym_EQ] = "=",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
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
  [sym_let_expr] = "let_expr",
  [sym_def] = "def",
  [sym__exprz] = "_exprz",
  [sym_boolean] = "boolean",
  [sym_fn_call] = "fn_call",
  [sym_let_in_expr] = "let_in_expr",
  [sym_number] = "number",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_let_expr_repeat1] = "let_expr_repeat1",
  [aux_sym_fn_call_repeat1] = "fn_call_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
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
  [sym_let_expr] = sym_let_expr,
  [sym_def] = sym_def,
  [sym__exprz] = sym__exprz,
  [sym_boolean] = sym_boolean,
  [sym_fn_call] = sym_fn_call,
  [sym_let_in_expr] = sym_let_in_expr,
  [sym_number] = sym_number,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_let_expr_repeat1] = aux_sym_let_expr_repeat1,
  [aux_sym_fn_call_repeat1] = aux_sym_fn_call_repeat1,
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
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
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
  [sym_let_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_def] = {
    .visible = true,
    .named = true,
  },
  [sym__exprz] = {
    .visible = false,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_fn_call] = {
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
};

enum {
  field_arg = 1,
  field_boolean = 2,
  field_def = 3,
  field_expr = 4,
  field_fn_call = 5,
  field_function = 6,
  field_ident = 7,
  field_let_in = 8,
  field_number = 9,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_arg] = "arg",
  [field_boolean] = "boolean",
  [field_def] = "def",
  [field_expr] = "expr",
  [field_fn_call] = "fn_call",
  [field_function] = "function",
  [field_ident] = "ident",
  [field_let_in] = "let_in",
  [field_number] = "number",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 7},
  [5] = {.index = 11, .length = 1},
  [6] = {.index = 12, .length = 1},
  [7] = {.index = 13, .length = 1},
  [8] = {.index = 14, .length = 1},
  [9] = {.index = 15, .length = 2},
  [10] = {.index = 17, .length = 7},
  [11] = {.index = 24, .length = 8},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_def, 1},
  [1] =
    {field_def, 1},
    {field_def, 2},
  [3] =
    {field_ident, 0},
  [4] =
    {field_boolean, 2, .inherited = true},
    {field_expr, 2},
    {field_fn_call, 2, .inherited = true},
    {field_ident, 0},
    {field_ident, 2, .inherited = true},
    {field_let_in, 2, .inherited = true},
    {field_number, 2, .inherited = true},
  [11] =
    {field_boolean, 0},
  [12] =
    {field_fn_call, 0},
  [13] =
    {field_let_in, 0},
  [14] =
    {field_number, 0},
  [15] =
    {field_arg, 1},
    {field_function, 0},
  [17] =
    {field_boolean, 3, .inherited = true},
    {field_def, 1},
    {field_expr, 3},
    {field_fn_call, 3, .inherited = true},
    {field_ident, 3, .inherited = true},
    {field_let_in, 3, .inherited = true},
    {field_number, 3, .inherited = true},
  [24] =
    {field_boolean, 4, .inherited = true},
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
  [3] = 3,
  [4] = 3,
  [5] = 5,
  [6] = 2,
  [7] = 2,
  [8] = 5,
  [9] = 3,
  [10] = 5,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 13,
  [15] = 11,
  [16] = 12,
  [17] = 13,
  [18] = 12,
  [19] = 19,
  [20] = 11,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 19,
  [25] = 25,
  [26] = 26,
  [27] = 19,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 33,
  [36] = 36,
  [37] = 37,
  [38] = 34,
  [39] = 19,
  [40] = 33,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 34,
  [45] = 45,
  [46] = 46,
  [47] = 45,
  [48] = 46,
  [49] = 45,
  [50] = 46,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 53,
  [55] = 53,
  [56] = 56,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(61);
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(92);
      if (lookahead == '%') ADVANCE(109);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '\'') ADVANCE(93);
      if (lookahead == '(') ADVANCE(87);
      if (lookahead == ')') ADVANCE(88);
      if (lookahead == '*') ADVANCE(107);
      if (lookahead == '+') ADVANCE(106);
      if (lookahead == ',') ADVANCE(84);
      if (lookahead == '-') ADVANCE(105);
      if (lookahead == '.') ADVANCE(76);
      if (lookahead == '/') ADVANCE(108);
      if (lookahead == ':') ADVANCE(83);
      if (lookahead == '<') ADVANCE(99);
      if (lookahead == '=') ADVANCE(67);
      if (lookahead == '>') ADVANCE(98);
      if (lookahead == '[') ADVANCE(77);
      if (lookahead == '\\') ADVANCE(75);
      if (lookahead == ']') ADVANCE(78);
      if (lookahead == '^') ADVANCE(104);
      if (lookahead == '_') SKIP(56)
      if (lookahead == 'a') ADVANCE(25);
      if (lookahead == 'c') ADVANCE(27);
      if (lookahead == 'e') ADVANCE(22);
      if (lookahead == 'f') ADVANCE(11);
      if (lookahead == 'i') ADVANCE(19);
      if (lookahead == 'l') ADVANCE(14);
      if (lookahead == 'o') ADVANCE(30);
      if (lookahead == 'p') ADVANCE(41);
      if (lookahead == 't') ADVANCE(33);
      if (lookahead == 'v') ADVANCE(10);
      if (lookahead == 'w') ADVANCE(20);
      if (lookahead == '{') ADVANCE(79);
      if (lookahead == '|') ADVANCE(43);
      if (lookahead == '}') ADVANCE(80);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(46)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(47)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(48)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(49)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      END_STATE();
    case 5:
      if (lookahead == '&') ADVANCE(100);
      END_STATE();
    case 6:
      if (lookahead == '.') ADVANCE(52);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '=') ADVANCE(66);
      if (lookahead == '_') SKIP(1)
      if (lookahead == 'f') ADVANCE(110);
      if (lookahead == 'l') ADVANCE(112);
      if (lookahead == 't') ADVANCE(118);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(6)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(52);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '_') SKIP(2)
      if (lookahead == 'a') ADVANCE(116);
      if (lookahead == 'i') ADVANCE(117);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(52);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '_') SKIP(3)
      if (lookahead == 'a') ADVANCE(116);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 9:
      if (lookahead == '_') SKIP(4)
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(32);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(24);
      if (lookahead == 'o') ADVANCE(31);
      END_STATE();
    case 12:
      if (lookahead == 'b') ADVANCE(89);
      END_STATE();
    case 13:
      if (lookahead == 'd') ADVANCE(64);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(82);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(68);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(86);
      END_STATE();
    case 19:
      if (lookahead == 'f') ADVANCE(81);
      if (lookahead == 'm') ADVANCE(29);
      if (lookahead == 'n') ADVANCE(72);
      END_STATE();
    case 20:
      if (lookahead == 'h') ADVANCE(21);
      END_STATE();
    case 21:
      if (lookahead == 'i') ADVANCE(23);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(35);
      END_STATE();
    case 23:
      if (lookahead == 'l') ADVANCE(18);
      END_STATE();
    case 24:
      if (lookahead == 'l') ADVANCE(37);
      END_STATE();
    case 25:
      if (lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 26:
      if (lookahead == 'n') ADVANCE(36);
      END_STATE();
    case 27:
      if (lookahead == 'o') ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 29:
      if (lookahead == 'p') ADVANCE(28);
      END_STATE();
    case 30:
      if (lookahead == 'r') ADVANCE(102);
      END_STATE();
    case 31:
      if (lookahead == 'r') ADVANCE(85);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(90);
      END_STATE();
    case 33:
      if (lookahead == 'r') ADVANCE(42);
      END_STATE();
    case 34:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 35:
      if (lookahead == 's') ADVANCE(15);
      END_STATE();
    case 36:
      if (lookahead == 's') ADVANCE(39);
      END_STATE();
    case 37:
      if (lookahead == 's') ADVANCE(17);
      END_STATE();
    case 38:
      if (lookahead == 't') ADVANCE(62);
      END_STATE();
    case 39:
      if (lookahead == 't') ADVANCE(91);
      END_STATE();
    case 40:
      if (lookahead == 't') ADVANCE(74);
      END_STATE();
    case 41:
      if (lookahead == 'u') ADVANCE(12);
      END_STATE();
    case 42:
      if (lookahead == 'u') ADVANCE(16);
      END_STATE();
    case 43:
      if (lookahead == '|') ADVANCE(101);
      END_STATE();
    case 44:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 45:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(126);
      END_STATE();
    case 46:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (lookahead == '.') ADVANCE(52);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '=') ADVANCE(66);
      if (lookahead == '_') SKIP(1)
      if (lookahead == 'f') ADVANCE(110);
      if (lookahead == 'l') ADVANCE(112);
      if (lookahead == 't') ADVANCE(118);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 47:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(47)
      if (lookahead == '.') ADVANCE(52);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '_') SKIP(2)
      if (lookahead == 'a') ADVANCE(116);
      if (lookahead == 'i') ADVANCE(117);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 48:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(48)
      if (lookahead == '.') ADVANCE(52);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '_') SKIP(3)
      if (lookahead == 'a') ADVANCE(116);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 49:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(49)
      if (lookahead == '_') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 50:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(127);
      END_STATE();
    case 51:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 52:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 53:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(129);
      END_STATE();
    case 54:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 55:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(128);
      END_STATE();
    case 56:
      if (eof) ADVANCE(61);
      if (lookahead == '\n') SKIP(59)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(56)
      END_STATE();
    case 57:
      if (eof) ADVANCE(61);
      if (lookahead == '\n') SKIP(60)
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(57)
      END_STATE();
    case 58:
      if (eof) ADVANCE(61);
      if (lookahead == '.') ADVANCE(52);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '_') SKIP(57)
      if (lookahead == 'a') ADVANCE(116);
      if (lookahead == 'l') ADVANCE(112);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(58)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 59:
      if (eof) ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(59)
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(92);
      if (lookahead == '%') ADVANCE(109);
      if (lookahead == '&') ADVANCE(5);
      if (lookahead == '\'') ADVANCE(93);
      if (lookahead == '(') ADVANCE(87);
      if (lookahead == ')') ADVANCE(88);
      if (lookahead == '*') ADVANCE(107);
      if (lookahead == '+') ADVANCE(106);
      if (lookahead == ',') ADVANCE(84);
      if (lookahead == '-') ADVANCE(105);
      if (lookahead == '.') ADVANCE(76);
      if (lookahead == '/') ADVANCE(108);
      if (lookahead == ':') ADVANCE(83);
      if (lookahead == '<') ADVANCE(99);
      if (lookahead == '=') ADVANCE(67);
      if (lookahead == '>') ADVANCE(98);
      if (lookahead == '[') ADVANCE(77);
      if (lookahead == '\\') ADVANCE(75);
      if (lookahead == ']') ADVANCE(78);
      if (lookahead == '^') ADVANCE(104);
      if (lookahead == '_') SKIP(56)
      if (lookahead == 'a') ADVANCE(25);
      if (lookahead == 'c') ADVANCE(27);
      if (lookahead == 'e') ADVANCE(22);
      if (lookahead == 'f') ADVANCE(11);
      if (lookahead == 'i') ADVANCE(19);
      if (lookahead == 'l') ADVANCE(14);
      if (lookahead == 'o') ADVANCE(30);
      if (lookahead == 'p') ADVANCE(41);
      if (lookahead == 't') ADVANCE(33);
      if (lookahead == 'v') ADVANCE(10);
      if (lookahead == 'w') ADVANCE(20);
      if (lookahead == '{') ADVANCE(79);
      if (lookahead == '|') ADVANCE(43);
      if (lookahead == '}') ADVANCE(80);
      END_STATE();
    case 60:
      if (eof) ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(60)
      if (lookahead == '.') ADVANCE(52);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '_') SKIP(57)
      if (lookahead == 'a') ADVANCE(116);
      if (lookahead == 'l') ADVANCE(112);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_let);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_and);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(94);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_in);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_pub);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_var);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_const);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_eq);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_neq);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_geq);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_leq);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_greater);
      if (lookahead == '=') ADVANCE(96);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_less);
      if (lookahead == '=') ADVANCE(97);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_bang);
      if (lookahead == '=') ADVANCE(95);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_exp);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_minus);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_plus);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_mul);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_div);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_mod);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(122);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym_number_token1);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(132);
      if (lookahead == '0') ADVANCE(129);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(45);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(44);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(50);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(55);
      if (lookahead == '_') ADVANCE(53);
      if (lookahead == 'n') ADVANCE(123);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '.') ADVANCE(132);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(44);
      if (lookahead == '_') ADVANCE(51);
      if (lookahead == 'n') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(45);
      if (lookahead == 'n') ADVANCE(123);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(126);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(50);
      if (lookahead == 'n') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(127);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(55);
      if (lookahead == 'n') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(128);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(53);
      if (lookahead == 'n') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(129);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == '_') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(44);
      if (lookahead == '_') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_number_token1);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 6},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 6},
  [5] = {.lex_state = 6},
  [6] = {.lex_state = 6},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 58},
  [12] = {.lex_state = 58},
  [13] = {.lex_state = 58},
  [14] = {.lex_state = 7},
  [15] = {.lex_state = 7},
  [16] = {.lex_state = 7},
  [17] = {.lex_state = 8},
  [18] = {.lex_state = 8},
  [19] = {.lex_state = 58},
  [20] = {.lex_state = 8},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 7},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 9},
  [34] = {.lex_state = 9},
  [35] = {.lex_state = 9},
  [36] = {.lex_state = 9},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 9},
  [39] = {.lex_state = 8},
  [40] = {.lex_state = 9},
  [41] = {.lex_state = 9},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 9},
  [44] = {.lex_state = 9},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 6},
  [54] = {.lex_state = 6},
  [55] = {.lex_state = 6},
  [56] = {.lex_state = 9},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
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
    [sym_source_file] = STATE(52),
    [sym_let_expr] = STATE(23),
    [aux_sym_source_file_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_let] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      sym_identifier,
    ACTIONS(13), 1,
      aux_sym_number_token1,
    STATE(26), 1,
      sym_number,
    STATE(28), 1,
      sym_let_in_expr,
    STATE(29), 1,
      sym__exprz,
    STATE(30), 1,
      sym_fn_call,
    STATE(32), 1,
      sym_boolean,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
  [29] = 9,
    ACTIONS(13), 1,
      aux_sym_number_token1,
    ACTIONS(15), 1,
      anon_sym_let,
    ACTIONS(17), 1,
      sym_identifier,
    STATE(22), 1,
      sym__exprz,
    STATE(26), 1,
      sym_number,
    STATE(28), 1,
      sym_let_in_expr,
    STATE(30), 1,
      sym_fn_call,
    STATE(32), 1,
      sym_boolean,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
  [58] = 9,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      sym_identifier,
    ACTIONS(13), 1,
      aux_sym_number_token1,
    STATE(22), 1,
      sym__exprz,
    STATE(26), 1,
      sym_number,
    STATE(28), 1,
      sym_let_in_expr,
    STATE(30), 1,
      sym_fn_call,
    STATE(32), 1,
      sym_boolean,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
  [87] = 9,
    ACTIONS(13), 1,
      aux_sym_number_token1,
    ACTIONS(15), 1,
      anon_sym_let,
    ACTIONS(17), 1,
      sym_identifier,
    STATE(26), 1,
      sym_number,
    STATE(28), 1,
      sym_let_in_expr,
    STATE(30), 1,
      sym_fn_call,
    STATE(31), 1,
      sym__exprz,
    STATE(32), 1,
      sym_boolean,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
  [116] = 9,
    ACTIONS(13), 1,
      aux_sym_number_token1,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_identifier,
    STATE(26), 1,
      sym_number,
    STATE(28), 1,
      sym_let_in_expr,
    STATE(29), 1,
      sym__exprz,
    STATE(30), 1,
      sym_fn_call,
    STATE(32), 1,
      sym_boolean,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
  [145] = 9,
    ACTIONS(13), 1,
      aux_sym_number_token1,
    ACTIONS(15), 1,
      anon_sym_let,
    ACTIONS(17), 1,
      sym_identifier,
    STATE(26), 1,
      sym_number,
    STATE(28), 1,
      sym_let_in_expr,
    STATE(29), 1,
      sym__exprz,
    STATE(30), 1,
      sym_fn_call,
    STATE(32), 1,
      sym_boolean,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
  [174] = 9,
    ACTIONS(13), 1,
      aux_sym_number_token1,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_identifier,
    STATE(26), 1,
      sym_number,
    STATE(28), 1,
      sym_let_in_expr,
    STATE(30), 1,
      sym_fn_call,
    STATE(31), 1,
      sym__exprz,
    STATE(32), 1,
      sym_boolean,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
  [203] = 9,
    ACTIONS(13), 1,
      aux_sym_number_token1,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_identifier,
    STATE(22), 1,
      sym__exprz,
    STATE(26), 1,
      sym_number,
    STATE(28), 1,
      sym_let_in_expr,
    STATE(30), 1,
      sym_fn_call,
    STATE(32), 1,
      sym_boolean,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
  [232] = 9,
    ACTIONS(7), 1,
      anon_sym_let,
    ACTIONS(11), 1,
      sym_identifier,
    ACTIONS(13), 1,
      aux_sym_number_token1,
    STATE(26), 1,
      sym_number,
    STATE(28), 1,
      sym_let_in_expr,
    STATE(30), 1,
      sym_fn_call,
    STATE(31), 1,
      sym__exprz,
    STATE(32), 1,
      sym_boolean,
    ACTIONS(9), 2,
      anon_sym_true,
      anon_sym_false,
  [261] = 5,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      aux_sym_number_token1,
    ACTIONS(25), 2,
      anon_sym_let,
      anon_sym_and,
    STATE(12), 2,
      sym_number,
      aux_sym_fn_call_repeat1,
  [279] = 5,
    ACTIONS(29), 1,
      aux_sym_number_token1,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      sym_identifier,
    ACTIONS(33), 2,
      anon_sym_let,
      anon_sym_and,
    STATE(13), 2,
      sym_number,
      aux_sym_fn_call_repeat1,
  [297] = 5,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(41), 1,
      sym_identifier,
    ACTIONS(44), 1,
      aux_sym_number_token1,
    ACTIONS(39), 2,
      anon_sym_let,
      anon_sym_and,
    STATE(13), 2,
      sym_number,
      aux_sym_fn_call_repeat1,
  [315] = 4,
    ACTIONS(47), 1,
      sym_identifier,
    ACTIONS(50), 1,
      aux_sym_number_token1,
    ACTIONS(39), 2,
      anon_sym_and,
      anon_sym_in,
    STATE(14), 2,
      sym_number,
      aux_sym_fn_call_repeat1,
  [330] = 4,
    ACTIONS(53), 1,
      sym_identifier,
    ACTIONS(55), 1,
      aux_sym_number_token1,
    ACTIONS(25), 2,
      anon_sym_and,
      anon_sym_in,
    STATE(16), 2,
      sym_number,
      aux_sym_fn_call_repeat1,
  [345] = 4,
    ACTIONS(55), 1,
      aux_sym_number_token1,
    ACTIONS(57), 1,
      sym_identifier,
    ACTIONS(33), 2,
      anon_sym_and,
      anon_sym_in,
    STATE(14), 2,
      sym_number,
      aux_sym_fn_call_repeat1,
  [360] = 4,
    ACTIONS(39), 1,
      anon_sym_and,
    ACTIONS(59), 1,
      sym_identifier,
    ACTIONS(62), 1,
      aux_sym_number_token1,
    STATE(17), 2,
      sym_number,
      aux_sym_fn_call_repeat1,
  [374] = 4,
    ACTIONS(33), 1,
      anon_sym_and,
    ACTIONS(65), 1,
      sym_identifier,
    ACTIONS(67), 1,
      aux_sym_number_token1,
    STATE(17), 2,
      sym_number,
      aux_sym_fn_call_repeat1,
  [388] = 2,
    ACTIONS(69), 2,
      ts_builtin_sym_end,
      aux_sym_number_token1,
    ACTIONS(71), 3,
      anon_sym_let,
      anon_sym_and,
      sym_identifier,
  [398] = 4,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(67), 1,
      aux_sym_number_token1,
    ACTIONS(73), 1,
      sym_identifier,
    STATE(18), 2,
      sym_number,
      aux_sym_fn_call_repeat1,
  [412] = 1,
    ACTIONS(75), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [419] = 1,
    ACTIONS(77), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [426] = 3,
    ACTIONS(5), 1,
      anon_sym_let,
    ACTIONS(79), 1,
      ts_builtin_sym_end,
    STATE(25), 2,
      sym_let_expr,
      aux_sym_source_file_repeat1,
  [437] = 2,
    ACTIONS(69), 1,
      aux_sym_number_token1,
    ACTIONS(71), 3,
      anon_sym_and,
      anon_sym_in,
      sym_identifier,
  [446] = 3,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(83), 1,
      anon_sym_let,
    STATE(25), 2,
      sym_let_expr,
      aux_sym_source_file_repeat1,
  [457] = 1,
    ACTIONS(86), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [464] = 1,
    ACTIONS(69), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [471] = 1,
    ACTIONS(88), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [478] = 1,
    ACTIONS(90), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [485] = 1,
    ACTIONS(92), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [492] = 1,
    ACTIONS(94), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [499] = 1,
    ACTIONS(96), 4,
      ts_builtin_sym_end,
      anon_sym_let,
      anon_sym_and,
      anon_sym_in,
  [506] = 3,
    ACTIONS(98), 1,
      sym_identifier,
    STATE(34), 1,
      aux_sym_let_expr_repeat1,
    STATE(47), 1,
      sym_def,
  [516] = 3,
    ACTIONS(98), 1,
      sym_identifier,
    STATE(36), 1,
      aux_sym_let_expr_repeat1,
    STATE(48), 1,
      sym_def,
  [526] = 3,
    ACTIONS(98), 1,
      sym_identifier,
    STATE(44), 1,
      aux_sym_let_expr_repeat1,
    STATE(49), 1,
      sym_def,
  [536] = 3,
    ACTIONS(100), 1,
      sym_identifier,
    STATE(36), 1,
      aux_sym_let_expr_repeat1,
    STATE(51), 1,
      sym_def,
  [546] = 2,
    ACTIONS(105), 1,
      anon_sym_and,
    ACTIONS(103), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [554] = 3,
    ACTIONS(98), 1,
      sym_identifier,
    STATE(36), 1,
      aux_sym_let_expr_repeat1,
    STATE(46), 1,
      sym_def,
  [564] = 2,
    ACTIONS(69), 1,
      aux_sym_number_token1,
    ACTIONS(71), 2,
      anon_sym_and,
      sym_identifier,
  [572] = 3,
    ACTIONS(98), 1,
      sym_identifier,
    STATE(38), 1,
      aux_sym_let_expr_repeat1,
    STATE(45), 1,
      sym_def,
  [582] = 3,
    ACTIONS(107), 1,
      sym_identifier,
    STATE(36), 1,
      aux_sym_let_expr_repeat1,
    STATE(37), 1,
      sym_def,
  [592] = 2,
    ACTIONS(105), 1,
      anon_sym_and,
    ACTIONS(109), 2,
      ts_builtin_sym_end,
      anon_sym_let,
  [600] = 3,
    ACTIONS(107), 1,
      sym_identifier,
    STATE(41), 1,
      aux_sym_let_expr_repeat1,
    STATE(42), 1,
      sym_def,
  [610] = 3,
    ACTIONS(98), 1,
      sym_identifier,
    STATE(36), 1,
      aux_sym_let_expr_repeat1,
    STATE(50), 1,
      sym_def,
  [620] = 2,
    ACTIONS(105), 1,
      anon_sym_and,
    ACTIONS(111), 1,
      anon_sym_in,
  [627] = 2,
    ACTIONS(105), 1,
      anon_sym_and,
    ACTIONS(113), 1,
      anon_sym_in,
  [634] = 2,
    ACTIONS(105), 1,
      anon_sym_and,
    ACTIONS(115), 1,
      anon_sym_in,
  [641] = 2,
    ACTIONS(105), 1,
      anon_sym_and,
    ACTIONS(117), 1,
      anon_sym_in,
  [648] = 2,
    ACTIONS(105), 1,
      anon_sym_and,
    ACTIONS(119), 1,
      anon_sym_in,
  [655] = 2,
    ACTIONS(105), 1,
      anon_sym_and,
    ACTIONS(121), 1,
      anon_sym_in,
  [662] = 1,
    ACTIONS(105), 1,
      anon_sym_and,
  [666] = 1,
    ACTIONS(123), 1,
      ts_builtin_sym_end,
  [670] = 1,
    ACTIONS(125), 1,
      anon_sym_EQ,
  [674] = 1,
    ACTIONS(127), 1,
      anon_sym_EQ,
  [678] = 1,
    ACTIONS(129), 1,
      anon_sym_EQ,
  [682] = 1,
    ACTIONS(131), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 29,
  [SMALL_STATE(4)] = 58,
  [SMALL_STATE(5)] = 87,
  [SMALL_STATE(6)] = 116,
  [SMALL_STATE(7)] = 145,
  [SMALL_STATE(8)] = 174,
  [SMALL_STATE(9)] = 203,
  [SMALL_STATE(10)] = 232,
  [SMALL_STATE(11)] = 261,
  [SMALL_STATE(12)] = 279,
  [SMALL_STATE(13)] = 297,
  [SMALL_STATE(14)] = 315,
  [SMALL_STATE(15)] = 330,
  [SMALL_STATE(16)] = 345,
  [SMALL_STATE(17)] = 360,
  [SMALL_STATE(18)] = 374,
  [SMALL_STATE(19)] = 388,
  [SMALL_STATE(20)] = 398,
  [SMALL_STATE(21)] = 412,
  [SMALL_STATE(22)] = 419,
  [SMALL_STATE(23)] = 426,
  [SMALL_STATE(24)] = 437,
  [SMALL_STATE(25)] = 446,
  [SMALL_STATE(26)] = 457,
  [SMALL_STATE(27)] = 464,
  [SMALL_STATE(28)] = 471,
  [SMALL_STATE(29)] = 478,
  [SMALL_STATE(30)] = 485,
  [SMALL_STATE(31)] = 492,
  [SMALL_STATE(32)] = 499,
  [SMALL_STATE(33)] = 506,
  [SMALL_STATE(34)] = 516,
  [SMALL_STATE(35)] = 526,
  [SMALL_STATE(36)] = 536,
  [SMALL_STATE(37)] = 546,
  [SMALL_STATE(38)] = 554,
  [SMALL_STATE(39)] = 564,
  [SMALL_STATE(40)] = 572,
  [SMALL_STATE(41)] = 582,
  [SMALL_STATE(42)] = 592,
  [SMALL_STATE(43)] = 600,
  [SMALL_STATE(44)] = 610,
  [SMALL_STATE(45)] = 620,
  [SMALL_STATE(46)] = 627,
  [SMALL_STATE(47)] = 634,
  [SMALL_STATE(48)] = 641,
  [SMALL_STATE(49)] = 648,
  [SMALL_STATE(50)] = 655,
  [SMALL_STATE(51)] = 662,
  [SMALL_STATE(52)] = 666,
  [SMALL_STATE(53)] = 670,
  [SMALL_STATE(54)] = 674,
  [SMALL_STATE(55)] = 678,
  [SMALL_STATE(56)] = 682,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 3),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__exprz, 1, .production_id = 3),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn_call, 2, .production_id = 9),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fn_call, 2, .production_id = 9),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2), SHIFT_REPEAT(13),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2), SHIFT_REPEAT(19),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2), SHIFT_REPEAT(14),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2), SHIFT_REPEAT(24),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_call_repeat1, 2), SHIFT_REPEAT(17),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_fn_call_repeat1, 2), SHIFT_REPEAT(39),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 1),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_def, 3, .production_id = 4),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(43),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 8),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 7),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_in_expr, 4, .production_id = 10),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 6),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_in_expr, 5, .production_id = 11),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exprz, 1, .production_id = 5),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2), SHIFT_REPEAT(53),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expr, 3, .production_id = 2),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_let_expr, 2, .production_id = 1),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [123] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_let_expr_repeat1, 2),
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
