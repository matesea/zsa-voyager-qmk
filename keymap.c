#include QMK_KEYBOARD_H
#include "version.h"
#include "layout.h"

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE
#define DIRECTION_LAYER_ENABLE

enum custom_keycodes {
  ARROW = ML_SAFE_RANGE,    // -> =>
  SWIME,   // switch ime
  CLOSAPP, // close app, alt-f4/gui-q according to OS
  APPPREV, // swap forground app to previous
  APPNEXT, // swap forground app to next
  RGBHRND, // random select effect

  // navigator trackball specific
  TOGGLE_SCROLL,        // toggle scroll drag
  DRAG_SCROLL,          // hold to enable scroll drag
  NAVIGATOR_TURBO,      // hold to enable trackball turbo mode
  NAVIGATOR_AIM,        // hold to enable trackball aim mode
  NAVIGATOR_INC_CPI,    // increase cpi
  NAVIGATOR_DEC_CPI,    // decrease cpi
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
  AUTO_MOUSE_LAYER_OFF, // deactivate auto mouse layer
  AUTO_MOUSE_TOGGLE,    // toggle auto mouse feature on/off
#endif

  // dummy keycode for C(KC_A)/C(KC_S)/C(KC_D)/C(KC_F)
  CA,
  CS,
  CD,
  CF,

#ifdef DIRECTION_LAYER_ENABLE
  /* vim navigation */
  /* the LBRC/RBRC keys must be both defined and in same order */
  /* shift + RBRC_* = LBRC_* */
  LBRC_A, // previous functon with aerial.nvim
  LBRC_B, // previous buffer
  LBRC_C, // previous hunk
  LBRC_D, // previous diagnostics
  LBRC_E,
  LBRC_F, // jump to highlight under cursor backward
  LBRC_G, // jump to any highlight backward
  LBRC_H,
  LBRC_I,
  LBRC_J,
  LBRC_K,
  LBRC_L,
  LBRC_M,
  LBRC_N,
  LBRC_O,
  LBRC_P,
  LBRC_Q, // previous item in quickfix
  LBRC_R,
  LBRC_S,
  LBRC_T, // previous tab
  LBRC_U,
  LBRC_V,
  LBRC_W,
  LBRC_X,
  LBRC_Y,
  LBRC_Z,

  RBRC_A,
  RBRC_B,
  RBRC_C,
  RBRC_D,
  RBRC_E,
  RBRC_F,
  RBRC_G,
  RBRC_H,
  RBRC_I,
  RBRC_J,
  RBRC_K,
  RBRC_L,
  RBRC_M,
  RBRC_N,
  RBRC_O,
  RBRC_P,
  RBRC_Q,
  RBRC_R,
  RBRC_S,
  RBRC_T,
  RBRC_U,
  RBRC_V,
  RBRC_W,
  RBRC_X,
  RBRC_Y,
  RBRC_Z,
#endif // DIRECTION_LAYER_ENABLE

  UPDIR, // input ../ per press
  KEYSTR_MIN = UPDIR,
  USRNAME, // input username

  /* tmux navigation */
  TMUX_A,    // C-a C-a, last window
  TMUX_C,    // C-a C-c, create
  TMUX_X,    // C-A x, kill
  TMUX_V,    // C-A v, vsplit
  TMUX_G,    // C-A g, split
  TMUX_P,    // C-A p, prev window
  TMUX_SLSH, // C-A /, search backward
  TMUX_QUES, // C-A ?, search backward with tmux plugin tmux-fuzzback
  TMUX_W,    // C-A w, select window with preview
  TMUX_N,    // C-A n, next window
  TMUX_S,    // C-A s, show all sessions
  TMUX_F,    // C-A f, select pane with fzf
  TMUX_Z,    // C-A z, zoom in current pane

  TMUX_H,    // C-A h, select left pane
  TMUX_K,    // C-A k, select down pane
  TMUX_J,    // C-A j, select up pane
  TMUX_L,    // C-A l, select right pane

  TMUX_SPC,  // C-A space, next layout
  TMUX_BSPC, // C-A backspace, previous layout

  TMUX_ML,   // C-A M-left, resize
  TMUX_MD,   // C-A M-down, resize
  TMUX_MU,   // C-A M-up, resize
  TMUX_MR,   // C-A M-right, resize

  TMUX_LBRC, // C-A [, enter copy mode
  TMUX_RBRC, // C-A ], paste
  TMUX_LCBR, // C-A {, swap pane
  TMUX_RCBR, // C-A }, swap pane

