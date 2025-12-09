#include QMK_KEYBOARD_H

#include "action_layer.h"

#include "quantum.h"

// The first four layers gets a name for readability, which is then used in the OLED below.
enum layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtrl| RAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| Del  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_DEFAULT] = LAYOUT(
  KC_GRV,      KC_1,            KC_2,            KC_3,            KC_4,             KC_5,                                      KC_6,       KC_7,            KC_8,            KC_9,            KC_0,               KC_MINS,
  KC_TAB,      KC_Q,            KC_W,            KC_E,            KC_R,             KC_T,                                      KC_Y,       KC_U,            KC_I,            KC_O,            KC_P,               KC_EQL,
  KC_ESC,      LGUI_T(KC_A),    LALT_T(KC_S),    LSFT_T(KC_D),    LCTL_T(KC_F),     KC_G,                                      KC_H,       RCTL_T(KC_J),    RSFT_T(KC_K),    LALT_T(KC_L),    RGUI_T(KC_SCLN),    KC_QUOT,
  KC_LSFT,     KC_Z,            KC_X,            KC_C,            KC_V,             KC_B,         KC_LBRC,       KC_RBRC,      KC_N,       KC_M,            KC_COMM,         KC_DOT,          KC_SLSH,            KC_BSLS,
                                                 KC_LCTL,         KC_RALT,          MO(_LOWER),   KC_SPC,        KC_ENT,       MO(_RAISE), KC_BSPC,         KC_DEL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END, KC_HOME,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   MS_WHLU, MS_WHLD,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
      case KC_BSPC: {
        static uint16_t registered_key = KC_NO;
        if (record->event.pressed) {  // On key press.
          const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
          uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
          uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
          if (shift_mods) {  // At least one shift key is held.
            registered_key = KC_DEL;
            // If one shift is held, clear it from the mods. But if both
            // shifts are held, leave as is to send Shift + Del.
            if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
              del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
              unregister_mods(MOD_MASK_SHIFT);
            }
          } else {
            registered_key = KC_BSPC;
          }

          register_code(registered_key);
          set_mods(mods);
        } else {  // On key release.
          unregister_code(registered_key);
        }
      } return false;

      // Other macros...
    }

    return true;
  }

