#include "macro.c"
#include QMK_KEYBOARD_H

const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS( {1, 16, HSV_CORAL} );
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS( {1, 16, HSV_GOLDENROD} );
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( {1, 16, HSV_TEAL} );
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS( {1, 16, HSV_TEAL} );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,    
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Mac Layuout
	[0] = LAYOUT_ansi_1u(
            TG(1),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,   KC_INS,  KC_DEL, 
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, 
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, 
            KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN, 
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END, 
            KC_LCTL, KC_LALT, KC_LGUI, LT(2,KC_SPC),     TG(2),   KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
        ),
    // Windows Layuout
	[1] = LAYOUT_ansi_1u(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, KC_LCTL, LT(3,KC_SPC),     TG(3),   _______, _______, _______, _______, _______
        ),
    // MAC VIM Layout
	[2] = LAYOUT_ansi_1u(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______, KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGUP, TO(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,            _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
        ),
    // Windows VIM Layuout
	[3] = LAYOUT_ansi_1u(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______, KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGUP, TO(1),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,            _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
        )
};
