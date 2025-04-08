/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#if !defined(ORYX_CONFIGURATOR) && defined(ORYX_ENABLE)
    #define ORYX_CONFIGURATOR
#endif

#define TAP_CODE_DELAY 5

#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY
#define QUICK_TAP_TERM 120

#define CHORDAL_HOLD

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
#define ONESHOT_TIMEOUT 2000

// #define NO_ALT_REPEAT_KEY

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

#define TAP_FLOW_TERM  75
#ifdef CONSOLE_ENABLE
#define TAP_FLOW_DEBUG
#endif