#ifdef OLED_ENABLE
// NOTE: Most of the OLED code was originally written by Soundmonster for the Corne,
// and has been copied directly from `crkbd/soundmonster/keymap.c`

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_space(void) {
  oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
  static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
  static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
  static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
  static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

  static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
  static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
  static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
  static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

  // fillers between the modifier icons bleed into the icon frames
  static const char PROGMEM off_off_1[] = {0xc5, 0};
  static const char PROGMEM off_off_2[] = {0xc6, 0};
  static const char PROGMEM on_off_1[] = {0xc7, 0};
  static const char PROGMEM on_off_2[] = {0xc8, 0};
  static const char PROGMEM off_on_1[] = {0xc9, 0};
  static const char PROGMEM off_on_2[] = {0xca, 0};
  static const char PROGMEM on_on_1[] = {0xcb, 0};
  static const char PROGMEM on_on_2[] = {0xcc, 0};

  if(modifiers & MOD_MASK_GUI) {
      oled_write_P(gui_on_1, false);
  } else {
      oled_write_P(gui_off_1, false);
  }

  if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
      oled_write_P(on_on_1, false);
  } else if(modifiers & MOD_MASK_GUI) {
      oled_write_P(on_off_1, false);
  } else if(modifiers & MOD_MASK_ALT) {
      oled_write_P(off_on_1, false);
  } else {
      oled_write_P(off_off_1, false);
  }

  if(modifiers & MOD_MASK_ALT) {
      oled_write_P(alt_on_1, false);
  } else {
      oled_write_P(alt_off_1, false);
  }

  if(modifiers & MOD_MASK_GUI) {
      oled_write_P(gui_on_2, false);
  } else {
      oled_write_P(gui_off_2, false);
  }

  if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
      oled_write_P(on_on_2, false);
  } else if(modifiers & MOD_MASK_GUI) {
      oled_write_P(on_off_2, false);
  } else if(modifiers & MOD_MASK_ALT) {
      oled_write_P(off_on_2, false);
  } else {
      oled_write_P(off_off_2, false);
  }

  if(modifiers & MOD_MASK_ALT) {
      oled_write_P(alt_on_2, false);
  } else {
      oled_write_P(alt_off_2, false);
  }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
  static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
  static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
  static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
  static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

  static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
  static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
  static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
  static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

  // fillers between the modifier icons bleed into the icon frames
  static const char PROGMEM off_off_1[] = {0xc5, 0};
  static const char PROGMEM off_off_2[] = {0xc6, 0};
  static const char PROGMEM on_off_1[] = {0xc7, 0};
  static const char PROGMEM on_off_2[] = {0xc8, 0};
  static const char PROGMEM off_on_1[] = {0xc9, 0};
  static const char PROGMEM off_on_2[] = {0xca, 0};
  static const char PROGMEM on_on_1[] = {0xcb, 0};
  static const char PROGMEM on_on_2[] = {0xcc, 0};

  if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(ctrl_on_1, false);
  } else {
      oled_write_P(ctrl_off_1, false);
  }

  if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
      oled_write_P(on_on_1, false);
  } else if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(on_off_1, false);
  } else if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(off_on_1, false);
  } else {
      oled_write_P(off_off_1, false);
  }

  if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(shift_on_1, false);
  } else {
      oled_write_P(shift_off_1, false);
  }

  if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(ctrl_on_2, false);
  } else {
      oled_write_P(ctrl_off_2, false);
  }

  if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
      oled_write_P(on_on_2, false);
  } else if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(on_off_2, false);
  } else if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(off_on_2, false);
  } else {
      oled_write_P(off_off_2, false);
  }

  if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(shift_on_2, false);
  } else {
      oled_write_P(shift_off_2, false);
  }
}

void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 64, 32,184, 36,162, 34,162, 34,162, 36,184, 32, 64, 64,
        128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  2,  6, 10, 10, 18, 18, 18, 18, 18, 18, 18,
        10, 10,  6,  2,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
  oled_set_cursor(0, 4);
}

void render_logo_text(void) {
  oled_write_P(PSTR("lily "), false);
}

void render_kb_LED_state(void) {
  // Host Keyboard LED Status
  led_t led_usb_state = host_keyboard_led_state();
  oled_write_P(led_usb_state.num_lock ? PSTR("N ") : PSTR("  "), false);
  oled_write_P(led_usb_state.caps_lock ? PSTR("C ") : PSTR("  "), false);
  oled_write_P(led_usb_state.scroll_lock ? PSTR("S ") : PSTR("  "), false);
}

