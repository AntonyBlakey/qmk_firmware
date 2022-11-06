#include QMK_KEYBOARD_H

#include "version.h"

#include "oneshot.h"
// #include "swapper.h"

#define TABR KC_TAB
#define TABL S(KC_TAB)
#define CMD_SPC G(KC_SPC)
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)

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

    // SW_WIN,  // Switch to next window         (cmd-tab)
    // SW_LANG, // Switch to next input language (ctl-spc)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,          XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, 
        XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX,          XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_ESC,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, LA_NAV,  KC_LSFT,          XXXXXXX,          XXXXXXX,          KC_SPC,  LA_SYM,  XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
    ),

    [SYM] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_QUES, KC_LBRC, KC_LCBR, KC_LPRN, KC_SLSH, XXXXXXX,          XXXXXXX, KC_BSLS, KC_RPRN, KC_RCBR, KC_RBRC, KC_AT,   XXXXXXX, 
        XXXXXXX, KC_GRV,  KC_QUOT, KC_DQUO, KC_DLR,  KC_HASH, XXXXXXX,          XXXXXXX, KC_UNDS, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, XXXXXXX,
        XXXXXXX, KC_EXLM, KC_TILD, KC_AMPR, KC_PIPE, KC_CIRC,                            KC_PLUS, KC_MINS, KC_ASTR, KC_PERC, KC_EQL,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, LA_NAV,  KC_LSFT,          XXXXXXX,          XXXXXXX,          KC_SPC,  LA_SYM,  XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
    ),

    [NAV] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_ESC,  CMD_SPC, XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX,          XXXXXXX, TABL,    TABR,    XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX, 
        XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  XXXXXXX, XXXXXXX,          XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_ENT,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, LA_NAV,  KC_LSFT,          XXXXXXX,          XXXXXXX,          KC_SPC,  LA_SYM,  XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX 
    ),

    [NUM] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,          XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, 
        XXXXXXX, OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_F11,  XXXXXXX,          XXXXXXX, KC_F12,  OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F3,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, LA_NAV,  KC_LSFT,          XXXXXXX,          XXXXXXX,          KC_SPC,  LA_SYM,  XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

// bool sw_win_active = false;
// bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // update_swapper(
    //     &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
    //     keycode, record
    // );
    // update_swapper(
    //     &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
    //     keycode, record
    // );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_matrix_set_color_all(RGB_BLACK);

    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (layer == 0)
                    rgb_matrix_set_color(index, RGB_CYAN);
                else if (layer == 1)
                    rgb_matrix_set_color(index, RGB_BLUE);
                else if (layer == 2)
                    rgb_matrix_set_color(index, RGB_GREEN);
                else if (layer == 3)
                    rgb_matrix_set_color(index, RGB_RED);
            }
        }
    }

        bool layer1 = layer == 1;
        bool layer2 = layer == 2;
        bool layer3 = layer == 3;

        ML_LED_1(layer1);
        ML_LED_2(layer2);
        ML_LED_3(layer3);
        ML_LED_4(layer1);
        ML_LED_5(layer2);
        ML_LED_6(layer3);

        // if (get_highest_layer(layer_state) > 0) {
        //     uint8_t layer = get_highest_layer(layer_state);

        //     for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        //         for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        //             uint8_t index = g_led_config.matrix_co[row][col];

        //             if (index >= led_min && index <= led_max && index != NO_LED &&
        //             keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
        //                 rgb_matrix_set_color(index, RGB_GREEN);
        //             }
        //         }
        //     }
        // }
}