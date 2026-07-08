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

// Build the regex source for a GM instrument alias: case-insensitive,
// '~' marks an optional whitespace gap (PEG `_`), other specials escaped.
function inst(name) {
  return name
    .split('')
    .map(c => {
      if (/[a-zA-Z]/.test(c)) return `[${c.toLowerCase()}${c.toUpperCase()}]`;
      if (c === '~') return '[ \\t\\n\\r]*';
      return c.replace(/[.*+?^${}()|[\]\\/-]/g, '\\$&');
    })
    .join('');
}

// GM instrument name aliases (JS PC000-PC127). The alias → program number
// mapping lives in chord2mml-core/src/cst_to_ast.rs (GM_PROGRAM_ALIASES,
// checked in PC order like the JS ordered choice — e.g. "Choir" is @52,
// not Pad 4); keep both lists in sync.
const GM_INSTRUMENT_ALIASES = [
  'piano~1', 'acoustic grand piano', 'grand piano', 'pf',
  'piano~2', 'bright acoustic piano',
  'piano~3', 'electric grand piano',
  'honky-tonk piano', 'honky-tonk',
  'e.piano~1', 'electric piano 1', 'rhodes', 'wurlitzer',
  'e.piano~2', 'electric piano 2', 'fm piano',
  'harpsichord',
  'clav.', 'clavinet',
  'celesta',
  'glockenspl', 'glockenspiel',
  'music box',
  'vibraphone',
  'marimba',
  'xylophone',
  'tubularbell', 'tubular bells',
  'santur', 'dulcimer',
  'organ~1', 'drawbar organ',
  'organ~2', 'percussive organ',
  'organ~3', 'rock organ',
  'church org~1', 'church org~2', 'church org~3', 'church organ',
  'reed organ',
  'accordion~f', 'accordion~l', 'accordion',
  'harmonica',
  'bandoneon',
  'nylon gt.', 'acoustic guitar (nylon)',
  'steel gt.', 'acoustic guitar (steel)',
  'jazz gt.', 'electric guitar (jazz)',
  'clean gt.', 'electric guitar (clean)',
  'muted gt.', 'electric guitar (muted)',
  'overdrive~gt', 'electric guitar (overdrive)',
  'dist.gt.', 'dist.gt', 'distortiongt.', 'distortiongt', 'electric guitar (distortion)',
  'gt.harmonix', 'gt.harmonics', 'electric guitar (harmonics)',
  'acoustic bass',
  'electric bass (finger)', 'electric bass (picked)', 'electric bass (fretless)',
  'slap bass 1', 'slap bass 2', 'synth bass 1', 'synth bass 2',
  'violin', 'viola', 'cello', 'contrabass',
  'tremolo strings', 'pizzicato strings', 'orchestral harp', 'timpani',
  'strings~ensemble~1', 'strings~1', 'str.~1',
  'strings~ensemble~2', 'strings~2', 'str.~2',
  'synth strings 1', 'synth strings 2',
  'voice aahs', 'choir aahs', 'choir', 'chor.',
  'voice oohs', 'synth voice', 'orchestra hit',
  'trumpet', 'trombone', 'tuba', 'muted trumpet', 'french horn',
  'brass section', 'synth brass 1', 'synth brass 2',
  'soprano sax', 'alto sax', 'tenor sax', 'baritone sax',
  'oboe', 'english horn', 'bassoon', 'clarinet',
  'piccolo', 'flute', 'recorder', 'pan flute', 'blown bottle',
  'shakuhachi', 'whistle', 'ocarina',
  'lead~1', 'square', 'lead~2', 'sawtooth', 'lead~3', 'calliope',
  'lead~4', 'chiff', 'lead~5', 'charang', 'lead~6', 'voice',
  'lead~7', 'fifths', 'lead~8', 'bass and lead',
  'pad~1', 'new age', 'pad~2', 'warm', 'pad~3', 'polysynth',
  'pad~4', 'pad~5', 'bowed glass', 'pad~6', 'metallic',
  'pad~7', 'halo', 'pad~8', 'sweep',
  'fx~1', 'rain', 'fx~2', 'soundtrack', 'fx~3', 'crystal',
  'fx~4', 'atmosphere', 'fx~5', 'brightness', 'fx~6', 'goblins',
  'fx~7', 'echoes', 'fx~8', 'sci-fi',
  'sitar', 'banjo', 'shamisen', 'koto', 'kalimba', 'bag pipe',
  'fiddle', 'shanai', 'tinkle bell', 'agogo', 'steel drums',
  'woodblock', 'taiko', 'melodic tom', 'synth drum', 'reverse cymbal',
  'guitar fret noise', 'breath noise', 'seashore', 'bird tweet',
  'telephone ring', 'helicopter', 'applause', 'gunshot',
];

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
      $.mode_close,
      $.mode_drop2,
      $.mode_drop4,
      $.mode_drop2and4,
      $.mode_no_bass,
      $.mode_bass_is_root,
      $.octave_up,
      $.octave_up_upper,
      $.octave_up_lower,
      $.octave_down,
      $.octave_down_upper,
      $.octave_down_lower,
      $.bar,
      $.bar_slash,
      $.key,
      $.scale,
      $.inline_abc,
      $.inline_mml,
      $.tempo,
      $.midi_pc,
    ),

    // Inline ABC (JS INLINE_ABC: "/*/*" ... "*/*/"); listed before
    // inline_mml but the token DFA's longest match decides anyway
    inline_abc: $ => token(/\/\*\/\*([^*/]|\*[^/]|\/)+\*\/\*\//),

    // Inline MML passthrough (JS INLINE_MML: "/*" ... "*/")
    inline_mml: $ => token(/\/\*([^*/]|\*[^/]|\/)+\*\//),

    // Tempo (JS TEMPO: ("BPM"i / "TEMPO"i) _ [0-9]+ [,.]?)
    tempo: $ => token(new RegExp(
      `(${ci('bpm')}|${ci('tempo')})[ \\t\\n\\r]*[0-9]+[,.]?`
    )),

    // MIDI program change by GM instrument name (JS PC000-PC127);
    // one token for all aliases, resolved to @NNN in cst_to_ast.rs
    midi_pc: $ => token(new RegExp(
      `(${GM_INSTRUMENT_ALIASES.map(inst).join('|')})[,.]?`
    )),

    // Bar line (JS BAR); note lengths derive from chords per bar
    bar: $ => '|',

    // Half-bar divider (JS BAR_SLASH = "/ ": the slash needs a following
    // space, which distinguishes it from a slash-chord "/")
    bar_slash: $ => token(/\/[ \t]/),

    // Key directive (JS KEY: "key"i [ =:]? [A-G] SHARP* FLAT* ("minor"i/"m")? [,.]?);
    // parsed from the token text in cst_to_ast
    key: $ => token(new RegExp(
      `${ci('key')}[ =:]?[A-G][#＃♯]*[b♭]*(${ci('minor')}|m)?[,.]?`
    )),

    // Scale directive (JS SCALE: the seven church modes, case-insensitive)
    scale: $ => token(new RegExp(
      `(${['ionian', 'dorian', 'phrygian', 'lydian', 'mixolydian', 'aeolian', 'locrian']
        .map(ci).join('|')})[,.]?`
    )),

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

    // Open harmony mode directives (JS OPEN_HARMONY_MODE_*)
    mode_close: $ => directive('close harmony', 'close'),
    mode_drop2: $ => directive('drop2', 'drop-2', 'open triad'),
    mode_drop4: $ => directive('drop4', 'drop-4'),
    mode_drop2and4: $ => directive('drop2and4', 'drop-2-and-4'),

    // Bass play mode directives (JS BASS_PLAY_MODE_*)
    mode_no_bass: $ => directive('no bass'),
    mode_bass_is_root: $ => directive('bass is root', 'bass plays root', 'bass play root'),

    // Octave directives (JS OCTAVE_UP/DOWN with UPPER/LOWER variants:
    // trailing "/" = upper only, leading "/" = lower only)
    octave_up: $ => directive('octave up', 'octave-up'),
    octave_up_upper: $ => token(new RegExp(`(${ci('octave up')}|${ci('octave-up')})/[,.]?`)),
    octave_up_lower: $ => token(new RegExp(`/(${ci('octave up')}|${ci('octave-up')})[,.]?`)),
    octave_down: $ => directive('octave down', 'octave-down'),
    octave_down_upper: $ => token(new RegExp(`(${ci('octave down')}|${ci('octave-down')})/[,.]?`)),
    octave_down_lower: $ => token(new RegExp(`/(${ci('octave down')}|${ci('octave-down')})[,.]?`)),

    // Progression separators (carry no meaning). Dynamic precedence
    // makes the separator reading win over "-" as the minor quality
    // when both produce a valid parse.
    separator: $ => prec.dynamic(1, choice('-', '→', '・')),

    // A chord: root + optional quality + optional ^N inversion +
    // optional octave offset + optional bass (slash chord or on-chord)
    chord: $ => seq(
      field('root', $.root),
      optional(field('quality', $.quality)),
      optional(field('inversion', $.chord_inversion)),
      optional(field('octave', $.octave_offset)),
      optional(field('bass', choice($.bass, $.on_bass)))
    ),

    // Per-chord inversion: ^0 (cancel mode) .. ^3 (JS INVERSION)
    chord_inversion: $ => /\^[0-3]/,

    // Per-chord octave offset: ' up, , down (JS OCTAVE_OFFSET = "'"* ","*)
    octave_offset: $ => /'+,*|,+/,

    // Root: a note letter with accidentals, or a degree with accidentals
    // (JS ROOT = ROOT_CDEFGAB / ROOT_DEGREE). Each is a single token, so
    // accidentals must touch the letter/numeral exactly like the PEG
    // grammar ("C #IV" is C then #IV, "C# IV" is C# then IV). The parts
    // are decomposed from the token text in cst_to_ast.rs.
    root: $ => choice(
      field('note', $.note),
      field('degree', $.degree),
    ),

    // Note name with accidentals: sharps then flats, half- or full-width
    // (JS ROOT_CDEFGAB = [A-G] SHARP* FLAT*)
    note: $ => token(/[A-G][#＃♯]*[b♭]*/),

    // Degree numeral with leading accidentals, key-relative
    // (JS ROOT_DEGREE = SHARP* FLAT* (VII/III/VI/IV/II/V/I/[1-7]);
    // the token DFA picks the longest match, so VI never reads as V + I)
    degree: $ => token(/[#＃♯]*[b♭]*(VII|III|VI|IV|II|V|I|[1-7])/),

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
      optional(field('inversion', $.chord_inversion)),
      optional(field('octave', $.octave_offset))
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
