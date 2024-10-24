#include QMK_KEYBOARD_H
#include "version.h"
#include "layout.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ARROW,    // -> => <-> <=>
  SELLINE,
  UPDIR,
  USRNAME,
  IME,
  RGB_DEF,
  SWAPP,

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
  TMUX_A,    // C-a C-a, last
  TMUX_C,    // C-a C-c, create
  TMUX_X,    // C-A x, kill
  TMUX_V,    // C-A v, vsplit
  TMUX_G,    // C-A g, split
  TMUX_ESC,  // C-A ESC, copy mode
  TMUX_P,    // C-A p, paste
  TMUX_QUES, // C-A ?, search backward with tmux plugin tmux-fuzzback
  TMUX_W,    // C-A w, window preview
  TMUX_N,    // C-A n, next window
  TMUX_S,    // C-A s, show all sessions
  TMUX_D,    // C-A d, deattach
  TMUX_F,    // C-A f, select pane with fzf
  TMUX_Z,    // C-A z, zoom in current pane

  TMUX_1,    // C-A 1, select pane 1
  TMUX_2,    // C-A 2, select pane 2
  TMUX_3,    // C-A 3, select pane 3
  TMUX_4,    // C-A 4, select pane 4
  TMUX_5,    // C-A 5, select pane 5
  TMUX_6,    // C-A 6, select pane 6
  TMUX_7,    // C-A 7, select pane 7
  TMUX_8,    // C-A 8, select pane 8
  TMUX_9,    // C-A 9, select pane 9
  TMUX_0,    // C-A 0, select pane 0

  TMUX_CH,   // C-A C-h, resize
  TMUX_CK,   // C-A C-k, resize
  TMUX_CJ,   // C-A C-j, resize
  TMUX_CL,   // C-A C-l, resize
};

enum {
    BASE = 0,
    MAC,
    NAVI,
    FN,
    SYS,
    TMUX,
    PREFIX_LBRC,
    PREFIX_RBRC,
    LAYER_MAX = PREFIX_RBRC,
    /* SYM, */
    /* NUM, */
};

#define BASE_A      MT(MOD_LGUI, KC_A)
#define BASE_S      MT(MOD_LALT, KC_S)
#define BASE_D      MT(MOD_LCTL, KC_D)
#define BASE_F      MT(MOD_LSFT, KC_F)

#define BASE_Z      LT(FN, KC_Z)
#define BASE_X      KC_X
#define BASE_C      KC_C
#define BASE_V      LT(NAVI, KC_V)

#define BASE_J      MT(MOD_RSFT, KC_J)
#define BASE_K      MT(MOD_RCTL, KC_K)
#define BASE_L      MT(MOD_LALT, KC_L)
#define BASE_SCLN   MT(MOD_RGUI, KC_SCLN)

#define BASE_M      LT(PREFIX_LBRC, KC_M)
#define BASE_COMM   LT(PREFIX_RBRC, KC_COMM)
#define BASE_DOT    KC_DOT
#define BASE_SLSH   LT(SYS, KC_SLSH)

