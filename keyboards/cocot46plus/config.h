/*
Copyright 2022 aki27

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

#ifndef __ASSEMBLER__
#include "config_common.h"
#include "apidef.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x1727
#define PRODUCT_ID   0x0003
#define DEVICE_VER   0x0001
#define MANUFACTURER aki27
#define PRODUCT      cocot46plus
#define DESCRIPTION  A custom keyboard
#define BMP_BOOTPIN_AS_RESET
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200
#define COMBO_COUNT 32
/* key matrix size */
#define MATRIX_ROWS_DEFAULT 10
#define MATRIX_COLS_DEFAULT 6
#define THIS_DEVICE_ROWS 5
#define THIS_DEVICE_COLS 12
#define IS_LEFT_HAND  true
#define BMP_DEFAULT_MODE SINGLE
#define CONFIG_RESERVED {0, 0, 1, 0, 0, 0, 0, 0}
// wiring of each half
#define MATRIX_ROW_PINS {  7,  8,  9, 10,  5 }
#define MATRIX_COL_PINS { 20, 19, 18, 17, 16, 15 }
#define MATRIX_LAYOUT \
    { 1,  2,  3,  4,  5,  6,             36, 35, 34, 33, 32, 31,    0, \
      7,  8,  9, 10, 11, 12,             42, 41, 40, 39, 38, 37,    0, \
     13, 14, 15, 16, 17, 18,             48, 47, 46, 45, 44, 43,    0, \
             19, 20, 21, 22,  24,   54,  52, 51, 50, 49,            0, \
                              27,23,30,  57, 53, 60,               255}
#define KEYMAP_PRIOR_LOCALE 0
#define KEYMAP_ASCII 0
#define DEBUG_ACTION
#define DEBOUNCE 1
#define DIODE_DIRECTION COL2ROW // MATRIX_COL2ROW2COL

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGBLIGHT_SPLIT
#define G00 255 // Dummy for bin/qmk config generation
#define RGB_DI_PIN G00
#ifdef RGB_DI_PIN
    #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
    #define RGBLIGHT_ANIMATIONS
    /* select individual effect 
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_TWINKLE
    */

    #define RGBLED_NUM_DEFAULT 12
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define ADNS5050_SCLK_PIN         14
#define ADNS5050_SDIO_PIN         11
#define ADNS5050_CS_PIN           12

#define POINTING_DEVICE_ROTATION_180
#define OLED_FONT_H "keyboards/cocot46plus/glcdfont.c"

#endif /*__ASSEMBLER__*/
