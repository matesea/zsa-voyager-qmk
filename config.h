/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY

#ifdef ACHORDION_ENABLE
#define ACHORDION_STREAK
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#endif

#ifdef COMBO_ENABLE
#define COMBO_TERM 35
#define COMBO_COUNT 6
#endif

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"LNQG6/EQMNb"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT

#define RGB_MATRIX_STARTUP_SPD 60

#ifdef LEADER_ENABLE
#define LEADER_TIMEOUT 300
#endif

#ifdef CAPS_WORD_ENABLE
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 5000
#endif