  KEYSTR_MAX = TMUX_RCBR,
};

struct keystring_t {
    const char *str;
    uint8_t delay;
};

enum {
    QWERTY = 0,
    SYM,
    EXT,
    NAV,
    FN,
#ifdef DIRECTION_LAYER_ENABLE
    DIR,
#endif // DIRECTION_LAYER_ENABLE
    TMUX,
};

enum keycode_aliases {
    SCL_TOG = TOGGLE_SCROLL,
    SCL_DRG = DRAG_SCROLL,
    NAV_TUR = NAVIGATOR_TURBO,
    NAV_AIM = NAVIGATOR_AIM,
    CPI_INC = NAVIGATOR_INC_CPI,
    CPI_DEC = NAVIGATOR_DEC_CPI,
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    AML_OFF = AUTO_MOUSE_LAYER_OFF,
    AM_TOGG = AUTO_MOUSE_TOGGLE,
#endif

    HRM_A   = LGUI_T(KC_A),
    HRM_S   = LT(SYM, KC_S),
    HRM_D   = LCTL_T(KC_D),
    HRM_F   = LSFT_T(KC_F),

    HRM_Z   = LALT_T(KC_Z),
    HRM_X   = LT(EXT, KC_X),

#if defined(POINTING_DEVICE_ENABLE)
    HRM_B   = LT(0, KC_B), // hold for navigator aim mode
    HRM_G   = LT(0, KC_G), // hold for scroll drag
#else
    HRM_B   = KC_B,
    HRM_G   = KC_G,
#endif // POINTING_DEVICE_ENABLE

    HRM_J    = RSFT_T(KC_J),
    HRM_K    = RCTL_T(KC_K),
    HRM_L    = LT(SYM, KC_L),
    HRM_SCLN = RGUI_T(KC_SCLN),

#ifdef DIRECTION_LAYER_ENABLE
    HRM_COMM = LT(DIR, KC_COMM),
    HRM_DOT = LT(DIR, KC_DOT),
#else
    HRM_COMM = KC_COMM,
    HRM_DOT = KC_DOT,
#endif // DIRECTION_LAYER_ENABLE
    HRM_SLSH = LALT_T(KC_SLSH),

    // HRM_REP  = LT(NAV, QK_REP),
    HRM_ENT  = LT(NAV, KC_ENT),
    HRM_BSPC = LT(FN, KC_BSPC),

    OSM_SFT  = OSM(MOD_LSFT),
    OSM_CTL  = OSM(MOD_LCTL),
    OSM_ALT  = OSM(MOD_LALT),
    OSM_GUI  = OSM(MOD_LGUI),

    NAV_A = LGUI_T(CA),
    NAV_S = LALT_T(CS),
    NAV_D = LCTL_T(CD),
    NAV_F = LSFT_T(CF),
};

