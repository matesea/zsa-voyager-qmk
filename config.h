/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once

#define TAP_CODE_DELAY 5

#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define QUICK_TAP_TERM_PER_KEY
#define QUICK_TAP_TERM 120

#define CHORDAL_HOLD

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
// #define NO_ACTION_ONESHOT

#define NO_ALT_REPEAT_KEY

#ifdef COMBO_ENABLE
#define COMBO_TERM 35
#endif

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"LNQG6/EQMNb"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_STARTUP_SPD 60
#include "rgb_matrix_effects.h"
#endif

#ifdef CAPS_WORD_ENABLE
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 5000
#endif

#ifdef LAYER_LOCK_ENABLE
#define LAYER_LOCK_IDLE_TIMEOUT 60000
#endif

#define CUSTOM_SHIFT_KEYS_LAYER_MASK (1 << 0)
#define SELECT_WORD_OS_DYNAMIC

// #ifdef OS_DETECTION_ENABLE
// #define OS_DETECTION_SINGLE_REPORT
// #endif

#define FLOW_TAP_TERM 100
// #define ACTION_DEBUG

// Define speed curve for Orbital Mouse.
#define ORBITAL_MOUSE_SPEED_CURVE \
      {24, 24, 24, 32, 62, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72}
//     |               |               |               |           |
// t = 0.000           1.024           2.048           3.072       3.840 s