#define BASE_UNDS   LT(TMUX, KC_UNDS)
#define BASE_COLN   LT(TMUX, KC_COLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR(
            KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,     KC_5,
            KC_EQL,    KC_Q,   KC_W,   KC_E,   KC_R,     KC_T,
            KC_TAB,    BASE_A, BASE_S, BASE_D, BASE_F,   KC_G,
            BASE_COLN, BASE_Z, BASE_X, BASE_C, BASE_V,   KC_B,
                                              KC_ENT,   QK_REP,

                            KC_6,    KC_7,   KC_8,      KC_9,     KC_0,      KC_MINS,
                            KC_Y,    KC_U,   KC_I,      KC_O,     KC_P,      KC_BSLS,
                            KC_H,    BASE_J, BASE_K,    BASE_L,   BASE_SCLN, KC_QUOT,
                            KC_N,    BASE_M, BASE_COMM, BASE_DOT, BASE_SLSH, BASE_UNDS,
                            KC_BSPC, KC_SPC
            ),

    [MAC] = LAYOUT_LR(
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

    [NAVI] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
                                                _______, _______,

                              XXXXXXX, UPDIR,   SELLINE, ARROW,   USRNAME, XXXXXXX,
                              KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  XXXXXXX,
                              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_PSCR,
                              KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_APP,  XXXXXXX,
                              _______, _______
            ),

    [FN] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, _______,

                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                              XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
                              KC_TAB,  KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,
                              XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  XXXXXXX,
                              _______, _______
            ),

    [SYS] = LAYOUT_LR(
            _______, XXXXXXX, DT_DOWN,  DT_UP,   DT_PRNT, XXXXXXX,
            _______, RGB_DEF, RGB_RMOD, RGB_MOD, RGB_TOG, XXXXXXX,
            _______, KC_MUTE, KC_VOLD,  KC_VOLU, KC_MPLY, KC_MNXT,
            _______, XXXXXXX, XXXXXXX,  TO(MAC), TO(BASE),XXXXXXX,
                                                _______, _______,

                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______
            ),

    [TMUX] = LAYOUT_LR(
            TMUX_ESC, TMUX_1,  TMUX_2, TMUX_3,  TMUX_4,  TMUX_5,
            XXXXXXX,  XXXXXXX, TMUX_W, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX,  TMUX_A,  TMUX_S, TMUX_D,  TMUX_F,  TMUX_G,
            XXXXXXX,  TMUX_Z,  TMUX_X, TMUX_C,  TMUX_V,  XXXXXXX,
                                                _______, _______,

                              TMUX_6,  TMUX_7,  TMUX_8,  TMUX_9,  TMUX_0,    TMUX_G,
                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TMUX_P,    TMUX_V,
                              TMUX_CH, TMUX_CJ, TMUX_CK, TMUX_CL, XXXXXXX,   XXXXXXX,
                              TMUX_N,  XXXXXXX, XXXXXXX, XXXXXXX, TMUX_QUES, XXXXXXX,
                              _______, _______
            ),

    [PREFIX_LBRC] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, LBRC_Q,  XXXXXXX, XXXXXXX, XXXXXXX, LBRC_T,
            _______, LBRC_A,  XXXXXXX, LBRC_D,  XXXXXXX, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, LBRC_C,  XXXXXXX, LBRC_B,
                                                _______, _______,

                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______
            ),

    [PREFIX_RBRC] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, RBRC_Q,  XXXXXXX, XXXXXXX, XXXXXXX, RBRC_T,
            _______, RBRC_A,  XXXXXXX, RBRC_D,  XXXXXXX, XXXXXXX,
            _______, XXXXXXX, XXXXXXX, RBRC_C,  XXXXXXX, RBRC_B,
                                                _______, _______,

                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______, _______, _______, _______,  _______,
                              _______, _______
            ),

    /*
         < > \ `
       ! - + = #
         / * ^ X

                & X [ ]
                | : ( ) %
                ~ $ { }
    [SYM] = LAYOUT_LR(  // Symbol layer.
              _______, _______, _______, _______, _______, _______,
              _______, XXXXXXX, KC_LABK, KC_RABK, KC_BSLS, KC_GRV ,
              _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,
              _______, XXXXXXX, KC_SLSH, KC_ASTR, KC_CIRC, USRNAME,
                                                           _______, _______,

                                _______, _______, _______, _______, _______, _______,
                                KC_AMPR, ARROW,   KC_LBRC, KC_RBRC, XXXXXXX, _______,
                                KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC, _______,
                                KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, XXXXXXX, _______,
                       _______, _______
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
    */
};

#if defined(COMBO_ENABLE)
enum combos {
    /* left hand */
    FG,
    CV,
    XC,

    /* right hand */
    HJ,
    MC,
    CD,

    /* return BASE from other layers */
    NAVI_BASE,
};

const uint16_t PROGMEM fg[] = {BASE_F, KC_G, COMBO_END};
const uint16_t PROGMEM cv[] = {BASE_C, BASE_V, COMBO_END};
const uint16_t PROGMEM xc[] = {BASE_X, BASE_C, COMBO_END};

const uint16_t PROGMEM hj[] = {BASE_J, KC_H, COMBO_END};
const uint16_t PROGMEM mc[] = {BASE_M, BASE_COMM, COMBO_END};
const uint16_t PROGMEM cd[] = {BASE_COMM, BASE_DOT, COMBO_END};

