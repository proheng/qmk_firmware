#include QMK_KEYBOARD_H


enum custom_keycodes {
    VIM_ON = SAFE_RANGE,
    VIM_OFF
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_ON:
            if (record->event.pressed) {
                layer_on(2);
            } 
            break;
        case VIM_OFF:
            if (record->event.pressed) {
                layer_off(2);
            } 
            break;
    }

    return true;
};