static bool isMacOS = false;
#if defined(COMMUNITY_MODULE_SELECT_WORD_ENABLE) && defined(SELECT_WORD_OS_DYNAMIC)
bool select_word_host_is_mac(void) {
    return isMacOS;
}
#endif /* defined(COMMUNITY_MODULE_SELECT_WORD_ENABLE) && defined(SELECT_WORD_OS_DYNAMIC) */
#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_user(os_variant_t os) {
    isMacOS = (os == OS_MACOS || os == OS_IOS);
    return true;
}
#endif /* OS_DETECTION_ENABLE */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_LR(
            KC_ESC,  KC_1,   KC_2,   KC_3,  KC_4,    KC_5,
            KC_TAB,  KC_Q,   KC_W,   KC_E,  KC_R,    KC_T,
            KC_UNDS, HRM_A,  HRM_S,  HRM_D, HRM_F,   HRM_G,
            SWIME,   HRM_Z,  HRM_X,  KC_C,  KC_V,    HRM_B,
                                             OSM_SFT, HRM_ENT,

                      KC_6,    KC_7,  KC_8,     KC_9,    KC_0,     KC_EQL,
                      KC_Y,    KC_U,  KC_I,     KC_O,    KC_P,     KC_MINS,
                      KC_H,    HRM_J, HRM_K,    HRM_L,   HRM_SCLN, KC_QUOT,
                      KC_N,    KC_M,  HRM_COMM, HRM_DOT, HRM_SLSH, KC_BSLS,
                      HRM_BSPC, KC_SPC
            ),

    /* getreuer's symbol layer
       ' < > - |
       ! * / = &
       ~ + [ ] %
               X

            ^ { } $ X
            # ( ) ; "
            @ : , . '
            X
       split symbol layer to two hands to reduce finger travel distance
     */
    [SYM] = LAYOUT_LR(
            _______, _______,  _______, _______,  _______, _______,
            _______, KC_GRV ,  KC_LABK, KC_RABK,  KC_MINS, KC_PIPE,
            _______, KC_EXLM,  KC_ASTR, KC_SLSH,  KC_EQL,  KC_AMPR,
            XXXXXXX, KC_TILD,  KC_PLUS, KC_LBRC,  KC_RBRC, KC_PERC,
                                                  USRNAME, _______,

                     _______, _______,  _______,  _______, _______, _______,
                     KC_CIRC, KC_LCBR,  KC_RCBR,  KC_DLR,  ARROW  , _______,
                     KC_HASH, KC_LPRN,  KC_RPRN, KC_SCLN, KC_DQUO, UPDIR,
                     KC_AT,   KC_COLN,  KC_COMM,  KC_DOT,  KC_QUOT, KC_BSLS,
                     _______, _______
            ),

    // mouse keycodes and those often used together
    [EXT] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, MS_BTN2, _______,
                                                MS_BTN1, HRM_ENT,

                     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, QK_LLCK,
                     _______, _______, _______, _______, _______, CPI_INC,
                     _______, _______, _______, _______, _______, CPI_DEC,
                     _______, _______, _______, _______, _______, _______,
                     _______, _______
            ),

    // shortcuts that can be done with one-hand
    // navigation layer
    [NAV] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, CLOSAPP, C(KC_W), APPPREV, APPNEXT, C(KC_T),
            _______, NAV_A,   NAV_S,   NAV_D,   NAV_F,   C(KC_G),
            _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B),
                                                XXXXXXX, _______,

                     SELLINE,   SELWBAK, SELWORD, XXXXXXX, XXXXXXX, QK_LLCK,
                     KC_HOME,   KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_BRK,
                     KC_LEFT,   KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_PSCR,
                     G(KC_TAB), APPPREV, APPNEXT, XXXXXXX, KC_APP,  KC_SCRL,
                     _______,   _______
     ),

#if 0
    [FN] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            _______, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                XXXXXXX, _______,

                     QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_LLCK,
                     XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  QK_BOOT,
                     XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  LUMINO,
                     DB_TOGG, KC_F1,   KC_F2,   KC_F3,   KC_F10,  RGBHRND,
                     _______, _______
            ),
#endif

    [FN] = LAYOUT_LR(
            QK_LLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            QK_BOOT, KC_F12,  KC_F9,   KC_F8,   KC_F7,   DB_TOGG,
            QK_RBT,  KC_F11,  KC_F6,   KC_F5,   KC_F4,   LUMINO,
            XXXXXXX, KC_F10,  KC_F3,   KC_F2,   KC_F1,   RGBHRND,
                                                XXXXXXX, _______,

                     _______, _______, _______, _______, _______, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     _______, _______
            ),

    [TMUX] = LAYOUT_LR(
            _______, _______, _______, _______,  _______, _______,
            _______, XXXXXXX, TMUX_W,  TMUX_P,   TMUX_N,  XXXXXXX,
            _______, TMUX_A,  TMUX_S,  XXXXXXX,  TMUX_F,  TMUX_G,
            _______, TMUX_Z,  TMUX_X,  TMUX_C,   TMUX_V,  XXXXXXX,
                                                 XXXXXXX, XXXXXXX,

                       _______,   _______,   _______,   _______,   _______,   _______,
                       TMUX_ML,   TMUX_MD,   TMUX_MU,   TMUX_MR,   TMUX_RBRC, _______,
                       TMUX_H,    TMUX_J,    TMUX_K,    TMUX_L,    TMUX_SLSH, _______,
                       TMUX_LCBR, TMUX_LBRC, TMUX_RBRC, TMUX_RCBR, TMUX_QUES, _______,
                       TMUX_BSPC, TMUX_SPC
            ),

#ifdef DIRECTION_LAYER_ENABLE
    [DIR] = LAYOUT_LR(
            _______, _______, _______, _______, _______, _______,
            XXXXXXX, RBRC_Q,  RBRC_W,  RBRC_E,  RBRC_R,  RBRC_T,
            TMUX_N,  RBRC_A,  RBRC_S,  RBRC_D,  RBRC_F,  RBRC_G,
            XXXXXXX, RBRC_Z,  RBRC_X,  RBRC_C,  RBRC_V,  RBRC_B,
                                                XXXXXXX, _______,

                     _______, _______, _______, _______, _______, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                     _______, _______
            ),
