// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
//
// To flash steno firmware
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
//   Reset keyboard or press hw reset button on base (hole)
//
//   cd qmk_firmware/keyboards/steno
//   sudo make KEYMAP=sdothum dfu
//
//   sudo make clean          (good practice before flashing)
//   sudo make KEYMAP=sdothum (to compile check)
//
// Package requirements (for arch linux)
// ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
//   avr-gcc-atmel
//   avr-libc-atmel
//   dfu-programmer
//
// Code
// ▔▔▔▔
//   This source is shamelessly based on the "default" steno layout
//
//   #ifdef/#endif block structures are not indented, as syntax highlighting
//   in vim is sufficient for identification
//
//   c++ commenting style is used throughout

#include "config.h"
#ifdef PLANCK
#include "planck.h"
#else
#include "splitography.h"
#endif
#include "action_layer.h"
#include "keymap_steno.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum splitography_layers {
  _QWERTY = 0
 ,_BLUE
 ,_ORANGE
 ,_GREEN
 ,_NUM
 ,_PLOVER
 ,_TXBOLT
 ,_END_LAYERS
};

enum splitography_keycodes {
  QWERTY = SAFE_RANGE
 ,BLUE
 ,ORANGE
 ,PLOVER
 // ,PLOVEX
 ,TXBOLT
 // ,TXBOLX
 ,OS_ALT
 ,OS_CTL
 ,OS_GUI
 ,OS_SFT
};

// tap dance keys
enum tap_dance {
  _SWAP = 0
};

#define TD_SWAP TD(_SWAP)

