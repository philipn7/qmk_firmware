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

// Some basic macros
#define TASK    LCTL(LSFT(KC_ESC))
#define TAB_R   LCTL(KC_TAB)
#define TAB_L   LCTL(LSFT(KC_TAB))
#define TAB_RO  LCTL(LSFT(KC_T))

enum keycodes {
  G_SCRL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_5x7(
  // left hand
   KC_ESC,    KC_Q,         KC_W,    KC_F,   KC_P,   KC_B,   KC_NUMLOCK,
   KC_LCTL,   KC_A,         KC_R,    KC_S,   KC_T,   KC_G,   TO(NAV),
   KC_LSHIFT, KC_Z,         KC_X,    KC_C,   KC_D,   KC_V,
   KC_LALT,   KC_LGUI,      TAB_L,   TAB_R,
                                      KC_SPC,   LT(NAV,KC_HOME),   KC_END,
                                                KC_TAB,   KC_LALT,
        // right hand
                     KC_BTN1,    KC_J,    KC_L,    KC_U,     KC_Y,     KC_QUOT,     KC_DEL,
                      KC_BTN2,   KC_M,    KC_N,    KC_E,     KC_I,     KC_O,     KC_ENT,
                                 KC_K,    KC_H,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_CAPS,
                                                 KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
        MO(FUN),    MO(NUM),    LT(SYM, KC_BSPC),
        KC_PGUP, KC_PGDN ),

[NAV] = LAYOUT_5x7(
  // left hand
   RESET,    U_NA,        U_NA,    U_NA,   U_NA,   U_NA,   KC_NUMLOCK,
   KC_LCTL,   U_NA,       U_CUT,   U_CPY,  U_PST,  G_SCRL,   TO(BASE),
   KC_LSHIFT, U_UND,      U_RDO,    U_NA,   U_NA,   U_NA,
   KC_LALT,   RESET,      TAB_L,   TAB_R,
                                      KC_BTN1,   KC_BTN2,   KC_BTN3,
                                                KC_TAB,   KC_LALT,
        // right hand
                     KC_BTN1,    KC_INS,  KC_HOME, KC_UP,   KC_END,  U_NA,     KC_DEL,
                      KC_BTN2,   U_NA,    KC_LEFT, KC_DOWN, KC_RGHT, U_NA,     KC_ENT,
                                 U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    KC_CAPS,
                                                 KC_LEFT,   KC_UP,   KC_DOWN,  KC_RGHT,
        U_NA,    U_NA,    KC_BSPC,
        KC_PGUP, KC_PGDN ),

[SYM] = LAYOUT_5x7(
  // left hand
   KC_ESC,    KC_LCBR, KC_EXLM, KC_AT,  KC_RCBR, KC_PIPE,   KC_NUMLOCK,
   KC_LCTL,   KC_LPRN, KC_HASH, KC_DLR,   KC_RPRN, KC_GRV,   TO(NAV),
   KC_LSHIFT, KC_LBRC, KC_PERC, KC_CIRC,   KC_RBRC, KC_TILD, 
   KC_LALT,   KC_LGUI, TAB_L,   TAB_R,
                                      KC_SPC,   KC_UNDS, KC_DOT,
                                                KC_TAB,   KC_LALT,
        // right hand
                     KC_BTN1,   U_NA,       KC_BSLS,       KC_SLSH,    U_NA,     KC_DQUO,     KC_DEL,
                      KC_BTN2,  KC_PLUS,    KC_MINS,       KC_ASTR,  KC_COLN,    KC_SCLN,     KC_ENT,
                                KC_AMPR,    KC_EQL,        KC_LT,      KC_GT,    KC_QUES,  KC_CAPS,
                                                           KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
        U_NA,    U_NA,    U_NA,
        U_NA, U_NA ),

[NUM] = LAYOUT_5x7(
  // left hand
   KC_ESC,    KC_LCBR, KC_EXLM, KC_AT,  KC_RCBR, KC_PIPE,   KC_NUMLOCK,
   KC_LCTL,   KC_LPRN, KC_HASH, KC_DLR,   KC_RPRN, KC_GRV,   TO(NAV),
   KC_LSHIFT, KC_LBRC, KC_PERC, KC_CIRC,   KC_RBRC, KC_TILD,
   KC_LALT,   KC_LGUI, TAB_L,   TAB_R,
                                      KC_SPC,   KC_UNDS,   KC_DOT,
                                                KC_TAB,   KC_LALT,
        // right hand
                     KC_BTN1,   KC_PLUS,  KC_7,    KC_8,    KC_9,    KC_BSPC,     KC_DEL,
                     KC_BTN2,   KC_0,     KC_4,    KC_5,    KC_6,    KC_ASTR,     KC_ENT,
                                KC_MINS,  KC_1,    KC_2,    KC_3,     KC_SLSH,  KC_CAPS,
                                                   KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
        U_NA,    U_NA,    U_NA,
        U_NA, U_NA ),

[FUN] = LAYOUT_5x7(
  // left hand
   KC_ESC,    U_NA,    U_NA, U_NA,    U_NA,    U_NA,   KC_NUMLOCK,
   KC_LCTL,   U_NA,    U_NA, U_NA,    U_NA,    U_NA,   TO(NAV),
   KC_LSHIFT, U_NA,    U_NA, U_NA,    U_NA,    U_NA,
   KC_LALT,   KC_LGUI,      U_NA,    U_NA,
                                      U_NA,    U_NA,    U_NA,
                                                U_NA,   KC_LALT,
        // right hand
                     KC_BTN1,    KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,     KC_DEL,
                      KC_BTN2,   KC_SLCK, KC_F4,   KC_F5,   KC_F6,   KC_F11,     KC_ENT,
                                 KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_CAPS,
                                                 KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
        U_NA,    U_NA,    U_NA,
        U_NA, U_NA )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t my_hash_timer;
  switch (keycode) {
    case G_SCRL:
      // Hold for numlock, key g otherwise
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
          tap_code(KC_G);
        }
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}