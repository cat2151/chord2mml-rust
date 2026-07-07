#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 18
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 60
#define ALIAS_COUNT 0
#define TOKEN_COUNT 51
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 10

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
  aux_sym_quality_token1 = 10,
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
  anon_sym_min = 34,
  anon_sym_Min = 35,
  anon_sym_MIN = 36,
  anon_sym_m = 37,
  anon_sym_7sus2 = 38,
  anon_sym_7sus4 = 39,
  anon_sym_sus4 = 40,
  anon_sym_sus2 = 41,
  anon_sym_dim = 42,
  anon_sym_aug = 43,
  anon_sym_PLUS = 44,
  anon_sym_13 = 45,
  anon_sym_11 = 46,
  anon_sym_92 = 47,
  anon_sym_7 = 48,
  anon_sym_62 = 49,
  anon_sym_SLASH = 50,
  sym_source_file = 51,
  sym_separator = 52,
  sym_chord = 53,
  sym_root = 54,
  sym_accidental = 55,
  sym_quality = 56,
  sym_bass = 57,
  aux_sym_source_file_repeat1 = 58,
  aux_sym_root_repeat1 = 59,
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
  [aux_sym_quality_token1] = "quality_token1",
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
  [anon_sym_SLASH] = "/",
  [sym_source_file] = "source_file",
  [sym_separator] = "separator",
  [sym_chord] = "chord",
  [sym_root] = "root",
  [sym_accidental] = "accidental",
  [sym_quality] = "quality",
  [sym_bass] = "bass",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_root_repeat1] = "root_repeat1",
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
  [aux_sym_quality_token1] = aux_sym_quality_token1,
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
  [anon_sym_SLASH] = anon_sym_SLASH,
  [sym_source_file] = sym_source_file,
  [sym_separator] = sym_separator,
  [sym_chord] = sym_chord,
  [sym_root] = sym_root,
  [sym_accidental] = sym_accidental,
  [sym_quality] = sym_quality,
  [sym_bass] = sym_bass,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_root_repeat1] = aux_sym_root_repeat1,
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
  [aux_sym_quality_token1] = {
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
};

