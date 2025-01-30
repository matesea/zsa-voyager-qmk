#include QMK_KEYBOARD_H
#include "version.h"
#include "layout.h"
#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif
#ifdef CUSTOM_SHIFT_KEYS_ENABLE
#include "features/custom_shift_keys.h"
#endif  // CUSTOM_SHIFT_KEYS_ENABLE
#ifdef SELECT_WORD_ENABLE
#include "features/select_word.h"
#endif  // SELECT_WORD_ENABLE

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ARROW,    // -> => <-> <=>
  IME,      // switch ime
  MAC_TOG,  // toggle mac os
  SELLINE,  // select entire line
  SELWBAK,  // backward word selection
  SELWFWD,  // forward word selection

  KEYSTR_MIN,
  UPDIR = KEYSTR_MIN,    // input ../ per press
  USRNAME,  // input username

  /* vim navigation */
  LBRC_A,
  LBRC_B,
  LBRC_C,
  LBRC_D,
  LBRC_Q,
  LBRC_T,

  RBRC_A,
  RBRC_B,
  RBRC_C,
  RBRC_D,
  RBRC_Q,
  RBRC_T,

  /* tmux navigation */
  TMUX_A,    // C-a C-a, last window
  TMUX_C,    // C-a C-c, create
  TMUX_X,    // C-A x, kill
  TMUX_V,    // C-A v, vsplit
  TMUX_G,    // C-A g, split
  TMUX_P,    // C-A p, prev window
  TMUX_SLSH, // C-A /, search backward
  TMUX_SCLN, // C-A ;, last pane
  TMUX_QUES,  // C-A ?, search backward with tmux plugin tmux-fuzzback
  TMUX_W,    // C-A w, window preview
  TMUX_N,    // C-A n, next window
  TMUX_S,    // C-A s, show all sessions
  TMUX_F,    // C-A f, select pane with fzf
  TMUX_Z,    // C-A z, zoom in current pane

  TMUX_H,   // C-A h, select left pane
  TMUX_K,   // C-A k, select down pane
  TMUX_J,   // C-A j, select up pane
  TMUX_L,   // C-A l, select right pane

  TMUX_1,   // C-A 1, select window
  TMUX_2,   // C-A 2, select window
  TMUX_3,   // C-A 3, select window
  TMUX_4,   // C-A 4, select window
  TMUX_5,   // C-A 5, select window
  TMUX_6,   // C-A 6, select window
  TMUX_7,   // C-A 7, select window
  TMUX_8,   // C-A 8, select window
  TMUX_9,   // C-A 9, select window
  TMUX_0,   // C-A 0, select window

  TMUX_SPC, // C-A space, next layout
  TMUX_BSPC, // C-A backspace, previous layout

  TMUX_ML,   // C-A M-left, resize
  TMUX_MD,   // C-A M-down, resize
  TMUX_MU,   // C-A M-up, resize
  TMUX_MR,   // C-A M-right, resize

  TMUX_LBRC, // C-A [, enter copy mode
  TMUX_RBRC, // C-A ], paste
  TMUX_LCBR,   // C-A {, swap pane
  TMUX_RCBR,   // C-A }, swap pane

  KEYSTR_MAX = TMUX_RCBR,
};

struct keystring_t {
    const char *str;
    uint8_t delay;
};

enum {
    BASE = 0,
    NAVI,
    SYM,
    // SYM1, // getreuer's symbol layer
    // NUM,
    FN,
    TMUX,
    BACKWARD,
    FORWARD,
    LAYER_MAX = FORWARD,
};

#define BS_A      LGUI_T(KC_A)
#define BS_S      LALT_T(KC_S)
#define BS_D      LCTL_T(KC_D)
#define BS_F      LSFT_T(KC_F)

#define BS_Z      LT(SYM, KC_Z)
#define BS_X      KC_X
#define BS_C      KC_C
#define BS_V      KC_V

#define BS_J      RSFT_T(KC_J)
#define BS_K      RCTL_T(KC_K)
#define BS_L      LALT_T(KC_L)
#define BS_SCLN   RGUI_T(KC_SCLN)

#define BS_M      KC_M
#define BS_COMM   LT(BACKWARD, KC_COMM)
#define BS_DOT    LT(FORWARD, KC_DOT)
#define BS_SLSH   KC_SLSH

