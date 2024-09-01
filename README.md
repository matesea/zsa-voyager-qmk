# zsa-voyager-qmk

Personal ZSA voyager keyboard config

## Configuration
* [Oryx configuration](https://configure.zsa.io/voyager/layouts/LNQG6/latest)
* Homerow mod: AGS
* Thumb
    * left: enter, ctrl
    * right: backspace, space
* Layers
    * NAVI: arrow keys/PGUP/PGDN/HOME/END/Insert/Delete etc
    * FN: Fn/Bright/Audio/animation/TappingTerm
    * PREFIX_LBRC, PREFIX_RBRC: prefix any keystroke with [ or ], mainly for vim navigation
* Key Override
    * shift + backspace = delete
    * gui + esc = \`
    * shift + esc = ~

## Disabled configuration
* Combo:
    * fg = esc
    * hj = esc
* Leader Key: replaced with prefix layers
    * leader leader = toggle vim direction, left/right braket
    * leader a = ]a, next symbol with aerial.nvim
    * leader t = ]t, next tab in vim
    * leader b = ]b, next buffer in vim
    * leader q = ]q, next in vim quickfix
    * leader c = ]c, next in vim diff hunk

## Additional features
* [Achordion](https://getreuer.info/posts/keyboards/achordion/index.html)
* [Key Override](https://docs.qmk.fm/#/feature_key_overrides)
* [Leader Key](https://docs.qmk.fm/features/leader_key)
* [Grave Escape](https://docs.qmk.fm/features/grave_esc)
* [Caps word](https://docs.qmk.fm/features/caps_word)
