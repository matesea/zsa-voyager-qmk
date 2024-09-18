#include QMK_KEYBOARD_H
#include "version.h"
#include "layout.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  TMUXCPY,  // tmux copy mode
  ARROW,    // -> => <-> <=>
  SELLINE,
  UPDIR,
};

enum {
    BASE = 0,
    NAVI,
    FN,
    PREFIX_LBRC,
    PREFIX_RBRC,
    LAYER_MAX = PREFIX_RBRC,
    /* PREFIX_TMUX */
    /* NEWBASE, */
    /* NUM, */
    /* SYM, */
};


#define BASE_A      MT(MOD_LGUI, KC_A)
/* #define NB_A        LT(SYM, KC_A) */
#define BASE_S      MT(MOD_LALT, KC_S)
#define BASE_D      MT(MOD_LCTL, KC_D)
#define BASE_F      MT(MOD_LSFT, KC_F)

#define BASE_Z      LT(FN, KC_Z)
#define BASE_X      KC_X
#define BASE_C      KC_C
#define BASE_V      LT(NAVI, KC_V)
/* #define NB_V        LT(NUM, KC_V) */

#define BASE_J      MT(MOD_RSFT, KC_J)
#define BASE_K      MT(MOD_RCTL, KC_K)
#define BASE_L      MT(MOD_LALT, KC_L)
#define BASE_SCLN   MT(MOD_RGUI, KC_SCLN)
/* #define NB_SCLN     LT(SYM, KC_SCLN) */

#define BASE_M      LT(PREFIX_LBRC, KC_M)
#define BASE_COMM   LT(PREFIX_RBRC, KC_COMM)
#define BASE_DOT    KC_DOT
#define BASE_SLSH   KC_SLSH

#define BASE_ENT    KC_ENT
#define OSM_SFT     OSM(MOD_LSFT)

#define IME         G(KC_SPC)

/* #define TO_BASE     TO(BASE) */
/* #define TO_NB       TO(NEWBASE) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR(
            KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,     KC_5,
            KC_EQL,   KC_Q,   KC_W,   KC_E,   KC_R,     KC_T,
            KC_TAB,   BASE_A, BASE_S, BASE_D, BASE_F,   KC_G,
            IME,      BASE_Z, BASE_X, BASE_C, BASE_V,   KC_B,
                                              BASE_ENT, OSM_SFT,

                            KC_6,    KC_7,   KC_8,      KC_9,     KC_0,      KC_MINS,
                            KC_Y,    KC_U,   KC_I,      KC_O,     KC_P,      KC_BSLS,
                            KC_H,    BASE_J, BASE_K,    BASE_L,   BASE_SCLN, KC_QUOT,
                            KC_N,    BASE_M, BASE_COMM, BASE_DOT, BASE_SLSH, KC_UNDS,
                            KC_BSPC, KC_SPC
            ),

    [NAVI] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
                                                _______, QK_LLCK,

                              TMUXCPY, UPDIR,   SELLINE, ARROW,   XXXXXXX, XXXXXXX,
                              KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  KC_INS,
                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_PSCR,
                              KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_APP,  XXXXXXX,
                              _______, _______
            ),

    [FN] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, QK_LLCK,

                              KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, QK_BOOT,
                              RGB_TOG, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
                              RGB_MOD, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,
                              RGB_RMOD,KC_F1,   KC_F2,   KC_F3,   KC_F12,  XXXXXXX,
                              _______, _______
            ),

    [PREFIX_LBRC] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
                                                _______, _______,

                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______
            ),

    [PREFIX_RBRC] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
                                                _______, _______,

                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______
            ),

    /*
    [PREFIX_TMUX] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
                                                _______, _______,

                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______
            ),
    [NEWBASE] = LAYOUT_LR(
            KC_ESC,    KC_COLN,  KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
            KC_EQL,    KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,
            KC_TAB,    NB_A,     BASE_S,  BASE_D,  BASE_F,   KC_G,
            IME,       BASE_Z,   BASE_X,  BASE_C,  NB_V,     KC_B,
                                                   KC_ENT,   KC_LCTL,

                                 KC_LEFT,  KC_DOWN,  KC_UP,     KC_RGHT,  KC_UNDS,    KC_MINS,
                                 KC_Y,     KC_U,     KC_I,      KC_O,     KC_P,       KC_BSLS,
                                 KC_H,     BASE_J,   BASE_K,    BASE_L,   NB_SCLN,    KC_QUOT,
                                 KC_N,     BASE_M,   BASE_COMM, BASE_DOT, BASE_SLSH,  KC_UNDS,
                                 KC_BSPC,  KC_SPC
            ),
    [NUM] = LAYOUT_LR(
            _______,   _______,  _______, _______, _______,  _______,
            _______,   _______,  _______, _______, _______,  _______,
            _______,   _______,  _______, _______, _______,  _______,
            _______,   _______,  _______, _______, _______,  _______,
                                                   _______,  _______,

                                 QK_LLCK,  KC_TAB,   _______,  _______,  _______,  _______,
                                 KC_COLN,  KC_7,     KC_8,     KC_9,     KC_PLUS,  KC_ASTR,
                                 KC_COMM,  KC_4,     KC_5,     KC_6,     KC_MINS,  KC_SLSH,
                                 KC_0,     KC_1,     KC_2,     KC_3,     KC_DOT,   KC_EQL,
                                 _______,  _______
            ),

    [SYM] = LAYOUT_LR(
            QK_LLCK, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
                                                _______, _______,

                              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_UNDS,
                              KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PLUS,  KC_PIPE,
                              KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC, KC_COLN,  KC_DQUO,
                              KC_PERC, KC_CIRC, KC_LABK, KC_RABK, KC_QUES,  _______,
                              _______, _______
            ),
    */



};

