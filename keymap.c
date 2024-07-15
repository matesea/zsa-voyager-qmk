#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,               KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_GRV,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,               KC_I,           KC_O,           KC_P,           KC_BSLS,
    KC_TAB,         KC_A,           KC_S,           MT(MOD_LALT, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                     KC_H,           MT(MOD_RSFT, KC_J), MT(MOD_LALT, KC_K),KC_L,        KC_SCLN,        KC_QUOTE,
    KC_CAPS,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,               KC_COMMA,       KC_DOT,         KC_SLASH,       KC_EQUAL,
                                                    MT(MOD_LGUI, KC_ENTER),KC_LEFT_CTRL,                                   LT(1,KC_BSPC),  KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCR,        KC_SCRL,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_INSERT,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_DELETE,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,        KC_APPLICATION, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    TO(0),          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    QK_BOOT,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F11,         KC_F12,         RGB_VAD,        RGB_VAI,        RGB_TOG,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo4[] = { MT(MOD_RSFT, KC_J), MT(MOD_LALT, KC_K), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LSFT(KC_LEFT_CTRL)),
    COMBO(combo1, TO(1)),
    COMBO(combo2, ST_MACRO_0),
    COMBO(combo3, TO(2)),
    COMBO(combo4, KC_ESCAPE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_F):
            return g_tapping_term -40;
        case MT(MOD_RSFT, KC_J):
            return g_tapping_term -40;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {204,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0, 0, 0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {127,234,222}, {127,234,222}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {0,0,0}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {0,0,0}, {21,228,212}, {21,228,212}, {21,228,212}, {21,228,212}, {127,234,222}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {204,255,255}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {6,255,255}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {0,0,0}, {83,193,218}, {83,193,218}, {44,255,255}, {44,255,255}, {44,255,255}, {21,228,212}, {21,228,212}, {21,228,212}, {151,234,222}, {151,234,222}, {151,234,222}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_LBRC));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


#ifdef KEY_OVERRIDE_ENABLE
// https://docs.qmk.fm/#/feature_key_overrides
const key_override_t **key_overrides = (const key_override_t *[]){
    // SHIFT+BSPC -> DEL
    // &ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL),
    &ko_make_basic(MOD_MASK_SHIFT, LT(1,KC_BSPC), KC_DEL),

    // SHIFT+ESC -> ~
    &ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV)),
    // ALT+ESC -> `
    &ko_make_basic(MOD_MASK_ALT, KC_ESC, KC_GRV),

    // ALT+] ->[
    /* &ko_make_basic(MOD_MASK_ALT, KC_RBRC, KC_LBRC), */

    // Null terminator is required at the end.
    NULL
};
#endif

#ifdef LEADER_ENABLE
// https://docs.qmk.fm/features/leader_key
void leader_start_user(void) {
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_S)) {
        // Leader, sp => space
        tap_code16(KC_SPACE);
    } else if (leader_sequence_one_key(KC_E)) {
        tap_code16(KC_ESC);
    } else if (leader_sequence_one_key(KC_1)) {
        tap_code16(TO(1));
    } else if (leader_sequence_one_key(KC_2)) {
        tap_code16(TO(2));
    } else if (leader_sequence_one_key(KC_C)) {
        tap_code16(LSFT(KC_LEFT_CTRL));
    } else if (leader_sequence_two_keys(KC_T, KC_C)) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_LBRC));
    }
}
#endif
