#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "mac_vim_keymap.c"
#include QMK_KEYBOARD_H

enum {
    TD_ESC_MAC_VIM,
    TD_ESC_MAC_QWERTY,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_MAC_VIM] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, MAC_VIM),
    [TD_ESC_MAC_QWERTY] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, MAC_QWERTY),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Mac Layuout
	[MAC_QWERTY] = LAYOUT_ansi_1u(
            KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,   KC_INS,  KC_DEL, 
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, 
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, 
            TD(TD_ESC_MAC_VIM),        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN, 
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END, 
            KC_LCTL, KC_LALT, KC_LGUI, LT(MAC_VIM, KC_SPC),       TO(WIN_QWERTY),   KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
        ),
    // Windows Layuout
    // TODO to follow mac to update the keymap with windows related settings
	[WIN_QWERTY] = LAYOUT_ansi_1u(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, LT(WIN_VIM, KC_SPC),       TO(MAC_QWERTY),   _______, _______, _______, _______, _______
        ),
    // MAC VIM Layout
	[MAC_VIM] = LAYOUT_ansi_1u(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LGUI(KC_LEFT),    LGUI(KC_RGHT),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_TAB,  KC_NO, LALT(KC_RGHT),    LALT(KC_RGHT),    KC_NO,   KC_NO,   LCTL(KC_INS),     LGUI(KC_Z),       TO(MAC_QWERTY),   KC_ENT,  LSFT(KC_INS),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            TD(TD_ESC_MAC_QWERTY),     KC_PGDN, KC_NO,   KC_BSPC, KC_PGUP, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_LSFT, KC_NO,   KC_DEL,  KC_NO,   TO(MAC_VIM_VISUAL),        LALT(KC_LEFT),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, KC_NO,   KC_NO,   
            KC_LCTL, KC_LALT, KC_NO,   KC_NO,   TO(MAC_QWERTY),   KC_RALT, KC_RCTL, KC_NO,   KC_NO,   KC_NO
        ),
    // TODO update the keymap when creating WIN_VIM_VISUAL 
    // Windows VIM Layuout
	[WIN_VIM] = LAYOUT_ansi_1u(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_TAB,  KC_NO,   LCTL(KC_RGHT),    LCTL(KC_RGHT),    KC_NO,   KC_NO,   LCTL(KC_INS),     LCTL(KC_Z),       TO(WIN_QWERTY),   KC_ENT,  LSFT(KC_INS),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   LCTL(KC_X),      KC_NO,    KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_LSFT, KC_NO,   LCTL(KC_X),       KC_NO,   KC_NO,   LCTL(KC_LEFT),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, KC_NO,   KC_NO,   
            KC_LCTL, KC_LALT, KC_NO,   KC_NO,   TO(WIN_QWERTY),   KC_RALT, KC_RCTL, KC_NO,   KC_NO,   KC_NO
        ),
    // MAC VIM VISUAL Layout
    // Every keystroke will be shifted to simulate selection in vim visual mode.
	[MAC_VIM_VISUAL] = LAYOUT_ansi_1u(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LSG(KC_LEFT),     LSG(KC_RGHT),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_TAB,  KC_NO,   LSA(KC_RGHT),     LSA(KC_RGHT),     KC_NO,   KC_NO,   VIM_Y,   LGUI(KC_Z),       TO(MAC_QWERTY),   KC_ENT,  LSFT(KC_INS),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            TO(MAC_VIM),KC_NO,KC_NO,   LGUI(KC_X),       KC_NO,   KC_NO,   LSFT(KC_LEFT),    LSFT(KC_DOWN),    LSFT(KC_UP),      LSFT(KC_RGHT),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_LSFT, KC_NO,   VIM_X,   KC_NO,   TO(MAC_VIM),      LSA(KC_LEFT),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, KC_NO,   KC_NO,   
            KC_LCTL, KC_LALT, KC_NO,   KC_NO,   TO(MAC_QWERTY),   KC_RALT, KC_RCTL, KC_NO,   KC_NO,   KC_NO
        ),
    // TODO
    // WIN VIM VISUAL Layout
    // Every keystroke will be shifted to simulate selection in vim visual mode.
	[WIN_VIM_VISUAL] = LAYOUT_ansi_1u(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),
	[GEN_FN] = LAYOUT_ansi_1u(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,  _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        )
};



/* RGB set up */
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_CORAL} );
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_GOLDENROD} );
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_TEAL} );
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_TEAL} );
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_YELLOW} );
const rgblight_segment_t PROGMEM my_layer15_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_RED} );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,    
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer,
    my_layer15_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, MAC_QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, WIN_QWERTY));
    rgblight_set_layer_state(2, layer_state_cmp(state, MAC_VIM));
    rgblight_set_layer_state(3, layer_state_cmp(state, WIN_VIM));
    rgblight_set_layer_state(4, layer_state_cmp(state, MAC_VIM_VISUAL));
    rgblight_set_layer_state(5, layer_state_cmp(state, GEN_FN));
    return state;
}


/* void mac_vim_visual_keymap(uint16_t keycode, keyrecord_t *record){ */
/*     switch(keycode){ */
/*         case KC_D: */
/*             if(record->event.pressed) */
/*             { */
/*                 PRESS(KC_D); */
/*             } */
/*             return; */
/*     } */
/* } */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(layer_state_is(MAC_VIM_VISUAL))
    {
        mac_vim_visual_keymap(keycode,record);    
    }
  /* bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) | */
  /*                (keyboard_report->mods & MOD_BIT(KC_RSFT)); */

    /* this is the sample code for future reference */
    /* if(layer_state_is(MAC_VIM)) */
    /* { */
    /*     switch(keycode){ */
    /*         case VIM_A: */
    /*             if(record->event.pressed) */
    /*             { */
    /*                 PRESS(KC_D); */
    /*             } */
    /*             return false; */
    /*     } */
    /* } */
  return true;
}; 
