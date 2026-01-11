#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 14
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 20
#define ALIAS_COUNT 0
#define TOKEN_COUNT 14
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  sym_note = 1,
  anon_sym_POUND = 2,
  anon_sym_b = 3,
  anon_sym_m = 4,
  anon_sym_maj7 = 5,
  anon_sym_M7 = 6,
  anon_sym_7 = 7,
  anon_sym_dim = 8,
  anon_sym_aug = 9,
  anon_sym_PLUS = 10,
  anon_sym_sus4 = 11,
  anon_sym_sus2 = 12,
  anon_sym_SLASH = 13,
  sym_source_file = 14,
  sym_chord = 15,
  sym_root = 16,
  sym_accidental = 17,
  sym_quality = 18,
  sym_bass = 19,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_note] = "note",
  [anon_sym_POUND] = "#",
  [anon_sym_b] = "b",
  [anon_sym_m] = "m",
  [anon_sym_maj7] = "maj7",
  [anon_sym_M7] = "M7",
  [anon_sym_7] = "7",
  [anon_sym_dim] = "dim",
  [anon_sym_aug] = "aug",
  [anon_sym_PLUS] = "+",
  [anon_sym_sus4] = "sus4",
  [anon_sym_sus2] = "sus2",
  [anon_sym_SLASH] = "/",
  [sym_source_file] = "source_file",
  [sym_chord] = "chord",
  [sym_root] = "root",
  [sym_accidental] = "accidental",
  [sym_quality] = "quality",
  [sym_bass] = "bass",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_note] = sym_note,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_b] = anon_sym_b,
  [anon_sym_m] = anon_sym_m,
  [anon_sym_maj7] = anon_sym_maj7,
  [anon_sym_M7] = anon_sym_M7,
  [anon_sym_7] = anon_sym_7,
  [anon_sym_dim] = anon_sym_dim,
  [anon_sym_aug] = anon_sym_aug,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_sus4] = anon_sym_sus4,
  [anon_sym_sus2] = anon_sym_sus2,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [sym_source_file] = sym_source_file,
  [sym_chord] = sym_chord,
  [sym_root] = sym_root,
  [sym_accidental] = sym_accidental,
  [sym_quality] = sym_quality,
  [sym_bass] = sym_bass,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_note] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_b] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_m] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_maj7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_M7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_dim] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_aug] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sus4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sus2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_chord] = {
    .visible = true,
    .named = true,
  },
  [sym_root] = {
    .visible = true,
    .named = true,
  },
  [sym_accidental] = {
    .visible = true,
    .named = true,
  },
  [sym_quality] = {
    .visible = true,
    .named = true,
  },
  [sym_bass] = {
    .visible = true,
    .named = true,
  },
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
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(11);
      if (lookahead == '#') ADVANCE(13);
      if (lookahead == '+') ADVANCE(21);
      if (lookahead == '/') ADVANCE(24);
      if (lookahead == '7') ADVANCE(18);
      if (lookahead == 'M') ADVANCE(2);
      if (lookahead == 'a') ADVANCE(9);
      if (lookahead == 'b') ADVANCE(14);
      if (lookahead == 'd') ADVANCE(5);
      if (lookahead == 'm') ADVANCE(15);
      if (lookahead == 's') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'G')) ADVANCE(12);
      END_STATE();
    case 1:
      if (lookahead == '2') ADVANCE(23);
      if (lookahead == '4') ADVANCE(22);
      END_STATE();
    case 2:
      if (lookahead == '7') ADVANCE(17);
      END_STATE();
    case 3:
      if (lookahead == '7') ADVANCE(16);
      END_STATE();
    case 4:
      if (lookahead == 'g') ADVANCE(20);
      END_STATE();
    case 5:
      if (lookahead == 'i') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == 'j') ADVANCE(3);
      END_STATE();
    case 7:
      if (lookahead == 'm') ADVANCE(19);
      END_STATE();
    case 8:
      if (lookahead == 's') ADVANCE(1);
      END_STATE();
    case 9:
      if (lookahead == 'u') ADVANCE(4);
      END_STATE();
    case 10:
      if (lookahead == 'u') ADVANCE(8);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_note);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_b);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_m);
      if (lookahead == 'a') ADVANCE(6);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_maj7);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_M7);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_7);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_dim);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_aug);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_sus4);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_sus2);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_note] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_b] = ACTIONS(1),
    [anon_sym_m] = ACTIONS(1),
    [anon_sym_maj7] = ACTIONS(1),
    [anon_sym_M7] = ACTIONS(1),
    [anon_sym_7] = ACTIONS(1),
    [anon_sym_dim] = ACTIONS(1),
    [anon_sym_aug] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_sus4] = ACTIONS(1),
    [anon_sym_sus2] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(9),
    [sym_chord] = STATE(10),
    [sym_root] = STATE(3),
    [sym_note] = ACTIONS(3),
  },
  [2] = {
    [sym_accidental] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_POUND] = ACTIONS(7),
    [anon_sym_b] = ACTIONS(7),
    [anon_sym_m] = ACTIONS(9),
    [anon_sym_maj7] = ACTIONS(5),
    [anon_sym_M7] = ACTIONS(5),
    [anon_sym_7] = ACTIONS(5),
    [anon_sym_dim] = ACTIONS(5),
    [anon_sym_aug] = ACTIONS(5),
    [anon_sym_PLUS] = ACTIONS(5),
    [anon_sym_sus4] = ACTIONS(5),
    [anon_sym_sus2] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(5),
  },
  [3] = {
    [sym_quality] = STATE(6),
    [sym_bass] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(11),
    [anon_sym_m] = ACTIONS(13),
    [anon_sym_maj7] = ACTIONS(15),
    [anon_sym_M7] = ACTIONS(15),
    [anon_sym_7] = ACTIONS(15),
    [anon_sym_dim] = ACTIONS(15),
    [anon_sym_aug] = ACTIONS(15),
    [anon_sym_PLUS] = ACTIONS(15),
    [anon_sym_sus4] = ACTIONS(15),
    [anon_sym_sus2] = ACTIONS(15),
    [anon_sym_SLASH] = ACTIONS(17),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(19),
    [anon_sym_m] = ACTIONS(21),
    [anon_sym_maj7] = ACTIONS(19),
    [anon_sym_M7] = ACTIONS(19),
    [anon_sym_7] = ACTIONS(19),
    [anon_sym_dim] = ACTIONS(19),
    [anon_sym_aug] = ACTIONS(19),
    [anon_sym_PLUS] = ACTIONS(19),
    [anon_sym_sus4] = ACTIONS(19),
    [anon_sym_sus2] = ACTIONS(19),
    [anon_sym_SLASH] = ACTIONS(19),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(23),
    [anon_sym_m] = ACTIONS(25),
    [anon_sym_maj7] = ACTIONS(23),
    [anon_sym_M7] = ACTIONS(23),
    [anon_sym_7] = ACTIONS(23),
    [anon_sym_dim] = ACTIONS(23),
    [anon_sym_aug] = ACTIONS(23),
    [anon_sym_PLUS] = ACTIONS(23),
    [anon_sym_sus4] = ACTIONS(23),
    [anon_sym_sus2] = ACTIONS(23),
    [anon_sym_SLASH] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(17), 1,
      anon_sym_SLASH,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    STATE(13), 1,
      sym_bass,
  [10] = 1,
    ACTIONS(29), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH,
  [15] = 2,
    ACTIONS(3), 1,
      sym_note,
    STATE(12), 1,
      sym_root,
  [22] = 1,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
  [26] = 1,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
  [30] = 1,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
  [34] = 1,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
  [38] = 1,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 10,
  [SMALL_STATE(8)] = 15,
  [SMALL_STATE(9)] = 22,
  [SMALL_STATE(10)] = 26,
  [SMALL_STATE(11)] = 30,
  [SMALL_STATE(12)] = 34,
  [SMALL_STATE(13)] = 38,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accidental, 1),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accidental, 1),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 2),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 2),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1),
  [31] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 2),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_chord(void) {
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