#if defined(COMBO_ENABLE)
enum combos {
    /* left hand */
    FG_ESC,
    CV_IME,
    VB_CW,
    XC_CTRL,

    /* right hand */
    HJ_ESC,
    MC_NAVI,

    /* return BASE from other layers */
    NAVI_BASE,
    FN_BASE,
};

const uint16_t PROGMEM fg_esc[] = { BASE_F, KC_G, COMBO_END};
const uint16_t PROGMEM cv_ime[] = { BASE_C, BASE_V, COMBO_END};
const uint16_t PROGMEM vb_cw[] = {  BASE_D, BASE_V, COMBO_END};
const uint16_t PROGMEM xc_ctrl[] = {  BASE_X, BASE_C, COMBO_END};

const uint16_t PROGMEM hj_esc[] = { BASE_J, KC_H, COMBO_END};
const uint16_t PROGMEM mc_navi[] = { BASE_M, BASE_COMM, COMBO_END};

const uint16_t PROGMEM navi_base[] = { KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM fn_base[] = { RGB_MOD, KC_F4, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [FG_ESC] = COMBO(fg_esc, KC_ESC),
    [CV_IME] = COMBO(cv_ime, IME),
    [VB_CW] = COMBO(vb_cw, CW_TOGG),
    [XC_CTRL] = COMBO(xc_ctrl, OSM(MOD_LCTL)),

    [HJ_ESC] = COMBO(hj_esc, KC_ESC),
    [MC_NAVI] = COMBO(mc_navi, TO(NAVI)),

    [NAVI_BASE] = COMBO(navi_base, TO(BASE)),
    [FN_BASE] = COMBO(fn_base, TO(BASE)),
};
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE_F:
        case BASE_J:
            return g_tapping_term - 20;
        case BASE_S:
        case BASE_X:
        case BASE_L:
        case BASE_DOT:
            return g_tapping_term + 20;
        case BASE_A:
        case BASE_Z:
        case BASE_SLSH:
        case BASE_SCLN:
        case BASE_ENT:
            return g_tapping_term + 40;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [NAVI] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
                                            {0,0,0}, {184,218,204},

            {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {0,0,0},       {0,0,0},
            {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {127,234,222},
            {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {127,234,222},
            {29,239,251}, {29,239,251}, {29,239,251}, {29,239,251}, {127,234,222}, {0,0,0},
            {0,0,0},      {0,0,0}
    },

    [FN] = {
        {0,0,0},  {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},  {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},  {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},  {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
                                             {0,0,0}, {184,218,204},

            {151,234,222}, {151,234,222}, {151,234,222}, {151,234,222}, {151,234,222}, {6,255,255},
            {44,255,255}, {83,193,218},  {83,193,218},  {83,193,218},  {83,193,218},  {0,0,0},
            {44,255,255}, {83,193,218},  {83,193,218},  {83,193,218},  {83,193,218},  {0,0,0},
            {44,255,255}, {83,193,218},  {83,193,218},  {83,193,218},  {83,193,218},  {0,0,0},
            {0,0,0},       {0,0,0}
    },

    [PREFIX_LBRC] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0},

            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}
    },

    [PREFIX_RBRC] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0},

            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}
    },

    /*
    [PREFIX_TMUX] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}
    },

    [NUM] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0},

            {184,218,204},{89,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {89,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {89,255,255}, {89,255,255},
            {89,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {89,255,255}, {89,255,255},
            {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {89,255,255}, {89,255,255},
            {0,0,0}, {0,0,0}
    },

    [SYM] = {
        {184,218,204}, {216,248,240}, {216,248,240}, {216,248,240}, {216,248,240}, {216,248,240},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0},

            {216,248,240}, {216,248,240}, {216,248,240}, {216,248,240}, {216,248,240}, {216,248,240},
            {46,255,255}, {46,255,255}, {19,255,255}, {19,255,255}, {89,255,255}, {216,248,240},
            {46,255,255}, {46,255,255}, {19,255,255}, {19,255,255}, {216,248,240}, {216,248,240},
            {46,255,255}, {46,255,255}, {216,248,240}, {216,248,240}, {216,248,240}, {0,0,0},
            {0,0,0}, {0,0,0}
    },
    */


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
  int layout = biton32(layer_state);
  switch (layout) {
   case 1 ... LAYER_MAX:
      set_layer_color(layout);
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
        case KC_A: case KC_S: case KC_D: case KC_F:
        case KC_C: case KC_V: case KC_X: case KC_Z:
        case KC_J: case KC_K: case KC_L: case KC_SCLN:
        case KC_M: case KC_COMM: case KC_DOT: case KC_SLSH:
            return 650;
    }
    // bypass achordion timeout
    return 0;
}

