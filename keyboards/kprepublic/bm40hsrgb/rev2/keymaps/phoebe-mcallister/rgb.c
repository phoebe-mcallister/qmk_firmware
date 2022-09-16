/* Copyright 2022 @phoebe-mcallister
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */


#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "rgbmap.h"

const uint8_t rgb_class_maps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR, KEYBASE,
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  I_CAPS, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR, KEYBASE,
      KEYBASE, USE_LYR, REF_LYR(_ARR), USE_LYR, REF_LYR(_SYM), REF_LYR(_NUM), USE_LYR, REF_LYR(_SYM), USE_LYR, USE_LYR, USE_LYR, KEYBASE,
      KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE,     KEYBASE,      KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE 
    ),
    [_SYM] = LAYOUT_ortho_4x12_1x2uC(
      KEYBASE, _NUMBER, _NUMBER, _NUMBER, _NUMBER, _NUMBER, _NUMBER, _NUMBER, _NUMBER, _NUMBER, _NUMBER,    _OFF,
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  I_CAPS, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,    _OFF,
      KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE, USE_LYR, KEYBASE, USE_LYR, USE_LYR, USE_LYR,    _OFF,
      KEYBASE,    _MOD,    _MOD,    _MOD,  _MOUSE,      _SPACE,      _DELETE,  _ENTER, KEYBASE, KEYBASE, KEYBASE 
    ),
    [_ARR] = LAYOUT_ortho_4x12_1x2uC(
      KEYBASE,   _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,
      KEYBASE, KEYBASE, KEYBASE, KEYBASE,     SYM,  I_CAPS, USE_LYR, USE_LYR, USE_LYR, USE_LYR,     SYM,   _FUNC,
      KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE,     SYM,     SYM,     SYM,     SYM,  _ENTER,    _OFF,
      KEYBASE,    _MOD,    _MOD,    _MOD,  _MOUSE,      _SPACE,      _DELETE,  _ENTER, KEYBASE, KEYBASE, KEYBASE 
    ),
    [_NUM] = LAYOUT_ortho_4x12_1x2uC(
      KEYBASE,  _MEDIA,  _MEDIA,   _BOOT,  _MEDIA,  _MEDIA, _NPSIDE, USE_LYR, USE_LYR, USE_LYR, _NPSIDE,    _OFF,
      KEYBASE,   _MOVE, KEYBASE, KEYBASE, KEYBASE,  I_CAPS, _NPSIDE, USE_LYR, USE_LYR, USE_LYR, _NPSIDE,    _OFF,
      KEYBASE,   _MOVE,   _MOVE, KEYBASE, KEYBASE, KEYBASE, KEYBASE,     SYM,     SYM,     SYM, _NPSIDE,    _OFF,
      KEYBASE,    _MOD,    _MOD,    _MOD,  _MOUSE,      USE_LYR,     _DELETE,  _ENTER, KEYBASE, KEYBASE, KEYBASE 
    )
};

void determine_key_color(RGB* retval, const keypos_t pos, const uint8_t layer) {
    const uint8_t rgb_code = rgb_class_maps[layer][pos.row][pos.col];
    const uint8_t body = GET_BODY(rgb_code);

    switch(GET_TYPE(rgb_code)) {
        case TYPE_CLASS:
            *retval = class_colors[body];
            break;
        case TYPE_LAYER:
            *retval = layer_colors[layer].keyglow;
            break;
        case TYPE_REFERENCE:
            *retval = layer_colors[body].keyglow;
            break;
        case TYPE_INDICATOR:
            if (body == _CAPS_IND && host_keyboard_led_state().caps_lock) {
                *retval = class_colors[_BOOT];
            } else {
                *retval = layer_colors[layer].keyglow;
            }
            break;
        case TYPE_KEYBASE:
            switch(keymap_key_to_keycode(layer, pos)) {
                case KC_ESC: case KC_BSPC:
                    *retval = class_colors[_DELETE];
                    break;
                case XXXXXXX:
                    *retval = class_colors[_OFF];
                    break;
                case KC_SPC:
                    *retval = layer_colors[layer].keyglow;
                    break;
                case KC_ENT:
                    *retval = class_colors[_ENTER];
                    break;
                case QK_BOOT:
                    *retval = class_colors[_BOOT];
                    break;
                case KC_LCTL: case KC_RCTL: case KC_LCMD: case KC_RCMD:
                case KC_LALT: case KC_RALT: case KC_LSFT: case KC_RSFT:
                    *retval = class_colors[_MOD];
                    break;
                case KC_BTN1: case KC_BTN2: case KC_BTN3: case KC_BTN4:
                case KC_BTN5: case KC_BTN6: case KC_BTN7: case KC_BTN8:
                    *retval = class_colors[_MOUSE];
                    break;
                default:
                    *retval = class_colors[_OFF];
                    break;
            }
            break;
        default:
            *retval = class_colors[_OFF];
            break;
    }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const uint8_t layer = get_highest_layer(layer_state);
    // Perform the underglow.
    const layer_color_set_t l_color = layer_colors[layer];
    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            SET_COLOR(i, l_color.underglow);
        }
    }

    // Set the key colors.
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t i = g_led_config.matrix_co[row][col];
            if (i < led_min || i > led_max || i == NO_LED) {
                continue;
            }

            RGB color;
            determine_key_color(&color, MAKE_KEYPOS(row, col), layer);
            SET_COLOR(i, color);
        }
    }
}
