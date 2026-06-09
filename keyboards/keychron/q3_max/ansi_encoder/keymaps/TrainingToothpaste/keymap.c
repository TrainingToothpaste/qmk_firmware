#include QMK_KEYBOARD_H
#include "keychron_common.h"

//custom
//#define DYNAMIC_KEYMAP_LAYER_COUNT 5

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    FN_RSFT, //extra layer for holding both FN & R Shift
};

//CUSTOM fn & RSft tracking
static bool fn_held = false;
static bool rsft_held = false;

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
    KC_SENDLOG,
    KC_LOGT,
    KC_LOGE,
    KC_REG,
    KC_MERGE,
    KC_AWE,
    KC_TEL,
    KC_EVENT,
    KC_SPHISH,
    KC_MSC,
    KC_GVUP,
    KC_GVDWN,
    KC_GMUTE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    //custom keycodes:

    switch (keycode) {
    case KC_EMMIE: //space, em dash, space
        if (record->event.pressed) {
            SEND_STRING(" "SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P1)SS_UP(X_LALT)" ");
        } else {
        }
        break;

    case KC_PHONE:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_B)SS_UP(X_LCTL)
            "941.955.8200 "
            SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P1)SS_TAP(X_P5)SS_UP(X_LALT)
            " 3225"
            SS_DOWN(X_LCTL)SS_TAP(X_B)SS_UP(X_LCTL)" ");
        } else {
        }
        break;

    case KC_ZUKO:
        if (record->event.pressed) {
            SEND_STRING("Chelle here. ");
        } else {
        }
        break;

    case KC_ZUKO2:
        if (record->event.pressed) {
            SEND_STRING("Chelle from Tech here. ");
        } else {
        }
        break;

    case KC_ZUKO3:
        if (record->event.pressed) {
            SEND_STRING("Chelle from MSC Tech here. ");
        } else {
        }
        break;

    case KC_ZUKO4:
        if (record->event.pressed) {
            SEND_STRING("Chelle from MSC Tech here. I'd be happy to help! ");
        } else {
        }
        break;

    case KC_ZUKO5:
        if (record->event.pressed) {
            SEND_STRING("Chelle from MSC Tech here. I'd be happy to help! "
            SS_DELAY(250)
            "I'll be available for a call at around TIME, if that's a good time for you.");
        } else {
        }
        break;

    case KC_THX:
        if (record->event.pressed) {
            SEND_STRING("Thank you for reaching out! ");
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
            SEND_STRING("I'll be available for a call at around TIME, if that's a good time for you.");
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
            SEND_STRING(", if that's a good time for you.");
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
            SEND_STRING("Thank you for reaching out! We'd be happy to help! "
            SS_DELAY(250)
            "Let me escalate this to the team "
            SS_DELAY(250)
            "so we can address it as soon as possible!"
            SS_TAP(X_ENT)SS_TAP(X_ENT)
            "Thank you and let us know if you have any questions!");
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
            SEND_STRING("Happy to help!"
            SS_TAP(X_ENT)SS_TAP(X_ENT)
            "Take care and let us know if there's anything else we can assist with!");
        } else {
        }
        break;

    case KC_STILL:
        if (record->event.pressed) {
            SEND_STRING("Chelle from MSC Tech here. Just wanted to reach out and see if you still need assistance "
            SS_DELAY(250)
            "with this request. If so, let us know and we'll be happy to help!");
        } else {
        }
        break;

    case KC_SPAM:
        if (record->event.pressed) {
            SEND_STRING("Thank you for reaching out. "
            SS_DELAY(250)
            "I'd be happy to help! This appears to be a scam "
            SS_DELAY(250)
            SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P1)SS_UP(X_LALT)
            SS_DELAY(250)
            " you can mark it as junk and block the sender to prevent future emails from this address!");
        } else {
        }
        break;

    case KC_SPAM2:
        if (record->event.pressed) {
            SEND_STRING("Thank you for reporting this to us "
            SS_DELAY(250)
            SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P1)SS_UP(X_LALT)
            SS_DELAY(250)
            " you can mark it as junk and block the sender to prevent future emails from that address!");
        } else {
        }
        break;

    case KC_SPAM3:
        if (record->event.pressed) {
            SEND_STRING("Thank you for reporting this message to us"
            SS_DELAY(250)
            SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P1)SS_UP(X_LALT)
            SS_DELAY(250)
            " we have documented the sender and message details and will keep an eye out for more reports of similar messages!");
        } else {
        }
        break;

    case KC_CLOSE:
        if (record->event.pressed) {
            SEND_STRING("I'm just reaching out to let you know that this request is being closed "
            SS_DELAY(250)
            "as we haven't received a reply from you in several days. "
            SS_DELAY(250)
            "If you still require assistance with this, please do not hesitate to let us know and we will be more than happy to help!"
            SS_DELAY(250)
            SS_TAP(X_ENT)SS_TAP(X_ENT)
            "Take care and let us know if there's anything else we can help with!");
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

    case KC_SUNQ: //quits moonlight
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_Q)SS_UP(X_LCTL)SS_UP(X_LALT)SS_UP(X_LSFT));
        } else {
        }
        break;

    case KC_DESKL: //move one desktop to the left
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LGUI)SS_UP(X_LCTL));
        } else {
        }
        break;

    case KC_DESKR: //move one desktop to the right
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_RGHT)SS_UP(X_LGUI)SS_UP(X_LCTL));
        } else {
        }
        break;

    case KC_DELUP: //deletes all text from current position to top
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_HOME)SS_UP(X_LCTL)SS_UP(X_LSFT)SS_TAP(X_DEL));
        } else {
        }
        break;

    case KC_TAXUP: //pastes a link in excel and automatically makes it a hyperlink (bc for some reason excel doesn't always do that automatically)
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_V)SS_TAP(X_K)
            SS_DELAY(500)
            SS_TAP(X_V)SS_UP(X_LCTL)SS_TAP(X_ENT)SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_NGROUP: //Groups selected browser tabs into a group called "new"
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_G)SS_UP(X_LSFT)SS_UP(X_LCTL)
            SS_DELAY(250)
            "New"
            SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_WGROUP: //Groups selected browser tabs into a group called "waiting"
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_G)SS_UP(X_LSFT)SS_UP(X_LCTL)
            SS_DELAY(250)
            "Waiting"
            SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_PUB: //Groups selected browser tabs into a group called "waiting"
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_F3)
            SS_DELAY(250)
            "add priv"
            SS_TAP(X_ESC)
            SS_DELAY(250)
            SS_TAP(X_ENT)SS_TAP(X_DOWN)SS_TAP(X_ENT)SS_DOWN(X_LCTL)SS_TAP(X_ENT)SS_UP(X_LCTL));
        } else {
        }
        break;

    case KC_LOG5: //logs 5 minutes in FS
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_M)
            SS_DELAY(440)
            ":5"
            SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_LOGT: //opens time logger and hits : to enter minutes worked
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_M)
            SS_DELAY(440)
            SS_DOWN(X_LSFT)SS_TAP(X_SCLN)SS_UP(X_LSFT));
        } else {
        }
        break;

    case KC_LOGE: //hits tab 8x to enter logged time
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_SENDLOG: //ctrl & enter, then log 5 minutes
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_RCTL)SS_TAP(X_ENT)SS_UP(X_RCTL)
            SS_DELAY(250)
            SS_TAP(X_M)
            SS_DELAY(440)
           ":5"
            SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_REG: //types ® symbol
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P7)SS_TAP(X_P4)SS_UP(X_LALT));
        } else {
        }
        break;

    case KC_MERGE: //change merge message and set note to public
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_F3)
            SS_DELAY(500)
            "is closed and"
            SS_TAP(X_ESC)SS_TAP(X_BSPC)
            SS_DELAY(500)
            "has been"
            /*SS_TAP(X_F3)
            SS_DELAY(500)
            "SAVE"
            SS_TAP(X_ESC)
            SS_DELAY(250)
            SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_UP(X_LSFT)SS_TAP(X_ESC)SS_TAP(X_SPC)
            SS_DELAY(250)
            SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_ENT)*/);
        } else {
        }
        break;

    case KC_AWE:
        if (record->event.pressed) {
            SEND_STRING("Awesome, glad to hear it! "
            SS_DELAY(250)
            "I'll go ahead and close this ticket down, then!"
            SS_DELAY(250)
            SS_TAP(X_ENT)SS_TAP(X_ENT)
            "Take care and let us know if there's anything else we can help with!");
        } else {
        }
        break;

    case KC_TEL: //enters telephone number and ticket number as links for ticlet appt events
        if (record->event.pressed) {
            SEND_STRING(
            SS_DOWN(X_LCTL) SS_TAP(X_K) SS_UP(X_LCTL)
            SS_DELAY(500)
            SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LSFT)
            SS_DELAY(250)
            SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL) SS_TAP(X_TAB)
            SS_DELAY(250)
            "tel:"
            SS_DOWN(X_LCTL) SS_TAP(X_V) SS_UP(X_LCTL)
            SS_DELAY(250)
            SS_TAP(X_ENT)
            SS_DELAY(725)
            SS_TAP(X_END) SS_TAP(X_ENT) SS_TAP(X_ENT)
            SS_DELAY(250)
            SS_DOWN(X_LGUI) SS_TAP(X_V) SS_UP(X_LGUI)
            SS_DELAY(500)
            SS_TAP(X_DOWN) SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_EVENT:
        if (record->event.pressed) {
            SEND_STRING(
            SS_TAP(X_TAB)
            "tech"
            SS_DELAY(500)
            SS_TAP(X_ENT));
        } else {
        }
        break;

    case KC_SPHISH:
        if (record->event.pressed) {
            SEND_STRING(
            "Thank you for forwarding this email to us; it is fake! "
            SS_DELAY(250)
            "You can click the 'Phish Alert' button at the top of Outlook to report the email as a scam!"
            SS_TAP(X_ENT)SS_TAP(X_ENT)
            SS_DELAY(250)
            "On that note, the Phish Alert button is now "
            SS_DELAY(250)
            "our primary scam-reporting method for staff members, "
            SS_DELAY(250)
            "so you no longer need to go through the trouble of forwarding them to us!");
        } else {
        }
        break;

    case KC_MSC:
        if (record->event.pressed) {
            SEND_STRING("michaelsaunders.com");
        } else {
        }
        break;

    case KC_GVUP:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_EQL)SS_DOWN(X_LALT));
        } else {
        }
        break;

    case KC_GVDWN:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_MINS)SS_UP(X_LALT));
        } else {
        }
        break;

    case KC_GMUTE:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_F12)SS_UP(X_LALT)SS_UP(X_LALT));
        } else {
        }
        break;

    //end of macros
    }

    //CUSTOM: Check for FN key
    if (keycode == MO(MAC_FN) || keycode == MO(WIN_FN)) {
        fn_held = record->event.pressed;
    }

    // Check for Right Shift
    if (keycode == KC_RSFT) {
        rsft_held = record->event.pressed;
    }

    // Toggle FN_RSFT layer
    if (fn_held && rsft_held) {
        layer_on(FN_RSFT);
    } else {
        layer_off(FN_RSFT);
    }

    //END of checking fn

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
        KC_SUNQ,  KC_F1,    KC_BRIU,  KC_TASK,  KC_FILE, LCTL(KC_R),RGB_VAI, KC_SPHISH, KC_STILL, KC_CLOSE, KC_SPAM,  KC_SPAM2, KC_SPAM3,   KC_GMUTE,  KC_ESCAL, KC_CARE,  KC_HELPCARE,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SAD,  RGB_SAI,    KC_DELUP,  KC_MPRV,  KC_MNXT,  KC_TRY,
        KC_EVENT, RGB_MOD,  RGB_VAI,  RGB_HUI,  KC_REG,   RGB_SPI,  _______,  _______,  _______,  _______,  KC_ZUKO,  KC_ZUKO2, KC_ZUKO3,   KC_ZUKO4,  KC_ZUKO5, KC_AVAIL2,KC_RES,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  KC_AWE,               KC_LOOK,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  KC_LOGT,  KC_LOGE,  KC_LOG5,  KC_MSC,               _______,             RALT(KC_EQL),
        _______,  _______,  KC_TEL,                                 KC_MERGE,                               KC_NGROUP,KC_WGROUP,_______,    KC_PUB,    KC_DESKL, RALT(KC_MINS),KC_DESKR),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F5,    KC_F2,    KC_F3,    KC_F4, LCTL(KC_F5), KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,   KC_PSCR,  KC_BTN1,  KC_MPLY,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,   KC_EMMIE, KC_HOME,  KC_VOLU,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,   KC_DEL,   KC_END,   KC_VOLD,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,             KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI, MO(WIN_FN),  KC_RCTL,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        KC_SUNQ,  KC_F1,    KC_BRIU,  KC_TASK,  KC_FILE, LCTL(KC_R),RGB_VAI, KC_SPHISH, KC_STILL, KC_CLOSE, KC_SPAM,  KC_SPAM2, KC_SPAM3,   _______,   KC_ESCAL, KC_CARE,  KC_HELPCARE,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_SAD,  RGB_SAI,    KC_DELUP,  KC_MPRV,  KC_MNXT,  KC_TRY,
        KC_EVENT, RGB_MOD,  RGB_VAI,  RGB_HUI,  KC_REG,   RGB_SPI,  _______,  _______,  _______,  _______,  KC_ZUKO,  KC_ZUKO2, KC_ZUKO3,   KC_ZUKO4,  KC_ZUKO5, KC_AVAIL2,KC_RES,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  KC_AWE,               KC_LOOK,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  KC_LOGT,  KC_LOGE,  KC_LOG5,  KC_MSC,               _______,             RGB_HUI,
        _______,  _______,  KC_TEL,                                 KC_MERGE,                               KC_NGROUP,KC_WGROUP,_______,    KC_PUB,    RGB_SPD,  RGB_HUD,  RGB_SPI),

    [FN_RSFT] = LAYOUT_tkl_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,   _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             KC_SENDLOG,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,   _______,  _______,  _______)
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(KC_GVDWN, KC_GVUP)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [FN_RSFT]  = {ENCODER_CCW_CW(_______, _______)},
};
#endif // ENCODER_MAP_ENABLE
