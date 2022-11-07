#include QMK_KEYBOARD_H

#include "version.h"
#include "oneshot.h"

#define TABL S(KC_TAB)

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

enum { TD_SCLN_COLN, TD_E_ESC, TD_A_GA, TD_Z_GZ, TD_X_GX, TD_C_GC, TD_V_GV };

#define TH_TAB MT(MOD_LSFT, KC_TAB)
#define TH_SPC LT(NAV, KC_SPC)
#define TH_ENT LT(SYM, KC_ENT)

#define TD_SCLN TD(TD_SCLN_COLN)
#define TD_E TD(TD_E_ESC)
#define TD_A TD(TD_A_GA)
#define TD_Z TD(TD_Z_GZ)
#define TD_X TD(TD_X_GX)
#define TD_C TD(TD_C_GC)
#define TD_V TD(TD_V_GV)

#define LNCHBAR G(KC_SPC)
#define VSTERM C(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_Q,    KC_W,    TD_E,    KC_R,    KC_T,    XXXXXXX,          XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, 
        XXXXXXX, TD_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,          XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_ESC,  XXXXXXX,
        XXXXXXX, TD_Z,    TD_X,    TD_C,    TD_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  TD_SCLN, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, TH_TAB,  TH_SPC,           XXXXXXX,          XXXXXXX,          TH_ENT,  KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
    ),

    [SYM] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_LT,   KC_LBRC, KC_LCBR, KC_LPRN, KC_SLSH, XXXXXXX,          XXXXXXX, KC_BSLS, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT,   XXXXXXX, 
        XXXXXXX, KC_GRV,  KC_QUOT, KC_DQUO, KC_DLR,  KC_HASH, XXXXXXX,          XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_PERC, KC_ESC,  XXXXXXX,
        XXXXXXX, KC_EXLM, KC_TILD, KC_AMPR, KC_PIPE, KC_CIRC,                            KC_AT,   KC_UNDS, KC_QUES, KC_EQL,  KC_COLN, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, TH_TAB,  TH_SPC,           XXXXXXX,          XXXXXXX,          TH_ENT,  KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
    ),

    [NAV] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VSTERM,  XXXXXXX,          XXXXXXX, TABL,    XXXXXXX, XXXXXXX, KC_TAB,  KC_MPLY, XXXXXXX, 
        XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX, XXXXXXX,          XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ESC,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LNCHBAR,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, TH_TAB,  TH_SPC,           XXXXXXX,          XXXXXXX,          TH_ENT,  KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
    ),

    [NUM] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,          XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, 
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  XXXXXXX,          XXXXXXX, KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F3,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, TH_TAB,  TH_SPC,           XXXXXXX,          XXXXXXX,          TH_ENT,  KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX,
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
        case TH_SPC: 
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
            if (keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (os_alt_state != os_up_unqueued || os_ctrl_state != os_up_unqueued || os_shft_state != os_up_unqueued || os_cmd_state != os_up_unqueued) {
                    rgb_matrix_set_color(index, RGB_MAGENTA);
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
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_E_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_ESC),
    [TD_A_GA] = ACTION_TAP_DANCE_DOUBLE(KC_A, G(KC_A)),
    [TD_Z_GZ] = ACTION_TAP_DANCE_DOUBLE(KC_Z, G(KC_Z)),
    [TD_X_GX] = ACTION_TAP_DANCE_DOUBLE(KC_X, G(KC_X)),
    [TD_C_GC] = ACTION_TAP_DANCE_DOUBLE(KC_C, G(KC_C)),
    [TD_V_GV] = ACTION_TAP_DANCE_DOUBLE(KC_V, G(KC_V)),
};