#include QMK_KEYBOARD_H
#include "artsey.h"
#include "keymap_combo.h"
#include "artsey.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_A_BASE] = LAYOUT(
    A_BASE_O, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______, A_BASE_S,A_BASE_T,A_BASE_R, A_BASE_A, _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,_______,  A_BASE_O,A_BASE_I,A_BASE_Y, A_BASE_E,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______, _______, _______,                     _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_A_NUM] = LAYOUT(
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______, A_NUM_S,A_NUM_T,A_NUM_R, A_NUM_A, _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______, _______,  A_NUM_O,A_NUM_I,A_NUM_Y, A_NUM_E, _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______, _______, _______,                     _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_A_NAV] = LAYOUT(
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______, A_NAV_S,A_NAV_T,A_NAV_R, A_NAV_A, _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______, _______,  A_NAV_O,A_NAV_I,A_NAV_Y, A_NAV_E, _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______, _______, _______,                     _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_A_SYM] = LAYOUT(
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______, A_SYM_S,A_SYM_T,A_SYM_R, A_SYM_A, _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______, _______, A_SYM_O,A_SYM_I,A_SYM_Y, A_SYM_E,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______, _______, _______,                     _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_A_BRAC] = LAYOUT(
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______, A_BRAC_S,A_BRAC_T,A_BRAC_R, A_BRAC_A, _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  _______, A_BRAC_O,A_BRAC_I,A_BRAC_Y, A_BRAC_E, _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______, _______, _______,                     _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_A_MOU] = LAYOUT(
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______, A_MOU_S,A_MOU_T,A_MOU_R, A_MOU_A, _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  _______,A_MOU_O,A_MOU_I,A_MOU_Y, A_MOU_E,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______, _______, _______,                     _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_A_CUSTOM] = LAYOUT(
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______, A_CUSTOM_S,A_CUSTOM_T,A_CUSTOM_R, A_CUSTOM_A, _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______, _______, A_CUSTOM_O,A_CUSTOM_I,A_CUSTOM_Y, A_CUSTOM_E,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______, _______, _______,                     _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  )

};
