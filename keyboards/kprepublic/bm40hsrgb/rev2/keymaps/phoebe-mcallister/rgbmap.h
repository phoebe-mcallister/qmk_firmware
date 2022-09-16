/* Copyright 2022 phoebe-mcallister
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

#pragma once

#define FLAG_CLASS (0x80)
#define FLAG_LAYER (0x40)
#define FLAG_INDICATOR (0x20)
#define NO_FLAG (0x00)
#define ALL_FLAG (FLAG_CLASS|FLAG_LAYER|FLAG_INDICATOR)

#define TYPE_CLASS (NO_FLAG)
#define TYPE_REFERENCE (FLAG_CLASS)
#define TYPE_KEYBASE (FLAG_CLASS|FLAG_LAYER)
#define TYPE_LAYER (FLAG_LAYER)
#define TYPE_INDICATOR (FLAG_INDICATOR)

#define GET_BODY(code) ((code) & (~ALL_FLAG))
#define GET_TYPE(code) ((code) & ALL_FLAG)

#define KEYBASE (TYPE_KEYBASE)
#define USE_LYR (FLAG_LAYER)
#define REF_LYR(l) ((GET_BODY(l))|TYPE_REFERENCE)
#define IND_KEY(l) ((GET_BODY(l))|TYPE_INDICATOR)

#define SYM REF_LYR(_SYM)
#define I_CAPS (IND_KEY(_CAPS_IND))

#define COLOR_COLEMAK_KEY {.r = 0x17, .g = 0x09, .b = 0x0A}
#define COLOR_COLEMAK_UNDER {.r = 0x5C, .g = 0x24, .b = 0x28}

#define SET_COLOR(i, rgb) rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b)

enum color_class {
    _MOUSE,
    _DELETE,
    _SPACE,
    _NUMBER,
    _MOD,
    _ENTER,
    _NPSIDE,
    _BOOT,
    _MEDIA,
    _MOVE,
    _FUNC,
    _OFF
};

enum indicator_lights {
    _CAPS_IND
};

typedef struct PACKED {
    RGB keyglow;
    RGB underglow;
} layer_color_set_t;

const layer_color_set_t layer_colors[] = {
    [_QWERTY] = {{.r = 0x1d, .g = 0x0a, .b = 0x2d}, {.r = 0x74, .g = 0x28, .b = 0xB4}},
    [_NUM] =    {{.r = 0x07, .g = 0x19, .b = 0x18}, {.r = 0x1C, .g = 0x64, .b = 0x60}},
    [_ARR] =    {{.r = 0x20, .g = 0x18, .b = 0x05}, {.r = 0x80, .g = 0x60, .b = 0x14}},
    [_SYM] =    {{.r = 0x16, .g = 0x33, .b = 0x00}, {.r = 0x58, .g = 0xCC, .b = 0x00}}
};

const RGB class_colors[] = {
    [_MOUSE] =  {.r = 0x19, .g = 0x0F, .b = 0x07},
    [_SPACE] = layer_colors[_QWERTY].keyglow,
    [_DELETE] = {.r = 0x20, .g = 0x00, .b = 0x00},
    [_MOD] =    {.r = 0x10, .g = 0x10, .b = 0x10},
    [_ENTER] =  {.r = 0x04, .g = 0x07, .b = 0x19},
    [_NPSIDE] = {.r = 0x04, .g = 0x18, .b = 0x04},
    [_MEDIA] =  {.r = 0x16, .g = 0x16, .b = 0x05},
    [_NUMBER] = {.r = 0x16, .g = 0x16, .b = 0x05},
    [_FUNC] =   {.r = 0x12, .g = 0x25, .b = 0x25},
    [_MOVE] =   {.r = 0x09, .g = 0x19, .b = 0x09},
    [_BOOT] =   {.r = 0x32, .g = 0x06, .b = 0x33},
    [_OFF] =    {.r = 0x00, .g = 0x00, .b = 0x00}
};
