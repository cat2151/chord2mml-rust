#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 49
#define LARGE_STATE_COUNT 9
#define SYMBOL_COUNT 96
#define ALIAS_COUNT 0
#define TOKEN_COUNT 81
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 27

enum {
  sym_mode_chord_over_bass_note = 1,
  sym_mode_slash_chord_inversion = 2,
  sym_mode_polychord = 3,
  sym_mode_root_inv = 4,
  sym_mode_1st_inv = 5,
  sym_mode_2nd_inv = 6,
  sym_mode_3rd_inv = 7,
  sym_mode_close = 8,
  sym_mode_drop2 = 9,
  sym_mode_drop4 = 10,
  sym_mode_drop2and4 = 11,
  sym_mode_no_bass = 12,
  sym_mode_bass_is_root = 13,
  sym_octave_up = 14,
  sym_octave_up_upper = 15,
  sym_octave_up_lower = 16,
  sym_octave_down = 17,
  sym_octave_down_upper = 18,
  sym_octave_down_lower = 19,
  anon_sym_DASH = 20,
  anon_sym_ = 21,
  anon_sym_2 = 22,
  sym_chord_inversion = 23,
  sym_octave_offset = 24,
  sym_note = 25,
  anon_sym_POUND = 26,
  anon_sym_3 = 27,
  anon_sym_4 = 28,
  anon_sym_b = 29,
  anon_sym_5 = 30,
  aux_sym_quality_base_token1 = 31,
  anon_sym_maj9 = 32,
  anon_sym_Maj9 = 33,
  anon_sym_MAJ9 = 34,
  anon_sym_M9 = 35,
  anon_sym_9 = 36,
  anon_sym_maj_LPAREN9_RPAREN = 37,
  anon_sym_Maj_LPAREN9_RPAREN = 38,
  anon_sym_MAJ_LPAREN9_RPAREN = 39,
  anon_sym_M_LPAREN9_RPAREN = 40,
  anon_sym_LPAREN9_RPAREN = 41,
  anon_sym_maj7 = 42,
  anon_sym_Maj7 = 43,
  anon_sym_MAJ7 = 44,
  anon_sym_M7 = 45,
  anon_sym_6 = 46,
  anon_sym_maj = 47,
  anon_sym_Maj = 48,
  anon_sym_MAJ = 49,
  anon_sym_M = 50,
  anon_sym_min7 = 51,
  anon_sym_Min7 = 52,
  anon_sym_MIN7 = 53,
  anon_sym_m7 = 54,
  anon_sym_DASH7 = 55,
  anon_sym_min = 56,
  anon_sym_Min = 57,
  anon_sym_MIN = 58,
  anon_sym_m = 59,
  anon_sym_7sus2 = 60,
  anon_sym_7sus4 = 61,
  anon_sym_sus4 = 62,
  anon_sym_sus2 = 63,
  anon_sym_dim = 64,
  anon_sym_aug = 65,
  anon_sym_PLUS = 66,
  anon_sym_13 = 67,
  anon_sym_11 = 68,
  anon_sym_92 = 69,
  anon_sym_7 = 70,
  anon_sym_62 = 71,
  aux_sym_quality_modifier_token1 = 72,
  aux_sym_quality_modifier_token2 = 73,
  anon_sym_LPARENb5_RPAREN = 74,
  anon_sym_LPAREN_DASH5_RPAREN = 75,
  anon_sym_LPAREN_PLUS5_RPAREN = 76,
  anon_sym_LPAREN_POUND5_RPAREN = 77,
  anon_sym_SLASH = 78,
  anon_sym_on = 79,
  anon_sym_over = 80,
  sym_source_file = 81,
  sym__event = 82,
  sym_separator = 83,
  sym_chord = 84,
  sym_root = 85,
  sym_accidental = 86,
  sym_quality = 87,
  sym_quality_base = 88,
  sym_quality_modifier = 89,
  sym__lower = 90,
  sym_bass = 91,
  sym_on_bass = 92,
  aux_sym_source_file_repeat1 = 93,
  aux_sym_root_repeat1 = 94,
  aux_sym_quality_repeat1 = 95,
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
  [sym_mode_close] = "mode_close",
  [sym_mode_drop2] = "mode_drop2",
  [sym_mode_drop4] = "mode_drop4",
  [sym_mode_drop2and4] = "mode_drop2and4",
  [sym_mode_no_bass] = "mode_no_bass",
  [sym_mode_bass_is_root] = "mode_bass_is_root",
  [sym_octave_up] = "octave_up",
  [sym_octave_up_upper] = "octave_up_upper",
  [sym_octave_up_lower] = "octave_up_lower",
  [sym_octave_down] = "octave_down",
  [sym_octave_down_upper] = "octave_down_upper",
  [sym_octave_down_lower] = "octave_down_lower",
  [anon_sym_DASH] = "-",
  [anon_sym_] = "→",
  [anon_sym_2] = "・",
  [sym_chord_inversion] = "chord_inversion",
  [sym_octave_offset] = "octave_offset",
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
  [sym_mode_close] = sym_mode_close,
  [sym_mode_drop2] = sym_mode_drop2,
  [sym_mode_drop4] = sym_mode_drop4,
  [sym_mode_drop2and4] = sym_mode_drop2and4,
  [sym_mode_no_bass] = sym_mode_no_bass,
  [sym_mode_bass_is_root] = sym_mode_bass_is_root,
  [sym_octave_up] = sym_octave_up,
  [sym_octave_up_upper] = sym_octave_up_upper,
  [sym_octave_up_lower] = sym_octave_up_lower,
  [sym_octave_down] = sym_octave_down,
  [sym_octave_down_upper] = sym_octave_down_upper,
  [sym_octave_down_lower] = sym_octave_down_lower,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_] = anon_sym_,
  [anon_sym_2] = anon_sym_2,
  [sym_chord_inversion] = sym_chord_inversion,
  [sym_octave_offset] = sym_octave_offset,
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
  [sym_mode_close] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_drop2] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_drop4] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_drop2and4] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_no_bass] = {
    .visible = true,
    .named = true,
  },
  [sym_mode_bass_is_root] = {
    .visible = true,
    .named = true,
  },
  [sym_octave_up] = {
    .visible = true,
    .named = true,
  },
  [sym_octave_up_upper] = {
    .visible = true,
    .named = true,
  },
  [sym_octave_up_lower] = {
    .visible = true,
    .named = true,
  },
  [sym_octave_down] = {
    .visible = true,
    .named = true,
  },
  [sym_octave_down_upper] = {
    .visible = true,
    .named = true,
  },
  [sym_octave_down_lower] = {
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
  [sym_octave_offset] = {
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
  field_octave = 7,
  field_quality = 8,
  field_root = 9,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_accidental] = "accidental",
  [field_base] = "base",
  [field_bass] = "bass",
  [field_inversion] = "inversion",
  [field_modifier] = "modifier",
  [field_note] = "note",
  [field_octave] = "octave",
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
  [7] = {.index = 9, .length = 2},
  [8] = {.index = 11, .length = 1},
  [9] = {.index = 12, .length = 1},
  [10] = {.index = 13, .length = 2},
  [11] = {.index = 15, .length = 1},
  [12] = {.index = 16, .length = 2},
  [13] = {.index = 18, .length = 3},
  [14] = {.index = 21, .length = 3},
  [15] = {.index = 24, .length = 3},
  [16] = {.index = 27, .length = 4},
  [17] = {.index = 31, .length = 3},
  [18] = {.index = 34, .length = 3},
  [19] = {.index = 37, .length = 3},
  [20] = {.index = 40, .length = 2},
  [21] = {.index = 42, .length = 2},
  [22] = {.index = 44, .length = 4},
  [23] = {.index = 48, .length = 4},
  [24] = {.index = 52, .length = 4},
  [25] = {.index = 56, .length = 4},
  [26] = {.index = 60, .length = 5},
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
    {field_octave, 1},
    {field_root, 0},
  [9] =
    {field_quality, 1},
    {field_root, 0},
  [11] =
    {field_base, 0},
  [12] =
    {field_modifier, 0},
  [13] =
    {field_bass, 1},
    {field_root, 0},
  [15] =
    {field_modifier, 0, .inherited = true},
  [16] =
    {field_accidental, 0, .inherited = true},
    {field_accidental, 1, .inherited = true},
  [18] =
    {field_inversion, 1},
    {field_octave, 2},
    {field_root, 0},
  [21] =
    {field_bass, 2},
    {field_inversion, 1},
    {field_root, 0},
  [24] =
    {field_bass, 2},
    {field_octave, 1},
    {field_root, 0},
  [27] =
    {field_inversion, 1, .inherited = true},
    {field_octave, 1, .inherited = true},
    {field_quality, 1, .inherited = true},
    {field_root, 1, .inherited = true},
  [31] =
    {field_inversion, 2},
    {field_quality, 1},
    {field_root, 0},
  [34] =
    {field_octave, 2},
    {field_quality, 1},
    {field_root, 0},
  [37] =
    {field_bass, 2},
    {field_quality, 1},
    {field_root, 0},
  [40] =
    {field_base, 0},
    {field_modifier, 1, .inherited = true},
  [42] =
    {field_modifier, 0, .inherited = true},
    {field_modifier, 1, .inherited = true},
  [44] =
    {field_bass, 3},
    {field_inversion, 1},
    {field_octave, 2},
    {field_root, 0},
  [48] =
    {field_inversion, 2},
    {field_octave, 3},
    {field_quality, 1},
    {field_root, 0},
  [52] =
    {field_bass, 3},
    {field_inversion, 2},
    {field_quality, 1},
    {field_root, 0},
  [56] =
    {field_bass, 3},
    {field_octave, 2},
    {field_quality, 1},
    {field_root, 0},
  [60] =
    {field_bass, 4},
    {field_inversion, 2},
    {field_octave, 3},
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
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(209);
      if (lookahead == '#') ADVANCE(264);
      if (lookahead == '\'') ADVANCE(258);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == '+') ADVANCE(304);
      if (lookahead == ',') ADVANCE(259);
      if (lookahead == '-') ADVANCE(254);
      if (lookahead == '/') ADVANCE(318);
      if (lookahead == '1') ADVANCE(31);
      if (lookahead == '2') ADVANCE(120);
      if (lookahead == '3') ADVANCE(166);
      if (lookahead == '4') ADVANCE(30);
      if (lookahead == '6') ADVANCE(309);
      if (lookahead == '7') ADVANCE(308);
      if (lookahead == '9') ADVANCE(307);
      if (lookahead == 'B') ADVANCE(261);
      if (lookahead == 'C') ADVANCE(262);
      if (lookahead == 'D') ADVANCE(263);
      if (lookahead == 'M') ADVANCE(288);
      if (lookahead == 'O') ADVANCE(79);
      if (lookahead == 'S') ADVANCE(116);
      if (lookahead == '^') ADVANCE(206);
      if (lookahead == 'a') ADVANCE(49);
      if (lookahead == 'b') ADVANCE(267);
      if (lookahead == 'c') ADVANCE(102);
      if (lookahead == 'd') ADVANCE(52);
      if (lookahead == 'm') ADVANCE(297);
      if (lookahead == 'o') ADVANCE(56);
      if (lookahead == 's') ADVANCE(65);
      if (lookahead == 8594) ADVANCE(255);
      if (lookahead == 9651) ADVANCE(284);
      if (lookahead == 9837) ADVANCE(268);
      if (lookahead == 9839) ADVANCE(266);
      if (lookahead == 12539) ADVANCE(256);
      if (lookahead == 65283) ADVANCE(265);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(134);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(136);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(140);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(151);
      if (('A' <= lookahead && lookahead <= 'G')) ADVANCE(260);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(77);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(107);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(115);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(88);
      if (lookahead == '-') ADVANCE(88);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(81);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(184);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(165);
      END_STATE();
    case 8:
      if (lookahead == ' ') ADVANCE(165);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(7);
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(175);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(146);
      END_STATE();
    case 11:
      if (lookahead == ' ') ADVANCE(132);
      END_STATE();
    case 12:
      if (lookahead == ' ') ADVANCE(108);
      END_STATE();
    case 13:
      if (lookahead == ' ') ADVANCE(90);
      if (lookahead == '-') ADVANCE(90);
      END_STATE();
    case 14:
      if (lookahead == ' ') ADVANCE(109);
      END_STATE();
    case 15:
      if (lookahead == ' ') ADVANCE(110);
      END_STATE();
    case 16:
      if (lookahead == ' ') ADVANCE(113);
      END_STATE();
    case 17:
      if (lookahead == ' ') ADVANCE(78);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(36);
      if (lookahead == '+') ADVANCE(37);
      if (lookahead == '-') ADVANCE(38);
      if (lookahead == 'a') ADVANCE(48);
      if (lookahead == 'b') ADVANCE(39);
      if (lookahead == 'o') ADVANCE(57);
      END_STATE();
    case 19:
      if (lookahead == ')') ADVANCE(317);
      END_STATE();
    case 20:
      if (lookahead == ')') ADVANCE(316);
      END_STATE();
    case 21:
      if (lookahead == ')') ADVANCE(315);
      END_STATE();
    case 22:
      if (lookahead == ')') ADVANCE(314);
      END_STATE();
    case 23:
      if (lookahead == ')') ADVANCE(278);
      END_STATE();
    case 24:
      if (lookahead == ')') ADVANCE(279);
      END_STATE();
    case 25:
      if (lookahead == ')') ADVANCE(277);
      END_STATE();
    case 26:
      if (lookahead == ')') ADVANCE(276);
      END_STATE();
    case 27:
      if (lookahead == ')') ADVANCE(275);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(35);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(34);
      if (lookahead == '2') ADVANCE(233);
      if (lookahead == '4') ADVANCE(235);
      END_STATE();
    case 30:
      if (lookahead == '.') ADVANCE(207);
      END_STATE();
    case 31:
      if (lookahead == '1') ADVANCE(306);
      if (lookahead == '3') ADVANCE(305);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(182);
      END_STATE();
    case 32:
      if (lookahead == '2') ADVANCE(301);
      if (lookahead == '4') ADVANCE(300);
      END_STATE();
    case 33:
      if (lookahead == '2') ADVANCE(298);
      if (lookahead == '4') ADVANCE(299);
      END_STATE();
    case 34:
      if (lookahead == '2') ADVANCE(231);
      if (lookahead == '4') ADVANCE(235);
      END_STATE();
    case 35:
      if (lookahead == '4') ADVANCE(237);
      END_STATE();
    case 36:
      if (lookahead == '5') ADVANCE(19);
      END_STATE();
    case 37:
      if (lookahead == '5') ADVANCE(20);
      END_STATE();
    case 38:
      if (lookahead == '5') ADVANCE(21);
      END_STATE();
    case 39:
      if (lookahead == '5') ADVANCE(22);
      END_STATE();
    case 40:
      if (lookahead == '9') ADVANCE(23);
      END_STATE();
    case 41:
      if (lookahead == '9') ADVANCE(24);
      END_STATE();
    case 42:
      if (lookahead == '9') ADVANCE(25);
      END_STATE();
    case 43:
      if (lookahead == '9') ADVANCE(26);
      END_STATE();
    case 44:
      if (lookahead == '9') ADVANCE(27);
      END_STATE();
    case 45:
      if (lookahead == 'J') ADVANCE(287);
      END_STATE();
    case 46:
      if (lookahead == 'N') ADVANCE(296);
      END_STATE();
    case 47:
      if (lookahead == 'd') ADVANCE(208);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(47);
      END_STATE();
    case 49:
      if (lookahead == 'd') ADVANCE(47);
      if (lookahead == 'u') ADVANCE(51);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(61);
      END_STATE();
    case 51:
      if (lookahead == 'g') ADVANCE(303);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(58);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(137);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(64);
      END_STATE();
    case 54:
      if (lookahead == 'j') ADVANCE(286);
      END_STATE();
    case 55:
      if (lookahead == 'j') ADVANCE(285);
      END_STATE();
    case 56:
      if (lookahead == 'm') ADVANCE(53);
      if (lookahead == 'n') ADVANCE(319);
      if (lookahead == 'v') ADVANCE(50);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(181);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(97);
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(313);
      END_STATE();
    case 57:
      if (lookahead == 'm') ADVANCE(53);
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(313);
      END_STATE();
    case 58:
      if (lookahead == 'm') ADVANCE(302);
      END_STATE();
    case 59:
      if (lookahead == 'n') ADVANCE(295);
      END_STATE();
    case 60:
      if (lookahead == 'n') ADVANCE(294);
      END_STATE();
    case 61:
      if (lookahead == 'r') ADVANCE(320);
      END_STATE();
    case 62:
      if (lookahead == 's') ADVANCE(32);
      END_STATE();
    case 63:
      if (lookahead == 's') ADVANCE(33);
      END_STATE();
    case 64:
      if (lookahead == 't') ADVANCE(205);
      END_STATE();
    case 65:
      if (lookahead == 'u') ADVANCE(62);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(70);
      END_STATE();
    case 66:
      if (lookahead == 'u') ADVANCE(63);
      END_STATE();
    case 67:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(196);
      END_STATE();
    case 68:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(203);
      END_STATE();
    case 69:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(83);
      END_STATE();
    case 70:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(169);
      END_STATE();
    case 71:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(156);
      END_STATE();
    case 72:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(86);
      END_STATE();
    case 73:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(176);
      END_STATE();
    case 74:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(128);
      END_STATE();
    case 75:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(179);
      END_STATE();
    case 76:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(199);
      END_STATE();
    case 77:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(73);
      END_STATE();
    case 78:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(75);
      END_STATE();
    case 79:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(181);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(97);
      END_STATE();
    case 80:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(183);
      END_STATE();
    case 81:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(106);
      END_STATE();
    case 82:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(189);
      END_STATE();
    case 83:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(216);
      END_STATE();
    case 84:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(35);
      END_STATE();
    case 85:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(28);
      END_STATE();
    case 86:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(232);
      END_STATE();
    case 87:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(10);
      END_STATE();
    case 88:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(135);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(153);
      END_STATE();
    case 89:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(12);
      END_STATE();
    case 90:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(147);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(154);
      END_STATE();
    case 91:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(14);
      END_STATE();
    case 92:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(16);
      END_STATE();
    case 93:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(228);
      END_STATE();
    case 94:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(4);
      END_STATE();
    case 95:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(215);
      END_STATE();
    case 96:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(211);
      END_STATE();
    case 97:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(129);
      END_STATE();
    case 98:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(162);
      END_STATE();
    case 99:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(168);
      END_STATE();
    case 100:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(161);
      END_STATE();
    case 101:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 102:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(148);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(138);
      END_STATE();
    case 103:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(71);
      END_STATE();
    case 104:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(5);
      END_STATE();
    case 105:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(145);
      END_STATE();
    case 106:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(150);
      END_STATE();
    case 107:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(125);
      END_STATE();
    case 108:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(127);
      END_STATE();
    case 109:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(130);
      END_STATE();
    case 110:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(131);
      END_STATE();
    case 111:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(72);
      END_STATE();
    case 112:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(69);
      END_STATE();
    case 113:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(133);
      END_STATE();
    case 114:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(144);
      END_STATE();
    case 115:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(177);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(118);
      END_STATE();
    case 116:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(70);
      END_STATE();
    case 117:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(202);
      END_STATE();
    case 118:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(68);
      END_STATE();
    case 119:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(142);
      END_STATE();
    case 120:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(89);
      END_STATE();
    case 121:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(249);
      END_STATE();
    case 122:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(253);
      END_STATE();
    case 123:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(213);
      END_STATE();
    case 124:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(84);
      END_STATE();
    case 125:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(192);
      END_STATE();
    case 126:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(204);
      END_STATE();
    case 127:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(193);
      END_STATE();
    case 128:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(85);
      END_STATE();
    case 129:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(6);
      END_STATE();
    case 130:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(194);
      END_STATE();
    case 131:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(195);
      END_STATE();
    case 132:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(141);
      END_STATE();
    case 133:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(198);
      END_STATE();
    case 134:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(1);
      END_STATE();
    case 135:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(200);
      END_STATE();
    case 136:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(117);
      END_STATE();
    case 137:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(152);
      END_STATE();
    case 138:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(172);
      END_STATE();
    case 139:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(180);
      END_STATE();
    case 140:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(149);
      END_STATE();
    case 141:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(186);
      END_STATE();
    case 142:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(126);
      END_STATE();
    case 143:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(139);
      END_STATE();
    case 144:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(123);
      END_STATE();
    case 145:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(159);
      END_STATE();
    case 146:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(197);
      END_STATE();
    case 147:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(201);
      END_STATE();
    case 148:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(163);
      END_STATE();
    case 149:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(188);
      END_STATE();
    case 150:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(167);
      END_STATE();
    case 151:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(155);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(218);
      END_STATE();
    case 152:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(29);
      END_STATE();
    case 153:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(243);
      END_STATE();
    case 154:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(247);
      END_STATE();
    case 155:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(98);
      END_STATE();
    case 156:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(119);
      END_STATE();
    case 157:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(191);
      END_STATE();
    case 158:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(111);
      END_STATE();
    case 159:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(83);
      END_STATE();
    case 160:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(95);
      END_STATE();
    case 161:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(174);
      END_STATE();
    case 162:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(9);
      END_STATE();
    case 163:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(87);
      END_STATE();
    case 164:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(112);
      END_STATE();
    case 165:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(143);
      END_STATE();
    case 166:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(91);
      END_STATE();
    case 167:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(92);
      END_STATE();
    case 168:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 169:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(104);
      END_STATE();
    case 170:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(239);
      END_STATE();
    case 171:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(173);
      END_STATE();
    case 172:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(93);
      END_STATE();
    case 173:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(3);
      END_STATE();
    case 174:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(114);
      END_STATE();
    case 175:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(185);
      END_STATE();
    case 176:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(170);
      END_STATE();
    case 177:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(7);
      END_STATE();
    case 178:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(11);
      END_STATE();
    case 179:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(178);
      END_STATE();
    case 180:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(241);
      END_STATE();
    case 181:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(67);
      END_STATE();
    case 182:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(2);
      END_STATE();
    case 183:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(190);
      END_STATE();
    case 184:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(158);
      END_STATE();
    case 185:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(157);
      END_STATE();
    case 186:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(96);
      END_STATE();
    case 187:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(164);
      END_STATE();
    case 188:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(15);
      END_STATE();
    case 189:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(76);
      END_STATE();
    case 190:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(160);
      END_STATE();
    case 191:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(80);
      END_STATE();
    case 192:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(222);
      END_STATE();
    case 193:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(224);
      END_STATE();
    case 194:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(226);
      END_STATE();
    case 195:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(220);
      END_STATE();
    case 196:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(94);
      END_STATE();
    case 197:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(99);
      END_STATE();
    case 198:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(100);
      END_STATE();
    case 199:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(101);
      END_STATE();
    case 200:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(121);
      END_STATE();
    case 201:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(122);
      END_STATE();
    case 202:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(217);
      END_STATE();
    case 203:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(8);
      END_STATE();
    case 204:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(229);
      END_STATE();
    case 205:
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(313);
      END_STATE();
    case 206:
      if (('0' <= lookahead && lookahead <= '3')) ADVANCE(257);
      END_STATE();
    case 207:
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(269);
      END_STATE();
    case 208:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(311);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_mode_chord_over_bass_note);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_mode_chord_over_bass_note);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(210);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_mode_slash_chord_inversion);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_mode_slash_chord_inversion);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(212);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_mode_polychord);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ' ') ADVANCE(187);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(214);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(214);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(214);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(105);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(214);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(216);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_mode_root_inv);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_mode_root_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(219);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_mode_1st_inv);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_mode_1st_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(221);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_mode_2nd_inv);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_mode_2nd_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(223);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_mode_3rd_inv);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_mode_3rd_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(225);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_mode_close);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_mode_close);
      if (lookahead == ' ') ADVANCE(103);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(227);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_mode_close);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(227);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_mode_drop2);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_mode_drop2);
      if (lookahead == '-') ADVANCE(74);
      if ((',' <= lookahead && lookahead <= '.')) ADVANCE(230);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_mode_drop2);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(230);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_mode_drop2);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(230);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(124);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_mode_drop4);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_mode_drop4);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(234);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_mode_drop2and4);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_mode_drop2and4);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(236);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_mode_no_bass);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_mode_no_bass);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(238);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_mode_bass_is_root);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_mode_bass_is_root);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(240);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_octave_up);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_octave_up);
      if (lookahead == '/') ADVANCE(245);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(242);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_octave_up_upper);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_octave_up_upper);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(244);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_octave_up_lower);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_octave_up_lower);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(246);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_octave_down);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_octave_down);
      if (lookahead == '/') ADVANCE(251);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(248);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_octave_down_upper);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_octave_down_upper);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(250);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_octave_down_lower);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_octave_down_lower);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(252);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '7') ADVANCE(293);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_chord_inversion);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_octave_offset);
      if (lookahead == '\'') ADVANCE(258);
      if (lookahead == ',') ADVANCE(259);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_octave_offset);
      if (lookahead == ',') ADVANCE(259);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_note);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(171);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(148);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(138);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(137);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(anon_sym_3);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(anon_sym_4);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(anon_sym_b);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(171);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_5);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(aux_sym_quality_base_token1);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(269);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(anon_sym_maj9);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(anon_sym_Maj9);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(anon_sym_MAJ9);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(anon_sym_M9);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(anon_sym_9);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(anon_sym_maj_LPAREN9_RPAREN);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(anon_sym_Maj_LPAREN9_RPAREN);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(anon_sym_MAJ_LPAREN9_RPAREN);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(anon_sym_M_LPAREN9_RPAREN);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_LPAREN9_RPAREN);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_maj7);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_Maj7);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_MAJ7);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(anon_sym_M7);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_6);
      if (lookahead == '(') ADVANCE(41);
      if (lookahead == '9') ADVANCE(274);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_maj);
      if (lookahead == '(') ADVANCE(44);
      if (lookahead == '7') ADVANCE(280);
      if (lookahead == '9') ADVANCE(270);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_Maj);
      if (lookahead == '(') ADVANCE(43);
      if (lookahead == '7') ADVANCE(281);
      if (lookahead == '9') ADVANCE(271);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(anon_sym_MAJ);
      if (lookahead == '(') ADVANCE(42);
      if (lookahead == '7') ADVANCE(282);
      if (lookahead == '9') ADVANCE(272);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_M);
      if (lookahead == '(') ADVANCE(40);
      if (lookahead == '7') ADVANCE(283);
      if (lookahead == '9') ADVANCE(273);
      if (lookahead == 'A') ADVANCE(45);
      if (lookahead == 'I') ADVANCE(46);
      if (lookahead == 'a') ADVANCE(54);
      if (lookahead == 'i') ADVANCE(59);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_min7);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_Min7);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(anon_sym_MIN7);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_m7);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_DASH7);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_min);
      if (lookahead == '7') ADVANCE(289);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_Min);
      if (lookahead == '7') ADVANCE(290);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_MIN);
      if (lookahead == '7') ADVANCE(291);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(anon_sym_m);
      if (lookahead == '7') ADVANCE(292);
      if (lookahead == 'a') ADVANCE(55);
      if (lookahead == 'i') ADVANCE(60);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(anon_sym_7sus2);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(anon_sym_7sus4);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(anon_sym_sus4);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_sus2);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(anon_sym_dim);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_aug);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(anon_sym_13);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(anon_sym_11);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(anon_sym_92);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(anon_sym_7);
      if (lookahead == 's') ADVANCE(66);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(anon_sym_62);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      if (lookahead == ')') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(311);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      if (lookahead == ')') ADVANCE(312);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(anon_sym_LPARENb5_RPAREN);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(anon_sym_LPAREN_DASH5_RPAREN);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(anon_sym_LPAREN_PLUS5_RPAREN);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(anon_sym_LPAREN_POUND5_RPAREN);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(82);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_on);
      END_STATE();
    case 320:
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
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
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
    [sym_mode_close] = ACTIONS(1),
    [sym_mode_drop2] = ACTIONS(1),
    [sym_mode_drop4] = ACTIONS(1),
    [sym_mode_drop2and4] = ACTIONS(1),
    [sym_mode_no_bass] = ACTIONS(1),
    [sym_mode_bass_is_root] = ACTIONS(1),
    [sym_octave_up] = ACTIONS(1),
    [sym_octave_up_upper] = ACTIONS(1),
    [sym_octave_up_lower] = ACTIONS(1),
    [sym_octave_down] = ACTIONS(1),
    [sym_octave_down_upper] = ACTIONS(1),
    [sym_octave_down_lower] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [sym_chord_inversion] = ACTIONS(1),
    [sym_octave_offset] = ACTIONS(1),
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
    [sym_source_file] = STATE(48),
    [sym__event] = STATE(24),
    [sym_chord] = STATE(24),
    [sym_root] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_mode_chord_over_bass_note] = ACTIONS(5),
    [sym_mode_slash_chord_inversion] = ACTIONS(5),
    [sym_mode_polychord] = ACTIONS(5),
    [sym_mode_root_inv] = ACTIONS(5),
    [sym_mode_1st_inv] = ACTIONS(5),
    [sym_mode_2nd_inv] = ACTIONS(5),
    [sym_mode_3rd_inv] = ACTIONS(5),
    [sym_mode_close] = ACTIONS(5),
    [sym_mode_drop2] = ACTIONS(7),
    [sym_mode_drop4] = ACTIONS(5),
    [sym_mode_drop2and4] = ACTIONS(5),
    [sym_mode_no_bass] = ACTIONS(5),
    [sym_mode_bass_is_root] = ACTIONS(5),
    [sym_octave_up] = ACTIONS(7),
    [sym_octave_up_upper] = ACTIONS(5),
    [sym_octave_up_lower] = ACTIONS(5),
    [sym_octave_down] = ACTIONS(7),
    [sym_octave_down_upper] = ACTIONS(5),
    [sym_octave_down_lower] = ACTIONS(5),
    [sym_note] = ACTIONS(9),
  },
  [2] = {
    [sym_accidental] = STATE(7),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(11),
    [sym_mode_chord_over_bass_note] = ACTIONS(11),
    [sym_mode_slash_chord_inversion] = ACTIONS(11),
    [sym_mode_polychord] = ACTIONS(11),
    [sym_mode_root_inv] = ACTIONS(11),
    [sym_mode_1st_inv] = ACTIONS(11),
    [sym_mode_2nd_inv] = ACTIONS(11),
    [sym_mode_3rd_inv] = ACTIONS(11),
    [sym_mode_close] = ACTIONS(11),
    [sym_mode_drop2] = ACTIONS(13),
    [sym_mode_drop4] = ACTIONS(11),
    [sym_mode_drop2and4] = ACTIONS(11),
    [sym_mode_no_bass] = ACTIONS(11),
    [sym_mode_bass_is_root] = ACTIONS(11),
    [sym_octave_up] = ACTIONS(13),
    [sym_octave_up_upper] = ACTIONS(11),
    [sym_octave_up_lower] = ACTIONS(11),
    [sym_octave_down] = ACTIONS(13),
    [sym_octave_down_upper] = ACTIONS(11),
    [sym_octave_down_lower] = ACTIONS(11),
    [anon_sym_DASH] = ACTIONS(13),
    [anon_sym_] = ACTIONS(11),
    [anon_sym_2] = ACTIONS(11),
    [sym_chord_inversion] = ACTIONS(11),
    [sym_octave_offset] = ACTIONS(11),
    [sym_note] = ACTIONS(13),
    [anon_sym_POUND] = ACTIONS(15),
    [anon_sym_3] = ACTIONS(15),
    [anon_sym_4] = ACTIONS(15),
    [anon_sym_b] = ACTIONS(17),
    [anon_sym_5] = ACTIONS(15),
    [aux_sym_quality_base_token1] = ACTIONS(11),
    [anon_sym_maj9] = ACTIONS(11),
    [anon_sym_Maj9] = ACTIONS(11),
    [anon_sym_MAJ9] = ACTIONS(11),
    [anon_sym_M9] = ACTIONS(11),
    [anon_sym_9] = ACTIONS(11),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(11),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(11),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(11),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(11),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(11),
    [anon_sym_maj7] = ACTIONS(11),
    [anon_sym_Maj7] = ACTIONS(11),
    [anon_sym_MAJ7] = ACTIONS(11),
    [anon_sym_M7] = ACTIONS(11),
    [anon_sym_6] = ACTIONS(13),
    [anon_sym_maj] = ACTIONS(13),
    [anon_sym_Maj] = ACTIONS(13),
    [anon_sym_MAJ] = ACTIONS(13),
    [anon_sym_M] = ACTIONS(13),
    [anon_sym_min7] = ACTIONS(11),
    [anon_sym_Min7] = ACTIONS(11),
    [anon_sym_MIN7] = ACTIONS(11),
    [anon_sym_m7] = ACTIONS(11),
    [anon_sym_DASH7] = ACTIONS(11),
    [anon_sym_min] = ACTIONS(13),
    [anon_sym_Min] = ACTIONS(13),
    [anon_sym_MIN] = ACTIONS(13),
    [anon_sym_m] = ACTIONS(13),
    [anon_sym_7sus2] = ACTIONS(11),
    [anon_sym_7sus4] = ACTIONS(11),
    [anon_sym_sus4] = ACTIONS(11),
    [anon_sym_sus2] = ACTIONS(11),
    [anon_sym_dim] = ACTIONS(11),
    [anon_sym_aug] = ACTIONS(11),
    [anon_sym_PLUS] = ACTIONS(11),
    [anon_sym_13] = ACTIONS(11),
    [anon_sym_11] = ACTIONS(11),
    [anon_sym_92] = ACTIONS(11),
    [anon_sym_7] = ACTIONS(13),
    [anon_sym_62] = ACTIONS(11),
    [aux_sym_quality_modifier_token1] = ACTIONS(11),
    [aux_sym_quality_modifier_token2] = ACTIONS(11),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(11),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(11),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(11),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(11),
    [anon_sym_SLASH] = ACTIONS(13),
    [anon_sym_on] = ACTIONS(11),
    [anon_sym_over] = ACTIONS(11),
  },
  [3] = {
    [sym_accidental] = STATE(7),
    [aux_sym_root_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(19),
    [sym_mode_chord_over_bass_note] = ACTIONS(19),
    [sym_mode_slash_chord_inversion] = ACTIONS(19),
    [sym_mode_polychord] = ACTIONS(19),
    [sym_mode_root_inv] = ACTIONS(19),
    [sym_mode_1st_inv] = ACTIONS(19),
    [sym_mode_2nd_inv] = ACTIONS(19),
    [sym_mode_3rd_inv] = ACTIONS(19),
    [sym_mode_close] = ACTIONS(19),
    [sym_mode_drop2] = ACTIONS(21),
    [sym_mode_drop4] = ACTIONS(19),
    [sym_mode_drop2and4] = ACTIONS(19),
    [sym_mode_no_bass] = ACTIONS(19),
    [sym_mode_bass_is_root] = ACTIONS(19),
    [sym_octave_up] = ACTIONS(21),
    [sym_octave_up_upper] = ACTIONS(19),
    [sym_octave_up_lower] = ACTIONS(19),
    [sym_octave_down] = ACTIONS(21),
    [sym_octave_down_upper] = ACTIONS(19),
    [sym_octave_down_lower] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(21),
    [anon_sym_] = ACTIONS(19),
    [anon_sym_2] = ACTIONS(19),
    [sym_chord_inversion] = ACTIONS(19),
    [sym_octave_offset] = ACTIONS(19),
    [sym_note] = ACTIONS(21),
    [anon_sym_POUND] = ACTIONS(15),
    [anon_sym_3] = ACTIONS(15),
    [anon_sym_4] = ACTIONS(15),
    [anon_sym_b] = ACTIONS(17),
    [anon_sym_5] = ACTIONS(15),
    [aux_sym_quality_base_token1] = ACTIONS(19),
    [anon_sym_maj9] = ACTIONS(19),
    [anon_sym_Maj9] = ACTIONS(19),
    [anon_sym_MAJ9] = ACTIONS(19),
    [anon_sym_M9] = ACTIONS(19),
    [anon_sym_9] = ACTIONS(19),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(19),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(19),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(19),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(19),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(19),
    [anon_sym_maj7] = ACTIONS(19),
    [anon_sym_Maj7] = ACTIONS(19),
    [anon_sym_MAJ7] = ACTIONS(19),
    [anon_sym_M7] = ACTIONS(19),
    [anon_sym_6] = ACTIONS(21),
    [anon_sym_maj] = ACTIONS(21),
    [anon_sym_Maj] = ACTIONS(21),
    [anon_sym_MAJ] = ACTIONS(21),
    [anon_sym_M] = ACTIONS(21),
    [anon_sym_min7] = ACTIONS(19),
    [anon_sym_Min7] = ACTIONS(19),
    [anon_sym_MIN7] = ACTIONS(19),
    [anon_sym_m7] = ACTIONS(19),
    [anon_sym_DASH7] = ACTIONS(19),
    [anon_sym_min] = ACTIONS(21),
    [anon_sym_Min] = ACTIONS(21),
    [anon_sym_MIN] = ACTIONS(21),
    [anon_sym_m] = ACTIONS(21),
    [anon_sym_7sus2] = ACTIONS(19),
    [anon_sym_7sus4] = ACTIONS(19),
    [anon_sym_sus4] = ACTIONS(19),
    [anon_sym_sus2] = ACTIONS(19),
    [anon_sym_dim] = ACTIONS(19),
    [anon_sym_aug] = ACTIONS(19),
    [anon_sym_PLUS] = ACTIONS(19),
    [anon_sym_13] = ACTIONS(19),
    [anon_sym_11] = ACTIONS(19),
    [anon_sym_92] = ACTIONS(19),
    [anon_sym_7] = ACTIONS(21),
    [anon_sym_62] = ACTIONS(19),
    [aux_sym_quality_modifier_token1] = ACTIONS(19),
    [aux_sym_quality_modifier_token2] = ACTIONS(19),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(19),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(19),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(19),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(19),
    [anon_sym_SLASH] = ACTIONS(21),
    [anon_sym_on] = ACTIONS(19),
    [anon_sym_over] = ACTIONS(19),
  },
  [4] = {
    [sym_accidental] = STATE(7),
    [aux_sym_root_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym_mode_chord_over_bass_note] = ACTIONS(23),
    [sym_mode_slash_chord_inversion] = ACTIONS(23),
    [sym_mode_polychord] = ACTIONS(23),
    [sym_mode_root_inv] = ACTIONS(23),
    [sym_mode_1st_inv] = ACTIONS(23),
    [sym_mode_2nd_inv] = ACTIONS(23),
    [sym_mode_3rd_inv] = ACTIONS(23),
    [sym_mode_close] = ACTIONS(23),
    [sym_mode_drop2] = ACTIONS(25),
    [sym_mode_drop4] = ACTIONS(23),
    [sym_mode_drop2and4] = ACTIONS(23),
    [sym_mode_no_bass] = ACTIONS(23),
    [sym_mode_bass_is_root] = ACTIONS(23),
    [sym_octave_up] = ACTIONS(25),
    [sym_octave_up_upper] = ACTIONS(23),
    [sym_octave_up_lower] = ACTIONS(23),
    [sym_octave_down] = ACTIONS(25),
    [sym_octave_down_upper] = ACTIONS(23),
    [sym_octave_down_lower] = ACTIONS(23),
    [anon_sym_DASH] = ACTIONS(25),
    [anon_sym_] = ACTIONS(23),
    [anon_sym_2] = ACTIONS(23),
    [sym_chord_inversion] = ACTIONS(23),
    [sym_octave_offset] = ACTIONS(23),
    [sym_note] = ACTIONS(25),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_3] = ACTIONS(27),
    [anon_sym_4] = ACTIONS(27),
    [anon_sym_b] = ACTIONS(30),
    [anon_sym_5] = ACTIONS(27),
    [aux_sym_quality_base_token1] = ACTIONS(23),
    [anon_sym_maj9] = ACTIONS(23),
    [anon_sym_Maj9] = ACTIONS(23),
    [anon_sym_MAJ9] = ACTIONS(23),
    [anon_sym_M9] = ACTIONS(23),
    [anon_sym_9] = ACTIONS(23),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(23),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(23),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(23),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(23),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(23),
    [anon_sym_maj7] = ACTIONS(23),
    [anon_sym_Maj7] = ACTIONS(23),
    [anon_sym_MAJ7] = ACTIONS(23),
    [anon_sym_M7] = ACTIONS(23),
    [anon_sym_6] = ACTIONS(25),
    [anon_sym_maj] = ACTIONS(25),
    [anon_sym_Maj] = ACTIONS(25),
    [anon_sym_MAJ] = ACTIONS(25),
    [anon_sym_M] = ACTIONS(25),
    [anon_sym_min7] = ACTIONS(23),
    [anon_sym_Min7] = ACTIONS(23),
    [anon_sym_MIN7] = ACTIONS(23),
    [anon_sym_m7] = ACTIONS(23),
    [anon_sym_DASH7] = ACTIONS(23),
    [anon_sym_min] = ACTIONS(25),
    [anon_sym_Min] = ACTIONS(25),
    [anon_sym_MIN] = ACTIONS(25),
    [anon_sym_m] = ACTIONS(25),
    [anon_sym_7sus2] = ACTIONS(23),
    [anon_sym_7sus4] = ACTIONS(23),
    [anon_sym_sus4] = ACTIONS(23),
    [anon_sym_sus2] = ACTIONS(23),
    [anon_sym_dim] = ACTIONS(23),
    [anon_sym_aug] = ACTIONS(23),
    [anon_sym_PLUS] = ACTIONS(23),
    [anon_sym_13] = ACTIONS(23),
    [anon_sym_11] = ACTIONS(23),
    [anon_sym_92] = ACTIONS(23),
    [anon_sym_7] = ACTIONS(25),
    [anon_sym_62] = ACTIONS(23),
    [aux_sym_quality_modifier_token1] = ACTIONS(23),
    [aux_sym_quality_modifier_token2] = ACTIONS(23),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(23),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(23),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(23),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(23),
    [anon_sym_SLASH] = ACTIONS(25),
    [anon_sym_on] = ACTIONS(23),
    [anon_sym_over] = ACTIONS(23),
  },
  [5] = {
    [sym_quality] = STATE(16),
    [sym_quality_base] = STATE(9),
    [sym_quality_modifier] = STATE(15),
    [sym_bass] = STATE(33),
    [sym_on_bass] = STATE(33),
    [aux_sym_quality_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_mode_chord_over_bass_note] = ACTIONS(33),
    [sym_mode_slash_chord_inversion] = ACTIONS(33),
    [sym_mode_polychord] = ACTIONS(33),
    [sym_mode_root_inv] = ACTIONS(33),
    [sym_mode_1st_inv] = ACTIONS(33),
    [sym_mode_2nd_inv] = ACTIONS(33),
    [sym_mode_3rd_inv] = ACTIONS(33),
    [sym_mode_close] = ACTIONS(33),
    [sym_mode_drop2] = ACTIONS(35),
    [sym_mode_drop4] = ACTIONS(33),
    [sym_mode_drop2and4] = ACTIONS(33),
    [sym_mode_no_bass] = ACTIONS(33),
    [sym_mode_bass_is_root] = ACTIONS(33),
    [sym_octave_up] = ACTIONS(35),
    [sym_octave_up_upper] = ACTIONS(33),
    [sym_octave_up_lower] = ACTIONS(33),
    [sym_octave_down] = ACTIONS(35),
    [sym_octave_down_upper] = ACTIONS(33),
    [sym_octave_down_lower] = ACTIONS(33),
    [anon_sym_DASH] = ACTIONS(37),
    [anon_sym_] = ACTIONS(33),
    [anon_sym_2] = ACTIONS(33),
    [sym_chord_inversion] = ACTIONS(40),
    [sym_octave_offset] = ACTIONS(42),
    [sym_note] = ACTIONS(35),
    [aux_sym_quality_base_token1] = ACTIONS(44),
    [anon_sym_maj9] = ACTIONS(44),
    [anon_sym_Maj9] = ACTIONS(44),
    [anon_sym_MAJ9] = ACTIONS(44),
    [anon_sym_M9] = ACTIONS(44),
    [anon_sym_9] = ACTIONS(44),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_maj7] = ACTIONS(44),
    [anon_sym_Maj7] = ACTIONS(44),
    [anon_sym_MAJ7] = ACTIONS(44),
    [anon_sym_M7] = ACTIONS(44),
    [anon_sym_6] = ACTIONS(46),
    [anon_sym_maj] = ACTIONS(46),
    [anon_sym_Maj] = ACTIONS(46),
    [anon_sym_MAJ] = ACTIONS(46),
    [anon_sym_M] = ACTIONS(46),
    [anon_sym_min7] = ACTIONS(44),
    [anon_sym_Min7] = ACTIONS(44),
    [anon_sym_MIN7] = ACTIONS(44),
    [anon_sym_m7] = ACTIONS(44),
    [anon_sym_DASH7] = ACTIONS(44),
    [anon_sym_min] = ACTIONS(46),
    [anon_sym_Min] = ACTIONS(46),
    [anon_sym_MIN] = ACTIONS(46),
    [anon_sym_m] = ACTIONS(46),
    [anon_sym_7sus2] = ACTIONS(44),
    [anon_sym_7sus4] = ACTIONS(44),
    [anon_sym_sus4] = ACTIONS(44),
    [anon_sym_sus2] = ACTIONS(44),
    [anon_sym_dim] = ACTIONS(44),
    [anon_sym_aug] = ACTIONS(44),
    [anon_sym_PLUS] = ACTIONS(44),
    [anon_sym_13] = ACTIONS(44),
    [anon_sym_11] = ACTIONS(44),
    [anon_sym_92] = ACTIONS(44),
    [anon_sym_7] = ACTIONS(46),
    [anon_sym_62] = ACTIONS(44),
    [aux_sym_quality_modifier_token1] = ACTIONS(48),
    [aux_sym_quality_modifier_token2] = ACTIONS(48),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(48),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(48),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(48),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(48),
    [anon_sym_SLASH] = ACTIONS(50),
    [anon_sym_on] = ACTIONS(52),
    [anon_sym_over] = ACTIONS(52),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(54),
    [sym_mode_chord_over_bass_note] = ACTIONS(54),
    [sym_mode_slash_chord_inversion] = ACTIONS(54),
    [sym_mode_polychord] = ACTIONS(54),
    [sym_mode_root_inv] = ACTIONS(54),
    [sym_mode_1st_inv] = ACTIONS(54),
    [sym_mode_2nd_inv] = ACTIONS(54),
    [sym_mode_3rd_inv] = ACTIONS(54),
    [sym_mode_close] = ACTIONS(54),
    [sym_mode_drop2] = ACTIONS(56),
    [sym_mode_drop4] = ACTIONS(54),
    [sym_mode_drop2and4] = ACTIONS(54),
    [sym_mode_no_bass] = ACTIONS(54),
    [sym_mode_bass_is_root] = ACTIONS(54),
    [sym_octave_up] = ACTIONS(56),
    [sym_octave_up_upper] = ACTIONS(54),
    [sym_octave_up_lower] = ACTIONS(54),
    [sym_octave_down] = ACTIONS(56),
    [sym_octave_down_upper] = ACTIONS(54),
    [sym_octave_down_lower] = ACTIONS(54),
    [anon_sym_DASH] = ACTIONS(56),
    [anon_sym_] = ACTIONS(54),
    [anon_sym_2] = ACTIONS(54),
    [sym_chord_inversion] = ACTIONS(54),
    [sym_octave_offset] = ACTIONS(54),
    [sym_note] = ACTIONS(56),
    [anon_sym_POUND] = ACTIONS(54),
    [anon_sym_3] = ACTIONS(54),
    [anon_sym_4] = ACTIONS(54),
    [anon_sym_b] = ACTIONS(56),
    [anon_sym_5] = ACTIONS(54),
    [aux_sym_quality_base_token1] = ACTIONS(54),
    [anon_sym_maj9] = ACTIONS(54),
    [anon_sym_Maj9] = ACTIONS(54),
    [anon_sym_MAJ9] = ACTIONS(54),
    [anon_sym_M9] = ACTIONS(54),
    [anon_sym_9] = ACTIONS(54),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(54),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(54),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(54),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(54),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(54),
    [anon_sym_maj7] = ACTIONS(54),
    [anon_sym_Maj7] = ACTIONS(54),
    [anon_sym_MAJ7] = ACTIONS(54),
    [anon_sym_M7] = ACTIONS(54),
    [anon_sym_6] = ACTIONS(56),
    [anon_sym_maj] = ACTIONS(56),
    [anon_sym_Maj] = ACTIONS(56),
    [anon_sym_MAJ] = ACTIONS(56),
    [anon_sym_M] = ACTIONS(56),
    [anon_sym_min7] = ACTIONS(54),
    [anon_sym_Min7] = ACTIONS(54),
    [anon_sym_MIN7] = ACTIONS(54),
    [anon_sym_m7] = ACTIONS(54),
    [anon_sym_DASH7] = ACTIONS(54),
    [anon_sym_min] = ACTIONS(56),
    [anon_sym_Min] = ACTIONS(56),
    [anon_sym_MIN] = ACTIONS(56),
    [anon_sym_m] = ACTIONS(56),
    [anon_sym_7sus2] = ACTIONS(54),
    [anon_sym_7sus4] = ACTIONS(54),
    [anon_sym_sus4] = ACTIONS(54),
    [anon_sym_sus2] = ACTIONS(54),
    [anon_sym_dim] = ACTIONS(54),
    [anon_sym_aug] = ACTIONS(54),
    [anon_sym_PLUS] = ACTIONS(54),
    [anon_sym_13] = ACTIONS(54),
    [anon_sym_11] = ACTIONS(54),
    [anon_sym_92] = ACTIONS(54),
    [anon_sym_7] = ACTIONS(56),
    [anon_sym_62] = ACTIONS(54),
    [aux_sym_quality_modifier_token1] = ACTIONS(54),
    [aux_sym_quality_modifier_token2] = ACTIONS(54),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(54),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(54),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(54),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(54),
    [anon_sym_SLASH] = ACTIONS(56),
    [anon_sym_on] = ACTIONS(54),
    [anon_sym_over] = ACTIONS(54),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(58),
    [sym_mode_chord_over_bass_note] = ACTIONS(58),
    [sym_mode_slash_chord_inversion] = ACTIONS(58),
    [sym_mode_polychord] = ACTIONS(58),
    [sym_mode_root_inv] = ACTIONS(58),
    [sym_mode_1st_inv] = ACTIONS(58),
    [sym_mode_2nd_inv] = ACTIONS(58),
    [sym_mode_3rd_inv] = ACTIONS(58),
    [sym_mode_close] = ACTIONS(58),
    [sym_mode_drop2] = ACTIONS(60),
    [sym_mode_drop4] = ACTIONS(58),
    [sym_mode_drop2and4] = ACTIONS(58),
    [sym_mode_no_bass] = ACTIONS(58),
    [sym_mode_bass_is_root] = ACTIONS(58),
    [sym_octave_up] = ACTIONS(60),
    [sym_octave_up_upper] = ACTIONS(58),
    [sym_octave_up_lower] = ACTIONS(58),
    [sym_octave_down] = ACTIONS(60),
    [sym_octave_down_upper] = ACTIONS(58),
    [sym_octave_down_lower] = ACTIONS(58),
    [anon_sym_DASH] = ACTIONS(60),
    [anon_sym_] = ACTIONS(58),
    [anon_sym_2] = ACTIONS(58),
    [sym_chord_inversion] = ACTIONS(58),
    [sym_octave_offset] = ACTIONS(58),
    [sym_note] = ACTIONS(60),
    [anon_sym_POUND] = ACTIONS(58),
    [anon_sym_3] = ACTIONS(58),
    [anon_sym_4] = ACTIONS(58),
    [anon_sym_b] = ACTIONS(60),
    [anon_sym_5] = ACTIONS(58),
    [aux_sym_quality_base_token1] = ACTIONS(58),
    [anon_sym_maj9] = ACTIONS(58),
    [anon_sym_Maj9] = ACTIONS(58),
    [anon_sym_MAJ9] = ACTIONS(58),
    [anon_sym_M9] = ACTIONS(58),
    [anon_sym_9] = ACTIONS(58),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(58),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(58),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(58),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(58),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(58),
    [anon_sym_maj7] = ACTIONS(58),
    [anon_sym_Maj7] = ACTIONS(58),
    [anon_sym_MAJ7] = ACTIONS(58),
    [anon_sym_M7] = ACTIONS(58),
    [anon_sym_6] = ACTIONS(60),
    [anon_sym_maj] = ACTIONS(60),
    [anon_sym_Maj] = ACTIONS(60),
    [anon_sym_MAJ] = ACTIONS(60),
    [anon_sym_M] = ACTIONS(60),
    [anon_sym_min7] = ACTIONS(58),
    [anon_sym_Min7] = ACTIONS(58),
    [anon_sym_MIN7] = ACTIONS(58),
    [anon_sym_m7] = ACTIONS(58),
    [anon_sym_DASH7] = ACTIONS(58),
    [anon_sym_min] = ACTIONS(60),
    [anon_sym_Min] = ACTIONS(60),
    [anon_sym_MIN] = ACTIONS(60),
    [anon_sym_m] = ACTIONS(60),
    [anon_sym_7sus2] = ACTIONS(58),
    [anon_sym_7sus4] = ACTIONS(58),
    [anon_sym_sus4] = ACTIONS(58),
    [anon_sym_sus2] = ACTIONS(58),
    [anon_sym_dim] = ACTIONS(58),
    [anon_sym_aug] = ACTIONS(58),
    [anon_sym_PLUS] = ACTIONS(58),
    [anon_sym_13] = ACTIONS(58),
    [anon_sym_11] = ACTIONS(58),
    [anon_sym_92] = ACTIONS(58),
    [anon_sym_7] = ACTIONS(60),
    [anon_sym_62] = ACTIONS(58),
    [aux_sym_quality_modifier_token1] = ACTIONS(58),
    [aux_sym_quality_modifier_token2] = ACTIONS(58),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(58),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(58),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(58),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(58),
    [anon_sym_SLASH] = ACTIONS(60),
    [anon_sym_on] = ACTIONS(58),
    [anon_sym_over] = ACTIONS(58),
  },
  [8] = {
    [sym_quality] = STATE(28),
    [sym_quality_base] = STATE(9),
    [sym_quality_modifier] = STATE(15),
    [aux_sym_quality_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(62),
    [sym_mode_chord_over_bass_note] = ACTIONS(62),
    [sym_mode_slash_chord_inversion] = ACTIONS(62),
    [sym_mode_polychord] = ACTIONS(62),
    [sym_mode_root_inv] = ACTIONS(62),
    [sym_mode_1st_inv] = ACTIONS(62),
    [sym_mode_2nd_inv] = ACTIONS(62),
    [sym_mode_3rd_inv] = ACTIONS(62),
    [sym_mode_close] = ACTIONS(62),
    [sym_mode_drop2] = ACTIONS(64),
    [sym_mode_drop4] = ACTIONS(62),
    [sym_mode_drop2and4] = ACTIONS(62),
    [sym_mode_no_bass] = ACTIONS(62),
    [sym_mode_bass_is_root] = ACTIONS(62),
    [sym_octave_up] = ACTIONS(64),
    [sym_octave_up_upper] = ACTIONS(62),
    [sym_octave_up_lower] = ACTIONS(62),
    [sym_octave_down] = ACTIONS(64),
    [sym_octave_down_upper] = ACTIONS(62),
    [sym_octave_down_lower] = ACTIONS(62),
    [anon_sym_DASH] = ACTIONS(66),
    [anon_sym_] = ACTIONS(62),
    [anon_sym_2] = ACTIONS(62),
    [sym_chord_inversion] = ACTIONS(69),
    [sym_octave_offset] = ACTIONS(71),
    [sym_note] = ACTIONS(64),
    [aux_sym_quality_base_token1] = ACTIONS(44),
    [anon_sym_maj9] = ACTIONS(44),
    [anon_sym_Maj9] = ACTIONS(44),
    [anon_sym_MAJ9] = ACTIONS(44),
    [anon_sym_M9] = ACTIONS(44),
    [anon_sym_9] = ACTIONS(44),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(44),
    [anon_sym_maj7] = ACTIONS(44),
    [anon_sym_Maj7] = ACTIONS(44),
    [anon_sym_MAJ7] = ACTIONS(44),
    [anon_sym_M7] = ACTIONS(44),
    [anon_sym_6] = ACTIONS(46),
    [anon_sym_maj] = ACTIONS(46),
    [anon_sym_Maj] = ACTIONS(46),
    [anon_sym_MAJ] = ACTIONS(46),
    [anon_sym_M] = ACTIONS(46),
    [anon_sym_min7] = ACTIONS(44),
    [anon_sym_Min7] = ACTIONS(44),
    [anon_sym_MIN7] = ACTIONS(44),
    [anon_sym_m7] = ACTIONS(44),
    [anon_sym_DASH7] = ACTIONS(44),
    [anon_sym_min] = ACTIONS(46),
    [anon_sym_Min] = ACTIONS(46),
    [anon_sym_MIN] = ACTIONS(46),
    [anon_sym_m] = ACTIONS(46),
    [anon_sym_7sus2] = ACTIONS(44),
    [anon_sym_7sus4] = ACTIONS(44),
    [anon_sym_sus4] = ACTIONS(44),
    [anon_sym_sus2] = ACTIONS(44),
    [anon_sym_dim] = ACTIONS(44),
    [anon_sym_aug] = ACTIONS(44),
    [anon_sym_PLUS] = ACTIONS(44),
    [anon_sym_13] = ACTIONS(44),
    [anon_sym_11] = ACTIONS(44),
    [anon_sym_92] = ACTIONS(44),
    [anon_sym_7] = ACTIONS(46),
    [anon_sym_62] = ACTIONS(44),
    [aux_sym_quality_modifier_token1] = ACTIONS(48),
    [aux_sym_quality_modifier_token2] = ACTIONS(48),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(48),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(48),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(48),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(48),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    STATE(11), 1,
      aux_sym_quality_repeat1,
    STATE(15), 1,
      sym_quality_modifier,
    ACTIONS(75), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      anon_sym_SLASH,
    ACTIONS(48), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(73), 24,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      sym_octave_offset,
      anon_sym_on,
      anon_sym_over,
  [48] = 5,
    STATE(10), 1,
      aux_sym_quality_repeat1,
    STATE(15), 1,
      sym_quality_modifier,
    ACTIONS(79), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      anon_sym_SLASH,
    ACTIONS(81), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(77), 24,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      sym_octave_offset,
      anon_sym_on,
      anon_sym_over,
  [96] = 5,
    STATE(10), 1,
      aux_sym_quality_repeat1,
    STATE(15), 1,
      sym_quality_modifier,
    ACTIONS(86), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      anon_sym_SLASH,
    ACTIONS(48), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(84), 24,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      sym_octave_offset,
      anon_sym_on,
      anon_sym_over,
  [144] = 5,
    STATE(10), 1,
      aux_sym_quality_repeat1,
    STATE(15), 1,
      sym_quality_modifier,
    ACTIONS(90), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      anon_sym_SLASH,
    ACTIONS(48), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(88), 24,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      sym_octave_offset,
      anon_sym_on,
      anon_sym_over,
  [192] = 2,
    ACTIONS(94), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      anon_sym_SLASH,
    ACTIONS(92), 30,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      sym_octave_offset,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
      anon_sym_on,
      anon_sym_over,
  [232] = 2,
    ACTIONS(98), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      anon_sym_SLASH,
    ACTIONS(96), 30,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      sym_octave_offset,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
      anon_sym_on,
      anon_sym_over,
  [272] = 2,
    ACTIONS(102), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      anon_sym_SLASH,
    ACTIONS(100), 30,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_chord_inversion,
      sym_octave_offset,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
      anon_sym_on,
      anon_sym_over,
  [312] = 7,
    ACTIONS(50), 1,
      anon_sym_SLASH,
    ACTIONS(108), 1,
      sym_chord_inversion,
    ACTIONS(110), 1,
      sym_octave_offset,
    ACTIONS(52), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(34), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(106), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(104), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [358] = 6,
    ACTIONS(50), 1,
      anon_sym_SLASH,
    ACTIONS(116), 1,
      sym_octave_offset,
    ACTIONS(52), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(40), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(114), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(112), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [401] = 6,
    ACTIONS(50), 1,
      anon_sym_SLASH,
    ACTIONS(122), 1,
      sym_octave_offset,
    ACTIONS(52), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(38), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(120), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(118), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [444] = 5,
    ACTIONS(50), 1,
      anon_sym_SLASH,
    ACTIONS(52), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(36), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(126), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(124), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [484] = 5,
    ACTIONS(50), 1,
      anon_sym_SLASH,
    ACTIONS(52), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(44), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(130), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(128), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [524] = 8,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(132), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      sym_root,
    STATE(46), 1,
      sym_separator,
    ACTIONS(136), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(138), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(22), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(134), 16,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
  [570] = 8,
    ACTIONS(140), 1,
      ts_builtin_sym_end,
    ACTIONS(151), 1,
      sym_note,
    STATE(5), 1,
      sym_root,
    STATE(46), 1,
      sym_separator,
    ACTIONS(145), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(148), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(22), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(142), 16,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
  [616] = 5,
    ACTIONS(50), 1,
      anon_sym_SLASH,
    ACTIONS(52), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(35), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(156), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(154), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [656] = 8,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(158), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      sym_root,
    STATE(46), 1,
      sym_separator,
    ACTIONS(138), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    ACTIONS(162), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    STATE(21), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(160), 16,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
  [702] = 5,
    ACTIONS(50), 1,
      anon_sym_SLASH,
    ACTIONS(52), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(41), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(166), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(164), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [742] = 5,
    ACTIONS(9), 1,
      sym_note,
    STATE(8), 1,
      sym_root,
    STATE(31), 1,
      sym__lower,
    ACTIONS(170), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(168), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [779] = 5,
    ACTIONS(9), 1,
      sym_note,
    STATE(8), 1,
      sym_root,
    STATE(32), 1,
      sym__lower,
    ACTIONS(174), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(172), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [816] = 4,
    ACTIONS(180), 1,
      sym_chord_inversion,
    ACTIONS(182), 1,
      sym_octave_offset,
    ACTIONS(178), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(176), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [851] = 3,
    ACTIONS(188), 1,
      sym_octave_offset,
    ACTIONS(186), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(184), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [883] = 3,
    ACTIONS(194), 1,
      sym_octave_offset,
    ACTIONS(192), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(190), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [915] = 2,
    ACTIONS(198), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(196), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [944] = 2,
    ACTIONS(202), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(200), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [973] = 2,
    ACTIONS(206), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(204), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1002] = 2,
    ACTIONS(210), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(208), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1031] = 2,
    ACTIONS(214), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(212), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1060] = 2,
    ACTIONS(218), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(216), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1089] = 2,
    ACTIONS(222), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(220), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1118] = 2,
    ACTIONS(226), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(224), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1147] = 2,
    ACTIONS(228), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(140), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1176] = 2,
    ACTIONS(232), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(230), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1205] = 2,
    ACTIONS(236), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(234), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1234] = 2,
    ACTIONS(240), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(238), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1263] = 2,
    ACTIONS(244), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(242), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1292] = 2,
    ACTIONS(248), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(246), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1321] = 2,
    ACTIONS(252), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(250), 20,
      ts_builtin_sym_end,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
  [1350] = 5,
    ACTIONS(9), 1,
      sym_note,
    STATE(5), 1,
      sym_root,
    STATE(39), 2,
      sym__event,
      sym_chord,
    ACTIONS(256), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(254), 16,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
  [1384] = 2,
    ACTIONS(260), 4,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
    ACTIONS(258), 16,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
      sym_mode_polychord,
      sym_mode_root_inv,
      sym_mode_1st_inv,
      sym_mode_2nd_inv,
      sym_mode_3rd_inv,
      sym_mode_close,
      sym_mode_drop4,
      sym_mode_drop2and4,
      sym_mode_no_bass,
      sym_mode_bass_is_root,
      sym_octave_up_upper,
      sym_octave_up_lower,
      sym_octave_down_upper,
      sym_octave_down_lower,
  [1409] = 1,
    ACTIONS(262), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(9)] = 0,
  [SMALL_STATE(10)] = 48,
  [SMALL_STATE(11)] = 96,
  [SMALL_STATE(12)] = 144,
  [SMALL_STATE(13)] = 192,
  [SMALL_STATE(14)] = 232,
  [SMALL_STATE(15)] = 272,
  [SMALL_STATE(16)] = 312,
  [SMALL_STATE(17)] = 358,
  [SMALL_STATE(18)] = 401,
  [SMALL_STATE(19)] = 444,
  [SMALL_STATE(20)] = 484,
  [SMALL_STATE(21)] = 524,
  [SMALL_STATE(22)] = 570,
  [SMALL_STATE(23)] = 616,
  [SMALL_STATE(24)] = 656,
  [SMALL_STATE(25)] = 702,
  [SMALL_STATE(26)] = 742,
  [SMALL_STATE(27)] = 779,
  [SMALL_STATE(28)] = 816,
  [SMALL_STATE(29)] = 851,
  [SMALL_STATE(30)] = 883,
  [SMALL_STATE(31)] = 915,
  [SMALL_STATE(32)] = 944,
  [SMALL_STATE(33)] = 973,
  [SMALL_STATE(34)] = 1002,
  [SMALL_STATE(35)] = 1031,
  [SMALL_STATE(36)] = 1060,
  [SMALL_STATE(37)] = 1089,
  [SMALL_STATE(38)] = 1118,
  [SMALL_STATE(39)] = 1147,
  [SMALL_STATE(40)] = 1176,
  [SMALL_STATE(41)] = 1205,
  [SMALL_STATE(42)] = 1234,
  [SMALL_STATE(43)] = 1263,
  [SMALL_STATE(44)] = 1292,
  [SMALL_STATE(45)] = 1321,
  [SMALL_STATE(46)] = 1350,
  [SMALL_STATE(47)] = 1384,
  [SMALL_STATE(48)] = 1409,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1, .production_id = 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 1, .production_id = 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 2, .production_id = 4),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 2, .production_id = 4),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 12),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 12),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 12), SHIFT_REPEAT(6),
  [30] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 12), SHIFT_REPEAT(6),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 1, .production_id = 2),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 1, .production_id = 2),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_chord, 1, .production_id = 2), SHIFT(13),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accidental, 1),
  [56] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accidental, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 1, .production_id = 3),
  [60] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 1, .production_id = 3),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 1, .production_id = 2),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 1, .production_id = 2),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym__lower, 1, .production_id = 2), SHIFT(13),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 8),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 1, .production_id = 8),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 21),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 21),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 21), SHIFT_REPEAT(14),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 2, .production_id = 20),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 2, .production_id = 20),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 11),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 1, .production_id = 11),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_base, 1),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality_base, 1),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_modifier, 1),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality_modifier, 1),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 1, .production_id = 9),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quality_repeat1, 1, .production_id = 9),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 7),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 7),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 17),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 17),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 5),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 5),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 6),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 6),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 23),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 23),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(22),
  [145] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(22),
  [148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(47),
  [151] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 13),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 13),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 18),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 18),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 1),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bass, 1),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_on_bass, 1),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_on_bass, 1),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 7),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 7),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 17),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 17),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 5),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 5),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 2, .production_id = 16),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bass, 2, .production_id = 16),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_on_bass, 2, .production_id = 16),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_on_bass, 2, .production_id = 16),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 10),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 10),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 19),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 19),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 22),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 22),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 15),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 15),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 6),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 6),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 14),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 14),
  [228] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 24),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 24),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 25),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 25),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 13),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 13),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 18),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 18),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 5, .production_id = 26),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 5, .production_id = 26),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 4, .production_id = 23),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 4, .production_id = 23),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [256] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_separator, 1, .dynamic_precedence = 1),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_separator, 1, .dynamic_precedence = 1),
  [262] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