#endif // DIRECTION_LAYER_ENABLE

#if 0
     [EXT] = LAYOUT_LR(  // Orbit Mouse
             _______, _______, _______, _______, _______, _______,
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,
             _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
             _______, KC_LALT, XXXXXXX, APPPREV, APPNEXT, XXXXXXX,
                                                 MS_BTN1, MS_BTN2,

                      _______, _______, _______, _______, _______, _______,
                      OM_W_U , OM_BTN1, OM_U   , OM_BTN2, XXXXXXX, _______,
                      OM_W_D , OM_L   , OM_D   , OM_R   , OM_SLOW, _______,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      XXXXXXX, QK_LLCK
     ),
#endif
};

#if defined(COMBO_ENABLE)
const uint16_t PROGMEM combo_xc[] = {HRM_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_fg[] = {HRM_F, HRM_G, COMBO_END};
const uint16_t PROGMEM combo_m_comm[] = {KC_M, HRM_COMM, COMBO_END};
const uint16_t PROGMEM combo_cd[] = {HRM_COMM, HRM_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_xc, MO(TMUX)),
    COMBO(combo_cv, CW_TOGG),
    COMBO(combo_fg, TOGGLE_SCROLL),
    COMBO(combo_m_comm, SWIME),
    COMBO(combo_cd, MO(TMUX)),
};
#endif /* COMBO_ENABLE */

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_F: case HRM_J:
            return TAPPING_TERM; /* 180ms */
    }
    return TAPPING_TERM + 70; /* 250ms */
}
#endif /* TAPPING_TERM_PER_KEY */

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // disable permissive hold for gui on windows
        // ; is frequently used in vim as leader key
        case HRM_A: case HRM_SCLN:
            return isMacOS;
        // disable permissive hold for alt
        case HRM_Z: case HRM_SLSH:
            return false;
    }
    return true;
}
#endif /* PERMISSIVE_HOLD_PER_KEY */

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_ENT:
            return true;
    }
    return false;
}
#endif

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case HRM_J:
    case HRM_K:
    case HRM_L:
    case HRM_ENT:
    case HRM_BSPC:
      return QUICK_TAP_TERM;  // Enable key repeating.
  }
  return 0;
}
#endif /* QUICK_TAP_TERM_PER_KEY */

#ifdef COMMUNITY_MODULE_PALETTEFX_ENABLE
static uint8_t myrand(void) {
  static uint16_t state = 1;
#ifdef __CHIBIOS__  // Use high-res timer on ChibiOS.
  state += (uint16_t)chVTGetSystemTimeX();
#else
  state += timer_read();
#endif
  state *= UINT16_C(36563);
  return state >> 8;
}

static void lighting_set_palette(uint8_t palette) {
  if (lumino_get_value() == 0) {
    lumino_cycle_3_state();
  }
  rgb_matrix_enable_noeeprom();
  rgb_matrix_sethsv_noeeprom(
      RGB_MATRIX_HUE_STEP * palette, 255, rgb_matrix_get_val());
}

static void lighting_preset(uint8_t effect, uint8_t palette) {
  lighting_set_palette(palette);
  rgb_matrix_mode_noeeprom(effect);
  rgb_matrix_set_speed_noeeprom(80);
}

void keyboard_post_init_user(void) {
  lighting_preset(RGB_MATRIX_CUSTOM_PALETTEFX_FLOW + (myrand() % 4), myrand());
}
#endif /* COMMUNITY_MODULE_PALETTEFX_ENABLE */

#ifdef CHORDAL_HOLD
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

