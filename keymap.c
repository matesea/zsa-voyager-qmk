#include QMK_KEYBOARD_H
#include "version.h"
#include "layout.h"
#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ARROW,    // -> => <-> <=>
  SELWORD,  // select word
  IME,      // switch ime
  RGB_DEF,  // set rgb to some nice default
  MAC_TOG,  // toggle mac os

  M_DOCSTR,
  M_INCLUDE,
  M_UPDIR,

  KEYSTR_MIN,
  SELLINE = KEYSTR_MIN,  // select entire line
  UPDIR,    // input ../ per press
  USRNAME,  // input username
  GOTOPATH, // entering selected path on windows
            // ctrl+c, win+r, ctrl+v
  CLOSAPP,  // alt+f4, close app

  /* vim navigation */
  LBRC_A,
  LBRC_B,
  LBRC_C,
  LBRC_D,
  /*
  LBRC_E,
  LBRC_F,
  LBRC_G,
  */
  LBRC_Q,
  /*
  LBRC_R,
  LBRC_S,
  */
  LBRC_T,
  /*
  LBRC_V,
  LBRC_W,
  LBRC_X,
  LBRC_Z,
  */

  RBRC_A,
  RBRC_B,
  RBRC_C,
  RBRC_D,
  /*
  RBRC_E,
  RBRC_F,
  RBRC_G,
  */
  RBRC_Q,
  /*
  RBRC_R,
  RBRC_S,
  */
  RBRC_T,
  /*
  RBRC_V,
  RBRC_W,
  RBRC_X,
  RBRC_Z,
  */

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
    NUM,
    FN,
    TMUX,
    BACKWARD,
    FORWARD,
    LAYER_MAX = FORWARD,
};

#define BASE_A      LT(SYM, KC_A)
#define BASE_S      LALT_T(KC_S)
#define BASE_D      LCTL_T(KC_D)
#define BASE_F      LSFT_T(KC_F)

#define BASE_Z      LGUI_T(KC_Z)
#define BASE_X      LT(NUM, KC_X)
#define BASE_C      KC_C
#define BASE_V      LT(NAVI, KC_V)

#define BASE_J      RSFT_T(KC_J)
#define BASE_K      RCTL_T(KC_K)
#define BASE_L      LALT_T(KC_L)
#define BASE_SCLN   LT(SYM, KC_SCLN)

#define BASE_M      KC_M
#define BASE_COMM   LT(BACKWARD, KC_COMM)
#define BASE_DOT    LT(FORWARD, KC_DOT)
#define BASE_SLSH   RGUI_T(KC_SLSH)

#define BASE_QUOT   LT(TMUX, KC_QUOT)
#define BASE_TAB    LT(TMUX, KC_TAB)

#define GS_LEFT     G(S(KC_LEFT))
#define GS_RGHT     G(S(KC_RGHT))

#define SYM_PLUS    KC_PLUS
#define SYM_MINS    KC_MINS
#define SYM_LPRN    KC_LPRN
#define SYM_RPRN    KC_RPRN