#define BS_ENT    LT(NAVI, KC_ENT)
#define BS_SPC    KC_SPC
// #define BS_REP    LT(SYM, KC_0)
#define BS_ESC    LT(TMUX, KC_ESC)
#define BS_QUOT   LT(TMUX, KC_QUOT)

#define CLOSAPP     A(KC_F4)

static bool isMacOS = false;

#if defined(SELECT_WORD_ENABLE) && defined(SELECT_WORD_OS_DYNAMIC)
bool select_word_host_is_mac(void) {
    return isMacOS;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR(
            KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
            KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
            BS_ESC,  BS_A,   BS_S,   BS_D,   BS_F,   KC_G,
            KC_UNDS, BS_Z,   BS_X,   BS_C,   BS_V,   KC_B,
                                             BS_ENT, QK_REP,

                      KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,
                      KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_EQL,
                      KC_H,   BS_J,   BS_K,    BS_L,   BS_SCLN, BS_QUOT,
                      KC_N,   BS_M,   BS_COMM, BS_DOT, BS_SLSH, KC_BSLS,
                      KC_BSPC, BS_SPC
            ),

    [NAVI] = LAYOUT_LR(
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, C(KC_A), XXXXXXX, XXXXXXX, C(KC_R), C(KC_T),
            _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B),
                                                _______, _______,

                     CLOSAPP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY,
                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  XXXXXXX,
                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_VOLU,
                     SELLINE, SELWBAK, SELWFWD, XXXXXXX, KC_APP,  KC_VOLD,
                     _______, QK_LLCK
            ),

    [SYM] = LAYOUT_LR(  // my simplied symbol layer.
              _______, _______, _______, _______, _______, _______,
              _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
              _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
              _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                  _______, _______,

                       _______, _______, _______, _______, _______, _______,
                       XXXXXXX, KC_LCBR, KC_RCBR, ARROW,   XXXXXXX, _______,
                       XXXXXXX, KC_LPRN, KC_RPRN, USRNAME, XXXXXXX, _______,
                       XXXXXXX, KC_LBRC, KC_RBRC, UPDIR,   XXXXXXX, _______,
                       _______, _______
            ),

    /* getreuer's symbol layer
       ` < > - |
       ! * / = &
       ~ + [ ] %
             X _

                ^ { } $ X
                # ( ) ; "
                @ : , . '
                _ X
                */
    /*
    [SYM1] = LAYOUT_LR(  // getreuer's symbol layer.
              _______, _______, _______, _______, _______, _______,
              _______, KC_GRV,  KC_LABK, KC_RABK, KC_MINS, KC_PIPE,
              _______, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,
              _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,
                                                  USRNAME, _______,

                       _______, _______,  _______, _______, _______, _______,
                       KC_CIRC, KC_LCBR,  KC_RCBR, KC_DLR,  ARROW,   _______,
                       KC_HASH, KC_LPRN,  KC_RPRN, KC_SCLN, KC_DQUO, _______,
                       KC_AT,   KC_COLN , KC_COMM, KC_DOT,  KC_QUOT, _______,
                       _______, UPDIR
            ),
    */

    /*
    [NUM] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, _______,

                     _______, _______, _______, _______, _______, _______,
                     KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_SLSH,
                     KC_COLN, KC_4,    KC_5,    KC_6,    KC_MINS, KC_ASTR,
                     KC_COMM, KC_1,    KC_2,    KC_3,    KC_DOT,  KC_BSPC,
                     KC_0, QK_LLCK
            ),
    */

    [FN] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, _______,

                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                     KC_BRK,  KC_F7,   KC_F8,   KC_F9,   KC_F12,  UG_TOGG,
                     KC_PSCR, KC_F4,   KC_F5,   KC_F6,   KC_F11,  MAC_TOG,
                     KC_SCRL, KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX,
                     _______, QK_LLCK
            ),

    [TMUX] = LAYOUT_LR(
            XXXXXXX,   TMUX_1,  TMUX_2,  TMUX_3,  TMUX_4,  TMUX_5,
            XXXXXXX,   XXXXXXX, TMUX_W,  XXXXXXX, XXXXXXX, XXXXXXX,
            TMUX_LBRC, TMUX_A,  TMUX_S,  XXXXXXX, TMUX_F,  TMUX_G,
            XXXXXXX,   TMUX_Z,  TMUX_X,  TMUX_C,  TMUX_V,  XXXXXXX,
                                                  XXXXXXX, XXXXXXX,

                       TMUX_6,    TMUX_7,    TMUX_8,    TMUX_9,    TMUX_0,    XXXXXXX,
                       TMUX_ML,   TMUX_MD,   TMUX_MU,   TMUX_MR,   TMUX_RBRC, XXXXXXX,
                       TMUX_H,    TMUX_J,    TMUX_K,    TMUX_L,    TMUX_SCLN, XXXXXXX,
                       TMUX_LCBR, TMUX_LBRC, TMUX_RBRC, TMUX_RCBR, TMUX_SLSH, TMUX_QUES,
                       TMUX_BSPC, TMUX_SPC
            ),

    [BACKWARD] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, LBRC_Q,  XXXXXXX, XXXXXXX, XXXXXXX, LBRC_T,
            _______, LBRC_A,  XXXXXXX, LBRC_D,  XXXXXXX, XXXXXXX,
            _______, XXXXXXX, TMUX_P,  LBRC_C,  XXXXXXX, LBRC_B,
                                                _______, _______,

                     _______, _______, _______, _______, _______, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     _______, _______
            ),

    [FORWARD] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, RBRC_Q,  XXXXXXX, XXXXXXX, XXXXXXX, RBRC_T,
            _______, RBRC_A,  XXXXXXX, RBRC_D,  XXXXXXX, XXXXXXX,
            _______, XXXXXXX, TMUX_N,  RBRC_C,  XXXXXXX, RBRC_B,
                                                _______, _______,

                     _______, _______, _______, _______, _______, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     _______, _______
            ),
};

