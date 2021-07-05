/* Copyright 2018 Yiancar
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

enum custom_keycodes {
    KC_P00 = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_5x4(
        KC_BSPC, KC_SLSH, KC_PAST, KC_PMNS, \
        KC_7, KC_8, KC_9, KC_EQL, \
        KC_4, KC_5, KC_6, KC_PPLS, \
        KC_1, KC_2, KC_3, KC_LSFT, \
        KC_0, MO(1), KC_DOT, KC_ENT \
  ),

  [1] = LAYOUT_ortho_5x4(
        KC_NO, KC_NO, KC_NO, RESET, \
        KC_NO, KC_UP, KC_NO, KC_NO, \
        KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, \
        KC_NO, KC_NO, KC_NO, KC_NO, \
        KC_NO, KC_TRNS, KC_NO, KC_NO \
  ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case KC_P00:
                // types Numpad 0 twice
                SEND_STRING(SS_TAP(X_KP_0) SS_TAP(X_KP_0));
                return false;
        }
    }
    return true;
};

void led_set_user(uint8_t usb_led) {

}

// Backlight code

//Color definition
#define rgblight_set_blue        rgblight_setrgb (0,  0, 255);
#define rgblight_set_green       rgblight_setrgb (0,  255, 0);
#define rgblight_set_purple      rgblight_setrgb (200,  0, 200);
#define rgblight_set_yellow      rgblight_setrgb (255,  255, 0);
#define rgblight_set_orange      rgblight_setrgb (255,  50, 0);
#define rgblight_set_red         rgblight_setrgb (255,  0, 0);

uint32_t layer_state_set_user(uint32_t  state) {
    switch (biton32(state)) {
    case 0:
        rgblight_set_blue;
        break;
    case 1:
        rgblight_set_red;
        break;
    default:
        rgblight_set_blue;
       break;
    }
  return state;
};

void keyboard_post_init_user(void) {
    layer_state_set_user(layer_state);
}
