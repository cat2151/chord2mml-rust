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

// Build a case-insensitive regex source for a literal (JS "..."i);
// spaces stay literal single spaces, matching the PEG grammar.
function ci(str) {
  return str
    .split('')
    .map(c => (/[a-zA-Z]/.test(c) ? `[${c.toLowerCase()}${c.toUpperCase()}]` : c))
    .join('');
}

// A mode directive: case-insensitive words with an optional trailing , or .
function directive(...variants) {
  return token(new RegExp(`(${variants.map(ci).join('|')})[,.]?`));
}

module.exports = grammar({
  name: 'chord',

  extras: $ => [/\s/],

  conflicts: $ => [
    [$.chord],
    [$._lower],
  ],

  rules: {
    // Entry point: events with separators only between events
    // (a trailing "-" must read as the minor quality, not a separator)
    source_file: $ => optional(seq(
      $._event,
      repeat(seq(optional($.separator), $._event))
    )),

    _event: $ => choice(
      $.chord,
      $.mode_chord_over_bass_note,
      $.mode_slash_chord_inversion,
      $.mode_polychord,
      $.mode_root_inv,
      $.mode_1st_inv,
      $.mode_2nd_inv,
      $.mode_3rd_inv,
    ),

    // Slash-chord mode directives (JS SLASH_CHORD_MODE_*)
    mode_chord_over_bass_note: $ => directive('chord over bass note'),
    mode_slash_chord_inversion: $ => directive('slash chord inversion'),
    mode_polychord: $ => directive(
      'upper structure triad', 'upper structure', 'UST', 'US', 'polychord', 'poly'
    ),

    // Inversion mode directives (JS INVERSION_MODE_*)
    mode_root_inv: $ => directive('root inv'),
    mode_1st_inv: $ => directive('1st inv'),
    mode_2nd_inv: $ => directive('2nd inv'),
    mode_3rd_inv: $ => directive('3rd inv'),

    // Progression separators (carry no meaning). Dynamic precedence
    // makes the separator reading win over "-" as the minor quality
    // when both produce a valid parse.
    separator: $ => prec.dynamic(1, choice('-', '→', '・')),

    // A chord: root + optional quality + optional ^N inversion +
    // optional bass (slash chord or on-chord)
    chord: $ => seq(
      field('root', $.root),
      optional(field('quality', $.quality)),
      optional(field('inversion', $.chord_inversion)),
      optional(field('bass', choice($.bass, $.on_bass)))
    ),

    // Per-chord inversion: ^0 (cancel mode) .. ^3 (JS INVERSION)
    chord_inversion: $ => /\^[0-3]/,

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

    // Lower part of a slash chord / on-chord: root, quality, and inversion
    // are all optional and inherit from the upper part (JS SLASH_CHORD /
    // ON_CHORD: lowerRoot? lowerQuality? lowerInversion)
    _lower: $ => seq(
      field('root', $.root),
      optional(field('quality', $.quality)),
      optional(field('inversion', $.chord_inversion))
    ),

    // Slash chord bass: /lower (e.g. C/E, US C/G); resolved by the current
    // slash-chord mode. prec.right binds a following root as the lower part
    // rather than starting a new chord.
    bass: $ => prec.right(seq('/', optional($._lower))),

    // On-chord bass: "on"/"over" + lower (e.g. EonC, CoverC); always
    // chord-over-bass-note regardless of the slash-chord mode
    on_bass: $ => prec.right(seq(choice('on', 'over'), optional($._lower))),
  }
});
