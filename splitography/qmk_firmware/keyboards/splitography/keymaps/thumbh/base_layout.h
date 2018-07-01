
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ..................................................................... BEAKL H

  // ,-----------------------------------------------------------------------------------.
  // |   ;  |   Y  |   O  |   U  |   Z  |  Fn  | Caps |   G  |   D  |   N  |   M  |   X  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |   Q  |   I  |   E  |   A  |   .  |Cursor| Mouse|   C  |   T  |   R  |   S  |   W  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |   J  |   -  |   '  |   K  |   ,  |  Num | Regex|   B  |   P  |   L  |   F  |   V  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                           |  Esc |   H  | Space| Bksp |                           |
  // `-----------------------------------------------------------------------------------'

  [_BASE] = {
    {KC_SCLN, KC_Y,    KC_O,    KC_U,    KC_Z,    CNTR_TL, CNTR_TR, KC_G,    KC_D,    KC_N,    KC_M,    KC_X   },
    {HOME_Q,  HOME_I,  HOME_E,  HOME_A,  KC_DOT,  CNTR_HL, CNTR_HR, KC_C,    HOME_T,  HOME_R,  HOME_S,  HOME_W },
    {KC_J,    KC_MINS, KC_QUOT, KC_K,    KC_COMM, CNTR_BL, CNTR_BR, KC_B,    KC_P,    KC_L,    KC_F,    KC_V   },
    {_______, _______, _______, _______, LT_ESC,  LT_H,    TD_SPC,  LT_BSPC, _______, _______, _______, _______},
  },

  [_SHIFT] = {
    {KC_COLN, S(KC_Y), S(KC_O), S(KC_U), S(KC_Z), CNTR_TL, CNTR_TR, S(KC_G), S(KC_D), S(KC_N), S(KC_M), S(KC_X)},
    {S(KC_Q), S(KC_I), S(KC_E), S(KC_A), KC_QUES, CNTR_HL, CNTR_HR, S(KC_C), S(KC_T), S(KC_R), S(KC_S), S(KC_W)},
    {S(KC_J), KC_UNDS, KC_DQT,  S(KC_K), KC_EXLM, CNTR_BL, CNTR_BR, S(KC_B), S(KC_P), S(KC_L), S(KC_F), S(KC_V)},
    {_______, _______, _______, _______, KC_ESC,  S(KC_H), KC_SPC,  KC_BSPC, _______, _______, _______, _______},
  },

  // ,-----------------------------------------------------------------------------------.
  // |   :  |   Y  |   O  |   U  |   Z  |  Fn  | Caps |   G  |   D  |   N  |   M  |   X  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |   Q  |   I  |   E  |   A  |   ~  |Cursor| Mouse|   C  |   T  |   R  |   S  |   W  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |   J  |   -  |   '  |   K  |   `  |  Num | Regex|   B  |   P  |   L  |   F  |   V  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                           |  Tab |  f() | Enter|  Del |                           |
  // `-----------------------------------------------------------------------------------'

  [_LSHIFT] = {
    {KC_SCLN, KC_Y,    KC_O,    KC_U,    KC_Z,    CNTR_TL, CNTR_TR, S(KC_G), S(KC_D), S(KC_N), S(KC_M), S(KC_X)},
    {KC_Q,    KC_I,    KC_E,    KC_A,    TD_TILD, CNTR_HL, CNTR_HR, S(KC_C), S(KC_T), S(KC_R), S(KC_S), S(KC_W)},
    {KC_J,    KC_MINS, KC_QUOT, KC_K,    KC_GRV,  CNTR_BL, CNTR_BR, S(KC_B), S(KC_P), S(KC_L), S(KC_F), S(KC_V)},
    {_______, _______, _______, _______, KC_TAB,  ___fn__, TD_ENT,  LT_DEL,  _______, _______, _______, _______},
  },

  // ,-----------------------------------------------------------------------------------.
  // |   :  |   Y  |   O  |   U  |   Z  |  Fn  | Caps |   G  |   D  |   N  |   M  |   X  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |   Q  |   I  |   E  |   A  |   ?  |Cursor| Mouse|   C  |   T  |   R  |   S  |   W  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |   J  |   _  |   "  |   K  |   !  |  Num | Regex|   B  |   P  |   L  |   F  |   V  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                           |  Tab |   H  |  f() |  Del |                           |
  // `-----------------------------------------------------------------------------------'

  [_RSHIFT] = {
    {KC_COLN, S(KC_Y), S(KC_O), S(KC_U), S(KC_Z), CNTR_TL, CNTR_TR, KC_G,    KC_D,    KC_N,    KC_M,    KC_X   },
    {S(KC_Q), S(KC_I), S(KC_E), S(KC_A), KC_QUES, CNTR_HL, CNTR_HR, KC_C,    KC_T,    KC_R,    KC_S,    KC_W   },
    {S(KC_J), KC_UNDS, KC_DQT,  S(KC_K), KC_EXLM, CNTR_BL, CNTR_BR, KC_B,    KC_P,    KC_L,    KC_F,    KC_V   },
    {_______, _______, _______, _______, KC_TAB,  S(KC_H), ___fn__, KC_DEL,  _______, _______, _______, _______},
  },

  // ,-----------------------------------------------------------------------------------.
  // |      |      |      |      |      |      |      |   *  |   [  |   ^  |   ]  |      |
  // |--------------------+---------------------------+------+------+------+------+------|
  // |      |      |      |      |      |      |      |   |  |   (  |   $  |   )  |      |
  // |------|-------------+------|------|-------------+------+------+------+------+------|
  // |      |      |      |      |      |      |      |   /  |   {  |   #  |   }  |      |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                           |  f() |      |   \  |  Del |                           |
  // `-----------------------------------------------------------------------------------'

  [_LSYMBOL] = {
    {_______, _______, _______, _______, _______, ___x___, ___x___, TD_ASTR, KC_LBRC, KC_CIRC, KC_RBRC, _______},
    {_______, _______, _______, _______, _______, ___x___, ___x___, KC_PIPE, KC_LPRN, KC_DLR,  KC_RPRN, _______},
    {_______, _______, _______, _______, _______, ___x___, ___x___, KC_SLSH, KC_LCBR, KC_HASH, KC_RCBR, _______},
    {_______, _______, _______, _______, ___fn__, ___x___, KC_BSLS, SL_DEL,  _______, _______, _______, _______},
  },

  // ,-----------------------------------------------------------------------------------.
  // |   :  |   .  |   *  |   &  |      |      |      |      | Home |  Up  |  End | PgUp |
  // |------+------+------+------+------+------------------------------------------------|
  // |   ~  |   <  |   %  |   >  |   ?  |      |      |      | Left | Down | Right| PgDn |
  // |------+------+------+------+------+------|-----------------------------------------|
  // |      |   +  |   @  |   !  |   /  |      |      |      |      |      |      |      |
  // |------+------+------+------+------+------+-----------------------------------------|
  // |                           | ↑Tab |   =  |      |  f() |                           |
  // `-----------------------------------------------------------------------------------'

  [_RSYMBOL] = {
    {HS_COLN, KC_DOT,  KC_ASTR, KC_AMPR, _______, ___x___, ___x___, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP},
    {SG_TILD, HS_LT,   SA_PERC, HS_GT,   KC_QUES, ___x___, ___x___, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN},
    {_______, KC_PLUS, KC_AT,   KC_EXLM, KC_SLSH, ___x___, ___x___, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, SL_TAB,  HS_EQL,  ___x___, ___fn__, _______, _______, _______, _______},
  },
