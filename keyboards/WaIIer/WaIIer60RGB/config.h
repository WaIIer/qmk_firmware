#pragma once

#include "config_common.h"

#define VENDOR_ID 0x0072
#define MANUFACTURER WaIIer
#define PRODUCT_ID 0x0002
#define DEVICE_VER 0
#define PRODUCT WaIIer60RGB

#define MATRIX_ROWS 5
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { C6, C7, B2, B3, F7 }
#define MATRIX_COL_PINS { F4, F1, F0, D0, D1, D2, D3, D5, D4, D6, D7, B4, B5, B6 }
#define UNUSED_PINS { B0, B1, B7, F6 }

#define DIODE_DIRECTION COL2ROW

#define RGBLIGHT_ANIMATIONS_OFF
#define RGBLIGHT_LAYERS
#define RGB_DI_PIN F5
#define RGBLED_NUM 61
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
