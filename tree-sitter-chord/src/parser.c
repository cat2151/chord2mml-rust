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
#define STATE_COUNT 46
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 94
#define ALIAS_COUNT 0
#define TOKEN_COUNT 81
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 25

enum {
  sym_bar = 1,
  sym_bar_slash = 2,
  sym_key = 3,
  sym_scale = 4,
  sym_mode_chord_over_bass_note = 5,
  sym_mode_slash_chord_inversion = 6,
  sym_mode_polychord = 7,
  sym_mode_root_inv = 8,
  sym_mode_1st_inv = 9,
  sym_mode_2nd_inv = 10,
  sym_mode_3rd_inv = 11,
  sym_mode_close = 12,
  sym_mode_drop2 = 13,
  sym_mode_drop4 = 14,
  sym_mode_drop2and4 = 15,
  sym_mode_no_bass = 16,
  sym_mode_bass_is_root = 17,
  sym_octave_up = 18,
  sym_octave_up_upper = 19,
  sym_octave_up_lower = 20,
  sym_octave_down = 21,
  sym_octave_down_upper = 22,
  sym_octave_down_lower = 23,
  anon_sym_DASH = 24,
  anon_sym_ = 25,
  anon_sym_2 = 26,
  sym_chord_inversion = 27,
  sym_octave_offset = 28,
  sym_note = 29,
  sym_degree = 30,
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
  anon_sym_3 = 46,
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
  anon_sym_6 = 71,
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
  sym_quality = 86,
  sym_quality_base = 87,
  sym_quality_modifier = 88,
  sym__lower = 89,
  sym_bass = 90,
  sym_on_bass = 91,
  aux_sym_source_file_repeat1 = 92,
  aux_sym_quality_repeat1 = 93,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_bar] = "bar",
  [sym_bar_slash] = "bar_slash",
  [sym_key] = "key",
  [sym_scale] = "scale",
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
  [sym_degree] = "degree",
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
  [anon_sym_3] = "△",
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
  [anon_sym_6] = "6",
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
  [sym_quality] = "quality",
  [sym_quality_base] = "quality_base",
  [sym_quality_modifier] = "quality_modifier",
  [sym__lower] = "_lower",
  [sym_bass] = "bass",
  [sym_on_bass] = "on_bass",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_quality_repeat1] = "quality_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_bar] = sym_bar,
  [sym_bar_slash] = sym_bar_slash,
  [sym_key] = sym_key,
  [sym_scale] = sym_scale,
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
  [sym_degree] = sym_degree,
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
  [anon_sym_3] = anon_sym_3,
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
  [anon_sym_6] = anon_sym_6,
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
  [sym_quality] = sym_quality,
  [sym_quality_base] = sym_quality_base,
  [sym_quality_modifier] = sym_quality_modifier,
  [sym__lower] = sym__lower,
  [sym_bass] = sym_bass,
  [sym_on_bass] = sym_on_bass,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_quality_repeat1] = aux_sym_quality_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_bar] = {
    .visible = true,
    .named = true,
  },
  [sym_bar_slash] = {
    .visible = true,
    .named = true,
  },
  [sym_key] = {
    .visible = true,
    .named = true,
  },
  [sym_scale] = {
    .visible = true,
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
  [sym_degree] = {
    .visible = true,
    .named = true,
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
  [anon_sym_3] = {
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
  [anon_sym_6] = {
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
  [aux_sym_quality_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_base = 1,
  field_bass = 2,
  field_degree = 3,
  field_inversion = 4,
  field_modifier = 5,
  field_note = 6,
  field_octave = 7,
  field_quality = 8,
  field_root = 9,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_base] = "base",
  [field_bass] = "bass",
  [field_degree] = "degree",
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
  [7] = {.index = 9, .length = 1},
  [8] = {.index = 10, .length = 1},
  [9] = {.index = 11, .length = 2},
  [10] = {.index = 13, .length = 1},
  [11] = {.index = 14, .length = 3},
  [12] = {.index = 17, .length = 3},
  [13] = {.index = 20, .length = 3},
  [14] = {.index = 23, .length = 4},
  [15] = {.index = 27, .length = 3},
  [16] = {.index = 30, .length = 3},
  [17] = {.index = 33, .length = 3},
  [18] = {.index = 36, .length = 2},
  [19] = {.index = 38, .length = 2},
  [20] = {.index = 40, .length = 4},
  [21] = {.index = 44, .length = 4},
  [22] = {.index = 48, .length = 4},
  [23] = {.index = 52, .length = 4},
  [24] = {.index = 56, .length = 5},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_note, 0},
  [1] =
    {field_degree, 0},
  [2] =
    {field_root, 0},
  [3] =
    {field_inversion, 1},
    {field_root, 0},
  [5] =
    {field_octave, 1},
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
    {field_inversion, 1},
    {field_octave, 2},
    {field_root, 0},
  [17] =
    {field_bass, 2},
    {field_inversion, 1},
    {field_root, 0},
  [20] =
    {field_bass, 2},
    {field_octave, 1},
    {field_root, 0},
  [23] =
    {field_inversion, 1, .inherited = true},
    {field_octave, 1, .inherited = true},
    {field_quality, 1, .inherited = true},
    {field_root, 1, .inherited = true},
  [27] =
    {field_inversion, 2},
    {field_quality, 1},
    {field_root, 0},
  [30] =
    {field_octave, 2},
    {field_quality, 1},
    {field_root, 0},
  [33] =
    {field_bass, 2},
    {field_quality, 1},
    {field_root, 0},
  [36] =
    {field_base, 0},
    {field_modifier, 1, .inherited = true},
  [38] =
    {field_modifier, 0, .inherited = true},
    {field_modifier, 1, .inherited = true},
  [40] =
    {field_bass, 3},
    {field_inversion, 1},
    {field_octave, 2},
    {field_root, 0},
  [44] =
    {field_inversion, 2},
    {field_octave, 3},
    {field_quality, 1},
    {field_root, 0},
  [48] =
    {field_bass, 3},
    {field_inversion, 2},
    {field_quality, 1},
    {field_root, 0},
  [52] =
    {field_bass, 3},
    {field_octave, 2},
    {field_quality, 1},
    {field_root, 0},
  [56] =
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(238);
      if (lookahead == '\'') ADVANCE(297);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == '+') ADVANCE(350);
      if (lookahead == ',') ADVANCE(298);
      if (lookahead == '-') ADVANCE(293);
      if (lookahead == '/') ADVANCE(364);
      if (lookahead == '1') ADVANCE(307);
      if (lookahead == '2') ADVANCE(312);
      if (lookahead == '3') ADVANCE(313);
      if (lookahead == '4') ADVANCE(306);
      if (lookahead == '5') ADVANCE(305);
      if (lookahead == '6') ADVANCE(355);
      if (lookahead == '7') ADVANCE(354);
      if (lookahead == '9') ADVANCE(353);
      if (lookahead == 'A') ADVANCE(300);
      if (lookahead == 'B') ADVANCE(299);
      if (lookahead == 'C') ADVANCE(301);
      if (lookahead == 'D') ADVANCE(302);
      if (lookahead == 'I') ADVANCE(311);
      if (lookahead == 'M') ADVANCE(334);
      if (lookahead == 'O') ADVANCE(83);
      if (lookahead == 'S') ADVANCE(127);
      if (lookahead == 'V') ADVANCE(309);
      if (lookahead == '^') ADVANCE(233);
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'b') ADVANCE(43);
      if (lookahead == 'c') ADVANCE(110);
      if (lookahead == 'd') ADVANCE(54);
      if (lookahead == 'i') ADVANCE(150);
      if (lookahead == 'm') ADVANCE(343);
      if (lookahead == 'o') ADVANCE(58);
      if (lookahead == 's') ADVANCE(67);
      if (lookahead == '|') ADVANCE(239);
      if (lookahead == 8594) ADVANCE(294);
      if (lookahead == 9651) ADVANCE(330);
      if (lookahead == 9837) ADVANCE(45);
      if (lookahead == 12539) ADVANCE(295);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(98);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(153);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(151);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(109);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(161);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(171);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(44);
      if (('E' <= lookahead && lookahead <= 'G')) ADVANCE(304);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(80);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(125);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(93);
      if (lookahead == '-') ADVANCE(93);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(116);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(85);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(208);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(197);
      END_STATE();
    case 8:
      if (lookahead == ' ') ADVANCE(187);
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(187);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(8);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(166);
      END_STATE();
    case 11:
      if (lookahead == ' ') ADVANCE(94);
      if (lookahead == '-') ADVANCE(94);
      END_STATE();
    case 12:
      if (lookahead == ' ') ADVANCE(118);
      END_STATE();
    case 13:
      if (lookahead == ' ') ADVANCE(147);
      END_STATE();
    case 14:
      if (lookahead == ' ') ADVANCE(119);
      END_STATE();
    case 15:
      if (lookahead == ' ') ADVANCE(123);
      END_STATE();
    case 16:
      if (lookahead == ' ') ADVANCE(124);
      END_STATE();
    case 17:
      if (lookahead == ' ') ADVANCE(81);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(34);
      if (lookahead == '+') ADVANCE(35);
      if (lookahead == '-') ADVANCE(36);
      if (lookahead == 'a') ADVANCE(49);
      if (lookahead == 'b') ADVANCE(37);
      if (lookahead == 'o') ADVANCE(59);
      END_STATE();
    case 19:
      if (lookahead == ')') ADVANCE(363);
      END_STATE();
    case 20:
      if (lookahead == ')') ADVANCE(362);
      END_STATE();
    case 21:
      if (lookahead == ')') ADVANCE(361);
      END_STATE();
    case 22:
      if (lookahead == ')') ADVANCE(360);
      END_STATE();
    case 23:
      if (lookahead == ')') ADVANCE(324);
      END_STATE();
    case 24:
      if (lookahead == ')') ADVANCE(325);
      END_STATE();
    case 25:
      if (lookahead == ')') ADVANCE(323);
      END_STATE();
    case 26:
      if (lookahead == ')') ADVANCE(322);
      END_STATE();
    case 27:
      if (lookahead == ')') ADVANCE(321);
      END_STATE();
    case 28:
      if (lookahead == '-') ADVANCE(33);
      END_STATE();
    case 29:
      if (lookahead == '-') ADVANCE(32);
      if (lookahead == '2') ADVANCE(271);
      if (lookahead == '4') ADVANCE(273);
      END_STATE();
    case 30:
      if (lookahead == '2') ADVANCE(347);
      if (lookahead == '4') ADVANCE(346);
      END_STATE();
    case 31:
      if (lookahead == '2') ADVANCE(344);
      if (lookahead == '4') ADVANCE(345);
      END_STATE();
    case 32:
      if (lookahead == '2') ADVANCE(269);
      if (lookahead == '4') ADVANCE(273);
      END_STATE();
    case 33:
      if (lookahead == '4') ADVANCE(275);
      END_STATE();
    case 34:
      if (lookahead == '5') ADVANCE(19);
      END_STATE();
    case 35:
      if (lookahead == '5') ADVANCE(20);
      END_STATE();
    case 36:
      if (lookahead == '5') ADVANCE(21);
      END_STATE();
    case 37:
      if (lookahead == '5') ADVANCE(22);
      END_STATE();
    case 38:
      if (lookahead == '9') ADVANCE(23);
      END_STATE();
    case 39:
      if (lookahead == '9') ADVANCE(24);
      END_STATE();
    case 40:
      if (lookahead == '9') ADVANCE(25);
      END_STATE();
    case 41:
      if (lookahead == '9') ADVANCE(26);
      END_STATE();
    case 42:
      if (lookahead == '9') ADVANCE(27);
      END_STATE();
    case 43:
      if (lookahead == 'I') ADVANCE(310);
      if (lookahead == 'V') ADVANCE(309);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(193);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(45);
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(305);
      END_STATE();
    case 44:
      if (lookahead == 'I') ADVANCE(310);
      if (lookahead == 'V') ADVANCE(309);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(45);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(44);
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(305);
      END_STATE();
    case 45:
      if (lookahead == 'I') ADVANCE(310);
      if (lookahead == 'V') ADVANCE(309);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(45);
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(305);
      END_STATE();
    case 46:
      if (lookahead == 'J') ADVANCE(333);
      END_STATE();
    case 47:
      if (lookahead == 'N') ADVANCE(342);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(168);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(236);
      END_STATE();
    case 49:
      if (lookahead == 'd') ADVANCE(48);
      END_STATE();
    case 50:
      if (lookahead == 'd') ADVANCE(48);
      if (lookahead == 'u') ADVANCE(53);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(155);
      END_STATE();
    case 51:
      if (lookahead == 'd') ADVANCE(48);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(155);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 53:
      if (lookahead == 'g') ADVANCE(349);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(60);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(176);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(154);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(66);
      END_STATE();
    case 56:
      if (lookahead == 'j') ADVANCE(332);
      END_STATE();
    case 57:
      if (lookahead == 'j') ADVANCE(331);
      END_STATE();
    case 58:
      if (lookahead == 'm') ADVANCE(55);
      if (lookahead == 'n') ADVANCE(365);
      if (lookahead == 'v') ADVANCE(52);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(203);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(103);
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(359);
      END_STATE();
    case 59:
      if (lookahead == 'm') ADVANCE(55);
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(359);
      END_STATE();
    case 60:
      if (lookahead == 'm') ADVANCE(348);
      END_STATE();
    case 61:
      if (lookahead == 'n') ADVANCE(341);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(168);
      END_STATE();
    case 62:
      if (lookahead == 'n') ADVANCE(340);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(168);
      END_STATE();
    case 63:
      if (lookahead == 'r') ADVANCE(366);
      END_STATE();
    case 64:
      if (lookahead == 's') ADVANCE(30);
      END_STATE();
    case 65:
      if (lookahead == 's') ADVANCE(31);
      END_STATE();
    case 66:
      if (lookahead == 't') ADVANCE(232);
      END_STATE();
    case 67:
      if (lookahead == 'u') ADVANCE(64);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(71);
      END_STATE();
    case 68:
      if (lookahead == 'u') ADVANCE(65);
      END_STATE();
    case 69:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(218);
      END_STATE();
    case 70:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(88);
      END_STATE();
    case 71:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(191);
      END_STATE();
    case 72:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(228);
      END_STATE();
    case 73:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 74:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(134);
      END_STATE();
    case 75:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(177);
      END_STATE();
    case 76:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(143);
      END_STATE();
    case 77:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(198);
      END_STATE();
    case 78:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(201);
      END_STATE();
    case 79:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(221);
      END_STATE();
    case 80:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(77);
      END_STATE();
    case 81:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(78);
      END_STATE();
    case 82:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(176);
      END_STATE();
    case 83:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(203);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(103);
      END_STATE();
    case 84:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(205);
      END_STATE();
    case 85:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(114);
      END_STATE();
    case 86:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(211);
      END_STATE();
    case 87:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(117);
      END_STATE();
    case 88:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(254);
      END_STATE();
    case 89:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(33);
      END_STATE();
    case 90:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(28);
      END_STATE();
    case 91:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(270);
      END_STATE();
    case 92:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(10);
      END_STATE();
    case 93:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(152);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(173);
      END_STATE();
    case 94:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(167);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(174);
      END_STATE();
    case 95:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(12);
      END_STATE();
    case 96:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(14);
      END_STATE();
    case 97:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(16);
      END_STATE();
    case 98:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(225);
      END_STATE();
    case 99:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(266);
      END_STATE();
    case 100:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(3);
      END_STATE();
    case 101:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(253);
      END_STATE();
    case 102:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(249);
      END_STATE();
    case 103:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(141);
      END_STATE();
    case 104:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(184);
      END_STATE();
    case 105:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(189);
      END_STATE();
    case 106:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(183);
      END_STATE();
    case 107:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 108:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(117);
      END_STATE();
    case 109:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(180);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(129);
      END_STATE();
    case 110:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(157);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(156);
      END_STATE();
    case 111:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(75);
      END_STATE();
    case 112:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(5);
      END_STATE();
    case 113:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(159);
      END_STATE();
    case 114:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(169);
      END_STATE();
    case 115:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(224);
      END_STATE();
    case 116:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(138);
      END_STATE();
    case 117:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(74);
      END_STATE();
    case 118:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(140);
      END_STATE();
    case 119:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(142);
      END_STATE();
    case 120:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(73);
      END_STATE();
    case 121:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(146);
      END_STATE();
    case 122:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(70);
      END_STATE();
    case 123:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(144);
      END_STATE();
    case 124:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(148);
      END_STATE();
    case 125:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(199);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      END_STATE();
    case 126:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(165);
      END_STATE();
    case 127:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(71);
      END_STATE();
    case 128:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(117);
      END_STATE();
    case 129:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(227);
      END_STATE();
    case 130:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(230);
      END_STATE();
    case 131:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(72);
      END_STATE();
    case 132:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(163);
      END_STATE();
    case 133:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(117);
      END_STATE();
    case 134:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(247);
      END_STATE();
    case 135:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(287);
      END_STATE();
    case 136:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(291);
      END_STATE();
    case 137:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(251);
      END_STATE();
    case 138:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(214);
      END_STATE();
    case 139:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(89);
      END_STATE();
    case 140:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(215);
      END_STATE();
    case 141:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(6);
      END_STATE();
    case 142:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(216);
      END_STATE();
    case 143:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 144:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(217);
      END_STATE();
    case 145:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(229);
      END_STATE();
    case 146:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(162);
      END_STATE();
    case 147:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(160);
      END_STATE();
    case 148:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(220);
      END_STATE();
    case 149:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(176);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(154);
      END_STATE();
    case 150:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(133);
      END_STATE();
    case 151:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(1);
      END_STATE();
    case 152:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(222);
      END_STATE();
    case 153:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(82);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(87);
      END_STATE();
    case 154:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(172);
      END_STATE();
    case 155:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(128);
      END_STATE();
    case 156:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(196);
      END_STATE();
    case 157:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(185);
      END_STATE();
    case 158:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(202);
      END_STATE();
    case 159:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(181);
      END_STATE();
    case 160:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(206);
      END_STATE();
    case 161:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(170);
      END_STATE();
    case 162:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(178);
      END_STATE();
    case 163:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(145);
      END_STATE();
    case 164:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(158);
      END_STATE();
    case 165:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(137);
      END_STATE();
    case 166:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(219);
      END_STATE();
    case 167:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(223);
      END_STATE();
    case 168:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(130);
      END_STATE();
    case 169:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(190);
      END_STATE();
    case 170:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(210);
      END_STATE();
    case 171:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(175);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(256);
      END_STATE();
    case 172:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(29);
      END_STATE();
    case 173:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(281);
      END_STATE();
    case 174:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(285);
      END_STATE();
    case 175:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(104);
      END_STATE();
    case 176:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(117);
      END_STATE();
    case 177:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(132);
      END_STATE();
    case 178:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(244);
      END_STATE();
    case 179:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(213);
      END_STATE();
    case 180:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(226);
      END_STATE();
    case 181:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(88);
      END_STATE();
    case 182:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(101);
      END_STATE();
    case 183:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(195);
      END_STATE();
    case 184:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(7);
      END_STATE();
    case 185:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(92);
      END_STATE();
    case 186:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(120);
      END_STATE();
    case 187:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(164);
      END_STATE();
    case 188:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(122);
      END_STATE();
    case 189:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 190:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(97);
      END_STATE();
    case 191:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(112);
      END_STATE();
    case 192:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(277);
      END_STATE();
    case 193:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(194);
      END_STATE();
    case 194:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(2);
      END_STATE();
    case 195:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(126);
      END_STATE();
    case 196:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(99);
      END_STATE();
    case 197:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(207);
      END_STATE();
    case 198:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(192);
      END_STATE();
    case 199:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(8);
      END_STATE();
    case 200:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(13);
      END_STATE();
    case 201:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(200);
      END_STATE();
    case 202:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(279);
      END_STATE();
    case 203:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(69);
      END_STATE();
    case 204:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(4);
      END_STATE();
    case 205:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(212);
      END_STATE();
    case 206:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(102);
      END_STATE();
    case 207:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(179);
      END_STATE();
    case 208:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(186);
      END_STATE();
    case 209:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(188);
      END_STATE();
    case 210:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(15);
      END_STATE();
    case 211:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(79);
      END_STATE();
    case 212:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(182);
      END_STATE();
    case 213:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(84);
      END_STATE();
    case 214:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(260);
      END_STATE();
    case 215:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(262);
      END_STATE();
    case 216:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(264);
      END_STATE();
    case 217:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(258);
      END_STATE();
    case 218:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(100);
      END_STATE();
    case 219:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(105);
      END_STATE();
    case 220:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(106);
      END_STATE();
    case 221:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(107);
      END_STATE();
    case 222:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(135);
      END_STATE();
    case 223:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(136);
      END_STATE();
    case 224:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(168);
      END_STATE();
    case 225:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(231);
      END_STATE();
    case 226:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(108);
      END_STATE();
    case 227:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(255);
      END_STATE();
    case 228:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(9);
      END_STATE();
    case 229:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(267);
      END_STATE();
    case 230:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(87);
      END_STATE();
    case 231:
      if (lookahead == ' ' ||
          lookahead == ':' ||
          lookahead == '=') ADVANCE(234);
      if (('A' <= lookahead && lookahead <= 'G')) ADVANCE(243);
      END_STATE();
    case 232:
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(359);
      END_STATE();
    case 233:
      if (('0' <= lookahead && lookahead <= '3')) ADVANCE(296);
      END_STATE();
    case 234:
      if (('A' <= lookahead && lookahead <= 'G')) ADVANCE(243);
      END_STATE();
    case 235:
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(315);
      END_STATE();
    case 236:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(357);
      END_STATE();
    case 237:
      if (eof) ADVANCE(238);
      if (lookahead == '\'') ADVANCE(297);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ',') ADVANCE(298);
      if (lookahead == '-') ADVANCE(292);
      if (lookahead == '/') ADVANCE(364);
      if (lookahead == '1') ADVANCE(314);
      if (lookahead == '2') ADVANCE(312);
      if (lookahead == '3') ADVANCE(313);
      if (lookahead == 'A') ADVANCE(300);
      if (lookahead == 'B') ADVANCE(299);
      if (lookahead == 'C') ADVANCE(301);
      if (lookahead == 'D') ADVANCE(302);
      if (lookahead == 'I') ADVANCE(311);
      if (lookahead == 'O') ADVANCE(83);
      if (lookahead == 'V') ADVANCE(309);
      if (lookahead == '^') ADVANCE(233);
      if (lookahead == 'a') ADVANCE(51);
      if (lookahead == 'b') ADVANCE(43);
      if (lookahead == 'c') ADVANCE(110);
      if (lookahead == 'd') ADVANCE(149);
      if (lookahead == 'i') ADVANCE(150);
      if (lookahead == 'o') ADVANCE(58);
      if (lookahead == '|') ADVANCE(239);
      if (lookahead == 8594) ADVANCE(294);
      if (lookahead == 9837) ADVANCE(45);
      if (lookahead == 12539) ADVANCE(295);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(98);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(153);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(115);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(151);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(109);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(161);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(127);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(171);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(44);
      if (('E' <= lookahead && lookahead <= 'G')) ADVANCE(304);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(237)
      if (('4' <= lookahead && lookahead <= '7')) ADVANCE(305);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_bar);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_bar_slash);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_key);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == 'M') ADVANCE(121);
      if (lookahead == 'm') ADVANCE(245);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(241);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(242);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == 'M') ADVANCE(121);
      if (lookahead == 'm') ADVANCE(245);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(241);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(242);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(243);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(241);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(241);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(146);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_scale);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_scale);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(246);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_mode_chord_over_bass_note);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_mode_chord_over_bass_note);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(248);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_mode_slash_chord_inversion);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_mode_slash_chord_inversion);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(250);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_mode_polychord);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ' ') ADVANCE(209);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(252);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(252);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(252);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(113);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(252);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(254);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_mode_root_inv);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_mode_root_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(257);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_mode_1st_inv);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_mode_1st_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(259);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_mode_2nd_inv);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_mode_2nd_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(261);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_mode_3rd_inv);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_mode_3rd_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(263);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_mode_close);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_mode_close);
      if (lookahead == ' ') ADVANCE(111);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(265);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_mode_close);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(265);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_mode_drop2);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_mode_drop2);
      if (lookahead == '-') ADVANCE(76);
      if ((',' <= lookahead && lookahead <= '.')) ADVANCE(268);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_mode_drop2);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(268);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_mode_drop2);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(268);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(139);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_mode_drop4);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_mode_drop4);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(272);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_mode_drop2and4);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_mode_drop2and4);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(274);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_mode_no_bass);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_mode_no_bass);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(276);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_mode_bass_is_root);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_mode_bass_is_root);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(278);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_octave_up);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_octave_up);
      if (lookahead == '/') ADVANCE(283);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(280);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_octave_up_upper);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_octave_up_upper);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(282);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_octave_up_lower);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_octave_up_lower);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(284);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_octave_down);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_octave_down);
      if (lookahead == '/') ADVANCE(289);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(286);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_octave_down_upper);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_octave_down_upper);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(288);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_octave_down_lower);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_octave_down_lower);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(290);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '7') ADVANCE(339);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_chord_inversion);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_octave_offset);
      if (lookahead == '\'') ADVANCE(297);
      if (lookahead == ',') ADVANCE(298);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_octave_offset);
      if (lookahead == ',') ADVANCE(298);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(193);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(303);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(304);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(155);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(303);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(304);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(157);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(156);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(303);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(304);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(176);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(154);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(303);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(304);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(303);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(303);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(304);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_degree);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == '.') ADVANCE(235);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == '1') ADVANCE(352);
      if (lookahead == '3') ADVANCE(351);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(204);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(305);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(308);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(308);
      if (lookahead == 'V') ADVANCE(305);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(308);
      if (lookahead == 'V') ADVANCE(305);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(133);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(95);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(96);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(204);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(aux_sym_quality_base_token1);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(315);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(anon_sym_maj9);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(anon_sym_Maj9);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_MAJ9);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_M9);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_9);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(anon_sym_maj_LPAREN9_RPAREN);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(anon_sym_Maj_LPAREN9_RPAREN);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(anon_sym_MAJ_LPAREN9_RPAREN);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_M_LPAREN9_RPAREN);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(anon_sym_LPAREN9_RPAREN);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(anon_sym_maj7);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(anon_sym_Maj7);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(anon_sym_MAJ7);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(anon_sym_M7);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_3);
      if (lookahead == '(') ADVANCE(39);
      if (lookahead == '9') ADVANCE(320);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(anon_sym_maj);
      if (lookahead == '(') ADVANCE(42);
      if (lookahead == '7') ADVANCE(326);
      if (lookahead == '9') ADVANCE(316);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(anon_sym_Maj);
      if (lookahead == '(') ADVANCE(41);
      if (lookahead == '7') ADVANCE(327);
      if (lookahead == '9') ADVANCE(317);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(anon_sym_MAJ);
      if (lookahead == '(') ADVANCE(40);
      if (lookahead == '7') ADVANCE(328);
      if (lookahead == '9') ADVANCE(318);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(anon_sym_M);
      if (lookahead == '(') ADVANCE(38);
      if (lookahead == '7') ADVANCE(329);
      if (lookahead == '9') ADVANCE(319);
      if (lookahead == 'A') ADVANCE(46);
      if (lookahead == 'I') ADVANCE(47);
      if (lookahead == 'a') ADVANCE(56);
      if (lookahead == 'i') ADVANCE(61);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(anon_sym_min7);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(anon_sym_Min7);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(anon_sym_MIN7);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(anon_sym_m7);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_DASH7);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_min);
      if (lookahead == '7') ADVANCE(335);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_Min);
      if (lookahead == '7') ADVANCE(336);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_MIN);
      if (lookahead == '7') ADVANCE(337);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_m);
      if (lookahead == '7') ADVANCE(338);
      if (lookahead == 'I') ADVANCE(224);
      if (lookahead == 'a') ADVANCE(57);
      if (lookahead == 'i') ADVANCE(62);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_7sus2);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(anon_sym_7sus4);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(anon_sym_sus4);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(anon_sym_sus2);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(anon_sym_dim);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(anon_sym_aug);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(anon_sym_13);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(anon_sym_11);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(anon_sym_92);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(anon_sym_7);
      if (lookahead == 's') ADVANCE(68);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(anon_sym_6);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      if (lookahead == ')') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(357);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      if (lookahead == ')') ADVANCE(358);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(anon_sym_LPARENb5_RPAREN);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(anon_sym_LPAREN_DASH5_RPAREN);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(anon_sym_LPAREN_PLUS5_RPAREN);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(anon_sym_LPAREN_POUND5_RPAREN);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(240);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(86);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(anon_sym_on);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_over);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 237},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 237},
  [7] = {.lex_state = 237},
  [8] = {.lex_state = 237},
  [9] = {.lex_state = 237},
  [10] = {.lex_state = 237},
  [11] = {.lex_state = 237},
  [12] = {.lex_state = 237},
  [13] = {.lex_state = 237},
  [14] = {.lex_state = 237},
  [15] = {.lex_state = 237},
  [16] = {.lex_state = 237},
  [17] = {.lex_state = 237},
  [18] = {.lex_state = 237},
  [19] = {.lex_state = 237},
  [20] = {.lex_state = 237},
  [21] = {.lex_state = 237},
  [22] = {.lex_state = 237},
  [23] = {.lex_state = 237},
  [24] = {.lex_state = 237},
  [25] = {.lex_state = 237},
  [26] = {.lex_state = 237},
  [27] = {.lex_state = 237},
  [28] = {.lex_state = 237},
  [29] = {.lex_state = 237},
  [30] = {.lex_state = 237},
  [31] = {.lex_state = 237},
  [32] = {.lex_state = 237},
  [33] = {.lex_state = 237},
  [34] = {.lex_state = 237},
  [35] = {.lex_state = 237},
  [36] = {.lex_state = 237},
  [37] = {.lex_state = 237},
  [38] = {.lex_state = 237},
  [39] = {.lex_state = 237},
  [40] = {.lex_state = 237},
  [41] = {.lex_state = 237},
  [42] = {.lex_state = 237},
  [43] = {.lex_state = 237},
  [44] = {.lex_state = 237},
  [45] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_bar] = ACTIONS(1),
    [sym_bar_slash] = ACTIONS(1),
    [sym_key] = ACTIONS(1),
    [sym_scale] = ACTIONS(1),
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
    [sym_degree] = ACTIONS(1),
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
    [anon_sym_3] = ACTIONS(1),
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
    [anon_sym_6] = ACTIONS(1),
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
    [sym_source_file] = STATE(45),
    [sym__event] = STATE(19),
    [sym_chord] = STATE(19),
    [sym_root] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_bar] = ACTIONS(5),
    [sym_bar_slash] = ACTIONS(5),
    [sym_key] = ACTIONS(5),
    [sym_scale] = ACTIONS(5),
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
    [sym_degree] = ACTIONS(11),
  },
  [2] = {
    [sym_quality] = STATE(13),
    [sym_quality_base] = STATE(6),
    [sym_quality_modifier] = STATE(10),
    [sym_bass] = STATE(31),
    [sym_on_bass] = STATE(31),
    [aux_sym_quality_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_bar] = ACTIONS(13),
    [sym_bar_slash] = ACTIONS(13),
    [sym_key] = ACTIONS(13),
    [sym_scale] = ACTIONS(13),
    [sym_mode_chord_over_bass_note] = ACTIONS(13),
    [sym_mode_slash_chord_inversion] = ACTIONS(13),
    [sym_mode_polychord] = ACTIONS(13),
    [sym_mode_root_inv] = ACTIONS(13),
    [sym_mode_1st_inv] = ACTIONS(13),
    [sym_mode_2nd_inv] = ACTIONS(13),
    [sym_mode_3rd_inv] = ACTIONS(13),
    [sym_mode_close] = ACTIONS(13),
    [sym_mode_drop2] = ACTIONS(15),
    [sym_mode_drop4] = ACTIONS(13),
    [sym_mode_drop2and4] = ACTIONS(13),
    [sym_mode_no_bass] = ACTIONS(13),
    [sym_mode_bass_is_root] = ACTIONS(13),
    [sym_octave_up] = ACTIONS(15),
    [sym_octave_up_upper] = ACTIONS(13),
    [sym_octave_up_lower] = ACTIONS(13),
    [sym_octave_down] = ACTIONS(15),
    [sym_octave_down_upper] = ACTIONS(13),
    [sym_octave_down_lower] = ACTIONS(13),
    [anon_sym_DASH] = ACTIONS(17),
    [anon_sym_] = ACTIONS(13),
    [anon_sym_2] = ACTIONS(13),
    [sym_chord_inversion] = ACTIONS(20),
    [sym_octave_offset] = ACTIONS(22),
    [sym_note] = ACTIONS(15),
    [sym_degree] = ACTIONS(15),
    [aux_sym_quality_base_token1] = ACTIONS(24),
    [anon_sym_maj9] = ACTIONS(24),
    [anon_sym_Maj9] = ACTIONS(24),
    [anon_sym_MAJ9] = ACTIONS(24),
    [anon_sym_M9] = ACTIONS(24),
    [anon_sym_9] = ACTIONS(24),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_maj7] = ACTIONS(24),
    [anon_sym_Maj7] = ACTIONS(24),
    [anon_sym_MAJ7] = ACTIONS(24),
    [anon_sym_M7] = ACTIONS(24),
    [anon_sym_3] = ACTIONS(26),
    [anon_sym_maj] = ACTIONS(26),
    [anon_sym_Maj] = ACTIONS(26),
    [anon_sym_MAJ] = ACTIONS(26),
    [anon_sym_M] = ACTIONS(26),
    [anon_sym_min7] = ACTIONS(24),
    [anon_sym_Min7] = ACTIONS(24),
    [anon_sym_MIN7] = ACTIONS(24),
    [anon_sym_m7] = ACTIONS(24),
    [anon_sym_DASH7] = ACTIONS(24),
    [anon_sym_min] = ACTIONS(26),
    [anon_sym_Min] = ACTIONS(26),
    [anon_sym_MIN] = ACTIONS(26),
    [anon_sym_m] = ACTIONS(26),
    [anon_sym_7sus2] = ACTIONS(24),
    [anon_sym_7sus4] = ACTIONS(24),
    [anon_sym_sus4] = ACTIONS(24),
    [anon_sym_sus2] = ACTIONS(24),
    [anon_sym_dim] = ACTIONS(24),
    [anon_sym_aug] = ACTIONS(24),
    [anon_sym_PLUS] = ACTIONS(24),
    [anon_sym_13] = ACTIONS(24),
    [anon_sym_11] = ACTIONS(24),
    [anon_sym_92] = ACTIONS(24),
    [anon_sym_7] = ACTIONS(26),
    [anon_sym_6] = ACTIONS(24),
    [aux_sym_quality_modifier_token1] = ACTIONS(28),
    [aux_sym_quality_modifier_token2] = ACTIONS(28),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(28),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(28),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(28),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(28),
    [anon_sym_SLASH] = ACTIONS(30),
    [anon_sym_on] = ACTIONS(32),
    [anon_sym_over] = ACTIONS(32),
  },
  [3] = {
    [sym_quality] = STATE(25),
    [sym_quality_base] = STATE(6),
    [sym_quality_modifier] = STATE(10),
    [aux_sym_quality_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(34),
    [sym_bar] = ACTIONS(34),
    [sym_bar_slash] = ACTIONS(34),
    [sym_key] = ACTIONS(34),
    [sym_scale] = ACTIONS(34),
    [sym_mode_chord_over_bass_note] = ACTIONS(34),
    [sym_mode_slash_chord_inversion] = ACTIONS(34),
    [sym_mode_polychord] = ACTIONS(34),
    [sym_mode_root_inv] = ACTIONS(34),
    [sym_mode_1st_inv] = ACTIONS(34),
    [sym_mode_2nd_inv] = ACTIONS(34),
    [sym_mode_3rd_inv] = ACTIONS(34),
    [sym_mode_close] = ACTIONS(34),
    [sym_mode_drop2] = ACTIONS(36),
    [sym_mode_drop4] = ACTIONS(34),
    [sym_mode_drop2and4] = ACTIONS(34),
    [sym_mode_no_bass] = ACTIONS(34),
    [sym_mode_bass_is_root] = ACTIONS(34),
    [sym_octave_up] = ACTIONS(36),
    [sym_octave_up_upper] = ACTIONS(34),
    [sym_octave_up_lower] = ACTIONS(34),
    [sym_octave_down] = ACTIONS(36),
    [sym_octave_down_upper] = ACTIONS(34),
    [sym_octave_down_lower] = ACTIONS(34),
    [anon_sym_DASH] = ACTIONS(38),
    [anon_sym_] = ACTIONS(34),
    [anon_sym_2] = ACTIONS(34),
    [sym_chord_inversion] = ACTIONS(41),
    [sym_octave_offset] = ACTIONS(43),
    [sym_note] = ACTIONS(36),
    [sym_degree] = ACTIONS(36),
    [aux_sym_quality_base_token1] = ACTIONS(24),
    [anon_sym_maj9] = ACTIONS(24),
    [anon_sym_Maj9] = ACTIONS(24),
    [anon_sym_MAJ9] = ACTIONS(24),
    [anon_sym_M9] = ACTIONS(24),
    [anon_sym_9] = ACTIONS(24),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(24),
    [anon_sym_maj7] = ACTIONS(24),
    [anon_sym_Maj7] = ACTIONS(24),
    [anon_sym_MAJ7] = ACTIONS(24),
    [anon_sym_M7] = ACTIONS(24),
    [anon_sym_3] = ACTIONS(26),
    [anon_sym_maj] = ACTIONS(26),
    [anon_sym_Maj] = ACTIONS(26),
    [anon_sym_MAJ] = ACTIONS(26),
    [anon_sym_M] = ACTIONS(26),
    [anon_sym_min7] = ACTIONS(24),
    [anon_sym_Min7] = ACTIONS(24),
    [anon_sym_MIN7] = ACTIONS(24),
    [anon_sym_m7] = ACTIONS(24),
    [anon_sym_DASH7] = ACTIONS(24),
    [anon_sym_min] = ACTIONS(26),
    [anon_sym_Min] = ACTIONS(26),
    [anon_sym_MIN] = ACTIONS(26),
    [anon_sym_m] = ACTIONS(26),
    [anon_sym_7sus2] = ACTIONS(24),
    [anon_sym_7sus4] = ACTIONS(24),
    [anon_sym_sus4] = ACTIONS(24),
    [anon_sym_sus2] = ACTIONS(24),
    [anon_sym_dim] = ACTIONS(24),
    [anon_sym_aug] = ACTIONS(24),
    [anon_sym_PLUS] = ACTIONS(24),
    [anon_sym_13] = ACTIONS(24),
    [anon_sym_11] = ACTIONS(24),
    [anon_sym_92] = ACTIONS(24),
    [anon_sym_7] = ACTIONS(26),
    [anon_sym_6] = ACTIONS(24),
    [aux_sym_quality_modifier_token1] = ACTIONS(28),
    [aux_sym_quality_modifier_token2] = ACTIONS(28),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(28),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(28),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(28),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(28),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(45),
    [sym_bar] = ACTIONS(45),
    [sym_bar_slash] = ACTIONS(45),
    [sym_key] = ACTIONS(45),
    [sym_scale] = ACTIONS(45),
    [sym_mode_chord_over_bass_note] = ACTIONS(45),
    [sym_mode_slash_chord_inversion] = ACTIONS(45),
    [sym_mode_polychord] = ACTIONS(45),
    [sym_mode_root_inv] = ACTIONS(45),
    [sym_mode_1st_inv] = ACTIONS(45),
    [sym_mode_2nd_inv] = ACTIONS(45),
    [sym_mode_3rd_inv] = ACTIONS(45),
    [sym_mode_close] = ACTIONS(45),
    [sym_mode_drop2] = ACTIONS(47),
    [sym_mode_drop4] = ACTIONS(45),
    [sym_mode_drop2and4] = ACTIONS(45),
    [sym_mode_no_bass] = ACTIONS(45),
    [sym_mode_bass_is_root] = ACTIONS(45),
    [sym_octave_up] = ACTIONS(47),
    [sym_octave_up_upper] = ACTIONS(45),
    [sym_octave_up_lower] = ACTIONS(45),
    [sym_octave_down] = ACTIONS(47),
    [sym_octave_down_upper] = ACTIONS(45),
    [sym_octave_down_lower] = ACTIONS(45),
    [anon_sym_DASH] = ACTIONS(47),
    [anon_sym_] = ACTIONS(45),
    [anon_sym_2] = ACTIONS(45),
    [sym_chord_inversion] = ACTIONS(45),
    [sym_octave_offset] = ACTIONS(45),
    [sym_note] = ACTIONS(47),
    [sym_degree] = ACTIONS(47),
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
    [anon_sym_3] = ACTIONS(47),
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
    [anon_sym_6] = ACTIONS(45),
    [aux_sym_quality_modifier_token1] = ACTIONS(45),
    [aux_sym_quality_modifier_token2] = ACTIONS(45),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(45),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(45),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(45),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(45),
    [anon_sym_SLASH] = ACTIONS(47),
    [anon_sym_on] = ACTIONS(45),
    [anon_sym_over] = ACTIONS(45),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(49),
    [sym_bar] = ACTIONS(49),
    [sym_bar_slash] = ACTIONS(49),
    [sym_key] = ACTIONS(49),
    [sym_scale] = ACTIONS(49),
    [sym_mode_chord_over_bass_note] = ACTIONS(49),
    [sym_mode_slash_chord_inversion] = ACTIONS(49),
    [sym_mode_polychord] = ACTIONS(49),
    [sym_mode_root_inv] = ACTIONS(49),
    [sym_mode_1st_inv] = ACTIONS(49),
    [sym_mode_2nd_inv] = ACTIONS(49),
    [sym_mode_3rd_inv] = ACTIONS(49),
    [sym_mode_close] = ACTIONS(49),
    [sym_mode_drop2] = ACTIONS(51),
    [sym_mode_drop4] = ACTIONS(49),
    [sym_mode_drop2and4] = ACTIONS(49),
    [sym_mode_no_bass] = ACTIONS(49),
    [sym_mode_bass_is_root] = ACTIONS(49),
    [sym_octave_up] = ACTIONS(51),
    [sym_octave_up_upper] = ACTIONS(49),
    [sym_octave_up_lower] = ACTIONS(49),
    [sym_octave_down] = ACTIONS(51),
    [sym_octave_down_upper] = ACTIONS(49),
    [sym_octave_down_lower] = ACTIONS(49),
    [anon_sym_DASH] = ACTIONS(51),
    [anon_sym_] = ACTIONS(49),
    [anon_sym_2] = ACTIONS(49),
    [sym_chord_inversion] = ACTIONS(49),
    [sym_octave_offset] = ACTIONS(49),
    [sym_note] = ACTIONS(51),
    [sym_degree] = ACTIONS(51),
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
    [anon_sym_3] = ACTIONS(51),
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
    [anon_sym_6] = ACTIONS(49),
    [aux_sym_quality_modifier_token1] = ACTIONS(49),
    [aux_sym_quality_modifier_token2] = ACTIONS(49),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(49),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(49),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(49),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(49),
    [anon_sym_SLASH] = ACTIONS(51),
    [anon_sym_on] = ACTIONS(49),
    [anon_sym_over] = ACTIONS(49),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    STATE(8), 1,
      aux_sym_quality_repeat1,
    STATE(10), 1,
      sym_quality_modifier,
    ACTIONS(28), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(55), 6,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
    ACTIONS(53), 28,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [53] = 5,
    STATE(7), 1,
      aux_sym_quality_repeat1,
    STATE(10), 1,
      sym_quality_modifier,
    ACTIONS(59), 6,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
    ACTIONS(61), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(57), 28,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [106] = 5,
    STATE(7), 1,
      aux_sym_quality_repeat1,
    STATE(10), 1,
      sym_quality_modifier,
    ACTIONS(28), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(66), 6,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
    ACTIONS(64), 28,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [159] = 5,
    STATE(7), 1,
      aux_sym_quality_repeat1,
    STATE(10), 1,
      sym_quality_modifier,
    ACTIONS(28), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(70), 6,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
    ACTIONS(68), 28,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [212] = 2,
    ACTIONS(74), 6,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
    ACTIONS(72), 34,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [257] = 2,
    ACTIONS(78), 6,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
    ACTIONS(76), 34,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [302] = 2,
    ACTIONS(82), 6,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
    ACTIONS(80), 34,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [347] = 7,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(88), 1,
      sym_chord_inversion,
    ACTIONS(90), 1,
      sym_octave_offset,
    ACTIONS(32), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(35), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(86), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(84), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [398] = 6,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(96), 1,
      sym_octave_offset,
    ACTIONS(32), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(34), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(94), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(92), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [446] = 6,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(102), 1,
      sym_octave_offset,
    ACTIONS(32), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(37), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(100), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(98), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [494] = 9,
    ACTIONS(104), 1,
      ts_builtin_sym_end,
    ACTIONS(115), 1,
      sym_note,
    ACTIONS(118), 1,
      sym_degree,
    STATE(2), 1,
      sym_root,
    STATE(43), 1,
      sym_separator,
    ACTIONS(109), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(112), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(16), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(106), 20,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [547] = 9,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    ACTIONS(121), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_root,
    STATE(43), 1,
      sym_separator,
    ACTIONS(125), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(127), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(16), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(123), 20,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [600] = 5,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(33), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(131), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(129), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [645] = 9,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    ACTIONS(133), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_root,
    STATE(43), 1,
      sym_separator,
    ACTIONS(127), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    ACTIONS(137), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    STATE(17), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(135), 20,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [698] = 5,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(41), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(141), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(139), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [743] = 5,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(38), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(145), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(143), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [788] = 5,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 2,
      anon_sym_on,
      anon_sym_over,
    STATE(32), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(149), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(147), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [833] = 6,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    STATE(3), 1,
      sym_root,
    STATE(29), 1,
      sym__lower,
    ACTIONS(153), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(151), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [877] = 6,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    STATE(3), 1,
      sym_root,
    STATE(30), 1,
      sym__lower,
    ACTIONS(157), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(155), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [921] = 4,
    ACTIONS(163), 1,
      sym_chord_inversion,
    ACTIONS(165), 1,
      sym_octave_offset,
    ACTIONS(161), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(159), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [961] = 3,
    ACTIONS(171), 1,
      sym_octave_offset,
    ACTIONS(169), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(167), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [998] = 3,
    ACTIONS(177), 1,
      sym_octave_offset,
    ACTIONS(175), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(173), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1035] = 2,
    ACTIONS(181), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(179), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1069] = 2,
    ACTIONS(185), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(183), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1103] = 2,
    ACTIONS(189), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(187), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1137] = 2,
    ACTIONS(193), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(191), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1171] = 2,
    ACTIONS(197), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(195), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
    ACTIONS(201), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(199), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1239] = 2,
    ACTIONS(205), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(203), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1273] = 2,
    ACTIONS(209), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(207), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1307] = 2,
    ACTIONS(211), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(104), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1341] = 2,
    ACTIONS(215), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(213), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1375] = 2,
    ACTIONS(219), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(217), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1409] = 2,
    ACTIONS(223), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(221), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1443] = 2,
    ACTIONS(227), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(225), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1477] = 2,
    ACTIONS(231), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(229), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1511] = 2,
    ACTIONS(235), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(233), 24,
      ts_builtin_sym_end,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1545] = 6,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    STATE(2), 1,
      sym_root,
    STATE(36), 2,
      sym__event,
      sym_chord,
    ACTIONS(239), 3,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(237), 20,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1586] = 2,
    ACTIONS(243), 5,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(241), 20,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
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
  [1616] = 1,
    ACTIONS(245), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 53,
  [SMALL_STATE(8)] = 106,
  [SMALL_STATE(9)] = 159,
  [SMALL_STATE(10)] = 212,
  [SMALL_STATE(11)] = 257,
  [SMALL_STATE(12)] = 302,
  [SMALL_STATE(13)] = 347,
  [SMALL_STATE(14)] = 398,
  [SMALL_STATE(15)] = 446,
  [SMALL_STATE(16)] = 494,
  [SMALL_STATE(17)] = 547,
  [SMALL_STATE(18)] = 600,
  [SMALL_STATE(19)] = 645,
  [SMALL_STATE(20)] = 698,
  [SMALL_STATE(21)] = 743,
  [SMALL_STATE(22)] = 788,
  [SMALL_STATE(23)] = 833,
  [SMALL_STATE(24)] = 877,
  [SMALL_STATE(25)] = 921,
  [SMALL_STATE(26)] = 961,
  [SMALL_STATE(27)] = 998,
  [SMALL_STATE(28)] = 1035,
  [SMALL_STATE(29)] = 1069,
  [SMALL_STATE(30)] = 1103,
  [SMALL_STATE(31)] = 1137,
  [SMALL_STATE(32)] = 1171,
  [SMALL_STATE(33)] = 1205,
  [SMALL_STATE(34)] = 1239,
  [SMALL_STATE(35)] = 1273,
  [SMALL_STATE(36)] = 1307,
  [SMALL_STATE(37)] = 1341,
  [SMALL_STATE(38)] = 1375,
  [SMALL_STATE(39)] = 1409,
  [SMALL_STATE(40)] = 1443,
  [SMALL_STATE(41)] = 1477,
  [SMALL_STATE(42)] = 1511,
  [SMALL_STATE(43)] = 1545,
  [SMALL_STATE(44)] = 1586,
  [SMALL_STATE(45)] = 1616,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 1, .production_id = 3),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 1, .production_id = 3),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_chord, 1, .production_id = 3), SHIFT(11),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [26] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [30] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 1, .production_id = 3),
  [36] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 1, .production_id = 3),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym__lower, 1, .production_id = 3), SHIFT(11),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1, .production_id = 1),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 1, .production_id = 1),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1, .production_id = 2),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 1, .production_id = 2),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 7),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 1, .production_id = 7),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 19),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 19),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 19), SHIFT_REPEAT(12),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 2, .production_id = 18),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 2, .production_id = 18),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 10),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 1, .production_id = 10),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 1, .production_id = 8),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quality_repeat1, 1, .production_id = 8),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_base, 1),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality_base, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_modifier, 1),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality_modifier, 1),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 6),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 6),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 4),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 4),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 15),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 15),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [109] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [112] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(44),
  [115] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [118] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [125] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 11),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 11),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 21),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 21),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 16),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 16),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 5),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 5),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 1),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bass, 1),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_on_bass, 1),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_on_bass, 1),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 6),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 6),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 15),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 15),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 4),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 4),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 5),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 5),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 2, .production_id = 14),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bass, 2, .production_id = 14),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_on_bass, 2, .production_id = 14),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_on_bass, 2, .production_id = 14),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 9),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 9),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 13),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 13),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 20),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 20),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 12),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 12),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 17),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 17),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 22),
  [215] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 22),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 23),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 23),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 11),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 11),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 16),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 16),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 5, .production_id = 24),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 5, .production_id = 24),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 4, .production_id = 21),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 4, .production_id = 21),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [239] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_separator, 1, .dynamic_precedence = 1),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_separator, 1, .dynamic_precedence = 1),
  [245] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
