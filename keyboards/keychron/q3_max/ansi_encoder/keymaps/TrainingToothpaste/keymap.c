/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

enum custom_keycodes {
    KC_EMMIE = SAFE_RANGE,
    KC_ZUKO,
    KC_ZUKO2,
    KC_ZUKO3,
    KC_ZUKO4,
    KC_ZUKO5,
    KC_AVAIL,
    KC_AVAIL2,
    KC_RES,
    KC_TIME,
    KC_THX,
    KC_HAPPY,
    KC_SCHED,
    KC_ESCAL,
    KC_CARE,
    KC_HELPCARE,
    KC_STILL,
    KC_SPAM,
    KC_SPAM2,
    KC_SPAM3,
    KC_TRY,
    KC_LOOK,
    KC_SUNQ,
    KC_CLOSE,
    KC_PHONE,
    KC_DESKL,
    KC_DESKR,
    KC_DELUP,
    KC_TAXUP,
    KC_NGROUP,
    KC_WGROUP,
    KC_KEYCOL,
    KC_PUB,
    KC_LOG5,
    KC_LOGT,
    KC_LOGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    //custom:

    switch (keycode) {
    case KC_EMMIE:
        if (record->event.pressed) {
            //space, em dash, space
            SEND_STRING(" "SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P1)SS_UP(X_LALT)" ");
        } else {
        }
        break;

