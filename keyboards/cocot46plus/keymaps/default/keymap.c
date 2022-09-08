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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"

enum cocot_keycodes {

    COCOT_SAFE_RANGE = SAFE_RANGE,
    CPI_SW,
    SCRL_SW,
    ROT_R15,
    ROT_L15,
    SCRL_MO,
    SCRL_TO,
    SCRL_IN,

};

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3
};


#define LW_MHEN LT(1,KC_MHEN)  // lower
#define RS_HENK LT(2,KC_HENK)  // raise
#define DEL_ALT ALT_T(KC_DEL)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT,   LW_MHEN,  KC_SPC, KC_MS_BTN1,             KC_MS_BTN2,  KC_ENT, RS_HENK, KC_BSPC,  KC_ESC,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_LOWER] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_COLN, KC_DQUO,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,  KC_GRV, KC_TILD, KC_NUBS, KC_PIPE, XXXXXXX,                                        KC_EQL, KC_PLUS, KC_LABK, KC_RABK, KC_QUES, KC_UNDS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT, KC_TRNS,  KC_SPC,   KC_MS_BTN4,             KC_MS_BTN5,  KC_ENT,   TT(3), KC_BSPC,  KC_ESC,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_RAISE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,   KC_0,  KC_BSPC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_APP,   KC_UP,S(KC_RO), KC_UNDS, KC_DQUO, KC_COLN,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                       KC_LEFT, KC_DOWN, KC_RGHT,  KC_DOT, KC_SLSH, KC_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT,   TT(3),  KC_SPC,   KC_MS_BTN4,             KC_MS_BTN5,  KC_ENT, KC_TRNS, KC_BSPC,  KC_ESC,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_TRACKBALL] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                                       SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, DEL_ALT, KC_TRNS,  KC_SPC,   KC_MS_BTN1,             KC_MS_BTN2,  KC_ENT, RS_HENK, KC_BSPC,  KC_ESC,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDOWN, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    )
};



typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_idx;
        uint8_t scrl_div;
        uint8_t rotation_angle;
        int8_t scrl_inv;
        bool scrl_mode;
        report_mouse_t last_mouse;
    };
} cocot_config_t;


extern cocot_config_t cocot_config;


bool cocot_get_scroll_mode(void) {
    return cocot_config.scrl_mode;
}

void cocot_set_scroll_mode(bool mode) {
    cocot_config.scrl_mode = mode;
}


// Invert vertical scroll direction
#ifndef COCOT_SCROLL_INV_DEFAULT
#    define COCOT_SCROLL_INV_DEFAULT 1
#endif

#ifndef COCOT_CPI_OPTIONS
#    define COCOT_CPI_OPTIONS { 250, 500, 750, 1000, 1250 }
#    ifndef COCOT_CPI_DEFAULT
#       define COCOT_CPI_DEFAULT 4
#    endif
#endif
#ifndef COCOT_CPI_DEFAULT
#    define COCOT_CPI_DEFAULT 4
#endif

#ifndef COCOT_SCROLL_DIVIDERS
#    define COCOT_SCROLL_DIVIDERS { 1, 2, 3, 4, 5, 6 }
#    ifndef COCOT_SCROLL_DIV_DEFAULT
#       define COCOT_SCROLL_DIV_DEFAULT 4
#    endif
#endif
#ifndef COCOT_SCROLL_DIV_DEFAULT
#    define COCOT_SCROLL_DIV_DEFAULT 4
#endif


#ifndef COCOT_ROTATION_ANGLE
#    define COCOT_ROTATION_ANGLE { -60, -45, -30, -15, 0, 15, 30, 45, 60 }
#    ifndef COCOT_ROTATION_DEFAULT
#       define COCOT_ROTATION_DEFAULT 2
#    endif
#endif
#ifndef COCOT_ROTATION_DEFAULT
#    define COCOT_ROTATION_DEFAULT 2
#endif


cocot_config_t cocot_config;
uint16_t cpi_array[] = COCOT_CPI_OPTIONS;
uint16_t scrl_div_array[] = COCOT_SCROLL_DIVIDERS;
uint16_t angle_array[] = COCOT_ROTATION_ANGLE;
#define CPI_OPTION_SIZE (sizeof(cpi_array) / sizeof(uint16_t))
#define SCRL_DIV_SIZE (sizeof(scrl_div_array) / sizeof(uint16_t))
#define ANGLE_SIZE (sizeof(angle_array) / sizeof(uint16_t))


void eeconfig_init_user(void) {
    cocot_config.cpi_idx = COCOT_CPI_DEFAULT;
    cocot_config.scrl_div = COCOT_SCROLL_DIV_DEFAULT;
    cocot_config.rotation_angle = COCOT_ROTATION_DEFAULT;
    cocot_config.scrl_inv = COCOT_SCROLL_INV_DEFAULT;
    cocot_config.scrl_mode = false;
    eeconfig_update_user(cocot_config.raw);
}


void matrix_init_user(void) {
    // is safe to just read CPI setting since matrix init
    // comes before pointing device init.
    cocot_config.raw = eeconfig_read_user();
    if (cocot_config.cpi_idx > CPI_OPTION_SIZE) // || cocot_config.scrl_div > SCRL_DIV_SIZE || cocot_config.rotation_angle > ANGLE_SIZE)
    {
        eeconfig_init_user();
    }
}


layer_state_t layer_state_set_user(layer_state_t state) {

#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        break;
    case _RAISE:
        rgblight_sethsv_range(HSV_RED, 0, 2);
        break;
    case _TRACKBALL:
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        break;
    default:
        rgblight_sethsv_range(HSV_OFF, 0, 2);
        break;
    }
    rgblight_set_effect_range( 2, 10);
#endif

