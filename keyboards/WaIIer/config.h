#include "config_common.h"

// Common config file included by other WaIIer Keyboards

#define VENDOR_ID 0x0072
#define MANUFACTURER WaIIer
#define PRODUCT_ID 0x0001
#define DEVICE_VER 0
#define PRODUCT WaIIerRGB

#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { B0, B1, B2, B3 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, C7, C6, B6, B5, B4, D7 }
#define UNUSED_PINS { B7, D2, D3, D5, D6, D4 }

#define DIODE_DIRECTION COL2ROW

#define USB_MAX_POWER_CONUMPTION 1250

#define RGB_DI_PIN E6
#define RGBLED_NUM 47
