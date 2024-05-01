// Copyright 2024 yes (@yes)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 7

#define MATRIX_ROW_PINS { F7, F6, F5, F4, B1, B3, B2, B4}
#define MATRIX_COL_PINS { D3, D2, D1, D0, D4, C6, D7}


/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define GRAVE_ESC_ALT_OVERRIDE

#define TAPPING_FORCE_HOLD
#define RETRO_TAPPING
#define TAPPING_TERM 200
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
