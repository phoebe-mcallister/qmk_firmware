/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MASTER_LEFT
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_FULL_DUPLEX
#undef SOFT_SERIAL_PIN

// Flashable Split Pins
#define SPLIT_USB_DETECT
#define SERIAL_USART_PIN_SWAP 
#define SERIAL_USART_TX_PIN GP3
#define SERIAL_USART_RX_PIN GP2

// Generic pins
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS \
    { GP4, GP5, GP6, GP7 }

#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS \
    { GP29, GP28, GP27, GP26, GP18, GP20 }

#undef RGB_DI_PIN
#define RGB_DI_PIN      GP0

#define WS2812_PIO_USE_PIO1
#define SPLIT_LAYER_STATE_ENABLE
