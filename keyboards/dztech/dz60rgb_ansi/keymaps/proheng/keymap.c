#include "quantum_keycodes.h"
#include "quantum.h"
#include "action_layer.h"
#include "version.h"
#include QMK_KEYBOARD_H


#include "custom_keycodes.c"
#include "tap_dance.c"
#include "mac_vim_keymap.c"
#include "win_vim_keymap.c"


// Tap dance enums
enum {
    TD_CAP,
    TD_FN,
    TD_RCTL,
    TD_KC_1,
    TD_KC_2,
    TD_KC_3,
    TD_KC_4,
    TD_KC_5,
    TD_KC_6,
    TD_KC_7,
    TD_KC_8,
    TD_KC_9,
    TD_KC_10,
    TD_KC_11,
    TD_KC_12
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cap_finished, cap_reset),
    [TD_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
    [TD_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rctl_finished, rctl_reset),
    [TD_KC_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,  kc_1_finished,  kc_num_reset),
    [TD_KC_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,  kc_2_finished,  kc_num_reset),
    [TD_KC_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,  kc_3_finished,  kc_num_reset),
    [TD_KC_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,  kc_4_finished,  kc_num_reset),
    [TD_KC_5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,  kc_5_finished,  kc_num_reset),
    [TD_KC_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,  kc_6_finished,  kc_num_reset),
    [TD_KC_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,  kc_7_finished,  kc_num_reset),
    [TD_KC_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,  kc_8_finished,  kc_num_reset),
    [TD_KC_9] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,  kc_9_finished,  kc_num_reset),
    [TD_KC_10] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kc_10_finished, kc_num_reset),
    [TD_KC_11] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kc_11_finished, kc_num_reset),
    [TD_KC_12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kc_12_finished, kc_num_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[MAC_QWERTY] = LAYOUT_60_ansi(
        KC_GRV,  TD(TD_KC_1),    TD(TD_KC_2),    TD(TD_KC_3),    TD(TD_KC_4),    TD(TD_KC_5),   TD(TD_KC_6),    TD(TD_KC_7),    TD(TD_KC_8),   TD(TD_KC_9),   TD(TD_KC_10),    TD(TD_KC_11), TD(TD_KC_12),  KC_BSPC,  
        KC_TAB,  LSG_T(KC_Q),    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, 
        TD(TD_CAP),       LCTL_T(KC_A),     LALT_T(KC_S),     LGUI_T(KC_D),     LSFT_T(KC_F),     KC_G,    KC_H,    RSFT_T(KC_J),     RGUI_T(KC_K),    RALT_T(KC_L),    RCTL_T(KC_SCLN), KC_QUOT, KC_ENT,  
        KC_LSFT, KC_Z,    LT(0,KC_X),    LT(0,KC_C),   LT(0,KC_V),    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  
        KC_LCTL, KC_LALT, KC_LGUI,    LT(MAC_VIM, KC_SPC),       TD(TD_FN),     KC_RGUI, KC_RALT, TD(TD_RCTL)
    ),
    // Windows Layuout
	[WIN_QWERTY] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, C_S_T(KC_Q), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        TD(TD_CAP),       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______,          LT(WIN_VIM, KC_SPC),       _______, _______, _______, _______
    ),
    // MAC VIM Layout
	[MAC_VIM] = LAYOUT_60_ansi(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LGUI(KC_LEFT),    LGUI(KC_RGHT),    KC_NO,   KC_NO,   KC_NO,  
        KC_TAB,  KC_NO,   LALT(KC_RGHT),    LALT(KC_RGHT),    KC_NO,   KC_NO,   LGUI(KC_C),       LGUI(KC_Z),       TO(MAC_QWERTY),   KC_ENT,  LGUI(KC_V),     KC_NO,   KC_NO,   KC_NO,  
        TD(TD_CAP),       KC_NO, KC_NO,   KC_BSPC, KC_NO, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,   KC_NO,  
        KC_LSFT, KC_NO,   KC_DEL,  KC_NO,   KC_NO,        LALT(KC_LEFT),    KC_NO,   KC_PGDN,   KC_PGUP,   KC_NO,   KC_NO,   KC_RSFT, 
        KC_LCTL, KC_LALT, KC_NO,   KC_NO,   _______, KC_RALT, KC_RCTL, KC_NO
    ),
    // Windows VIM Layuout
	[WIN_VIM] = LAYOUT_60_ansi(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,   KC_NO,  
        KC_TAB,  KC_NO,   LCTL(KC_RGHT),    LCTL(KC_RGHT),    KC_NO,   KC_NO,   LCTL(KC_C),       LCTL(KC_Z),       TO(WIN_QWERTY),   KC_ENT,  LCTL(KC_V),     KC_NO,   KC_NO,   KC_NO,   
        TD(TD_CAP),       KC_NO, KC_NO,   KC_BSPC, KC_NO, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_NO,   KC_NO,  
        KC_LSFT, KC_NO,   KC_DEL,  KC_NO,   KC_NO,        LCTL(KC_LEFT),    KC_NO,   KC_PGDN,   KC_PGUP,   KC_NO,   KC_NO,   KC_RSFT, 
        KC_LCTL, KC_LALT, KC_NO,   KC_NO,   _______, KC_RALT, KC_RCTL, KC_NO
    ),
	[GEN_FN] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
    )
};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_matrix_set_color(7, RGB_TEAL);//KC_6
    rgb_matrix_set_color(8, RGB_TEAL);//KC_5
    rgb_matrix_set_color(2, RGB_GREEN);//KC_-
    rgb_matrix_set_color(1, RGB_GREEN);//KC_=

    rgb_matrix_set_color(21, RGB_TEAL);//KC_Y
    rgb_matrix_set_color(22, RGB_TEAL);//KC_T
    rgb_matrix_set_color(15, RGB_BLUE);//KC_]
    rgb_matrix_set_color(16, RGB_BLUE);//KC_[
    rgb_matrix_set_color(14, RGB_ORANGE);//KC_|

    rgb_matrix_set_color(33, RGB_GREEN);//KC_J
    rgb_matrix_set_color(34, RGB_TEAL);//KC_H
    rgb_matrix_set_color(35, RGB_TEAL);//KC_G
    rgb_matrix_set_color(36, RGB_RED);//KC_F
    rgb_matrix_set_color(29, RGB_MAGENTA);//KC_'

    rgb_matrix_set_color(46, RGB_TEAL);//KC_N
    rgb_matrix_set_color(47, RGB_TEAL);//KC_B


    for (uint8_t i = led_min; i <= led_max; i++) {
        if(layer_state_is(MAC_QWERTY)) { rgb_matrix_set_color(i, RGB_CORAL); }
        if(layer_state_is(WIN_QWERTY)) { rgb_matrix_set_color(i, RGB_GOLDENROD); }
        if(layer_state_is(MAC_VIM) || layer_state_is(WIN_VIM)) { rgb_matrix_set_color(i, RGB_TURQUOISE); }
        if(layer_state_is(GEN_FN)) { rgb_matrix_set_color(i, RGB_RED); }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_X):
            if (!record->tap.count && record->event.pressed) {
                if(layer_state_is(MAC_QWERTY)){ 
                    tap_code16(LGUI(KC_X)); // Intercept hold function to send CMD-X
                }
                if(layer_state_is(WIN_QWERTY)){ 
                    tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
                }
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_C):
            if (!record->tap.count && record->event.pressed) {
                if(layer_state_is(MAC_QWERTY)){ 
                    tap_code16(LGUI(KC_C)); // Intercept hold function to send CMD-C
                }
                if(layer_state_is(WIN_QWERTY)){ 
                    tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
                }
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_V):
            if (!record->tap.count && record->event.pressed) {
                if(layer_state_is(MAC_QWERTY)){ 
                    tap_code16(LGUI(KC_V)); // Intercept hold function to send CMD-V
                }
                if(layer_state_is(WIN_QWERTY)){ 
                    tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
                }
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
    }
    return true;
}
/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case TD(TD_KC_1): */
/*             return TAPPING_TERM - 100; */
/*         default: */
/*             return TAPPING_TERM; */
/*     } */
/* } */

