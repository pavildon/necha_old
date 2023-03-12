module.exports = grammar({
  name: 'necha',

  extras: $ => [
    /\s/, /_\s*\n/
  ],

  rules: {
    source_file: $ => seq(
      optional(repeat1($.let_expr))),

    let_expr: $ => seq(
      "let",
      field("def", repeat(seq($.def, "and"))),
      field("def", $.def)),

    def: $ => seq(
      field('ident', $.identifier),
      "=",
      field('expr', $._exprz)),

    _exprz: $ => choice(
      field('number', $.number),
      field('ident', $.identifier),
      field('let_in', $.let_in_expr),
      $.boolean,
      $.fn_call,
    ),

    boolean: $ => choice("true", "false"),

    fn_call: $ => seq(
      $.identifier,
      repeat1(choice($.identifier, $.number))),

    let_in_expr: $ => seq(
      "let",
      field('def', seq(repeat(seq($.def, "and")), $.def)),
      "in",
      field('expr', $._exprz)),

    import_decl: $ => prec.right(99, seq(
      field('visibility', optional($.pub)),
      field('mutability', choice($.var, $.const)),
      field('name', $.identifier),
      '=',
      'import',
      field('file', $.string)
    )),

    declaration: $ => prec.right(100, seq(
      field('visibility', optional($.pub)),
      field('mutability', choice($.var, $.const)),
      field('name', $.identifier),
      '=',
      field('value', $._expr3)
    )),

    assignment: $ => prec.right(100, seq(
      field('name', choice($.array_accessor, $.accessor, $.identifier)),
      '=',
      field('value', $._expr3)
    )),

    function_call: $ => prec.right(1, seq(
      field('id', choice($.identifier, $.array_accessor, $.accessor, $._paren, $.brace_expr)),
      field('arg', repeat1($._expr2)),
    )),

    function_def: $ => prec.right(1, seq(
      '\\',
      optional(field("arg", $._arg_list)),
      '.',
      field("body", $._expr),
    )),

    bracket_expr: $ => seq(
      '[',
      $._comma_list,
      ']'
    ),

    brace_expr: $ => seq(
      '{',
      optional(repeat(seq($._expr, $._eol))),
      optional($._expr),
      '}',
    ),

    boolean_expr: $ => prec(30, choice(
      prec.left(5, seq(field('lhs', $._expr2), field('op', $.geq), field('rhs', $._expr2))),
      prec.left(5, seq(field('lhs', $._expr2), field('op', $.leq), field('rhs', $._expr2))),
      prec.left(5, seq(field('lhs', $._expr2), field('op', $.greater), field('rhs', $._expr2))),
      prec.left(5, seq(field('lhs', $._expr2), field('op', $.less), field('rhs', $._expr2))),
      prec.left(4, seq(field('lhs', $._expr2), field('op', $.eq), field('rhs', $._expr2))),
      prec.left(4, seq(field('lhs', $._expr2), field('op', $.neq), field('rhs', $._expr2))),

      prec.left(3, seq(field('lhs', $._expr2), field('op', $.and), field('rhs', $._expr2))),
      prec.left(3, seq(field('lhs', $._expr2), field('op', $.or), field('rhs', $._expr2)))
    )),

    math_expr: $ => prec(29, choice(
      prec.left(20, seq(field("lhs", $._expr2), field('op', $.exp), field('rhs', $._expr2))),
      prec.left(19, seq(field("lhs", $._expr2), field('op', $.div), field('rhs', $._expr2))),
      prec.left(18, seq(field("lhs", $._expr2), field('op', $.mul), field('rhs', $._expr2))),
      prec.left(17, seq(field("lhs", $._expr2), field('op', $.minus), field('rhs', $._expr2))),
      prec.left(16, seq(field("lhs", $._expr2), field('op', $.plus), field('rhs', $._expr2)))
    )),

    if_expr: $ => seq(
      'if',
      field('condition', choice($.boolean_expr, $._paren)),
      field('true', $._expr),
      'else',
      field('false', $._expr),
    ),

    record_entry: $ => seq(
      field('key', $.identifier), ':', field('value', $._expr3)
    ),

    record_expr: $ => seq(
      '{',
      field('record', $.record_entry),
      optional(
        field('record', repeat(seq(',',
          $.record_entry)))),
      optional(','),
      '}'
    ),

    for_stmt: $ => seq(
      'for',
      field('var', $.identifier),
      'in',
      field('expr', $._expr4),
      field('body', $._expr),
    ),

    while_stmt: $ => seq(
      'while',
      field('condition', $.boolean_expr, $._paren),
      field('body', $._expr),
    ),

    import_stmt: $ => seq(
      'import',
      $.string,
    ),

    void_expr: $ => seq('(', ')'),

    unary_expr: $ => prec.left(10, seq(
      field('op', choice($.bang, $.minus, $.plus)),
      field('expr', choice($.number, $.identifier, $.array_accessor, $.accessor, $.unary_expr, $.brace_expr, $._paren))
    )),

    pub: $ => 'pub',
    var: $ => 'var',
    const: $ => 'const',

    string: $ => choice(
      seq(
        '"',
        repeat(choice(
          alias($.unescaped_double_string_fragment, $.string_fragment),
          $.escape_sequence
        )),
        '"'
      ),
      seq(
        "'",
        repeat(choice(
          alias($.unescaped_single_string_fragment, $.string_fragment),
          $.escape_sequence
        )),
        "'"
      )
    ),
    unescaped_double_string_fragment: $ =>
      token.immediate(prec(1, /[^"\\]+/)),

    // same here
    unescaped_single_string_fragment: $ =>
      token.immediate(prec(1, /[^'\\]+/)),

    escape_sequence: $ => token.immediate(seq(
      '\\',
      choice(
        /[^xu0-7]/,
        /[0-7]{1,3}/,
        /x[0-9a-fA-F]{2}/,
        /u[0-9a-fA-F]{4}/,
        /u{[0-9a-fA-F]+}/
      )
    )),

    _expr: $ => prec(10, choice(
      $.identifier,
      $.array_accessor,
      $.accessor,
      $.function_call,
      $.function_def,
      $.number,
      $.declaration,
      $.assignment,
      $.brace_expr,
      $.bracket_expr,
      $.record_expr,
      $.void_expr,
      $.string,
      $.math_expr,
      $.boolean_expr,
      $._paren,
      $.if_expr,
      $.for_stmt,
      $.while_stmt,
      $.unary_expr,
    )),

    _expr2: $ => prec(8, choice(
      $.identifier,
      $.accessor,
      $.array_accessor,
      $.number,
      $.brace_expr,
      $.bracket_expr,
      $.record_expr,
      $.void_expr,
      $.boolean_expr,
      $.string,
      $.math_expr,
      $.unary_expr,
      $._paren,
    )),

    _expr3: $ => prec(9, choice(
      $.identifier,
      $.accessor,
      $.array_accessor,
      $.number,
      $.brace_expr,
      $.bracket_expr,
      $.record_expr,
      $.boolean_expr,
      $.void_expr,
      $.string,
      $.assignment,
      $.math_expr,
      $.unary_expr,
      $.if_expr,
      $.function_def,
      $.function_call,
      $._paren,
    )),

    _paren: $ => seq(
      '(',
      $._expr3,
      ')'
    ),

    _comma_list: $ => seq(
      $._expr3,
      optional(repeat(seq(',', $._expr3))),
      optional(',')
    ),

    _arg_list: $ => seq(
      $.identifier,
      repeat(seq(',', $.identifier)),
      optional(',')
    ),

    eq: _ => '==',
    neq: _ => '!=',
    geq: _ => '>=',
    leq: _ => '<=',
    greater: _ => '>',
    less: _ => '<',

    and: _ => choice('&&', 'and'),
    or: _ => choice('||', 'or'),

    bang: $ => '!',
    exp: $ => '^',
    minus: $ => '-',
    plus: $ => '+',
    mul: $ => '*',
    div: $ => '/',
    mod: $ => '%',

    _eol: $ => /[\n*;^.]/,

    item_access: $ => seq(field('id', $.identifier), '[', field('index', $.number), ']'),

    _expr4: $ => prec.left(12, choice(
      $.identifier,
      $.accessor,
      $.array_accessor,
      $.brace_expr,
      $.bracket_expr,
      $.record_expr,
      $.string,
      $._paren,
    )),

    accessor: $ => prec.left(
      seq(field('lhs', $._expr4), '.', field('rhs', $._expr4))
    ),

    array_accessor: $ => prec.left(
      seq(field('id', $._expr4),
        '[',
        field(
          'index',
          choice($.number, $._expr4)),
        ']')),

    identifier: $ => /[a-zA-Z][_\w]*/,

    number: $ => {
      const hex_literal = seq(
        choice('0x', '0X'),
        /[\da-fA-F](_?[\da-fA-F])*/
      )

      const decimal_digits = /\d(_?\d)*/
      const signed_integer = seq(optional(choice('-', '+')), decimal_digits)
      const exponent_part = seq(choice('e', 'E'), signed_integer)

      const binary_literal = seq(choice('0b', '0B'), /[0-1](_?[0-1])*/)

      const octal_literal = seq(choice('0o', '0O'), /[0-7](_?[0-7])*/)

      const bigint_literal = seq(
        choice(hex_literal, binary_literal, octal_literal, decimal_digits), 'n')

      const decimal_integer_literal = choice(
        '0',
        seq(optional('0'), /[1-9]/, optional(seq(optional('_'), decimal_digits)))
      )

      const decimal_literal = choice(
        seq(
          decimal_integer_literal,
          '.',
          optional(decimal_digits),
          optional(exponent_part)
        ),
        seq('.', decimal_digits, optional(exponent_part)),
        seq(decimal_integer_literal, exponent_part),
        seq(decimal_digits),
      )

      return prec.right(1, token(choice(
        hex_literal,
        decimal_literal,
        binary_literal,
        octal_literal,
        bigint_literal,
      )))
    },
  }
});
