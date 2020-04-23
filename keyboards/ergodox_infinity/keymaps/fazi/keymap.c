#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define FL1 1 // symbols
#define FL2 2 // media keys
#define FL3 3 // media keys
#define FL4 4 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  BACKSPACE  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LSHIFT |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RSHIFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  LCTL | LALT | LGUI | FN1 | FN2 |                                          | FN2 | FN1| RGUI | RALT | RCTL |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | Esc   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space| Bsp  |------|       |------| Enter  |Space |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC ,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   _______,
        KC_TAB ,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   _______,
        _______,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   _______,
        KC_LCTL,KC_LALT,KC_LGUI,MO(FL1) ,MO(FL2), 
                                        _______, _______,
                                                        _______,
                                        KC_SPC, KC_BSPC,_______,
        // right hand
             _______,KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_BSPC,
             _______,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   _______,
                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,_______,
             _______,KC_N,   KC_M,   KC_COMM,KC_DOT,KC_SLASH,KC_RSHIFT,
                           MO(FL3),MO(FL4), KC_RGUI,KC_LALT,KC_RCTL,
             _______,        _______,
             _______,
             _______,KC_ENT, KC_SPC
    ),
/* Keymap 1: Functions, Media and Mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  | EJECT  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | WhUp | Lclk | MsUP | Rclk |      |MouseAc0|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|WhLeft|MsLeft|MsDown|MsRigh|WhRigh|MouseAc1|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |WhDown|      |      |      |  UP  |MouseAc2|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      | LEFT | DOWN | RIGHT |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[FL1] = LAYOUT_ergodox(
       KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______,  _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_MEDIA_EJECT,
       _______,  KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______, KC_MS_ACCEL0,
                 KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_MS_ACCEL1,
       _______,  KC_WH_D, _______, _______, _______, KC_UP, KC_MS_ACCEL2,
                          _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,
       _______,   _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |  -   |   =   |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |   [  |   ]  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |   '  |   \  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |       |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[FL2] = LAYOUT_ergodox(
       // left hand

    S(LCTL(LGUI(KC_T))),_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,
       _______,KC_GRV,_______,_______,_______,_______,_______,
       _______,_______, _______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______, _______,_______, KC_MINS, KC_EQL ,_______,
       _______, _______, _______,_______, KC_LBRC, KC_RBRC ,_______,
                _______, _______,_______, KC_QUOT, KC_BSLS, _______,
       _______, _______, _______,_______, _______, _______, _______,
                         _______,_______, _______, _______, _______,
       _______,   _______,
       _______,
       _______, _______, _______
),
/* Keymap 3: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |  -   |   =   |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |   [  |   ]  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |   '  |   \  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |       |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[FL3] = LAYOUT_ergodox(
       // left hand
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,
       _______,KC_GRV,_______,_______,_______,_______,_______,
       _______,_______, _______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______, _______,_______, KC_MINS, KC_EQL ,_______,
       _______, _______, _______,_______, KC_LBRC, KC_RBRC ,_______,
                _______, _______,_______, KC_QUOT, KC_BSLS, _______,
       _______, _______, _______,_______, _______, _______, _______,
                         _______,_______, _______, _______, _______,
       _______,   _______,
       _______,
       _______, _______, _______
),
/* Keymap 4: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |  -   |   =   |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |   [  |   ]  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |   '  |   \  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |       |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLjS
[FL4] = LAYOUT_ergodox(
       // left hand
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,
       _______,KC_GRV,_______,_______,_______,_______,_______,
       _______,_______, _______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______, _______,_______, KC_MINS, KC_EQL ,_______,
       _______, _______, _______,_______, KC_LBRC, KC_RBRC ,_______,
                _______, _______,_______, KC_QUOT, KC_BSLS, _______,
       _______, _______, _______,_______, _______, _______, _______,
                         _______,_______, _______, _______, _______,
       _______,   _______,
       _______,
       _______, _______, _______
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case FL1:
            ergodox_right_led_1_on();
            break;
        case FL2:
            ergodox_right_led_2_on();
            break;
        case FL3:
            ergodox_right_led_3_on();
            break;
        case FL4:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
