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
        KC_LCTL,    KC_LSFT,    DF(1),      KC_MINS,    KC_BSPC,        KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,     KC_RSFT, 
        KC_NUBS,    KC_COMM,    KC_PDOT,    KC_EQL,     KC_ENT,         KC_GRV,     KC_NUHS,    KC_QUOT,    KC_LBRC,    KC_RBRC, 
                                KC_NO,      DF(0),      KC_NO,          KC_TAB,     KC_SPC,     KC_DEL
    ),
    [2] = LAYOUT_split_3x5_3(
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10, 
        KC_F11,     KC_F12,     DF(2),      KC_NO,      KC_SLEP,    KC_LEFT,    KC_UP,      KC_DOWN,    KC_LEFT,    KC_CAPS, 
        KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MPLY,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_BRID,    KC_BRIU, 
                                KC_NO,      DF(0),      KC_NO,      KC_NO,      KC_NO,      KC_NO
    )
};


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    draw_bongo(true);
    return false;
}

#endif