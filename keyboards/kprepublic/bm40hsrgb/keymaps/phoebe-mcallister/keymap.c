/* Copyright 2020 tominabox1
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

enum layers {
  _QWERTY,
  _SYM,
  _NUM,
  _ARR
};

#define MSYM LT(_SYM, KC_M)
#define VSYM LT(_SYM, KC_V)
#define BNUM LT(_NUM, KC_B)
#define XARR LT(_ARR, KC_X)

#define CTLUP LCTL(KC_UP)
#define CTLLEFT LCTL(KC_LEFT)
#define CTLRGHT LCTL(KC_RGHT)

#define ZSFT LSFT_T(KC_Z)
#define SLSHFT RSFT_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
    XXXXXXX, ZSFT,    XARR,    KC_C,    VSYM,    BNUM,    KC_N,    MSYM,    KC_COMM, KC_DOT,  SLSHFT,  XXXXXXX,
    XXXXXXX, KC_LCTL, KC_LALT, KC_LCMD, KC_BTN1,      KC_SPC,      KC_BSPC, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX
),
[_SYM] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, XXXXXXX, KC_RBRC, KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, KC_BTN2,      _______,     _______, _______, _______, _______, _______
),
[_ARR] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_ESC,  XXXXXXX, XXXXXXX, KC_TAB,  KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_F12,
    _______, KC_LSFT, XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, KC_GRV,  KC_EQL,  KC_BSLS, KC_MINS, KC_ENT,  _______,
    _______, _______, _______, _______, KC_ENT,       _______,     _______, _______, _______, _______, _______
),
[_NUM] = LAYOUT_ortho_4x12_1x2uC(
    QK_BOOT, KC_VOLD, KC_VOLU, RGB_TOG, KC_BRID, KC_BRIU, KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______,
    _______, CTLUP,   XXXXXXX, XXXXXXX, KC_TAB,  KC_CAPS, KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______,
    _______, CTLLEFT, CTLRGHT, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, _______,
    _______, _______, _______, _______, KC_BTN2,      KC_KP_0,     _______, _______, _______, _______, _______
)
};

