// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum tap_dance_codes {
  D_1,
  D_2,
  D_3,
};

enum layer_names {
  _Letters=0,
  _Digits=1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,------------------------------------------------++------+-----------------------------------------.
 * | Esc  |  Q   |  W   |  E   |  R   |  T   | =(+) ||   (  |  Y   |  U   |  I   | O(() | P()) |      |
 * |------+------+------+------+------+-------------++------|------+------+------+------+------+------|
 * | TAB  |  A   |  S   |  D   |  F   |  G   | -(_) ||   }  |  H   |  J   |  K   |  L   |  ;   |  "   |
 * |------+------+------+------+------+------|------++-------------+------+------+------+------+------|
 * | Shift|  Z   |  X   |  C   |  V   |  B   |      ||Layer1|  N   |  M   |  ,   |  .   |  /   |      |
 * |------+------+------+------+------+------+------++------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |      |      | SPACE|      ||      |Enter | Left |  Up  | Down |Right | BSPC |
 * `------------------------------------------------++------+-----------------------------------------'
 */
 [_Letters] = LAYOUT(
    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_EQUAL,     
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINUS, 
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_A, 
    KC_LCTL, KC_LALT, KC_LGUI, KC_A,    KC_A,    KC_SPC,  KC_A,

    KC_A,    TD(D_1),TD(D_2),    KC_I,    KC_U,    KC_Y,   SFT_T(KC_9),
    KC_QUOT, KC_SCLN,    KC_L,    KC_K,    KC_J,    KC_H,   KC_LEFT_BRACKET,
    KC_A,    KC_SLSH,    KC_DOT,  KC_COMM, KC_M,    KC_N,   TO(1),
    KC_BSPC, KC_RGHT,    KC_DOWN, KC_UP,   KC_LEFT, KC_ENT, KC_A
  ),
/*
 * ,------------------------------------------------++------+-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |      ||      |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------++------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------++-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |Layer0||      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------++------+------+------+------+------+------+------|
 * |      |      |      |      |      |SPACE |      ||      |Enter |      |      |      |      | BSPC |
 * `------------------------------------------------++------+-----------------------------------------'
 */
 [_Digits] = LAYOUT(
    KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,   
    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(0),
    KC_TRNS,  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,
                                                           
    KC_TRNS,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_NO,
    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_O:
            if (record->tap.count && record->event.pressed) { 
                register_code(keycode); // tap
            } else if(record->event.pressed) {
                tap_code16(KC_8);    // hold
            }
            return false;        
            break;
        case KC_P:
            if (!record->tap.count && record->event.pressed) { // hold
                tap_code16(KC_9); 
                return false;        // Return false to ignore further processing of key
            } 
            break;
        case SFT_T(KC_9):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(SFT_T(KC_LEFT_BRACKET)); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            } 
            break;
    }
    return true;
}

extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

void on_dance_1(tap_dance_state_t  *state, void *user_data);
uint8_t dance_1_dance_step(tap_dance_state_t  *state);
void dance_1_finished(tap_dance_state_t  *state, void *user_data);
void dance_1_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_1(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_P);
		tap_code16(KC_P);
	}
	if(state->count > 2) {
		tap_code16(KC_P);
	}
}

uint8_t dance_1_dance_step(tap_dance_state_t  *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) 
      return SINGLE_TAP;
		else 
      return SINGLE_HOLD;
	} 
  // else if (state->count == 2) {
	// 	if (state->interrupted) return DOUBLE_SINGLE_TAP;
	// 	else if (state->pressed) return DOUBLE_HOLD;
	// 	else return DOUBLE_TAP;
	// }
	return MORE_TAPS;
}
void dance_1_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_1_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_P); break;
		case SINGLE_HOLD: register_code16(S(KC_0)); break;
		// case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
		// case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
	}
}

void dance_1_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_P); break;
		case SINGLE_HOLD: unregister_code16(S(KC_0)); break;
		// case DOUBLE_TAP: unregister_code16(KC_0); break;
		// case DOUBLE_SINGLE_TAP: unregister_code16(KC_0); break;
	}
	dance_state.step = 0;
}


void on_dance_2(tap_dance_state_t  *state, void *user_data);
uint8_t dance_2_dance_step(tap_dance_state_t  *state);
void dance_2_finished(tap_dance_state_t  *state, void *user_data);
void dance_2_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_2(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_O);
		tap_code16(KC_O);
	}
	if(state->count > 2) {
		tap_code16(KC_O);
	}
}

uint8_t dance_2_dance_step(tap_dance_state_t  *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) 
      return SINGLE_TAP;
		else 
      return SINGLE_HOLD;
	} 

	return MORE_TAPS;
}
void dance_2_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_2_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_O); break;
		case SINGLE_HOLD: register_code16(S(KC_9)); break;
	}
}

void dance_2_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_O); break;
		case SINGLE_HOLD: unregister_code16(S(KC_9)); break;
	}
	dance_state.step = 0;
}


tap_dance_action_t  tap_dance_actions[] = {
        [D_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [D_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