void render_layer_state(void) {
  static const char PROGMEM default_layer[] = {
      0x20, 0x94, 0x95, 0x96, 0x20,
      0x20, 0xb4, 0xb5, 0xb6, 0x20,
      0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
  static const char PROGMEM raise_layer[] = {
      0x20, 0x97, 0x98, 0x99, 0x20,
      0x20, 0xb7, 0xb8, 0xb9, 0x20,
      0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
  static const char PROGMEM lower_layer[] = {
      0x20, 0x9a, 0x9b, 0x9c, 0x20,
      0x20, 0xba, 0xbb, 0xbc, 0x20,
      0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
  static const char PROGMEM adjust_layer[] = {
      0x20, 0x9d, 0x9e, 0x9f, 0x20,
      0x20, 0xbd, 0xbe, 0xbf, 0x20,
      0x20, 0xdd, 0xde, 0xdf, 0x20, 0};

  switch (get_highest_layer(layer_state | default_layer_state)) {
      case _LOWER:
          oled_write_P(lower_layer, false);
          break;
      case _RAISE:
          oled_write_P(raise_layer, false);
          break;
      case _ADJUST:
          oled_write_P(adjust_layer, false);
          break;
      default:
          oled_write_P(default_layer, false);
  }
}

static void render_wufo(void) {
    static const char PROGMEM raw_logo[] = {
        0, 16,  0,  0,  0,  0,  0,128,129,128,128,  0,  0,  0,  0,  0,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0, 16,  0,  0,  0,  0,  1,  0,  0,  0,120,254,255,255,135,  3,  1,  1,  1,  1,  2,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  7,  7,  6,  6,  2,  2,  1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  8,  0,  0,  0,  0,  4,  0,  0,  0,  0,
        0,  0,  0,  0,  0, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,192, 32, 16, 16, 16, 16, 16, 32,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 32,  0,  0,128,  0,  0,  0,  0,  8, 28, 18, 50, 81, 85,145,149,145,149,145,149,145, 85, 81, 50, 18, 28,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  8,  0,  0,  0,192,252,255,255,255,255,255,255,255,252,192,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,192,252,255,255,255,255,255,255,255,255,255,255,255,248,128,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,192,252,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,248,  0,  0,  0, 32,  0,  0,  0,  0, 16,  0,  0,  0,192,252,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,240,  0,  0,  0,  0,  0,  0,  0,  0,192,252,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,224,  0,  0,  4,
        0,192,252,255,255,255,255,255,255,255,255,255,255,255,255,255, 31, 63, 31,191,127,127,255,255,255,255,255,255,255,254,192,  0,252,255,255,255,255,255,255,255,255,255,255,248, 51,135,  3,195,225,  0, 96,204,156,254,255,255,255,255,255,255,255,255,255,252,223, 63,223,239,255,127,247,255,231,255,255,255,110,207,254, 62,255,255,255,255,255,111,255, 47,239,175,255,255,255,255, 63,127,  6,137,247, 17, 76,  9, 27, 31, 69, 40, 17,  1, 55,  9, 41,  3, 13,  9, 57, 45,  9, 29, 31,  2,  3,  6,  2, 75, 15,199,  9,228,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}



bool oled_task_kb(void) {
  if (!oled_task_user()) {
      return false;
  }
  if (is_keyboard_master()) {
      // Renders the current keyboard state (layers and mods)
      render_logo();
    //   render_logo_text();
      render_space();
      render_space();
      render_layer_state();
      render_space();
      render_space();
      render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
      render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    //   render_kb_LED_state();
  } else {
    // render_anim();
    render_wufo();

//       // clang-format off
//       static const char PROGMEM aurora_art[] = {
//           0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1c, 0x08, 0x00, 0x00,
//           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
//           0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x40,
//           0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80,
//           0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x80, 0x00, 0xf0, 0x00, 0x00, 0xc0,
//           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
//           0x81, 0x00, 0xc0, 0x00, 0xfe, 0x00, 0xfc, 0x00, 0xff, 0x20, 0xff, 0xf0, 0x0f, 0xf0, 0x00, 0xff,
//           0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x00, 0xf8, 0x00, 0x00, 0xf8,
//           0xff, 0x10, 0xff, 0x84, 0xff, 0x60, 0xff, 0x36, 0xff, 0x0f, 0xff, 0x3f, 0x00, 0x5f, 0x00, 0x05,
//           0x80, 0x00, 0x80, 0x00, 0xc0, 0x38, 0x00, 0xec, 0xf0, 0x00, 0xfb, 0x80, 0xff, 0xf0, 0xff, 0xef,
//           0xff, 0xe8, 0xff, 0x03, 0xff, 0x0c, 0xff, 0x00, 0xff, 0x00, 0x03, 0x00, 0x00, 0xf8, 0x00, 0x80,
//           0xff, 0x20, 0xff, 0xd0, 0xff, 0xe0, 0xfe, 0xf8, 0xff, 0xfc, 0xff, 0xff, 0x0f, 0xff, 0x01, 0x3f,
//           0xff, 0x00, 0x0f, 0x00, 0x01, 0x00, 0x03, 0x00, 0xfe, 0x80, 0xfe, 0x00, 0xc0, 0xff, 0xc4, 0xfb,
//           0xff, 0xfe, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0x07, 0xff, 0x03, 0x3f, 0x00, 0x0f, 0xc0, 0x00,
//           0x00, 0x00, 0xb8, 0x00, 0xff, 0x40, 0xbe, 0xf0, 0xff, 0xf1, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff,
//           0x1f, 0xff, 0x67, 0x00, 0xef, 0x00, 0x1f, 0x00, 0x00, 0x07, 0x00, 0x00, 0xe0, 0x00, 0xff, 0xf0,
//           0xff, 0x88, 0xff, 0xc4, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x7f, 0x0f, 0xff,
//           0x00, 0x07, 0xfe, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0xc0, 0x3f, 0xf8, 0xe7, 0xff,
//           0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x1f, 0x3f, 0x01, 0xff, 0x0b, 0x00, 0xff, 0x00, 0x00, 0x05,
//           0x00, 0x00, 0x00, 0xe0, 0x00, 0xf8, 0x60, 0x80, 0xfe, 0xe3, 0xfc, 0xff, 0x1e, 0xff, 0xff, 0x23,
//           0xff, 0x09, 0xff, 0x20, 0x00, 0x3f, 0x02, 0x00, 0x00, 0x0f, 0x00, 0x40, 0x00, 0xc0, 0x00, 0xfc,
//           0xe0, 0xfc, 0xf0, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0x0f, 0xff, 0x07, 0x1f, 0x00, 0x01, 0x0f, 0x00,
//           0x0f, 0x00, 0x81, 0x70, 0x0c, 0xf0, 0x80, 0x00, 0x00, 0xe4, 0xf8, 0xe6, 0x70, 0x3f, 0xcf, 0xff,
//           0x1f, 0xff, 0x48, 0xff, 0x0f, 0x00, 0x07, 0x00, 0x00, 0x43, 0x60, 0xf8, 0xf0, 0xfe, 0x38, 0xfe,
//           0x00, 0xfc, 0x03, 0x00, 0xc8, 0x72, 0xcf, 0xfc, 0x00, 0x03, 0x0f, 0x01, 0xe0, 0x1c, 0xe0, 0x03,
//           0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x06, 0xf9, 0x00, 0x03, 0x00, 0x07,
//           0xff, 0x00, 0x10, 0x12, 0xc9, 0xf0, 0xcf, 0xb4, 0x7f, 0x80, 0xe0, 0x1e, 0x01, 0x40, 0x65, 0x5e,
//           0xe0, 0x00, 0x00, 0xf0, 0x0c, 0xf0, 0x00, 0x80, 0x7e, 0x01, 0x80, 0x93, 0xfc, 0xc0, 0x00, 0x00,
//           0x00, 0x00, 0x00, 0x00, 0x89, 0x18, 0x2c, 0x46, 0x00, 0x07, 0x21, 0x10, 0x10, 0x80, 0x09, 0x13,
//           0x31, 0xbf, 0xff, 0x00, 0x08, 0x1a, 0xf7, 0x0f, 0x00, 0x00, 0x44, 0x45, 0x34, 0xbf, 0xb8, 0x00,
//           0x10, 0xf0, 0x08, 0xf4, 0x18, 0x11, 0xfc, 0x18, 0xfb, 0x0e, 0x10, 0xf8, 0x04, 0xf8, 0x10, 0x20,
//           0x18, 0x09, 0xff, 0x0c, 0xea, 0x1f, 0x28, 0x60, 0x30, 0xf8, 0x20, 0xc0, 0x42, 0x33, 0x21, 0x00
//       };
//       // clang-format on
//       oled_write_raw_P(aurora_art, sizeof(aurora_art));
  }
  return false;
}
#endif
