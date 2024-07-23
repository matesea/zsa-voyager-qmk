#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
};

#define BASE 0
#define NAVI 1
#define SYS 2

#define BASE_IME    S(KC_LCTL)
#define BASE_A      MT(MOD_LALT, KC_A)
#define BASE_S      MT(MOD_LGUI, KC_S)
#define BASE_D      LT(NAVI, KC_D)
#define BASE_F      MT(MOD_LSFT, KC_F)

#define BASE_J      MT(MOD_RSFT, KC_J)
#define BASE_K      MT(MOD_RGUI, KC_K)
#define BASE_L      MT(MOD_LALT, KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_voyager(
    QK_GESC,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
    KC_EQL,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    KC_TAB,         BASE_A,         BASE_S,         BASE_D,         BASE_F,         KC_G,                                           KC_H,           BASE_J,         BASE_K,         BASE_L,         KC_SCLN,        KC_QUOT,
    BASE_IME,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        QK_LEAD,
                                                    KC_ENT, KC_LCTL,                                               KC_BSPC,  KC_SPC
  ),
  [NAVI] = LAYOUT_voyager(
    TO(BASE),       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        ST_MACRO_0,     KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_INSERT,      KC_SCRL,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_DELETE,      KC_PSCR,
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                        KC_LCBR,        KC_LBRC,        KC_RBRC,        KC_RCBR,        KC_APPLICATION, KC_CAPS,
                                                    KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_TRNS
  ),
  [SYS] = LAYOUT_voyager(
    TO(BASE),       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    QK_BOOT,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,        KC_F11,         KC_F12,         RGB_VAD,        RGB_VAI,        RGB_TOG,                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    DT_PRNT,        DT_DOWN,        DT_UP,          KC_VOLD,        KC_VOLU,        KC_MUTE,                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_TRNS
  ),
};

#if defined(COMBO_ENABLE)
enum combos {
    CVNAVI,
    MCNAVI,
    DSSYS,
};

const uint16_t PROGMEM cv_combo[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mc_combo[] = { KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cd_combo[] = { KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [CVNAVI] = COMBO(cv_combo, TO(NAVI)),
    [MCNAVI] = COMBO(mc_combo, TO(NAVI)),
    [DSSYS] = COMBO(cd_combo, TO(SYS)),
};
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE_F:
        case BASE_J:
            return g_tapping_term - 20;
        case BASE_S:
        case BASE_L:
            return g_tapping_term + 20;
        case BASE_A:
            return g_tapping_term + 30;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [NAVI] = { {204,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {184,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {127,234,222}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {127,234,222}, {29,239,251}, {29,239,251}, {29,239,251}, {29,239,251}, {127,234,222}, {174,218,204}, {0,0,0}, {0,0,0} },

    [SYS] = { {204,255,255}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {6,255,255}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {0,0,0}, {83,193,218}, {83,193,218}, {44,255,255}, {44,255,255}, {44,255,255}, {21,228,212}, {21,228,212}, {21,228,212}, {151,234,222}, {151,234,222}, {151,234,222}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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

#ifdef ACHORDION_ENABLE
// https://getreuer.info/posts/keyboards/achordion/index.html
void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    switch (other_keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        other_keycode &= 0xff;  // Get base keycode.
    }
    // Allow same-hand holds with non-alpha keys.
    if (other_keycode > KC_0) { return true; }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    tap_hold_keycode &= 0xff;
    // only enable achordion for homerow
    switch (tap_hold_keycode) {
        case KC_D: // give LT shorter time to trigger
            return 400;
        case KC_A:
        case KC_S:
        case KC_F:
        case KC_J:
        case KC_K:
        case KC_L:
            return 500;
    }
    // bypass achordion timeout
    return 0;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef ACHORDION_ENABLE
    if (!process_achordion(keycode, record)) return false;
#endif
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
    &ko_make_basic(MOD_MASK_SHIFT, LT(NAVI,KC_BSPC), KC_DEL),

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
    if (leader_sequence_one_key(QK_LEAD)) {
        // Leader -> Leader = ESC
        tap_code(KC_ESC);
    } else if (leader_sequence_one_key(KC_T)) {
        // Leader -> t = ctrl+a [, tmux copy mode
        SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_LBRC));
    }
    /* } else if (leader_sequence_one_key(KC_1)) { */
    /*     layer_move(NAVI); */
    /* } else if (leader_sequence_one_key(KC_2)) { */
    /*     layer_move(SYS); */
    /* } else if (leader_sequence_one_key(KC_C)) { */
    /*     // Leader -> c = ctrl+shift, switch IME */
    /*     tap_code16(LSFT(KC_LEFT_CTRL)); */
}
#endif
