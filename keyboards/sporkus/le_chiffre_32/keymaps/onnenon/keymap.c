/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "../../rgb.c"

enum combos { COMBO_ESC, COMBO_TAB, COMBO_DEL, COMBO_CAPS };

enum layer_names { BASE, NUM, SYM, NAV, FN };

const uint16_t PROGMEM combo_tab[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {LGUI_T(KC_A), LGUI_T(KC_QUOT),
                                       COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_R, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
    [COMBO_DEL] = COMBO(combo_del, KC_DEL),
    [COMBO_CAPS] = COMBO(combo_caps, CW_TOGG),
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
  case COMBO_CAPS:
    return 200;
  }
  return 15;
}

const key_override_t comma_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SEMICOLON);
const key_override_t dot_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);
const key_override_t del_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {&comma_key_override, &dot_key_override,
                                         &del_key_override};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
    KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,           KC_MUTE,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
    LGUI_T(KC_A),       LALT_T(KC_S),       LCTL_T(KC_D),       LSFT_T(KC_F),       KC_G,                              KC_H,           LSFT_T(KC_J),   LCTL_T(KC_K),   LALT_T(KC_L),   LGUI_T(KC_QUOT),
    KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,                              KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                                                LT(NAV,KC_LSFT),    LT(NUM,KC_ENT),                    LT(SYM,KC_SPC), LT(FN,KC_BSPC)
),

[NUM] = LAYOUT(
    KC_1,              KC_2,              KC_3,              KC_4,              KC_5,               KC_MUTE,           KC_6,              KC_7,              KC_8,              KC_9,              KC_0,
    KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                  U_NA,              KC_4,              KC_5,              KC_6,              U_NA,
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,                                  KC_0,              KC_1,              KC_2,              KC_3,              U_NA,
                                                             U_NA,              U_NA,                                  U_NA,              U_NA
),

[SYM] = LAYOUT(
    KC_EXLM,           KC_AT,             KC_HASH,           KC_DLR,            KC_PERC,            KC_MUTE,           KC_CIRC,           KC_AMPR,           KC_ASTR,           KC_GRAVE,          KC_TILD,
    KC_BSLS,           KC_PIPE,           KC_LPRN,           KC_RPRN,           KC_MINS,                               KC_EQL,            KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,
    KC_LT,             KC_GT,             KC_LCBR,           KC_RCBR,           KC_UNDS,                               KC_PLUS,           KC_LBRC,           KC_RBRC,           U_NA,              U_NA,
                                                             U_NA,              U_NA,                                  U_NA,              U_NA
),

[NAV] = LAYOUT(
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,               KC_MUTE,           KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            U_NA,
    KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                  KC_LEFT,           KC_DOWN,           KC_UP,             KC_RIGHT,          KC_BSPC,
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,                                  U_NA,              U_NA,              U_NA,              U_NA,              KC_DEL,
                                                             U_NA,              U_NA,                                  U_NA,              U_NA
),

[FN] = LAYOUT(
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,               KC_MUTE,           U_NA,              U_NA,              U_NA,              U_NA,              U_NA,
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,                                  U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,                                  U_NA,              U_NA,              U_NA,              U_NA,              U_NA,
                                                             U_NA,              U_NA,                                  U_NA,              U_NA
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// }

// bool oled_task_user(void) {
//     render_logo();
//     return false;
// }

void board_init(void) {
  SYSCFG->CFGR1 |= SYSCFG_CFGR1_I2C1_DMA_RMP;
}

void keyboard_post_init_kb(void) {

    #ifdef OLED_ENABLE
    if(!is_oled_on()){
        wait_ms(3000);
        // oled_init(OLED_ROTATION_0);
    }
    #endif

    keyboard_post_init_user();
}

#ifdef OLED_ENABLE
bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }
    oled_write_P(PSTR("Hello"), false);
}
#endif