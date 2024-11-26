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

enum combos { COMBO_ESC, COMBO_TAB, COMBO_DEL, COMBO_CAPS };

enum layer_names { BASE, NUM, SYM, NAV, FN };

const uint16_t PROGMEM combo_tab[]  = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_del[]  = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_caps[] = {LGUI_T(KC_A), LGUI_T(KC_QUOT), COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {KC_E, KC_R, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC]  = COMBO(combo_esc, KC_ESC),
    [COMBO_TAB]  = COMBO(combo_tab, KC_TAB),
    [COMBO_DEL]  = COMBO(combo_del, KC_DEL),
    [COMBO_CAPS] = COMBO(combo_caps, CW_TOGG),
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case COMBO_CAPS:
            return 200;
    }
    return 15;
}

const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SEMICOLON);
const key_override_t dot_key_override   = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);
const key_override_t del_key_override   = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {&comma_key_override, &dot_key_override, &del_key_override};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_3x5_3(
    KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
    LGUI_T(KC_A),       LALT_T(KC_S),       LCTL_T(KC_D),       LSFT_T(KC_F),       KC_G,           KC_H,           LSFT_T(KC_J),   LCTL_T(KC_K),   LALT_T(KC_L),   LGUI_T(KC_QUOT),
    KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                            KC_ESC,             LT(NAV,KC_LSFT),    LT(NUM,KC_ENT), LT(SYM,KC_SPC), LT(FN,KC_BSPC), KC_DEL
),

[NUM] = LAYOUT_split_3x5_3(
    KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_0,
    KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NA,              KC_4,              KC_5,              KC_6,              U_NA,
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              KC_0,              KC_1,              KC_2,              KC_3,              U_NA,
                                          U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA
),

[SYM] = LAYOUT_split_3x5_3(
    KC_EXLM,           KC_AT,             KC_HASH,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_AMPR,           KC_ASTR,           KC_GRAVE,          KC_TILD,
    KC_BSLS,           KC_PIPE,           KC_LPRN,           KC_RPRN,           KC_MINS,           KC_EQL,            KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,
    KC_LT,             KC_GT,             KC_LCBR,           KC_RCBR,           KC_UNDS,           KC_PLUS,           KC_LBRC,           KC_RBRC,           U_NA,              U_NA,
                                          U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA
),

[NAV] = LAYOUT_split_3x5_3(
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            U_NA,
    KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RIGHT,          KC_BSPC,
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              KC_DEL,
                                          U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA
),

[FN] = LAYOUT_split_3x5_3(
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,
    U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,
                                          U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA
)
};
