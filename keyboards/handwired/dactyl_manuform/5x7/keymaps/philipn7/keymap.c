#include QMK_KEYBOARD_H

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

enum layers { BASE, NAV, SYM, NUM, FUN, RST };

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
#define SUP_L   LGUI(KC_LEFT)
#define SUP_R   LGUI(KC_RIGHT)

enum keycodes {
  SCRL_WHL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_5x7(
  // left hand
<<<<<<< HEAD
   KC_ESC,    KC_Q,         KC_W,    KC_F,   KC_P,   KC_B,   KC_BTN3,
   KC_LCTL,   KC_A,         KC_R,    KC_S,   KC_T,   KC_G,   SCRL_WHL,
   KC_LSHIFT, KC_Z,         KC_X,    KC_C,   KC_D,   KC_V,
<<<<<<< HEAD
   U_NA,   U_NA,      U_NA,   TD(TD_RESET),
=======
   SCRL_WHL,   KC_BTN3,      KC_BTN2,   KC_BTN1,
>>>>>>> c913a9b0e4 (moved la)
=======
   KC_ESC,    KC_Q,         KC_W,    KC_F,   KC_P,   KC_B,   MO(RST),
   KC_LCTL,   KC_A,         KC_R,    KC_S,   KC_T,   KC_G,   U_NA,
   KC_LSHIFT, KC_Z,         KC_X,    KC_C,   KC_D,   KC_V,
   SCRL_WHL,   KC_BTN3,      KC_BTN2,   KC_BTN1,
>>>>>>> 0b44eaf3a20cec74b02499ae8a1e606651af3f63
                                         LT(NAV,KC_SPC),   KC_END,  KC_HOME,
                                                KC_TAB,   KC_LALT,
        // right hand
                     KC_BTN1,    KC_J,    KC_L,    KC_U,     KC_Y,     KC_QUOT,     KC_BSPC,
                      KC_BTN2,   KC_M,    KC_N,    KC_E,     KC_I,     KC_O,     KC_ENT,
                                 KC_K,    KC_H,    KC_COMM,  KC_DOT,   KC_SLSH,  OSM(MOD_LSFT),
<<<<<<< HEAD
<<<<<<< HEAD
                                                 U_NA, U_NA,    U_NA,  U_NA,
        MO(FUN),    MO(NUM),    LT(SYM, KC_BSPC),
        U_NA, KC_LGUI ),
=======
                                                 SUP_L, SUP_R,    U_NA,  KC_CAPS,
        MO(FUN),    MO(NUM),    MO(SYM),
        KC_DEL, KC_LGUI ),
>>>>>>> c913a9b0e4 (moved la)

[NAV] = LAYOUT_5x7(
  // left hand
   KC_ESC,    KC_CAPS,        U_NA,    U_NA,   U_NA,   U_NA,   KC_NUMLOCK,
=======
                                                 SUP_L, SUP_R,    U_NA,  KC_CAPS,
        MO(FUN),    MO(NUM),    MO(SYM),
        KC_DEL, KC_LGUI ),

[NAV] = LAYOUT_5x7(
  // left hand
   KC_ESC,    U_NA,        U_NA,    U_NA,   U_NA,   U_NA,   KC_NUMLOCK,
>>>>>>> 0b44eaf3a20cec74b02499ae8a1e606651af3f63
   KC_LCTL,   U_NA,       U_CUT,   U_CPY,  U_PST,  U_NA,   U_NA,
   KC_LSHIFT, U_UND,      U_RDO,    U_NA,   U_NA,   U_NA,
   U_NA,   U_NA,      U_NA,    U_NA,
                                      U_NA,   U_NA,   U_NA,
                                                U_NA,   U_NA,
        // right hand
                     KC_BTN1,    KC_BTN3,  KC_HOME, KC_UP,   KC_END,  U_NA,     KC_BSPC,
                      KC_BTN2,   U_NA,    KC_LEFT, KC_DOWN, KC_RGHT, U_NA,     KC_ENT,
<<<<<<< HEAD
<<<<<<< HEAD
                                 KC_INS,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
                                                 U_NA,   U_NA,   U_NA,  U_NA,
        U_NA,    U_NA,    KC_BSPC,
        U_NA, KC_LGUI ),
=======
=======
>>>>>>> 0b44eaf3a20cec74b02499ae8a1e606651af3f63
                                 KC_INS,    U_NA,    U_NA,    U_NA,    U_NA,    KC_CAPS,
                                                 KC_LEFT,   KC_UP,   KC_DOWN,  KC_RGHT,
        U_NA,    U_NA,    U_NA,
        KC_DEL, KC_LGUI ),
<<<<<<< HEAD
>>>>>>> c913a9b0e4 (moved la)
=======
>>>>>>> 0b44eaf3a20cec74b02499ae8a1e606651af3f63

