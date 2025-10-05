# zsa-voyager-qmk

Personal ZSA voyager keyboard config
qmk firmware version >= 0.28.0 with community modules

## configuration
* qwerty keyboard layout
* homerow mod: GACS
* thumbs
    * left: Enter, OSM_SFT
    * right: Backspace, Space
* layers
    * NAVI: arrow keys/PGUP/PGDN/HOME/END/Insert/Delete etc
    * SYM: symbol layer
    * FN: Function keys
    * DIR: prefix keystroke with [ or ] for vim, or other directional navigation
    * TMUX: tmux shortcuts
    * EXT: navigator/orbital mouse
* combo:
    * cv = CW_TOGG
    * m, = ctrl+space/win+space depending on OS
    * fg = OSL(FN)
* community module: custom shift
    * shift + esc = ~
* community module: lumino/palettefx
    * randomly pick an effect/palette at startup
* zsa navigator support
    * auto mouse enabled, with two custom keycodes
    * AML_OFF: turn off automouse layer
    * AM_TOGG: toggle automouse feature
