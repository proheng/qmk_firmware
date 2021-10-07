#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "vim.h"
#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Mac Layuout
	[0] = LAYOUT_ansi_1u(
            TG(1),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,   KC_INS,  KC_DEL, 
            KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME, 
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, 
            KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN, 
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END, 
            KC_LCTL, KC_LALT, KC_LGUI, LT(2,KC_SPC),     TO(2),   KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
        ),
    // Windows Layuout
	[1] = LAYOUT_ansi_1u(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, KC_LCTL, LT(3,KC_SPC),     TO(3), _______, _______, _______, _______, _______
        ),
    // MAC VIM Layout
	[2] = LAYOUT_ansi_1u(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_TAB,  KC_NO,   LALT(KC_RGHT),    LALT(KC_RGHT),    KC_NO,   KC_NO,   LCTL(KC_INS),     LGUI(KC_Z),       TO(0),   KC_ENT,  LSFT(KC_INS),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   VIM_A,   VIM_S,   VIM_D,   KC_NO,   KC_NO,   VIM_H,   VIM_J,   VIM_K,   VIM_L,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_LSFT, KC_NO,   VIM_X,   VIM_C,   VIM_V,   LALT(KC_LEFT),   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_RSFT, KC_NO,   KC_NO,   
            KC_LCTL, KC_LALT, KC_NO,   KC_NO,            TO(1),  KC_RALT, KC_RCTL, KC_NO,   KC_NO,   KC_NO
        ),
    // Windows VIM Layuout
	[3] = LAYOUT_ansi_1u(
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,   KC_NO,   KC_NO,   
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_TAB,  KC_NO,   LCTL(KC_RGHT),    LCTL(KC_RGHT),    KC_NO,   KC_NO,   LCTL(KC_INS),     LCTL(KC_Z),       TO(1),   KC_ENT,  LSFT(KC_INS),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_NO,   VIM_A,   VIM_S,   VIM_D,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,   KC_NO,   KC_NO,   KC_NO,   
            KC_LSFT, KC_NO,   VIM_X,   VIM_C,   VIM_V,   LCTL(KC_LEFT),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, KC_NO,   KC_NO,   
            KC_LCTL, KC_LALT, KC_NO,   KC_NO,            TO(2),   KC_RALT, KC_RCTL, KC_NO,   KC_NO,   KC_NO
        )
};