static bool isMacOS = false;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR(
            KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,     KC_5,
            KC_EQL,   KC_Q,   KC_W,   KC_E,   KC_R,     KC_T,
            BASE_TAB, BASE_A, BASE_S, BASE_D, BASE_F,   KC_G,
            QK_AREP,  BASE_Z, BASE_X, BASE_C, BASE_V,   KC_B,
                                              KC_ENT,   QK_REP,

                      KC_6,    KC_7,   KC_8,      KC_9,     KC_0,      KC_MINS,
                      KC_Y,    KC_U,   KC_I,      KC_O,     KC_P,      KC_BSLS,
                      KC_H,    BASE_J, BASE_K,    BASE_L,   BASE_SCLN, BASE_QUOT,
                      KC_N,    BASE_M, BASE_COMM, BASE_DOT, BASE_SLSH, KC_UNDS,
                      KC_BSPC, KC_SPC
            ),

    [NAVI] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
                                                _______, _______,

                     CLOSAPP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_BRK,
                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_PSCR,
                     GS_LEFT, SELLINE, SELWORD, GS_RGHT, KC_APP,  KC_SCRL,
                     _______, _______
            ),

    /*
         < > \ `
       ! - + = #
         / * ^ X

                & X [ ]
                | : ( ) %
                ~ $ { }
                */

    [SYM] = LAYOUT_LR(  // getreuer's symbol layer.
              _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, GOTOPATH,
              _______, MO(FN),  KC_LABK,  KC_RABK,  KC_BSLS, KC_GRV,
              _______, KC_EXLM, SYM_MINS, SYM_PLUS, KC_EQL , KC_HASH,
              _______, _______, KC_SLSH,  KC_ASTR,  KC_CIRC, UPDIR,
                                                  _______, _______,

                       _______, _______, _______,  _______,  _______, _______,
                       KC_AMPR, ARROW,   KC_LBRC,  KC_RBRC,  USRNAME, _______,
                       KC_PIPE, KC_COLN, SYM_LPRN, SYM_RPRN, KC_PERC, _______,
                       KC_TILD, KC_DLR , KC_LCBR,  KC_RCBR,  _______, _______,
                       _______, _______
            ),

    [NUM] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            _______, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, _______,

                     _______, _______, _______, _______, _______, _______,
                     KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_SLSH,
                     KC_COLN, KC_4,    KC_5,    KC_6,    KC_MINS, KC_ASTR,
                     KC_COMM, KC_1,    KC_2,    KC_3,    KC_DOT,  KC_BSPC,
                     KC_0, _______
            ),

    [FN] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, XXXXXXX, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            _______, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, _______,

                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                     XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
                     XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,
                     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  XXXXXXX,
                     _______, _______
            ),

    [TMUX] = LAYOUT_LR(
            TMUX_LBRC, TMUX_1,  TMUX_2,  TMUX_3,  TMUX_4,  TMUX_5,
            XXXXXXX,   XXXXXXX, TMUX_W,  XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX,   TMUX_A,  TMUX_S,  XXXXXXX, TMUX_F,  TMUX_G,
            XXXXXXX,   TMUX_Z,  TMUX_X,  TMUX_C,  TMUX_V,  XXXXXXX,
                                                _______, _______,

                       TMUX_6,    TMUX_7,    TMUX_8,    TMUX_9,    TMUX_0,    XXXXXXX,
                       TMUX_ML,   TMUX_MD,   TMUX_MU,   TMUX_MR,   TMUX_RBRC, XXXXXXX,
                       TMUX_H,    TMUX_J,    TMUX_K,    TMUX_L,    TMUX_SCLN, XXXXXXX,
                       TMUX_LCBR, TMUX_LBRC, TMUX_RBRC, TMUX_RCBR, TMUX_SLSH, TMUX_QUES,
                       TMUX_BSPC, TMUX_SPC
            ),

    [BACKWARD] = LAYOUT_LR(
            _______, RGB_DEF, RGB_RMOD, RGB_MOD, RGB_TOG, MAC_TOG,
            _______, LBRC_Q,  XXXXXXX,  XXXXXXX, XXXXXXX, LBRC_T,
            _______, LBRC_A,  XXXXXXX,  LBRC_D,  XXXXXXX, XXXXXXX,
            _______, XXXXXXX, TMUX_P,   LBRC_C,  XXXXXXX, LBRC_B,
                                                _______, _______,

                     _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______
            ),

    [FORWARD] = LAYOUT_LR(
            _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT,
            _______, RBRC_Q,  XXXXXXX, XXXXXXX, XXXXXXX, RBRC_T,
            _______, RBRC_A,  XXXXXXX, RBRC_D,  XXXXXXX, XXXXXXX,
            _______, XXXXXXX, TMUX_N,  RBRC_C,  XXXXXXX, RBRC_B,
                                                _______, _______,

                     _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______
            ),
};

#if defined(COMBO_ENABLE)
const uint16_t PROGMEM cv[] = {BASE_C, BASE_V, COMBO_END};
const uint16_t PROGMEM xcv[] = {BASE_X, BASE_C, BASE_V, COMBO_END};

const uint16_t PROGMEM hj[] = {BASE_J, KC_H, COMBO_END};
const uint16_t PROGMEM nm[] = {KC_N, BASE_M, COMBO_END};
const uint16_t PROGMEM mc[] = {BASE_M, BASE_COMM, COMBO_END};
const uint16_t PROGMEM cd[] = {BASE_COMM, BASE_DOT, COMBO_END};