// keycodes
#define ___x___ KC_TRNS
#ifdef _______
#undef _______
#endif
#define _______ KC_NO
#define KC_PSTE KC_PASTE
#define TG_NUM  TG(_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ...................................................................... Qwerty
//
// http://www.keyboard-layout-editor.com/#/gists/1b04ce6be0cee6e5d2998b2a8efb8b09

  // ,-----------------------------------------------------------------------------------.
  // |  Esc |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
  // -------|------+------+------+------+------+------+------+------+------+-------------|
  // |  Alt |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
  // -------|------+------+------+------+------+------+------+------+------+-------------|
  // | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  GUI |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                    | Blue |Orange|             | Space| Ctrl |                    |
  // `-----------------------------------------------------------------------------------'

  [_QWERTY] = {
    {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
    {OS_ALT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {OS_SFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_GUI },
#ifdef PLANCK
    {_______, _______, _______, BLUE,    ORANGE,  _______, _______, KC_SPC,  OS_CTL,  _______, _______, _______},
#else
    {                           BLUE,    ORANGE,                    KC_SPC,  OS_CTL                            },
#endif
  },

// .................................................................. Blue Layer
//
// http://www.keyboard-layout-editor.com/#/gists/054b8bc0e31971bb962ea1c781232e0b

  // .-----------------------------------------------------------------------------------.
  // |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
  // |-----------------------------------------------------------------------------------|
  // |  Alt | Stop | Prev | Play | Next | +Vol |      |      |      |   [  |   ]  | Enter|
  // |-----------------------------------------------------------------------------------|
  // | Shift| Undo |  Cut | Copy | Paste| -Vol | Mute |      |      |   -  |   =  |  GUI |
  // |-----------------------------------------------------------------------------------|
  // |                    |  f() |Orange|             | Bksp | Ctrl |                    |
  // '-----------------------------------------------------------------------------------'

  [_BLUE] = {
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
    {OS_ALT,  KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, _______, _______, _______, KC_LBRC, KC_RBRC, KC_ENT },
    {OS_SFT,  KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_VOLD, KC_MUTE, _______, _______, KC_MINS, KC_EQL,  OS_GUI },
#ifdef PLANCK
    {_______, _______, _______, ___x___, ORANGE,  _______, _______, KC_BSPC, OS_CTL,  _______, _______, _______},
#else
    {                           ___x___, ORANGE,                    KC_BSPC, OS_CTL                            },
#endif
  },

// ................................................................ Orange Layer
//
// http://www.keyboard-layout-editor.com/#/gists/83ccc7c3faa78b1f67f6fef65063a248

  // .-----------------------------------------------------------------------------------.
  // |Plover|  F1  |  F2  |  F3  |  F4  |      |  App | PrScr|ScrLck| Pause|      |      |
  // |-----------------------------------------------------------------------------------|
  // |  Alt |  F5  |  F6  |  F7  |  F8  |      |      |Insert| Home | PgUp |      | Enter|
  // |-----------------------------------------------------------------------------------|
  // | Shift|  F9  |  F10 |  F11 |  F12 |      |      |  Del |  End | PgDn |   \  |  GUI |
  // |-----------------------------------------------------------------------------------|
  // |                    | Blue |  f() |             |  Del | Ctrl |                    |
  // '-----------------------------------------------------------------------------------'

  [_ORANGE] = {
    {PLOVER,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, KC_APP,  KC_PSCR, KC_SLCK, KC_PAUS, _______, _______},
    {OS_ALT,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______, KC_ENT },
    {OS_SFT,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_DEL,  KC_END,  KC_PGDN, KC_BSLS, OS_GUI },
#ifdef PLANCK
    {_______, _______, _______, BLUE,    ___x___, _______, _______, KC_DEL,  OS_CTL,  _______, _______, _______},
#else
    {                           BLUE,    ___x___,                   KC_DEL,  OS_CTL                            },
#endif
  },

// ................................................................. Green Layer
//
// http://www.keyboard-layout-editor.com/#/gists/bc7902f1eada4d7d34d3445aa1eccdab

  // .-----------------------------------------------------------------------------------.
  // |TxBolt| Reset|      |      |      |Scroll|   /  |   7  |   8  |   9  |   -  | Swap |
  // |-----------------------------------------------------------------------------------|
  // |  Alt | Home |  Up  |  End | PgUp | Caps |   *  |   4  |   5  |   6  |   +  | Enter|
  // |-----------------------------------------------------------------------------------|
  // | Shift| Left | Down | Right| PgDn |  Num |   0  |   1  |   2  |   3  |      |  GUI |
  // |-----------------------------------------------------------------------------------|
  // |                    |  f() |  f() |             |  --  | Ctrl |                    |
  // '-----------------------------------------------------------------------------------'

  [_GREEN] = {
#ifdef PLANCK
    {TXBOLT,  RESET,   _______, _______, _______, KC_SLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_MINS, TD_SWAP},
#else
    {TXBOLT,  _______, _______, _______, _______, KC_SLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_MINS, TD_SWAP},
#endif
    {OS_ALT,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_CAPS, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_ENT },
    {OS_SFT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, TG_NUM,  KC_P0,   KC_P1,   KC_P2,   KC_P3,   _______, OS_GUI },
#ifdef PLANCK
    {_______, _______, _______, ___x___, ___x___, _______, _______, _______, OS_CTL,  _______, _______, _______},
#else
    {                           ___x___, ___x___,                   _______, OS_CTL                            },
#endif
  },

// ................................................................... Num Layer
//
// http://www.keyboard-layout-editor.com/#/gists/bc7902f1eada4d7d34d3445aa1eccdab

  // .-----------------------------------------------------------------------------------.
  // |      |      |      |      |      |Scroll|   /  |   7  |   8  |   9  |   -  |      |
  // |-----------------------------------------------------------------------------------|
  // |  Alt | Home |  Up  |  End | PgUp | Caps |   *  |   4  |   5  |   6  |   +  | Enter|
  // |-----------------------------------------------------------------------------------|
  // | Shift| Left | Down | Right| PgDn |  f() |   0  |   1  |   2  |   3  |      |  GUI |
  // |-----------------------------------------------------------------------------------|
  // |                    |  --  |  --  |             |  --  | Ctrl |                    |
  // '-----------------------------------------------------------------------------------'

  [_NUM] = {
    {_______, _______, _______, _______, _______, KC_SLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______},
    {OS_ALT,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_CAPS, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_ENT },
    {OS_SFT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, QWERTY,  KC_P0,   KC_P1,   KC_P2,   KC_P3,   _______, OS_GUI },
#ifdef PLANCK
    {_______, _______, _______, _______, _______, _______, _______, _______, OS_CTL,  _______, _______, _______},
#else
    {                           _______, _______,                   _______, OS_CTL                            },
#endif
  },

// ...................................................................... Plover
//
// http://www.keyboard-layout-editor.com/#/gists/27b8f8649393a8ba4071ba946a9306f4

  // ,-----------------------------------------------------------------------------------.
  // |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |   1  |
  // +-------------+------+------+------+------+------+------+------+------+------+------|
  // |Qwerty|   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
  // +------|------+------+------+------+------+------+------+------+------+------+------|
  // |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
  // +------+------+------+------+------+------+------+------+------+------+------+------|
  // |                    |   A  |   O  |             |   E  |   U  |                    |
  // `-----------------------------------------------------------------------------------'

  [_PLOVER] = {
    {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
    {QWERTY,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
    {_______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
#ifdef PLANCK
    {_______, _______, _______, KC_C,    KC_V,    _______, _______, KC_N,    KC_M,    _______, _______, _______},
#else
    {                           KC_C,    KC_V,                      KC_N,    KC_M                              },
#endif
  },

// ...................................................................... TxBolt
//
// http://www.keyboard-layout-editor.com/#/gists/27b8f8649393a8ba4071ba946a9306f4

  // ,-----------------------------------------------------------------------------------.
  // |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |Qwerty|   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                    |   A  |   O  |             |   E  |   U  |                    |
  // `-----------------------------------------------------------------------------------'

  [_TXBOLT] = {
    {STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM, STN_NUM},
    {QWERTY,  STN_SL,  STN_TL,  STN_PL,  STN_HL,  STN_STR, STN_STR, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR },
    {_______, STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_STR, STN_STR, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR },
#ifdef PLANCK
    {_______, _______, _______, STN_A,   STN_O,   _______, _______, STN_E,   STN_U,   _______, _______, _______},
#else
    {                           STN_A,   STN_O,                     STN_E,   STN_U                             },
#endif
  },

};

// ............................................................ Tap Dance Toggle

// see config.h
static uint8_t swap_shift_ctrl = TOGGLE_SHIFT;
static uint8_t on_down_only    = TOGGLE_ONESHOT;

void swap(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    on_down_only = on_down_only ? 0 : 1;
  }
  else {
    swap_shift_ctrl = swap_shift_ctrl ? 0 : 1;
  }
  reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [_SWAP] = ACTION_TAP_DANCE_FN (swap)
};

// ................................................................... Modifiers

void modifier(keyrecord_t *record, uint8_t oneshot_mods, uint16_t modifier)
{
  if (record->event.pressed) {
    if (!on_down_only) {
      set_oneshot_mods(oneshot_mods);
    }
    register_code  (modifier);
  }
  else {
    unregister_code(modifier);
  }
}

// ..................................................................... Keymaps

void clear_layers(void)
{
  uint8_t layer;
  for (layer = 0; layer < _END_LAYERS; layer++) {
    layer_off(layer);
  }
}

#ifdef PLANCK
// register simple key press
void tap_key(uint16_t keycode)
{
  register_code  (keycode);
  unregister_code(keycode);
}

void shift_key(uint16_t keycode)
{
  register_code  (KC_LSFT);
  tap_key        (keycode);
  unregister_code(KC_LSFT);
}

// txbolt plover run state
static uint8_t plover = 0;

void toggle_plover(uint8_t state)
{
  // toggle window manager plover application, see herbstluftwm/config/appbinds
  if (plover != state) {
    register_code  (KC_LGUI);
    shift_key      (KC_RGHT);
    unregister_code(KC_LGUI);
    plover = state;
  }
}
#endif

void steno(keyrecord_t *record, uint8_t layer)
{
  if (record->event.pressed) {
    clear_layers();
    layer_on(layer);
    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }
    keymap_config.raw  = eeconfig_read_keymap();
    keymap_config.nkro = 1;
    eeconfig_update_keymap(keymap_config.raw);
#ifdef PLANCK
    toggle_plover(1);
#endif
  }
}

// void steno_exit(keyrecord_t *record, uint8_t layer)
// {
//   if (record->event.pressed) {
//     layer_off(layer);
// #ifdef PLANCK
//     toggle_plover(0);
// #endif
//   }
// }

// ........................................................... User Keycode Trap

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        clear_layers();
        set_single_persistent_default_layer(_QWERTY);
#ifdef PLANCK
        toggle_plover(0);
#endif
      }
      return false;
    case BLUE:
      if (record->event.pressed) {
        layer_on        (_BLUE);
        update_tri_layer(_BLUE, _ORANGE, _GREEN);
      } else {
        layer_off       (_BLUE);
        update_tri_layer(_BLUE, _ORANGE, _GREEN);
      }
      return false;
    case ORANGE:
      if (record->event.pressed) {
        layer_on        (_ORANGE);
        update_tri_layer(_BLUE, _ORANGE, _GREEN);
      } else {
        layer_off       (_ORANGE);
        update_tri_layer(_BLUE, _ORANGE, _GREEN);
      }
      return false;
    case PLOVER:
      steno(record, _PLOVER);
      return false;
    // case PLOVEX:
    //   steno_exit(record, _PLOVER);
    //   return false;
    case TXBOLT:
      steno(record, _TXBOLT);
      return false;
    // case TXBOLX:
    //   steno_exit(record, _TXBOLT);
    //   return false;
    case OS_ALT:
      modifier(record, MOD_LALT, KC_LALT);
      break;
    case OS_CTL:
      if (swap_shift_ctrl) {
        modifier(record, MOD_LSFT, KC_LSFT);
      }
      else {
        modifier(record, MOD_LCTL, KC_LCTL);
      }
      break;
    case OS_GUI:
      modifier(record, MOD_LGUI, KC_LGUI);
      break;
    case OS_SFT:
      if (swap_shift_ctrl) {
        modifier(record, MOD_LCTL, KC_LCTL);
      }
      else {
        modifier(record, MOD_LSFT, KC_LSFT);
      }
      break;
  }
  return true;
}

// initialize steno protocol
void matrix_init_user(void)
{
  steno_set_mode(STENO_MODE_BOLT);
}

