#include QMK_KEYBOARD_H
#include "tap_dance.c"

enum layer_number {
    _QWERTY     = 0,
    _QWERTY_MAC = 1,
    _VIM        = 2,
    _VIM_MAC    = 3,
    _LOWER      = 4,
};

enum my_keycodes { LEFT_KNOB = SAFE_RANGE, RIGHT_KNOB };

uint16_t left_knob_step  = 0;
uint16_t right_knob_step = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |TD_CAP|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |RSFT J|RGUI K|RALT L|RCTL ;|  '   |
     * |------+------+------+------+------+------| L_KNOB|    |R_KNOB |------+------+------+------+------+------|
     * | LSFT |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RSFT |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |  LGUI | MO(_VIM) | Space/|SFT_CST/       \  ENT \| BackSP  |TD_CAD | RGUI |
     *                   `-----------------------------'        '--------------------------------'
     */

    [_QWERTY]     = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, LCTL_T(KC_Q), LALT_T(KC_W), LGUI_T(KC_E), LSFT_T(KC_R), KC_T, KC_Y, RSFT_T(KC_U), RGUI_T(KC_I), RALT_T(KC_O), RCTL_T(KC_P), KC_EQL, TD(TD_CAP), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, LT(0, KC_Z), LT(0, KC_X), LT(0, KC_C), LT(0, KC_V), LT(0, KC_B), LEFT_KNOB, RIGHT_KNOB, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_MEDIA_PLAY_PAUSE, MO(_VIM), LCTL_T(KC_SPC), C_S_T(KC_ENT), LCA_T(KC_ENT), LT(_VIM, KC_BSPC), TD(TD_CAD), KC_MEDIA_PLAY_PAUSE),
    [_QWERTY_MAC] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, LCTL_T(KC_Q), LALT_T(KC_W), LGUI_T(KC_E), LSFT_T(KC_R), KC_T, KC_Y, RSFT_T(KC_U), RGUI_T(KC_I), RALT_T(KC_O), RCTL_T(KC_P), KC_EQL, TD(TD_CAP), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, _______, _______, _______, _______, _______, LEFT_KNOB, RIGHT_KNOB, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_MEDIA_PLAY_PAUSE, MO(_VIM_MAC), LGUI_T(KC_SPC), LSG_T(KC_ENT), LAG_T(KC_ENT), LT(_VIM_MAC, KC_BSPC), TD(TD_CAD), KC_MEDIA_PLAY_PAUSE),
    /* _VIM
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |VIM W |VIM E |      |      |                    | COPY | UNDO |      |      |PASTE |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |VIM D |      |      |-------.    ,-------| LEFT | DOWN |  UP  |RIGHT | HOME | END  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |______|      |VIM X |      |      |VIM B |-------|    |-------|      | PGDN | PGUP |      |      |______|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |       |/       /       \      \|      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_VIM]     = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(TD_KC_LBRC), TD(TD_KC_RBRC), TD(TD_KC_BSLS), XXXXXXX, XXXXXXX, LCTL(KC_RGHT), LCTL(KC_RGHT), XXXXXXX, XXXXXXX, RCTL(KC_INS), RCTL(KC_Z), XXXXXXX, XXXXXXX, RSFT(KC_INS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_HOME, KC_END, _______, XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX, LCTL(KC_LEFT), XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    [_VIM_MAC] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(TD_KC_LBRC), TD(TD_KC_RBRC), TD(TD_KC_BSLS), XXXXXXX, XXXXXXX, LALT(KC_RGHT), LALT(KC_RGHT), XXXXXXX, XXXXXXX, RCTL(KC_INS), RCTL(KC_Z), XXXXXXX, XXXXXXX, RSFT(KC_INS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, LGUI(KC_LEFT), LGUI(KC_RIGHT), _______, XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX, LALT(KC_LEFT), XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   `  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   -  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  | F12  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |______|______|______| /Enter  /       \Enter \  |______|______|______|
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LOWER] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_F12, _______, _______, _______, _______, _______, _______, _______, _______)};

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
static void render_custom_logo(void) {
    static const char PROGMEM qmk_custom_logo[] = {153, 154, 10, 185, 186, 0};

    oled_write_P(qmk_custom_logo, false);
}

