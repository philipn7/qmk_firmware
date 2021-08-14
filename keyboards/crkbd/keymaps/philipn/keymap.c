#include QMK_KEYBOARD_H

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

enum layers { BASE, NAV, SYM, NUM, FUN };

#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)


#ifdef OLED_DRIVER_ENABLE
#    include "oled.c"
#endif

enum {
  TD_Q_NAV,
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Q_NAV] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_Q, NAV)
};

enum keycodes {
  B_SCRL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_miryoku(
    TD(TD_Q_NAV),      ALGR_T(KC_W),      KC_F,              KC_P,              B_SCRL,                  KC_J,              KC_L,              KC_U,                KC_Y,              KC_QUOT,
    LT(NAV, KC_A),     KC_R,              KC_S,              KC_T,              KC_G,                  KC_M,              KC_N,              KC_E,                KC_I,              LT(NUM, KC_O),
    KC_Z,              LALT_T(KC_X),      LCTL_T(KC_C),      LSFT_T(KC_D),      LGUI_T(KC_V),          LGUI_T(KC_K),      LSFT_T(KC_H),      LCTL_T(KC_COMM),     LALT_T(KC_DOT),    KC_SLSH,
    U_NP,              U_NP,              LSFT_T(KC_SPC),    LCTL_T(KC_TAB),    KC_ESC,                LT(FUN,KC_DEL),    LT(NUM, KC_ENT),   LT(SYM, KC_BSPC),       U_NP,              U_NP
  ),
  [NAV] = LAYOUT_miryoku(
    TO(0),   KC_ALGR, U_NA,    U_NA,    KC_NLCK,    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,
    U_NA,    U_CUT,   U_CPY,   U_PST,   U_NA,       KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    RESET, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,  
    U_NP,    U_NP,    KC_BTN1, KC_BTN2, KC_BTN3,    KC_DEL,  KC_ENT,  KC_BSPC,   U_NP,    U_NP
  ),
  [NUM] = LAYOUT_miryoku(
   KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, U_NA,                       KC_PLUS,  KC_7,    KC_8,    KC_9,    KC_BSPC,
   U_NA,    U_NA,    U_NA,    KC_COMM, U_NA,                       KC_0,     KC_4,    KC_5,    KC_6,    KC_SLSH,
   U_NA,    KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,                    KC_MINS,  KC_1,    KC_2,    KC_3,    KC_ASTR,
   U_NP,    U_NP,    KC_SPC,  KC_DOT,  KC_UNDS,                    U_NA,     U_NA,    U_NA,    U_NP,    U_NP
  ),
  [SYM] = LAYOUT_miryoku(
    KC_LCBR, KC_EXLM, KC_AT,  KC_RCBR, KC_PIPE,           U_NA,       KC_BSLS,       KC_SLSH,    U_NA,     KC_DQUO,
    KC_LPRN, KC_HASH, KC_DLR,   KC_RPRN, KC_GRV,          KC_PLUS,    KC_MINS,       KC_ASTR,  KC_COLN,    KC_SCLN,    
    KC_LBRC, KC_PERC, KC_CIRC,   KC_RBRC, KC_TILD,        KC_AMPR,    KC_EQL,        KC_LT,      KC_GT,    KC_QUES,
    U_NP,    U_NP,    KC_SPC,  KC_UNDS, KC_DOT,           U_NA,       U_NA,          U_NA,       U_NP,       U_NP
  ), 
  [FUN] = LAYOUT_miryoku(
    RESET,   KC_ALGR, U_NA,    U_NA,    U_NA,    KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    KC_SLCK, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    U_NA,    KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,  U_NP,    U_NP
  )
};
  

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef OLED_DRIVER_ENABLE
  // tell the oled code about the key
  process_record_user_oled(keycode, record);
  #endif

  static uint16_t my_hash_timer;
  switch (keycode) {
    case B_SCRL:
      // Hold for numlock, key b otherwise
      if (record->event.pressed) {
        // Do something when pressed 
        my_hash_timer = timer_read();
        
        if (!host_keyboard_led_state().num_lock) {
          tap_code(KC_NUMLOCK);
        }
      } else {
        // Do something else when release
        if (host_keyboard_led_state().num_lock) {
          tap_code(KC_NUMLOCK);
        }
        if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
          tap_code(KC_B);
        }
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}