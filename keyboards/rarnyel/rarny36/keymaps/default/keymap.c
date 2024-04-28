/*
Copyright 2024 Ramy Elabbadi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "config.h"

#ifdef BONGO_ENABLE
#include "bongo.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,               KC_Y,         KC_U,           KC_I,             KC_O,           KC_P, 
        LCTL_T(KC_A),   LSFT_T(KC_S),   LALT_T(KC_D),   LGUI_T(KC_F),   KC_G,               KC_H,         KC_J,           RALT_T(KC_K),     RSFT_T(KC_L),   RCTL_T(KC_SCLN), 
        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,               KC_N,         KC_M,           KC_COMM,          KC_DOT,         KC_SLSH, 
                                        KC_ESC,         KC_SPC,         LT(1,KC_ENT),       LT(2,KC_TAB), KC_SPC,         KC_BSPC
    ),
    [1] = LAYOUT_split_3x5_3(
        KC_1,       KC_2,       KC_3,       KC_4,       KC_5,           KC_6,       KC_7,       KC_8,       KC_9,       KC_0, 
        KC_LCTL,    KC_LSFT,    DF(1),      KC_MINS,    KC_BSPC,        KC_LEFT,    KC_UP,      KC_DOWN,    KC_RGHT,    KC_RSFT, 
        KC_NUBS,    KC_COMM,    KC_DOT,     KC_EQL,     KC_ENT,         KC_QUOT,    KC_NO,      KC_NO,      KC_LBRC,    KC_RBRC, 
                                KC_NO,      DF(0),      KC_NO,          KC_TAB,     KC_SPC,     KC_DEL
    ),
    [2] = LAYOUT_split_3x5_3(
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10, 
        KC_GRV,     KC_NO,      DF(2),      KC_NO,      KC_SLEP,    KC_CAPS,    KC_PGUP,    KC_PGDN,    KC_F11,     KC_F12, 
        KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MPLY,    KC_NO,      KC_NO,      KC_HOME,    KC_END,     KC_BRID,    KC_BRIU, 
                                KC_NO,      DF(0),      KC_NO,      KC_NO,      KC_NO,      KC_NO
    )
};


#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    // draw_bongo(false);
    return false;
}

#endif