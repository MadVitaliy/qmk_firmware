// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum custom_keycodes {
  D_Q = SAFE_RANGE,
  D_W,
  D_E,
  D_R,
  D_T,
  D_Y,
  D_U,
  D_I,
  D_O,
  D_P,
  LAZO, 
};

enum layer_names {
  _Letters=0,
  _Numbers=1,
  _Functional=2,
  _Digits=3,
};

#define DIG MO(_Digits)
#define TAP_SFT OSM(MOD_LSFT)
#define BOUNCE_TIME 2 //ms
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,------------------------------------------------++------+-----------------------------------------.
 * | Esc  | Q(!) | W(@) | E(#) | R($) | T(%) | =(+) ||  [   | Y(^) | U(&) | I(*) | O(() | P()) |DELETE|
 * |------+------+------+------+------+-------------++------|------+------+------+------+------+------|
 * | TAB  |  A   |  S   |  D   |  F   |  G   | -(_) ||  ]   |  H   |  J   |  K   |  L   |  ;   |  "   |
 * |------+------+------+------+------+------|------++-------------+------+------+------+------+------|
 * | Shift|  Z   |  X   |  C   |  V   |  B   | Shift||Layer1|  N   |  M   |  ,   |  .   |  /   |      |
 * |------+------+------+------+------+------+------++------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |MO(d) |SPACE |      ||      |Enter | Left |  Up  | Right| Down | BSPC |
 * `------------------------------------------------++------+-----------------------------------------'
 */
 [_Letters] = LAYOUT(
    QK_GESC, TD(D_Q), TD(D_W), TD(D_E), TD(D_R), TD(D_T), KC_EQUAL,     
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINUS, 
    TAP_SFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TAP_SFT, 
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   DIG,     KC_SPC,  KC_NO,

    KC_DELETE,TD(D_P), TD(D_O), TD(D_I), TD(D_U), TD(D_Y),KC_LEFT_BRACKET,
    KC_QUOT,  KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,   KC_RIGHT_BRACKET,
    KC_NO,    KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,   TO(1),
    KC_BSPC,  KC_DOWN, KC_RGHT, KC_UP,   KC_LEFT, KC_ENT, KC_NO
  ),
/*
 * ,------------------------------------------------++------+-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  | =(+) ||  [   |   6  |   7  |   8  |   9  |   0  |DELETE|
 * |------+------+------+------+------+-------------++------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | -(_) ||  ]   |      |      |      |      |  ;   |  "   |
 * |------+------+------+------+------+------|------++-------------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |Layer0||Layer2|      |      |  ,   |  .   |  /   |      |
 * |------+------+------+------+------+------+------++------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |      |SPACE |      ||      |Enter | Left |  Up  | Down |Right | BSPC |
 * `------------------------------------------------++------+-----------------------------------------'
 */
 [_Numbers] = LAYOUT(
    KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,   
    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(0),
    KC_TRNS,  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,
                                                           
    KC_TRNS,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_NO,    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(2),
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
  ),
/*
 * ,------------------------------------------------++------+-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      ||      |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+-------------++------|------+------+------+------+------+------|
 * |      |      |      |      | M_LB | M_RB |      ||      |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------|------++-------------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |Layer0||      |      | M_A0 | M_A1 |      |      |      |
 * |------+------+------+------+------+------+------++------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |      |SPACE |      ||      |Enter | M_LT | M_UP | M_RT | M_DW | BSPC |
 * `------------------------------------------------++------+-----------------------------------------'
 */
 [_Functional] = LAYOUT(
    KC_NO,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,   
    KC_NO,    KC_NO,   KC_NO,   KC_BTN2, KC_BTN1, KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(0),
    KC_TRNS,  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,
                                                           
    KC_F11,   KC_F10,  KC_F9,   KC_F8,   KC_F7,   KC_F6,   KC_NO,
    KC_F12,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS,  KC_NO,   KC_NO,   KC_ACL1, KC_ACL0, KC_NO,   KC_NO,
    KC_TRNS,  KC_MS_D, KC_MS_R, KC_MS_U, KC_MS_L, KC_TRNS, KC_NO
  ),
/*
 * ,------------------------------------------------++------+-----------------------------------------.
 * |      |      |      |      |      |      |      ||      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------++------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------++-------------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      ||      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------++------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |      |      |      ||      |BSPC  |DELETE|      |      |      |      |
 * `------------------------------------------------++------+-----------------------------------------'
 */
 [_Digits] = LAYOUT(   
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_TRNS, KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,
                                                    
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_DELETE,  KC_BSPC,    KC_NO
  ),
};

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

uint8_t dance_step(tap_dance_state_t  *state);

uint8_t dance_step(tap_dance_state_t  *state) {
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

void on_dance_0(tap_dance_state_t  *state, void *user_data);
void dance_0_finished(tap_dance_state_t  *state, void *user_data);
void dance_0_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_0(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_Q);
		tap_code16(KC_Q);
	}
	if(state->count > 2) {
		tap_code16(KC_Q);
	}
}

void dance_0_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_Q); break;
		case SINGLE_HOLD: register_code16(S(KC_1)); break;
	}
}

void dance_0_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_Q); break;
		case SINGLE_HOLD: unregister_code16(S(KC_1)); break;
	}
	dance_state.step = 0;
}

void on_dance_1(tap_dance_state_t  *state, void *user_data);
void dance_1_finished(tap_dance_state_t  *state, void *user_data);
void dance_1_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_1(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_W);
		tap_code16(KC_W);
	}
	if(state->count > 2) {
		tap_code16(KC_W);
	}
}

