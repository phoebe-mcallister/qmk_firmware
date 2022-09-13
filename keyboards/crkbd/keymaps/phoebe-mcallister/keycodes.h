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

#define ZSFT LSFT_T(KC_Z)
#define SLSHFT RSFT_T(KC_SLSH)
#define CMDCLK LCMD_T(KC_BTN1)
#define CTLUP LCTL(KC_UP)
#define CTLLEFT LCTL(KC_LEFT)
#define CTLRGHT LCTL(KC_RGHT)

#define VSYM LT(_SYM, KC_V)
#define MSYM LT(_SYM, KC_M)
#define HSYM LT(_SYM, KC_H)
#define DSYM LT(_SYM, KC_D)
#define JSYM LT(_SYM, KC_J)

#define VNUM LT(_NUM, KC_V)
#define BNUM LT(_NUM, KC_B)

#define XARR LT(_ARR, KC_X)

enum crkbd_layers {
    _QWERTY,
    _ZER,
    _ONE,
    _TWO,
    _TRE,
    _FOR,
    _COL,
    _SYM,
    _ARR,
    _NUM
};