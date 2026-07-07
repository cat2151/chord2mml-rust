#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 27
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 70
#define ALIAS_COUNT 0
#define TOKEN_COUNT 58
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 15

enum {
  anon_sym_DASH = 1,
  anon_sym_ = 2,
  anon_sym_2 = 3,
  sym_note = 4,
  anon_sym_POUND = 5,
  anon_sym_3 = 6,
  anon_sym_4 = 7,
  anon_sym_b = 8,
  anon_sym_5 = 9,
  aux_sym_quality_base_token1 = 10,
  anon_sym_maj9 = 11,
  anon_sym_Maj9 = 12,
  anon_sym_MAJ9 = 13,
  anon_sym_M9 = 14,
  anon_sym_9 = 15,
  anon_sym_maj_LPAREN9_RPAREN = 16,
  anon_sym_Maj_LPAREN9_RPAREN = 17,
  anon_sym_MAJ_LPAREN9_RPAREN = 18,
  anon_sym_M_LPAREN9_RPAREN = 19,
  anon_sym_LPAREN9_RPAREN = 20,
  anon_sym_maj7 = 21,
  anon_sym_Maj7 = 22,
  anon_sym_MAJ7 = 23,
  anon_sym_M7 = 24,
  anon_sym_6 = 25,
  anon_sym_maj = 26,
  anon_sym_Maj = 27,
  anon_sym_MAJ = 28,
  anon_sym_M = 29,
  anon_sym_min7 = 30,
  anon_sym_Min7 = 31,
  anon_sym_MIN7 = 32,
  anon_sym_m7 = 33,
  anon_sym_DASH7 = 34,
  anon_sym_min = 35,
  anon_sym_Min = 36,
  anon_sym_MIN = 37,
  anon_sym_m = 38,
  anon_sym_7sus2 = 39,
  anon_sym_7sus4 = 40,
  anon_sym_sus4 = 41,
  anon_sym_sus2 = 42,
  anon_sym_dim = 43,
  anon_sym_aug = 44,
  anon_sym_PLUS = 45,
  anon_sym_13 = 46,
  anon_sym_11 = 47,
  anon_sym_92 = 48,
  anon_sym_7 = 49,
  anon_sym_62 = 50,
  aux_sym_quality_modifier_token1 = 51,
  aux_sym_quality_modifier_token2 = 52,
  anon_sym_LPARENb5_RPAREN = 53,
  anon_sym_LPAREN_DASH5_RPAREN = 54,
  anon_sym_LPAREN_PLUS5_RPAREN = 55,
  anon_sym_LPAREN_POUND5_RPAREN = 56,
  anon_sym_SLASH = 57,
  sym_source_file = 58,
  sym_separator = 59,
  sym_chord = 60,
  sym_root = 61,
  sym_accidental = 62,
  sym_quality = 63,
  sym_quality_base = 64,
  sym_quality_modifier = 65,
  sym_bass = 66,
  aux_sym_source_file_repeat1 = 67,
  aux_sym_root_repeat1 = 68,
  aux_sym_quality_repeat1 = 69,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_DASH] = "-",
  [anon_sym_] = "→",
  [anon_sym_2] = "・",
  [sym_note] = "note",
  [anon_sym_POUND] = "#",
  [anon_sym_3] = "＃",
  [anon_sym_4] = "♯",
  [anon_sym_b] = "b",
  [anon_sym_5] = "♭",
  [aux_sym_quality_base_token1] = "quality_base_token1",
  [anon_sym_maj9] = "maj9",
  [anon_sym_Maj9] = "Maj9",
  [anon_sym_MAJ9] = "MAJ9",
  [anon_sym_M9] = "M9",
  [anon_sym_9] = "△9",
  [anon_sym_maj_LPAREN9_RPAREN] = "maj(9)",
  [anon_sym_Maj_LPAREN9_RPAREN] = "Maj(9)",
  [anon_sym_MAJ_LPAREN9_RPAREN] = "MAJ(9)",
  [anon_sym_M_LPAREN9_RPAREN] = "M(9)",
  [anon_sym_LPAREN9_RPAREN] = "△(9)",
  [anon_sym_maj7] = "maj7",
  [anon_sym_Maj7] = "Maj7",
  [anon_sym_MAJ7] = "MAJ7",
  [anon_sym_M7] = "M7",
  [anon_sym_6] = "△",
  [anon_sym_maj] = "maj",
  [anon_sym_Maj] = "Maj",
  [anon_sym_MAJ] = "MAJ",
  [anon_sym_M] = "M",
  [anon_sym_min7] = "min7",
  [anon_sym_Min7] = "Min7",
  [anon_sym_MIN7] = "MIN7",
  [anon_sym_m7] = "m7",
  [anon_sym_DASH7] = "-7",
  [anon_sym_min] = "min",
  [anon_sym_Min] = "Min",
  [anon_sym_MIN] = "MIN",
  [anon_sym_m] = "m",
  [anon_sym_7sus2] = "7sus2",
  [anon_sym_7sus4] = "7sus4",
  [anon_sym_sus4] = "sus4",
  [anon_sym_sus2] = "sus2",
  [anon_sym_dim] = "dim",
  [anon_sym_aug] = "aug",
  [anon_sym_PLUS] = "+",
  [anon_sym_13] = "13",
  [anon_sym_11] = "11",
  [anon_sym_92] = "9",
  [anon_sym_7] = "7",
  [anon_sym_62] = "6",
  [aux_sym_quality_modifier_token1] = "quality_modifier_token1",
  [aux_sym_quality_modifier_token2] = "quality_modifier_token2",
  [anon_sym_LPARENb5_RPAREN] = "(b5)",
  [anon_sym_LPAREN_DASH5_RPAREN] = "(-5)",
  [anon_sym_LPAREN_PLUS5_RPAREN] = "(+5)",
  [anon_sym_LPAREN_POUND5_RPAREN] = "(#5)",
  [anon_sym_SLASH] = "/",
  [sym_source_file] = "source_file",
  [sym_separator] = "separator",
  [sym_chord] = "chord",
  [sym_root] = "root",
  [sym_accidental] = "accidental",
  [sym_quality] = "quality",
  [sym_quality_base] = "quality_base",
  [sym_quality_modifier] = "quality_modifier",
  [sym_bass] = "bass",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_root_repeat1] = "root_repeat1",
  [aux_sym_quality_repeat1] = "quality_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_] = anon_sym_,
  [anon_sym_2] = anon_sym_2,
  [sym_note] = sym_note,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_3] = anon_sym_3,
  [anon_sym_4] = anon_sym_4,
  [anon_sym_b] = anon_sym_b,
  [anon_sym_5] = anon_sym_5,
  [aux_sym_quality_base_token1] = aux_sym_quality_base_token1,
  [anon_sym_maj9] = anon_sym_maj9,
  [anon_sym_Maj9] = anon_sym_Maj9,
  [anon_sym_MAJ9] = anon_sym_MAJ9,
  [anon_sym_M9] = anon_sym_M9,
  [anon_sym_9] = anon_sym_9,
  [anon_sym_maj_LPAREN9_RPAREN] = anon_sym_maj_LPAREN9_RPAREN,
  [anon_sym_Maj_LPAREN9_RPAREN] = anon_sym_Maj_LPAREN9_RPAREN,
  [anon_sym_MAJ_LPAREN9_RPAREN] = anon_sym_MAJ_LPAREN9_RPAREN,
  [anon_sym_M_LPAREN9_RPAREN] = anon_sym_M_LPAREN9_RPAREN,
  [anon_sym_LPAREN9_RPAREN] = anon_sym_LPAREN9_RPAREN,
  [anon_sym_maj7] = anon_sym_maj7,
  [anon_sym_Maj7] = anon_sym_Maj7,
  [anon_sym_MAJ7] = anon_sym_MAJ7,
  [anon_sym_M7] = anon_sym_M7,
  [anon_sym_6] = anon_sym_6,
  [anon_sym_maj] = anon_sym_maj,
  [anon_sym_Maj] = anon_sym_Maj,
  [anon_sym_MAJ] = anon_sym_MAJ,
  [anon_sym_M] = anon_sym_M,
  [anon_sym_min7] = anon_sym_min7,
  [anon_sym_Min7] = anon_sym_Min7,
  [anon_sym_MIN7] = anon_sym_MIN7,
  [anon_sym_m7] = anon_sym_m7,
  [anon_sym_DASH7] = anon_sym_DASH7,
  [anon_sym_min] = anon_sym_min,
  [anon_sym_Min] = anon_sym_Min,
  [anon_sym_MIN] = anon_sym_MIN,
  [anon_sym_m] = anon_sym_m,
  [anon_sym_7sus2] = anon_sym_7sus2,
  [anon_sym_7sus4] = anon_sym_7sus4,
  [anon_sym_sus4] = anon_sym_sus4,
  [anon_sym_sus2] = anon_sym_sus2,
  [anon_sym_dim] = anon_sym_dim,
  [anon_sym_aug] = anon_sym_aug,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_13] = anon_sym_13,
  [anon_sym_11] = anon_sym_11,
  [anon_sym_92] = anon_sym_92,
  [anon_sym_7] = anon_sym_7,
  [anon_sym_62] = anon_sym_62,
  [aux_sym_quality_modifier_token1] = aux_sym_quality_modifier_token1,
  [aux_sym_quality_modifier_token2] = aux_sym_quality_modifier_token2,
  [anon_sym_LPARENb5_RPAREN] = anon_sym_LPARENb5_RPAREN,
  [anon_sym_LPAREN_DASH5_RPAREN] = anon_sym_LPAREN_DASH5_RPAREN,
  [anon_sym_LPAREN_PLUS5_RPAREN] = anon_sym_LPAREN_PLUS5_RPAREN,
  [anon_sym_LPAREN_POUND5_RPAREN] = anon_sym_LPAREN_POUND5_RPAREN,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [sym_source_file] = sym_source_file,
  [sym_separator] = sym_separator,
  [sym_chord] = sym_chord,
  [sym_root] = sym_root,
  [sym_accidental] = sym_accidental,
  [sym_quality] = sym_quality,
  [sym_quality_base] = sym_quality_base,
  [sym_quality_modifier] = sym_quality_modifier,
  [sym_bass] = sym_bass,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_root_repeat1] = aux_sym_root_repeat1,
  [aux_sym_quality_repeat1] = aux_sym_quality_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_2] = {
    .visible = true,
    .named = false,
  },
  [sym_note] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_3] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_b] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_5] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quality_base_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_maj9] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Maj9] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MAJ9] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_M9] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_9] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_maj_LPAREN9_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Maj_LPAREN9_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MAJ_LPAREN9_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_M_LPAREN9_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN9_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_maj7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Maj7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MAJ7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_M7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_6] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_maj] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Maj] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MAJ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_M] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_min7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Min7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MIN7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_m7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_min] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Min] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_MIN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_m] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_7sus2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_7sus4] = {
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
  [anon_sym_13] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_11] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_92] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_62] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quality_modifier_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quality_modifier_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LPARENb5_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN_DASH5_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN_PLUS5_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN_POUND5_RPAREN] = {
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
  [sym_separator] = {
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
  [sym_quality_base] = {
    .visible = true,
    .named = true,
  },
  [sym_quality_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym_bass] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_root_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quality_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_accidental = 1,
  field_base = 2,
  field_bass = 3,
  field_modifier = 4,
  field_note = 5,
  field_quality = 6,
  field_root = 7,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_accidental] = "accidental",
  [field_base] = "base",
  [field_bass] = "bass",
  [field_modifier] = "modifier",
  [field_note] = "note",
  [field_quality] = "quality",
  [field_root] = "root",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 2},
  [6] = {.index = 7, .length = 1},
  [7] = {.index = 8, .length = 1},
  [8] = {.index = 9, .length = 2},
  [9] = {.index = 11, .length = 1},
  [10] = {.index = 12, .length = 2},
  [11] = {.index = 14, .length = 1},
  [12] = {.index = 15, .length = 3},
  [13] = {.index = 18, .length = 2},
  [14] = {.index = 20, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_note, 0},
  [1] =
    {field_root, 0},
  [2] =
    {field_accidental, 0},
  [3] =
    {field_accidental, 1, .inherited = true},
    {field_note, 0},
  [5] =
    {field_quality, 1},
    {field_root, 0},
  [7] =
    {field_base, 0},
  [8] =
    {field_modifier, 0},
  [9] =
    {field_bass, 1},
    {field_root, 0},
  [11] =
    {field_modifier, 0, .inherited = true},
  [12] =
    {field_accidental, 0, .inherited = true},
    {field_accidental, 1, .inherited = true},
  [14] =
    {field_root, 1},
  [15] =
    {field_bass, 2},
    {field_quality, 1},
    {field_root, 0},
  [18] =
    {field_base, 0},
    {field_modifier, 1, .inherited = true},
  [20] =
    {field_modifier, 0, .inherited = true},
    {field_modifier, 1, .inherited = true},
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
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(46);
      if (lookahead == '#') ADVANCE(51);
      if (lookahead == '(') ADVANCE(1);
      if (lookahead == '+') ADVANCE(91);
      if (lookahead == '-') ADVANCE(47);
      if (lookahead == '/') ADVANCE(105);
      if (lookahead == '1') ADVANCE(12);
      if (lookahead == '4') ADVANCE(11);
      if (lookahead == '6') ADVANCE(96);
      if (lookahead == '7') ADVANCE(95);
      if (lookahead == '9') ADVANCE(94);
      if (lookahead == 'M') ADVANCE(75);
      if (lookahead == 'a') ADVANCE(28);
      if (lookahead == 'b') ADVANCE(54);
      if (lookahead == 'd') ADVANCE(30);
      if (lookahead == 'm') ADVANCE(84);
      if (lookahead == 'o') ADVANCE(35);
      if (lookahead == 's') ADVANCE(41);
      if (lookahead == 8594) ADVANCE(48);
      if (lookahead == 9651) ADVANCE(71);
      if (lookahead == 9837) ADVANCE(55);
      if (lookahead == 9839) ADVANCE(53);
      if (lookahead == 12539) ADVANCE(49);
      if (lookahead == 65283) ADVANCE(52);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'G')) ADVANCE(50);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(15);
      if (lookahead == '+') ADVANCE(16);
      if (lookahead == '-') ADVANCE(17);
      if (lookahead == 'a') ADVANCE(27);
      if (lookahead == 'b') ADVANCE(18);
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 2:
      if (lookahead == ')') ADVANCE(104);
      END_STATE();
    case 3:
      if (lookahead == ')') ADVANCE(103);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(102);
      END_STATE();
    case 5:
      if (lookahead == ')') ADVANCE(101);
      END_STATE();
    case 6:
      if (lookahead == ')') ADVANCE(65);
      END_STATE();
    case 7:
      if (lookahead == ')') ADVANCE(66);
      END_STATE();
    case 8:
      if (lookahead == ')') ADVANCE(64);
      END_STATE();
    case 9:
      if (lookahead == ')') ADVANCE(63);
      END_STATE();
    case 10:
      if (lookahead == ')') ADVANCE(62);
      END_STATE();
    case 11:
      if (lookahead == '.') ADVANCE(44);
      END_STATE();
    case 12:
      if (lookahead == '1') ADVANCE(93);
      if (lookahead == '3') ADVANCE(92);
      END_STATE();
    case 13:
      if (lookahead == '2') ADVANCE(88);
      if (lookahead == '4') ADVANCE(87);
      END_STATE();
    case 14:
      if (lookahead == '2') ADVANCE(85);
      if (lookahead == '4') ADVANCE(86);
      END_STATE();
    case 15:
      if (lookahead == '5') ADVANCE(2);
      END_STATE();
    case 16:
      if (lookahead == '5') ADVANCE(3);
      END_STATE();
    case 17:
      if (lookahead == '5') ADVANCE(4);
      END_STATE();
    case 18:
      if (lookahead == '5') ADVANCE(5);
      END_STATE();
    case 19:
      if (lookahead == '9') ADVANCE(6);
      END_STATE();
    case 20:
      if (lookahead == '9') ADVANCE(7);
      END_STATE();
    case 21:
      if (lookahead == '9') ADVANCE(8);
      END_STATE();
    case 22:
      if (lookahead == '9') ADVANCE(9);
      END_STATE();
    case 23:
      if (lookahead == '9') ADVANCE(10);
      END_STATE();
    case 24:
      if (lookahead == 'J') ADVANCE(74);
      END_STATE();
    case 25:
      if (lookahead == 'N') ADVANCE(83);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(45);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(26);
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 29:
      if (lookahead == 'g') ADVANCE(90);
      END_STATE();
    case 30:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 31:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 32:
      if (lookahead == 'j') ADVANCE(73);
      END_STATE();
    case 33:
      if (lookahead == 'j') ADVANCE(72);
      END_STATE();
    case 34:
      if (lookahead == 'm') ADVANCE(89);
      END_STATE();
    case 35:
      if (lookahead == 'm') ADVANCE(31);
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(100);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(82);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(81);
      END_STATE();
    case 38:
      if (lookahead == 's') ADVANCE(13);
      END_STATE();
    case 39:
      if (lookahead == 's') ADVANCE(14);
      END_STATE();
    case 40:
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 41:
      if (lookahead == 'u') ADVANCE(38);
      END_STATE();
    case 42:
      if (lookahead == 'u') ADVANCE(39);
      END_STATE();
    case 43:
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(100);
      END_STATE();
    case 44:
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(56);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(98);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '7') ADVANCE(80);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_note);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_3);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_4);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_b);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_5);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_quality_base_token1);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_maj9);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_Maj9);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_MAJ9);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_M9);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_9);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_maj_LPAREN9_RPAREN);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_Maj_LPAREN9_RPAREN);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_MAJ_LPAREN9_RPAREN);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_M_LPAREN9_RPAREN);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_LPAREN9_RPAREN);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_maj7);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_Maj7);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_MAJ7);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_M7);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_6);
      if (lookahead == '(') ADVANCE(20);
      if (lookahead == '9') ADVANCE(61);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_maj);
      if (lookahead == '(') ADVANCE(23);
      if (lookahead == '7') ADVANCE(67);
      if (lookahead == '9') ADVANCE(57);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_Maj);
      if (lookahead == '(') ADVANCE(22);
      if (lookahead == '7') ADVANCE(68);
      if (lookahead == '9') ADVANCE(58);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_MAJ);
      if (lookahead == '(') ADVANCE(21);
      if (lookahead == '7') ADVANCE(69);
      if (lookahead == '9') ADVANCE(59);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_M);
      if (lookahead == '(') ADVANCE(19);
      if (lookahead == '7') ADVANCE(70);
      if (lookahead == '9') ADVANCE(60);
      if (lookahead == 'A') ADVANCE(24);
      if (lookahead == 'I') ADVANCE(25);
      if (lookahead == 'a') ADVANCE(32);
      if (lookahead == 'i') ADVANCE(36);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_min7);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_Min7);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_MIN7);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_m7);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_DASH7);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_min);
      if (lookahead == '7') ADVANCE(76);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_Min);
      if (lookahead == '7') ADVANCE(77);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_MIN);
      if (lookahead == '7') ADVANCE(78);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_m);
      if (lookahead == '7') ADVANCE(79);
      if (lookahead == 'a') ADVANCE(33);
      if (lookahead == 'i') ADVANCE(37);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_7sus2);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_7sus4);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_sus4);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_sus2);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_dim);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_aug);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_13);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_11);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_92);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_7);
      if (lookahead == 's') ADVANCE(42);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_62);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      if (lookahead == ')') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(98);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      if (lookahead == ')') ADVANCE(99);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_LPARENb5_RPAREN);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_LPAREN_DASH5_RPAREN);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_LPAREN_PLUS5_RPAREN);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_LPAREN_POUND5_RPAREN);
      END_STATE();
    case 105:
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
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [sym_note] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_3] = ACTIONS(1),
    [anon_sym_4] = ACTIONS(1),
    [anon_sym_b] = ACTIONS(1),
    [anon_sym_5] = ACTIONS(1),
    [aux_sym_quality_base_token1] = ACTIONS(1),
    [anon_sym_maj9] = ACTIONS(1),
    [anon_sym_Maj9] = ACTIONS(1),
    [anon_sym_MAJ9] = ACTIONS(1),
    [anon_sym_M9] = ACTIONS(1),
    [anon_sym_9] = ACTIONS(1),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(1),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(1),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(1),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(1),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(1),
    [anon_sym_maj7] = ACTIONS(1),
    [anon_sym_Maj7] = ACTIONS(1),
    [anon_sym_MAJ7] = ACTIONS(1),
    [anon_sym_M7] = ACTIONS(1),
    [anon_sym_6] = ACTIONS(1),
    [anon_sym_maj] = ACTIONS(1),
    [anon_sym_Maj] = ACTIONS(1),
    [anon_sym_MAJ] = ACTIONS(1),
    [anon_sym_M] = ACTIONS(1),
    [anon_sym_min7] = ACTIONS(1),
    [anon_sym_Min7] = ACTIONS(1),
    [anon_sym_MIN7] = ACTIONS(1),
    [anon_sym_m7] = ACTIONS(1),
    [anon_sym_DASH7] = ACTIONS(1),
    [anon_sym_min] = ACTIONS(1),
    [anon_sym_Min] = ACTIONS(1),
    [anon_sym_MIN] = ACTIONS(1),
    [anon_sym_m] = ACTIONS(1),
    [anon_sym_7sus2] = ACTIONS(1),
    [anon_sym_7sus4] = ACTIONS(1),
    [anon_sym_sus4] = ACTIONS(1),
    [anon_sym_sus2] = ACTIONS(1),
    [anon_sym_dim] = ACTIONS(1),
    [anon_sym_aug] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_13] = ACTIONS(1),
    [anon_sym_11] = ACTIONS(1),
    [anon_sym_92] = ACTIONS(1),
    [anon_sym_7] = ACTIONS(1),
    [anon_sym_62] = ACTIONS(1),
    [aux_sym_quality_modifier_token1] = ACTIONS(1),
    [aux_sym_quality_modifier_token2] = ACTIONS(1),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(1),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(1),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(1),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(25),
    [sym_chord] = STATE(17),
    [sym_root] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_note] = ACTIONS(5),
  },
  [2] = {
    [sym_accidental] = STATE(7),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(7),
    [anon_sym_DASH] = ACTIONS(9),
    [anon_sym_] = ACTIONS(7),
    [anon_sym_2] = ACTIONS(7),
    [sym_note] = ACTIONS(7),
    [anon_sym_POUND] = ACTIONS(11),
    [anon_sym_3] = ACTIONS(11),
    [anon_sym_4] = ACTIONS(11),
    [anon_sym_b] = ACTIONS(11),
    [anon_sym_5] = ACTIONS(11),
    [aux_sym_quality_base_token1] = ACTIONS(7),
    [anon_sym_maj9] = ACTIONS(7),
    [anon_sym_Maj9] = ACTIONS(7),
    [anon_sym_MAJ9] = ACTIONS(7),
    [anon_sym_M9] = ACTIONS(7),
    [anon_sym_9] = ACTIONS(7),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(7),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(7),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(7),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(7),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(7),
    [anon_sym_maj7] = ACTIONS(7),
    [anon_sym_Maj7] = ACTIONS(7),
    [anon_sym_MAJ7] = ACTIONS(7),
    [anon_sym_M7] = ACTIONS(7),
    [anon_sym_6] = ACTIONS(9),
    [anon_sym_maj] = ACTIONS(9),
    [anon_sym_Maj] = ACTIONS(9),
    [anon_sym_MAJ] = ACTIONS(9),
    [anon_sym_M] = ACTIONS(9),
    [anon_sym_min7] = ACTIONS(7),
    [anon_sym_Min7] = ACTIONS(7),
    [anon_sym_MIN7] = ACTIONS(7),
    [anon_sym_m7] = ACTIONS(7),
    [anon_sym_DASH7] = ACTIONS(7),
    [anon_sym_min] = ACTIONS(9),
    [anon_sym_Min] = ACTIONS(9),
    [anon_sym_MIN] = ACTIONS(9),
    [anon_sym_m] = ACTIONS(9),
    [anon_sym_7sus2] = ACTIONS(7),
    [anon_sym_7sus4] = ACTIONS(7),
    [anon_sym_sus4] = ACTIONS(7),
    [anon_sym_sus2] = ACTIONS(7),
    [anon_sym_dim] = ACTIONS(7),
    [anon_sym_aug] = ACTIONS(7),
    [anon_sym_PLUS] = ACTIONS(7),
    [anon_sym_13] = ACTIONS(7),
    [anon_sym_11] = ACTIONS(7),
    [anon_sym_92] = ACTIONS(7),
    [anon_sym_7] = ACTIONS(9),
    [anon_sym_62] = ACTIONS(7),
    [aux_sym_quality_modifier_token1] = ACTIONS(7),
    [aux_sym_quality_modifier_token2] = ACTIONS(7),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(7),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(7),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(7),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(7),
    [anon_sym_SLASH] = ACTIONS(7),
  },
  [3] = {
    [sym_accidental] = STATE(7),
    [aux_sym_root_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(13),
    [anon_sym_DASH] = ACTIONS(15),
    [anon_sym_] = ACTIONS(13),
    [anon_sym_2] = ACTIONS(13),
    [sym_note] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(11),
    [anon_sym_3] = ACTIONS(11),
    [anon_sym_4] = ACTIONS(11),
    [anon_sym_b] = ACTIONS(11),
    [anon_sym_5] = ACTIONS(11),
    [aux_sym_quality_base_token1] = ACTIONS(13),
    [anon_sym_maj9] = ACTIONS(13),
    [anon_sym_Maj9] = ACTIONS(13),
    [anon_sym_MAJ9] = ACTIONS(13),
    [anon_sym_M9] = ACTIONS(13),
    [anon_sym_9] = ACTIONS(13),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(13),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(13),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(13),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(13),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(13),
    [anon_sym_maj7] = ACTIONS(13),
    [anon_sym_Maj7] = ACTIONS(13),
    [anon_sym_MAJ7] = ACTIONS(13),
    [anon_sym_M7] = ACTIONS(13),
    [anon_sym_6] = ACTIONS(15),
    [anon_sym_maj] = ACTIONS(15),
    [anon_sym_Maj] = ACTIONS(15),
    [anon_sym_MAJ] = ACTIONS(15),
    [anon_sym_M] = ACTIONS(15),
    [anon_sym_min7] = ACTIONS(13),
    [anon_sym_Min7] = ACTIONS(13),
    [anon_sym_MIN7] = ACTIONS(13),
    [anon_sym_m7] = ACTIONS(13),
    [anon_sym_DASH7] = ACTIONS(13),
    [anon_sym_min] = ACTIONS(15),
    [anon_sym_Min] = ACTIONS(15),
    [anon_sym_MIN] = ACTIONS(15),
    [anon_sym_m] = ACTIONS(15),
    [anon_sym_7sus2] = ACTIONS(13),
    [anon_sym_7sus4] = ACTIONS(13),
    [anon_sym_sus4] = ACTIONS(13),
    [anon_sym_sus2] = ACTIONS(13),
    [anon_sym_dim] = ACTIONS(13),
    [anon_sym_aug] = ACTIONS(13),
    [anon_sym_PLUS] = ACTIONS(13),
    [anon_sym_13] = ACTIONS(13),
    [anon_sym_11] = ACTIONS(13),
    [anon_sym_92] = ACTIONS(13),
    [anon_sym_7] = ACTIONS(15),
    [anon_sym_62] = ACTIONS(13),
    [aux_sym_quality_modifier_token1] = ACTIONS(13),
    [aux_sym_quality_modifier_token2] = ACTIONS(13),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(13),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(13),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(13),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(13),
  },
  [4] = {
    [sym_accidental] = STATE(7),
    [aux_sym_root_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(17),
    [anon_sym_DASH] = ACTIONS(19),
    [anon_sym_] = ACTIONS(17),
    [anon_sym_2] = ACTIONS(17),
    [sym_note] = ACTIONS(17),
    [anon_sym_POUND] = ACTIONS(21),
    [anon_sym_3] = ACTIONS(21),
    [anon_sym_4] = ACTIONS(21),
    [anon_sym_b] = ACTIONS(21),
    [anon_sym_5] = ACTIONS(21),
    [aux_sym_quality_base_token1] = ACTIONS(17),
    [anon_sym_maj9] = ACTIONS(17),
    [anon_sym_Maj9] = ACTIONS(17),
    [anon_sym_MAJ9] = ACTIONS(17),
    [anon_sym_M9] = ACTIONS(17),
    [anon_sym_9] = ACTIONS(17),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(17),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(17),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(17),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(17),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(17),
    [anon_sym_maj7] = ACTIONS(17),
    [anon_sym_Maj7] = ACTIONS(17),
    [anon_sym_MAJ7] = ACTIONS(17),
    [anon_sym_M7] = ACTIONS(17),
    [anon_sym_6] = ACTIONS(19),
    [anon_sym_maj] = ACTIONS(19),
    [anon_sym_Maj] = ACTIONS(19),
    [anon_sym_MAJ] = ACTIONS(19),
    [anon_sym_M] = ACTIONS(19),
    [anon_sym_min7] = ACTIONS(17),
    [anon_sym_Min7] = ACTIONS(17),
    [anon_sym_MIN7] = ACTIONS(17),
    [anon_sym_m7] = ACTIONS(17),
    [anon_sym_DASH7] = ACTIONS(17),
    [anon_sym_min] = ACTIONS(19),
    [anon_sym_Min] = ACTIONS(19),
    [anon_sym_MIN] = ACTIONS(19),
    [anon_sym_m] = ACTIONS(19),
    [anon_sym_7sus2] = ACTIONS(17),
    [anon_sym_7sus4] = ACTIONS(17),
    [anon_sym_sus4] = ACTIONS(17),
    [anon_sym_sus2] = ACTIONS(17),
    [anon_sym_dim] = ACTIONS(17),
    [anon_sym_aug] = ACTIONS(17),
    [anon_sym_PLUS] = ACTIONS(17),
    [anon_sym_13] = ACTIONS(17),
    [anon_sym_11] = ACTIONS(17),
    [anon_sym_92] = ACTIONS(17),
    [anon_sym_7] = ACTIONS(19),
    [anon_sym_62] = ACTIONS(17),
    [aux_sym_quality_modifier_token1] = ACTIONS(17),
    [aux_sym_quality_modifier_token2] = ACTIONS(17),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(17),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(17),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(17),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(17),
    [anon_sym_SLASH] = ACTIONS(17),
  },
  [5] = {
    [sym_quality] = STATE(18),
    [sym_quality_base] = STATE(11),
    [sym_quality_modifier] = STATE(14),
    [sym_bass] = STATE(19),
    [aux_sym_quality_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(24),
    [anon_sym_DASH] = ACTIONS(26),
    [anon_sym_] = ACTIONS(24),
    [anon_sym_2] = ACTIONS(24),
    [sym_note] = ACTIONS(24),
    [aux_sym_quality_base_token1] = ACTIONS(29),
    [anon_sym_maj9] = ACTIONS(29),
    [anon_sym_Maj9] = ACTIONS(29),
    [anon_sym_MAJ9] = ACTIONS(29),
    [anon_sym_M9] = ACTIONS(29),
    [anon_sym_9] = ACTIONS(29),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(29),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(29),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(29),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(29),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(29),
    [anon_sym_maj7] = ACTIONS(29),
    [anon_sym_Maj7] = ACTIONS(29),
    [anon_sym_MAJ7] = ACTIONS(29),
    [anon_sym_M7] = ACTIONS(29),
    [anon_sym_6] = ACTIONS(31),
    [anon_sym_maj] = ACTIONS(31),
    [anon_sym_Maj] = ACTIONS(31),
    [anon_sym_MAJ] = ACTIONS(31),
    [anon_sym_M] = ACTIONS(31),
    [anon_sym_min7] = ACTIONS(29),
    [anon_sym_Min7] = ACTIONS(29),
    [anon_sym_MIN7] = ACTIONS(29),
    [anon_sym_m7] = ACTIONS(29),
    [anon_sym_DASH7] = ACTIONS(29),
    [anon_sym_min] = ACTIONS(31),
    [anon_sym_Min] = ACTIONS(31),
    [anon_sym_MIN] = ACTIONS(31),
    [anon_sym_m] = ACTIONS(31),
    [anon_sym_7sus2] = ACTIONS(29),
    [anon_sym_7sus4] = ACTIONS(29),
    [anon_sym_sus4] = ACTIONS(29),
    [anon_sym_sus2] = ACTIONS(29),
    [anon_sym_dim] = ACTIONS(29),
    [anon_sym_aug] = ACTIONS(29),
    [anon_sym_PLUS] = ACTIONS(29),
    [anon_sym_13] = ACTIONS(29),
    [anon_sym_11] = ACTIONS(29),
    [anon_sym_92] = ACTIONS(29),
    [anon_sym_7] = ACTIONS(31),
    [anon_sym_62] = ACTIONS(29),
    [aux_sym_quality_modifier_token1] = ACTIONS(33),
    [aux_sym_quality_modifier_token2] = ACTIONS(33),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(33),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(33),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(33),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(33),
    [anon_sym_SLASH] = ACTIONS(35),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(37),
    [anon_sym_DASH] = ACTIONS(39),
    [anon_sym_] = ACTIONS(37),
    [anon_sym_2] = ACTIONS(37),
    [sym_note] = ACTIONS(37),
    [anon_sym_POUND] = ACTIONS(37),
    [anon_sym_3] = ACTIONS(37),
    [anon_sym_4] = ACTIONS(37),
    [anon_sym_b] = ACTIONS(37),
    [anon_sym_5] = ACTIONS(37),
    [aux_sym_quality_base_token1] = ACTIONS(37),
    [anon_sym_maj9] = ACTIONS(37),
    [anon_sym_Maj9] = ACTIONS(37),
    [anon_sym_MAJ9] = ACTIONS(37),
    [anon_sym_M9] = ACTIONS(37),
    [anon_sym_9] = ACTIONS(37),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(37),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(37),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(37),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(37),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(37),
    [anon_sym_maj7] = ACTIONS(37),
    [anon_sym_Maj7] = ACTIONS(37),
    [anon_sym_MAJ7] = ACTIONS(37),
    [anon_sym_M7] = ACTIONS(37),
    [anon_sym_6] = ACTIONS(39),
    [anon_sym_maj] = ACTIONS(39),
    [anon_sym_Maj] = ACTIONS(39),
    [anon_sym_MAJ] = ACTIONS(39),
    [anon_sym_M] = ACTIONS(39),
    [anon_sym_min7] = ACTIONS(37),
    [anon_sym_Min7] = ACTIONS(37),
    [anon_sym_MIN7] = ACTIONS(37),
    [anon_sym_m7] = ACTIONS(37),
    [anon_sym_DASH7] = ACTIONS(37),
    [anon_sym_min] = ACTIONS(39),
    [anon_sym_Min] = ACTIONS(39),
    [anon_sym_MIN] = ACTIONS(39),
    [anon_sym_m] = ACTIONS(39),
    [anon_sym_7sus2] = ACTIONS(37),
    [anon_sym_7sus4] = ACTIONS(37),
    [anon_sym_sus4] = ACTIONS(37),
    [anon_sym_sus2] = ACTIONS(37),
    [anon_sym_dim] = ACTIONS(37),
    [anon_sym_aug] = ACTIONS(37),
    [anon_sym_PLUS] = ACTIONS(37),
    [anon_sym_13] = ACTIONS(37),
    [anon_sym_11] = ACTIONS(37),
    [anon_sym_92] = ACTIONS(37),
    [anon_sym_7] = ACTIONS(39),
    [anon_sym_62] = ACTIONS(37),
    [aux_sym_quality_modifier_token1] = ACTIONS(37),
    [aux_sym_quality_modifier_token2] = ACTIONS(37),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(37),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(37),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(37),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(37),
    [anon_sym_SLASH] = ACTIONS(37),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(43),
    [anon_sym_] = ACTIONS(41),
    [anon_sym_2] = ACTIONS(41),
    [sym_note] = ACTIONS(41),
    [anon_sym_POUND] = ACTIONS(41),
    [anon_sym_3] = ACTIONS(41),
    [anon_sym_4] = ACTIONS(41),
    [anon_sym_b] = ACTIONS(41),
    [anon_sym_5] = ACTIONS(41),
    [aux_sym_quality_base_token1] = ACTIONS(41),
    [anon_sym_maj9] = ACTIONS(41),
    [anon_sym_Maj9] = ACTIONS(41),
    [anon_sym_MAJ9] = ACTIONS(41),
    [anon_sym_M9] = ACTIONS(41),
    [anon_sym_9] = ACTIONS(41),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(41),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(41),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(41),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(41),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(41),
    [anon_sym_maj7] = ACTIONS(41),
    [anon_sym_Maj7] = ACTIONS(41),
    [anon_sym_MAJ7] = ACTIONS(41),
    [anon_sym_M7] = ACTIONS(41),
    [anon_sym_6] = ACTIONS(43),
    [anon_sym_maj] = ACTIONS(43),
    [anon_sym_Maj] = ACTIONS(43),
    [anon_sym_MAJ] = ACTIONS(43),
    [anon_sym_M] = ACTIONS(43),
    [anon_sym_min7] = ACTIONS(41),
    [anon_sym_Min7] = ACTIONS(41),
    [anon_sym_MIN7] = ACTIONS(41),
    [anon_sym_m7] = ACTIONS(41),
    [anon_sym_DASH7] = ACTIONS(41),
    [anon_sym_min] = ACTIONS(43),
    [anon_sym_Min] = ACTIONS(43),
    [anon_sym_MIN] = ACTIONS(43),
    [anon_sym_m] = ACTIONS(43),
    [anon_sym_7sus2] = ACTIONS(41),
    [anon_sym_7sus4] = ACTIONS(41),
    [anon_sym_sus4] = ACTIONS(41),
    [anon_sym_sus2] = ACTIONS(41),
    [anon_sym_dim] = ACTIONS(41),
    [anon_sym_aug] = ACTIONS(41),
    [anon_sym_PLUS] = ACTIONS(41),
    [anon_sym_13] = ACTIONS(41),
    [anon_sym_11] = ACTIONS(41),
    [anon_sym_92] = ACTIONS(41),
    [anon_sym_7] = ACTIONS(43),
    [anon_sym_62] = ACTIONS(41),
    [aux_sym_quality_modifier_token1] = ACTIONS(41),
    [aux_sym_quality_modifier_token2] = ACTIONS(41),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(41),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(41),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(41),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(41),
    [anon_sym_SLASH] = ACTIONS(41),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    STATE(8), 1,
      aux_sym_quality_repeat1,
    STATE(14), 1,
      sym_quality_modifier,
    ACTIONS(45), 6,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
      anon_sym_SLASH,
    ACTIONS(47), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
  [23] = 4,
    STATE(8), 1,
      aux_sym_quality_repeat1,
    STATE(14), 1,
      sym_quality_modifier,
    ACTIONS(33), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(50), 6,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
      anon_sym_SLASH,
  [46] = 4,
    STATE(8), 1,
      aux_sym_quality_repeat1,
    STATE(14), 1,
      sym_quality_modifier,
    ACTIONS(33), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(52), 6,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
      anon_sym_SLASH,
  [69] = 4,
    STATE(9), 1,
      aux_sym_quality_repeat1,
    STATE(14), 1,
      sym_quality_modifier,
    ACTIONS(33), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(54), 6,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
      anon_sym_SLASH,
  [92] = 1,
    ACTIONS(56), 12,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
      anon_sym_SLASH,
  [107] = 1,
    ACTIONS(58), 12,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
      anon_sym_SLASH,
  [122] = 1,
    ACTIONS(60), 12,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
      anon_sym_SLASH,
  [137] = 6,
    ACTIONS(5), 1,
      sym_note,
    ACTIONS(62), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      sym_root,
    STATE(23), 1,
      sym_separator,
    STATE(16), 2,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(64), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [159] = 6,
    ACTIONS(66), 1,
      ts_builtin_sym_end,
    ACTIONS(71), 1,
      sym_note,
    STATE(5), 1,
      sym_root,
    STATE(23), 1,
      sym_separator,
    STATE(16), 2,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(68), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [181] = 6,
    ACTIONS(5), 1,
      sym_note,
    ACTIONS(74), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      sym_root,
    STATE(23), 1,
      sym_separator,
    STATE(15), 2,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(64), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [203] = 3,
    ACTIONS(35), 1,
      anon_sym_SLASH,
    STATE(22), 1,
      sym_bass,
    ACTIONS(76), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [217] = 1,
    ACTIONS(78), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [225] = 1,
    ACTIONS(66), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [233] = 1,
    ACTIONS(80), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [241] = 1,
    ACTIONS(82), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [249] = 3,
    ACTIONS(5), 1,
      sym_note,
    STATE(5), 1,
      sym_root,
    STATE(20), 1,
      sym_chord,
  [259] = 2,
    ACTIONS(5), 1,
      sym_note,
    STATE(21), 1,
      sym_root,
  [266] = 1,
    ACTIONS(84), 1,
      ts_builtin_sym_end,
  [270] = 1,
    ACTIONS(86), 1,
      sym_note,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 23,
  [SMALL_STATE(10)] = 46,
  [SMALL_STATE(11)] = 69,
  [SMALL_STATE(12)] = 92,
  [SMALL_STATE(13)] = 107,
  [SMALL_STATE(14)] = 122,
  [SMALL_STATE(15)] = 137,
  [SMALL_STATE(16)] = 159,
  [SMALL_STATE(17)] = 181,
  [SMALL_STATE(18)] = 203,
  [SMALL_STATE(19)] = 217,
  [SMALL_STATE(20)] = 225,
  [SMALL_STATE(21)] = 233,
  [SMALL_STATE(22)] = 241,
  [SMALL_STATE(23)] = 249,
  [SMALL_STATE(24)] = 259,
  [SMALL_STATE(25)] = 266,
  [SMALL_STATE(26)] = 270,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1, .production_id = 1),
  [9] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 1, .production_id = 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 2, .production_id = 4),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 2, .production_id = 4),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 10),
  [19] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 10),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 10), SHIFT_REPEAT(6),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 1, .production_id = 2),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_chord, 1, .production_id = 2), SHIFT(12),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accidental, 1),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accidental, 1),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 1, .production_id = 3),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 1, .production_id = 3),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 14),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 14), SHIFT_REPEAT(13),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 2, .production_id = 13),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 9),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 6),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_base, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_modifier, 1),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 1, .production_id = 7),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(26),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 5),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 8),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 2, .production_id = 11),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 12),
  [84] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_separator, 1, .dynamic_precedence = 1),
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