bool get_chordal_hold(
        uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
        uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case HRM_A:
            switch (other_keycode) {
                // gui+E: explorer/gui+R: run
                case KC_E:
                case KC_R:
                    return true;
            }
            break;
        case HRM_X:
            switch (other_keycode) {
                // mouse keys
                case KC_V:
                    return true;
            }
            break;
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif  // CHORDAL_HOLD

#ifdef FLOW_TAP_TERM
static bool is_typing(uint16_t keycode) {
  switch (get_tap_keycode(keycode)) {
      case KC_A ... KC_Z:
      case KC_COMM:
      case KC_DOT:
      case KC_SCLN:
      case KC_SLSH:
      case KC_UNDS: // XXX: get_tap_keycode(HRM_UNDS) returns KC_MINS
      case KC_QUOT:
      case SWIME:
      case KC_BSLS:
      case KC_MINS:
      // thumb
      case KC_SPC:
      // case KC_BSPC:
          return true;
  }
  return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    const uint8_t all_mods = (get_mods() | get_weak_mods() |
            get_oneshot_mods());
    if (is_typing(prev_keycode) &&
            (all_mods & MOD_MASK_CAG) == 0) {
        // determine FLOW_TAP_TERM per key
        switch (keycode) {
            /*
             * XXX: tried investigating proper FLOW_TAP_TERM with qmk module dave-thompson/lumberjack
             *      this meaningful value should be around 60ms for me
             */
            // case HRM_S: case HRM_L: // LT(SYM) XXX: hard to find proper value for SYM layer
            case HRM_D: case HRM_K: // ctrl
                 return FLOW_TAP_TERM - 70; // 55ms

#ifdef DIRECTION_LAYER_ENABLE
            case HRM_COMM: case HRM_DOT:
                 return FLOW_TAP_TERM;      // 125ms
#endif
            case HRM_A: case HRM_SCLN:      // gui
            case HRM_Z: case HRM_SLSH:      // alt
            case HRM_X:                     // LT(EXT)
#ifdef POINTING_DEVICE_ENABLE
            case HRM_B:                     // NAVIGATOR_AIM
            case HRM_G:                     // DRAG_SCROLL
#endif // POINTING_DEVICE_ENABLE
                return FLOW_TAP_TERM + 25;  // 150ms
        }
    }
    return 0;
}
#endif /* FLOW_TAP_TERM */

#if defined(REPEAT_KEY_ENABLE)
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    /*
    // do not remember repeat key
    switch (keycode) {
        case HRM_REP:
            return false;
    }
    */

    // Unpack tapping keycode for tap-hold keys.
    keycode = get_tap_keycode(keycode);

    // Forget Shift on most letters when Shift or AltGr are the only mods. Some
    // letters are excluded, e.g. for "NN" and "ZZ" in Vim.
    // NN, SS, ZZ are excluded
    switch (keycode) {
      case KC_A ... KC_Y:
        if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
          *remembered_mods &= ~MOD_MASK_SHIFT;
        }
        break;

      case KC_TAB: // only remember shift when tab pressed
      case C(KC_TAB):
        *remembered_mods &= MOD_MASK_SHIFT;
        break;

#ifdef DIRECTION_LAYER_ENABLE
      case LBRC_A ... RBRC_Z:
#endif // DIRECTION_LAYER_ENABLE
      case KEYSTR_MIN ... KEYSTR_MAX: // forget all mods
        *remembered_mods = 0;
        break;
    }

    return true;
}

#ifndef NO_ALT_REPEAT_KEY
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if ((mods & ~MOD_MASK_SHIFT) == 0) {
        switch (keycode) {
            case KC_TAB:
            case C(KC_TAB):
                if (mods & MOD_MASK_SHIFT)
                    return keycode;
                else
                    return S(keycode);

#ifdef DIRECTION_LAYER_ENABLE
            /* reverse vim navigation */
            case LBRC_A ... LBRC_Z:
                return keycode - LBRC_A + RBRC_A;

            case RBRC_A ... RBRC_Z:
                return keycode - RBRC_A + LBRC_A;
#endif // DIRECTION_LAYER_ENABLE

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
#endif /* NO_ALT_REPEAT_KEY */
#endif /* REPEAT_KEY_ENABLE */

#ifdef DIRECTION_LAYER_ENABLE
static void generate_directional_string(uint16_t keycode, char* buf) {
    switch (keycode) {
        case LBRC_A ... LBRC_Z:
            buf[0] = '[';
            buf[1] = keycode - LBRC_A + 'a';
            break;
        case RBRC_A ... RBRC_Z:
            buf[0] = ']';
            buf[1] = keycode - RBRC_A + 'a';
            break;
        default:
            buf[0] = '\0';
            break;
    }
    buf[2] = '\0';
}
#endif // DIRECTION_LAYER_ENABLE

#define PREFIX_DELAY 50
static const struct keystring_t keystrings[] = {
    [UPDIR - KEYSTR_MIN]    = {"../", TAP_CODE_DELAY},
    [USRNAME - KEYSTR_MIN]  = {"wenlongy", TAP_CODE_DELAY},

    [TMUX_A - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LCTL(SS_TAP(X_A)), TAP_CODE_DELAY},
    [TMUX_C - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LCTL(SS_TAP(X_C)), TAP_CODE_DELAY},
    [TMUX_X - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_X), TAP_CODE_DELAY},
    [TMUX_V - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_V), TAP_CODE_DELAY},
    [TMUX_G - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_G), TAP_CODE_DELAY},
    [TMUX_P - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_TAP(X_P), TAP_CODE_DELAY},
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

    [TMUX_ML - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LALT(SS_TAP(X_LEFT)), TAP_CODE_DELAY},
    [TMUX_MD - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LALT(SS_TAP(X_DOWN)), TAP_CODE_DELAY},
    [TMUX_MU - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LALT(SS_TAP(X_UP)), TAP_CODE_DELAY},
    [TMUX_MR - KEYSTR_MIN]   = {SS_LCTL(SS_TAP(X_A)) SS_DELAY(PREFIX_DELAY) SS_LALT(SS_TAP(X_RIGHT)), TAP_CODE_DELAY},
};

