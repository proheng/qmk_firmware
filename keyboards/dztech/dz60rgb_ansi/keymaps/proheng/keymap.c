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
    SOME_OTHER_DANCE
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cap_finished, cap_reset),
    [TD_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[MAC_QWERTY] = LAYOUT_60_ansi(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, 
        TD(TD_CAP),       LCTL_T(KC_A),     LALT_T(KC_S),     LGUI_T(KC_D),     LSFT_T(KC_F),     KC_G,    KC_H,    RSFT_T(KC_J),     RGUI_T(KC_K),    RALT_T(KC_L),    RCTL_T(KC_SCLN), KC_QUOT, KC_ENT,  
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  
        KC_LCTL, KC_LALT, KC_LGUI,    LT(MAC_VIM, KC_SPC),       TD(TD_FN),     KC_RGUI, KC_RALT, KC_RCTL
    ),

    // Mac Layuout
	[MAC_QWERTY] = LAYOUT_60_ansi(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, 
        TD(TD_CAP),       LCTL_T(KC_A),     LALT_T(KC_S),     LGUI_T(KC_D),     LSFT_T(KC_F),     KC_G,    KC_H,    RSFT_T(KC_J),     RGUI_T(KC_K),    RALT_T(KC_L),    RCTL_T(KC_SCLN), KC_QUOT, KC_ENT,  
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI,    LT(MAC_VIM, KC_SPC),       TD(TD_FN),     KC_RGUI, KC_RALT, KC_RCTL
    ),
    // Windows Layuout
	[WIN_QWERTY] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        TD(TD_CAP),       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______,          LT(WIN_VIM, KC_SPC),       _______, _______, _______, _______
    ),
    // MAC VIM Layout
	[MAC_VIM] = LAYOUT_60_ansi(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LGUI(KC_LEFT),    LGUI(KC_RGHT),    KC_NO,   KC_NO,   KC_NO,  
        KC_TAB,  KC_NO,   LALT(KC_RGHT),    LALT(KC_RGHT),    KC_NO,   KC_NO,   LGUI(KC_C),       LGUI(KC_Z),       TO(MAC_QWERTY),   KC_ENT,  LGUI(KC_V),     KC_NO,   KC_NO,   KC_NO,  
        TD(TD_CAP),       KC_PGDN, KC_NO,   KC_BSPC, KC_PGUP, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,   KC_NO,  
        KC_LSFT, KC_NO,   KC_DEL,  KC_NO,   TO(MAC_VIM_VISUAL),        LALT(KC_LEFT),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, 
        KC_LCTL, KC_LALT, KC_NO,   KC_NO,   _______, KC_RALT, KC_RCTL, KC_NO
    ),
    // Windows VIM Layuout
	[WIN_VIM] = LAYOUT_60_ansi(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,   KC_NO,  
        KC_TAB,  KC_NO,   LCTL(KC_RGHT),    LCTL(KC_RGHT),    KC_NO,   KC_NO,   LCTL(KC_C),       LCTL(KC_Z),       TO(WIN_QWERTY),   KC_ENT,  LCTL(KC_V),     KC_NO,   KC_NO,   KC_NO,   
        TD(TD_CAP),       KC_PGDN, KC_NO,   KC_BSPC, KC_PGUP, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_NO,   KC_NO,  
        KC_LSFT, KC_NO,   KC_DEL,  KC_NO,   TO(WIN_VIM_VISUAL),        LCTL(KC_LEFT),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, 
        KC_LCTL, KC_LALT, KC_NO,   KC_NO,   _______, KC_RALT, KC_RCTL, KC_NO
    ),
    // MAC VIM VISUAL Layout
    // Every keystroke will be shifted to simulate selection in vim visual mode.
	[MAC_VIM_VISUAL] = LAYOUT_60_ansi(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LSG(KC_LEFT),     LSG(KC_RGHT),     KC_NO,   KC_NO,   KC_NO,   
        KC_TAB,  KC_NO,   LSA(KC_RGHT),     LSA(KC_RGHT),     KC_NO,   KC_NO,   VIM_Y,   LGUI(KC_Z),       TO(MAC_QWERTY),   KC_ENT,  LSFT(KC_INS),     KC_NO,   KC_NO,   KC_NO,   
        TO(MAC_VIM),      KC_NO,   KC_NO,   VIM_D,       KC_NO,   KC_NO,   LSFT(KC_LEFT),    LSFT(KC_DOWN),    LSFT(KC_UP),      LSFT(KC_RGHT),    KC_NO,   KC_NO,   KC_NO,  
        KC_LSFT, KC_NO,   VIM_X,   KC_NO,   TO(MAC_VIM),      LSA(KC_LEFT),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, 
        KC_LCTL, KC_LALT, KC_NO,   KC_NO,   _______, KC_RALT, KC_RCTL, KC_NO
    ),
    // WIN VIM VISUAL Layout
    // Every keystroke will be shifted to simulate selection in vim visual mode.
	[WIN_VIM_VISUAL] = LAYOUT_60_ansi(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LCTL(KC_HOME),    LCTL(KC_END),     KC_NO,   KC_NO,   KC_NO,  
        KC_TAB,  KC_NO,   LCTL(KC_RGHT),    LCTL(KC_RGHT),    KC_NO,   KC_NO,   VIM_Y,   LCTL(KC_Z),       TO(WIN_QWERTY),   KC_ENT,  LSFT(KC_INS),     KC_NO,   KC_NO,   KC_NO,  
        TO(WIN_VIM),      KC_NO,   KC_NO,   VIM_D,      KC_NO,   KC_NO,   LSFT(KC_LEFT),    LSFT(KC_DOWN),    LSFT(KC_UP),      LSFT(KC_RGHT),    KC_NO,   KC_NO,   KC_NO, 
        KC_LSFT, KC_NO,   VIM_X,   KC_NO,   TO(WIN_VIM),      LSFT(KC_LEFT),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
        KC_LCTL, KC_LALT, KC_NO,   KC_NO,   _______, KC_RALT, KC_RCTL, KC_NO
    ),
	[MOUSE_KEY] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  
        _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______,  
        _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
        _______, _______, _______, KC_BTN1, _______, _______, _______, _______
    ),
	[GEN_FN] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
    )
};



