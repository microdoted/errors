/* Copyright 2018 Yuki Rea <null-src.com>
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

#define led_on_helper(port, pin) DDR ## port |=  (1<<pin); PORT ## port |=  (1<<pin)
#define led_on(x) led_on_helper(x)
#define led_off_helper(port, pin) DDR ## port &=  ~(1<<pin); PORT ## port &=  ~(1<<pin)
#define led_off(x) led_off_helper(x)

// LED pin definition 
#define num_led		B,5
#define caps_led	D,7

enum custom_keycodes {
  DLP_SIG = SAFE_RANGE,
  DLP_PRT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DLP_SIG:
      if (record->event.pressed) {
        // when keycode DLP_SIG is pressed
        SEND_STRING("Thanks from Microdoted");
      } else {
        // when keycode DLP_SIG is released
      }
      break;
    case DLP_PRT:
      if (record->event.pressed) {
        // when keycode DLP_PRT is pressed
		SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)SS_TAP(X_S)SS_UP(X_LSFT)SS_UP(X_LGUI));
      } else {
        // when keycode DLP_PRT is released
      }
      break;
  }
  return true;
};

#define DLP_CONV LCTL(LALT(KC_EQL))

#include "eeprom.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC,          DLP_SIG,  KC_F2,  KC_F3,  KC_F4,     KC_F5,  KC_F6,  KC_F7,  KC_F8,     KC_F9,  KC_F10,  KC_F11,  KC_F12,   DLP_PRT,DLP_CONV,KC_CALC,  
    KC_GRV,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_JYEN,KC_BSPC,   KC_INS, KC_HOME,KC_PGUP,   KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,                   KC_DEL, KC_END, KC_PGDN,   KC_P7,  KC_P8,  KC_P9,  
    KC_CAPS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_BSLS,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,  KC_PPLS,  
    KC_LSFT,KC_TRNS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RO,          KC_RSFT,           KC_UP,             KC_P1,  KC_P2,  KC_P3,  
    KC_LALT,KC_LGUI,KC_LCTL,KC_TRNS,            KC_TRNS,KC_SPC,KC_TRNS,             KC_TRNS,KC_RCTL,KC_RGUI,MO(1),KC_RALT,   KC_LEFT,KC_DOWN,KC_RGHT,   KC_P0,          KC_PDOT,KC_PENT
),
  [1] = LAYOUT(
	KC_ESC,          KC_F1,  KC_F2,  KC_F3,  KC_F4,     KC_F5,  KC_F6,  KC_F7,  KC_F8,     KC_F9,  KC_F10,  KC_F11,  KC_F12,   KC_PSCR,DLP_CONV,KC_PAUS,  
    KC_GRV,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_JYEN,KC_BSPC,   KC_INS, KC_HOME,KC_PGUP,   KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,                   KC_DEL, KC_END, KC_PGDN,   KC_P7,  KC_P8,  KC_P9,  
    KC_CAPS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_BSLS,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,  KC_PPLS,  
    KC_LSFT,KC_TRNS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RO,          KC_RSFT,           KC_UP,             KC_P1,  KC_P2,  KC_P3,  
    KC_LALT,KC_LGUI,KC_LCTL,KC_TRNS,            KC_TRNS,KC_SPC,KC_TRNS,             KC_TRNS,KC_RCTL,KC_RGUI,KC_TRNS,KC_RALT,   KC_LEFT,KC_DOWN,KC_RGHT,   KC_P0,          KC_PDOT,KC_PENT
),
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {
	if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
		led_on(caps_led);
	}
	else {
		led_off(caps_led);
	}

	if (usb_led & (1<<USB_LED_NUM_LOCK)) {
		led_on(num_led);
	}
	else {
		led_off(num_led);
	}
}
