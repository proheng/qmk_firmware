#include QMK_KEYBOARD_H
#include "process_tap_dance.h"

enum custom_keycodes {
    CAD = 1212,
    TD_CTRLV = 0,
    TD_CTRLC = 1,
    TD_CTRLX = 2,
};
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GRV  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|CG_TOGG|    |  CAD  |------+------+------+------+------+------|
 * |LShift|   Z  |  X   |  C   |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,LCTL_T(KC_Q),LALT_T(KC_W),LGUI_T(KC_E), LSFT_T(KC_R),  KC_T,         KC_Y,    RSFT_T(KC_U),    RGUI_T(KC_I),    RALT_T(KC_O),    RCTL_T(KC_P),    KC_EQL,
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, CG_TOGG,           CAD,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
  LCTL(KC_TAB), LALT(KC_TAB), LCTL_T(KC_SPC), MT(MOD_LCTL | MOD_LSFT, KC_ENT),      MT(MOD_RCTL | MOD_RALT, KC_ENT), LT(1,KC_BSPC), KC_BSPC, TG(_NUM)
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |   [  |  ]   |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT| HOME | END  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | LSFT |      |  DEL |      |      |      |-------|    |-------|      |ScrDn| ScrUp |ScrLft|ScrRit|  |   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,KC_LBRC, KC_RBRC, KC_BSLS,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_HOME, KC_END,
  KC_LSFT, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_WH_DOWN, KC_MS_WH_UP, QK_MOUSE_WHEEL_LEFT, QK_MOUSE_WHEEL_RIGHT, KC_PIPE,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
),
/* NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | DEL  |BSPC  |  /   |  *   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  7   |  8   |  9   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  1   |  2   |  3   |  =   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \Enter \  | 0    |  .   |KC_TRNS|
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''---------------------'
 */
[_NUM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_DEL,  KC_BSPC, KC_SLSH, KC_ASTR, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_MINS, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PLUS, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  KC_1,    KC_2,    KC_3,    KC_EQL,  XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, KC_ENT,  KC_0, KC_DOT, KC_TRNS
)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CAD:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_DEL);
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
            }
            return false;
    }
    return true;
}
// Tap Dance function for V / Ctrl+V
void td_ctrlv_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) { // Hold: send Ctrl+V
        register_code(KC_LCTL); tap_code(KC_V); unregister_code(KC_LCTL); }
    else if (state->count == 1) {
        // Tap: send V
        tap_code(KC_V);
    }
}
// Tap Dance function for C / Ctrl+C
void td_ctrlc_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) { // Hold: send Ctrl+C
        register_code(KC_LCTL); tap_code(KC_C); unregister_code(KC_LCTL); }
    else if (state->count == 1) {
        // Tap: send C
        tap_code(KC_C);
    }
}
// Tap Dance function for C / Ctrl+X
void td_ctrlx_finished(tap_dance_state_t *state, void *user_data) {
    if (state->pressed) { // Hold: send Ctrl+X
        register_code(KC_LCTL); tap_code(KC_X); unregister_code(KC_LCTL); }
    else if (state->count == 1) {
        // Tap: send X
        tap_code(KC_X);
    }
}
void td_reset(tap_dance_state_t *state, void *user_data) {  }
tap_dance_action_t tap_dance_actions[] = {
    [TD_CTRLV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ctrlv_finished, td_reset),
    [TD_CTRLC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ctrlc_finished, td_reset),
    [TD_CTRLX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ctrlx_finished, td_reset),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) { /* First encoder */
        if (!clockwise) {
            tap_code16(KC_MS_WH_DOWN);
        } else {
            tap_code16(KC_MS_WH_UP);
        }
    } else if (index == 0) { /* Second encoder */
        if (!clockwise) {
            tap_code16(QK_MOUSE_WHEEL_RIGHT);
        } else {
            tap_code16(QK_MOUSE_WHEEL_LEFT);
        }
    }
    return false;
}