enum {
  field_accidental = 1,
  field_bass = 2,
  field_note = 3,
  field_quality = 4,
  field_root = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_accidental] = "accidental",
  [field_bass] = "bass",
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
  [7] = {.index = 9, .length = 2},
  [8] = {.index = 11, .length = 1},
  [9] = {.index = 12, .length = 3},
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
    {field_bass, 1},
    {field_root, 0},
  [9] =
    {field_accidental, 0, .inherited = true},
    {field_accidental, 1, .inherited = true},
  [11] =
    {field_root, 1},
  [12] =
    {field_bass, 2},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(30);
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '+') ADVANCE(74);
      if (lookahead == '-') ADVANCE(31);
      if (lookahead == '/') ADVANCE(80);
      if (lookahead == '1') ADVANCE(7);
      if (lookahead == '4') ADVANCE(6);
      if (lookahead == '6') ADVANCE(79);
      if (lookahead == '7') ADVANCE(78);
      if (lookahead == '9') ADVANCE(77);
      if (lookahead == 'M') ADVANCE(59);
      if (lookahead == 'a') ADVANCE(26);
      if (lookahead == 'b') ADVANCE(38);
      if (lookahead == 'd') ADVANCE(18);
      if (lookahead == 'm') ADVANCE(67);
      if (lookahead == 's') ADVANCE(27);
      if (lookahead == 8594) ADVANCE(32);
      if (lookahead == 9651) ADVANCE(55);
      if (lookahead == 9837) ADVANCE(39);
      if (lookahead == 9839) ADVANCE(37);
      if (lookahead == 12539) ADVANCE(33);
      if (lookahead == 65283) ADVANCE(36);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'G')) ADVANCE(34);
      END_STATE();
    case 1:
      if (lookahead == ')') ADVANCE(49);
      END_STATE();
    case 2:
      if (lookahead == ')') ADVANCE(50);
      END_STATE();
    case 3:
      if (lookahead == ')') ADVANCE(48);
      END_STATE();
    case 4:
      if (lookahead == ')') ADVANCE(47);
      END_STATE();
    case 5:
      if (lookahead == ')') ADVANCE(46);
      END_STATE();
    case 6:
      if (lookahead == '.') ADVANCE(29);
      END_STATE();
    case 7:
      if (lookahead == '1') ADVANCE(76);
      if (lookahead == '3') ADVANCE(75);
      END_STATE();
    case 8:
      if (lookahead == '2') ADVANCE(71);
      if (lookahead == '4') ADVANCE(70);
      END_STATE();
    case 9:
      if (lookahead == '2') ADVANCE(68);
      if (lookahead == '4') ADVANCE(69);
      END_STATE();
    case 10:
      if (lookahead == '9') ADVANCE(1);
      END_STATE();
    case 11:
      if (lookahead == '9') ADVANCE(2);
      END_STATE();
    case 12:
      if (lookahead == '9') ADVANCE(3);
      END_STATE();
    case 13:
      if (lookahead == '9') ADVANCE(4);
      END_STATE();
    case 14:
      if (lookahead == '9') ADVANCE(5);
      END_STATE();
    case 15:
      if (lookahead == 'J') ADVANCE(58);
      END_STATE();
    case 16:
      if (lookahead == 'N') ADVANCE(66);
      END_STATE();
    case 17:
      if (lookahead == 'g') ADVANCE(73);
      END_STATE();
    case 18:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 19:
      if (lookahead == 'j') ADVANCE(57);
      END_STATE();
    case 20:
      if (lookahead == 'j') ADVANCE(56);
      END_STATE();
    case 21:
      if (lookahead == 'm') ADVANCE(72);
      END_STATE();
    case 22:
      if (lookahead == 'n') ADVANCE(65);
      END_STATE();
    case 23:
      if (lookahead == 'n') ADVANCE(64);
      END_STATE();
    case 24:
      if (lookahead == 's') ADVANCE(8);
      END_STATE();
    case 25:
      if (lookahead == 's') ADVANCE(9);
      END_STATE();
    case 26:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 27:
      if (lookahead == 'u') ADVANCE(24);
      END_STATE();
    case 28:
      if (lookahead == 'u') ADVANCE(25);
      END_STATE();
    case 29:
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_note);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_3);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_4);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_b);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_5);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_quality_token1);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_maj9);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_Maj9);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_MAJ9);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_M9);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_9);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_maj_LPAREN9_RPAREN);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_Maj_LPAREN9_RPAREN);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_MAJ_LPAREN9_RPAREN);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_M_LPAREN9_RPAREN);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_LPAREN9_RPAREN);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_maj7);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_Maj7);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_MAJ7);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_M7);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_6);
      if (lookahead == '(') ADVANCE(11);
      if (lookahead == '9') ADVANCE(45);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_maj);
      if (lookahead == '(') ADVANCE(14);
      if (lookahead == '7') ADVANCE(51);
      if (lookahead == '9') ADVANCE(41);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_Maj);
      if (lookahead == '(') ADVANCE(13);
      if (lookahead == '7') ADVANCE(52);
      if (lookahead == '9') ADVANCE(42);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_MAJ);
      if (lookahead == '(') ADVANCE(12);
      if (lookahead == '7') ADVANCE(53);
      if (lookahead == '9') ADVANCE(43);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_M);
      if (lookahead == '(') ADVANCE(10);
      if (lookahead == '7') ADVANCE(54);
      if (lookahead == '9') ADVANCE(44);
      if (lookahead == 'A') ADVANCE(15);
      if (lookahead == 'I') ADVANCE(16);
      if (lookahead == 'a') ADVANCE(19);
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_min7);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_Min7);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_MIN7);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_m7);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_min);
      if (lookahead == '7') ADVANCE(60);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_Min);
      if (lookahead == '7') ADVANCE(61);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_MIN);
      if (lookahead == '7') ADVANCE(62);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_m);
      if (lookahead == '7') ADVANCE(63);
      if (lookahead == 'a') ADVANCE(20);
      if (lookahead == 'i') ADVANCE(23);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_7sus2);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_7sus4);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_sus4);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_sus2);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_dim);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_aug);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_13);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_11);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_92);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_7);
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_62);
      END_STATE();
    case 80:
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
    [aux_sym_quality_token1] = ACTIONS(1),
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
    [anon_sym_SLASH] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(17),
    [sym_separator] = STATE(8),
    [sym_chord] = STATE(8),
    [sym_root] = STATE(7),
    [aux_sym_source_file_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(5),
    [anon_sym_] = ACTIONS(5),
    [anon_sym_2] = ACTIONS(5),
    [sym_note] = ACTIONS(7),
  },
  [2] = {
    [sym_accidental] = STATE(6),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [anon_sym_DASH] = ACTIONS(9),
    [anon_sym_] = ACTIONS(9),
    [anon_sym_2] = ACTIONS(9),
    [sym_note] = ACTIONS(9),
    [anon_sym_POUND] = ACTIONS(11),
    [anon_sym_3] = ACTIONS(11),
    [anon_sym_4] = ACTIONS(11),
    [anon_sym_b] = ACTIONS(11),
    [anon_sym_5] = ACTIONS(11),
    [aux_sym_quality_token1] = ACTIONS(9),
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
    [anon_sym_6] = ACTIONS(13),
    [anon_sym_maj] = ACTIONS(13),
    [anon_sym_Maj] = ACTIONS(13),
    [anon_sym_MAJ] = ACTIONS(13),
    [anon_sym_M] = ACTIONS(13),
    [anon_sym_min7] = ACTIONS(9),
    [anon_sym_Min7] = ACTIONS(9),
    [anon_sym_MIN7] = ACTIONS(9),
    [anon_sym_m7] = ACTIONS(9),
    [anon_sym_min] = ACTIONS(13),
    [anon_sym_Min] = ACTIONS(13),
    [anon_sym_MIN] = ACTIONS(13),
    [anon_sym_m] = ACTIONS(13),
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
    [anon_sym_7] = ACTIONS(13),
    [anon_sym_62] = ACTIONS(9),
    [anon_sym_SLASH] = ACTIONS(9),
  },
  [3] = {
    [sym_accidental] = STATE(6),
    [aux_sym_root_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(15),
    [anon_sym_] = ACTIONS(15),
    [anon_sym_2] = ACTIONS(15),
    [sym_note] = ACTIONS(15),
    [anon_sym_POUND] = ACTIONS(11),
    [anon_sym_3] = ACTIONS(11),
    [anon_sym_4] = ACTIONS(11),
    [anon_sym_b] = ACTIONS(11),
    [anon_sym_5] = ACTIONS(11),
    [aux_sym_quality_token1] = ACTIONS(15),
    [anon_sym_maj9] = ACTIONS(15),
    [anon_sym_Maj9] = ACTIONS(15),
    [anon_sym_MAJ9] = ACTIONS(15),
    [anon_sym_M9] = ACTIONS(15),
    [anon_sym_9] = ACTIONS(15),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(15),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(15),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(15),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(15),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(15),
    [anon_sym_maj7] = ACTIONS(15),
    [anon_sym_Maj7] = ACTIONS(15),
    [anon_sym_MAJ7] = ACTIONS(15),
    [anon_sym_M7] = ACTIONS(15),
    [anon_sym_6] = ACTIONS(17),
    [anon_sym_maj] = ACTIONS(17),
    [anon_sym_Maj] = ACTIONS(17),
    [anon_sym_MAJ] = ACTIONS(17),
    [anon_sym_M] = ACTIONS(17),
    [anon_sym_min7] = ACTIONS(15),
    [anon_sym_Min7] = ACTIONS(15),
    [anon_sym_MIN7] = ACTIONS(15),
    [anon_sym_m7] = ACTIONS(15),
    [anon_sym_min] = ACTIONS(17),
    [anon_sym_Min] = ACTIONS(17),
    [anon_sym_MIN] = ACTIONS(17),
    [anon_sym_m] = ACTIONS(17),
    [anon_sym_7sus2] = ACTIONS(15),
    [anon_sym_7sus4] = ACTIONS(15),
    [anon_sym_sus4] = ACTIONS(15),
    [anon_sym_sus2] = ACTIONS(15),
    [anon_sym_dim] = ACTIONS(15),
    [anon_sym_aug] = ACTIONS(15),
    [anon_sym_PLUS] = ACTIONS(15),
    [anon_sym_13] = ACTIONS(15),
    [anon_sym_11] = ACTIONS(15),
    [anon_sym_92] = ACTIONS(15),
    [anon_sym_7] = ACTIONS(17),
    [anon_sym_62] = ACTIONS(15),
    [anon_sym_SLASH] = ACTIONS(15),
  },
  [4] = {
    [sym_accidental] = STATE(6),
    [aux_sym_root_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(19),
    [anon_sym_] = ACTIONS(19),
    [anon_sym_2] = ACTIONS(19),
    [sym_note] = ACTIONS(19),
    [anon_sym_POUND] = ACTIONS(21),
    [anon_sym_3] = ACTIONS(21),
    [anon_sym_4] = ACTIONS(21),
    [anon_sym_b] = ACTIONS(21),
    [anon_sym_5] = ACTIONS(21),
    [aux_sym_quality_token1] = ACTIONS(19),
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
    [anon_sym_6] = ACTIONS(24),
    [anon_sym_maj] = ACTIONS(24),
    [anon_sym_Maj] = ACTIONS(24),
    [anon_sym_MAJ] = ACTIONS(24),
    [anon_sym_M] = ACTIONS(24),
    [anon_sym_min7] = ACTIONS(19),
    [anon_sym_Min7] = ACTIONS(19),
    [anon_sym_MIN7] = ACTIONS(19),
    [anon_sym_m7] = ACTIONS(19),
    [anon_sym_min] = ACTIONS(24),
    [anon_sym_Min] = ACTIONS(24),
    [anon_sym_MIN] = ACTIONS(24),
    [anon_sym_m] = ACTIONS(24),
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
    [anon_sym_7] = ACTIONS(24),
    [anon_sym_62] = ACTIONS(19),
    [anon_sym_SLASH] = ACTIONS(19),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(26),
    [anon_sym_DASH] = ACTIONS(26),
    [anon_sym_] = ACTIONS(26),
    [anon_sym_2] = ACTIONS(26),
    [sym_note] = ACTIONS(26),
    [anon_sym_POUND] = ACTIONS(26),
    [anon_sym_3] = ACTIONS(26),
    [anon_sym_4] = ACTIONS(26),
    [anon_sym_b] = ACTIONS(26),
    [anon_sym_5] = ACTIONS(26),
    [aux_sym_quality_token1] = ACTIONS(26),
    [anon_sym_maj9] = ACTIONS(26),
    [anon_sym_Maj9] = ACTIONS(26),
    [anon_sym_MAJ9] = ACTIONS(26),
    [anon_sym_M9] = ACTIONS(26),
    [anon_sym_9] = ACTIONS(26),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(26),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(26),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(26),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(26),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(26),
    [anon_sym_maj7] = ACTIONS(26),
    [anon_sym_Maj7] = ACTIONS(26),
    [anon_sym_MAJ7] = ACTIONS(26),
    [anon_sym_M7] = ACTIONS(26),
    [anon_sym_6] = ACTIONS(28),
    [anon_sym_maj] = ACTIONS(28),
    [anon_sym_Maj] = ACTIONS(28),
    [anon_sym_MAJ] = ACTIONS(28),
    [anon_sym_M] = ACTIONS(28),
    [anon_sym_min7] = ACTIONS(26),
    [anon_sym_Min7] = ACTIONS(26),
    [anon_sym_MIN7] = ACTIONS(26),
    [anon_sym_m7] = ACTIONS(26),
    [anon_sym_min] = ACTIONS(28),
    [anon_sym_Min] = ACTIONS(28),
    [anon_sym_MIN] = ACTIONS(28),
    [anon_sym_m] = ACTIONS(28),
    [anon_sym_7sus2] = ACTIONS(26),
    [anon_sym_7sus4] = ACTIONS(26),
    [anon_sym_sus4] = ACTIONS(26),
    [anon_sym_sus2] = ACTIONS(26),
    [anon_sym_dim] = ACTIONS(26),
    [anon_sym_aug] = ACTIONS(26),
    [anon_sym_PLUS] = ACTIONS(26),
    [anon_sym_13] = ACTIONS(26),
    [anon_sym_11] = ACTIONS(26),
    [anon_sym_92] = ACTIONS(26),
    [anon_sym_7] = ACTIONS(28),
    [anon_sym_62] = ACTIONS(26),
    [anon_sym_SLASH] = ACTIONS(26),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(30),
    [anon_sym_DASH] = ACTIONS(30),
    [anon_sym_] = ACTIONS(30),
    [anon_sym_2] = ACTIONS(30),
    [sym_note] = ACTIONS(30),
    [anon_sym_POUND] = ACTIONS(30),
    [anon_sym_3] = ACTIONS(30),
    [anon_sym_4] = ACTIONS(30),
    [anon_sym_b] = ACTIONS(30),
    [anon_sym_5] = ACTIONS(30),
    [aux_sym_quality_token1] = ACTIONS(30),
    [anon_sym_maj9] = ACTIONS(30),
    [anon_sym_Maj9] = ACTIONS(30),
    [anon_sym_MAJ9] = ACTIONS(30),
    [anon_sym_M9] = ACTIONS(30),
    [anon_sym_9] = ACTIONS(30),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(30),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(30),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(30),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(30),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(30),
    [anon_sym_maj7] = ACTIONS(30),
    [anon_sym_Maj7] = ACTIONS(30),
    [anon_sym_MAJ7] = ACTIONS(30),
    [anon_sym_M7] = ACTIONS(30),
    [anon_sym_6] = ACTIONS(32),
    [anon_sym_maj] = ACTIONS(32),
    [anon_sym_Maj] = ACTIONS(32),
    [anon_sym_MAJ] = ACTIONS(32),
    [anon_sym_M] = ACTIONS(32),
    [anon_sym_min7] = ACTIONS(30),
    [anon_sym_Min7] = ACTIONS(30),
    [anon_sym_MIN7] = ACTIONS(30),
    [anon_sym_m7] = ACTIONS(30),
    [anon_sym_min] = ACTIONS(32),
    [anon_sym_Min] = ACTIONS(32),
    [anon_sym_MIN] = ACTIONS(32),
    [anon_sym_m] = ACTIONS(32),
    [anon_sym_7sus2] = ACTIONS(30),
    [anon_sym_7sus4] = ACTIONS(30),
    [anon_sym_sus4] = ACTIONS(30),
    [anon_sym_sus2] = ACTIONS(30),
    [anon_sym_dim] = ACTIONS(30),
    [anon_sym_aug] = ACTIONS(30),
    [anon_sym_PLUS] = ACTIONS(30),
    [anon_sym_13] = ACTIONS(30),
    [anon_sym_11] = ACTIONS(30),
    [anon_sym_92] = ACTIONS(30),
    [anon_sym_7] = ACTIONS(32),
    [anon_sym_62] = ACTIONS(30),
    [anon_sym_SLASH] = ACTIONS(30),
  },
  [7] = {
    [sym_quality] = STATE(10),
    [sym_bass] = STATE(13),
    [ts_builtin_sym_end] = ACTIONS(34),
    [anon_sym_DASH] = ACTIONS(34),
    [anon_sym_] = ACTIONS(34),
    [anon_sym_2] = ACTIONS(34),
    [sym_note] = ACTIONS(34),
    [aux_sym_quality_token1] = ACTIONS(36),
    [anon_sym_maj9] = ACTIONS(36),
    [anon_sym_Maj9] = ACTIONS(36),
    [anon_sym_MAJ9] = ACTIONS(36),
    [anon_sym_M9] = ACTIONS(36),
    [anon_sym_9] = ACTIONS(36),
    [anon_sym_maj_LPAREN9_RPAREN] = ACTIONS(36),
    [anon_sym_Maj_LPAREN9_RPAREN] = ACTIONS(36),
    [anon_sym_MAJ_LPAREN9_RPAREN] = ACTIONS(36),
    [anon_sym_M_LPAREN9_RPAREN] = ACTIONS(36),
    [anon_sym_LPAREN9_RPAREN] = ACTIONS(36),
    [anon_sym_maj7] = ACTIONS(36),
    [anon_sym_Maj7] = ACTIONS(36),
    [anon_sym_MAJ7] = ACTIONS(36),
    [anon_sym_M7] = ACTIONS(36),
    [anon_sym_6] = ACTIONS(38),
    [anon_sym_maj] = ACTIONS(38),
    [anon_sym_Maj] = ACTIONS(38),
    [anon_sym_MAJ] = ACTIONS(38),
    [anon_sym_M] = ACTIONS(38),
    [anon_sym_min7] = ACTIONS(36),
    [anon_sym_Min7] = ACTIONS(36),
    [anon_sym_MIN7] = ACTIONS(36),
    [anon_sym_m7] = ACTIONS(36),
    [anon_sym_min] = ACTIONS(38),
    [anon_sym_Min] = ACTIONS(38),
    [anon_sym_MIN] = ACTIONS(38),
    [anon_sym_m] = ACTIONS(38),
    [anon_sym_7sus2] = ACTIONS(36),
    [anon_sym_7sus4] = ACTIONS(36),
    [anon_sym_sus4] = ACTIONS(36),
    [anon_sym_sus2] = ACTIONS(36),
    [anon_sym_dim] = ACTIONS(36),
    [anon_sym_aug] = ACTIONS(36),
    [anon_sym_PLUS] = ACTIONS(36),
    [anon_sym_13] = ACTIONS(36),
    [anon_sym_11] = ACTIONS(36),
    [anon_sym_92] = ACTIONS(36),
    [anon_sym_7] = ACTIONS(38),
    [anon_sym_62] = ACTIONS(36),
    [anon_sym_SLASH] = ACTIONS(40),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(7), 1,
      sym_note,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
    STATE(7), 1,
      sym_root,
    ACTIONS(5), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(9), 3,
      sym_separator,
      sym_chord,
      aux_sym_source_file_repeat1,
  [20] = 5,
    ACTIONS(44), 1,
      ts_builtin_sym_end,
    ACTIONS(49), 1,
      sym_note,
    STATE(7), 1,
      sym_root,
    ACTIONS(46), 3,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
    STATE(9), 3,
      sym_separator,
      sym_chord,
      aux_sym_source_file_repeat1,
  [40] = 3,
    ACTIONS(40), 1,
      anon_sym_SLASH,
    STATE(15), 1,
      sym_bass,
    ACTIONS(52), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [54] = 1,
    ACTIONS(54), 6,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
      anon_sym_SLASH,
  [63] = 1,
    ACTIONS(56), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [71] = 1,
    ACTIONS(58), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [79] = 1,
    ACTIONS(60), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [87] = 1,
    ACTIONS(62), 5,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_,
      anon_sym_2,
      sym_note,
  [95] = 2,
    ACTIONS(7), 1,
      sym_note,
    STATE(14), 1,
      sym_root,
  [102] = 1,
    ACTIONS(64), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 20,
  [SMALL_STATE(10)] = 40,
  [SMALL_STATE(11)] = 54,
  [SMALL_STATE(12)] = 63,
  [SMALL_STATE(13)] = 71,
  [SMALL_STATE(14)] = 79,
  [SMALL_STATE(15)] = 87,
  [SMALL_STATE(16)] = 95,
  [SMALL_STATE(17)] = 102,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1, .production_id = 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 1, .production_id = 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 2, .production_id = 4),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_root, 2, .production_id = 4),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 7),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 7), SHIFT_REPEAT(5),
  [24] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2, .production_id = 7),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_accidental, 1),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_accidental, 1),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 1, .production_id = 3),
  [32] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 1, .production_id = 3),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 1, .production_id = 2),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [38] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(12),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 5),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quality, 1),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_separator, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 2, .production_id = 6),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bass, 2, .production_id = 8),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_chord, 3, .production_id = 9),
  [64] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
