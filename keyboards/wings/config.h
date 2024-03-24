// Copyright 2024 yes (@yes)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 7

#define MATRIX_ROW_PINS { D1, D0, D4, D7, F4, F5, F6, F7}
#define MATRIX_COL_PINS { E6, B5, B4, B6, B2, B3, B1}


/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define GRAVE_ESC_ALT_OVERRIDE
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
