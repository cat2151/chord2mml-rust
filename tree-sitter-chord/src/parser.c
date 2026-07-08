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
#define SYMBOL_COUNT 98
#define ALIAS_COUNT 0
#define TOKEN_COUNT 85
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 25

enum {
  sym_inline_abc = 1,
  sym_inline_mml = 2,
  sym_tempo = 3,
  sym_midi_pc = 4,
  sym_bar = 5,
  sym_bar_slash = 6,
  sym_key = 7,
  sym_scale = 8,
  sym_mode_chord_over_bass_note = 9,
  sym_mode_slash_chord_inversion = 10,
  sym_mode_polychord = 11,
  sym_mode_root_inv = 12,
  sym_mode_1st_inv = 13,
  sym_mode_2nd_inv = 14,
  sym_mode_3rd_inv = 15,
  sym_mode_close = 16,
  sym_mode_drop2 = 17,
  sym_mode_drop4 = 18,
  sym_mode_drop2and4 = 19,
  sym_mode_no_bass = 20,
  sym_mode_bass_is_root = 21,
  sym_octave_up = 22,
  sym_octave_up_upper = 23,
  sym_octave_up_lower = 24,
  sym_octave_down = 25,
  sym_octave_down_upper = 26,
  sym_octave_down_lower = 27,
  anon_sym_DASH = 28,
  anon_sym_ = 29,
  anon_sym_2 = 30,
  sym_chord_inversion = 31,
  sym_octave_offset = 32,
  sym_note = 33,
  sym_degree = 34,
  aux_sym_quality_base_token1 = 35,
  anon_sym_maj9 = 36,
  anon_sym_Maj9 = 37,
  anon_sym_MAJ9 = 38,
  anon_sym_M9 = 39,
  anon_sym_9 = 40,
  anon_sym_maj_LPAREN9_RPAREN = 41,
  anon_sym_Maj_LPAREN9_RPAREN = 42,
  anon_sym_MAJ_LPAREN9_RPAREN = 43,
  anon_sym_M_LPAREN9_RPAREN = 44,
  anon_sym_LPAREN9_RPAREN = 45,
  anon_sym_maj7 = 46,
  anon_sym_Maj7 = 47,
  anon_sym_MAJ7 = 48,
  anon_sym_M7 = 49,
  anon_sym_3 = 50,
  anon_sym_maj = 51,
  anon_sym_Maj = 52,
  anon_sym_MAJ = 53,
  anon_sym_M = 54,
  anon_sym_min7 = 55,
  anon_sym_Min7 = 56,
  anon_sym_MIN7 = 57,
  anon_sym_m7 = 58,
  anon_sym_DASH7 = 59,
  anon_sym_min = 60,
  anon_sym_Min = 61,
  anon_sym_MIN = 62,
  anon_sym_m = 63,
  anon_sym_7sus2 = 64,
  anon_sym_7sus4 = 65,
  anon_sym_sus4 = 66,
  anon_sym_sus2 = 67,
  anon_sym_dim = 68,
  anon_sym_aug = 69,
  anon_sym_PLUS = 70,
  anon_sym_13 = 71,
  anon_sym_11 = 72,
  anon_sym_92 = 73,
  anon_sym_7 = 74,
  anon_sym_6 = 75,
  aux_sym_quality_modifier_token1 = 76,
  aux_sym_quality_modifier_token2 = 77,
  anon_sym_LPARENb5_RPAREN = 78,
  anon_sym_LPAREN_DASH5_RPAREN = 79,
  anon_sym_LPAREN_PLUS5_RPAREN = 80,
  anon_sym_LPAREN_POUND5_RPAREN = 81,
  anon_sym_SLASH = 82,
  anon_sym_on = 83,
  anon_sym_over = 84,
  sym_source_file = 85,
  sym__event = 86,
  sym_separator = 87,
  sym_chord = 88,
  sym_root = 89,
  sym_quality = 90,
  sym_quality_base = 91,
  sym_quality_modifier = 92,
  sym__lower = 93,
  sym_bass = 94,
  sym_on_bass = 95,
  aux_sym_source_file_repeat1 = 96,
  aux_sym_quality_repeat1 = 97,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_inline_abc] = "inline_abc",
  [sym_inline_mml] = "inline_mml",
  [sym_tempo] = "tempo",
  [sym_midi_pc] = "midi_pc",
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
  [sym_inline_abc] = sym_inline_abc,
  [sym_inline_mml] = sym_inline_mml,
  [sym_tempo] = sym_tempo,
  [sym_midi_pc] = sym_midi_pc,
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
  [sym_inline_abc] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_mml] = {
    .visible = true,
    .named = true,
  },
  [sym_tempo] = {
    .visible = true,
    .named = true,
  },
  [sym_midi_pc] = {
    .visible = true,
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
      if (eof) ADVANCE(920);
      if (lookahead == '\'') ADVANCE(992);
      if (lookahead == '(') ADVANCE(54);
      if (lookahead == '+') ADVANCE(1051);
      if (lookahead == ',') ADVANCE(993);
      if (lookahead == '-') ADVANCE(988);
      if (lookahead == '/') ADVANCE(1065);
      if (lookahead == '1') ADVANCE(1005);
      if (lookahead == '2') ADVANCE(1013);
      if (lookahead == '3') ADVANCE(1014);
      if (lookahead == '4') ADVANCE(1004);
      if (lookahead == '5') ADVANCE(1003);
      if (lookahead == '6') ADVANCE(1056);
      if (lookahead == '7') ADVANCE(1055);
      if (lookahead == '9') ADVANCE(1054);
      if (lookahead == 'A') ADVANCE(997);
      if (lookahead == 'B') ADVANCE(995);
      if (lookahead == 'C') ADVANCE(996);
      if (lookahead == 'D') ADVANCE(998);
      if (lookahead == 'E') ADVANCE(994);
      if (lookahead == 'F') ADVANCE(999);
      if (lookahead == 'G') ADVANCE(1000);
      if (lookahead == 'I') ADVANCE(1010);
      if (lookahead == 'M') ADVANCE(1035);
      if (lookahead == 'O') ADVANCE(214);
      if (lookahead == 'S') ADVANCE(135);
      if (lookahead == 'V') ADVANCE(1012);
      if (lookahead == '^') ADVANCE(913);
      if (lookahead == 'a') ADVANCE(119);
      if (lookahead == 'b') ADVANCE(110);
      if (lookahead == 'c') ADVANCE(134);
      if (lookahead == 'd') ADVANCE(109);
      if (lookahead == 'e') ADVANCE(87);
      if (lookahead == 'f') ADVANCE(410);
      if (lookahead == 'g') ADVANCE(489);
      if (lookahead == 'i') ADVANCE(604);
      if (lookahead == 'm') ADVANCE(1044);
      if (lookahead == 'o') ADVANCE(116);
      if (lookahead == 's') ADVANCE(132);
      if (lookahead == 'v') ADVANCE(411);
      if (lookahead == '|') ADVANCE(934);
      if (lookahead == 8594) ADVANCE(989);
      if (lookahead == 9651) ADVANCE(1031);
      if (lookahead == 9837) ADVANCE(112);
      if (lookahead == 12539) ADVANCE(990);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(136);
      if (lookahead == 'J' ||
          lookahead == 'j') ADVANCE(137);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(154);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(311);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(308);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(149);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(152);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(673);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(153);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(893);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(111);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(205);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(616);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(378);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(288);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(213);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(290);
      if (lookahead == '-') ADVANCE(290);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(230);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(231);
      END_STATE();
    case 8:
      if (lookahead == ' ') ADVANCE(904);
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(55);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(56);
      END_STATE();
    case 11:
      if (lookahead == ' ') ADVANCE(222);
      END_STATE();
    case 12:
      if (lookahead == ' ') ADVANCE(57);
      END_STATE();
    case 13:
      if (lookahead == ' ') ADVANCE(364);
      END_STATE();
    case 14:
      if (lookahead == ' ') ADVANCE(365);
      END_STATE();
    case 15:
      if (lookahead == ' ') ADVANCE(224);
      END_STATE();
    case 16:
      if (lookahead == ' ') ADVANCE(220);
      END_STATE();
    case 17:
      if (lookahead == ' ') ADVANCE(768);
      END_STATE();
    case 18:
      if (lookahead == ' ') ADVANCE(397);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(47);
      END_STATE();
    case 19:
      if (lookahead == ' ') ADVANCE(263);
      END_STATE();
    case 20:
      if (lookahead == ' ') ADVANCE(158);
      END_STATE();
    case 21:
      if (lookahead == ' ') ADVANCE(823);
      END_STATE();
    case 22:
      if (lookahead == ' ') ADVANCE(790);
      END_STATE();
    case 23:
      if (lookahead == ' ') ADVANCE(245);
      END_STATE();
    case 24:
      if (lookahead == ' ') ADVANCE(646);
      END_STATE();
    case 25:
      if (lookahead == ' ') ADVANCE(191);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(353);
      END_STATE();
    case 26:
      if (lookahead == ' ') ADVANCE(746);
      END_STATE();
    case 27:
      if (lookahead == ' ') ADVANCE(746);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead == ' ') ADVANCE(376);
      END_STATE();
    case 29:
      if (lookahead == ' ') ADVANCE(292);
      if (lookahead == '-') ADVANCE(292);
      END_STATE();
    case 30:
      if (lookahead == ' ') ADVANCE(677);
      END_STATE();
    case 31:
      if (lookahead == ' ') ADVANCE(427);
      END_STATE();
    case 32:
      if (lookahead == ' ') ADVANCE(377);
      END_STATE();
    case 33:
      if (lookahead == ' ') ADVANCE(221);
      END_STATE();
    case 34:
      if (lookahead == ' ') ADVANCE(511);
      END_STATE();
    case 35:
      if (lookahead == ' ') ADVANCE(429);
      END_STATE();
    case 36:
      if (lookahead == ' ') ADVANCE(430);
      END_STATE();
    case 37:
      if (lookahead == ' ') ADVANCE(819);
      END_STATE();
    case 38:
      if (lookahead == ' ') ADVANCE(628);
      END_STATE();
    case 39:
      if (lookahead == ' ') ADVANCE(778);
      END_STATE();
    case 40:
      if (lookahead == ' ') ADVANCE(582);
      END_STATE();
    case 41:
      if (lookahead == ' ') ADVANCE(795);
      END_STATE();
    case 42:
      if (lookahead == ' ') ADVANCE(638);
      END_STATE();
    case 43:
      if (lookahead == ' ') ADVANCE(593);
      END_STATE();
    case 44:
      if (lookahead == ' ') ADVANCE(439);
      END_STATE();
    case 45:
      if (lookahead == ' ') ADVANCE(442);
      END_STATE();
    case 46:
      if (lookahead == ' ') ADVANCE(836);
      END_STATE();
    case 47:
      if (lookahead == ' ') ADVANCE(405);
      END_STATE();
    case 48:
      if (lookahead == ' ') ADVANCE(406);
      END_STATE();
    case 49:
      if (lookahead == ' ') ADVANCE(744);
      END_STATE();
    case 50:
      if (lookahead == ' ') ADVANCE(687);
      END_STATE();
    case 51:
      if (lookahead == ' ') ADVANCE(228);
      END_STATE();
    case 52:
      if (lookahead == ' ') ADVANCE(227);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(346);
      END_STATE();
    case 53:
      if (lookahead == ' ') ADVANCE(232);
      END_STATE();
    case 54:
      if (lookahead == '#') ADVANCE(99);
      if (lookahead == '+') ADVANCE(100);
      if (lookahead == '-') ADVANCE(101);
      if (lookahead == 'a') ADVANCE(118);
      if (lookahead == 'b') ADVANCE(102);
      if (lookahead == 'o') ADVANCE(125);
      END_STATE();
    case 55:
      if (lookahead == '(') ADVANCE(362);
      END_STATE();
    case 56:
      if (lookahead == '(') ADVANCE(584);
      END_STATE();
    case 57:
      if (lookahead == '(') ADVANCE(265);
      END_STATE();
    case 58:
      if (lookahead == ')') ADVANCE(932);
      END_STATE();
    case 59:
      if (lookahead == ')') ADVANCE(1064);
      END_STATE();
    case 60:
      if (lookahead == ')') ADVANCE(1063);
      END_STATE();
    case 61:
      if (lookahead == ')') ADVANCE(1062);
      END_STATE();
    case 62:
      if (lookahead == ')') ADVANCE(1061);
      END_STATE();
    case 63:
      if (lookahead == ')') ADVANCE(1025);
      END_STATE();
    case 64:
      if (lookahead == ')') ADVANCE(1026);
      END_STATE();
    case 65:
      if (lookahead == ')') ADVANCE(1024);
      END_STATE();
    case 66:
      if (lookahead == ')') ADVANCE(1023);
      END_STATE();
    case 67:
      if (lookahead == ')') ADVANCE(1022);
      END_STATE();
    case 68:
      if (lookahead == '*') ADVANCE(918);
      if (lookahead == '/') ADVANCE(71);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 69:
      if (lookahead == '*') ADVANCE(90);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 70:
      if (lookahead == '*') ADVANCE(93);
      END_STATE();
    case 71:
      if (lookahead == '*') ADVANCE(73);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 72:
      if (lookahead == '*') ADVANCE(91);
      if (lookahead != 0) ADVANCE(72);
      END_STATE();
    case 73:
      if (lookahead == '*') ADVANCE(77);
      if (lookahead == '/') ADVANCE(924);
      if (lookahead != 0) ADVANCE(74);
      END_STATE();
    case 74:
      if (lookahead == '*') ADVANCE(92);
      if (lookahead != 0) ADVANCE(74);
      END_STATE();
    case 75:
      if (lookahead == '*') ADVANCE(78);
      if (lookahead == '/') ADVANCE(924);
      if (lookahead != 0) ADVANCE(74);
      END_STATE();
    case 76:
      if (lookahead == '*') ADVANCE(94);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 77:
      if (lookahead == '*') ADVANCE(75);
      if (lookahead == '/') ADVANCE(69);
      if (lookahead != 0) ADVANCE(74);
      END_STATE();
    case 78:
      if (lookahead == '*') ADVANCE(75);
      if (lookahead == '/') ADVANCE(76);
      if (lookahead != 0) ADVANCE(74);
      END_STATE();
    case 79:
      if (lookahead == '-') ADVANCE(98);
      END_STATE();
    case 80:
      if (lookahead == '-') ADVANCE(363);
      END_STATE();
    case 81:
      if (lookahead == '-') ADVANCE(97);
      if (lookahead == '2') ADVANCE(966);
      if (lookahead == '4') ADVANCE(968);
      END_STATE();
    case 82:
      if (lookahead == '-') ADVANCE(839);
      END_STATE();
    case 83:
      if (lookahead == '.') ADVANCE(932);
      END_STATE();
    case 84:
      if (lookahead == '.') ADVANCE(932);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(24);
      END_STATE();
    case 85:
      if (lookahead == '.') ADVANCE(932);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(575);
      END_STATE();
    case 86:
      if (lookahead == '.') ADVANCE(906);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(557);
      END_STATE();
    case 87:
      if (lookahead == '.') ADVANCE(686);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(396);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(341);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(380);
      END_STATE();
    case 88:
      if (lookahead == '.') ADVANCE(398);
      END_STATE();
    case 89:
      if (lookahead == '.') ADVANCE(374);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(723);
      END_STATE();
    case 90:
      if (lookahead == '/') ADVANCE(922);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 91:
      if (lookahead == '/') ADVANCE(70);
      if (lookahead != 0) ADVANCE(72);
      END_STATE();
    case 92:
      if (lookahead == '/') ADVANCE(923);
      if (lookahead != 0) ADVANCE(74);
      END_STATE();
    case 93:
      if (lookahead == '/') ADVANCE(921);
      END_STATE();
    case 94:
      if (lookahead == '/') ADVANCE(921);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 95:
      if (lookahead == '2') ADVANCE(1048);
      if (lookahead == '4') ADVANCE(1047);
      END_STATE();
    case 96:
      if (lookahead == '2') ADVANCE(1045);
      if (lookahead == '4') ADVANCE(1046);
      END_STATE();
    case 97:
      if (lookahead == '2') ADVANCE(964);
      if (lookahead == '4') ADVANCE(968);
      END_STATE();
    case 98:
      if (lookahead == '4') ADVANCE(970);
      END_STATE();
    case 99:
      if (lookahead == '5') ADVANCE(59);
      END_STATE();
    case 100:
      if (lookahead == '5') ADVANCE(60);
      END_STATE();
    case 101:
      if (lookahead == '5') ADVANCE(61);
      END_STATE();
    case 102:
      if (lookahead == '5') ADVANCE(62);
      END_STATE();
    case 103:
      if (lookahead == '9') ADVANCE(63);
      END_STATE();
    case 104:
      if (lookahead == '9') ADVANCE(64);
      END_STATE();
    case 105:
      if (lookahead == '9') ADVANCE(65);
      END_STATE();
    case 106:
      if (lookahead == '9') ADVANCE(66);
      END_STATE();
    case 107:
      if (lookahead == '9') ADVANCE(67);
      END_STATE();
    case 108:
      if (lookahead == 'E') ADVANCE(700);
      if (lookahead == 'e') ADVANCE(115);
      END_STATE();
    case 109:
      if (lookahead == 'I') ADVANCE(757);
      if (lookahead == 'i') ADVANCE(126);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(703);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(151);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(488);
      END_STATE();
    case 110:
      if (lookahead == 'I') ADVANCE(1011);
      if (lookahead == 'V') ADVANCE(1008);
      if (lookahead == 'i') ADVANCE(732);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(383);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(607);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(879);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(527);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(148);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(112);
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(1003);
      END_STATE();
    case 111:
      if (lookahead == 'I') ADVANCE(1009);
      if (lookahead == 'V') ADVANCE(1008);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(112);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(111);
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(1003);
      END_STATE();
    case 112:
      if (lookahead == 'I') ADVANCE(1009);
      if (lookahead == 'V') ADVANCE(1008);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(112);
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(1003);
      END_STATE();
    case 113:
      if (lookahead == 'J') ADVANCE(1034);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(444);
      END_STATE();
    case 114:
      if (lookahead == 'N') ADVANCE(1043);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(621);
      END_STATE();
    case 115:
      if (lookahead == 'R') ADVANCE(294);
      if (lookahead == 'r') ADVANCE(1067);
      END_STATE();
    case 116:
      if (lookahead == 'V') ADVANCE(317);
      if (lookahead == 'm') ADVANCE(122);
      if (lookahead == 'n') ADVANCE(1066);
      if (lookahead == 'v') ADVANCE(108);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(614);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(193);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(312);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(237);
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(1060);
      END_STATE();
    case 117:
      if (lookahead == 'd') ADVANCE(917);
      END_STATE();
    case 118:
      if (lookahead == 'd') ADVANCE(117);
      END_STATE();
    case 119:
      if (lookahead == 'd') ADVANCE(117);
      if (lookahead == 'u') ADVANCE(121);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(243);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(651);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(605);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(809);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(676);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(531);
      END_STATE();
    case 120:
      if (lookahead == 'd') ADVANCE(117);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(243);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(651);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(605);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(809);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(676);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(531);
      END_STATE();
    case 121:
      if (lookahead == 'g') ADVANCE(1050);
      END_STATE();
    case 122:
      if (lookahead == 'i') ADVANCE(131);
      END_STATE();
    case 123:
      if (lookahead == 'j') ADVANCE(1033);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(444);
      END_STATE();
    case 124:
      if (lookahead == 'j') ADVANCE(1032);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(444);
      END_STATE();
    case 125:
      if (lookahead == 'm') ADVANCE(122);
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(1060);
      END_STATE();
    case 126:
      if (lookahead == 'm') ADVANCE(1049);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(798);
      END_STATE();
    case 127:
      if (lookahead == 'n') ADVANCE(1042);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(621);
      END_STATE();
    case 128:
      if (lookahead == 'n') ADVANCE(1041);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(621);
      END_STATE();
    case 129:
      if (lookahead == 's') ADVANCE(95);
      END_STATE();
    case 130:
      if (lookahead == 's') ADVANCE(96);
      END_STATE();
    case 131:
      if (lookahead == 't') ADVANCE(908);
      END_STATE();
    case 132:
      if (lookahead == 'u') ADVANCE(129);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(560);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(413);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(206);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(143);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(810);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(146);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(684);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(858);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(315);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(318);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(564);
      END_STATE();
    case 133:
      if (lookahead == 'u') ADVANCE(130);
      END_STATE();
    case 134:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(518);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(486);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(157);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(142);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(552);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(894);
      END_STATE();
    case 135:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(560);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(413);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(206);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(143);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(810);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(146);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(684);
      if (lookahead == 'Q' ||
          lookahead == 'q') ADVANCE(858);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(315);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(318);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(564);
      END_STATE();
    case 136:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(503);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(517);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(543);
      END_STATE();
    case 137:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(898);
      END_STATE();
    case 138:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(271);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(697);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(932);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(695);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(160);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(490);
      END_STATE();
    case 139:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(932);
      END_STATE();
    case 140:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(932);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(542);
      END_STATE();
    case 141:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(932);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(520);
      END_STATE();
    case 142:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(738);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(189);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(762);
      END_STATE();
    case 143:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(477);
      END_STATE();
    case 144:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(869);
      END_STATE();
    case 145:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(18);
      END_STATE();
    case 146:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(688);
      END_STATE();
    case 147:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(884);
      END_STATE();
    case 148:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(759);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(208);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(368);
      END_STATE();
    case 149:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(419);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(260);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(609);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(236);
      END_STATE();
    case 150:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(270);
      END_STATE();
    case 151:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(878);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(669);
      END_STATE();
    case 152:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(415);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(495);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(529);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(343);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(212);
      END_STATE();
    case 153:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(696);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(451);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(612);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(739);
      END_STATE();
    case 154:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(494);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(886);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(813);
      END_STATE();
    case 155:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(592);
      END_STATE();
    case 156:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(385);
      END_STATE();
    case 157:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(737);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(361);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(423);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(704);
      END_STATE();
    case 158:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(369);
      END_STATE();
    case 159:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(861);
      END_STATE();
    case 160:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(574);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(261);
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(902);
      END_STATE();
    case 161:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(888);
      END_STATE();
    case 162:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(542);
      END_STATE();
    case 163:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(273);
      END_STATE();
    case 164:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(544);
      END_STATE();
    case 165:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(689);
      END_STATE();
    case 166:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(275);
      END_STATE();
    case 167:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(698);
      END_STATE();
    case 168:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(272);
      END_STATE();
    case 169:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(412);
      END_STATE();
    case 170:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(244);
      END_STATE();
    case 171:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(562);
      END_STATE();
    case 172:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(485);
      END_STATE();
    case 173:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(545);
      END_STATE();
    case 174:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(702);
      END_STATE();
    case 175:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(725);
      END_STATE();
    case 176:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(711);
      END_STATE();
    case 177:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(691);
      END_STATE();
    case 178:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(156);
      END_STATE();
    case 179:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(156);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(611);
      END_STATE();
    case 180:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(568);
      END_STATE();
    case 181:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(701);
      END_STATE();
    case 182:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(730);
      END_STATE();
    case 183:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(731);
      END_STATE();
    case 184:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(523);
      END_STATE();
    case 185:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(899);
      END_STATE();
    case 186:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(706);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(501);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(885);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(777);
      END_STATE();
    case 187:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(767);
      END_STATE();
    case 188:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(241);
      END_STATE();
    case 189:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(563);
      END_STATE();
    case 190:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(581);
      END_STATE();
    case 191:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(257);
      END_STATE();
    case 192:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(734);
      END_STATE();
    case 193:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(741);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(144);
      END_STATE();
    case 194:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(573);
      END_STATE();
    case 195:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(571);
      END_STATE();
    case 196:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(565);
      END_STATE();
    case 197:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(818);
      END_STATE();
    case 198:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(780);
      END_STATE();
    case 199:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(780);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(198);
      END_STATE();
    case 200:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(572);
      END_STATE();
    case 201:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(761);
      END_STATE();
    case 202:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(783);
      END_STATE();
    case 203:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(786);
      END_STATE();
    case 204:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(583);
      END_STATE();
    case 205:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(594);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(772);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(509);
      END_STATE();
    case 206:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(781);
      END_STATE();
    case 207:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(685);
      END_STATE();
    case 208:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(828);
      END_STATE();
    case 209:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(875);
      END_STATE();
    case 210:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(749);
      END_STATE();
    case 211:
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(229);
      END_STATE();
    case 212:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(141);
      END_STATE();
    case 213:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(199);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(713);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(845);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(662);
      END_STATE();
    case 214:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(614);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(193);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(312);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(237);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(317);
      END_STATE();
    case 215:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(717);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(487);
      END_STATE();
    case 216:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(519);
      END_STATE();
    case 217:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(172);
      END_STATE();
    case 218:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(515);
      END_STATE();
    case 219:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(139);
      END_STATE();
    case 220:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(346);
      END_STATE();
    case 221:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(606);
      END_STATE();
    case 222:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(187);
      END_STATE();
    case 223:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(512);
      END_STATE();
    case 224:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(629);
      END_STATE();
    case 225:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(176);
      END_STATE();
    case 226:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(630);
      END_STATE();
    case 227:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(349);
      END_STATE();
    case 228:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(198);
      END_STATE();
    case 229:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(201);
      END_STATE();
    case 230:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(201);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(693);
      END_STATE();
    case 231:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(202);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(694);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(469);
      END_STATE();
    case 232:
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(203);
      END_STATE();
    case 233:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(50);
      END_STATE();
    case 234:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(932);
      END_STATE();
    case 235:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(703);
      END_STATE();
    case 236:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(479);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(847);
      END_STATE();
    case 237:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(386);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(164);
      END_STATE();
    case 238:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(483);
      END_STATE();
    case 239:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(301);
      END_STATE();
    case 240:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(860);
      END_STATE();
    case 241:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(475);
      END_STATE();
    case 242:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(482);
      END_STATE();
    case 243:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(618);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(863);
      END_STATE();
    case 244:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(388);
      END_STATE();
    case 245:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(897);
      END_STATE();
    case 246:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(753);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(932);
      END_STATE();
    case 247:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(417);
      END_STATE();
    case 248:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(831);
      END_STATE();
    case 249:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(309);
      END_STATE();
    case 250:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(139);
      END_STATE();
    case 251:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(763);
      END_STATE();
    case 252:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(617);
      END_STATE();
    case 253:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(197);
      END_STATE();
    case 254:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(37);
      END_STATE();
    case 255:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(6);
      END_STATE();
    case 256:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(7);
      END_STATE();
    case 257:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(666);
      END_STATE();
    case 258:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(850);
      END_STATE();
    case 259:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(824);
      END_STATE();
    case 260:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(622);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(280);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(328);
      END_STATE();
    case 261:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(653);
      END_STATE();
    case 262:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(33);
      END_STATE();
    case 263:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(395);
      END_STATE();
    case 264:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(408);
      END_STATE();
    case 265:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(513);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(465);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(210);
      if (lookahead == 'J' ||
          lookahead == 'j') ADVANCE(185);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(859);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(876);
      END_STATE();
    case 266:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(392);
      END_STATE();
    case 267:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(407);
      END_STATE();
    case 268:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(846);
      END_STATE();
    case 269:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(50);
      END_STATE();
    case 270:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(915);
      END_STATE();
    case 271:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(915);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 272:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(932);
      END_STATE();
    case 273:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(949);
      END_STATE();
    case 274:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(98);
      END_STATE();
    case 275:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(965);
      END_STATE();
    case 276:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(284);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(806);
      END_STATE();
    case 277:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(79);
      END_STATE();
    case 278:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(21);
      END_STATE();
    case 279:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(460);
      END_STATE();
    case 280:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(38);
      END_STATE();
    case 281:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(28);
      END_STATE();
    case 282:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(58);
      END_STATE();
    case 283:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(322);
      END_STATE();
    case 284:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(491);
      END_STATE();
    case 285:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(2);
      END_STATE();
    case 286:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(464);
      END_STATE();
    case 287:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(34);
      END_STATE();
    case 288:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(710);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(802);
      END_STATE();
    case 289:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(218);
      END_STATE();
    case 290:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(649);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(671);
      END_STATE();
    case 291:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(624);
      if (lookahead == 'J' ||
          lookahead == 'j') ADVANCE(600);
      END_STATE();
    case 292:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(656);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(672);
      END_STATE();
    case 293:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(324);
      END_STATE();
    case 294:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(721);
      END_STATE();
    case 295:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(425);
      END_STATE();
    case 296:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(35);
      END_STATE();
    case 297:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(829);
      END_STATE();
    case 298:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(747);
      END_STATE();
    case 299:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(36);
      END_STATE();
    case 300:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(45);
      END_STATE();
    case 301:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(932);
      END_STATE();
    case 302:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(906);
      END_STATE();
    case 303:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(961);
      END_STATE();
    case 304:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(5);
      END_STATE();
    case 305:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(375);
      END_STATE();
    case 306:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(948);
      END_STATE();
    case 307:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(944);
      END_STATE();
    case 308:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(877);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(11);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(514);
      END_STATE();
    case 309:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(928);
      END_STATE();
    case 310:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(598);
      END_STATE();
    case 311:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(150);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(235);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(279);
      END_STATE();
    case 312:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(588);
      END_STATE();
    case 313:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 314:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(668);
      END_STATE();
    case 315:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(326);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 316:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(675);
      END_STATE();
    case 317:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(700);
      END_STATE();
    case 318:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(314);
      END_STATE();
    case 319:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(534);
      END_STATE();
    case 320:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(542);
      END_STATE();
    case 321:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 322:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(753);
      END_STATE();
    case 323:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 324:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(689);
      END_STATE();
    case 325:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(698);
      END_STATE();
    case 326:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(505);
      END_STATE();
    case 327:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(282);
      END_STATE();
    case 328:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(733);
      END_STATE();
    case 329:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(332);
      END_STATE();
    case 330:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(720);
      END_STATE();
    case 331:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(485);
      END_STATE();
    case 332:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(797);
      END_STATE();
    case 333:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(498);
      END_STATE();
    case 334:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(586);
      END_STATE();
    case 335:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 336:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 337:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(168);
      END_STATE();
    case 338:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(752);
      END_STATE();
    case 339:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(724);
      END_STATE();
    case 340:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(714);
      END_STATE();
    case 341:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(248);
      END_STATE();
    case 342:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(816);
      END_STATE();
    case 343:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(536);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(528);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(532);
      END_STATE();
    case 344:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(835);
      END_STATE();
    case 345:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(268);
      END_STATE();
    case 346:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(507);
      END_STATE();
    case 347:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(333);
      END_STATE();
    case 348:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(281);
      END_STATE();
    case 349:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(508);
      END_STATE();
    case 350:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 351:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(616);
      END_STATE();
    case 352:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(794);
      END_STATE();
    case 353:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(761);
      END_STATE();
    case 354:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(285);
      END_STATE();
    case 355:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(771);
      END_STATE();
    case 356:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(180);
      END_STATE();
    case 357:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 358:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(785);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(600);
      END_STATE();
    case 359:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(748);
      END_STATE();
    case 360:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(932);
      END_STATE();
    case 361:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(360);
      END_STATE();
    case 362:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(443);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(454);
      END_STATE();
    case 363:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(412);
      END_STATE();
    case 364:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(484);
      END_STATE();
    case 365:
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(726);
      END_STATE();
    case 366:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(932);
      END_STATE();
    case 367:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(909);
      END_STATE();
    case 368:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(389);
      END_STATE();
    case 369:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(301);
      END_STATE();
    case 370:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(460);
      END_STATE();
    case 371:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(753);
      END_STATE();
    case 372:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(600);
      END_STATE();
    case 373:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(755);
      END_STATE();
    case 374:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(800);
      END_STATE();
    case 375:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(797);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(375);
      END_STATE();
    case 376:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(525);
      END_STATE();
    case 377:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(802);
      END_STATE();
    case 378:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(802);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(705);
      END_STATE();
    case 379:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(774);
      END_STATE();
    case 380:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(500);
      END_STATE();
    case 381:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(340);
      END_STATE();
    case 382:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(162);
      END_STATE();
    case 383:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(30);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(291);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(421);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(754);
      END_STATE();
    case 384:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(932);
      END_STATE();
    case 385:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(753);
      END_STATE();
    case 386:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(352);
      END_STATE();
    case 387:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(19);
      END_STATE();
    case 388:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(412);
      END_STATE();
    case 389:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(799);
      END_STATE();
    case 390:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(4);
      END_STATE();
    case 391:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(40);
      END_STATE();
    case 392:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(48);
      END_STATE();
    case 393:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(626);
      END_STATE();
    case 394:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(170);
      END_STATE();
    case 395:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(645);
      END_STATE();
    case 396:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(619);
      END_STATE();
    case 397:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(436);
      END_STATE();
    case 398:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(174);
      END_STATE();
    case 399:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(620);
      END_STATE();
    case 400:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(325);
      END_STATE();
    case 401:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(630);
      END_STATE();
    case 402:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(636);
      END_STATE();
    case 403:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(660);
      END_STATE();
    case 404:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(192);
      END_STATE();
    case 405:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(181);
      END_STATE();
    case 406:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(642);
      END_STATE();
    case 407:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(644);
      END_STATE();
    case 408:
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(42);
      END_STATE();
    case 409:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(757);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(703);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(151);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(488);
      END_STATE();
    case 410:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(276);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(853);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(50);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(310);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(915);
      END_STATE();
    case 411:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(215);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(416);
      END_STATE();
    case 412:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(932);
      END_STATE();
    case 413:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(80);
      END_STATE();
    case 414:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(246);
      END_STATE();
    case 415:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(480);
      END_STATE();
    case 416:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(249);
      END_STATE();
    case 417:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(537);
      END_STATE();
    case 418:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(262);
      END_STATE();
    case 419:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(542);
      END_STATE();
    case 420:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(252);
      END_STATE();
    case 421:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(830);
      END_STATE();
    case 422:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(253);
      END_STATE();
    case 423:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(690);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(84);
      END_STATE();
    case 424:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(787);
      END_STATE();
    case 425:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(254);
      END_STATE();
    case 426:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(784);
      END_STATE();
    case 427:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(550);
      END_STATE();
    case 428:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(234);
      END_STATE();
    case 429:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(551);
      END_STATE();
    case 430:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(553);
      END_STATE();
    case 431:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(805);
      END_STATE();
    case 432:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(233);
      END_STATE();
    case 433:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(562);
      END_STATE();
    case 434:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(655);
      END_STATE();
    case 435:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(251);
      END_STATE();
    case 436:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(797);
      END_STATE();
    case 437:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(567);
      END_STATE();
    case 438:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(577);
      END_STATE();
    case 439:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(555);
      END_STATE();
    case 440:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(166);
      END_STATE();
    case 441:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(163);
      END_STATE();
    case 442:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(599);
      END_STATE();
    case 443:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(570);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(344);
      END_STATE();
    case 444:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(533);
      END_STATE();
    case 445:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(239);
      END_STATE();
    case 446:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(331);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(932);
      END_STATE();
    case 447:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(250);
      END_STATE();
    case 448:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(255);
      END_STATE();
    case 449:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(587);
      END_STATE();
    case 450:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(575);
      END_STATE();
    case 451:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(765);
      END_STATE();
    case 452:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(870);
      END_STATE();
    case 453:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(674);
      END_STATE();
    case 454:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(242);
      END_STATE();
    case 455:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(758);
      END_STATE();
    case 456:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(256);
      END_STATE();
    case 457:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(590);
      END_STATE();
    case 458:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(871);
      END_STATE();
    case 459:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(616);
      END_STATE();
    case 460:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(173);
      END_STATE();
    case 461:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(595);
      END_STATE();
    case 462:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(872);
      END_STATE();
    case 463:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(190);
      END_STATE();
    case 464:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(632);
      END_STATE();
    case 465:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(788);
      END_STATE();
    case 466:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(200);
      END_STATE();
    case 467:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(637);
      END_STATE();
    case 468:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(641);
      END_STATE();
    case 469:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(204);
      END_STATE();
    case 470:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(643);
      END_STATE();
    case 471:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(834);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(776);
      END_STATE();
    case 472:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(267);
      END_STATE();
    case 473:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(840);
      END_STATE();
    case 474:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(841);
      END_STATE();
    case 475:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(932);
      END_STATE();
    case 476:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(930);
      END_STATE();
    case 477:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(857);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(426);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(169);
      END_STATE();
    case 478:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(891);
      END_STATE();
    case 479:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(38);
      END_STATE();
    case 480:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(600);
      END_STATE();
    case 481:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(506);
      END_STATE();
    case 482:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(327);
      END_STATE();
    case 483:
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(334);
      END_STATE();
    case 484:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(853);
      END_STATE();
    case 485:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(932);
      END_STATE();
    case 486:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(358);
      END_STATE();
    case 487:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(140);
      END_STATE();
    case 488:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(247);
      END_STATE();
    case 489:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(608);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(216);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(155);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(88);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(471);
      END_STATE();
    case 490:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(887);
      END_STATE();
    case 491:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(301);
      END_STATE();
    case 492:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(890);
      END_STATE();
    case 493:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(460);
      END_STATE();
    case 494:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(444);
      END_STATE();
    case 495:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(316);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(679);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(623);
      END_STATE();
    case 496:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(434);
      END_STATE();
    case 497:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(753);
      END_STATE();
    case 498:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(58);
      END_STATE();
    case 499:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(159);
      END_STATE();
    case 500:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(424);
      END_STATE();
    case 501:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(647);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(184);
      END_STATE();
    case 502:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(600);
      END_STATE();
    case 503:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(600);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(539);
      END_STATE();
    case 504:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(663);
      END_STATE();
    case 505:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(3);
      END_STATE();
    case 506:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(350);
      END_STATE();
    case 507:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(485);
      END_STATE();
    case 508:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(497);
      END_STATE();
    case 509:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(161);
      END_STATE();
    case 510:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(664);
      END_STATE();
    case 511:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(337);
      END_STATE();
    case 512:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(302);
      END_STATE();
    case 513:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(356);
      END_STATE();
    case 514:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(652);
      END_STATE();
    case 515:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(650);
      END_STATE();
    case 516:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(431);
      END_STATE();
    case 517:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(420);
      END_STATE();
    case 518:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(496);
      END_STATE();
    case 519:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(437);
      END_STATE();
    case 520:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(177);
      END_STATE();
    case 521:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(428);
      END_STATE();
    case 522:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(643);
      END_STATE();
    case 523:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(521);
      END_STATE();
    case 524:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(355);
      END_STATE();
    case 525:
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(201);
      END_STATE();
    case 526:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(932);
      END_STATE();
    case 527:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(912);
      END_STATE();
    case 528:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(226);
      END_STATE();
    case 529:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(683);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(481);
      END_STATE();
    case 530:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(753);
      END_STATE();
    case 531:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(613);
      END_STATE();
    case 532:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(678);
      END_STATE();
    case 533:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(219);
      END_STATE();
    case 534:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(223);
      END_STATE();
    case 535:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(217);
      END_STATE();
    case 536:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(657);
      END_STATE();
    case 537:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(324);
      END_STATE();
    case 538:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(639);
      END_STATE();
    case 539:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(648);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(789);
      END_STATE();
    case 540:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(659);
      END_STATE();
    case 541:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(665);
      END_STATE();
    case 542:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(932);
      END_STATE();
    case 543:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(478);
      END_STATE();
    case 544:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(910);
      END_STATE();
    case 545:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(942);
      END_STATE();
    case 546:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(933);
      END_STATE();
    case 547:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(982);
      END_STATE();
    case 548:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(986);
      END_STATE();
    case 549:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(946);
      END_STATE();
    case 550:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(865);
      END_STATE();
    case 551:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(866);
      END_STATE();
    case 552:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(826);
      END_STATE();
    case 553:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(867);
      END_STATE();
    case 554:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(374);
      END_STATE();
    case 555:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(868);
      END_STATE();
    case 556:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(301);
      END_STATE();
    case 557:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(373);
      END_STATE();
    case 558:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(460);
      END_STATE();
    case 559:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(476);
      END_STATE();
    case 560:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(804);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(814);
      END_STATE();
    case 561:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(297);
      END_STATE();
    case 562:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(366);
      END_STATE();
    case 563:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(32);
      END_STATE();
    case 564:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(825);
      END_STATE();
    case 565:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(615);
      END_STATE();
    case 566:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(274);
      END_STATE();
    case 567:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(753);
      END_STATE();
    case 568:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 569:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(889);
      END_STATE();
    case 570:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(381);
      END_STATE();
    case 571:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(277);
      END_STATE();
    case 572:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(600);
      END_STATE();
    case 573:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(412);
      END_STATE();
    case 574:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(603);
      END_STATE();
    case 575:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(332);
      END_STATE();
    case 576:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(351);
      END_STATE();
    case 577:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(139);
      END_STATE();
    case 578:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(313);
      END_STATE();
    case 579:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(414);
      END_STATE();
    case 580:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(808);
      END_STATE();
    case 581:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(602);
      END_STATE();
    case 582:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(625);
      END_STATE();
    case 583:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(635);
      END_STATE();
    case 584:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(896);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(827);
      END_STATE();
    case 585:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(15);
      END_STATE();
    case 586:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(764);
      END_STATE();
    case 587:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(379);
      END_STATE();
    case 588:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(46);
      END_STATE();
    case 589:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(336);
      END_STATE();
    case 590:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(371);
      END_STATE();
    case 591:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(773);
      END_STATE();
    case 592:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(269);
      END_STATE();
    case 593:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(633);
      END_STATE();
    case 594:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(287);
      END_STATE();
    case 595:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(640);
      END_STATE();
    case 596:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(447);
      END_STATE();
    case 597:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(435);
      END_STATE();
    case 598:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(266);
      END_STATE();
    case 599:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(874);
      END_STATE();
    case 600:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(932);
      END_STATE();
    case 601:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(912);
      END_STATE();
    case 602:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(906);
      END_STATE();
    case 603:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(910);
      END_STATE();
    case 604:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(558);
      END_STATE();
    case 605:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(372);
      END_STATE();
    case 606:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(884);
      END_STATE();
    case 607:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(880);
      END_STATE();
    case 608:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(238);
      END_STATE();
    case 609:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(283);
      END_STATE();
    case 610:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(526);
      END_STATE();
    case 611:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(385);
      END_STATE();
    case 612:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(289);
      END_STATE();
    case 613:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(760);
      END_STATE();
    case 614:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(301);
      END_STATE();
    case 615:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 616:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(542);
      END_STATE();
    case 617:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(680);
      END_STATE();
    case 618:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(736);
      END_STATE();
    case 619:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(322);
      END_STATE();
    case 620:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(698);
      END_STATE();
    case 621:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(492);
      END_STATE();
    case 622:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(707);
      END_STATE();
    case 623:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(699);
      END_STATE();
    case 624:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(576);
      END_STATE();
    case 625:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(455);
      END_STATE();
    case 626:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(797);
      END_STATE();
    case 627:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(808);
      END_STATE();
    case 628:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(709);
      END_STATE();
    case 629:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(811);
      END_STATE();
    case 630:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(556);
      END_STATE();
    case 631:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(801);
      END_STATE();
    case 632:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(546);
      END_STATE();
    case 633:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(820);
      END_STATE();
    case 634:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(559);
      END_STATE();
    case 635:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(8);
      END_STATE();
    case 636:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(715);
      END_STATE();
    case 637:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(554);
      END_STATE();
    case 638:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(712);
      END_STATE();
    case 639:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(569);
      END_STATE();
    case 640:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(692);
      END_STATE();
    case 641:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(549);
      END_STATE();
    case 642:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(708);
      END_STATE();
    case 643:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(568);
      END_STATE();
    case 644:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(718);
      END_STATE();
    case 645:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(750);
      END_STATE();
    case 646:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(873);
      END_STATE();
    case 647:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(295);
      END_STATE();
    case 648:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(596);
      END_STATE();
    case 649:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(881);
      END_STATE();
    case 650:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(241);
      END_STATE();
    case 651:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(493);
      END_STATE();
    case 652:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(563);
      END_STATE();
    case 653:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(502);
      END_STATE();
    case 654:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(627);
      END_STATE();
    case 655:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(674);
      END_STATE();
    case 656:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(882);
      END_STATE();
    case 657:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(510);
      END_STATE();
    case 658:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(578);
      END_STATE();
    case 659:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(579);
      END_STATE();
    case 660:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(589);
      END_STATE();
    case 661:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(631);
      END_STATE();
    case 662:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(445);
      END_STATE();
    case 663:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(685);
      END_STATE();
    case 664:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(41);
      END_STATE();
    case 665:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(597);
      END_STATE();
    case 666:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(864);
      END_STATE();
    case 667:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(751);
      END_STATE();
    case 668:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(932);
      END_STATE();
    case 669:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(81);
      END_STATE();
    case 670:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(446);
      END_STATE();
    case 671:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(976);
      END_STATE();
    case 672:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(980);
      END_STATE();
    case 673:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(682);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(951);
      END_STATE();
    case 674:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(301);
      END_STATE();
    case 675:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(403);
      END_STATE();
    case 676:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(499);
      END_STATE();
    case 677:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(453);
      END_STATE();
    case 678:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(332);
      END_STATE();
    case 679:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(601);
      END_STATE();
    case 680:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(832);
      END_STATE();
    case 681:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(400);
      END_STATE();
    case 682:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(330);
      END_STATE();
    case 683:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(194);
      END_STATE();
    case 684:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(740);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(561);
      END_STATE();
    case 685:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(401);
      END_STATE();
    case 686:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(463);
      END_STATE();
    case 687:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(466);
      END_STATE();
    case 688:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(51);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(387);
      END_STATE();
    case 689:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(932);
      END_STATE();
    case 690:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(929);
      END_STATE();
    case 691:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 692:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(939);
      END_STATE();
    case 693:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(155);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(473);
      END_STATE();
    case 694:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(155);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(474);
      END_STATE();
    case 695:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(892);
      END_STATE();
    case 696:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(526);
      END_STATE();
    case 697:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(240);
      END_STATE();
    case 698:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(301);
      END_STATE();
    case 699:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 700:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(294);
      END_STATE();
    case 701:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(668);
      END_STATE();
    case 702:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(540);
      END_STATE();
    case 703:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(460);
      END_STATE();
    case 704:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(264);
      END_STATE();
    case 705:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(851);
      END_STATE();
    case 706:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(444);
      END_STATE();
    case 707:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(293);
      END_STATE();
    case 708:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(542);
      END_STATE();
    case 709:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(382);
      END_STATE();
    case 710:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(854);
      END_STATE();
    case 711:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 712:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(367);
      END_STATE();
    case 713:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(852);
      END_STATE();
    case 714:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(58);
      END_STATE();
    case 715:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(273);
      END_STATE();
    case 716:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(862);
      END_STATE();
    case 717:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(207);
      END_STATE();
    case 718:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(272);
      END_STATE();
    case 719:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(211);
      END_STATE();
    case 720:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 721:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(452);
      END_STATE();
    case 722:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(440);
      END_STATE();
    case 723:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(844);
      END_STATE();
    case 724:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(796);
      END_STATE();
    case 725:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 726:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(342);
      END_STATE();
    case 727:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(188);
      END_STATE();
    case 728:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(145);
      END_STATE();
    case 729:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(306);
      END_STATE();
    case 730:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(10);
      END_STATE();
    case 731:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 732:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(278);
      END_STATE();
    case 733:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(770);
      END_STATE();
    case 734:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(538);
      END_STATE();
    case 735:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(441);
      END_STATE();
    case 736:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(286);
      END_STATE();
    case 737:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(171);
      END_STATE();
    case 738:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(450);
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(85);
      END_STATE();
    case 739:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(516);
      END_STATE();
    case 740:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(196);
      END_STATE();
    case 741:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(438);
      END_STATE();
    case 742:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(456);
      END_STATE();
    case 743:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(449);
      END_STATE();
    case 744:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(433);
      END_STATE();
    case 745:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(457);
      END_STATE();
    case 746:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(661);
      END_STATE();
    case 747:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(462);
      END_STATE();
    case 748:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(298);
      END_STATE();
    case 749:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(541);
      END_STATE();
    case 750:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(300);
      END_STATE();
    case 751:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(849);
      END_STATE();
    case 752:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 753:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(932);
      END_STATE();
    case 754:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(1);
      END_STATE();
    case 755:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(905);
      END_STATE();
    case 756:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(972);
      END_STATE();
    case 757:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(798);
      END_STATE();
    case 758:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(301);
      END_STATE();
    case 759:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(779);
      END_STATE();
    case 760:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(681);
      END_STATE();
    case 761:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(753);
      END_STATE();
    case 762:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(303);
      END_STATE();
    case 763:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(58);
      END_STATE();
    case 764:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(670);
      END_STATE();
    case 765:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(812);
      END_STATE();
    case 766:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(838);
      END_STATE();
    case 767:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(756);
      END_STATE();
    case 768:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(147);
      END_STATE();
    case 769:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(792);
      END_STATE();
    case 770:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(335);
      END_STATE();
    case 771:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(763);
      END_STATE();
    case 772:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(26);
      END_STATE();
    case 773:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(319);
      END_STATE();
    case 774:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(8);
      END_STATE();
    case 775:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(9);
      END_STATE();
    case 776:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(393);
      END_STATE();
    case 777:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(418);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(354);
      END_STATE();
    case 778:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(822);
      END_STATE();
    case 779:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(22);
      END_STATE();
    case 780:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(774);
      END_STATE();
    case 781:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(399);
      END_STATE();
    case 782:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(815);
      END_STATE();
    case 783:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(775);
      END_STATE();
    case 784:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(320);
      END_STATE();
    case 785:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(817);
      END_STATE();
    case 786:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(793);
      END_STATE();
    case 787:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(392);
      END_STATE();
    case 788:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(843);
      END_STATE();
    case 789:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(472);
      END_STATE();
    case 790:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(345);
      END_STATE();
    case 791:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(842);
      END_STATE();
    case 792:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(458);
      END_STATE();
    case 793:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(43);
      END_STATE();
    case 794:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(833);
      END_STATE();
    case 795:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(848);
      END_STATE();
    case 796:
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(468);
      END_STATE();
    case 797:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(932);
      END_STATE();
    case 798:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(89);
      END_STATE();
    case 799:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(25);
      END_STATE();
    case 800:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(931);
      END_STATE();
    case 801:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(974);
      END_STATE();
    case 802:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(83);
      END_STATE();
    case 803:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(31);
      END_STATE();
    case 804:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(855);
      END_STATE();
    case 805:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(903);
      END_STATE();
    case 806:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(385);
      END_STATE();
    case 807:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(301);
      END_STATE();
    case 808:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(384);
      END_STATE();
    case 809:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(615);
      END_STATE();
    case 810:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(165);
      END_STATE();
    case 811:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(812);
      END_STATE();
    case 812:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(491);
      END_STATE();
    case 813:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(600);
      END_STATE();
    case 814:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(654);
      END_STATE();
    case 815:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(172);
      END_STATE();
    case 816:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(40);
      END_STATE();
    case 817:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(139);
      END_STATE();
    case 818:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(664);
      END_STATE();
    case 819:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(610);
      END_STATE();
    case 820:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(307);
      END_STATE();
    case 821:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(327);
      END_STATE();
    case 822:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(716);
      END_STATE();
    case 823:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(883);
      END_STATE();
    case 824:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(856);
      END_STATE();
    case 825:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(390);
      END_STATE();
    case 826:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(719);
      END_STATE();
    case 827:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(347);
      END_STATE();
    case 828:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(391);
      END_STATE();
    case 829:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(727);
      END_STATE();
    case 830:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(658);
      END_STATE();
    case 831:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(742);
      END_STATE();
    case 832:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(324);
      END_STATE();
    case 833:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(728);
      END_STATE();
    case 834:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(175);
      END_STATE();
    case 835:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(524);
      END_STATE();
    case 836:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(722);
      END_STATE();
    case 837:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(735);
      END_STATE();
    case 838:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(448);
      END_STATE();
    case 839:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(634);
      END_STATE();
    case 840:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(182);
      END_STATE();
    case 841:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(183);
      END_STATE();
    case 842:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(432);
      END_STATE();
    case 843:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(667);
      END_STATE();
    case 844:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(467);
      END_STATE();
    case 845:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(743);
      END_STATE();
    case 846:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(459);
      END_STATE();
    case 847:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(44);
      END_STATE();
    case 848:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(745);
      END_STATE();
    case 849:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(470);
      END_STATE();
    case 850:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(209);
      END_STATE();
    case 851:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(532);
      END_STATE();
    case 852:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(526);
      END_STATE();
    case 853:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(807);
      END_STATE();
    case 854:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(530);
      END_STATE();
    case 855:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(689);
      END_STATE();
    case 856:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(729);
      END_STATE();
    case 857:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(394);
      END_STATE();
    case 858:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(167);
      END_STATE();
    case 859:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(821);
      END_STATE();
    case 860:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(769);
      END_STATE();
    case 861:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(758);
      END_STATE();
    case 862:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(259);
      END_STATE();
    case 863:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(766);
      END_STATE();
    case 864:
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(791);
      END_STATE();
    case 865:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(955);
      END_STATE();
    case 866:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(957);
      END_STATE();
    case 867:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(959);
      END_STATE();
    case 868:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(953);
      END_STATE();
    case 869:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(304);
      END_STATE();
    case 870:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(305);
      END_STATE();
    case 871:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(321);
      END_STATE();
    case 872:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(323);
      END_STATE();
    case 873:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(338);
      END_STATE();
    case 874:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(339);
      END_STATE();
    case 875:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(357);
      END_STATE();
    case 876:
      if (lookahead == 'V' ||
          lookahead == 'v') ADVANCE(359);
      END_STATE();
    case 877:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(20);
      END_STATE();
    case 878:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(225);
      END_STATE();
    case 879:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(348);
      END_STATE();
    case 880:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(585);
      END_STATE();
    case 881:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(547);
      END_STATE();
    case 882:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(548);
      END_STATE();
    case 883:
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(329);
      END_STATE();
    case 884:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(932);
      END_STATE();
    case 885:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(621);
      END_STATE();
    case 886:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(907);
      END_STATE();
    case 887:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(950);
      END_STATE();
    case 888:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(27);
      END_STATE();
    case 889:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(962);
      END_STATE();
    case 890:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(279);
      END_STATE();
    case 891:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(82);
      END_STATE();
    case 892:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(370);
      END_STATE();
    case 893:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(504);
      END_STATE();
    case 894:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(782);
      END_STATE();
    case 895:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(580);
      END_STATE();
    case 896:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(522);
      END_STATE();
    case 897:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(535);
      END_STATE();
    case 898:
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(900);
      END_STATE();
    case 899:
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(901);
      END_STATE();
    case 900:
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(32);
      END_STATE();
    case 901:
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(58);
      END_STATE();
    case 902:
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(422);
      END_STATE();
    case 903:
      if (lookahead == 'Z' ||
          lookahead == 'z') ADVANCE(324);
      END_STATE();
    case 904:
      if (lookahead == '1' ||
          lookahead == '2') ADVANCE(932);
      END_STATE();
    case 905:
      if (lookahead == '1' ||
          lookahead == '2') ADVANCE(932);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(591);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(905);
      END_STATE();
    case 906:
      if (lookahead == '1' ||
          lookahead == '2') ADVANCE(932);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(906);
      END_STATE();
    case 907:
      if (lookahead == ' ' ||
          lookahead == ':' ||
          lookahead == '=') ADVANCE(914);
      if (('A' <= lookahead && lookahead <= 'G')) ADVANCE(938);
      END_STATE();
    case 908:
      if (lookahead == '1' ||
          lookahead == '3' ||
          lookahead == '5') ADVANCE(1060);
      END_STATE();
    case 909:
      if (('1' <= lookahead && lookahead <= '3')) ADVANCE(932);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(542);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(910);
      END_STATE();
    case 910:
      if (('1' <= lookahead && lookahead <= '3')) ADVANCE(932);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(910);
      END_STATE();
    case 911:
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'f' ||
          lookahead == 'l') ADVANCE(932);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(911);
      END_STATE();
    case 912:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(912);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(926);
      END_STATE();
    case 913:
      if (('0' <= lookahead && lookahead <= '3')) ADVANCE(991);
      END_STATE();
    case 914:
      if (('A' <= lookahead && lookahead <= 'G')) ADVANCE(938);
      END_STATE();
    case 915:
      if (('1' <= lookahead && lookahead <= '8')) ADVANCE(932);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(915);
      END_STATE();
    case 916:
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(1016);
      END_STATE();
    case 917:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(1058);
      END_STATE();
    case 918:
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(69);
      END_STATE();
    case 919:
      if (eof) ADVANCE(920);
      if (lookahead == '\'') ADVANCE(992);
      if (lookahead == '(') ADVANCE(54);
      if (lookahead == ',') ADVANCE(993);
      if (lookahead == '-') ADVANCE(987);
      if (lookahead == '/') ADVANCE(1065);
      if (lookahead == '1') ADVANCE(1015);
      if (lookahead == '2') ADVANCE(1013);
      if (lookahead == '3') ADVANCE(1014);
      if (lookahead == 'A') ADVANCE(997);
      if (lookahead == 'B') ADVANCE(995);
      if (lookahead == 'C') ADVANCE(996);
      if (lookahead == 'D') ADVANCE(998);
      if (lookahead == 'E') ADVANCE(994);
      if (lookahead == 'F') ADVANCE(999);
      if (lookahead == 'G') ADVANCE(1000);
      if (lookahead == 'I') ADVANCE(1010);
      if (lookahead == 'O') ADVANCE(214);
      if (lookahead == 'V') ADVANCE(1012);
      if (lookahead == '^') ADVANCE(913);
      if (lookahead == 'a') ADVANCE(120);
      if (lookahead == 'b') ADVANCE(110);
      if (lookahead == 'c') ADVANCE(134);
      if (lookahead == 'd') ADVANCE(409);
      if (lookahead == 'e') ADVANCE(87);
      if (lookahead == 'f') ADVANCE(410);
      if (lookahead == 'g') ADVANCE(489);
      if (lookahead == 'i') ADVANCE(604);
      if (lookahead == 'o') ADVANCE(116);
      if (lookahead == 'v') ADVANCE(411);
      if (lookahead == '|') ADVANCE(934);
      if (lookahead == 8594) ADVANCE(989);
      if (lookahead == 9837) ADVANCE(112);
      if (lookahead == 12539) ADVANCE(990);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(136);
      if (lookahead == 'J' ||
          lookahead == 'j') ADVANCE(137);
      if (lookahead == 'K' ||
          lookahead == 'k') ADVANCE(154);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(311);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(186);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(308);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(149);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(135);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(152);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(673);
      if (lookahead == 'W' ||
          lookahead == 'w') ADVANCE(153);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(893);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(111);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(919)
      if (('4' <= lookahead && lookahead <= '7')) ADVANCE(1003);
      END_STATE();
    case 920:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 921:
      ACCEPT_TOKEN(sym_inline_abc);
      END_STATE();
    case 922:
      ACCEPT_TOKEN(sym_inline_mml);
      END_STATE();
    case 923:
      ACCEPT_TOKEN(sym_inline_mml);
      if (lookahead == '*') ADVANCE(93);
      END_STATE();
    case 924:
      ACCEPT_TOKEN(sym_inline_mml);
      if (lookahead == '*') ADVANCE(91);
      if (lookahead != 0) ADVANCE(72);
      END_STATE();
    case 925:
      ACCEPT_TOKEN(sym_tempo);
      END_STATE();
    case 926:
      ACCEPT_TOKEN(sym_tempo);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(925);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(926);
      END_STATE();
    case 927:
      ACCEPT_TOKEN(sym_midi_pc);
      END_STATE();
    case 928:
      ACCEPT_TOKEN(sym_midi_pc);
      if (lookahead == ' ') ADVANCE(179);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(927);
      END_STATE();
    case 929:
      ACCEPT_TOKEN(sym_midi_pc);
      if (lookahead == ' ') ADVANCE(178);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(927);
      END_STATE();
    case 930:
      ACCEPT_TOKEN(sym_midi_pc);
      if (lookahead == ' ') ADVANCE(687);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(927);
      END_STATE();
    case 931:
      ACCEPT_TOKEN(sym_midi_pc);
      if (lookahead == ',') ADVANCE(927);
      if (lookahead == '.') ADVANCE(932);
      END_STATE();
    case 932:
      ACCEPT_TOKEN(sym_midi_pc);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(927);
      END_STATE();
    case 933:
      ACCEPT_TOKEN(sym_midi_pc);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(927);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'f' ||
          lookahead == 'l') ADVANCE(932);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(911);
      END_STATE();
    case 934:
      ACCEPT_TOKEN(sym_bar);
      END_STATE();
    case 935:
      ACCEPT_TOKEN(sym_bar_slash);
      END_STATE();
    case 936:
      ACCEPT_TOKEN(sym_key);
      END_STATE();
    case 937:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == 'M') ADVANCE(461);
      if (lookahead == 'm') ADVANCE(940);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(936);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(937);
      END_STATE();
    case 938:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == 'M') ADVANCE(461);
      if (lookahead == 'm') ADVANCE(940);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(936);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(937);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(938);
      END_STATE();
    case 939:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(936);
      END_STATE();
    case 940:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(936);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(595);
      END_STATE();
    case 941:
      ACCEPT_TOKEN(sym_scale);
      END_STATE();
    case 942:
      ACCEPT_TOKEN(sym_scale);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(941);
      END_STATE();
    case 943:
      ACCEPT_TOKEN(sym_mode_chord_over_bass_note);
      END_STATE();
    case 944:
      ACCEPT_TOKEN(sym_mode_chord_over_bass_note);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(943);
      END_STATE();
    case 945:
      ACCEPT_TOKEN(sym_mode_slash_chord_inversion);
      END_STATE();
    case 946:
      ACCEPT_TOKEN(sym_mode_slash_chord_inversion);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(945);
      END_STATE();
    case 947:
      ACCEPT_TOKEN(sym_mode_polychord);
      END_STATE();
    case 948:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ' ') ADVANCE(837);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(947);
      END_STATE();
    case 949:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(947);
      END_STATE();
    case 950:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(947);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(402);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(895);
      END_STATE();
    case 951:
      ACCEPT_TOKEN(sym_mode_polychord);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(947);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(949);
      END_STATE();
    case 952:
      ACCEPT_TOKEN(sym_mode_root_inv);
      END_STATE();
    case 953:
      ACCEPT_TOKEN(sym_mode_root_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(952);
      END_STATE();
    case 954:
      ACCEPT_TOKEN(sym_mode_1st_inv);
      END_STATE();
    case 955:
      ACCEPT_TOKEN(sym_mode_1st_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(954);
      END_STATE();
    case 956:
      ACCEPT_TOKEN(sym_mode_2nd_inv);
      END_STATE();
    case 957:
      ACCEPT_TOKEN(sym_mode_2nd_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(956);
      END_STATE();
    case 958:
      ACCEPT_TOKEN(sym_mode_3rd_inv);
      END_STATE();
    case 959:
      ACCEPT_TOKEN(sym_mode_3rd_inv);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(958);
      END_STATE();
    case 960:
      ACCEPT_TOKEN(sym_mode_close);
      END_STATE();
    case 961:
      ACCEPT_TOKEN(sym_mode_close);
      if (lookahead == ' ') ADVANCE(404);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(960);
      END_STATE();
    case 962:
      ACCEPT_TOKEN(sym_mode_close);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(960);
      END_STATE();
    case 963:
      ACCEPT_TOKEN(sym_mode_drop2);
      END_STATE();
    case 964:
      ACCEPT_TOKEN(sym_mode_drop2);
      if (lookahead == '-') ADVANCE(195);
      if ((',' <= lookahead && lookahead <= '.')) ADVANCE(963);
      END_STATE();
    case 965:
      ACCEPT_TOKEN(sym_mode_drop2);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(963);
      END_STATE();
    case 966:
      ACCEPT_TOKEN(sym_mode_drop2);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(963);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(566);
      END_STATE();
    case 967:
      ACCEPT_TOKEN(sym_mode_drop4);
      END_STATE();
    case 968:
      ACCEPT_TOKEN(sym_mode_drop4);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(967);
      END_STATE();
    case 969:
      ACCEPT_TOKEN(sym_mode_drop2and4);
      END_STATE();
    case 970:
      ACCEPT_TOKEN(sym_mode_drop2and4);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(969);
      END_STATE();
    case 971:
      ACCEPT_TOKEN(sym_mode_no_bass);
      END_STATE();
    case 972:
      ACCEPT_TOKEN(sym_mode_no_bass);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(971);
      END_STATE();
    case 973:
      ACCEPT_TOKEN(sym_mode_bass_is_root);
      END_STATE();
    case 974:
      ACCEPT_TOKEN(sym_mode_bass_is_root);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(973);
      END_STATE();
    case 975:
      ACCEPT_TOKEN(sym_octave_up);
      END_STATE();
    case 976:
      ACCEPT_TOKEN(sym_octave_up);
      if (lookahead == '/') ADVANCE(978);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(975);
      END_STATE();
    case 977:
      ACCEPT_TOKEN(sym_octave_up_upper);
      END_STATE();
    case 978:
      ACCEPT_TOKEN(sym_octave_up_upper);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(977);
      END_STATE();
    case 979:
      ACCEPT_TOKEN(sym_octave_up_lower);
      END_STATE();
    case 980:
      ACCEPT_TOKEN(sym_octave_up_lower);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(979);
      END_STATE();
    case 981:
      ACCEPT_TOKEN(sym_octave_down);
      END_STATE();
    case 982:
      ACCEPT_TOKEN(sym_octave_down);
      if (lookahead == '/') ADVANCE(984);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(981);
      END_STATE();
    case 983:
      ACCEPT_TOKEN(sym_octave_down_upper);
      END_STATE();
    case 984:
      ACCEPT_TOKEN(sym_octave_down_upper);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(983);
      END_STATE();
    case 985:
      ACCEPT_TOKEN(sym_octave_down_lower);
      END_STATE();
    case 986:
      ACCEPT_TOKEN(sym_octave_down_lower);
      if (lookahead == ',' ||
          lookahead == '.') ADVANCE(985);
      END_STATE();
    case 987:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 988:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '7') ADVANCE(1040);
      END_STATE();
    case 989:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 990:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 991:
      ACCEPT_TOKEN(sym_chord_inversion);
      END_STATE();
    case 992:
      ACCEPT_TOKEN(sym_octave_offset);
      if (lookahead == '\'') ADVANCE(992);
      if (lookahead == ',') ADVANCE(993);
      END_STATE();
    case 993:
      ACCEPT_TOKEN(sym_octave_offset);
      if (lookahead == ',') ADVANCE(993);
      END_STATE();
    case 994:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == '.') ADVANCE(686);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(396);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(341);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(380);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(1001);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(1002);
      END_STATE();
    case 995:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(383);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(732);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(607);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(879);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(527);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(148);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(1001);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(1002);
      END_STATE();
    case 996:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'A' ||
          lookahead == 'a') ADVANCE(518);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(486);
      if (lookahead == 'H' ||
          lookahead == 'h') ADVANCE(157);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(142);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(552);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(894);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(1001);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(1002);
      END_STATE();
    case 997:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(243);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(651);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(605);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(809);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(676);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(531);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(1001);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(1002);
      END_STATE();
    case 998:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(757);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(703);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(151);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(488);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(1001);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(1002);
      END_STATE();
    case 999:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(276);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(853);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(50);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(310);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(915);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(1001);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(1002);
      END_STATE();
    case 1000:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'L' ||
          lookahead == 'l') ADVANCE(608);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(216);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(155);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(88);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(471);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(1001);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(1002);
      END_STATE();
    case 1001:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(1001);
      END_STATE();
    case 1002:
      ACCEPT_TOKEN(sym_note);
      if (lookahead == 'b' ||
          lookahead == 9837) ADVANCE(1001);
      if (lookahead == '#' ||
          lookahead == 9839 ||
          lookahead == 65283) ADVANCE(1002);
      END_STATE();
    case 1003:
      ACCEPT_TOKEN(sym_degree);
      END_STATE();
    case 1004:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == '.') ADVANCE(916);
      END_STATE();
    case 1005:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == '1') ADVANCE(1053);
      if (lookahead == '3') ADVANCE(1052);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(803);
      END_STATE();
    case 1006:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(1003);
      END_STATE();
    case 1007:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(1003);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(717);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(487);
      END_STATE();
    case 1008:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(1006);
      END_STATE();
    case 1009:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(1006);
      if (lookahead == 'V') ADVANCE(1003);
      END_STATE();
    case 1010:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(1006);
      if (lookahead == 'V') ADVANCE(1003);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(558);
      END_STATE();
    case 1011:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(1006);
      if (lookahead == 'V') ADVANCE(1003);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(278);
      END_STATE();
    case 1012:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'I') ADVANCE(1007);
      if (lookahead == 'i') ADVANCE(215);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(416);
      END_STATE();
    case 1013:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(296);
      END_STATE();
    case 1014:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(299);
      END_STATE();
    case 1015:
      ACCEPT_TOKEN(sym_degree);
      if (lookahead == 'S' ||
          lookahead == 's') ADVANCE(803);
      END_STATE();
    case 1016:
      ACCEPT_TOKEN(aux_sym_quality_base_token1);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(1016);
      END_STATE();
    case 1017:
      ACCEPT_TOKEN(anon_sym_maj9);
      END_STATE();
    case 1018:
      ACCEPT_TOKEN(anon_sym_Maj9);
      END_STATE();
    case 1019:
      ACCEPT_TOKEN(anon_sym_MAJ9);
      END_STATE();
    case 1020:
      ACCEPT_TOKEN(anon_sym_M9);
      END_STATE();
    case 1021:
      ACCEPT_TOKEN(anon_sym_9);
      END_STATE();
    case 1022:
      ACCEPT_TOKEN(anon_sym_maj_LPAREN9_RPAREN);
      END_STATE();
    case 1023:
      ACCEPT_TOKEN(anon_sym_Maj_LPAREN9_RPAREN);
      END_STATE();
    case 1024:
      ACCEPT_TOKEN(anon_sym_MAJ_LPAREN9_RPAREN);
      END_STATE();
    case 1025:
      ACCEPT_TOKEN(anon_sym_M_LPAREN9_RPAREN);
      END_STATE();
    case 1026:
      ACCEPT_TOKEN(anon_sym_LPAREN9_RPAREN);
      END_STATE();
    case 1027:
      ACCEPT_TOKEN(anon_sym_maj7);
      END_STATE();
    case 1028:
      ACCEPT_TOKEN(anon_sym_Maj7);
      END_STATE();
    case 1029:
      ACCEPT_TOKEN(anon_sym_MAJ7);
      END_STATE();
    case 1030:
      ACCEPT_TOKEN(anon_sym_M7);
      END_STATE();
    case 1031:
      ACCEPT_TOKEN(anon_sym_3);
      if (lookahead == '(') ADVANCE(104);
      if (lookahead == '9') ADVANCE(1021);
      END_STATE();
    case 1032:
      ACCEPT_TOKEN(anon_sym_maj);
      if (lookahead == '(') ADVANCE(107);
      if (lookahead == '7') ADVANCE(1027);
      if (lookahead == '9') ADVANCE(1017);
      END_STATE();
    case 1033:
      ACCEPT_TOKEN(anon_sym_Maj);
      if (lookahead == '(') ADVANCE(106);
      if (lookahead == '7') ADVANCE(1028);
      if (lookahead == '9') ADVANCE(1018);
      END_STATE();
    case 1034:
      ACCEPT_TOKEN(anon_sym_MAJ);
      if (lookahead == '(') ADVANCE(105);
      if (lookahead == '7') ADVANCE(1029);
      if (lookahead == '9') ADVANCE(1019);
      END_STATE();
    case 1035:
      ACCEPT_TOKEN(anon_sym_M);
      if (lookahead == '(') ADVANCE(103);
      if (lookahead == '7') ADVANCE(1030);
      if (lookahead == '9') ADVANCE(1020);
      if (lookahead == 'A') ADVANCE(113);
      if (lookahead == 'I') ADVANCE(114);
      if (lookahead == 'a') ADVANCE(123);
      if (lookahead == 'i') ADVANCE(127);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(501);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(777);
      END_STATE();
    case 1036:
      ACCEPT_TOKEN(anon_sym_min7);
      END_STATE();
    case 1037:
      ACCEPT_TOKEN(anon_sym_Min7);
      END_STATE();
    case 1038:
      ACCEPT_TOKEN(anon_sym_MIN7);
      END_STATE();
    case 1039:
      ACCEPT_TOKEN(anon_sym_m7);
      END_STATE();
    case 1040:
      ACCEPT_TOKEN(anon_sym_DASH7);
      END_STATE();
    case 1041:
      ACCEPT_TOKEN(anon_sym_min);
      if (lookahead == '7') ADVANCE(1036);
      END_STATE();
    case 1042:
      ACCEPT_TOKEN(anon_sym_Min);
      if (lookahead == '7') ADVANCE(1037);
      END_STATE();
    case 1043:
      ACCEPT_TOKEN(anon_sym_MIN);
      if (lookahead == '7') ADVANCE(1038);
      END_STATE();
    case 1044:
      ACCEPT_TOKEN(anon_sym_m);
      if (lookahead == '7') ADVANCE(1039);
      if (lookahead == 'A') ADVANCE(706);
      if (lookahead == 'I') ADVANCE(885);
      if (lookahead == 'a') ADVANCE(124);
      if (lookahead == 'i') ADVANCE(128);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(501);
      if (lookahead == 'U' ||
          lookahead == 'u') ADVANCE(777);
      END_STATE();
    case 1045:
      ACCEPT_TOKEN(anon_sym_7sus2);
      END_STATE();
    case 1046:
      ACCEPT_TOKEN(anon_sym_7sus4);
      END_STATE();
    case 1047:
      ACCEPT_TOKEN(anon_sym_sus4);
      END_STATE();
    case 1048:
      ACCEPT_TOKEN(anon_sym_sus2);
      END_STATE();
    case 1049:
      ACCEPT_TOKEN(anon_sym_dim);
      END_STATE();
    case 1050:
      ACCEPT_TOKEN(anon_sym_aug);
      END_STATE();
    case 1051:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 1052:
      ACCEPT_TOKEN(anon_sym_13);
      END_STATE();
    case 1053:
      ACCEPT_TOKEN(anon_sym_11);
      END_STATE();
    case 1054:
      ACCEPT_TOKEN(anon_sym_92);
      END_STATE();
    case 1055:
      ACCEPT_TOKEN(anon_sym_7);
      if (lookahead == 's') ADVANCE(133);
      END_STATE();
    case 1056:
      ACCEPT_TOKEN(anon_sym_6);
      END_STATE();
    case 1057:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      END_STATE();
    case 1058:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token1);
      if (lookahead == ')') ADVANCE(1057);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(1058);
      END_STATE();
    case 1059:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      END_STATE();
    case 1060:
      ACCEPT_TOKEN(aux_sym_quality_modifier_token2);
      if (lookahead == ')') ADVANCE(1059);
      END_STATE();
    case 1061:
      ACCEPT_TOKEN(anon_sym_LPARENb5_RPAREN);
      END_STATE();
    case 1062:
      ACCEPT_TOKEN(anon_sym_LPAREN_DASH5_RPAREN);
      END_STATE();
    case 1063:
      ACCEPT_TOKEN(anon_sym_LPAREN_PLUS5_RPAREN);
      END_STATE();
    case 1064:
      ACCEPT_TOKEN(anon_sym_LPAREN_POUND5_RPAREN);
      END_STATE();
    case 1065:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(68);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(935);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(258);
      END_STATE();
    case 1066:
      ACCEPT_TOKEN(anon_sym_on);
      END_STATE();
    case 1067:
      ACCEPT_TOKEN(anon_sym_over);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(721);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 919},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 919},
  [7] = {.lex_state = 919},
  [8] = {.lex_state = 919},
  [9] = {.lex_state = 919},
  [10] = {.lex_state = 919},
  [11] = {.lex_state = 919},
  [12] = {.lex_state = 919},
  [13] = {.lex_state = 919},
  [14] = {.lex_state = 919},
  [15] = {.lex_state = 919},
  [16] = {.lex_state = 919},
  [17] = {.lex_state = 919},
  [18] = {.lex_state = 919},
  [19] = {.lex_state = 919},
  [20] = {.lex_state = 919},
  [21] = {.lex_state = 919},
  [22] = {.lex_state = 919},
  [23] = {.lex_state = 919},
  [24] = {.lex_state = 919},
  [25] = {.lex_state = 919},
  [26] = {.lex_state = 919},
  [27] = {.lex_state = 919},
  [28] = {.lex_state = 919},
  [29] = {.lex_state = 919},
  [30] = {.lex_state = 919},
  [31] = {.lex_state = 919},
  [32] = {.lex_state = 919},
  [33] = {.lex_state = 919},
  [34] = {.lex_state = 919},
  [35] = {.lex_state = 919},
  [36] = {.lex_state = 919},
  [37] = {.lex_state = 919},
  [38] = {.lex_state = 919},
  [39] = {.lex_state = 919},
  [40] = {.lex_state = 919},
  [41] = {.lex_state = 919},
  [42] = {.lex_state = 919},
  [43] = {.lex_state = 919},
  [44] = {.lex_state = 919},
  [45] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_inline_abc] = ACTIONS(1),
    [sym_inline_mml] = ACTIONS(1),
    [sym_tempo] = ACTIONS(1),
    [sym_midi_pc] = ACTIONS(1),
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
    [sym_inline_abc] = ACTIONS(5),
    [sym_inline_mml] = ACTIONS(7),
    [sym_tempo] = ACTIONS(5),
    [sym_midi_pc] = ACTIONS(5),
    [sym_bar] = ACTIONS(5),
    [sym_bar_slash] = ACTIONS(5),
    [sym_key] = ACTIONS(5),
    [sym_scale] = ACTIONS(5),
    [sym_mode_chord_over_bass_note] = ACTIONS(5),
    [sym_mode_slash_chord_inversion] = ACTIONS(5),
    [sym_mode_polychord] = ACTIONS(7),
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
    [sym_inline_abc] = ACTIONS(13),
    [sym_inline_mml] = ACTIONS(15),
    [sym_tempo] = ACTIONS(13),
    [sym_midi_pc] = ACTIONS(13),
    [sym_bar] = ACTIONS(13),
    [sym_bar_slash] = ACTIONS(13),
    [sym_key] = ACTIONS(13),
    [sym_scale] = ACTIONS(13),
    [sym_mode_chord_over_bass_note] = ACTIONS(13),
    [sym_mode_slash_chord_inversion] = ACTIONS(13),
    [sym_mode_polychord] = ACTIONS(15),
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
    [anon_sym_over] = ACTIONS(34),
  },
  [3] = {
    [sym_quality] = STATE(25),
    [sym_quality_base] = STATE(6),
    [sym_quality_modifier] = STATE(10),
    [aux_sym_quality_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(36),
    [sym_inline_abc] = ACTIONS(36),
    [sym_inline_mml] = ACTIONS(38),
    [sym_tempo] = ACTIONS(36),
    [sym_midi_pc] = ACTIONS(36),
    [sym_bar] = ACTIONS(36),
    [sym_bar_slash] = ACTIONS(36),
    [sym_key] = ACTIONS(36),
    [sym_scale] = ACTIONS(36),
    [sym_mode_chord_over_bass_note] = ACTIONS(36),
    [sym_mode_slash_chord_inversion] = ACTIONS(36),
    [sym_mode_polychord] = ACTIONS(38),
    [sym_mode_root_inv] = ACTIONS(36),
    [sym_mode_1st_inv] = ACTIONS(36),
    [sym_mode_2nd_inv] = ACTIONS(36),
    [sym_mode_3rd_inv] = ACTIONS(36),
    [sym_mode_close] = ACTIONS(36),
    [sym_mode_drop2] = ACTIONS(38),
    [sym_mode_drop4] = ACTIONS(36),
    [sym_mode_drop2and4] = ACTIONS(36),
    [sym_mode_no_bass] = ACTIONS(36),
    [sym_mode_bass_is_root] = ACTIONS(36),
    [sym_octave_up] = ACTIONS(38),
    [sym_octave_up_upper] = ACTIONS(36),
    [sym_octave_up_lower] = ACTIONS(36),
    [sym_octave_down] = ACTIONS(38),
    [sym_octave_down_upper] = ACTIONS(36),
    [sym_octave_down_lower] = ACTIONS(36),
    [anon_sym_DASH] = ACTIONS(40),
    [anon_sym_] = ACTIONS(36),
    [anon_sym_2] = ACTIONS(36),
    [sym_chord_inversion] = ACTIONS(43),
    [sym_octave_offset] = ACTIONS(45),
    [sym_note] = ACTIONS(38),
    [sym_degree] = ACTIONS(38),
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
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym_inline_abc] = ACTIONS(47),
    [sym_inline_mml] = ACTIONS(49),
    [sym_tempo] = ACTIONS(47),
    [sym_midi_pc] = ACTIONS(47),
    [sym_bar] = ACTIONS(47),
    [sym_bar_slash] = ACTIONS(47),
    [sym_key] = ACTIONS(47),
    [sym_scale] = ACTIONS(47),
    [sym_mode_chord_over_bass_note] = ACTIONS(47),
    [sym_mode_slash_chord_inversion] = ACTIONS(47),
    [sym_mode_polychord] = ACTIONS(49),
    [sym_mode_root_inv] = ACTIONS(47),
    [sym_mode_1st_inv] = ACTIONS(47),
    [sym_mode_2nd_inv] = ACTIONS(47),
    [sym_mode_3rd_inv] = ACTIONS(47),
    [sym_mode_close] = ACTIONS(47),
    [sym_mode_drop2] = ACTIONS(49),
    [sym_mode_drop4] = ACTIONS(47),
    [sym_mode_drop2and4] = ACTIONS(47),
    [sym_mode_no_bass] = ACTIONS(47),
    [sym_mode_bass_is_root] = ACTIONS(47),
    [sym_octave_up] = ACTIONS(49),
    [sym_octave_up_upper] = ACTIONS(47),
    [sym_octave_up_lower] = ACTIONS(47),
    [sym_octave_down] = ACTIONS(49),
    [sym_octave_down_upper] = ACTIONS(47),
    [sym_octave_down_lower] = ACTIONS(47),
    [anon_sym_DASH] = ACTIONS(49),
    [anon_sym_] = ACTIONS(47),
    [anon_sym_2] = ACTIONS(47),
    [sym_chord_inversion] = ACTIONS(47),
    [sym_octave_offset] = ACTIONS(47),
    [sym_note] = ACTIONS(49),
    [sym_degree] = ACTIONS(49),
    [aux_sym_quality_base_token1] = ACTIONS(47),
    [anon_sym_maj9] = ACTIONS(47),
    [anon_sym_Maj9] = ACTIONS(47),
    [anon_sym_MAJ9] = ACTIONS(47),
    [anon_sym_M9] = ACTIONS(47),
    [anon_sym_9] = ACTIONS(47),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(47),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(47),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(47),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(47),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(47),
    [anon_sym_maj7] = ACTIONS(47),
    [anon_sym_Maj7] = ACTIONS(47),
    [anon_sym_MAJ7] = ACTIONS(47),
    [anon_sym_M7] = ACTIONS(47),
    [anon_sym_3] = ACTIONS(49),
    [anon_sym_maj] = ACTIONS(49),
    [anon_sym_Maj] = ACTIONS(49),
    [anon_sym_MAJ] = ACTIONS(49),
    [anon_sym_M] = ACTIONS(49),
    [anon_sym_min7] = ACTIONS(47),
    [anon_sym_Min7] = ACTIONS(47),
    [anon_sym_MIN7] = ACTIONS(47),
    [anon_sym_m7] = ACTIONS(47),
    [anon_sym_DASH7] = ACTIONS(47),
    [anon_sym_min] = ACTIONS(49),
    [anon_sym_Min] = ACTIONS(49),
    [anon_sym_MIN] = ACTIONS(49),
    [anon_sym_m] = ACTIONS(49),
    [anon_sym_7sus2] = ACTIONS(47),
    [anon_sym_7sus4] = ACTIONS(47),
    [anon_sym_sus4] = ACTIONS(47),
    [anon_sym_sus2] = ACTIONS(47),
    [anon_sym_dim] = ACTIONS(47),
    [anon_sym_aug] = ACTIONS(47),
    [anon_sym_PLUS] = ACTIONS(47),
    [anon_sym_13] = ACTIONS(47),
    [anon_sym_11] = ACTIONS(47),
    [anon_sym_92] = ACTIONS(47),
    [anon_sym_7] = ACTIONS(49),
    [anon_sym_6] = ACTIONS(47),
    [aux_sym_quality_modifier_token1] = ACTIONS(47),
    [aux_sym_quality_modifier_token2] = ACTIONS(47),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(47),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(47),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(47),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(47),
    [anon_sym_SLASH] = ACTIONS(49),
    [anon_sym_on] = ACTIONS(47),
    [anon_sym_over] = ACTIONS(49),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(51),
    [sym_inline_abc] = ACTIONS(51),
    [sym_inline_mml] = ACTIONS(53),
    [sym_tempo] = ACTIONS(51),
    [sym_midi_pc] = ACTIONS(51),
    [sym_bar] = ACTIONS(51),
    [sym_bar_slash] = ACTIONS(51),
    [sym_key] = ACTIONS(51),
    [sym_scale] = ACTIONS(51),
    [sym_mode_chord_over_bass_note] = ACTIONS(51),
    [sym_mode_slash_chord_inversion] = ACTIONS(51),
    [sym_mode_polychord] = ACTIONS(53),
    [sym_mode_root_inv] = ACTIONS(51),
    [sym_mode_1st_inv] = ACTIONS(51),
    [sym_mode_2nd_inv] = ACTIONS(51),
    [sym_mode_3rd_inv] = ACTIONS(51),
    [sym_mode_close] = ACTIONS(51),
    [sym_mode_drop2] = ACTIONS(53),
    [sym_mode_drop4] = ACTIONS(51),
    [sym_mode_drop2and4] = ACTIONS(51),
    [sym_mode_no_bass] = ACTIONS(51),
    [sym_mode_bass_is_root] = ACTIONS(51),
    [sym_octave_up] = ACTIONS(53),
    [sym_octave_up_upper] = ACTIONS(51),
    [sym_octave_up_lower] = ACTIONS(51),
    [sym_octave_down] = ACTIONS(53),
    [sym_octave_down_upper] = ACTIONS(51),
    [sym_octave_down_lower] = ACTIONS(51),
    [anon_sym_DASH] = ACTIONS(53),
    [anon_sym_] = ACTIONS(51),
    [anon_sym_2] = ACTIONS(51),
    [sym_chord_inversion] = ACTIONS(51),
    [sym_octave_offset] = ACTIONS(51),
    [sym_note] = ACTIONS(53),
    [sym_degree] = ACTIONS(53),
    [aux_sym_quality_base_token1] = ACTIONS(51),
    [anon_sym_maj9] = ACTIONS(51),
    [anon_sym_Maj9] = ACTIONS(51),
    [anon_sym_MAJ9] = ACTIONS(51),
    [anon_sym_M9] = ACTIONS(51),
    [anon_sym_9] = ACTIONS(51),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(51),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(51),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(51),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(51),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(51),
    [anon_sym_maj7] = ACTIONS(51),
    [anon_sym_Maj7] = ACTIONS(51),
    [anon_sym_MAJ7] = ACTIONS(51),
    [anon_sym_M7] = ACTIONS(51),
    [anon_sym_3] = ACTIONS(53),
    [anon_sym_maj] = ACTIONS(53),
    [anon_sym_Maj] = ACTIONS(53),
    [anon_sym_MAJ] = ACTIONS(53),
    [anon_sym_M] = ACTIONS(53),
    [anon_sym_min7] = ACTIONS(51),
    [anon_sym_Min7] = ACTIONS(51),
    [anon_sym_MIN7] = ACTIONS(51),
    [anon_sym_m7] = ACTIONS(51),
    [anon_sym_DASH7] = ACTIONS(51),
    [anon_sym_min] = ACTIONS(53),
    [anon_sym_Min] = ACTIONS(53),
    [anon_sym_MIN] = ACTIONS(53),
    [anon_sym_m] = ACTIONS(53),
    [anon_sym_7sus2] = ACTIONS(51),
    [anon_sym_7sus4] = ACTIONS(51),
    [anon_sym_sus4] = ACTIONS(51),
    [anon_sym_sus2] = ACTIONS(51),
    [anon_sym_dim] = ACTIONS(51),
    [anon_sym_aug] = ACTIONS(51),
    [anon_sym_PLUS] = ACTIONS(51),
    [anon_sym_13] = ACTIONS(51),
    [anon_sym_11] = ACTIONS(51),
    [anon_sym_92] = ACTIONS(51),
    [anon_sym_7] = ACTIONS(53),
    [anon_sym_6] = ACTIONS(51),
    [aux_sym_quality_modifier_token1] = ACTIONS(51),
    [aux_sym_quality_modifier_token2] = ACTIONS(51),
    [anon_sym_LPARENb5_RPAREN] = ACTIONS(51),
    [anon_sym_LPAREN_DASH5_RPAREN] = ACTIONS(51),
    [anon_sym_LPAREN_PLUS5_RPAREN] = ACTIONS(51),
    [anon_sym_LPAREN_POUND5_RPAREN] = ACTIONS(51),
    [anon_sym_SLASH] = ACTIONS(53),
    [anon_sym_on] = ACTIONS(51),
    [anon_sym_over] = ACTIONS(53),
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
    ACTIONS(57), 9,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
      anon_sym_over,
    ACTIONS(55), 29,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [57] = 5,
    STATE(7), 1,
      aux_sym_quality_repeat1,
    STATE(10), 1,
      sym_quality_modifier,
    ACTIONS(63), 6,
      aux_sym_quality_modifier_token1,
      aux_sym_quality_modifier_token2,
      anon_sym_LPARENb5_RPAREN,
      anon_sym_LPAREN_DASH5_RPAREN,
      anon_sym_LPAREN_PLUS5_RPAREN,
      anon_sym_LPAREN_POUND5_RPAREN,
    ACTIONS(61), 9,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
      anon_sym_over,
    ACTIONS(59), 29,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [114] = 5,
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
    ACTIONS(68), 9,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
      anon_sym_over,
    ACTIONS(66), 29,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [171] = 5,
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
    ACTIONS(72), 9,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
      anon_sym_over,
    ACTIONS(70), 29,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [228] = 2,
    ACTIONS(76), 9,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
      anon_sym_over,
    ACTIONS(74), 35,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [277] = 2,
    ACTIONS(80), 9,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
      anon_sym_over,
    ACTIONS(78), 35,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [326] = 2,
    ACTIONS(84), 9,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
      anon_sym_SLASH,
      anon_sym_over,
    ACTIONS(82), 35,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [375] = 8,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 1,
      anon_sym_on,
    ACTIONS(34), 1,
      anon_sym_over,
    ACTIONS(90), 1,
      sym_chord_inversion,
    ACTIONS(92), 1,
      sym_octave_offset,
    STATE(35), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(88), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(86), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [432] = 7,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 1,
      anon_sym_on,
    ACTIONS(34), 1,
      anon_sym_over,
    ACTIONS(98), 1,
      sym_octave_offset,
    STATE(34), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(96), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(94), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [486] = 7,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 1,
      anon_sym_on,
    ACTIONS(34), 1,
      anon_sym_over,
    ACTIONS(104), 1,
      sym_octave_offset,
    STATE(37), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(102), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(100), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [540] = 9,
    ACTIONS(106), 1,
      ts_builtin_sym_end,
    ACTIONS(117), 1,
      sym_note,
    ACTIONS(120), 1,
      sym_degree,
    STATE(2), 1,
      sym_root,
    STATE(43), 1,
      sym_separator,
    ACTIONS(114), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(16), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(111), 5,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(108), 22,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [597] = 9,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    ACTIONS(123), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_root,
    STATE(43), 1,
      sym_separator,
    ACTIONS(129), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(16), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(127), 5,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(125), 22,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [654] = 6,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 1,
      anon_sym_on,
    ACTIONS(34), 1,
      anon_sym_over,
    STATE(33), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(133), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(131), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [705] = 9,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    ACTIONS(135), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym_root,
    STATE(43), 1,
      sym_separator,
    ACTIONS(129), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(17), 3,
      sym__event,
      sym_chord,
      aux_sym_source_file_repeat1,
    ACTIONS(139), 5,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(137), 22,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [762] = 6,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 1,
      anon_sym_on,
    ACTIONS(34), 1,
      anon_sym_over,
    STATE(41), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(143), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(141), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [813] = 6,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 1,
      anon_sym_on,
    ACTIONS(34), 1,
      anon_sym_over,
    STATE(38), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(147), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(145), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [864] = 6,
    ACTIONS(30), 1,
      anon_sym_SLASH,
    ACTIONS(32), 1,
      anon_sym_on,
    ACTIONS(34), 1,
      anon_sym_over,
    STATE(32), 2,
      sym_bass,
      sym_on_bass,
    ACTIONS(151), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(149), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [915] = 6,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    STATE(3), 1,
      sym_root,
    STATE(29), 1,
      sym__lower,
    ACTIONS(155), 5,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(153), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [963] = 6,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    STATE(3), 1,
      sym_root,
    STATE(30), 1,
      sym__lower,
    ACTIONS(159), 5,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(157), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1011] = 4,
    ACTIONS(165), 1,
      sym_chord_inversion,
    ACTIONS(167), 1,
      sym_octave_offset,
    ACTIONS(163), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(161), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1055] = 3,
    ACTIONS(173), 1,
      sym_octave_offset,
    ACTIONS(171), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(169), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1096] = 3,
    ACTIONS(179), 1,
      sym_octave_offset,
    ACTIONS(177), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(175), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
    ACTIONS(183), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(181), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1175] = 2,
    ACTIONS(187), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(185), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1213] = 2,
    ACTIONS(191), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(189), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1251] = 2,
    ACTIONS(195), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(193), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1289] = 2,
    ACTIONS(199), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(197), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1327] = 2,
    ACTIONS(203), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(201), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1365] = 2,
    ACTIONS(207), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(205), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1403] = 2,
    ACTIONS(211), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(209), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1441] = 2,
    ACTIONS(213), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(106), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1479] = 2,
    ACTIONS(217), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(215), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1517] = 2,
    ACTIONS(221), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(219), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1555] = 2,
    ACTIONS(225), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(223), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1593] = 2,
    ACTIONS(229), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(227), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1631] = 2,
    ACTIONS(233), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(231), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1669] = 2,
    ACTIONS(237), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(235), 26,
      ts_builtin_sym_end,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1707] = 6,
    ACTIONS(9), 1,
      sym_note,
    ACTIONS(11), 1,
      sym_degree,
    STATE(2), 1,
      sym_root,
    STATE(36), 2,
      sym__event,
      sym_chord,
    ACTIONS(241), 5,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
    ACTIONS(239), 22,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1752] = 2,
    ACTIONS(245), 7,
      sym_inline_mml,
      sym_mode_polychord,
      sym_mode_drop2,
      sym_octave_up,
      sym_octave_down,
      sym_note,
      sym_degree,
    ACTIONS(243), 22,
      sym_inline_abc,
      sym_tempo,
      sym_midi_pc,
      sym_bar,
      sym_bar_slash,
      sym_key,
      sym_scale,
      sym_mode_chord_over_bass_note,
      sym_mode_slash_chord_inversion,
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
  [1786] = 1,
    ACTIONS(247), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 57,
  [SMALL_STATE(8)] = 114,
  [SMALL_STATE(9)] = 171,
  [SMALL_STATE(10)] = 228,
  [SMALL_STATE(11)] = 277,
  [SMALL_STATE(12)] = 326,
  [SMALL_STATE(13)] = 375,
  [SMALL_STATE(14)] = 432,
  [SMALL_STATE(15)] = 486,
  [SMALL_STATE(16)] = 540,
  [SMALL_STATE(17)] = 597,
  [SMALL_STATE(18)] = 654,
  [SMALL_STATE(19)] = 705,
  [SMALL_STATE(20)] = 762,
  [SMALL_STATE(21)] = 813,
  [SMALL_STATE(22)] = 864,
  [SMALL_STATE(23)] = 915,
  [SMALL_STATE(24)] = 963,
  [SMALL_STATE(25)] = 1011,
  [SMALL_STATE(26)] = 1055,
  [SMALL_STATE(27)] = 1096,
  [SMALL_STATE(28)] = 1137,
  [SMALL_STATE(29)] = 1175,
  [SMALL_STATE(30)] = 1213,
  [SMALL_STATE(31)] = 1251,
  [SMALL_STATE(32)] = 1289,
  [SMALL_STATE(33)] = 1327,
  [SMALL_STATE(34)] = 1365,
  [SMALL_STATE(35)] = 1403,
  [SMALL_STATE(36)] = 1441,
  [SMALL_STATE(37)] = 1479,
  [SMALL_STATE(38)] = 1517,
  [SMALL_STATE(39)] = 1555,
  [SMALL_STATE(40)] = 1593,
  [SMALL_STATE(41)] = 1631,
  [SMALL_STATE(42)] = 1669,
  [SMALL_STATE(43)] = 1707,
  [SMALL_STATE(44)] = 1752,
  [SMALL_STATE(45)] = 1786,
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
  [34] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 1, .production_id = 3),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 1, .production_id = 3),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym__lower, 1, .production_id = 3), SHIFT(11),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1, .production_id = 1),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 1, .production_id = 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1, .production_id = 2),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 1, .production_id = 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 7),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 1, .production_id = 7),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 19),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 19),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 2, .production_id = 19), SHIFT_REPEAT(12),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 2, .production_id = 18),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 2, .production_id = 18),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1, .production_id = 10),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality, 1, .production_id = 10),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quality_repeat1, 1, .production_id = 8),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quality_repeat1, 1, .production_id = 8),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_base, 1),
  [80] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality_base, 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality_modifier, 1),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quality_modifier, 1),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 6),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 6),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 4),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 4),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 15),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 15),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [108] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [114] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(44),
  [117] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [120] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 11),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 11),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 21),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 21),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 16),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 16),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 5),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 5),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 1),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bass, 1),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_on_bass, 1),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_on_bass, 1),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 6),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 6),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 15),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 15),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 4),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 4),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 2, .production_id = 5),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 2, .production_id = 5),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 2, .production_id = 14),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bass, 2, .production_id = 14),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_on_bass, 2, .production_id = 14),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_on_bass, 2, .production_id = 14),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 9),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 2, .production_id = 9),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 13),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 13),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 20),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 20),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 12),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 12),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 17),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 3, .production_id = 17),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 22),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 22),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 4, .production_id = 23),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 4, .production_id = 23),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 11),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 11),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 3, .production_id = 16),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 3, .production_id = 16),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 5, .production_id = 24),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_chord, 5, .production_id = 24),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__lower, 4, .production_id = 21),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__lower, 4, .production_id = 21),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_separator, 1, .dynamic_precedence = 1),
  [245] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_separator, 1, .dynamic_precedence = 1),
  [247] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