const uint16_t PROGMEM navi_base[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM num_base[] = {KC_COMM, KC_1, COMBO_END};

const uint16_t PROGMEM navi_lock[] = {SELLINE, SELWORD, COMBO_END};
const uint16_t PROGMEM num_lock[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM fn_lock[] = {KC_F1, KC_F2, COMBO_END};
const uint16_t PROGMEM sym_lock[] = {KC_DLR, KC_LCBR, COMBO_END};

combo_t key_combos[] = {
    COMBO(cv, IME),
    COMBO(xcv, CW_TOGG),

    COMBO(hj, TO(NAVI)),
    COMBO(nm, TO(NUM)),
    COMBO(mc, QK_AREP),
    COMBO(cd, C(KC_W)), // vim window prefix

    COMBO(navi_base, TO(BASE)),
    COMBO(num_base, TO(BASE)),

    COMBO(navi_lock, QK_LLCK),
    COMBO(num_lock, QK_LLCK),
    COMBO(fn_lock, QK_LLCK),
    COMBO(sym_lock, QK_LLCK),
};
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE_F:
        case BASE_J:
            return TAPPING_TERM;
        // longer tapping term for ALT
        case BASE_S:
        case BASE_L:
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
    case BASE_J:
    case BASE_K:
    case BASE_L:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // only enable permissive hold for specific layer
    if (IS_QK_LAYER_TAP(keycode)) {
        uint16_t layer = QK_LAYER_TAP_GET_LAYER(keycode);
        return layer == NAVI || layer == SYM;
    }
    // disable permissive hold for ALT
    if (keycode & QK_LALT)
        return false;
    return true;
}
#endif

#ifdef RGB_MATRIX_CUSTOM_KB
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
                                            {0,0,0}, {0,0,0},

            {184,218,204},{0,0,0},      {0,0,0},      {0,0,0},      {0,0,0}, {0,0,0},
            {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {127,234,222},
            {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {127,234,222},
            {29,239,251}, {29,239,251}, {29,239,251}, {29,239,251}, {127,234,222}, {127,234,222},
            {0,0,0},      {0,0,0}
    },

    [SYM] = {
        {0,0,0}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {19,255,255},
        {0,0,0}, {6,255,255},   {184,218,204}, {184,218,204}, {44,255,255},  {44,255,255},
        {0,0,0}, {184,218,204}, {83,193,218},  {83,193,218},  {184,218,204}, {44,255,255},
        {0,0,0}, {0,0,0},       {83,193,218},  {83,193,218},  {44,255,255},  {44,255,255},
                                                              {0,0,0}, {0,0,0},

            {0,0,0},      {0,0,0},      {0,0,0},       {0,0,0},       {0,0,0},      {0,0,0},
            {83,193,218}, {44,255,255}, {127,234,222}, {127,234,222}, {6,255,255},  {0,0,0},
            {83,193,218}, {44,255,255}, {127,234,222}, {127,234,222}, {44,255,255}, {0,0,0},
            {83,193,218}, {44,255,255}, {127,234,222}, {127,234,222}, {0,0,0},      {0,0,0},
            {0,0,0},      {0,0,0}
    },

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
            {19,255,255}, {0,0,0},
    },

    [FN] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
                                            {0,0,0}, {0,0,0},

            {0,0,0}, {0,0,0},      {0,0,0},       {0,0,0},      {0,0,0},      {6,255,255},
            {0,0,0}, {83,193,218}, {83,193,218},  {83,193,218}, {83,193,218}, {0,0,0},
            {0,0,0}, {83,193,218}, {83,193,218},  {83,193,218}, {83,193,218}, {0,0,0},
            {0,0,0}, {83,193,218}, {83,193,218},  {83,193,218}, {83,193,218}, {0,0,0},
            {0,0,0},       {0,0,0}
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
        {0,0,0}, {44,255,255}, {44,255,255}, {44,255,255}, {44,255,255}, {6,255,255},
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
        {0,0,0}, {151,234,222}, {151,234,222}, {151,234,222}, {151,234,222}, {151,234,222},
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

#ifdef ACHORDION_ENABLE
// https://getreuer.info/posts/keyboards/achordion/index.html
void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    uint8_t other_row = other_record->event.key.row % (MATRIX_ROWS / 2);

    // allow same-hand shortcut when tap in thumb or first row
    if (other_row < 1 ||
            other_row > 4)
        return true;

    if (isMacOS) {
        switch (tap_hold_keycode) {
            /* same hand exceptions for GUI shortcut */
            case BASE_Z:
                // for cut/copy/paste/new tab on MAC OS
                if (other_keycode == BASE_X ||
                        other_keycode == BASE_C ||
                        other_keycode == BASE_V ||
                        other_keycode == KC_T ||
                        other_keycode == KC_W)
                    return true;
                break;
        }
    } else {
        switch (tap_hold_keycode) {
            /* same hand exceptions for CTRL shortcut */
            case BASE_D:
                if (other_keycode == BASE_A || // for tmux, ctrl-a ctrl-<letter>
                    // for cut/copy/paste/new tab
                        other_keycode == BASE_X ||
                        other_keycode == BASE_C ||
                        other_keycode == BASE_V ||
                        other_keycode == KC_B ||
                        other_keycode == KC_T)
                    return true;
                break;
            case BASE_Z:
                if (other_keycode == KC_R)
                    return true;
                break;
        }
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
    return 650;
}

#ifdef ACHORDION_STREAK
uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
    uint16_t layer = QK_LAYER_TAP_GET_LAYER(tap_hold_keycode);

  if (layer == NAVI)
    return 150;  // shorter streak detection on NAVI layer-tap key.

  // shortcut not blocked by streak detection
    if (isMacOS) {
        switch (tap_hold_keycode) {
            case BASE_Z:
                // for cut/copy/paste/new tab on MAC OS
                if (next_keycode == BASE_X ||
                        next_keycode == BASE_C ||
                        next_keycode == BASE_V ||
                        next_keycode == KC_T ||
                        next_keycode == KC_W)
                    return 0;
                break;
        }
    } else {
        switch (tap_hold_keycode) {
            case BASE_D:
                if (next_keycode == BASE_A ||
                        next_keycode == BASE_X ||
                        next_keycode == BASE_C ||
                        next_keycode == BASE_V ||
                        next_keycode == KC_B ||
                        next_keycode == KC_T)
                    return 0;
                break;
            case BASE_Z:
                if (next_keycode == KC_R)
                    return 0;
                break;
        }
    }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & (MOD_LSFT | MOD_RSFT)) != 0) {
    return 100;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return 240;  // A longer timeout otherwise.
  }
}
#endif
#endif