#if defined(COMBO_ENABLE)
const uint16_t PROGMEM cv[] = {BS_C, BS_V, COMBO_END};
const uint16_t PROGMEM xc[] = {BS_C, BS_X, COMBO_END};

const uint16_t PROGMEM mc[] = {BS_M, BS_COMM, COMBO_END};
const uint16_t PROGMEM cd[] = {BS_COMM, BS_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(cv, IME),
    COMBO(xc, OSL(FN)),

    COMBO(mc, CW_TOGG),
    COMBO(cd, QK_AREP),
};
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BS_F:
        case BS_J:
            return TAPPING_TERM;
        // longer tapping term for ALT
        case BS_S:
        case BS_L:
            return TAPPING_TERM + 50;
    }
    return TAPPING_TERM + 30;
}

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case BS_J:
    case BS_K:
    case BS_L:
    case BS_ENT:
    // case BS_SPC:
    // case BS_REP:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // disable permissive hold for ALT
    if (IS_QK_MODS(keycode)) {
        uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(keycode));
        if (mod & MOD_LALT)
            return false;
    }
    return true;
}
#endif

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
  rgb_matrix_enable_noeeprom();
}
#endif

#ifdef CHORDAL_HOLD
// Handedness for Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
  LAYOUT_LR(
  '*'    , '*'    , '*'    , '*'    , '*'    , '*'    ,
  '*'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
  '*'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
  '*'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
                                               '*'    , '*'    ,

                    '*'    , '*'    , '*'    , '*'    , '*'    , '*'    ,
                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , '*'    ,
                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , '*'    ,
                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , '*'    ,
           '*'    , '*'
);
// Callback for Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
bool get_chordal_hold(
        uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
        uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
      // same hand exceptions for GUI shortcut
      case BS_A:
          switch (other_keycode) {
              case BS_C:
              case BS_V:
              case KC_W:
              case KC_T:
                  if (isMacOS) return true;
                  break;
              case KC_R: // for win+r run on windows
                  if (!isMacOS) return true;
                  break;
          }
          break;
  }
  return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif  // CHORDAL_HOLD

void housekeeping_task_user(void) {
#ifdef ACHORDION_ENABLE
    achordion_task();
#endif
#ifdef SELECT_WORD_ENABLE
    select_word_task();
#endif
}

