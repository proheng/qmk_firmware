#include "config.h"
#include "action_layer.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "key.c"
#define PRESS(keycode) register_code16(keycode)
#define RELEASE(keycode) unregister_code16(keycode)

#define KC_CAD	LALT(LCTL(KC_DEL))

void TAP(uint16_t keycode) {
    PRESS(keycode);
    RELEASE(keycode);
}

void CMD(uint16_t keycode) {
  PRESS(KC_LGUI);
    TAP(keycode);
  RELEASE(KC_LGUI);
}

void CTRL(uint16_t keycode) {
  PRESS(KC_LCTRL);
    TAP(keycode);
  RELEASE(KC_LCTRL);
}

void SHIFT(uint16_t keycode) {
  PRESS(KC_LSHIFT);
    TAP(keycode);
  RELEASE(KC_LSHIFT);
}

void ALT(uint16_t keycode) {
  PRESS(KC_LALT);
    TAP(keycode);
  RELEASE(KC_LALT);
}


/* Quad Function Tap-Dance */
/* https://beta.docs.qmk.fm/using-qmk/software-features/feature_tap_dance#example-4-quad-function-tap-dance-id-example-4 */
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;



// For the x tap dance. Put it here so it can be used in any keymap

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};


/* ------------------------------------------------------------------------------------------------------- */
/* These are the key specified handler */
/* ------------------------------------------------------------------------------------------------------- */

void cad_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            set_oneshot_layer(4, ONESHOT_START); break;
        case TD_DOUBLE_TAP:
            keys();
            break;
        case TD_TRIPLE_TAP:
            tap_code16(KC_CAD);
            break;
        case TD_SINGLE_HOLD:
            layer_on(4);
            break;
        default:
            break;
    }
}

void cad_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            clear_oneshot_layer_state(ONESHOT_PRESSED); break;
            break;
        case TD_SINGLE_HOLD:
            layer_off(4);
            break;
        default:
            break;
    }
    tap_state.state = TD_NONE;
}

void cap_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            TAP(KC_ESC); break;
        case TD_SINGLE_HOLD:
            oled_write_P(PSTR("CTRL HOLDED\n"), false);
            PRESS(KC_LCTL); break;
        default:
            break;
    }
}

void cap_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_HOLD:
            oled_clear();
            RELEASE(KC_LCTL);
            break;
        default:
            break;

    }
    tap_state.state = TD_NONE;
}

enum {
    TD_CAD = 0,
    TD_CAP = 1,
    TD_KC_LBRC = 2,
    TD_KC_RBRC = 3,
    TD_KC_BSLS = 4
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAD] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, cad_finished, cad_reset),
    [TD_CAP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, cap_finished, cap_reset),
    [TD_KC_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC,S(KC_LBRC)),
    [TD_KC_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC,S(KC_RBRC)),
    [TD_KC_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS,S(KC_BSLS)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
    switch(keycode){
        default:
            return TAPPING_TERM;

    }
}
