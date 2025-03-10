#include QMK_KEYBOARD_H
#include "version.h"
#include "layout.h"

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  ARROW = ML_SAFE_RANGE,    // -> => <-> <=>
  IME,      // switch ime
  CLOSAPP,  // close app
  MAC_TOG,  // toggle mac os

  SELALL,
  UNDO,
  CUT,
  COPY,
  PASTE,
  BOLD,
  FIND,
  NEWTAB,
  CLOSTAB,

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
    SYM,
    NAV,
    // SYM1, // getreuer's symbol layer
    // NUM,
    FN,
    TMUX,
    BAK,
    FWD,
    LAYER_MAX = FWD,
};

#define BS_A      LGUI_T(KC_A)
#define BS_S      LALT_T(KC_S)
#define BS_D      LCTL_T(KC_D)
#define BS_F      LSFT_T(KC_F)

#define BS_Z      LT(TMUX, KC_Z)
#define BS_X      KC_X
#define BS_C      KC_C
#define BS_V      LT(SYM, KC_V)

#define BS_J      RSFT_T(KC_J)
#define BS_K      RCTL_T(KC_K)
#define BS_L      LALT_T(KC_L)
#define BS_SCLN   RGUI_T(KC_SCLN)

#define BS_M      KC_M
#define BS_COMM   LT(BAK, KC_COMM)
#define BS_DOT    LT(FWD, KC_DOT)
#define BS_SLSH   LT(TMUX, KC_SLSH)

#define BS_ENT    LT(NAV, KC_ENT)
#define BS_SPC    KC_SPC
#define BS_BSPC   KC_BSPC

#define BS_REP    QK_REP

#define BS_TAB    KC_TAB
#define BS_QUOT   KC_QUOT

#define BS_CW     CW_TOGG
#define BS_BSLS   KC_BSLS
#define BS_UNDS   KC_UNDS

#define OSM_SFT   OSM(MOD_LSFT)
#define OSM_CTL   OSM(MOD_LCTL)
#define OSM_ALT   OSM(MOD_LALT)
#define OSM_GUI   OSM(MOD_LGUI)