#ifdef ACHORDION_ENABLE
// https://getreuer.info/posts/keyboards/achordion/index.html

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    uint8_t hold_row = tap_hold_record->event.key.row % (MATRIX_ROWS / 2);
    uint8_t other_row = other_record->event.key.row % (MATRIX_ROWS / 2);

    // allow same-hand shortcut when tap/hold in thumb
    if (other_row > 4 || hold_row > 4)
        return true;

    switch (tap_hold_keycode) {
        // same hand exceptions for GUI shortcut
        case BS_A:
            switch (other_keycode) {
                case BS_C:
                case BS_V:
                case KC_W:
                case KC_T:
                    if (isMacOS) return true;
                    break;
                case KC_R: // for win+r run on windows
                    if (!isMacOS) return true;
                    break;
            }
            break;
    }

    // allow hold key at first column and last column
    /*
    if ((tap_hold_record->event.key.row <= 3 && tap_hold_record->event.key.col == 1) ||
            (6 <= tap_hold_record->event.key.row && tap_hold_record->event.key.row <= 9 &&
            tap_hold_record->event.key.col == 5))
        return true;
    */

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    if (IS_QK_MODS(tap_hold_keycode)) {
        const uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
        if (mod & MOD_MASK_CS)
            return 300;
    }
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        const uint16_t layer = QK_LAYER_TAP_GET_LAYER(tap_hold_keycode);
        switch (layer) {
            case NAVI:
            case SYM:
                return 300;
        }
    }
    return 500;
}

#ifdef ACHORDION_STREAK
uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {

    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        const uint16_t layer = QK_LAYER_TAP_GET_LAYER(tap_hold_keycode);
        switch (layer) {
            case NAVI:
            case SYM:
                return 150;
        }
    }

    // shortcut not blocked by streak detection
    switch (tap_hold_keycode) {
        case BS_A:
            // for cut/copy/paste/new tab on MAC OS
            switch (next_keycode) {
                case BS_C:
                case BS_V:
                case KC_W:
                case KC_T:
                    if (isMacOS) return 0;
                    break;
                case KC_R: // for win+r run on windows
                    if (!isMacOS) return 0;
                    break;
            }
            break;
    }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
    if (mod & MOD_MASK_CS)
    return 150;  // A shorter streak timeout for Shift or Ctrl mod-tap keys.
  return 240;  // A longer timeout otherwise.
}
#endif
#endif

#if defined(REPEAT_KEY_ENABLE)
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    /*
    if (keycode == BS_REP)
        return false;
    */
  // Unpack tapping keycode for tap-hold keys.
  switch (keycode) {
#ifndef NO_ACTION_TAPPING
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
      break;
#ifndef NO_ACTION_LAYER
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
      break;
#endif  // NO_ACTION_LAYER
#endif  // NO_ACTION_TAPPING
  }

  // Forget Shift on most letters when Shift or AltGr are the only mods. Some
  // letters are excluded, e.g. for "NN" and "ZZ" in Vim.
  // NN, SS, ZZ are excluded
  switch (keycode) {
    case KC_A ... KC_M:
    case KC_O ... KC_R:
    case KC_T ... KC_Y:
      if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
        *remembered_mods &= ~MOD_MASK_SHIFT;
      }
      break;
  }

  return true;
}

#ifndef NO_ALT_REPEAT_KEY
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if (mods == MOD_BIT_RCTRL || mods == MOD_BIT_LCTRL) {
        switch (keycode) {
          case KC_TAB: return C(S(KC_TAB));
        }
    } else if (mods == MOD_BIT_LGUI || mods == MOD_BIT_RGUI) {
        switch (keycode) {
          case KC_TAB: return G(S(KC_TAB));
        }
    } else if (mods == MOD_BIT_LALT) {
        switch (keycode) {
          case KC_TAB: return A(S(KC_TAB));
        }
    } else if ((mods & ~MOD_MASK_SHIFT) == 0) {
        switch (keycode) {
            case KC_N:
                if ((mods & MOD_MASK_SHIFT) == 0)
                    return S(KC_N);
                return KC_N;

            /* reverse vim navigation */
            case LBRC_A: return RBRC_A;
            case LBRC_B: return RBRC_B;
            case LBRC_C: return RBRC_C;
            case LBRC_D: return RBRC_D;
            case LBRC_Q: return RBRC_Q;
            case LBRC_T: return RBRC_T;

            case RBRC_A: return LBRC_A;
            case RBRC_B: return LBRC_B;
            case RBRC_C: return LBRC_C;
            case RBRC_D: return LBRC_D;
            case RBRC_Q: return LBRC_Q;
            case RBRC_T: return LBRC_T;

            /* select pane */
            case TMUX_J: return TMUX_K;
            case TMUX_K: return TMUX_J;
            case TMUX_H: return TMUX_L;
            case TMUX_L: return TMUX_H;

            /* reverse tmux resize */
            case TMUX_ML: return TMUX_MR;
            case TMUX_MR: return TMUX_ML;
            case TMUX_MU: return TMUX_MD;
            case TMUX_MD: return TMUX_MU;

            /* swap pane */
            case TMUX_LCBR: return TMUX_RCBR;
            case TMUX_RCBR: return TMUX_LCBR;

            /* tmux previous/next window */
            case TMUX_N: return TMUX_P;
            case TMUX_P: return TMUX_N;

            /* previous/next layout */
            case TMUX_SPC: return TMUX_BSPC;
            case TMUX_BSPC: return TMUX_SPC;

            case SELWBAK: return SELWFWD;
            case SELWFWD: return SELWBAK;
        }
    }
    return KC_TRNS;
}
#endif
#endif