#if defined(REPEAT_KEY_ENABLE) && !defined(NO_ALT_REPEAT_KEY)
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if (mods == MOD_BIT_RCTRL || mods == MOD_BIT_LCTRL) {
        switch (keycode) {
          case BASE_TAB: return C(S(KC_TAB));
        }
    } else if (mods == MOD_BIT_LGUI || mods == MOD_BIT_RGUI) {
        switch (keycode) {
          case BASE_TAB: return G(S(KC_TAB));
        }
    } else if (mods == MOD_BIT_LALT) {
        switch (keycode) {
          case BASE_TAB: return A(S(KC_TAB));
        }
    } else if ((mods & ~MOD_MASK_SHIFT) == 0) {
        switch (keycode) {
            case KC_N:
                if ((mods & MOD_MASK_SHIFT) == 0)
                    return S(KC_N);
                return KC_N;

            case BASE_DOT:
              if ((mods & MOD_MASK_SHIFT) == 0) {
                return M_UPDIR;  // . -> ../
              }
              break;

            case KC_HASH: return M_INCLUDE; // # -> include
            case BASE_QUOT:
              if ((mods & MOD_MASK_SHIFT) != 0) {
                return M_DOCSTR;  // " -> ""<cursor>"""
              }
              break;

            /* reverse vim navigation */
            case LBRC_A: return RBRC_A;
            case LBRC_B: return RBRC_B;
            case LBRC_C: return RBRC_C;
            case LBRC_D: return RBRC_D;
            /*
            case LBRC_E: return RBRC_E;
            case LBRC_F: return RBRC_F;
            case LBRC_G: return RBRC_G;
            */
            case LBRC_Q: return RBRC_Q;
            /*
            case LBRC_R: return RBRC_R;
            case LBRC_S: return RBRC_S;
            */
            case LBRC_T: return RBRC_T;
            /*
            case LBRC_W: return RBRC_W;
            case LBRC_V: return RBRC_V;
            case LBRC_X: return RBRC_X;
            case LBRC_Z: return RBRC_Z;
            */

            case RBRC_A: return LBRC_A;
            case RBRC_B: return LBRC_B;
            case RBRC_C: return LBRC_C;
            case RBRC_D: return LBRC_D;
            /*
            case RBRC_E: return LBRC_E;
            case RBRC_F: return LBRC_F;
            case RBRC_G: return LBRC_G;
            */
            case RBRC_Q: return LBRC_Q;
            /*
            case RBRC_R: return LBRC_R;
            case RBRC_S: return LBRC_S;
            */
            case RBRC_T: return LBRC_T;
            /*
            case RBRC_W: return LBRC_W;
            case RBRC_V: return LBRC_V;
            case RBRC_X: return LBRC_X;
            case RBRC_Z: return LBRC_Z;
            */

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

// An enhanced version of SEND_STRING: if Caps Word is active, the Shift key is
// held while sending the string. Additionally, the last key is set such that if
// the Repeat Key is pressed next, it produces `repeat_keycode`. This helper is
// used for several macros below in my process_record_user() function.
#define MAGIC_STRING(str, repeat_keycode) \
  magic_send_string_P(PSTR(str), (repeat_keycode))
static void magic_send_string_P(const char* str, uint16_t repeat_keycode) {
  uint8_t saved_mods = 0;
  // If Caps Word is on, save the mods and hold Shift.
  if (is_caps_word_on()) {
    saved_mods = get_mods();
    register_mods(MOD_BIT(KC_LSFT));
  }

  send_string_P(str);  // Send the string.
  set_last_keycode(repeat_keycode);

  // If Caps Word is on, restore the mods.
  if (is_caps_word_on()) {
    set_mods(saved_mods);
  }
}
#endif


#define PREFIX_DELAY 50
static const struct keystring_t keystrings[] = {
    [SELLINE - KEYSTR_MIN]  = {SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)), TAP_CODE_DELAY},
    [UPDIR - KEYSTR_MIN]    = {"../", TAP_CODE_DELAY},
    [USRNAME - KEYSTR_MIN]  = {"wenlongy", TAP_CODE_DELAY},
    [GOTOPATH - KEYSTR_MIN] = {SS_LCTL(SS_TAP(X_C)) SS_DELAY(PREFIX_DELAY) SS_LGUI(SS_TAP(X_R)) SS_DELAY(PREFIX_DELAY) SS_LCTL(SS_TAP(X_V)), TAP_CODE_DELAY},
    [CLOSAPP - KEYSTR_MIN]  = {SS_LALT(SS_TAP(X_F4)), TAP_CODE_DELAY},
    [LBRC_A - KEYSTR_MIN]   = {"[a", TAP_CODE_DELAY},
    [LBRC_B - KEYSTR_MIN]   = {"[b", TAP_CODE_DELAY},
    [LBRC_C - KEYSTR_MIN]   = {"[c", TAP_CODE_DELAY},
    [LBRC_D - KEYSTR_MIN]   = {"[d", TAP_CODE_DELAY},
    /*
    [LBRC_E - KEYSTR_MIN]   = {"[e", TAP_CODE_DELAY},
    [LBRC_F - KEYSTR_MIN]   = {"[f", TAP_CODE_DELAY},
    [LBRC_G - KEYSTR_MIN]   = {"[g", TAP_CODE_DELAY},
    */
    [LBRC_Q - KEYSTR_MIN]   = {"[q", TAP_CODE_DELAY},
    /*
    [LBRC_R - KEYSTR_MIN]   = {"[r", TAP_CODE_DELAY},
    [LBRC_S - KEYSTR_MIN]   = {"[s", TAP_CODE_DELAY},
    */
    [LBRC_T - KEYSTR_MIN]   = {"[t", TAP_CODE_DELAY},
    /*
    [LBRC_V - KEYSTR_MIN]   = {"[v", TAP_CODE_DELAY},
    [LBRC_W - KEYSTR_MIN]   = {"[w", TAP_CODE_DELAY},
    [LBRC_X - KEYSTR_MIN]   = {"[x", TAP_CODE_DELAY},
    [LBRC_Z - KEYSTR_MIN]   = {"[z", TAP_CODE_DELAY},
    */

    [RBRC_A - KEYSTR_MIN]   = {"]a", TAP_CODE_DELAY},
    [RBRC_B - KEYSTR_MIN]   = {"]b", TAP_CODE_DELAY},
    [RBRC_C - KEYSTR_MIN]   = {"]c", TAP_CODE_DELAY},
    [RBRC_D - KEYSTR_MIN]   = {"]d", TAP_CODE_DELAY},
    /*
    [RBRC_E - KEYSTR_MIN]   = {"]e", TAP_CODE_DELAY},
    [RBRC_F - KEYSTR_MIN]   = {"]f", TAP_CODE_DELAY},
    [RBRC_G - KEYSTR_MIN]   = {"]g", TAP_CODE_DELAY},
    */
    [RBRC_Q - KEYSTR_MIN]   = {"]q", TAP_CODE_DELAY},
    /*
    [RBRC_R - KEYSTR_MIN]   = {"]r", TAP_CODE_DELAY},
    [RBRC_S - KEYSTR_MIN]   = {"]s", TAP_CODE_DELAY},
    */
    [RBRC_T - KEYSTR_MIN]   = {"]t", TAP_CODE_DELAY},
    /*
    [RBRC_V - KEYSTR_MIN]   = {"]v", TAP_CODE_DELAY},
    [RBRC_W - KEYSTR_MIN]   = {"]w", TAP_CODE_DELAY},
    [RBRC_X - KEYSTR_MIN]   = {"]x", TAP_CODE_DELAY},
    [RBRC_Z - KEYSTR_MIN]   = {"]z", TAP_CODE_DELAY},
    */

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
  const uint8_t layer = read_source_layers_cache(record->event.key);

  // WA to address unintended shift
  // source: reddit r/zsaVoyager: Weird firmware issue with [ turning into {
  if (layer == SYM && record->event.pressed) {
      switch (keycode) {
          case KC_BSLS:
          case KC_GRV:
          case KC_EQL:
          case KC_MINS:
          case KC_SLSH:
          case KC_LBRC:
          case KC_RBRC:
              clear_weak_mods();
              send_keyboard_report();
              break;
      }
  }

  switch (keycode) {
      /*
    case BASE_UNDS:
      // send _ when tap
      if (record->tap.count && record->event.pressed) {
          clear_mods();
          tap_code16(KC_UNDS);
          set_mods(mods);
          return false;
      }
      return true;

    case BASE_CW:
      if (record->tap.count && record->event.pressed) {
          caps_word_toggle();
          return false;
      }
      return true;
      */

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

    /*
       shift + esc = ~
    */
    case KC_ESC: {
      static uint16_t registered_key = KC_NO;

      if (record->event.pressed) {
          process_caps_word(keycode, record);
          const bool shifted = (mods | get_weak_mods()) & MOD_MASK_SHIFT;
          unregister_mods(MOD_MASK_SHIFT);

          registered_key = shifted ? KC_TILD : KC_ESC;
          register_code16(registered_key);
          set_mods(mods);
      } else if (registered_key) {
          unregister_code16(registered_key);
          registered_key = KC_NO;
      }
    } return false;
  }

  if (record->event.pressed) {
    switch (keycode) {
        case MAC_TOG:
            isMacOS = !isMacOS;
            return false;

        case SELWORD:
            if (isMacOS)
                SEND_STRING_DELAY(SS_LALT(SS_TAP(X_LEFT)) SS_LSFT(SS_LALT(SS_TAP(X_RIGHT))), TAP_CODE_DELAY);
            else
                SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_LEFT)) SS_LSFT(SS_LCTL(SS_TAP(X_RIGHT))), TAP_CODE_DELAY);
            return false;

        case RGB_SLD:
            rgblight_mode(1);
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

        /* switch IME based on layer */
        case IME:
            clear_mods();
            tap_code16(isMacOS ? C(KC_SPC) : G(KC_SPC));
            set_mods(mods);
            return false;
