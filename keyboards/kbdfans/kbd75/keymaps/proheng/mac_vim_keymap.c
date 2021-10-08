#include "vim_helper.c"
#include "config.h"
#include "print.h"
#include "keycode.h"
#include "quantum.h"
#include "quantum_keycodes.h"


void mac_vim_visual_keymap(uint16_t keycode, keyrecord_t *record){
    switch(keycode){
        case VIM_Y:
            if(record->event.pressed)
            {
                CTRL(KC_INS);
                layer_move(MAC_VIM);
            }
            break;
        case VIM_X:
            if(record->event.pressed)
            {
                CMD(KC_X);
                layer_move(MAC_VIM);
            }
            break;
    }
}