#define PREFIX_DELAY 50
static const struct keystring_t keystrings[] = {
    [UPDIR - KEYSTR_MIN]    = {"../", TAP_CODE_DELAY},
    [USRNAME - KEYSTR_MIN]  = {"wenlongy", TAP_CODE_DELAY},
    [LBRC_A - KEYSTR_MIN]   = {"[a", TAP_CODE_DELAY},
    [LBRC_B - KEYSTR_MIN]   = {"[b", TAP_CODE_DELAY},
    [LBRC_C - KEYSTR_MIN]   = {"[c", TAP_CODE_DELAY},
    [LBRC_D - KEYSTR_MIN]   = {"[d", TAP_CODE_DELAY},
    [LBRC_Q - KEYSTR_MIN]   = {"[q", TAP_CODE_DELAY},
    [LBRC_T - KEYSTR_MIN]   = {"[t", TAP_CODE_DELAY},

    [RBRC_A - KEYSTR_MIN]   = {"]a", TAP_CODE_DELAY},
    [RBRC_B - KEYSTR_MIN]   = {"]b", TAP_CODE_DELAY},
    [RBRC_C - KEYSTR_MIN]   = {"]c", TAP_CODE_DELAY},
    [RBRC_D - KEYSTR_MIN]   = {"]d", TAP_CODE_DELAY},
    [RBRC_Q - KEYSTR_MIN]   = {"]q", TAP_CODE_DELAY},
    [RBRC_T - KEYSTR_MIN]   = {"]t", TAP_CODE_DELAY},

    [TMUX_A - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LCTL(SS_TAP(X_A)), TAP_CODE_DELAY},
    [TMUX_C - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LCTL(SS_TAP(X_C)), TAP_CODE_DELAY},
    [TMUX_X - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_X), TAP_CODE_DELAY},
    [TMUX_V - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_V), TAP_CODE_DELAY},
    [TMUX_G - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_G), TAP_CODE_DELAY},
    [TMUX_P - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_P), TAP_CODE_DELAY},
    [TMUX_SCLN - KEYSTR_MIN] = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_SCLN), TAP_CODE_DELAY},
    [TMUX_SLSH - KEYSTR_MIN] = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_SLSH), TAP_CODE_DELAY},
    [TMUX_QUES - KEYSTR_MIN] = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LSFT(SS_TAP(X_SLSH)), TAP_CODE_DELAY},
    [TMUX_W - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_W), TAP_CODE_DELAY},
    [TMUX_N - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_N), TAP_CODE_DELAY},
    [TMUX_S - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_S), TAP_CODE_DELAY},
    [TMUX_F - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_F), TAP_CODE_DELAY},
    [TMUX_Z - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_Z), TAP_CODE_DELAY},
    [TMUX_LBRC - KEYSTR_MIN] = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_LBRC), TAP_CODE_DELAY},
    [TMUX_RBRC - KEYSTR_MIN] = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_RBRC), TAP_CODE_DELAY},

    [TMUX_H - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_H), TAP_CODE_DELAY},
    [TMUX_K - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_K), TAP_CODE_DELAY},
    [TMUX_J - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_J), TAP_CODE_DELAY},
    [TMUX_L - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_L), TAP_CODE_DELAY},

    [TMUX_LCBR - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LSFT(SS_TAP(X_LBRC)), TAP_CODE_DELAY},
    [TMUX_RCBR - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LSFT(SS_TAP(X_RBRC)), TAP_CODE_DELAY},

    [TMUX_SPC - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_SPC), TAP_CODE_DELAY},
    [TMUX_BSPC - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_BSPC), TAP_CODE_DELAY},

    [TMUX_1 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_1), TAP_CODE_DELAY},
    [TMUX_2 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_2), TAP_CODE_DELAY},
    [TMUX_3 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_3), TAP_CODE_DELAY},
    [TMUX_4 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_4), TAP_CODE_DELAY},
    [TMUX_5 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_5), TAP_CODE_DELAY},
    [TMUX_6 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_6), TAP_CODE_DELAY},
    [TMUX_7 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_7), TAP_CODE_DELAY},
    [TMUX_8 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_8), TAP_CODE_DELAY},
    [TMUX_9 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_9), TAP_CODE_DELAY},
    [TMUX_0 - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_0), TAP_CODE_DELAY},

    [TMUX_ML - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LALT(SS_TAP(X_LEFT)), TAP_CODE_DELAY},
    [TMUX_MD - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LALT(SS_TAP(X_DOWN)), TAP_CODE_DELAY},
    [TMUX_MU - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LALT(SS_TAP(X_UP)), TAP_CODE_DELAY},
    [TMUX_MR - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LALT(SS_TAP(X_RIGHT)), TAP_CODE_DELAY},
};

