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

#include "config_common.h"


#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200


/* Rotary encoder */
#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A { D3 }
    #define ENCODERS_PAD_B { D2 }
    #define ENCODER_RESOLUTION 4
#endif


/* ws2812 RGB LED */
#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN B6
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    // #define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLED_NUM 12
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

/* Track ball */
#ifdef POINTING_DEVICE_ENABLE
    #define ADNS5050_SCLK_PIN         B2
    #define ADNS5050_SDIO_PIN         B4
    #define ADNS5050_CS_PIN           B5
    #define POINTING_DEVICE_ROTATION_180
#endif

/* OLED */
#ifdef OLED_ENABLE
    #define OLED_FONT_H "keyboards/cocot46plus/glcdfont.c"
#endif
