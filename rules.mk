# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
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
ACHORDION_ENABLE ?= no
ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	OPT_DEFS += -DACHORDION_ENABLE -DACHORDION_STREAK
	SRC += features/achordion.c
endif

CUSTOM_SHIFT_KEYS_ENABLE ?= no
ifeq ($(strip $(CUSTOM_SHIFT_KEYS_ENABLE)), yes)
	OPT_DEFS += -DCUSTOM_SHIFT_KEYS_ENABLE
	SRC += features/custom_shift_keys.c
endif

SELECT_WORD_ENABLE ?= yes
ifeq ($(strip $(SELECT_WORD_ENABLE)), yes)
	OPT_DEFS += -DSELECT_WORD_ENABLE -DSELECT_WORD_OS_DYNAMIC
	SRC += features/select_word.c
endif

ORYX_ENABLE = no
RGB_MATRIX_CUSTOM_KB = no