    case KC_PHONE:
        if (record->event.pressed) {
            //          " "____________bold text on_______________ AS phone + " " ____________________the little x character for extensions___________________   ext   _____________bold text off_____________" "
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_B)SS_UP(X_LCTL)"941.955.8200 " SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P1)SS_TAP(X_P5)SS_UP(X_LALT) " 3225" SS_DOWN(X_LCTL)SS_TAP(X_B)SS_UP(X_LCTL)" ");
        } else {
        }
        break;

    case KC_ZUKO:
        if (record->event.pressed) {
            SEND_STRING("Michelle here. ");
        } else {
        }
        break;

    case KC_ZUKO2:
        if (record->event.pressed) {
            SEND_STRING("Michelle from Tech here. ");
        } else {
        }
        break;

    case KC_ZUKO3:
        if (record->event.pressed) {
            SEND_STRING("Michelle from MSC Tech here. ");
        } else {
        }
        break;

    case KC_ZUKO4:
        if (record->event.pressed) {
            SEND_STRING("Michelle from MSC Tech here. I'd be happy to help! ");
        } else {
        }
        break;

    case KC_ZUKO5:
        if (record->event.pressed) {
            SEND_STRING("Michelle from MSC Tech here. I'd be happy to help! I'll be available to take a look at around TIME, if that's a good time for you!");
        } else {
        }
        break;

    case KC_THX:
        if (record->event.pressed) {
            SEND_STRING("Thank you for reaching out. ");
        } else {
        }
        break;

    case KC_HAPPY:
        if (record->event.pressed) {
            SEND_STRING("I'd be happy to help! ");
        } else {
        }
        break;

    case KC_AVAIL:
        if (record->event.pressed) {
            SEND_STRING("I'll be available at around ");
        } else {
        }
        break;

    case KC_AVAIL2:
        if (record->event.pressed) {
            SEND_STRING("I'll be available at around TIME, if that's a good time for you!");
        } else {
        }
        break;

    case KC_RES:
        if (record->event.pressed) {
            SEND_STRING("all set, resolving");
        } else {
        }
        break;

    case KC_TIME:
        if (record->event.pressed) {
            SEND_STRING(", if that's a good time for you!");
        } else {
        }
        break;

    case KC_SCHED:
        if (record->event.pressed) {
            SEND_STRING("Let me know when you're available and we can schedule a time to take care of that!");
        } else {
        }
        break;

    case KC_ESCAL:
        if (record->event.pressed) {
            //OG:
            /*SEND_STRING("Thank you for reaching out. We'd be happy to help! Let me escalate this to the team so we can address it as soon as possible!"SS_TAP(X_ENT)SS_TAP(X_ENT)"Thank you and let us know if you have any questions!");*/

            //Delayed:
            SEND_STRING("Thank you for reaching out. We'd be happy to help! " SS_DELAY(250) "Let me escalate this to the team " SS_DELAY(250) "so we can address it as soon as possible!"SS_TAP(X_ENT)SS_TAP(X_ENT)"Thank you and let us know if you have any questions!");
        } else {
        }
        break;

    case KC_CARE:
        if (record->event.pressed) {
            SEND_STRING("Take care and let us know if there's anything else we can help with!");
        } else {
        }
        break;

    case KC_HELPCARE:
        if (record->event.pressed) {
            SEND_STRING("Happy to help!"SS_TAP(X_ENT)SS_TAP(X_ENT)"Take care and let us know if there's anything else we can assist with!");
        } else {
        }
        break;

    case KC_STILL:
        if (record->event.pressed) {
            SEND_STRING("Just wanted to reach out and see if you still need assistance with this request. If so, please let us know and we'll be happy to help!");
        } else {
        }
        break;

    case KC_SPAM:
        if (record->event.pressed) {
            SEND_STRING("Thank you for reaching out. I'd be happy to help! This is fake "SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P1)SS_UP(X_LALT)" you can mark it as junk and block the sender to prevent future emails from this address!");
        } else {
        }
        break;

    case KC_SPAM2:
        if (record->event.pressed) {
            SEND_STRING("Thank you for reporting this scam to us "SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P1)SS_UP(X_LALT)" you can mark it as junk and block the sender to prevent future emails from that address!");
        } else {
        }
        break;

    case KC_SPAM3:
        if (record->event.pressed) {
            SEND_STRING("Thank you for reporting this message to us"SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P1)SS_UP(X_LALT)" we have documented the sender and message details and will keep an eye out for more reports of similar messages!");
        } else {
        }
        break;

    case KC_CLOSE:
        if (record->event.pressed) {
            SEND_STRING("I'm just reaching out to let you know that this request is being closed as we haven't received a reply from you in several days. If you still require assistance with this, please do not hesitate to let us know and we will be more than happy to help!"SS_TAP(X_ENT)SS_TAP(X_ENT)"Take care and let us know if there's anything else we can help with!");
        } else {
        }
        break;

    case KC_TRY:
        if (record->event.pressed) {
            SEND_STRING("Give that a try and let me know if you have any questions!");
        } else {
        }
        break;

    case KC_LOOK:
        if (record->event.pressed) {
            SEND_STRING("Take a look when you get the chance and let me know if everything looks good on your end!");
        } else {
        }
        break;

    case KC_SUNQ:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_Q)SS_UP(X_LCTL)SS_UP(X_LALT)SS_UP(X_LSFT));
        } else {
        }
        break;

    case KC_DESKL:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LGUI)SS_UP(X_LCTL));
        } else {
        }
        break;

    case KC_DESKR:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_RGHT)SS_UP(X_LGUI)SS_UP(X_LCTL));
        } else {
        }
        break;

    case KC_DELUP:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LCTL)SS_UP(X_LSFT)SS_TAP(X_DEL));
        } else {
        }
        break;

    case KC_TAXUP:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_V)SS_TAP(X_K)SS_DELAY(500)SS_TAP(X_V)SS_UP(X_LCTL)SS_TAP(X_ENT)SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_NGROUP: //Groups selected browser tabs into a group called "new"
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_G)SS_UP(X_LSFT)SS_UP(X_LCTL)SS_DELAY(250)"new"SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_WGROUP: //Groups selected browser tabs into a group called "waiting"
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_G)SS_UP(X_LSFT)SS_UP(X_LCTL)SS_DELAY(250)"waiting"SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_PUB: //Groups selected browser tabs into a group called "waiting"
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_F3)SS_DELAY(250)"add priv"SS_TAP(X_ESC)SS_DELAY(250)SS_TAP(X_ENT)SS_TAP(X_DOWN)SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_LOG5: //logs 5 minutes in FS
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_M)SS_DELAY(440)SS_DOWN(X_LSFT)SS_TAP(X_SCLN)SS_UP(X_LSFT)SS_TAP(X_5)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_LOGT: //opens time logger and hits : to enter minutes worked
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_M)SS_DELAY(440)SS_DOWN(X_LSFT)SS_TAP(X_SCLN)SS_UP(X_LSFT));
        } else {
        }
        break;

    case KC_LOGE: //hits tab 8x to enter logged time
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_ENT));
        } else {
        }
        break;
    }

    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F5,    KC_F2,    KC_F3,    KC_F4, LCTL(KC_F5), KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,   KC_PSCR,  KC_BTN1,  KC_MPLY,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,   KC_EMMIE, KC_HOME,  KC_VOLU,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,   KC_DEL,   KC_END,   KC_VOLD,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,             KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,MO(MAC_FN),   KC_RCTL,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        KC_SUNQ,  KC_F1,    KC_BRIU,  KC_TASK,  KC_FILE, LCTL(KC_R),RGB_VAI,  KC_MPRV,  KC_STILL, KC_CLOSE, KC_SPAM,  KC_SPAM2, KC_SPAM3,   _______,   KC_ESCAL, KC_CARE,  KC_HELPCARE,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SAD,  RGB_SAI,    KC_DELUP,  KC_MPRV,  KC_MNXT,  KC_TRY,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  KC_ZUKO,  KC_ZUKO2, KC_ZUKO3,   KC_ZUKO4,  KC_ZUKO5, KC_AVAIL2,KC_RES,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              KC_LOOK,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  KC_LOGT,  KC_LOGE,  KC_LOG5,  KC_TAXUP,             KC_PHONE,            RALT(KC_EQL),
        _______,  _______,  _______,                                _______,                                KC_NGROUP,KC_WGROUP,_______,    KC_PUB,    KC_DESKL, RALT(KC_MINS),KC_DESKR),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F5,    KC_F2,    KC_F3,    KC_F4, LCTL(KC_F5), KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,   KC_PSCR,  KC_BTN1,  KC_MPLY,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,   KC_EMMIE, KC_HOME,  KC_VOLU,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,   KC_DEL,   KC_END,   KC_VOLD,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,             KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI, MO(WIN_FN),  KC_RCTL,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        KC_SUNQ,  KC_F1,    KC_BRIU,  KC_TASK,  KC_FILE, LCTL(KC_R),RGB_VAI,  KC_MPRV,  KC_STILL, KC_CLOSE, KC_SPAM,  KC_SPAM2, KC_SPAM3,   _______,   KC_ESCAL, KC_CARE,  KC_HELPCARE,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SAD,  RGB_SAI,    KC_DELUP,  KC_MPRV,  KC_MNXT,  KC_TRY,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  KC_ZUKO,  KC_ZUKO2, KC_ZUKO3,   KC_ZUKO4,  KC_THX,   KC_HAPPY, KC_SCHED,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              KC_LOOK,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  KC_LOGT,  KC_LOGE,  KC_LOG5,  KC_PUB,               KC_PHONE,            RGB_HUI,
        _______,  _______,  _______,                                _______,                                KC_NGROUP,KC_WGROUP,_______,    KC_TAXUP,  RGB_SPD,  RGB_HUD,  RGB_SPI)
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE
