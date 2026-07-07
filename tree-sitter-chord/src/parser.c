#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 83
#define ALIAS_COUNT 0
#define TOKEN_COUNT 68
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 8
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 19

enum {
  sym_mode_chord_over_bass_note = 1,
  sym_mode_slash_chord_inversion = 2,
  sym_mode_polychord = 3,
  sym_mode_root_inv = 4,
  sym_mode_1st_inv = 5,
  sym_mode_2nd_inv = 6,
  sym_mode_3rd_inv = 7,
  anon_sym_DASH = 8,
  anon_sym_ = 9,
  anon_sym_2 = 10,
  sym_chord_inversion = 11,
  sym_note = 12,
  anon_sym_POUND = 13,
  anon_sym_3 = 14,
  anon_sym_4 = 15,
  anon_sym_b = 16,
  anon_sym_5 = 17,
  aux_sym_quality_base_token1 = 18,
  anon_sym_maj9 = 19,
  anon_sym_Maj9 = 20,
  anon_sym_MAJ9 = 21,
  anon_sym_M9 = 22,
  anon_sym_9 = 23,
  anon_sym_maj_LPAREN9_RPAREN = 24,
  anon_sym_Maj_LPAREN9_RPAREN = 25,
  anon_sym_MAJ_LPAREN9_RPAREN = 26,
  anon_sym_M_LPAREN9_RPAREN = 27,
  anon_sym_LPAREN9_RPAREN = 28,
  anon_sym_maj7 = 29,
  anon_sym_Maj7 = 30,
  anon_sym_MAJ7 = 31,
  anon_sym_M7 = 32,
  anon_sym_6 = 33,
  anon_sym_maj = 34,
  anon_sym_Maj = 35,
  anon_sym_MAJ = 36,
  anon_sym_M = 37,
  anon_sym_min7 = 38,
  anon_sym_Min7 = 39,
  anon_sym_MIN7 = 40,
  anon_sym_m7 = 41,
  anon_sym_DASH7 = 42,
  anon_sym_min = 43,
  anon_sym_Min = 44,
  anon_sym_MIN = 45,
  anon_sym_m = 46,
  anon_sym_7sus2 = 47,
  anon_sym_7sus4 = 48,
  anon_sym_sus4 = 49,
  anon_sym_sus2 = 50,
  anon_sym_dim = 51,
  anon_sym_aug = 52,
  anon_sym_PLUS = 53,
  anon_sym_13 = 54,
  anon_sym_11 = 55,
  anon_sym_92 = 56,
  anon_sym_7 = 57,
  anon_sym_62 = 58,
  aux_sym_quality_modifier_token1 = 59,
  aux_sym_quality_modifier_token2 = 60,
  anon_sym_LPARENb5_RPAREN = 61,
  anon_sym_LPAREN_DASH5_RPAREN = 62,
  anon_sym_LPAREN_PLUS5_RPAREN = 63,
  anon_sym_LPAREN_POUND5_RPAREN = 64,
  anon_sym_SLASH = 65,
  anon_sym_on = 66,
  anon_sym_over = 67,
  sym_source_file = 68,
  sym__event = 69,
  sym_separator = 70,
  sym_chord = 71,
  sym_root = 72,
  sym_accidental = 73,
  sym_quality = 74,
  sym_quality_base = 75,
  sym_quality_modifier = 76,
  sym__lower = 77,
  sym_bass = 78,
  sym_on_bass = 79,
  aux_sym_source_file_repeat1 = 80,
  aux_sym_root_repeat1 = 81,
  aux_sym_quality_repeat1 = 82,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_mode_chord_over_bass_note] = "mode_chord_over_bass_note",
  [sym_mode_slash_chord_inversion] = "mode_slash_chord_inversion",
  [sym_mode_polychord] = "mode_polychord",
  [sym_mode_root_inv] = "mode_root_inv",
  [sym_mode_1st_inv] = "mode_1st_inv",
  [sym_mode_2nd_inv] = "mode_2nd_inv",
  [sym_mode_3rd_inv] = "mode_3rd_inv",
  [anon_sym_DASH] = "-",
  [anon_sym_] = "→",
  [anon_sym_2] = "・",
  [sym_chord_inversion] = "chord_inversion",
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
  [anon_sym_on] = "on",
  [anon_sym_over] = "over",
  [sym_source_file] = "source_file",
  [sym__event] = "_event",
  [sym_separator] = "separator",
  [sym_chord] = "chord",
  [sym_root] = "root",
  [sym_accidental] = "accidental",
  [sym_quality] = "quality",
  [sym_quality_base] = "quality_base",
  [sym_quality_modifier] = "quality_modifier",
  [sym__lower] = "_lower",
  [sym_bass] = "bass",
  [sym_on_bass] = "on_bass",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_root_repeat1] = "root_repeat1",
  [aux_sym_quality_repeat1] = "quality_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_mode_chord_over_bass_note] = sym_mode_chord_over_bass_note,
  [sym_mode_slash_chord_inversion] = sym_mode_slash_chord_inversion,
  [sym_mode_polychord] = sym_mode_polychord,
  [sym_mode_root_inv] = sym_mode_root_inv,
  [sym_mode_1st_inv] = sym_mode_1st_inv,
  [sym_mode_2nd_inv] = sym_mode_2nd_inv,
  [sym_mode_3rd_inv] = sym_mode_3rd_inv,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_] = anon_sym_,
  [anon_sym_2] = anon_sym_2,
  [sym_chord_inversion] = sym_chord_inversion,
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
  [anon_sym_on] = anon_sym_on,
  [anon_sym_over] = anon_sym_over,
  [sym_source_file] = sym_source_file,
  [sym__event] = sym__event,
  [sym_separator] = sym_separator,
  [sym_chord] = sym_chord,
  [sym_root] = sym_root,
  [sym_accidental] = sym_accidental,
  [sym_quality] = sym_quality,
  [sym_quality_base] = sym_quality_base,
  [sym_quality_modifier] = sym_quality_modifier,
  [sym__lower] = sym__lower,
  [sym_bass] = sym_bass,
  [sym_on_bass] = sym_on_bass,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_root_repeat1] = aux_sym_root_repeat1,
  [aux_sym_quality_repeat1] = aux_sym_quality_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_mode_chord_over_bass_note] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_slash_chord_inversion] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_polychord] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_root_inv] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_1st_inv] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_2nd_inv] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_3rd_inv] = {
    .visible = true,
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
  [sym_chord_inversion] = {
    .visible = true,
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
  [anon_sym_on] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_over] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__event] = {
    .visible = false,
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
  [sym__lower] = {
    .visible = false,
    .named = true,
  },
  [sym_bass] = {
    .visible = true,
    .named = true,
  },
  [sym_on_bass] = {
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
  field_inversion = 4,
  field_modifier = 5,
  field_note = 6,
  field_quality = 7,
  field_root = 8,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_accidental] = "accidental",
  [field_base] = "base",
  [field_bass] = "bass",
  [field_inversion] = "inversion",
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
  [6] = {.index = 7, .length = 2},
  [7] = {.index = 9, .length = 1},
  [8] = {.index = 10, .length = 1},
  [9] = {.index = 11, .length = 2},
  [10] = {.index = 13, .length = 1},
  [11] = {.index = 14, .length = 2},
  [12] = {.index = 16, .length = 3},
  [13] = {.index = 19, .length = 3},
  [14] = {.index = 22, .length = 3},
  [15] = {.index = 25, .length = 3},
  [16] = {.index = 28, .length = 2},
  [17] = {.index = 30, .length = 2},
  [18] = {.index = 32, .length = 4},
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
    {field_inversion, 1},
    {field_root, 0},
  [7] =
    {field_quality, 1},
    {field_root, 0},
  [9] =
    {field_base, 0},
  [10] =
    {field_modifier, 0},
  [11] =
    {field_bass, 1},
    {field_root, 0},
  [13] =
    {field_modifier, 0, .inherited = true},
  [14] =
    {field_accidental, 0, .inherited = true},
    {field_accidental, 1, .inherited = true},
  [16] =
    {field_bass, 2},
    {field_inversion, 1},
    {field_root, 0},
  [19] =
    {field_inversion, 1, .inherited = true},
    {field_quality, 1, .inherited = true},
    {field_root, 1, .inherited = true},
  [22] =
    {field_inversion, 2},
    {field_quality, 1},
    {field_root, 0},
  [25] =
    {field_bass, 2},
    {field_quality, 1},
    {field_root, 0},
  [28] =
    {field_base, 0},
    {field_modifier, 1, .inherited = true},
  [30] =
    {field_modifier, 0, .inherited = true},
    {field_modifier, 1, .inherited = true},
  [32] =
    {field_bass, 3},
    {field_inversion, 2},
    {field_quality, 1},
    {field_root, 0},
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
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(138);
      if (lookahead == '#') ADVANCE(162);
      if (lookahead == '(') ADVANCE(11);
      if (lookahead == '+') ADVANCE(202);
      if (lookahead == '-') ADVANCE(156);
      if (lookahead == '/') ADVANCE(216);
      if (lookahead == '1') ADVANCE(22);
      if (lookahead == '2') ADVANCE(85);
      if (lookahead == '3') ADVANCE(112);
      if (lookahead == '4') ADVANCE(21);
      if (lookahead == '6') ADVANCE(207);
      if (lookahead == '7') ADVANCE(206);
      if (lookahead == '9') ADVANCE(205);
      if (lookahead == 'C') ADVANCE(161);
      if (lookahead == 'M') ADVANCE(186);
      if (lookahead == 'S') ADVANCE(83);
      if (lookahead == '^') ADVANCE(135);
      if (lookahead == 'a') ADVANCE(38);
      if (lookahead == 'b') ADVANCE(165);
      if (lookahead == 'c') ADVANCE(72);
      if (lookahead == 'd') ADVANCE(41);
      if (lookahead == 'm') ADVANCE(195);
      if (lookahead == 'o') ADVANCE(46);
      if (lookahead == 's') ADVANCE(54);
      if (lookahead == 8594) ADVANCE(157);
      if (lookahead == 9651) ADVANCE(182);
      if (lookahead == 9837) ADVANCE(166);
      if (lookahead == 9839) ADVANCE(164);
      if (lookahead == 12539) ADVANCE(158);
      if (lookahead == 65283) ADVANCE(163);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(93);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(94);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(102);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'G')) ADVANCE(160);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(76);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(61);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(59);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(115);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(96);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(91);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(78);
      END_STATE();
    case 8:
      if (lookahead == ' ') ADVANCE(79);
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(80);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(81);
      END_STATE();
    case 11:
      if (lookahead == '#') ADVANCE(25);
      if (lookahead == '+') ADVANCE(26);
      if (lookahead == '-') ADVANCE(27);
      if (lookahead == 'a') ADVANCE(37);
      if (lookahead == 'b') ADVANCE(28);
      if (lookahead == 'o') ADVANCE(47);
      END_STATE();
    case 12:
      if (lookahead == ')') ADVANCE(215);
      END_STATE();
    case 13:
      if (lookahead == ')') ADVANCE(214);
      END_STATE();
    case 14:
      if (lookahead == ')') ADVANCE(213);
      END_STATE();
    case 15:
      if (lookahead == ')') ADVANCE(212);
      END_STATE();
    case 16:
      if (lookahead == ')') ADVANCE(176);
      END_STATE();
    case 17:
      if (lookahead == ')') ADVANCE(177);
      END_STATE();
    case 18:
      if (lookahead == ')') ADVANCE(175);
      END_STATE();
    case 19:
      if (lookahead == ')') ADVANCE(174);
      END_STATE();
    case 20:
      if (lookahead == ')') ADVANCE(173);
      END_STATE();
    case 21:
      if (lookahead == '.') ADVANCE(136);
      END_STATE();
    case 22:
      if (lookahead == '1') ADVANCE(204);
      if (lookahead == '3') ADVANCE(203);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(119);
      END_STATE();
    case 23:
      if (lookahead == '2') ADVANCE(199);
      if (lookahead == '4') ADVANCE(198);
      END_STATE();
    case 24:
      if (lookahead == '2') ADVANCE(196);
      if (lookahead == '4') ADVANCE(197);
      END_STATE();
    case 25:
      if (lookahead == '5') ADVANCE(12);
      END_STATE();
    case 26:
      if (lookahead == '5') ADVANCE(13);
      END_STATE();
    case 27:
      if (lookahead == '5') ADVANCE(14);
      END_STATE();
    case 28:
      if (lookahead == '5') ADVANCE(15);
      END_STATE();
    case 29:
      if (lookahead == '9') ADVANCE(16);
      END_STATE();
    case 30:
      if (lookahead == '9') ADVANCE(17);
      END_STATE();
    case 31:
      if (lookahead == '9') ADVANCE(18);
      END_STATE();
    case 32:
      if (lookahead == '9') ADVANCE(19);
      END_STATE();
    case 33:
      if (lookahead == '9') ADVANCE(20);
      END_STATE();
    case 34:
      if (lookahead == 'J') ADVANCE(185);
      END_STATE();
    case 35:
      if (lookahead == 'N') ADVANCE(194);
      END_STATE();
    case 36:
      if (lookahead == 'd') ADVANCE(137);
      END_STATE();
    case 37:
      if (lookahead == 'd') ADVANCE(36);
      END_STATE();
    case 38:
      if (lookahead == 'd') ADVANCE(36);
      if (lookahead == 'u') ADVANCE(40);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(50);
      END_STATE();
    case 40:
      if (lookahead == 'g') ADVANCE(201);
      END_STATE();
    case 41:
      if (lookahead == 'i') ADVANCE(45);
      END_STATE();
    case 42:
      if (lookahead == 'i') ADVANCE(53);
      END_STATE();
    case 43:
      if (lookahead == 'j') ADVANCE(184);
      END_STATE();
    case 44:
      if (lookahead == 'j') ADVANCE(183);
      END_STATE();
    case 45:
      if (lookahead == 'm') ADVANCE(200);
      END_STATE();
    case 46:
      if (lookahead == 'm') ADVANCE(42);
      if (lookahead == 'n') ADVANCE(217);
      if (lookahead == 'v') ADVANCE(39);
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(211);
      END_STATE();
    case 47:
      if (lookahead == 'm') ADVANCE(42);
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(211);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(193);
      END_STATE();
    case 49:
      if (lookahead == 'n') ADVANCE(192);
      END_STATE();
    case 50:
      if (lookahead == 'r') ADVANCE(218);
      END_STATE();
    case 51:
      if (lookahead == 's') ADVANCE(23);
      END_STATE();
    case 52:
      if (lookahead == 's') ADVANCE(24);
      END_STATE();
    case 53:
      if (lookahead == 't') ADVANCE(134);
      END_STATE();
    case 54:
      if (lookahead == 'u') ADVANCE(51);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(56);
      END_STATE();
    case 55:
      if (lookahead == 'u') ADVANCE(52);
      END_STATE();
    case 56:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(114);
      END_STATE();
    case 57:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 58:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(117);
      END_STATE();
    case 59:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(58);
      END_STATE();
    case 60:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(120);
      END_STATE();
    case 61:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(75);
      END_STATE();
    case 62:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(145);
      END_STATE();
    case 63:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(5);
      END_STATE();
    case 64:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(7);
      END_STATE();
    case 65:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(8);
      END_STATE();
    case 66:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(10);
      END_STATE();
    case 67:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(144);
      END_STATE();
    case 68:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(140);
      END_STATE();
    case 69:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(108);
      END_STATE();
    case 70:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(110);
      END_STATE();
    case 71:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(109);
      END_STATE();
    case 72:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(99);
      END_STATE();
    case 73:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(2);
      END_STATE();
    case 74:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(98);
      END_STATE();
    case 75:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(101);
      END_STATE();
    case 76:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(86);
      END_STATE();
    case 77:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(57);
      END_STATE();
    case 78:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(88);
      END_STATE();
    case 79:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(89);
      END_STATE();
    case 80:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(90);
      END_STATE();
    case 81:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(92);
      END_STATE();
    case 82:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(97);
      END_STATE();
    case 83:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(56);
      END_STATE();
    case 84:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(133);
      END_STATE();
    case 85:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(64);
      END_STATE();
    case 86:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(127);
      END_STATE();
    case 87:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(142);
      END_STATE();
    case 88:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(128);
      END_STATE();
    case 89:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(129);
      END_STATE();
    case 90:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(130);
      END_STATE();
    case 91:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(95);
      END_STATE();
    case 92:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(131);
      END_STATE();
    case 93:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(84);
      END_STATE();
    case 94:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(100);
      END_STATE();
    case 95:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(122);
      END_STATE();
    case 96:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(132);
      END_STATE();
    case 97:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(87);
      END_STATE();
    case 98:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(105);
      END_STATE();
    case 99:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(111);
      END_STATE();
    case 100:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(124);
      END_STATE();
    case 101:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(113);
      END_STATE();
    case 102:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(103);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(147);
      END_STATE();
    case 103:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(69);
      END_STATE();
    case 104:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(125);
      END_STATE();
    case 105:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 106:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 107:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(77);
      END_STATE();
    case 108:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(4);
      END_STATE();
    case 109:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(3);
      END_STATE();
    case 110:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(116);
      END_STATE();
    case 111:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(63);
      END_STATE();
    case 112:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 113:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(66);
      END_STATE();
    case 114:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(73);
      END_STATE();
    case 115:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(121);
      END_STATE();
    case 116:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(82);
      END_STATE();
    case 117:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(118);
      END_STATE();
    case 118:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(6);
      END_STATE();
    case 119:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(1);
      END_STATE();
    case 120:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(126);
      END_STATE();
    case 121:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(104);
      END_STATE();
    case 122:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(68);
      END_STATE();
    case 123:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(107);
      END_STATE();
    case 124:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(9);
      END_STATE();
    case 125:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(60);
      END_STATE();
    case 126:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(106);
      END_STATE();
    case 127:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(151);
      END_STATE();
    case 128:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(153);
      END_STATE();
    case 129:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(155);
      END_STATE();
    case 130:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(149);
      END_STATE();
    case 131:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(70);
      END_STATE();
    case 132:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(71);
      END_STATE();
    case 133:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(146);
      END_STATE();
    case 134:
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(211);
      END_STATE();
    case 135:
      if (('0' <= lookahead && lookahead <= '3')) ADVANCE(159);
      END_STATE();
    case 136:
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(167);
      END_STATE();
    case 137:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(209);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_mode_chord_over_bass_note);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_mode_chord_over_bass_note);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(139);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_mode_slash_chord_inversion);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_mode_slash_chord_inversion);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(141);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_mode_polychord);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ' ') ADVANCE(123);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(143);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(143);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(143);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(74);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(143);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(145);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_mode_root_inv);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_mode_root_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(148);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_mode_1st_inv);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_mode_1st_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(150);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_mode_2nd_inv);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_mode_2nd_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(152);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_mode_3rd_inv);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_mode_3rd_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(154);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '7') ADVANCE(191);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_chord_inversion);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_note);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(99);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_3);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_4);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_b);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_5);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_quality_base_token1);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(167);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_maj9);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_Maj9);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_MAJ9);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_M9);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_9);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_maj_LPAREN9_RPAREN);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_Maj_LPAREN9_RPAREN);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_MAJ_LPAREN9_RPAREN);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_M_LPAREN9_RPAREN);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_LPAREN9_RPAREN);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_maj7);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_Maj7);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_MAJ7);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_M7);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_6);
      if (lookahead == '(') ADVANCE(30);
      if (lookahead == '9') ADVANCE(172);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_maj);
      if (lookahead == '(') ADVANCE(33);
      if (lookahead == '7') ADVANCE(178);
      if (lookahead == '9') ADVANCE(168);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_Maj);
      if (lookahead == '(') ADVANCE(32);
      if (lookahead == '7') ADVANCE(179);
      if (lookahead == '9') ADVANCE(169);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_MAJ);
      if (lookahead == '(') ADVANCE(31);
      if (lookahead == '7') ADVANCE(180);
      if (lookahead == '9') ADVANCE(170);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_M);
      if (lookahead == '(') ADVANCE(29);
      if (lookahead == '7') ADVANCE(181);
      if (lookahead == '9') ADVANCE(171);
      if (lookahead == 'A') ADVANCE(34);
      if (lookahead == 'I') ADVANCE(35);
      if (lookahead == 'a') ADVANCE(43);
      if (lookahead == 'i') ADVANCE(48);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_min7);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_Min7);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_MIN7);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_m7);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_DASH7);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_min);
      if (lookahead == '7') ADVANCE(187);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_Min);
      if (lookahead == '7') ADVANCE(188);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_MIN);
      if (lookahead == '7') ADVANCE(189);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_m);
      if (lookahead == '7') ADVANCE(190);
      if (lookahead == 'a') ADVANCE(44);
      if (lookahead == 'i') ADVANCE(49);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_7sus2);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_7sus4);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_sus4);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_sus2);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_dim);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_aug);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_13);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_11);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_92);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_7);
      if (lookahead == 's') ADVANCE(55);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_62);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      if (lookahead == ')') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(209);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      if (lookahead == ')') ADVANCE(210);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_LPARENb5_RPAREN);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_LPAREN_DASH5_RPAREN);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_LPAREN_PLUS5_RPAREN);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_LPAREN_POUND5_RPAREN);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_on);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_over);
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
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_mode_chord_over_bass_note] = ACTIONS(1),
    [sym_mode_slash_chord_inversion] = ACTIONS(1),
    [sym_mode_polychord] = ACTIONS(1),
    [sym_mode_root_inv] = ACTIONS(1),
    [sym_mode_1st_inv] = ACTIONS(1),
    [sym_mode_2nd_inv] = ACTIONS(1),
    [sym_mode_3rd_inv] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [sym_chord_inversion] = ACTIONS(1),
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
    [anon_sym_on] = ACTIONS(1),
    [anon_sym_over] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(36),
    [sym__event] = STATE(21),
    [sym_chord] = STATE(21),
    [sym_root] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_mode_chord_over_bass_note] = ACTIONS(5),
    [sym_mode_slash_chord_inversion] = ACTIONS(5),
    [sym_mode_polychord] = ACTIONS(5),
    [sym_mode_root_inv] = ACTIONS(5),
    [sym_mode_1st_inv] = ACTIONS(5),
    [sym_mode_2nd_inv] = ACTIONS(5),
    [sym_mode_3rd_inv] = ACTIONS(5),
    [sym_note] = ACTIONS(7),
  },
  [2] = {
    [sym_accidental] = STATE(7),
    [aux_sym_root_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_mode_chord_over_bass_note] = ACTIONS(9),
    [sym_mode_slash_chord_inversion] = ACTIONS(9),
    [sym_mode_polychord] = ACTIONS(9),
    [sym_mode_root_inv] = ACTIONS(9),
    [sym_mode_1st_inv] = ACTIONS(9),
    [sym_mode_2nd_inv] = ACTIONS(9),
    [sym_mode_3rd_inv] = ACTIONS(9),
    [anon_sym_DASH] = ACTIONS(11),
    [anon_sym_] = ACTIONS(9),
    [anon_sym_2] = ACTIONS(9),
    [sym_chord_inversion] = ACTIONS(9),
    [sym_note] = ACTIONS(11),
    [anon_sym_POUND] = ACTIONS(13),
    [anon_sym_3] = ACTIONS(13),
    [anon_sym_4] = ACTIONS(13),
    [anon_sym_b] = ACTIONS(13),
    [anon_sym_5] = ACTIONS(13),
    [aux_sym_quality_base_token1] = ACTIONS(9),
    [anon_sym_maj9] = ACTIONS(9),
    [anon_sym_Maj9] = ACTIONS(9),
    [anon_sym_MAJ9] = ACTIONS(9),
    [anon_sym_M9] = ACTIONS(9),
    [anon_sym_9] = ACTIONS(9),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(9),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(9),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(9),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(9),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(9),
    [anon_sym_maj7] = ACTIONS(9),
    [anon_sym_Maj7] = ACTIONS(9),
    [anon_sym_MAJ7] = ACTIONS(9),
    [anon_sym_M7] = ACTIONS(9),
    [anon_sym_6] = ACTIONS(11),
    [anon_sym_maj] = ACTIONS(11),
    [anon_sym_Maj] = ACTIONS(11),
    [anon_sym_MAJ] = ACTIONS(11),
    [anon_sym_M] = ACTIONS(11),
    [anon_sym_min7] = ACTIONS(9),
    [anon_sym_Min7] = ACTIONS(9),
    [anon_sym_MIN7] = ACTIONS(9),
    [anon_sym_m7] = ACTIONS(9),
    [anon_sym_DASH7] = ACTIONS(9),
    [anon_sym_min] = ACTIONS(11),
    [anon_sym_Min] = ACTIONS(11),
    [anon_sym_MIN] = ACTIONS(11),
    [anon_sym_m] = ACTIONS(11),
    [anon_sym_7sus2] = ACTIONS(9),
    [anon_sym_7sus4] = ACTIONS(9),
    [anon_sym_sus4] = ACTIONS(9),
    [anon_sym_sus2] = ACTIONS(9),
    [anon_sym_dim] = ACTIONS(9),
    [anon_sym_aug] = ACTIONS(9),
    [anon_sym_PLUS] = ACTIONS(9),
    [anon_sym_13] = ACTIONS(9),
    [anon_sym_11] = ACTIONS(9),
    [anon_sym_92] = ACTIONS(9),
    [anon_sym_7] = ACTIONS(11),
    [anon_sym_62] = ACTIONS(9),
    [aux_sym_quality_modifier_token1] = ACTIONS(9),
    [aux_sym_quality_modifier_token2] = ACTIONS(9),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(9),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(9),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(9),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(9),
    [anon_sym_SLASH] = ACTIONS(9),
    [anon_sym_on] = ACTIONS(9),
    [anon_sym_over] = ACTIONS(9),
  },
  [3] = {
    [sym_accidental] = STATE(7),
    [aux_sym_root_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(16),
    [sym_mode_chord_over_bass_note] = ACTIONS(16),
    [sym_mode_slash_chord_inversion] = ACTIONS(16),
    [sym_mode_polychord] = ACTIONS(16),
    [sym_mode_root_inv] = ACTIONS(16),
    [sym_mode_1st_inv] = ACTIONS(16),
    [sym_mode_2nd_inv] = ACTIONS(16),
    [sym_mode_3rd_inv] = ACTIONS(16),
    [anon_sym_DASH] = ACTIONS(18),
    [anon_sym_] = ACTIONS(16),
    [anon_sym_2] = ACTIONS(16),
    [sym_chord_inversion] = ACTIONS(16),
    [sym_note] = ACTIONS(18),
    [anon_sym_POUND] = ACTIONS(20),
    [anon_sym_3] = ACTIONS(20),
    [anon_sym_4] = ACTIONS(20),
    [anon_sym_b] = ACTIONS(20),
    [anon_sym_5] = ACTIONS(20),
    [aux_sym_quality_base_token1] = ACTIONS(16),
    [anon_sym_maj9] = ACTIONS(16),
    [anon_sym_Maj9] = ACTIONS(16),
    [anon_sym_MAJ9] = ACTIONS(16),
    [anon_sym_M9] = ACTIONS(16),
    [anon_sym_9] = ACTIONS(16),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(16),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(16),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(16),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(16),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(16),
    [anon_sym_maj7] = ACTIONS(16),
    [anon_sym_Maj7] = ACTIONS(16),
    [anon_sym_MAJ7] = ACTIONS(16),
    [anon_sym_M7] = ACTIONS(16),
    [anon_sym_6] = ACTIONS(18),
    [anon_sym_maj] = ACTIONS(18),
    [anon_sym_Maj] = ACTIONS(18),
    [anon_sym_MAJ] = ACTIONS(18),
    [anon_sym_M] = ACTIONS(18),
    [anon_sym_min7] = ACTIONS(16),
    [anon_sym_Min7] = ACTIONS(16),
    [anon_sym_MIN7] = ACTIONS(16),
    [anon_sym_m7] = ACTIONS(16),
    [anon_sym_DASH7] = ACTIONS(16),
    [anon_sym_min] = ACTIONS(18),
    [anon_sym_Min] = ACTIONS(18),
    [anon_sym_MIN] = ACTIONS(18),
    [anon_sym_m] = ACTIONS(18),
    [anon_sym_7sus2] = ACTIONS(16),
    [anon_sym_7sus4] = ACTIONS(16),
    [anon_sym_sus4] = ACTIONS(16),
    [anon_sym_sus2] = ACTIONS(16),
    [anon_sym_dim] = ACTIONS(16),
    [anon_sym_aug] = ACTIONS(16),
    [anon_sym_PLUS] = ACTIONS(16),
    [anon_sym_13] = ACTIONS(16),
    [anon_sym_11] = ACTIONS(16),
    [anon_sym_92] = ACTIONS(16),
    [anon_sym_7] = ACTIONS(18),
    [anon_sym_62] = ACTIONS(16),
    [aux_sym_quality_modifier_token1] = ACTIONS(16),
    [aux_sym_quality_modifier_token2] = ACTIONS(16),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(16),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(16),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(16),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(16),
    [anon_sym_SLASH] = ACTIONS(16),
    [anon_sym_on] = ACTIONS(16),
    [anon_sym_over] = ACTIONS(16),
  },
  [4] = {
    [sym_accidental] = STATE(7),
    [aux_sym_root_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(22),
    [sym_mode_chord_over_bass_note] = ACTIONS(22),
    [sym_mode_slash_chord_inversion] = ACTIONS(22),
    [sym_mode_polychord] = ACTIONS(22),
    [sym_mode_root_inv] = ACTIONS(22),
    [sym_mode_1st_inv] = ACTIONS(22),
    [sym_mode_2nd_inv] = ACTIONS(22),
    [sym_mode_3rd_inv] = ACTIONS(22),
    [anon_sym_DASH] = ACTIONS(24),
    [anon_sym_] = ACTIONS(22),
    [anon_sym_2] = ACTIONS(22),
    [sym_chord_inversion] = ACTIONS(22),
    [sym_note] = ACTIONS(24),
    [anon_sym_POUND] = ACTIONS(20),
    [anon_sym_3] = ACTIONS(20),
    [anon_sym_4] = ACTIONS(20),
    [anon_sym_b] = ACTIONS(20),
    [anon_sym_5] = ACTIONS(20),
    [aux_sym_quality_base_token1] = ACTIONS(22),
    [anon_sym_maj9] = ACTIONS(22),
    [anon_sym_Maj9] = ACTIONS(22),
    [anon_sym_MAJ9] = ACTIONS(22),
    [anon_sym_M9] = ACTIONS(22),
    [anon_sym_9] = ACTIONS(22),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(22),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(22),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(22),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(22),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(22),
    [anon_sym_maj7] = ACTIONS(22),
    [anon_sym_Maj7] = ACTIONS(22),
    [anon_sym_MAJ7] = ACTIONS(22),
    [anon_sym_M7] = ACTIONS(22),
    [anon_sym_6] = ACTIONS(24),
    [anon_sym_maj] = ACTIONS(24),
    [anon_sym_Maj] = ACTIONS(24),
    [anon_sym_MAJ] = ACTIONS(24),
    [anon_sym_M] = ACTIONS(24),
    [anon_sym_min7] = ACTIONS(22),
    [anon_sym_Min7] = ACTIONS(22),
    [anon_sym_MIN7] = ACTIONS(22),
    [anon_sym_m7] = ACTIONS(22),
    [anon_sym_DASH7] = ACTIONS(22),
    [anon_sym_min] = ACTIONS(24),
    [anon_sym_Min] = ACTIONS(24),
    [anon_sym_MIN] = ACTIONS(24),
    [anon_sym_m] = ACTIONS(24),
    [anon_sym_7sus2] = ACTIONS(22),
    [anon_sym_7sus4] = ACTIONS(22),
    [anon_sym_sus4] = ACTIONS(22),
    [anon_sym_sus2] = ACTIONS(22),
    [anon_sym_dim] = ACTIONS(22),
    [anon_sym_aug] = ACTIONS(22),
    [anon_sym_PLUS] = ACTIONS(22),
    [anon_sym_13] = ACTIONS(22),
    [anon_sym_11] = ACTIONS(22),
    [anon_sym_92] = ACTIONS(22),
    [anon_sym_7] = ACTIONS(24),
    [anon_sym_62] = ACTIONS(22),
    [aux_sym_quality_modifier_token1] = ACTIONS(22),
    [aux_sym_quality_modifier_token2] = ACTIONS(22),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(22),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(22),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(22),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(22),
    [anon_sym_SLASH] = ACTIONS(22),
    [anon_sym_on] = ACTIONS(22),
    [anon_sym_over] = ACTIONS(22),
  },
  [5] = {
    [sym_quality] = STATE(16),
    [sym_quality_base] = STATE(9),
    [sym_quality_modifier] = STATE(15),
    [sym_bass] = STATE(27),
    [sym_on_bass] = STATE(27),
    [aux_sym_quality_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(26),
    [sym_mode_chord_over_bass_note] = ACTIONS(26),
    [sym_mode_slash_chord_inversion] = ACTIONS(26),
    [sym_mode_polychord] = ACTIONS(26),
    [sym_mode_root_inv] = ACTIONS(26),
    [sym_mode_1st_inv] = ACTIONS(26),
    [sym_mode_2nd_inv] = ACTIONS(26),
    [sym_mode_3rd_inv] = ACTIONS(26),
    [anon_sym_DASH] = ACTIONS(28),
    [anon_sym_] = ACTIONS(26),
    [anon_sym_2] = ACTIONS(26),
    [sym_chord_inversion] = ACTIONS(31),
    [sym_note] = ACTIONS(33),
    [aux_sym_quality_base_token1] = ACTIONS(35),
    [anon_sym_maj9] = ACTIONS(35),
    [anon_sym_Maj9] = ACTIONS(35),
    [anon_sym_MAJ9] = ACTIONS(35),
    [anon_sym_M9] = ACTIONS(35),
    [anon_sym_9] = ACTIONS(35),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_maj7] = ACTIONS(35),
    [anon_sym_Maj7] = ACTIONS(35),
    [anon_sym_MAJ7] = ACTIONS(35),
    [anon_sym_M7] = ACTIONS(35),
    [anon_sym_6] = ACTIONS(37),
    [anon_sym_maj] = ACTIONS(37),
    [anon_sym_Maj] = ACTIONS(37),
    [anon_sym_MAJ] = ACTIONS(37),
    [anon_sym_M] = ACTIONS(37),
    [anon_sym_min7] = ACTIONS(35),
    [anon_sym_Min7] = ACTIONS(35),
    [anon_sym_MIN7] = ACTIONS(35),
    [anon_sym_m7] = ACTIONS(35),
    [anon_sym_DASH7] = ACTIONS(35),
    [anon_sym_min] = ACTIONS(37),
    [anon_sym_Min] = ACTIONS(37),
    [anon_sym_MIN] = ACTIONS(37),
    [anon_sym_m] = ACTIONS(37),
    [anon_sym_7sus2] = ACTIONS(35),
    [anon_sym_7sus4] = ACTIONS(35),
    [anon_sym_sus4] = ACTIONS(35),
    [anon_sym_sus2] = ACTIONS(35),
    [anon_sym_dim] = ACTIONS(35),
    [anon_sym_aug] = ACTIONS(35),
    [anon_sym_PLUS] = ACTIONS(35),
    [anon_sym_13] = ACTIONS(35),
    [anon_sym_11] = ACTIONS(35),
    [anon_sym_92] = ACTIONS(35),
    [anon_sym_7] = ACTIONS(37),
    [anon_sym_62] = ACTIONS(35),
    [aux_sym_quality_modifier_token1] = ACTIONS(39),
    [aux_sym_quality_modifier_token2] = ACTIONS(39),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(39),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(39),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(39),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(39),
    [anon_sym_SLASH] = ACTIONS(41),
    [anon_sym_on] = ACTIONS(43),
    [anon_sym_over] = ACTIONS(43),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_mode_chord_over_bass_note] = ACTIONS(45),
    [sym_mode_slash_chord_inversion] = ACTIONS(45),
    [sym_mode_polychord] = ACTIONS(45),
    [sym_mode_root_inv] = ACTIONS(45),
    [sym_mode_1st_inv] = ACTIONS(45),
    [sym_mode_2nd_inv] = ACTIONS(45),
    [sym_mode_3rd_inv] = ACTIONS(45),
    [anon_sym_DASH] = ACTIONS(47),
    [anon_sym_] = ACTIONS(45),
    [anon_sym_2] = ACTIONS(45),
    [sym_chord_inversion] = ACTIONS(45),
    [sym_note] = ACTIONS(47),
    [anon_sym_POUND] = ACTIONS(45),
    [anon_sym_3] = ACTIONS(45),
    [anon_sym_4] = ACTIONS(45),
    [anon_sym_b] = ACTIONS(45),
    [anon_sym_5] = ACTIONS(45),
    [aux_sym_quality_base_token1] = ACTIONS(45),
    [anon_sym_maj9] = ACTIONS(45),
    [anon_sym_Maj9] = ACTIONS(45),
    [anon_sym_MAJ9] = ACTIONS(45),
    [anon_sym_M9] = ACTIONS(45),
    [anon_sym_9] = ACTIONS(45),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(45),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(45),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(45),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(45),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(45),
    [anon_sym_maj7] = ACTIONS(45),
    [anon_sym_Maj7] = ACTIONS(45),
    [anon_sym_MAJ7] = ACTIONS(45),
    [anon_sym_M7] = ACTIONS(45),
    [anon_sym_6] = ACTIONS(47),
    [anon_sym_maj] = ACTIONS(47),
    [anon_sym_Maj] = ACTIONS(47),
    [anon_sym_MAJ] = ACTIONS(47),
    [anon_sym_M] = ACTIONS(47),
    [anon_sym_min7] = ACTIONS(45),
    [anon_sym_Min7] = ACTIONS(45),
    [anon_sym_MIN7] = ACTIONS(45),
    [anon_sym_m7] = ACTIONS(45),
    [anon_sym_DASH7] = ACTIONS(45),
    [anon_sym_min] = ACTIONS(47),
    [anon_sym_Min] = ACTIONS(47),
    [anon_sym_MIN] = ACTIONS(47),
    [anon_sym_m] = ACTIONS(47),
    [anon_sym_7sus2] = ACTIONS(45),
    [anon_sym_7sus4] = ACTIONS(45),
    [anon_sym_sus4] = ACTIONS(45),
    [anon_sym_sus2] = ACTIONS(45),
    [anon_sym_dim] = ACTIONS(45),
    [anon_sym_aug] = ACTIONS(45),
    [anon_sym_PLUS] = ACTIONS(45),
    [anon_sym_13] = ACTIONS(45),
    [anon_sym_11] = ACTIONS(45),
    [anon_sym_92] = ACTIONS(45),
    [anon_sym_7] = ACTIONS(47),
    [anon_sym_62] = ACTIONS(45),
    [aux_sym_quality_modifier_token1] = ACTIONS(45),
    [aux_sym_quality_modifier_token2] = ACTIONS(45),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(45),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(45),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(45),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(45),
    [anon_sym_SLASH] = ACTIONS(45),
    [anon_sym_on] = ACTIONS(45),
    [anon_sym_over] = ACTIONS(45),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(49),
    [sym_mode_chord_over_bass_note] = ACTIONS(49),
    [sym_mode_slash_chord_inversion] = ACTIONS(49),
    [sym_mode_polychord] = ACTIONS(49),
    [sym_mode_root_inv] = ACTIONS(49),
    [sym_mode_1st_inv] = ACTIONS(49),
    [sym_mode_2nd_inv] = ACTIONS(49),
    [sym_mode_3rd_inv] = ACTIONS(49),
    [anon_sym_DASH] = ACTIONS(51),
    [anon_sym_] = ACTIONS(49),
    [anon_sym_2] = ACTIONS(49),
    [sym_chord_inversion] = ACTIONS(49),
    [sym_note] = ACTIONS(51),
    [anon_sym_POUND] = ACTIONS(49),
    [anon_sym_3] = ACTIONS(49),
    [anon_sym_4] = ACTIONS(49),
    [anon_sym_b] = ACTIONS(49),
    [anon_sym_5] = ACTIONS(49),
    [aux_sym_quality_base_token1] = ACTIONS(49),
    [anon_sym_maj9] = ACTIONS(49),
    [anon_sym_Maj9] = ACTIONS(49),
    [anon_sym_MAJ9] = ACTIONS(49),
    [anon_sym_M9] = ACTIONS(49),
    [anon_sym_9] = ACTIONS(49),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(49),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(49),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(49),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(49),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(49),
    [anon_sym_maj7] = ACTIONS(49),
    [anon_sym_Maj7] = ACTIONS(49),
    [anon_sym_MAJ7] = ACTIONS(49),
    [anon_sym_M7] = ACTIONS(49),
    [anon_sym_6] = ACTIONS(51),
    [anon_sym_maj] = ACTIONS(51),
    [anon_sym_Maj] = ACTIONS(51),
    [anon_sym_MAJ] = ACTIONS(51),
    [anon_sym_M] = ACTIONS(51),
    [anon_sym_min7] = ACTIONS(49),
    [anon_sym_Min7] = ACTIONS(49),
    [anon_sym_MIN7] = ACTIONS(49),
    [anon_sym_m7] = ACTIONS(49),
    [anon_sym_DASH7] = ACTIONS(49),
    [anon_sym_min] = ACTIONS(51),
    [anon_sym_Min] = ACTIONS(51),
    [anon_sym_MIN] = ACTIONS(51),
    [anon_sym_m] = ACTIONS(51),
    [anon_sym_7sus2] = ACTIONS(49),
    [anon_sym_7sus4] = ACTIONS(49),
    [anon_sym_sus4] = ACTIONS(49),
    [anon_sym_sus2] = ACTIONS(49),
    [anon_sym_dim] = ACTIONS(49),
    [anon_sym_aug] = ACTIONS(49),
    [anon_sym_PLUS] = ACTIONS(49),
    [anon_sym_13] = ACTIONS(49),
    [anon_sym_11] = ACTIONS(49),
    [anon_sym_92] = ACTIONS(49),
    [anon_sym_7] = ACTIONS(51),
    [anon_sym_62] = ACTIONS(49),
    [aux_sym_quality_modifier_token1] = ACTIONS(49),
    [aux_sym_quality_modifier_token2] = ACTIONS(49),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(49),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(49),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(49),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(49),
    [anon_sym_SLASH] = ACTIONS(49),
    [anon_sym_on] = ACTIONS(49),
    [anon_sym_over] = ACTIONS(49),
  },
  [8] = {
    [sym_quality] = STATE(24),
    [sym_quality_base] = STATE(9),
    [sym_quality_modifier] = STATE(15),
    [aux_sym_quality_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(53),
    [sym_mode_chord_over_bass_note] = ACTIONS(53),
    [sym_mode_slash_chord_inversion] = ACTIONS(53),
    [sym_mode_polychord] = ACTIONS(53),
    [sym_mode_root_inv] = ACTIONS(53),
    [sym_mode_1st_inv] = ACTIONS(53),
    [sym_mode_2nd_inv] = ACTIONS(53),
    [sym_mode_3rd_inv] = ACTIONS(53),
    [anon_sym_DASH] = ACTIONS(55),
    [anon_sym_] = ACTIONS(53),
    [anon_sym_2] = ACTIONS(53),
    [sym_chord_inversion] = ACTIONS(58),
    [sym_note] = ACTIONS(60),
    [aux_sym_quality_base_token1] = ACTIONS(35),
    [anon_sym_maj9] = ACTIONS(35),
    [anon_sym_Maj9] = ACTIONS(35),
    [anon_sym_MAJ9] = ACTIONS(35),
    [anon_sym_M9] = ACTIONS(35),
    [anon_sym_9] = ACTIONS(35),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(35),
    [anon_sym_maj7] = ACTIONS(35),
    [anon_sym_Maj7] = ACTIONS(35),
    [anon_sym_MAJ7] = ACTIONS(35),
    [anon_sym_M7] = ACTIONS(35),
    [anon_sym_6] = ACTIONS(37),
    [anon_sym_maj] = ACTIONS(37),
    [anon_sym_Maj] = ACTIONS(37),
    [anon_sym_MAJ] = ACTIONS(37),
    [anon_sym_M] = ACTIONS(37),
    [anon_sym_min7] = ACTIONS(35),
    [anon_sym_Min7] = ACTIONS(35),
    [anon_sym_MIN7] = ACTIONS(35),
    [anon_sym_m7] = ACTIONS(35),
    [anon_sym_DASH7] = ACTIONS(35),
    [anon_sym_min] = ACTIONS(37),
    [anon_sym_Min] = ACTIONS(37),
    [anon_sym_MIN] = ACTIONS(37),
    [anon_sym_m] = ACTIONS(37),
    [anon_sym_7sus2] = ACTIONS(35),
    [anon_sym_7sus4] = ACTIONS(35),
    [anon_sym_sus4] = ACTIONS(35),
    [anon_sym_sus2] = ACTIONS(35),
    [anon_sym_dim] = ACTIONS(35),
    [anon_sym_aug] = ACTIONS(35),
    [anon_sym_PLUS] = ACTIONS(35),
    [anon_sym_13] = ACTIONS(35),
    [anon_sym_11] = ACTIONS(35),
    [anon_sym_92] = ACTIONS(35),
    [anon_sym_7] = ACTIONS(37),
    [anon_sym_62] = ACTIONS(35),
    [aux_sym_quality_modifier_token1] = ACTIONS(39),
    [aux_sym_quality_modifier_token2] = ACTIONS(39),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(39),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(39),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(39),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(39),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(64), 1,
      sym_note,
    STATE(10), 1,
      aux_sym_quality_repeat1,
    STATE(15), 1,
      sym_quality_modifier,
    ACTIONS(39), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(62), 15,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      anon_sym_SLASH,
      anon_sym_on,
      anon_sym_over,
  [35] = 5,
    ACTIONS(68), 1,
      sym_note,
    STATE(12), 1,
      aux_sym_quality_repeat1,
    STATE(15), 1,
      sym_quality_modifier,
    ACTIONS(39), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(66), 15,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      anon_sym_SLASH,
      anon_sym_on,
      anon_sym_over,
  [70] = 5,
    ACTIONS(72), 1,
      sym_note,
    STATE(12), 1,
      aux_sym_quality_repeat1,
    STATE(15), 1,
      sym_quality_modifier,
    ACTIONS(39), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(70), 15,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      anon_sym_SLASH,
      anon_sym_on,
      anon_sym_over,
  [105] = 5,
    ACTIONS(76), 1,
      sym_note,
    STATE(12), 1,
      aux_sym_quality_repeat1,
    STATE(15), 1,
      sym_quality_modifier,
    ACTIONS(78), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(74), 15,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      anon_sym_SLASH,
      anon_sym_on,
      anon_sym_over,
  [140] = 2,
    ACTIONS(83), 1,
      sym_note,
    ACTIONS(81), 21,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
      anon_sym_SLASH,
      anon_sym_on,
      anon_sym_over,
  [167] = 2,
    ACTIONS(87), 1,
      sym_note,
    ACTIONS(85), 21,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
      anon_sym_SLASH,
      anon_sym_on,
      anon_sym_over,
  [194] = 2,
    ACTIONS(91), 1,
      sym_note,
    ACTIONS(89), 21,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
      anon_sym_SLASH,
      anon_sym_on,
      anon_sym_over,
  [221] = 6,
    ACTIONS(41), 1,
      anon_sym_SLASH,
    ACTIONS(95), 1,
      sym_chord_inversion,
    ACTIONS(97), 1,
      sym_note,
    ACTIONS(43), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(30), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(93), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [252] = 7,
    ACTIONS(7), 1,
      sym_note,
    ACTIONS(99), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      sym_root,
    STATE(34), 1,
      sym_separator,
    ACTIONS(103), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(20), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(101), 7,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
  [284] = 5,
    ACTIONS(41), 1,
      anon_sym_SLASH,
    ACTIONS(107), 1,
      sym_note,
    ACTIONS(43), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(29), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(105), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [312] = 5,
    ACTIONS(41), 1,
      anon_sym_SLASH,
    ACTIONS(111), 1,
      sym_note,
    ACTIONS(43), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(32), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(109), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [340] = 7,
    ACTIONS(113), 1,
      ts_builtin_sym_end,
    ACTIONS(121), 1,
      sym_note,
    STATE(5), 1,
      sym_root,
    STATE(34), 1,
      sym_separator,
    ACTIONS(118), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(20), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(115), 7,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
  [372] = 7,
    ACTIONS(7), 1,
      sym_note,
    ACTIONS(124), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      sym_root,
    STATE(34), 1,
      sym_separator,
    ACTIONS(103), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(17), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(126), 7,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
  [404] = 4,
    ACTIONS(7), 1,
      sym_note,
    STATE(8), 1,
      sym_root,
    STATE(25), 1,
      sym__lower,
    ACTIONS(128), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [427] = 4,
    ACTIONS(7), 1,
      sym_note,
    STATE(8), 1,
      sym_root,
    STATE(28), 1,
      sym__lower,
    ACTIONS(130), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [450] = 3,
    ACTIONS(134), 1,
      sym_chord_inversion,
    ACTIONS(136), 1,
      sym_note,
    ACTIONS(132), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [470] = 2,
    ACTIONS(140), 1,
      sym_note,
    ACTIONS(138), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [487] = 2,
    ACTIONS(142), 1,
      sym_note,
    ACTIONS(113), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [504] = 2,
    ACTIONS(146), 1,
      sym_note,
    ACTIONS(144), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [521] = 2,
    ACTIONS(150), 1,
      sym_note,
    ACTIONS(148), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [538] = 2,
    ACTIONS(154), 1,
      sym_note,
    ACTIONS(152), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [555] = 2,
    ACTIONS(158), 1,
      sym_note,
    ACTIONS(156), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [572] = 2,
    ACTIONS(162), 1,
      sym_note,
    ACTIONS(160), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [589] = 2,
    ACTIONS(166), 1,
      sym_note,
    ACTIONS(164), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [606] = 2,
    ACTIONS(170), 1,
      sym_note,
    ACTIONS(168), 11,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [623] = 4,
    ACTIONS(7), 1,
      sym_note,
    STATE(5), 1,
      sym_root,
    STATE(26), 2,
      sym__event,
      sym_chord,
    ACTIONS(172), 7,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
  [643] = 2,
    ACTIONS(176), 1,
      sym_note,
    ACTIONS(174), 7,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
  [656] = 1,
    ACTIONS(178), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 35,
  [SMALL_STATE(11)] = 70,
  [SMALL_STATE(12)] = 105,
  [SMALL_STATE(13)] = 140,
  [SMALL_STATE(14)] = 167,
  [SMALL_STATE(15)] = 194,
  [SMALL_STATE(16)] = 221,
  [SMALL_STATE(17)] = 252,
  [SMALL_STATE(18)] = 284,
  [SMALL_STATE(19)] = 312,
  [SMALL_STATE(20)] = 340,
  [SMALL_STATE(21)] = 372,
  [SMALL_STATE(22)] = 404,
  [SMALL_STATE(23)] = 427,
  [SMALL_STATE(24)] = 450,
  [SMALL_STATE(25)] = 470,
  [SMALL_STATE(26)] = 487,
  [SMALL_STATE(27)] = 504,
  [SMALL_STATE(28)] = 521,
  [SMALL_STATE(29)] = 538,
  [SMALL_STATE(30)] = 555,
  [SMALL_STATE(31)] = 572,
  [SMALL_STATE(32)] = 589,
  [SMALL_STATE(33)] = 606,
  [SMALL_STATE(34)] = 623,
  [SMALL_STATE(35)] = 643,
  [SMALL_STATE(36)] = 656,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 11),
  [11] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 11),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 11), SHIFT_REPEAT(6),
  [16] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1, .production_id = 1),
  [18] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 1, .production_id = 1),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 2, .production_id = 4),
  [24] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 2, .production_id = 4),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 1, .production_id = 2),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_chord, 1, .production_id = 2), SHIFT(13),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 1, .production_id = 2),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accidental, 1),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accidental, 1),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 1, .production_id = 3),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 1, .production_id = 3),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 1, .production_id = 2),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym__lower, 1, .production_id = 2), SHIFT(13),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [60] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 1, .production_id = 2),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 7),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 1, .production_id = 7),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 2, .production_id = 16),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 2, .production_id = 16),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 10),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 1, .production_id = 10),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 17),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 17),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 17), SHIFT_REPEAT(14),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_base, 1),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality_base, 1),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_modifier, 1),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality_modifier, 1),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 1, .production_id = 8),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quality_repeat1, 1, .production_id = 8),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 6),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 6),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 5),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 5),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 14),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 14),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(20),
  [118] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(35),
  [121] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 1),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_on_bass, 1),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 6),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 6),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 2, .production_id = 13),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bass, 2, .production_id = 13),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 9),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 9),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_on_bass, 2, .production_id = 13),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_on_bass, 2, .production_id = 13),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 12),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 12),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 15),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 15),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 5),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 5),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 18),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 18),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 14),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 14),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_separator, 1, .dynamic_precedence = 1),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_separator, 1, .dynamic_precedence = 1),
  [178] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
