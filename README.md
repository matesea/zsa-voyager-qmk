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
    * NAV: arrow keys/page up/page down/home/end/insert/delete etc + mouse keys
    * SYM: symbol layer
    * FN: Function keys
    * DIR: prefix keystroke with [ or ] for vim, or other directional navigation
    * TMUX: tmux shortcuts
    * SHORTCUT: left-hand shortcuts
* combo:
    * cv = caps word toggle
    * m, = ctrl+space/win+space depending on OS, switch input method
    * fg = OSL(FN)
* community module: lumino/palettefx
    * randomly pick an effect/palette at startup
* community module: select word
    * quickly select word forward/backward or select line
* other custom keycodes
    * APPNEXT/APPPREV: swap foreground app