#ifndef NO_DEBUG
#pragma message "dlog_record enabled."
#include "print.h"

static void dlog_record(uint16_t keycode, keyrecord_t* record) {
  if (!debug_enable) { return; }
  uint8_t layer = read_source_layers_cache(record->event.key);
  bool is_tap_hold = IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode);
  xprintf("L%-2u ", layer);  // Log the layer.
  if (IS_COMBOEVENT(record->event)) {  // Combos don't have a position.
    xprintf("combo   ");
  } else {  // Log the "(row,col)" position.
    xprintf("(%2u,%2u) ", record->event.key.row, record->event.key.col);
  }
  xprintf("%-4s %-7s %s\n",  // "(tap|hold) (press|release) <keycode>".
      is_tap_hold ? (record->tap.count ? "tap" : "hold") : "",
      record->event.pressed ? "press" : "release",
      get_keycode_string(keycode));
}
#else
#pragma message "dlog_record disabled."
#define dlog_record(keycode, record)
#endif  // NO_DEBUG

// customize tap behavior
// returning true means already handled
__attribute__((weak)) bool process_tap(keyrecord_t *record, uint16_t tap) {
    if (!record->tap.count)
        return false;
    // tap
    if (record->event.pressed) {
        tap_code16_delay(tap, TAP_CODE_DELAY);
#ifdef REPEAT_KEY_ENABLE
        set_last_keycode(tap);
#endif // REPEAT_KEY_ENABLE
     }
     return true;
}

__attribute__((weak)) bool add_mod_when_held(keyrecord_t *record, uint8_t mod) {
    if (record->tap.count)
        return false;
    if (record->event.pressed)
        register_mods(mod);
    else
        unregister_mods(mod);
    return true;
}

#ifdef STATUS_LED_4
// LED 4 indicate OSM_SFT status
void oneshot_mods_changed_user(uint8_t mods) {
    STATUS_LED_4(!!(mods & MOD_MASK_SHIFT));
}
#endif

#ifdef POINTING_DEVICE_ENABLE
extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(EXT);
    set_auto_mouse_enable(true);
}
bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case SCL_TOG ... NAV_AIM:
    // modifiers for mouse key
    case HRM_A:
    case HRM_D:
    case HRM_F:
    case HRM_Z:
      return true;
  }
  return is_mouse_record_user(keycode, record);
}
#endif /* POINTING_DEVICE_AUTO_MOUSE_ENABLE */
#endif /* POINTING_DEVICE_ENABLE */

static uint8_t swapp_mod = 0; // record app switch mod key status, alt for WIN, gui for MAC

