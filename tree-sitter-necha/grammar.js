module.exports = grammar({
  name: 'necha',

  extras: $ => [
    /\s/, /_\s*\n/ 
  ],

  rules: {
    source_file: $ => seq(
      optional(repeat(seq($._expr, $._eol))),
      optional($._expr)
    ),

    assignment: $ => seq(
      optional(choice(
        optional(seq($.pub, optional($.mutable))),
        optional($.mutable)
      )),
      field('name', $.identifier),
      '=',
      field('value', $._expr)
    ),

    function_call: $ => prec.right(1, seq(
      field('id', choice($.identifier, $._paren, $.brace_expr)),
      field('arg', repeat1($._expr2)),
    )),

    function_def: $ => prec.right(1, seq(
      '\\',
      optional(field("args", $._arg_list)),
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
      prec.left(5, seq(field('lhs', $._expr2),field('op',$.eq),field('rhs', $._expr2))),
      prec.left(5, seq(field('lhs', $._expr2),field('op',$.neq),field('rhs', $._expr2))),
      prec.left(5, seq(field('lhs', $._expr2),field('op',$.geq),field('rhs', $._expr2))),
      prec.left(5, seq(field('lhs', $._expr2),field('op',$.leq),field('rhs', $._expr2))),
      prec.left(5, seq(field('lhs', $._expr2),field('op',$.greater),field('rhs', $._expr2))),
      prec.left(5, seq(field('lhs', $._expr2),field('op',$.less),field('rhs', $._expr2))),

      prec.left(4, seq(field('lhs', $._expr2),field('op',$.and),field('rhs', $._expr2))),
      prec.left(4, seq(field('lhs', $._expr2),field('op',$.or),field('rhs', $._expr2)))
    )),

    math_expr: $ => prec(29, choice(
      prec.left(20, seq(field("lhs", $._expr2),field('op',$.exp),field('rhs', $._expr2))),
      prec.left(19, seq(field("lhs", $._expr2),field('op',$.div),field('rhs', $._expr2))),
      prec.left(18, seq(field("lhs", $._expr2),field('op',$.mul),field('rhs', $._expr2))),
      prec.left(17, seq(field("lhs", $._expr2),field('op',$.minus),field('rhs', $._expr2))),
      prec.left(16, seq(field("lhs", $._expr2),field('op',$.plus),field('rhs', $._expr2)))
    )),

    if_expr: $ => seq(
      'if',
      choice($.boolean_expr, $._paren),
      $._expr,
      'else',
      $._expr,
    ),

    unary_expr: $ => seq(
      choice($.bang, $.minus, $.plus),
      choice($.number, $.identifier, $.unary_expr, $.brace_expr, $._paren)
    ),

    pub: $ => 'pub',
    mutable: $ => 'mutable',

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
      $.function_call,
      $.function_def,
      $.number,
      $.assignment,
      $.brace_expr,
      $.bracket_expr,
      $.string,
      $.math_expr,
      $.boolean_expr,
      $._paren,
      $.if_expr,
      $.unary_expr,
    )),

    _expr2: $ => prec(9, choice(
      $.identifier,
      $.number,
      $.brace_expr,
      $.bracket_expr,
      $.boolean_expr,
      $.string,
      $.math_expr,
      $.unary_expr,
      $._paren,
    )),

    _paren: $ => seq(
      '(',
      $._expr,
      ')'
    ),

    _comma_list: $ => seq(
      $._expr,
      optional(repeat(seq(',', $._expr))),
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