bool oled_task_kb(void) {
    if (is_keyboard_master()) {
        switch (left_knob_step % 2) {
            case 0:
                oled_write_ln_P(PSTR("Windows Movement"), false);
                break;
            case 1:
                oled_write_ln_P(PSTR("Winodws Movement Mac"), false);
                break;
        }
        // If you want to change the display of OLED, you need to change here
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _QWERTY_MAC:
                oled_write_P(PSTR("QWERTY MAC\n"), false);
                break;
            case _VIM:
                oled_write_P(PSTR("VIM\n"), false);
                break;
            case _VIM_MAC:
                oled_write_P(PSTR("VIM MAC\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("LOWER\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }
    } else {
        render_custom_logo();
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LEFT_KNOB:
            if (record->event.pressed) {
                left_knob_step = left_knob_step + 1;

                if (layer_state_is(_QWERTY)) {
                    layer_move(_QWERTY_MAC);
                } else if (layer_state_is(_QWERTY_MAC)) {
                    layer_move(_QWERTY);
                }
            }
            return true;
        case RIGHT_KNOB:
            if (record->event.pressed) {
                right_knob_step = right_knob_step + 1;
            }
            return true;
        case LCTL_T(KC_SPC):
            if (!record->tap.count && record->event.pressed) {
                oled_write_ln_P(PSTR("CTRL HOLDED\n"), false);
            } else {
                oled_clear();
            }
            return true;
        case LT(0, KC_X):
            if (!record->tap.count && record->event.pressed) {
                if (layer_state_is(_QWERTY_MAC)) {
                    tap_code16(LGUI(KC_X)); // Intercept hold function to send CMD-X
                }
                if (layer_state_is(_QWERTY)) {
                    tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
                }
            }
            return true; // Return true for normal processing of tap keycode
        case LT(0, KC_C):
            if (!record->tap.count && record->event.pressed) {
                if (layer_state_is(_QWERTY_MAC)) {
                    tap_code16(LGUI(KC_C)); // Intercept hold function to send CMD-X
                }
                if (layer_state_is(_QWERTY)) {
                    tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-X
                }
            }
            return true; // Return true for normal processing of tap keycode
        case LT(0, KC_V):
            if (!record->tap.count && record->event.pressed) {
                if (layer_state_is(_QWERTY_MAC)) {
                    tap_code16(LGUI(KC_V)); // Intercept hold function to send CMD-X
                }
                if (layer_state_is(_QWERTY)) {
                    tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-X
                }
            }
            return true; // Return true for normal processing of tap keycode
        case LT(0, KC_Z):
            if (!record->tap.count && record->event.pressed) {
                if (layer_state_is(_QWERTY_MAC)) {
                    tap_code16(LGUI(KC_Z)); // Intercept hold function to send CMD-X
                }
                if (layer_state_is(_QWERTY)) {
                    tap_code16(C(KC_Z)); // Intercept hold function to send Ctrl-X
                }
            }
            return true; // Return true for normal processing of tap keycode
        case LT(0, KC_B):
            if (!record->tap.count && record->event.pressed) {
                if (layer_state_is(_QWERTY_MAC)) {
                    tap_code16(LGUI(KC_B)); // Intercept hold function to send CMD-X
                }
                if (layer_state_is(_QWERTY)) {
                    tap_code16(C(KC_B)); // Intercept hold function to send Ctrl-X
                }
            }
            return true; // Return true for normal processing of tap keycode
        default:
            return true;
    }
}

/* The encoder_update_user is a function.
 * It'll be called by QMK every time you turn the encoder.
 *
 * The index parameter tells you which encoder was turned. If you only have
 * one encoder, the index will always be zero.
 *
 * The clockwise parameter tells you the direction of the encoder. It'll be
 * true when you turned the encoder clockwise, and false otherwise.
 */
bool     is_alt_tab_active  = false;
uint16_t alt_tab_timer      = 0;
bool     is_ctrl_tab_active = false;
uint16_t ctrl_tab_timer     = 0;
bool     is_gui_tab_active  = false;
uint16_t gui_tab_timer      = 0;

void knob_windows_movement(bool clockwise) {
    if (clockwise) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);

    } else {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(S(KC_TAB));
    }
}

void knob_windows_movement_mac(bool clockwise) {
    if (clockwise) {
        if (!is_gui_tab_active) {
            is_gui_tab_active = true;
            register_code(KC_LGUI);
        }
        gui_tab_timer = timer_read();
        tap_code16(KC_TAB);
    } else {
        if (!is_gui_tab_active) {
            is_gui_tab_active = true;
            register_code(KC_LGUI);
        }
        gui_tab_timer = timer_read();
        tap_code16(S(KC_TAB));
    }
}
void knob_tab_movement(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
        // if (!is_ctrl_tab_active) {
        //     is_ctrl_tab_active = true;
        //     register_code(KC_LCTL);
        // }
        // ctrl_tab_timer = timer_read();
        // tap_code16(KC_TAB);
    } else {
        tap_code(KC_VOLD);
        // if (!is_ctrl_tab_active) {
        //     is_ctrl_tab_active = true;
        //     register_code(KC_LCTL);
        // }
        // ctrl_tab_timer = timer_read();
        // tap_code16(S(KC_TAB));
    }
}

void knob_tab_movement_mac(bool clockwise) {
    if (clockwise) {
        register_code(KC_KB_VOLUME_UP);
        unregister_code(KC_KB_VOLUME_UP);
        // if (!is_gui_tab_active) {
        //     is_gui_tab_active = true;
        //     register_code(KC_LGUI);
        // }
        // gui_tab_timer = timer_read();
        // tap_code16(A(KC_RIGHT));
    } else {
        register_code(KC_KB_VOLUME_DOWN);
        unregister_code(KC_KB_VOLUME_DOWN);
        // if (!is_gui_tab_active) {
        //     is_gui_tab_active = true;
        //     register_code(KC_LGUI);
        // }
        // gui_tab_timer = timer_read();
        // tap_code16(A(KC_LEFT));
    }
}

void knob_scrolling(bool clockwise) {
    if (clockwise) {
        tap_code(KC_PGDN);
    } else {
        tap_code(KC_PGUP);
    }
}
void knob_action_switcher(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (left_knob_step % 2) {
            case 0:
                knob_windows_movement(clockwise);
                break;
            case 1:
                knob_windows_movement_mac(clockwise);
                break;
        }
    }
    if (index == 1) {
        switch (right_knob_step % 2) {
            case 0:
                knob_tab_movement(clockwise);
                break;
            case 1:
                knob_tab_movement_mac(clockwise);
                break;
        }
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    knob_action_switcher(index, clockwise);
    return false;
}
void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 500) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
    if (is_ctrl_tab_active) {
        if (timer_elapsed(ctrl_tab_timer) > 100) {
            unregister_code(KC_LCTL);
            is_ctrl_tab_active = false;
        }
    }
    if (is_gui_tab_active) {
        if (timer_elapsed(gui_tab_timer) > 500) {
            unregister_code(KC_LGUI);
            is_gui_tab_active = false;
        }
    }
}