#if 0
// process keycode with shift when tapped
bool process_shifted_tap(uint16_t keycode, keyrecord_t *record, bool *registered) {
    if (record->tap.count) {
        switch (keycode) {
#ifndef NO_ACTION_TAPPING
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
              keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
              break;
#ifndef NO_ACTION_LAYER
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
              keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
              break;
#endif  // NO_ACTION_LAYER
#endif  // NO_ACTION_TAPPING
        }
        keycode = S(keycode);

        if (record->event.pressed) {
            process_caps_word(keycode, record);
            if (*registered)
                unregister_code16(keycode);
            register_code16(keycode);
            *registered = true;
        } else {
            unregister_code16(keycode);
            *registered = false;
        }
        return false;
    }
    return true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef ACHORDION_ENABLE
    if (!process_achordion(keycode, record)) return false;
#endif
#ifdef SELECT_WORD_ENABLE
  if (!process_select_word(keycode, record)) { return false; }
#endif  // SELECT_WORD_ENABLE
#ifdef CUSTOM_SHIFT_KEYS_ENABLE
  if (!process_custom_shift_keys(keycode, record)) { return false; }
#endif  // CUSTOM_SHIFT_KEYS_ENABLE

  const uint8_t mods = get_mods();
  const uint8_t all_mods = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                        | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
  );
  const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;
  const bool alt = all_mods & MOD_BIT(KC_LALT);
  const uint8_t layer = read_source_layers_cache(record->event.key);

  // WA to address unintended shift
  // source: reddit r/zsaVoyager: Weird firmware issue with [ turning into {
  if (record->event.pressed) {
      switch (layer) {
          case SYM:
          // case SYM1:
              clear_weak_mods();
              send_keyboard_report();
              break;
      }
  }

  switch (keycode) {
    case SELWBAK:  // Backward word selection.
      if (record->event.pressed) {
        select_word_register('B');
      } else {
        select_word_unregister();
      }
      break;

    case SELWFWD:  // Forward word selection.
      if (record->event.pressed) {
        select_word_register('W');
      } else {
        select_word_unregister();
      }
      break;

    case SELLINE:  // Line selection.
      if(record->event.pressed) {
        select_word_register('L');
      } else {
        select_word_unregister();
      }
      break;
      /*
      case BS_REP:
          if (record->tap.count) {
              repeat_key_invoke(&record->event);
              return false;
          }
          break;
       */
    /*
    case BS_UNDS: {
        static bool registered = false;
        return process_shifted_tap(keycode, record, &registered);
    }
    */

    /*
    case BS_CW:
      if (record->tap.count && record->event.pressed) {
          caps_word_toggle();
          return false;
      }
      return true;
    */

    /* when both shift are held => shift + del
       when one shift is held => del
     */
    case KC_BSPC:
      {
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
  }

  if (record->event.pressed) {
    switch (keycode) {
        case MAC_TOG:
            isMacOS = !isMacOS;
            return false;

#ifdef RGB_MATRIX_ENABLE
        case RGB_SLD:
            rgblight_mode(1);
            return false;
#endif
        case ARROW:
#ifndef NO_ACTION_ONESHOT
            del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
            unregister_mods(MOD_MASK_SA);
            if (shift_mods)
                SEND_STRING_DELAY(alt ? "<=>" : "=>", TAP_CODE_DELAY);
            else
                SEND_STRING_DELAY(alt ? "<->" : "->", TAP_CODE_DELAY);
            set_mods(mods);
            return false;

        /* switch IME based on layer */
        case IME:
            clear_mods();
            tap_code16(isMacOS ? C(KC_SPC) : G(KC_SPC));
            set_mods(mods);
            return false;

        case KEYSTR_MIN ... KEYSTR_MAX:
          const struct keystring_t *p = &keystrings[keycode - KEYSTR_MIN];
          clear_mods();
          SEND_STRING_DELAY(p->str, p->delay);
          set_mods(mods);
          return false;
    }
  }
  return true;
}

