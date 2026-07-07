// TreeSitter grammar for chord notation
//
// The input is a sequence of chords separated by whitespace, " - "
// (spaced hyphen), "→", or "・" — matching the original JS chord2mml
// (peggyjs/chord2mml_chord2ast.pegjs). The unspaced hyphen (C-F-G-C)
// is additionally supported as first-class syntax of this Rust port
// (user decision 2026-07-08); it coexists with the "-" minor quality:
// "-7" wins by longest match, and a bare "-" prefers the separator
// reading via dynamic precedence when both parses are possible
// (so C-F is [C, F], while C- at the end of input is C minor,
// matching the JS behavior for every input JS accepts).
//
// Semantics (root numbers, quality normalization) live in
// chord2mml-core/src/cst_to_ast.rs — this grammar only names the tokens.

module.exports = grammar({
  name: 'chord',

  extras: $ => [/\s/],

  conflicts: $ => [
    [$.chord],
  ],

  rules: {
    // Entry point: chords with separators only between chords
    // (a trailing "-" must read as the minor quality, not a separator)
    source_file: $ => optional(seq(
      $.chord,
      repeat(seq(optional($.separator), $.chord))
    )),

    // Progression separators (carry no meaning). Dynamic precedence
    // makes the separator reading win over "-" as the minor quality
    // when both produce a valid parse.
    separator: $ => prec.dynamic(1, choice('-', '→', '・')),

    // A chord consists of: root + optional quality + optional bass
    chord: $ => seq(
      field('root', $.root),
      optional(field('quality', $.quality)),
      optional(field('bass', $.bass))
    ),

    // Root note: C, D, E, F, G, A, B with optional accidentals
    root: $ => seq(
      field('note', $.note),
      repeat(field('accidental', $.accidental))
    ),

    // Note names
    note: $ => /[A-G]/,

    // Accidentals: sharp (#, ＃, ♯) or flat (b, ♭); half- and full-width
    accidental: $ => choice('#', '＃', '♯', 'b', '♭'),

    // Chord quality: a base followed by modifiers, or modifiers alone
    // (JS CHORD_QUALITY: base (OMIT_N / ADD_N / FLATTED_FIFTH /
    // AUGMENTED_FIFTH)*; the empty base MAJ_SHORT means "maj").
    // Normalization to the JS quality strings happens in cst_to_ast.rs.
    quality: $ => choice(
      seq(
        field('base', $.quality_base),
        repeat(field('modifier', $.quality_modifier))
      ),
      repeat1(field('modifier', $.quality_modifier)),
    ),

    // Base quality tokens (longest match wins in the lexer)
    quality_base: $ => choice(
      // Quartal harmony (JS: "4." [2-9]+; only the first digit counts)
      /4\.[2-9]+/,
      // maj9 family (JS MAJ9: ("maj"i / "M" / "△") "("? "9" ")"?)
      'maj9', 'Maj9', 'MAJ9', 'M9', '△9',
      'maj(9)', 'Maj(9)', 'MAJ(9)', 'M(9)', '△(9)',
      'maj7',
      'Maj7',
      'MAJ7',
      'M7',
      '△',
      'maj',
      'Maj',
      'MAJ',
      'M',
      'min7',
      'Min7',
      'MIN7',
      'm7',
      '-7',
      'min',
      'Min',
      'MIN',
      'm',
      '-',
      '7sus2',
      '7sus4',
      'sus4',
      'sus2',
      'dim',
      'aug',
      '+',
      '13',
      '11',
      '9',
      '7',
      '6',
      // Add more as needed
    ),

    // Quality modifiers (JS: OMIT_N / ADD_N / FLATTED_FIFTH /
    // AUGMENTED_FIFTH; parens optional for add/omit, required for fifths)
    quality_modifier: $ => choice(
      /\(?add[0-9]+\)?/,
      /\(?(omit|o)[135]\)?/,
      '(b5)',
      '(-5)',
      '(+5)',
      '(#5)',
    ),

    // Bass note: /root for slash chords (e.g. C/E)
    bass: $ => seq(
      '/',
      field('root', $.root)
    ),
  }
});