#ifdef POINTING_DEVICE_ENABLE
    switch (get_highest_layer(state)) {
    case _LOWER:
    case _RAISE:
        cocot_set_scroll_mode(true);
        break;
    default:
        cocot_set_scroll_mode(false);
        break;
    }
#endif

    return state;
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);

    switch (keycode) {
#if defined(MOUSEKEY_ENABLE) || defined(POINTING_DEVICE_ENABLE)
        // process KC_MS_BTN1~8 by myself
        // See process_action() in quantum/action.c for details.
        case KC_MS_BTN1 ... KC_MS_BTN8: {
            extern void register_button(bool, enum mouse_buttons);
            register_button(record->event.pressed, MOUSE_BTN_MASK(keycode - KC_MS_BTN1));
            return false;
        }
#endif
    }

#ifdef POINTING_DEVICE_ENABLE
    if (keycode == CPI_SW && record->event.pressed) {
        cocot_config.cpi_idx = (cocot_config.cpi_idx + 1) % CPI_OPTION_SIZE;
        eeconfig_update_user(cocot_config.raw);
        pointing_device_set_cpi(cpi_array[cocot_config.cpi_idx]);
    }

    if (keycode == SCRL_SW && record->event.pressed) {
        cocot_config.scrl_div = (cocot_config.scrl_div + 1) % SCRL_DIV_SIZE;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == ROT_R15 && record->event.pressed) {
        cocot_config.rotation_angle = (cocot_config.rotation_angle + 1) % ANGLE_SIZE;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == ROT_L15 && record->event.pressed) {
        cocot_config.rotation_angle = (ANGLE_SIZE + cocot_config.rotation_angle - 1) % ANGLE_SIZE;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == SCRL_IN && record->event.pressed) {
        cocot_config.scrl_inv = - cocot_config.scrl_inv;
        eeconfig_update_user(cocot_config.raw);
    }

    if (keycode == SCRL_TO && record->event.pressed) {
        { cocot_config.scrl_mode ^= 1; }
    }

    if (keycode == SCRL_MO) {
        { cocot_config.scrl_mode ^= 1; }
    }
#endif

    return true;
}



#ifdef POINTING_DEVICE_ENABLE

// Scroll Accumulation
static int16_t h_acm       = 0;
static int16_t v_acm       = 0;


void pointing_device_init_user(void) {
    // set the CPI.
    pointing_device_set_cpi(cpi_array[cocot_config.cpi_idx]);
}


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    double rad = angle_array[cocot_config.rotation_angle] * (M_PI / 180) * -1;
    int8_t x_rev =  + mouse_report.x * cos(rad) - mouse_report.y * sin(rad);
    int8_t y_rev =  + mouse_report.x * sin(rad) + mouse_report.y * cos(rad);

    if (cocot_get_scroll_mode()) {
        // rock scroll direction
        if (abs(x_rev) > abs(y_rev)) {
            y_rev = 0;
        } else {
            x_rev = 0;
        }

        // accumulate scroll
        h_acm += x_rev * cocot_config.scrl_inv;
        v_acm += y_rev * cocot_config.scrl_inv * -1;

        int8_t h_rev = h_acm >> scrl_div_array[cocot_config.scrl_div];
        int8_t v_rev = v_acm >> scrl_div_array[cocot_config.scrl_div];

        // clear accumulated scroll on assignment

        if (h_rev != 0) {
            if (mouse_report.h + h_rev > 127) {
                h_rev = 127 - mouse_report.h;
            } else if (mouse_report.h + h_rev < -127) {
                h_rev = -127 - mouse_report.h;
            }
            mouse_report.h += h_rev;
            h_acm -= h_rev << scrl_div_array[cocot_config.scrl_div];
        }
        if (v_rev != 0) {
            if (mouse_report.v + v_rev > 127) {
                v_rev = 127 - mouse_report.v;
            } else if (mouse_report.v + v_rev < -127) {
                v_rev = -127 - mouse_report.v;
            }
            mouse_report.v += v_rev;
            v_acm -= v_rev << scrl_div_array[cocot_config.scrl_div];
        }

        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        mouse_report.x = x_rev;
        mouse_report.y = y_rev;
    }

    return mouse_report;
}
#endif


#ifdef ENCODER_ENABLE

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }

    return true;
}


void matrix_scan_user(void) {

    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

}
#endif


// OLED utility
#ifdef OLED_ENABLE

static const char PROGMEM cocot_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4,
    0};

void render_logo(void) {
    oled_write_P(cocot_logo, false);
};

void oled_write_layer_state(void) {

    oled_write_P(PSTR(" "), false);
    // int cpi = pointing_device_get_cpi();
    int cpi = cpi_array[cocot_config.cpi_idx];
    int scroll_div = scrl_div_array[cocot_config.scrl_div];
    int angle = angle_array[cocot_config.rotation_angle];

    char buf1[5];
    char buf2[3];
    char buf3[4];
    snprintf(buf1, 5, "%4d", cpi);
    snprintf(buf2, 3, "%2d", scroll_div);
    snprintf(buf3, 4, "%3d", angle);

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            oled_write_P(PSTR("Base "), false);
            break;
        case 1:
            oled_write_P(PSTR("Lower"), false);
            break;
        case 2:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 3:
            oled_write_P(PSTR("Mouse"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
            break;
    }
    oled_write_P(PSTR("/"), false);
    if (cocot_get_scroll_mode()){
        oled_write_P(PSTR("S"), false);
    } else{
        oled_write_P(PSTR("C"), false);
    }
    oled_write_P(PSTR("/"), false);
    oled_write(buf1, false);
    oled_write_P(PSTR("/"), false);
    oled_write(buf2, false);
    oled_write_P(PSTR("/"), false);
    oled_write(buf3, false);
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}


bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}

#endif