void dance_1_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_W); break;
		case SINGLE_HOLD: register_code16(S(KC_2)); break;
		// case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
		// case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
	}
}

void dance_1_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_W); break;
		case SINGLE_HOLD: unregister_code16(S(KC_2)); break;
		// case DOUBLE_TAP: unregister_code16(KC_0); break;
		// case DOUBLE_SINGLE_TAP: unregister_code16(KC_0); break;
	}
	dance_state.step = 0;
}

void on_dance_2(tap_dance_state_t  *state, void *user_data);
void dance_2_finished(tap_dance_state_t  *state, void *user_data);
void dance_2_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_2(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_E);
		tap_code16(KC_E);
	}
	if(state->count > 2) {
		tap_code16(KC_E);
	}
}

void dance_2_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_E); break;
		case SINGLE_HOLD: register_code16(S(KC_3)); break;
	}
}

void dance_2_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_E); break;
		case SINGLE_HOLD: unregister_code16(S(KC_3)); break;
	}
	dance_state.step = 0;
}

void on_dance_3(tap_dance_state_t  *state, void *user_data);
void dance_3_finished(tap_dance_state_t  *state, void *user_data);
void dance_3_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_3(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_R);
		tap_code16(KC_R);
	}
	if(state->count > 2) {
		tap_code16(KC_R);
	}
}

void dance_3_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_R); break;
		case SINGLE_HOLD: register_code16(S(KC_4)); break;
	}
}

void dance_3_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_R); break;
		case SINGLE_HOLD: unregister_code16(S(KC_4)); break;
	}
	dance_state.step = 0;
}

void on_dance_4(tap_dance_state_t  *state, void *user_data);
void dance_4_finished(tap_dance_state_t  *state, void *user_data);
void dance_4_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_4(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_T);
		tap_code16(KC_T);
	}
	if(state->count > 2) {
		tap_code16(KC_T);
	}
}

void dance_4_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_T); break;
		case SINGLE_HOLD: register_code16(S(KC_5)); break;
	}
}

void dance_4_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_T); break;
		case SINGLE_HOLD: unregister_code16(S(KC_5)); break;
	}
	dance_state.step = 0;
}

void on_dance_5(tap_dance_state_t  *state, void *user_data);
void dance_5_finished(tap_dance_state_t  *state, void *user_data);
void dance_5_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_5(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_Y);
		tap_code16(KC_Y);
	}
	if(state->count > 2) {
		tap_code16(KC_Y);
	}
}

void dance_5_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_Y); break;
		case SINGLE_HOLD: register_code16(S(KC_6)); break;
	}
}

void dance_5_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_Y); break;
		case SINGLE_HOLD: unregister_code16(S(KC_6)); break;
	}
	dance_state.step = 0;
}

void on_dance_6(tap_dance_state_t  *state, void *user_data);
void dance_6_finished(tap_dance_state_t  *state, void *user_data);
void dance_6_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_6(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_U);
		tap_code16(KC_U);
	}
	if(state->count > 2) {
		tap_code16(KC_U);
	}
}

void dance_6_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_U); break;
		case SINGLE_HOLD: register_code16(S(KC_7)); break;
	}
}

void dance_6_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_U); break;
		case SINGLE_HOLD: unregister_code16(S(KC_7)); break;
	}
	dance_state.step = 0;
}

void on_dance_7(tap_dance_state_t  *state, void *user_data);
void dance_7_finished(tap_dance_state_t  *state, void *user_data);
void dance_7_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_7(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_I);
		tap_code16(KC_I);
	}
	if(state->count > 2) {
		tap_code16(KC_I);
	}
}

void dance_7_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_I); break;
		case SINGLE_HOLD: register_code16(S(KC_8)); break;
	}
}

void dance_7_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_I); break;
		case SINGLE_HOLD: unregister_code16(S(KC_8)); break;
	}
	dance_state.step = 0;
}

void on_dance_8(tap_dance_state_t  *state, void *user_data);
void dance_8_finished(tap_dance_state_t  *state, void *user_data);
void dance_8_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_8(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_O);
		tap_code16(KC_O);
	}
	if(state->count > 2) {
		tap_code16(KC_O);
	}
}

void dance_8_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_O); break;
		case SINGLE_HOLD: register_code16(S(KC_9)); break;
	}
}

void dance_8_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_O); break;
		case SINGLE_HOLD: unregister_code16(S(KC_9)); break;
	}
	dance_state.step = 0;
}

void on_dance_9(tap_dance_state_t  *state, void *user_data);
void dance_9_finished(tap_dance_state_t  *state, void *user_data);
void dance_9_reset(tap_dance_state_t  *state, void *user_data);

void on_dance_9(tap_dance_state_t  *state, void *user_data) {
	if(state->count == 2) {
		tap_code16(KC_P);
		tap_code16(KC_P);
	}
	if(state->count > 2) {
		tap_code16(KC_P);
	}
}

void dance_9_finished(tap_dance_state_t  *state, void *user_data) {
	dance_state.step = dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_P); break;
		case SINGLE_HOLD: register_code16(S(KC_0)); break;
	}
}

void dance_9_reset(tap_dance_state_t  *state, void *user_data) {
	wait_ms(BOUNCE_TIME);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_P); break;
		case SINGLE_HOLD: unregister_code16(S(KC_0)); break;
	}
	dance_state.step = 0;
}


tap_dance_action_t  tap_dance_actions[] = {
        [D_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [D_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [D_E] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [D_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [D_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [D_Y] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [D_U] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [D_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [D_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [D_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
};
