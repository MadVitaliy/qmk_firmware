// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum zero_sixty_layers {
  _Letters=0,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
/* Qwerty
 * ,------------------------------------------------+
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |      |
 * |------+------+------+------+------+-------------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |      |
 * |------+------+------+------+------+------|-------
 * | Shift|   Z  |   X  |   C  |   V  |   B  |      |
 * |------+------+------+------+------+------+------+
 * | Ctrl | Alt  | GUI  |      |      | SPACE|      |
 * `------------------------------------------------+
 * +------+-----------------------------------------.
 * |      |   Y  |   U  |   I  |   O  |   P  | Del  |
 * -------|------+------+------+------+------+------|
 * |      |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |-------------+------+------+------+------+------|
 * |      |   N  |   M  |   ,  |   .  |   /  |      |
 * +------+------+------+------+------+------+------|
 * |      |Enter | BSPC | Left |  Up  | Down |Right |
 * +------+-----------------------------------------'
 */
 [_Letters] = LAYOUT_letters(
    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_A,     
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_A, 
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_A, 
    KC_LCTL, KC_LALT, KC_LGUI, KC_A,    KC_A,    KC_SPC,  KC_A,

    KC_A,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, 
    KC_A,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_A,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_A, 
    KC_A,    KC_ENT,  KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
  ),
};
