#include QMK_KEYBOARD_H


enum custom_keycodes {
    TEST = SAFE_RANGE,
    SWITCH_WIN,
    SWITCH_MAC
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TEST:
            if (record->event.pressed) {
            } 
            break;
        case SWITCH_MAC:
            if (record->event.pressed) {
                /* rgblight_sethsv(0, 255, 255); */
                layer_move(0);
            } 
            break;
        case SWITCH_WIN:
            if (record->event.pressed) {
                /* rgblight_sethsv(140, 255, 255); */
                layer_move(1);
            } 
            break;
    }

    return true;
};

