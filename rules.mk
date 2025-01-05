# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = yes
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = no
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = no
LAYER_LOCK_ENABLE = yes
REPEAT_KEY_ENABLE = yes
LTO_ENABLE = yes
EXTRAKEY_ENABLE = yes

# use userspace version achordion
OPT_DEFS += -DACHORDION_ENABLE -DACHORDION_STREAK
SRC += features/achordion.c