/* RGB set up */
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_CORAL} );
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_GOLDENROD} );
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_TEAL} );
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 16, HSV_TEAL} );

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



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) |
                 (keyboard_report->mods & MOD_BIT(KC_RSFT));

  if(layer_state_is(2))
  {
      switch (keycode) {

        case VIM_A:
          if (record->event.pressed) { SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND(); }
          return false;

        case VIM_B:
          if (record->event.pressed) {
            switch(VIM_QUEUE) {
              case KC_NO: VIM_BACK(); break;
              case VIM_C: VIM_CHANGE_BACK(); break;
              case VIM_D: VIM_DELETE_BACK(); break;
              case VIM_V: VIM_VISUAL_BACK(); break;
            }
          }
          return false;

        case VIM_C:
          if (record->event.pressed) {
            switch(VIM_QUEUE) {
              case KC_NO: SHIFTED ? VIM_CHANGE_LINE(): VIM_LEADER(VIM_C); break;
              case VIM_C: VIM_CHANGE_WHOLE_LINE(); break;
            }
          }
          return false;

        case VIM_D:
          if (record->event.pressed) {
            switch(VIM_QUEUE) {
              case KC_NO: SHIFTED ? TAP(KC_DEL) : VIM_LEADER(VIM_D); break;
              case VIM_D: VIM_DELETE_WHOLE_LINE(); break;
            }
          }
          return false;

        case VIM_E:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_END(); break;
              case VIM_C: VIM_CHANGE_END(); break;
              case VIM_D: VIM_DELETE_END(); break;
              case VIM_V: VIM_VISUAL_END(); break;
            }
          }
          return false;

        case VIM_H:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_LEFT(); break;
              case VIM_C: VIM_CHANGE_LEFT(); break;
              case VIM_D: VIM_DELETE_LEFT(); break;
              case VIM_V: VIM_VISUAL_LEFT(); break;
            }
          }
          return false;

        case VIM_I:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              /* case KC_NO: layer_on(INSERT_MODE); break; */
              case VIM_C: VIM_LEADER(VIM_CI); break;
              case VIM_D: VIM_LEADER(VIM_DI); break;
              case VIM_V: VIM_LEADER(VIM_VI); break;
            }
          }
          return false;

        case VIM_J:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_DOWN(); break;
              /*DISABLE JOIN case KC_NO: SHIFTED ? VIM_JOIN() : VIM_DOWN(); break; */
              case VIM_C: VIM_CHANGE_DOWN(); break;
              case VIM_D: VIM_DELETE_DOWN(); break;
              case VIM_V: VIM_VISUAL_DOWN(); break;
            }
          }
          return false;

        case VIM_K:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_UP(); break;
              case VIM_C: VIM_CHANGE_UP(); break;
              case VIM_D: VIM_DELETE_UP(); break;
              case VIM_V: VIM_VISUAL_UP(); break;
            }
          }
          return false;

        case VIM_L:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_RIGHT(); break;
              case VIM_C: VIM_CHANGE_RIGHT(); break;
              case VIM_D: VIM_DELETE_RIGHT(); break;
              case VIM_V: VIM_VISUAL_RIGHT(); break;
            }
          }
          return false;

        case VIM_O:
          if (record->event.pressed) { SHIFTED ? VIM_OPEN_ABOVE() : VIM_OPEN(); }
          return false;

        case VIM_P:
          if (record->event.pressed) { SHIFTED ? VIM_PUT_BEFORE() : VIM_PUT(); }
          return false;

        case VIM_S:
          if (record->event.pressed) { SHIFTED ? VIM_CHANGE_WHOLE_LINE() : VIM_SUBSTITUTE(); }
          return false;

        case VIM_U:
          if (record->event.pressed) { VIM_UNDO(); }
          return false;

        case VIM_V:
          if (record->event.pressed) { VIM_LEADER(VIM_V); }
          return false;

        case VIM_W:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_WORD(); break;
              case VIM_C: VIM_CHANGE_WORD(); break;
              case VIM_CI: VIM_CHANGE_INNER_WORD(); break;
              case VIM_D: VIM_DELETE_WORD(); break;
              case VIM_DI: VIM_DELETE_INNER_WORD(); break;
              case VIM_V: VIM_VISUAL_WORD(); break;
              case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
            }
          }
          return false;

        case VIM_X:
          if (record->event.pressed) { VIM_CUT(); }
          return false;

        case VIM_Y:
          if (record->event.pressed) { SHIFTED ? VIM_YANK_LINE() : VIM_YANK(); }
          return false;

      }

  }

  /* This is the windows' version */
  if(layer_state_is(3))
  {
      switch (keycode) {

        case VIM_A:
          if (record->event.pressed) { SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND(); }
          return false;

        case VIM_B:
          CTRL(KC_LEFT);
          /* if (record->event.pressed) { */
          /*   switch(VIM_QUEUE) { */
          /*     case KC_NO: VIM_BACK(); break; */
          /*     case VIM_C: VIM_CHANGE_BACK(); break; */
          /*     case VIM_D: VIM_DELETE_BACK(); break; */
          /*     case VIM_V: VIM_VISUAL_BACK(); break; */
          /*   } */
          /* } */
          return false;

        case VIM_C:
          if (record->event.pressed) {
            switch(VIM_QUEUE) {
              case KC_NO: SHIFTED ? VIM_CHANGE_LINE(): VIM_LEADER(VIM_C); break;
              /* case VIM_C: VIM_CHANGE_WHOLE_LINE(); break; */
              case VIM_C: 
                          TAP(KC_HOME);
                          SHIFT(KC_END);
                          CTRL(KC_X);
                          break;
            }
          }
          return false;

        case VIM_D:
          if (record->event.pressed) {
            switch(VIM_QUEUE) {
              case KC_NO: SHIFTED ? CTRL(KC_X) : VIM_LEADER(VIM_D); break;
              case VIM_D: 
                          TAP(KC_HOME);
                          SHIFT(KC_END);
                          CTRL(KC_X);
                          break;
            }
          }
          return false;

        case VIM_E:
          if (record->event.pressed) {
              CTRL(KC_RGHT);
            /* switch (VIM_QUEUE) { */
            /*   case KC_NO: VIM_END(); break; */
            /*   case VIM_C: VIM_CHANGE_END(); break; */
            /*   case VIM_D: VIM_DELETE_END(); break; */
            /*   case VIM_V: VIM_VISUAL_END(); break; */
            /* } */
          }
          return false;

        case VIM_H:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_LEFT(); break;
              case VIM_C: VIM_CHANGE_LEFT(); break;
              case VIM_D: VIM_DELETE_LEFT(); break;
              case VIM_V: VIM_VISUAL_LEFT(); break;
            }
          }
          return false;

        case VIM_I:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              /* case KC_NO: layer_on(INSERT_MODE); break; */
              case VIM_C: VIM_LEADER(VIM_CI); break;
              case VIM_D: VIM_LEADER(VIM_DI); break;
              case VIM_V: VIM_LEADER(VIM_VI); break;
            }
          }
          return false;

        case VIM_J:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_DOWN(); break;
              /*DISABLE JOIN case KC_NO: SHIFTED ? VIM_JOIN() : VIM_DOWN(); break; */
              case VIM_C: VIM_CHANGE_DOWN(); break;
              case VIM_D: VIM_DELETE_DOWN(); break;
              case VIM_V: VIM_VISUAL_DOWN(); break;
            }
          }
          return false;

        case VIM_K:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_UP(); break;
              case VIM_C: VIM_CHANGE_UP(); break;
              case VIM_D: VIM_DELETE_UP(); break;
              case VIM_V: VIM_VISUAL_UP(); break;
            }
          }
          return false;

        case VIM_L:
          if (record->event.pressed) {
            switch (VIM_QUEUE) {
              case KC_NO: VIM_RIGHT(); break;
              case VIM_C: VIM_CHANGE_RIGHT(); break;
              case VIM_D: VIM_DELETE_RIGHT(); break;
              case VIM_V: VIM_VISUAL_RIGHT(); break;
            }
          }
          return false;

        case VIM_O:
          if (record->event.pressed) { 
              /* SHIFTED ? VIM_OPEN_ABOVE() : VIM_OPEN(); */
              TAP(KC_ENT);
          }
          return false;

        case VIM_P:
          if (record->event.pressed) { 
              /* SHIFTED ? VIM_PUT_BEFORE() : VIM_PUT(); */ 
              CTRL(KC_V);
          }
          return false;

        case VIM_S:
          if (record->event.pressed) { SHIFTED ? VIM_CHANGE_WHOLE_LINE() : VIM_SUBSTITUTE(); }
          return false;

        case VIM_U:
          if (record->event.pressed) { CTRL(KC_Z); }
          return false;

        case VIM_V:
          if (record->event.pressed) { VIM_LEADER(VIM_V); }
          return false;

        case VIM_W:
          if (record->event.pressed) {
              PRESS(KC_LCTL);
                TAP(KC_RIGHT);
                TAP(KC_RIGHT);
                TAP(KC_LEFT);
              RELEASE(KC_LCTL);
            /* switch (VIM_QUEUE) { */
            /*   case KC_NO: VIM_WORD(); break; */
            /*   case VIM_C: VIM_CHANGE_WORD(); break; */
            /*   case VIM_CI: VIM_CHANGE_INNER_WORD(); break; */
            /*   case VIM_D: VIM_DELETE_WORD(); break; */
            /*   case VIM_DI: VIM_DELETE_INNER_WORD(); break; */
            /*   case VIM_V: VIM_VISUAL_WORD(); break; */
            /*   case VIM_VI: VIM_VISUAL_INNER_WORD(); break; */
            /* } */
          }
          return false;

        case VIM_X:
          if (record->event.pressed) { 
              /* VIM_CUT(); */ 
              TAP(KC_DEL);
          }
          return false;

        case VIM_Y:
          if (record->event.pressed) { 
              /* SHIFTED ? VIM_YANK_LINE() : VIM_YANK(); */
              CTRL(KC_C);
          }
          return false;

      }

  }

  // End by clearing the queue unless keycode is a
  // if ((record->event.pressed) &&
  //     (keycode != VIM_I ||
  //     keycode != VIM_C ||
  //     keycode != VIM_D ||
  //     keycode != VIM_V)) {
  //   VIM_LEADER(KC_NO);
  // }

  return true;
}; 