#ifdef ACHORDION_STREAK
uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {

  if (QK_LAYER_TAP_GET_LAYER(tap_hold_keycode) == NAVI) {
    return 150;  // shorter streak detection on NAVI layer-tap key.
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 150;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return 250;  // A longer timeout otherwise.
  }
}
#endif
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef ACHORDION_ENABLE
    if (!process_achordion(keycode, record)) return false;
#endif

  const uint8_t mods = get_mods();
  const uint8_t all_mods = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                        | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
  );
  const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;
  const bool alt = all_mods & MOD_BIT(KC_LALT);

  if (IS_LAYER_ON(PREFIX_LBRC) && record->event.pressed) {
      tap_code16(KC_LBRC);  // Tap [
  } else if (IS_LAYER_ON(PREFIX_RBRC) && record->event.pressed) {
      tap_code16(KC_RBRC);  // Tap ]
  /* } else if (IS_LAYER_ON(PREFIX_TMUX) && record->event.pressed) {
       tap_code16(G(KC_A));  // Tap ctrl+a */
  }

  switch (keycode) {
    case TMUXCPY:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_LBRC));
        }
        return false;

    case ARROW:
        if (record->event.pressed) {
#ifndef NO_ACTION_ONESHOT
            del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
            unregister_mods(MOD_MASK_SA);
            if (shift_mods)
                SEND_STRING(alt ? "<=>" : "=>");
            else
                SEND_STRING(alt ? "<->" : "->");
            set_mods(mods);
        }
        return false;

    case SELLINE:  // Selects the current line.
        if (record->event.pressed) {
            SEND_STRING_DELAY(
                    SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)), TAP_CODE_DELAY);
        }
        return false;

    case UPDIR:
        if (record->event.pressed) {
            SEND_STRING_DELAY("../", TAP_CODE_DELAY);
        }
        return false;

    /* when both shift are held => shift + del
       when one shift is held => del
     */
    case KC_BSPC: {
      static uint16_t registered_key = KC_NO;
      if (record->event.pressed) {  // On key press.
        if (shift_mods) {  // At least one shift key is held.
          registered_key = KC_DEL;
          // If one shift is held, clear it from the mods. But if both
          // shifts are held, leave as is to send Shift + Del.
          if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
            del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
            unregister_mods(MOD_MASK_SHIFT);
          }
        } else {
          registered_key = KC_BSPC;
        }

        register_code(registered_key);
        set_mods(mods);
      } else {  // On key release.
        unregister_code(registered_key);
      }
    } return false;


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
    // SHIFT+BSPC = DEL
    /* &ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL), */
    // SHIFT+ESC = ~
    &ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV)),
    // GUI+ESC = `
    &ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV),
    NULL
};
#endif

#ifdef LEADER_ENABLE
// https://docs.qmk.fm/features/leader_key
void leader_start_user(void) {
}

void leader_end_user(void) {
    static bool _right_bracket = true;

    if (leader_sequence_one_key(QK_LEAD)) {
        // Leader -> leader = toggle [] for vim usecase
        _right_bracket = !_right_bracket;
    } else if (leader_sequence_one_key(KC_T)) {
        // Leader -> t =
        if (_right_bracket)
            SEND_STRING(SS_TAP(X_RBRC) SS_DELAY(50) SS_TAP(X_T));
        else
            SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(50) SS_TAP(X_T));
    } else if (leader_sequence_one_key(KC_B)) {
        // Leader -> b = ]b, vim next buffer
        if (_right_bracket)
            SEND_STRING(SS_TAP(X_RBRC) SS_DELAY(50) SS_TAP(X_B));
        else
            SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(50) SS_TAP(X_B));
    } else if (leader_sequence_one_key(KC_Q)) {
        // Leader -> q = ]q, vim next quickfix
        if (_right_bracket)
            SEND_STRING(SS_TAP(X_RBRC) SS_DELAY(50) SS_TAP(X_Q));
        else
            SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(50) SS_TAP(X_Q));
    } else if (leader_sequence_one_key(KC_A)) {
        // Leader -> a = ]a, vim next function
        if (_right_bracket)
            SEND_STRING(SS_TAP(X_RBRC) SS_DELAY(50) SS_TAP(X_A));
        else
            SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(50) SS_TAP(X_A));
    } else if (leader_sequence_one_key(KC_C)) {
        // Leader -> c = ]c, vim next hunk
        if (_right_bracket)
            SEND_STRING(SS_TAP(X_RBRC) SS_DELAY(50) SS_TAP(X_C));
        else
            SEND_STRING(SS_TAP(X_LBRC) SS_DELAY(50) SS_TAP(X_C));
    }
}
#endif

///////////////////////////////////////////////////////////////////////////////
// Caps word (https://docs.qmk.fm/features/caps_word)
///////////////////////////////////////////////////////////////////////////////
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case KC_MINS:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
#endif  // CAPS_WORD_ENABLE