static bool isMacOS = false;
#if defined(COMMUNITY_MODULE_SELECT_WORD_ENABLE) && defined(SELECT_WORD_OS_DYNAMIC)
bool select_word_host_is_mac(void) {
    return isMacOS;
}
#endif
#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_user(os_variant_t os) {
    isMacOS = (os == OS_MACOS || os == OS_IOS);
    return true;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR(
            KC_ESC,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
            KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
            BS_UNDS, BS_A,   BS_S,   BS_D,   BS_F,   KC_G,
            BS_CW,   BS_Z,   BS_X,   BS_C,   BS_V,   KC_B,
                                             BS_ENT, BS_REP,

                      KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,
                      KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_EQL,
                      KC_H,   BS_J,   BS_K,    BS_L,   BS_SCLN, BS_QUOT,
                      KC_N,   BS_M,   BS_COMM, BS_DOT, BS_SLSH, BS_BSLS,
                      BS_BSPC, BS_SPC
            ),

    [NAV] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, XXXXXXX, CLOSTAB, G(KC_E), G(KC_R), NEWTAB,
            _______, OSM_GUI, OSM_ALT, OSM_CTL, OSM_SFT, FIND,
            _______, UNDO,    CUT,     COPY,    PASTE,   BOLD,
                                                _______, _______,

                     CLOSAPP, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_MPLY,
                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_BRK,
                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_PSCR,
                     SELLINE, SELWBAK, SELWORD, SELALL,  KC_APP,  KC_SCRL,
                     _______, _______
            ),

    /* my simplied right-handed symbol layer

       ^$ vim navigation, jump to start/end of the current line
       *# vim navigation, search behind/ahead for word under cursor
       :% enter vim command mode, % for whole buffer
       @: repeat last command in vim command mode

                X X
                * { } # X `
                ^ ( ) $ ;
                : [ ] % @ ~
                */
    [SYM] = LAYOUT_LR(
              _______, _______, _______, _______, _______, _______,
              _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
              _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
              _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                  _______, _______,

                       USRNAME, UPDIR,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       KC_ASTR, KC_LCBR, KC_RCBR, KC_HASH, ARROW,   KC_GRV,
                       KC_CIRC, KC_LPRN, KC_RPRN, KC_DLR,  KC_SCLN, XXXXXXX,
                       KC_COLN, KC_LBRC, KC_RBRC, KC_PERC, KC_AT,   KC_TILD,
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
    [SYM] = LAYOUT_LR(  // getreuer's symbol layer.
              _______, _______, _______, _______, _______, _______,
              XXXXXXX, KC_GRV,  KC_LABK, KC_RABK, KC_MINS, KC_PIPE,
              XXXXXXX, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,
              XXXXXXX, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,
                                                  _______, _______,

                       _______, _______,  _______, _______, _______, _______,
                       KC_CIRC, KC_LCBR,  KC_RCBR, KC_DLR,  ARROW,   XXXXXXX,
                       KC_HASH, KC_LPRN,  KC_RPRN, KC_SCLN, KC_DQUO, USRNAME,
                       KC_AT,   KC_COLN , KC_COMM, KC_DOT,  KC_QUOT, UPDIR,
                       _______, _______
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
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
            _______, KC_F12,  KC_F9,   KC_F8,   KC_F7,   UG_TOGG,
            _______, KC_F11,  KC_F6,   KC_F5,   KC_F4,   MAC_TOG,
            _______, KC_F10,  KC_F3,   KC_F2,   KC_F1,   XXXXXXX,
                                                _______, _______,

                     _______, _______, _______, _______, _______, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     _______, _______
            ),

    [TMUX] = LAYOUT_LR(
            TMUX_LBRC, TMUX_1,  TMUX_2,  TMUX_3,  TMUX_4,  TMUX_5,
            XXXXXXX,   XXXXXXX, TMUX_W,  XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX,   TMUX_A,  TMUX_S,  XXXXXXX, TMUX_F,  TMUX_G,
            XXXXXXX,   TMUX_Z,  TMUX_X,  TMUX_C,  TMUX_V,  XXXXXXX,
                                                  XXXXXXX, XXXXXXX,

                       TMUX_6,    TMUX_7,    TMUX_8,    TMUX_9,    TMUX_0,    XXXXXXX,
                       TMUX_ML,   TMUX_MD,   TMUX_MU,   TMUX_MR,   TMUX_RBRC, XXXXXXX,
                       TMUX_H,    TMUX_J,    TMUX_K,    TMUX_L,    TMUX_SCLN, XXXXXXX,
                       TMUX_LCBR, TMUX_LBRC, TMUX_RBRC, TMUX_RCBR, TMUX_SLSH, TMUX_QUES,
                       TMUX_BSPC, TMUX_SPC
            ),

    [BAK] = LAYOUT_LR(
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

    [FWD] = LAYOUT_LR(
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
const uint16_t PROGMEM mc[] = {BS_M, BS_COMM, COMBO_END};
const uint16_t PROGMEM hj[] = {KC_H, BS_J, COMBO_END};

combo_t key_combos[] = {
    COMBO(cv, IME),
    COMBO(mc, QK_AREP),
    COMBO(hj, OSL(FN)),

};
#endif

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BS_F:
        case BS_J:
            return TAPPING_TERM;
    }
    return TAPPING_TERM + 170;
}
#endif

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
    // case BS_DOT:
    // case BS_REP:
    case BS_BSPC:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
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
  'L'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
  'L'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
  'L'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
  'L'    , 'L'    , 'L'    , 'L'    , 'L'    , 'L'    ,
                                               '*'    , '*'    ,

                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , 'R'    ,
                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , 'R'    ,
                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , 'R'    ,
                    'R'    , 'R'    , 'R'    , 'R'    , 'R'    , 'R'    ,
           '*'    , '*'
);
// Callback for Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
bool get_chordal_hold(
        uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
        uint16_t other_keycode, keyrecord_t* other_record) {
    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif  // CHORDAL_HOLD

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

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
  if (record->event.pressed) {
      switch (layer) {
          case SYM:
              clear_weak_mods();
              send_keyboard_report();
              break;
      }
  }

  switch (keycode) {
    /* switch IME */
    case IME: {
        static int8_t hold_mod;
        hold_mod = (isMacOS ? MOD_BIT_LCTRL : MOD_BIT_LGUI);
        if (record->event.pressed) {
            register_mods(hold_mod);
            tap_code16(KC_SPC);
        } else
            unregister_mods(hold_mod);
        return false;
    }

    /* close app */
    case CLOSAPP:
        {
            if (record->event.pressed) {
                register_mods(isMacOS ? MOD_BIT_LGUI : MOD_BIT_LALT);
                tap_code16(isMacOS ? KC_Q : KC_F4);
            } else
                unregister_mods(isMacOS ? MOD_BIT_LGUI : MOD_BIT_LALT);
            return false;
        }

    case SELWBAK:  // Backward word selection.
      if (record->event.pressed) {
        select_word_register('B');
      } else {
        select_word_unregister();
      }
      break;

    case SELWORD:  // Forward word selection.
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
    case BS_UNDS: {
        static bool registered = false;
        return process_shifted_tap(keycode, record, &registered);
    }
    case BS_REP:
      if (record->tap.count) {
          repeat_key_invoke(&record->event);
          return false;
      }
      break;
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
    /*
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
    */
  }

  if (record->event.pressed) {
    switch (keycode) {
        case MAC_TOG:
            isMacOS = !isMacOS;
            return false;

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

        case UNDO:
            clear_mods();
            SEND_STRING_DELAY(isMacOS ? SS_LGUI(SS_TAP(X_Z)) : SS_LCTL(SS_TAP(X_Z)) , TAP_CODE_DELAY);
            set_mods(mods);
            return false;

        case SELALL:
            clear_mods();
            SEND_STRING_DELAY(isMacOS ? SS_LGUI(SS_TAP(X_A)) : SS_LCTL(SS_TAP(X_A)) , TAP_CODE_DELAY);
            set_mods(mods);
            return false;

        case CUT:
            clear_mods();
            SEND_STRING_DELAY(isMacOS ? SS_LGUI(SS_TAP(X_X)) : SS_LCTL(SS_TAP(X_X)) , TAP_CODE_DELAY);
            set_mods(mods);
            return false;

        case COPY:
            clear_mods();
            SEND_STRING_DELAY(isMacOS ? SS_LGUI(SS_TAP(X_C)) : SS_LCTL(SS_TAP(X_C)) , TAP_CODE_DELAY);
            set_mods(mods);
            return false;

        case PASTE:
            clear_mods();
            SEND_STRING_DELAY(isMacOS ? SS_LGUI(SS_TAP(X_V)) : SS_LCTL(SS_TAP(X_V)) , TAP_CODE_DELAY);
            set_mods(mods);
            return false;

        case BOLD:
            clear_mods();
            SEND_STRING_DELAY(isMacOS ? SS_LGUI(SS_TAP(X_B)) : SS_LCTL(SS_TAP(X_B)) , TAP_CODE_DELAY);
            set_mods(mods);
            return false;

        case FIND:
            clear_mods();
            SEND_STRING_DELAY(isMacOS ? SS_LGUI(SS_TAP(X_F)) : SS_LCTL(SS_TAP(X_F)) , TAP_CODE_DELAY);
            set_mods(mods);
            return false;

        case NEWTAB:
            clear_mods();
            SEND_STRING_DELAY(isMacOS ? SS_LGUI(SS_TAP(X_T)) : SS_LCTL(SS_TAP(X_T)) , TAP_CODE_DELAY);
            set_mods(mods);
            return false;

        case CLOSTAB:
            clear_mods();
            SEND_STRING_DELAY(isMacOS ? SS_LGUI(SS_TAP(X_W)) : SS_LCTL(SS_TAP(X_W)) , TAP_CODE_DELAY);
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

#ifdef COMMUNITY_MODULE_CUSTOM_SHIFT_KEYS_ENABLE
const custom_shift_key_t custom_shift_keys[] = {
    {KC_ESC, KC_TILD},
};
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
