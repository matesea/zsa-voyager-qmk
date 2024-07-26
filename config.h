/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 200

#ifdef ACHORDION_ENABLE
#define ACHORDION_STREAK
#endif

#ifdef COMBO_ENABLE
#define COMBO_TERM 30
#endif

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"LNQG6/EQMNb"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define COMBO_COUNT 3

#define TAPPING_TERM_PER_KEY
#define RGB_MATRIX_STARTUP_SPD 60

#define ACHORDION_STREAK

#ifdef LEADER_ENABLE
#define LEADER_TIMEOUT 300
#endif
