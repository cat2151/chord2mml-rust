// TreeSitter grammar for chord notation
//
// The input is a sequence of chords separated by whitespace, " - "
// (spaced hyphen), "→", or "・" — matching the original JS chord2mml
// (peggyjs/chord2mml_chord2ast.pegjs). The unspaced hyphen (C-F-G-C)
// is legacy syntax of this Rust port, kept until "-" becomes the minor
// quality per the JS spec.
//
// Semantics (root numbers, quality normalization) live in
// chord2mml-core/src/cst_to_ast.rs — this grammar only names the tokens.

module.exports = grammar({
  name: 'chord',

  extras: $ => [/\s/],

  rules: {
    // Entry point: a sequence of chords and separators
    source_file: $ => repeat(choice($.chord, $.separator)),

    // Progression separators (carry no meaning)
    separator: $ => choice('-', '→', '・'),

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

    // Chord quality tokens (longest match wins in the lexer).
    // Normalization to the JS quality strings happens in cst_to_ast.rs.
    quality: $ => choice(
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
      'min',
      'Min',
      'MIN',
      'm',
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

    // Bass note: /root for slash chords (e.g. C/E)
    bass: $ => seq(
      '/',
      field('root', $.root)
    ),
  }
});