/* RGB set up */
/* const rgblight_segment_t PROGMEM mac_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_CORAL} ); */
/* const rgblight_segment_t PROGMEM win_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_GOLDENROD} ); */
/* const rgblight_segment_t PROGMEM mac_vim_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_TEAL} ); */
/* const rgblight_segment_t PROGMEM win_vim_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_TEAL} ); */
/* const rgblight_segment_t PROGMEM mac_vim_visual_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_YELLOW} ); */
/* const rgblight_segment_t PROGMEM win_vim_visual_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_YELLOW} ); */
/* const rgblight_segment_t PROGMEM mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_GREEN} ); */
/* const rgblight_segment_t PROGMEM fn_visual_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_RED} ); */

/* const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST( */
/*     mac_qwerty_layer, */    
/*     win_qwerty_layer, */
/*     mac_vim_layer, */
/*     win_vim_layer, */
/*     mac_vim_visual_layer, */
/*     win_vim_visual_layer, */
/*     fn_visual_layer, */
/*     mouse_layer */
/* ); */

/* void keyboard_post_init_user(void) { */
/*     rgblight_layers = my_rgb_layers; */
/* } */

/* layer_state_t default_layer_state_set_user(layer_state_t state) { */
/*     rgblight_set_layer_state(0, layer_state_cmp(state, MAC_QWERTY)); */
/*     return state; */
/* } */

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     rgblight_set_layer_state(1, layer_state_cmp(state, WIN_QWERTY)); */
/*     rgblight_set_layer_state(2, layer_state_cmp(state, MAC_VIM)); */
/*     rgblight_set_layer_state(3, layer_state_cmp(state, WIN_VIM)); */
/*     rgblight_set_layer_state(4, layer_state_cmp(state, MAC_VIM_VISUAL)); */
/*     rgblight_set_layer_state(5, layer_state_cmp(state, WIN_VIM_VISUAL)); */
/*     rgblight_set_layer_state(6, layer_state_cmp(state, GEN_FN)); */
/*     rgblight_set_layer_state(7, layer_state_cmp(state, MOUSE_KEY)); */
/*     return state; */
/* } */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(layer_state_is(MAC_VIM_VISUAL))
    {
        mac_vim_visual_keymap(keycode,record);    
    }
    if(layer_state_is(WIN_VIM_VISUAL))
    {
        win_vim_visual_keymap(keycode,record);    
    }
        

  return true;
}; 