#ifdef RGB_MATRIX_ENABLE
        case RGB_DEF:  // Set RGB matrix to some nice defaults.
          rgb_matrix_enable_noeeprom();
          rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
          rgb_matrix_sethsv_noeeprom(17, 255, 255);  // Amber color.
          return false;
#endif  // RGB_MATRIX_ENABLE

        case KEYSTR_MIN ... KEYSTR_MAX:
          const struct keystring_t *p = &keystrings[keycode - KEYSTR_MIN];
          clear_mods();
          SEND_STRING_DELAY(p->str, p->delay);
          set_mods(mods);
          return false;

        // Macros invoked through the QK_AREP key.
        case M_UPDIR:   MAGIC_STRING(/*.*/"./", UPDIR); break;
        case M_INCLUDE: SEND_STRING_DELAY(/*#*/"include ", TAP_CODE_DELAY); break;
        case M_DOCSTR:
          SEND_STRING_DELAY(/*"*/"\"\"\"\"\""
              SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT), TAP_CODE_DELAY);
          break;
    }
  }
  return true;
}

#ifdef KEY_OVERRIDE_ENABLE
// https://docs.qmk.fm/#/feature_key_overrides
const key_override_t **key_overrides = (const key_override_t *[]){
    // SHIFT+ESC = ~
    &ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV)),
    // GUI+ESC = `
    &ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRV),
    NULL
};
#endif

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