[SYM] = LAYOUT_5x7(
  // left hand
   KC_ESC,    KC_LCBR, KC_EXLM, KC_AT,  KC_RCBR, KC_PIPE,   U_NA,
   KC_LCTL,   KC_LPRN, KC_HASH, KC_DLR,   KC_RPRN, KC_GRV,   U_NA,
   KC_LSHIFT, KC_LBRC, KC_PERC, KC_CIRC,   KC_RBRC, KC_TILD, 
   U_NA,   U_NA,      U_NA,    U_NA,
                                      KC_SPC,   KC_UNDS, KC_DOT,
                                                KC_TAB,   KC_LALT,
        // right hand
                     KC_BTN1,   U_NA,       KC_BSLS,       KC_SLSH,    U_NA,     KC_DQUO,     KC_BSPC, 
                      KC_BTN2,  KC_PLUS,    KC_MINS,       KC_ASTR,  KC_COLN,    KC_SCLN,     KC_ENT,
                                KC_AMPR,    KC_EQL,        KC_LT,      KC_GT,    KC_QUES,  KC_CAPS,
                                                           KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
        U_NA,    U_NA,    U_NA,
<<<<<<< HEAD
<<<<<<< HEAD
        U_NA, KC_LGUI ),
=======
        KC_DEL, KC_LGUI ),
>>>>>>> c913a9b0e4 (moved la)
=======
        KC_DEL, KC_LGUI ),
>>>>>>> 0b44eaf3a20cec74b02499ae8a1e606651af3f63

[NUM] = LAYOUT_5x7(
  // left hand
   KC_ESC,    KC_LCBR, KC_EXLM, KC_AT,  KC_RCBR, KC_PIPE,   U_NA,
   KC_LCTL,   KC_LPRN, KC_HASH, KC_DLR,   KC_RPRN, KC_GRV,   U_NA,
   KC_LSHIFT, KC_LBRC, KC_PERC, KC_CIRC,   KC_RBRC, KC_TILD,
   U_NA,   U_NA,      U_NA,    U_NA,
                                      KC_SPC,   KC_UNDS,   KC_DOT,
                                                KC_TAB,   KC_LALT,
        // right hand
                     KC_BTN1,   KC_PLUS,  KC_7,    KC_8,    KC_9,    U_NA,     KC_BSPC,
                     KC_BTN2,   KC_0,     KC_4,    KC_5,    KC_6,    KC_ASTR,     KC_ENT,
                                KC_MINS,  KC_1,    KC_2,    KC_3,     KC_SLSH,  KC_CAPS,
                                                   KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
        U_NA,    U_NA,    U_NA,
        KC_DEL, KC_LGUI ),

[FUN] = LAYOUT_5x7(
  // left hand
   KC_ESC,    U_NA,    U_NA, U_NA,    U_NA,    U_NA,   U_NA,
   KC_LCTL,   U_NA,    U_NA, U_NA,    U_NA,    U_NA,   U_NA,
   KC_LSHIFT, U_NA,    U_NA, U_NA,    U_NA,    U_NA,
   U_NA,   U_NA,      U_NA,    U_NA,
                                      U_NA,    U_NA,    U_NA,
                                                U_NA,   KC_LALT,
        // right hand
                     KC_BTN1,    KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,     KC_BSPC,
                      KC_BTN2,   KC_SLCK, KC_F4,   KC_F5,   KC_F6,   KC_F11,     KC_ENT,
                                 KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_CAPS,
                                                 KC_LEFT, KC_UP,    KC_DOWN,  KC_RGHT,
        U_NA,     U_NA,    U_NA,
<<<<<<< HEAD
<<<<<<< HEAD
        U_NA, KC_LGUI ),
=======
        KC_DEL, KC_LGUI ),
>>>>>>> c913a9b0e4 (moved la)
=======
        KC_DEL, KC_LGUI ),
>>>>>>> 0b44eaf3a20cec74b02499ae8a1e606651af3f63

[RST] = LAYOUT_5x7(
  // left hand
   RESET,    U_NA,    U_NA, U_NA,    U_NA,    U_NA,   U_NA,
   U_NA,   U_NA,    U_NA, U_NA,    U_NA,    U_NA,   U_NA,
   U_NA, U_NA,    U_NA, U_NA,    U_NA,    U_NA,
   U_NA,   U_NA,      U_NA,    U_NA,
                                      U_NA,    U_NA,    U_NA,
                                                U_NA,   U_NA,
        // right hand
                     U_NA,    U_NA,    U_NA, U_NA,    U_NA,    U_NA,   U_NA,
                      U_NA,    U_NA,    U_NA, U_NA,    U_NA,    U_NA,   U_NA,
                                 U_NA, U_NA,    U_NA, U_NA,    U_NA,    U_NA,
                                                 U_NA,   U_NA,      U_NA,    U_NA,
        U_NA,    U_NA,    U_NA,
        U_NA, U_NA )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  //static uint16_t my_hash_timer;
  switch (keycode) {
    case SCRL_WHL:
      // Hold for numlock, off otherwise
      if (record->event.pressed) {
        // Do something when pressed 
        //my_hash_timer = timer_read();
        
        if (!host_keyboard_led_state().num_lock) {
          tap_code(KC_NUMLOCK);
        }
      } else {
        // Do something else when release
        if (host_keyboard_led_state().num_lock) {
          tap_code(KC_NUMLOCK);
        }
        //if (timer_elapsed(my_hash_timer) < TAPPING_TERM) {
          // if not held then ?
        //}
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
