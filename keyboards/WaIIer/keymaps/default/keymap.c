/* Copyright 2020
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

#define NUM_LAYERS 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_RGB_ORTHO( // default
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,     KC_U,  KC_I,    KC_O,    KC_P,     KC_BSPC,
        KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,     KC_J,  KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSHIFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,     KC_M,  KC_COMM, KC_DOT,  KC_SLASH, KC_ENTER,
        MO(3),     KC_LCPO, KC_LALT, KC_LCMD, MO(1), KC__MUTE, KC_SPACE, MO(2), KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT
    ),
    [1] = LAYOUT_RGB_ORTHO( // lower
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,     KC_RPRN,   KC_DEL,
          KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR,     KC_RCBR,   KC_PIPE,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PIPE, KC_PIPE, KC_HOME,     KC_END,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_TRNS, KC__VOLDOWN, KC__VOLUP, KC_MPLY
    ),
    [2] = LAYOUT_RGB_ORTHO( // raise
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,        KC_0,      KC_BSPC,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC,     KC_RBRC,   KC_BSLASH,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_PGUP,     KC_PGDN,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_TRNS, KC__VOLDOWN, KC__VOLUP, KC_MPLY
    ),
    [3] = LAYOUT_RGB_ORTHO( // numpad
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAST, KC_7, KC_8, KC_9,   KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSLS, KC_4, KC_5, KC_6,   KC_MINS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CIRC, KC_1, KC_2, KC_3,   KC_PLUS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_0, KC_DOT, KC_ENTER
    )
};

// Color Picker https://alloyui.com/examples/color-picker/hsv.html
// HUE: H * 255 / 360
// SAT: S * 255 / 100
// VAL: V * 255 / 100

#define WAIIER_WHITE 0,   0,   128
#define WAIIER_RED   0,   255, 128
#define WAIIER_BLUE  170, 255, 128
#define WAIIER_GREEN 85,  220, 128


const rgblight_segment_t PROGMEM my_layer0_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 47, WAIIER_RED}
);

const rgblight_segment_t PROGMEM my_layer1_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {12, 24, WAIIER_WHITE }
);

const rgblight_segment_t PROGMEM my_layer2_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {12, 24, WAIIER_BLUE }
);

const rgblight_segment_t PROGMEM my_layer3_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,  3, WAIIER_GREEN},
    {13, 3, WAIIER_GREEN},
    {32, 3, WAIIER_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_rgb,
    my_layer1_rgb,
    my_layer2_rgb,
    my_layer3_rgb
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    layer_state_set_user(layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    for (int i = 0; i < NUM_LAYERS; i++) {
        rgblight_set_layer_state(i, layer_state_cmp(state, i));
    }
    return state;
}
