#pragma once

#include "dactyl_manuform.h"

#define LAYOUT_4x7( \
    L11, L12, L13, L14, L15, L16, L17,      \
    L21, L22, L23, L24, L25, L26, L27,      \
    L31, L32, L33, L34, L35, L36,           \
    L41, L42, L43, L44,                     \
                        L45, L46, L47,       \
                             L56, L57,       \
         R11, R12, R13, R14, R15, R16, R17, \
         R21, R22, R23, R24, R25, R26, R27, \
              R32, R33, R34, R35, R36, R37, \
                        R44, R45, R46, R47, \
         R41, R42, R43,                     \
         R51, R52                          \
  ) \
  { \
    { L11,   L12,   L13, L14, L15, L16,   L17   }, \
    { L21,   L22,   L23, L24, L25, L26,   L27   }, \
    { L31,   L32,   L33, L34, L35, L36,   KC_NO }, \
    { L41,   L42,   L43, L44, L45, L46,   L47   }, \
    { KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,L56,  L57   }, \
    { R11,   R12,   R13, R14, R15, R16,   R17   }, \
    { R21,   R22,   R23, R24, R25, R26,   R27   }, \
    { KC_NO, R32,   R33, R34, R35, R36,   R37   }, \
    { R41,   R42,   R43, R44, R45, R46,   R47   }, \
    { R51,   R52,  KC_NO,KC_NO,KC_NO,KC_NO,KC_NO}, \
}
