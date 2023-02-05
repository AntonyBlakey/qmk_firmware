#include QMK_KEYBOARD_H

#include "version.h"
#include "oneshot.h"

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

// enum { TD_SCLN_COLN};

// #define TD_SCLN TD(TD_SCLN_COLN)

#define TH_SFT MT(MOD_LSFT, KC_SPC)
#define TH_NAV LT(NAV, KC_SPC)

#define TH_LSFT MT(MOD_LSFT, KC_Z)
#define TH_LCTL MT(MOD_LCTL, KC_X)
#define TH_LALT MT(MOD_LALT, KC_C)
#define TH_LCMD MT(MOD_LGUI, KC_V)

#define TH_RCMD MT(MOD_RGUI, KC_M)
#define TH_RALT MT(MOD_RALT, KC_COMM)
#define TH_RCTL MT(MOD_RCTL, KC_DOT)
#define TH_RSFT MT(MOD_RSFT, KC_SCLN)

#define TH_SYM LT(SYM, KC_SPC)
#define TH_CTL MT(MOD_RCTL, KC_SPC)

#define TABL S(KC_TAB)

#define G_SPC G(KC_SPC)
#define C_GRV C(KC_GRV)
#define G_P G(KC_P)
#define GS_P G(S(KC_P))
#define G_Z G(KC_Z)
#define G_X G(KC_X)
#define G_C G(KC_C)
#define G_V G(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,          XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, 
        XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,          XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_ESC,  XXXXXXX,
        XXXXXXX, TH_LSFT, TH_LCTL, TH_LALT, TH_LCMD, KC_B,                               KC_N,    TH_RCMD, TH_RALT, TH_RCTL, TH_RSFT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, TH_SFT,  TH_NAV,           XXXXXXX,          XXXXXXX,          TH_SYM,  TH_CTL,  XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
    ),

    [SYM] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_LT,   KC_LBRC, KC_LCBR, KC_LPRN, KC_SLSH, XXXXXXX,          XXXXXXX, KC_BSLS, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT,   XXXXXXX, 
        XXXXXXX, KC_GRV,  KC_QUOT, KC_DQUO, KC_DLR,  KC_HASH, XXXXXXX,          XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_PERC, KC_ESC,  XXXXXXX,
        XXXXXXX, KC_EXLM, KC_TILD, KC_AMPR, KC_PIPE, KC_CIRC,                            KC_AT,   KC_UNDS, KC_QUES, KC_EQL,  KC_COLN, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, TH_NAV,           XXXXXXX,          XXXXXXX,          TH_SYM,  TH_CTL,  XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
    ),

    [NAV] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LCMD, KC_MPLY, XXXXXXX,          XXXXXXX, TABL,    KC_BSPC, KC_ENT,  KC_TAB,  C_GRV,   XXXXXXX, 
        XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  G_SPC,   XXXXXXX,          XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, GS_P,    XXXXXXX,
        XXXXXXX, G_Z,     G_X,     G_C,     G_V,     XXXXXXX,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  G_P,     XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, TH_SFT,  TH_NAV,           XXXXXXX,          XXXXXXX,          TH_SYM,  TH_CTL,  XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
    ),

    [NUM] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,          XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, 
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,          XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        XXXXXXX, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                             XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_MINS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, TH_SFT,  TH_NAV,           XXXXXXX,          XXXXXXX,          TH_SYM,  TH_CTL,  XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case KC_ESC:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case TH_NAV: 
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer  = get_highest_layer(layer_state);
    bool    layer0 = layer == 0;
    bool    layer1 = layer == 1;
    bool    layer2 = layer == 2;
    bool    layer3 = layer == 3;

    rgb_matrix_set_color_all(RGB_BLACK);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            int keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});
            if (keycode > KC_TRNS) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if ((keycode == KC_CAPS || keycode == TH_SFT) && host_keyboard_led_state().caps_lock) {
                    rgb_matrix_set_color(index, RGB_MAGENTA);
                    continue;
                } else if ((keycode == KC_A || keycode == KC_GRV || keycode == OS_SHFT || keycode == KC_1) && os_shft_state != os_up_unqueued) {
                    rgb_matrix_set_color(index, RGB_MAGENTA);
                    continue;
                } else if ((keycode == KC_S || keycode == KC_QUOT || keycode == OS_CTRL || keycode == KC_2) && os_ctrl_state != os_up_unqueued) {
                    rgb_matrix_set_color(index, RGB_MAGENTA);
                    continue;
                } else if ((keycode == KC_D || keycode == KC_DQUO || keycode == OS_ALT || keycode == KC_3) && os_alt_state != os_up_unqueued) {
                    rgb_matrix_set_color(index, RGB_MAGENTA);
                    continue;
                } else if ((keycode == KC_F || keycode == KC_DLR || keycode == OS_CMD || keycode == KC_4) && os_cmd_state != os_up_unqueued) {
                    rgb_matrix_set_color(index, RGB_MAGENTA);
                    continue;
                } else if (keycode == KC_BSPC) {
                    rgb_matrix_set_color(index, RGB_RED);
                    continue;
                } else if (layer0)
                    rgb_matrix_set_color(index, RGB_WHITE);
                else if (layer1)
                    rgb_matrix_set_color(index, RGB_CYAN);
                else if (layer2)
                    rgb_matrix_set_color(index, RGB_GREEN);
                else if (layer3)
                    rgb_matrix_set_color(index, RGB_RED);
            }
        }
    }

    ML_LED_1(layer1);
    ML_LED_2(layer2);
    ML_LED_3(layer3);
    ML_LED_4(layer1);
    ML_LED_5(layer2);
    ML_LED_6(layer3);
}

// Tap Dance definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     [TD_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
// };