const uint16_t PROGMEM navi_base[] = {KC_LEFT, KC_DOWN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [FG] = COMBO(fg, SWAPP),
    [CV] = COMBO(cv, IME),
    [XC] = COMBO(xc, CW_TOGG),

    [HJ] = COMBO(hj, TO(NAVI)),
    [MC] = COMBO(mc, QK_AREP),
    [CD] = COMBO(cd, C(KC_W)), // vim window prefix

    [NAVI_BASE] = COMBO(navi_base, TO(BASE)),
};
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE_F:
        case BASE_J:
            return g_tapping_term;
            /*
        case BASE_D:
        case BASE_C:
        case BASE_V:
        case BASE_K:
        case BASE_M:
        case BASE_COMM:
            return g_tapping_term + 20;
        case BASE_S:
        case BASE_X:
        case BASE_L:
        case BASE_DOT:
            return g_tapping_term + 40;
            */
        // longer tapping term for ALT
        case BASE_S:
        case BASE_L:
            return g_tapping_term + 50;
    }
    return g_tapping_term + 30;
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
    uint16_t layer;

    // only enable permissive hold for specific layer
    if (IS_QK_LAYER_TAP(keycode)) {
        layer = QK_LAYER_TAP_GET_LAYER(keycode);
        return layer == NAVI || layer == FN;
    }
    // disable permissive hold for ALT
    // disable permissive hold for RGUI for avoid misfire vim leader sequence starting with ;
    if (keycode & (QK_LALT | QK_RGUI))
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
    [MAC] = {
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

    [NAVI] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
                                            {0,0,0}, {0,0,0},
                                            // {0,0,0}, {184,218,204},

            {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255}, {19,255,255},  {0,0,0},
            {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {0,0,0},
            {83,193,218}, {83,193,218}, {83,193,218}, {83,193,218}, {127,234,222}, {127,234,222},
            {29,239,251}, {29,239,251}, {29,239,251}, {29,239,251}, {127,234,222}, {0,0,0},
            {0,0,0},      {0,0,0}
    },

    [FN] = {
        {0,0,0},  {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},  {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},  {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0},  {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
                                             {0,0,0}, {0,0,0},

            {0,0,0},      {0,0,0},      {0,0,0},       {0,0,0},      {0,0,0},      {6,255,255},
            {0,0,0},      {83,193,218}, {83,193,218},  {83,193,218}, {83,193,218}, {0,0,0},
            {44,255,255}, {83,193,218}, {83,193,218},  {83,193,218}, {83,193,218}, {0,0,0},
            {0,0,0},      {83,193,218}, {83,193,218},  {83,193,218}, {83,193,218}, {0,0,0},
            {0,0,0},      {0,0,0}
    },

    [SYS] = {
        {0,0,0}, {0,0,0},       {83,193,218},  {83,193,218},  {83,193,218},  {0,0,0},
        {0,0,0}, {44,255,255},  {44,255,255},  {44,255,255},  {44,255,255},  {0,0,0},
        {0,0,0}, {151,234,222}, {151,234,222}, {151,234,222}, {151,234,222}, {151,234,222},
        {0,0,0}, {0,0,0},       {0,0,0},       {184,218,204}, {6,255,255},   {0,0,0},
                                                              {0,0,0},       {0,0,0},

            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}
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
    [SYM] = {
        {0,0,0}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
        {0,0,0}, {0,0,0},       {184,218,204}, {184,218,204}, {44,255,255},  {44,255,255},
        {0,0,0}, {184,218,204}, {83,193,218},  {83,193,218},  {184,218,204}, {44,255,255},
        {0,0,0}, {0,0,0},       {83,193,218},  {83,193,218},  {44,255,255},  {44,255,255},
                                                              {0,0,0}, {0,0,0},

            {0,0,0},       {0,0,0},      {0,0,0},      {0,0,0},      {0,0,0},      {0,0,0},
            {151,234,222}, {44,255,255}, {29,239,251}, {29,239,251}, {0,0,0},      {0,0,0},
            {151,234,222}, {44,255,255}, {29,239,251}, {29,239,251}, {44,255,255}, {0,0,0},
            {151,234,222}, {44,255,255}, {29,239,251}, {29,239,251}, {0,0,0},      {0,0,0},
            {0,0,0},       {0,0,0}
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
    uint8_t tap_hold_row = tap_hold_record->event.key.row % (MATRIX_ROWS / 2);
    uint8_t other_row = other_record->event.key.row % (MATRIX_ROWS / 2);

    // allow either hold key or other key in thumb
    if (tap_hold_row > 4 ||
            other_row > 4)
        return true;

    switch (tap_hold_keycode) {
        /* same hand exceptions for CTRL shortcut */
        case BASE_D:
            if (other_keycode == BASE_A || // for tmux, ctrl-a ctrl-<letter>
                // for cut/copy/paste/new tab
                    other_keycode == BASE_X ||
                    other_keycode == BASE_C ||
                    other_keycode == BASE_V ||
                    other_keycode == KC_T)
                return true;
            break;
        /* same hand exceptions for GUI shortcut */
        case BASE_A:
            // for cut/copy/paste/new tab on MAC OS
            if (other_keycode == BASE_X ||
                    other_keycode == BASE_C ||
                    other_keycode == BASE_V ||
                    other_keycode == KC_T ||
                    other_keycode == KC_W)
                return true;
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
    tap_hold_keycode &= 0xff;
    // only enable achordion for homerow
    switch (tap_hold_keycode) {
        // homerow and bottom row
        case KC_A: case KC_S: case KC_D: case KC_F:
        case KC_C: case KC_V: case KC_X: case KC_Z:
        case KC_J: case KC_K: case KC_L: case KC_SCLN:
        case KC_M: case KC_COMM: case KC_DOT: case KC_SLSH:

        // thumb keys or edge columns
        case KC_ENT: case KC_MINS: case KC_TAB:
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

  // shortcut not blocked by streak detection
  switch (tap_hold_keycode) {
      case BASE_D:
          if (next_keycode == BASE_A ||
                  next_keycode == BASE_X ||
                  next_keycode == BASE_C ||
                  next_keycode == BASE_V ||
                  next_keycode == KC_T)
              return 0;
          break;

      case BASE_A:
          // for cut/copy/paste/new tab on MAC OS
          if (next_keycode == BASE_X ||
                  next_keycode == BASE_C ||
                  next_keycode == BASE_V ||
                  next_keycode == KC_T ||
                  next_keycode == KC_W)
              return 0;
          break;
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & (MOD_LSFT | MOD_RSFT)) != 0) {
    return 100;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return 200;  // A longer timeout otherwise.
  }
}
#endif
#endif

void static update_swapper(
    uint16_t *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (*active == KC_NO) {
                register_code(cmdish);
                *active = cmdish;
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active != KC_NO) {
        unregister_code(*active);
        *active = KC_NO;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t swapp_active = KC_NO;

    update_swapper(
        &swapp_active,
        IS_LAYER_ON(MAC) ? KC_LGUI : KC_LALT,
        KC_TAB, SWAPP, keycode, record);

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

  switch (keycode) {
      case BASE_UNDS:
        // send _ when tap
        if (record->tap.count && record->event.pressed) {
            clear_mods();
            tap_code16(KC_UNDS);
            set_mods(mods);
            return false;
        }
        return true;

      case BASE_COLN:
        // send _ when tap
        if (record->tap.count && record->event.pressed) {
            clear_mods();
            tap_code16(KC_COLN);
            set_mods(mods);
            return false;
        }
        return true;

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

  }

  if (record->event.pressed) {
    switch (keycode) {
        case SELLINE:  // Selects the current line.
            SEND_STRING_DELAY(
                    SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)), TAP_CODE_DELAY);
            return false;

        case UPDIR:
            SEND_STRING_DELAY("../", TAP_CODE_DELAY);
            return false;

        case USRNAME:
            SEND_STRING_DELAY("wenlongy", TAP_CODE_DELAY);
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
                SEND_STRING(alt ? "<=>" : "=>");
            else
                SEND_STRING(alt ? "<->" : "->");
            set_mods(mods);
            return false;

        /* switch IME based on layer */
        case IME:
            clear_mods();
            tap_code16(IS_LAYER_ON(MAC) ? C(KC_SPC) : G(KC_SPC));
            set_mods(mods);
            return false;
#ifdef RGB_MATRIX_ENABLE
        case RGB_DEF:  // Set RGB matrix to some nice defaults.
          rgb_matrix_enable_noeeprom();
          rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
          rgb_matrix_sethsv_noeeprom(17, 255, 255);  // Amber color.
          return false;
#endif  // RGB_MATRIX_ENABLE

        case LBRC_A:
          SEND_STRING_DELAY("[a", TAP_CODE_DELAY);
          return false;
        case LBRC_B:
          SEND_STRING_DELAY("[b", TAP_CODE_DELAY);
          return false;
        case LBRC_C:
          SEND_STRING_DELAY("[c", TAP_CODE_DELAY);
          return false;
        case LBRC_D:
          SEND_STRING_DELAY("[d", TAP_CODE_DELAY);
          return false;
        case LBRC_Q:
          SEND_STRING_DELAY("[q", TAP_CODE_DELAY);
          return false;
        case LBRC_T:
          SEND_STRING_DELAY("[t", TAP_CODE_DELAY);
          return false;
        case RBRC_A:
          SEND_STRING_DELAY("]a", TAP_CODE_DELAY);
          return false;
        case RBRC_B:
          SEND_STRING_DELAY("]b", TAP_CODE_DELAY);
          return false;
        case RBRC_C:
          SEND_STRING_DELAY("]c", TAP_CODE_DELAY);
          return false;
        case RBRC_D:
          SEND_STRING_DELAY("]d", TAP_CODE_DELAY);
          return false;
        case RBRC_Q:
          SEND_STRING_DELAY("]q", TAP_CODE_DELAY);
          return false;
        case RBRC_T:
          SEND_STRING_DELAY("]t", TAP_CODE_DELAY);
          return false;
        case TMUX_A:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_A)));
          return false;
        case TMUX_C:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_C)));
          return false;
        case TMUX_X:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_X));
          return false;
        case TMUX_V:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_V));
          return false;
        case TMUX_G:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_G));
          return false;
        case TMUX_ESC:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_ESC));
          return false;
        case TMUX_P:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_P));
          return false;
        case TMUX_QUES:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LSFT(SS_TAP(X_SLSH)));
          return false;
        case TMUX_W:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_W));
          return false;
        case TMUX_N:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_N));
          return false;
        case TMUX_S:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_S));
          return false;
        case TMUX_D:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_D));
          return false;
        case TMUX_F:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_F));
          return false;
        case TMUX_Z:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_Z));
          return false;
        case TMUX_1:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_1));
          return false;
        case TMUX_2:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_2));
          return false;
        case TMUX_3:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_3));
          return false;
        case TMUX_4:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_4));
          return false;
        case TMUX_5:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_5));
          return false;
        case TMUX_6:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_6));
          return false;
        case TMUX_7:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_7));
          return false;
        case TMUX_8:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_8));
          return false;
        case TMUX_9:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_9));
          return false;
        case TMUX_0:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_0));
          return false;
        case TMUX_CH:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_H)));
          return false;
        case TMUX_CJ:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_J)));
          return false;
        case TMUX_CK:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_K)));
          return false;
        case TMUX_CL:
          SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_L)));
          return false;
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

#if defined(REPEAT_KEY_ENABLE) && !defined(NO_ALT_REPEAT_KEY)
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if (keycode == KC_TAB) {
        if ((mods & MOD_MASK_CTRL)) return C(S(KC_TAB));
        if ((mods & MOD_MASK_ALT)) return A(S(KC_TAB));
        if (mods & MOD_MASK_GUI) return G(S(KC_TAB));
    } else if ((mods & ~MOD_MASK_SHIFT) == 0) {
        switch (keycode) {
            case KC_N:
                if ((mods & MOD_MASK_SHIFT) == 0)
                    return S(KC_N);
                else
                    return KC_N;
                break;

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
        }
    }
    return KC_TRNS;
}
#endif
