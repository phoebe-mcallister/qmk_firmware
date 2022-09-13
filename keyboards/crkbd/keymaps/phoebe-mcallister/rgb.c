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

const uint8_t PROGMEM rgb_class_maps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  I_CAPS,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,REF_LYR(_ZER),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,    _OFF,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR,REF_LYR(_ARR),USE_LYR,REF_LYR(_SYM),REF_LYR(_NUM),   USE_LYR,REF_LYR(_SYM), USE_LYR, USE_LYR, USE_LYR,    _OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KEYBASE, KEYBASE, KEYBASE,    KEYBASE, KEYBASE, KEYBASE
                                      //`--------------------------'  `--------------------------'    
    ),
    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE, _NUMBER, _NUMBER, _NUMBER, _NUMBER, _NUMBER,                      _NUMBER, _NUMBER, _NUMBER, _NUMBER, _NUMBER,    _OFF,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,    _OFF,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE,                      USE_LYR, KEYBASE, USE_LYR, USE_LYR, USE_LYR,    _OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _SPACE,    _MOD,  _MOUSE,     _SPACE, _DELETE,  _ENTER
                                      //`--------------------------'  `--------------------------'    
    ),
    [_ARR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE,   _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,                        _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,   _FUNC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, KEYBASE, KEYBASE, KEYBASE,     SYM,  I_CAPS,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR,     SYM,   _FUNC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE, KEYBASE,                          SYM,     SYM,     SYM,     SYM,  _ENTER,    _OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _SPACE,    _MOD, KEYBASE,     _SPACE, _DELETE,  _ENTER
                                      //`--------------------------'  `--------------------------'    
    ),
    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE,  _MEDIA,  _MEDIA,   _BOOT,  _MEDIA,  _MEDIA,                      _NPSIDE, USE_LYR, USE_LYR, USE_LYR, _NPSIDE, KEYBASE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE,   _MOVE, KEYBASE, KEYBASE, KEYBASE, KEYBASE,                      _NPSIDE, USE_LYR, USE_LYR, USE_LYR, _NPSIDE, KEYBASE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE,   _MOVE,   _MOVE, KEYBASE, KEYBASE, KEYBASE,                      KEYBASE, USE_LYR, USE_LYR, USE_LYR, _NPSIDE, KEYBASE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _SPACE,    _MOD,  _MOUSE,    USE_LYR, _DELETE,  _ENTER
                                      //`--------------------------'  `--------------------------'    
    ),
    [_ZER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  I_CAPS,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,REF_LYR(_ONE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,    _OFF,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR,REF_LYR(_ARR),USE_LYR,REF_LYR(_SYM),REF_LYR(_NUM),   USE_LYR,REF_LYR(_SYM), USE_LYR, USE_LYR, USE_LYR,    _OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KEYBASE, KEYBASE, KEYBASE,    KEYBASE, KEYBASE, KEYBASE
                                      //`--------------------------'  `--------------------------'    
    ),
    [_ONE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  I_CAPS,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,REF_LYR(_TWO),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,    _OFF,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR,REF_LYR(_ARR),USE_LYR,REF_LYR(_SYM),REF_LYR(_NUM),   USE_LYR,REF_LYR(_SYM), USE_LYR, USE_LYR, USE_LYR,    _MOD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KEYBASE, KEYBASE, KEYBASE,    KEYBASE, KEYBASE, KEYBASE
                                      //`--------------------------'  `--------------------------'    
    ),
    [_TWO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  I_CAPS,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,REF_LYR(_TRE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,    _MOD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR,REF_LYR(_ARR),USE_LYR,REF_LYR(_SYM),REF_LYR(_NUM),   USE_LYR,REF_LYR(_SYM), USE_LYR, USE_LYR, USE_LYR,    _OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KEYBASE, KEYBASE, KEYBASE,    KEYBASE, KEYBASE, KEYBASE
                                      //`--------------------------'  `--------------------------'    
    ),
    [_TRE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  I_CAPS,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,REF_LYR(_FOR),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,    _MOD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR,REF_LYR(_ARR),USE_LYR,REF_LYR(_SYM),REF_LYR(_NUM),   USE_LYR,REF_LYR(_SYM), USE_LYR, USE_LYR, USE_LYR,    _MOD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KEYBASE, KEYBASE, KEYBASE,    KEYBASE, KEYBASE, KEYBASE
                                      //`--------------------------'  `--------------------------'    
    ),
    [_FOR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  I_CAPS,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,REF_LYR(_COL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,    _OFF,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR,REF_LYR(_ARR),USE_LYR,REF_LYR(_SYM),REF_LYR(_NUM),   USE_LYR,REF_LYR(_SYM), USE_LYR, USE_LYR, USE_LYR,  _ENTER,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KEYBASE, KEYBASE, KEYBASE,    KEYBASE, KEYBASE, KEYBASE
                                      //`--------------------------'  `--------------------------'    
    ),
    [_COL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  I_CAPS,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,REF_LYR(_QWERTY),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,                      USE_LYR, USE_LYR, USE_LYR, USE_LYR, USE_LYR,  _ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KEYBASE, USE_LYR,REF_LYR(_ARR),USE_LYR,REF_LYR(_SYM),REF_LYR(_NUM),   USE_LYR,REF_LYR(_SYM), USE_LYR, USE_LYR, USE_LYR,  _ENTER,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KEYBASE, KEYBASE, KEYBASE,    KEYBASE, KEYBASE, KEYBASE
                                      //`--------------------------'  `--------------------------'    
    )
};

void determine_key_color(RGB* retval, const keypos_t pos, const uint8_t layer) {
    const uint8_t rgb_code = rgb_class_maps[layer][pos.row][pos.col];
    const uint16_t keycode = keymap_key_to_keycode(layer, pos);
    if (IS_CLASS(rgb_code)) {
        *retval = class_colors[GET_BODY(rgb_code)];
    } else if (IS_LAYER(rgb_code)) {
        *retval = layer_colors[layer].keyglow;
    } else if (IS_REFERNCE(rgb_code)) {
        *retval = layer_colors[GET_BODY(rgb_code)].keyglow;
    } else if (IS_KEYBASED(rgb_code)) {
        switch(keycode) {
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
    } else if (IS_INDICATOR_KEY(rgb_code)) {
        if (GET_BODY(rgb_code) == _CAPS_IND && host_keyboard_led_state().caps_lock) {
            *retval = class_colors[_BOOT];
        } else {
            *retval = layer_colors[layer].keyglow;
        }
    } else {
        *retval = class_colors[_OFF];
    }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const uint8_t layer = get_highest_layer(layer_state | default_layer_state);
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