// layer mask for which layers APPPREV/APPNEXT on
#define SWAPP_LAYER_MASK ((1 << NAV))
layer_state_t layer_state_set_user(layer_state_t state) {
#define max(x, y) ((x) > (y) ? (x) : (y))
    // LED indicates SYM or above layer is on
    uint8_t layer = max(get_highest_layer(state), SYM - 1) + 1 - SYM;
    // release swapp_mod when the layer is released
    if (swapp_mod && !(state & SWAPP_LAYER_MASK)) {
        unregister_mods(swapp_mod);
        swapp_mod = 0;
    }
    // automatically cancel oneshot shift when in other layer
    if ((get_oneshot_mods() & MOD_MASK_SHIFT) && layer > QWERTY) {
        del_oneshot_mods(MOD_MASK_SHIFT);
    }
    STATUS_LED_1(layer & (1 << 0));
    STATUS_LED_2(layer & (1 << 1));
    STATUS_LED_3(layer & (1 << 2));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  const uint8_t mods = get_mods();
  const uint8_t all_mods = (mods | get_weak_mods() | get_oneshot_mods());
  const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;
  const uint8_t ctrl_mods = all_mods & MOD_MASK_CTRL;
  const uint8_t layer = read_source_layers_cache(record->event.key);

  dlog_record(keycode, record);

  // XXX: WA to address unintended shift
  if (layer == SYM && record->event.pressed) {
      clear_weak_mods();
      send_keyboard_report();
  }

  if (swapp_mod) {
    // release swapp mod when the layer where APPPREV/APPNEXT are on
    // any tap/hold key pressed other than APPPREV/APPNEXT
    if ((keycode != APPPREV && keycode != APPNEXT && record->event.pressed)) {
        unregister_mods(swapp_mod);
        wait_ms(TAP_CODE_DELAY);
        swapp_mod = 0;
    }
  }

  // EXT layer lock will be automatically turned on when left/right mouse key pressed
  if (record->event.pressed) {
      switch (keycode) {
          // mouse keys press to keep staying EXT layer
          case MS_BTN1:
          case MS_BTN2:
              layer_lock_on(EXT);
              break;
          case C(KC_C):
          case C(KC_V):
          case TOGGLE_SCROLL:
              break;
          // hold modifiers to keep staying EXT layer
          case HRM_F:
          case HRM_D:
          case HRM_A:
          case HRM_Z:
          case HRM_ENT: // for shortcuts on NAV layer
          case HRM_B: case HRM_G: // DRAG_SCROLL
              if (!record->tap.count)
                  break;
          default:
              layer_lock_off(EXT);
              break;
      }
  }

#if defined(REPEAT_KEY_ENABLE)
  switch (get_tap_keycode(keycode)) {
      /* change repeat key as oneshot shift if following these keys */
      case KC_ENT:
      case KC_SPC:
      case KC_TAB:
      case KC_MINS:
      case APPPREV:
      case APPNEXT:
      case SWIME:
          if (get_repeat_key_count() > 0) {
              add_oneshot_mods(MOD_LSFT);
              return false;
          }
          break;
  }
#endif /* REPEAT_KEY_ENABLE */

  switch (keycode) {
    case APPPREV:
    case APPNEXT:
        if (record->event.pressed) {
          if (!swapp_mod) {
              swapp_mod = (isMacOS ? MOD_BIT_LGUI : MOD_BIT_LALT);
              register_mods(swapp_mod);
              wait_ms(TAP_CODE_DELAY);
          }
          tap_code16((keycode == APPNEXT ? KC_TAB : S(KC_TAB)));
        }
        return false;

    /* switch IME */
    case SWIME:
        const int8_t hold_mod = (isMacOS ? MOD_BIT_LCTRL : MOD_BIT_LGUI);
        if (record->event.pressed) {
#ifdef CAPS_WORD_ENABLE
            caps_word_off();
#endif /* CAPS_WORD_ENABLE */
            register_mods(hold_mod);
            tap_code16(KC_SPC);
        } else
            unregister_mods(hold_mod);
        return false;

    /*
     * close app
     * gui+q in MacOS
     * alt+f4 in Windows
     */
    case CLOSAPP:
        {
            uint8_t hold_mod = (isMacOS ? MOD_BIT_LGUI : MOD_BIT_LALT);
            uint16_t tap_key = (isMacOS ? KC_Q : KC_F4);
            if (record->event.pressed) {
                register_mods(hold_mod);
                wait_ms(TAP_CODE_DELAY);
                tap_code16(tap_key);
            } else
                unregister_mods(hold_mod);
        }
        return false;

    case NAV_A:
         if (process_tap(record, isMacOS ? G(KC_A) : C(KC_A)))
             return false;
         break;
    case NAV_S:
         if (process_tap(record, isMacOS ? G(KC_S) : C(KC_S)))
             return false;
         break;
    case NAV_D:
         if (process_tap(record, isMacOS ? G(KC_D) : C(KC_D)))
             return false;
         break;

    case NAV_F:
         if (process_tap(record, isMacOS ? G(KC_F) : C(KC_F)))
             return false;
         break;

    case HRM_COMM:
         add_mod_when_held(record, MOD_BIT_LSHIFT);
         break;

    case C(KC_A) ... C(KC_Z):
        // convert ctrl-<key> shortcuts to gui-<key> on MacOS
        if (isMacOS && record->event.pressed) {
            keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
            tap_code16_delay(G(keycode), TAP_CODE_DELAY);
#ifdef REPEAT_KEY_ENABLE
            set_last_keycode(G(keycode));
#endif /* REPEAT_KEY_ENABLE */
            return false;
        }
        break;

    /*
    case HRM_REP:
        if (record->tap.count) {
            repeat_key_invoke(&record->event);
            return false;
        }
        break;
    */
#ifdef POINTING_DEVICE_ENABLE
    case DRAG_SCROLL:
      set_scrolling = record->event.pressed;
      return false;

    case NAVIGATOR_TURBO:
      navigator_turbo = record->event.pressed;
      return false;

    case NAVIGATOR_AIM:
      navigator_aim = record->event.pressed;
      return false;

    case HRM_B:
      if (!record->tap.count)
          navigator_aim = record->event.pressed;
      break;

    case HRM_G:
      if (!record->tap.count)
          set_scrolling = record->event.pressed;
      break;
#endif /* POINTING_DEVICE_ENABLE */
  }

  if (record->event.pressed) {
#ifdef DIRECTION_LAYER_ENABLE
    // opposite directional movement when shift pressed
    if (shift_mods) {
        switch (keycode) {
          case RBRC_A ... RBRC_Z:
              keycode += LBRC_A - RBRC_A;
#ifdef REPEAT_KEY_ENABLE
              set_last_keycode(keycode);
#endif
              break;
          case TMUX_N:
              keycode = TMUX_P;
#ifdef REPEAT_KEY_ENABLE
              set_last_keycode(keycode);
#endif
              break;
        }
    }
#endif // DIRECTION_LAYER_ENABLE

    switch (keycode) {
        /* cancel OSM shift with BSPC */
        case HRM_BSPC:
            if (!record->tap.count)
                break;
            if (record->event.pressed && (get_oneshot_mods() & MOD_MASK_SHIFT)) {
                del_oneshot_mods(MOD_MASK_SHIFT);
                return false;
            }
            break;

        case ARROW:
          clear_mods();
          SEND_STRING(ctrl_mods ?
                  (shift_mods ?
                      "<=>" :
                      "=>") :
                  (shift_mods ?
                      "<->" :
                      "->"));
          set_mods(mods);
          return false;

#ifdef DIRECTION_LAYER_ENABLE
        case LBRC_A ... RBRC_Z:
          {
              static char buf[5] = {0};
              clear_mods();
              generate_directional_string(keycode, buf);
              SEND_STRING_DELAY(buf, TAP_CODE_DELAY);
              set_mods(mods);
          }
          return false;
#endif // DIRECTION_LAYER_ENABLE

        case KEYSTR_MIN ... KEYSTR_MAX:
          const struct keystring_t *p = &keystrings[keycode - KEYSTR_MIN];
          clear_mods();
          SEND_STRING_DELAY(p->str, p->delay);
          set_mods(mods);
          return false;

#ifdef COMMUNITY_MODULE_PALETTEFX_ENABLE
        case RGBHRND:
          lighting_preset(RGB_MATRIX_CUSTOM_PALETTEFX_FLOW + (myrand() % 4), myrand());
          return false;
#endif /* COMMUNITY_MODULE_PALETTEFX_ENABLE */

#ifdef POINTING_DEVICE_ENABLE
        case TOGGLE_SCROLL:
            set_scrolling = !set_scrolling;
            return false;
        case NAVIGATOR_INC_CPI:
            pointing_device_set_cpi(1);
            return false;
        case NAVIGATOR_DEC_CPI:
            pointing_device_set_cpi(0);
            return false;
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
        case AUTO_MOUSE_LAYER_OFF:
            auto_mouse_layer_off();
            return false;
        case AUTO_MOUSE_TOGGLE:
            auto_mouse_layer_off();
            set_auto_mouse_enable((AUTO_MOUSE_ENABLED) ^ 1);
            return false;
#endif
#endif /* POINTING_DEVICE_ENABLE */
    }
  }
  return true;
}

#ifdef COMMUNITY_MODULE_CUSTOM_SHIFT_KEYS_ENABLE
const custom_shift_key_t custom_shift_keys[] = {
    {KC_ESC, KC_TILD},
    {KC_MINS, KC_MINS}, // disable shift + -
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