#ifdef CUSTOM_SHIFT_KEYS_ENABLE
const custom_shift_key_t custom_shift_keys[] = {
    {KC_ESC, KC_TILD},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
#endif  // CUSTOM_SHIFT_KEYS_ENABLE

///////////////////////////////////////////////////////////////////////////////
// Caps word (https://docs.qmk.fm/features/caps_word)
///////////////////////////////////////////////////////////////////////////////
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
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

#ifdef RGB_MATRIX_CUSTOM_KB
extern rgb_config_t rgb_matrix_config;

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [NAVI] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
                                            {0,0,0}, {0,0,0},

            {184,218,204},{29,239,251}, {0,0,0},      {0,0,0},      {0,0,0},       {19,255,255},
            {29,239,251}, {29,239,251}, {29,239,251}, {0,0,0},      {127,234,222}, {0,0,0},
            {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {19,255,255},
            {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {19,255,255},
            {0,0,0},      {184,218,204}
    },

    [SYM] = {
        {0,0,0}, {0,0,0}, {0,0,0},      {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0}, {0,0,0}, {29,239.251}, {127,234,222}, {127,234,222}, {0,0,0},
        {0,0,0}, {0,0,0}, {29,239.251}, {127,234,222}, {127,234,222}, {0,0,0},
        {0,0,0}, {0,0,0}, {29,239.251}, {127,234,222}, {127,234,222}, {0,0,0},
                                                       {0,0,0}, {0,0,0},

            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}
    },

    /*
    [SYM1] = {
        {0,0,0}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0}, {44,255,255},  {184,218,204}, {184,218,204}, {83,193,218},  {83,193,218},
        {0,0,0}, {184,218,204}, {83,193,218},  {83,193,218},  {184,218,204}, {83,193,218},
        {0,0,0}, {83,193,218},  {83,193,218},  {127,234,222}, {127,234,222}, {44,255,255},
                                                              {19,255,255}, {0,0,0},

            {0,0,0},      {0,0,0},      {0,0,0},       {0,0,0},       {0,0,0},      {0,0,0},
            {44,255,255}, {127,234,222}, {127,234,222}, {44,255,255}, {6,255,255},  {0,0,0},
            {44,255,255}, {127,234,222}, {127,234,222}, {44,255,255}, {44,255,255}, {0,0,0},
            {44,255,255}, {44,255,255},  {44,255,255},  {44,255,255}, {44,255,255}, {0,0,0},
            {0,0,0},      {19,255,255}
    },
    */

    /*
    [NUM] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
                                            {0,0,0}, {0,0,0},

            {0,0,0},      {0,0,0},      {0,0,0},      {0,0,0},      {0,0,0},      {0,0,0},
            {89,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {89,255,255}, {89,255,255},
            {89,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {89,255,255}, {89,255,255},
            {89,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {89,255,255}, {184,218,204},
            {19,255,255}, {184,218,204},
    },
    */

    [FN] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
                                            {0,0,0}, {0,0,0},

            {0,0,0},       {0,0,0},      {0,0,0},       {0,0,0},      {0,0,0},      {6,255,255},
            {127,234,222}, {83,193,218}, {83,193,218},  {83,193,218}, {83,193,218}, {44,255,255},
            {127,234,222}, {83,193,218}, {83,193,218},  {83,193,218}, {83,193,218}, {184,218,204},
            {127,234,222}, {83,193,218}, {83,193,218},  {83,193,218}, {83,193,218}, {0,0,0},
            {0,0,0},       {184,218,204}
    },

    [TMUX] = {
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

    [BACKWARD] = {
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

    [FORWARD] = {
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
#endif
