// TreeSitter grammar for chord notation
// Supports basic chord parsing: C, Dm, G7, etc.
// Also supports chord progressions: C-F-G-C

module.exports = grammar({
  name: 'chord',

  rules: {
    // Entry point: can be a single chord or a chord progression
    source_file: $ => choice(
      $.chord_progression,
      $.chord
    ),

    // Chord progression: one or more chords separated by hyphens
    chord_progression: $ => seq(
      $.chord,
      repeat1(seq('-', $.chord))
    ),

    // A chord consists of: root + optional quality + optional bass
    chord: $ => seq(
      field('root', $.root),
      optional(field('quality', $.quality)),
      optional(field('bass', $.bass))
    ),

    // Root note: C, D, E, F, G, A, B with optional accidental
    root: $ => seq(
      field('note', $.note),
      optional(field('accidental', $.accidental))
    ),

    // Note names
    note: $ => /[A-G]/,

    // Accidentals: sharp (#) or flat (b)
    accidental: $ => choice('#', 'b'),

    // Chord quality: m, maj7, 7, sus4, etc.
    quality: $ => choice(
      'm',
      'maj7',
      'M7',
      '7',
      'dim',
      'aug',
      '+',
      'sus4',
      'sus2',
      // Add more as needed
    ),

    // Bass note: /note for slash chords (e.g., C/E)
    bass: $ => seq(
      '/',
      $.root
    ),
  }
});
