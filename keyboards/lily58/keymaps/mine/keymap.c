#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
  extern rgblight_config_t rgblight_config;
  #include "rgblight.h"
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _APEX 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4 

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  APEX,
  LOWER,
  RAISE,
  ADJUST,
  SG
};

//  qmk compile -kb lily58 -km mine

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  LOWER,    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,  KC_MUTE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                             KC_LALT, KC_LGUI, KC_LCTRL, KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, KC_RGUI \
),


/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_APEX] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_CAPS, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \

  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,  KC_MUTE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                             LOWER, SG, KC_LCTL, KC_SPC, SG,   RAISE,   KC_BSPC, KC_RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, KC_CAPS,                   _______, _______, _______,_______, _______, _______,\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
  _______, _______, _______,_______, KC_LGUI, TG(1), _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  // TODO: replace these numbers with something else
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
  _______,KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |RGBTST|XMAS  |SNAKE |RAINBW|PLAIN |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |GRADE |KNIGHT|SWIRL |BREATH|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RGB_M_T, RGB_M_X, RGB_M_SN, RGB_M_R, RGB_M_P, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_M_G, RGB_M_K, RGB_M_SW, RGB_M_B, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY, APEX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 15, HSV_PURPLE}       // Light 4 LEDs, starting with LED 6
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 15, HSV_ORANGE}       // Light 4 LEDs, starting with LED 6
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 15, HSV_CYAN}       // Light 4 LEDs, starting with LED 6
);

const rgblight_segment_t PROGMEM three_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 15, HSV_RED}       // Light# 4 LEDs, starting with LED 6
);

const rgblight_segment_t PROGMEM four_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 15, HSV_BLUE }       // Light 4 LEDs, starting with LED 6
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    lower_layer,
    raise_layer,
    adjust_layer, 
    three_layer,
    four_layer
);
uint16_t keyCntr = 0;
#define OLED_SUGAR_HEIGHT 128

#define OLED_SUGAR_WIDTH  32

#define OLED_SUGAR_WITH_DOWN 1

#define OLED_SUGAR_PIXELS (OLED_SUGAR_HEIGHT*OLED_SUGAR_WIDTH)
#define OLED_SUGAR_BYTES (OLED_SUGAR_PIXELS/8)
typedef signed char lineIdx_t;
lineIdx_t* activeSugar = NULL;

char* pixels = NULL;

bool pixelInvert = false;
void setPixel(char * pixels, uint8_t h, uint8_t w, bool pix) {
//    oled_write_pixel(w, h, pix);
    uint16_t byteIdx = w + (h/8)*OLED_SUGAR_WIDTH;
    int8_t byteMask = 1<<(h%8);
    if(pixelInvert) pix = !pix;
    if(pix) {
        pixels[byteIdx] |= byteMask;
    } else {
        pixels[byteIdx] &= ~byteMask;
    }
}

bool getPixel(char * pixels, uint8_t h, uint8_t w) {
    uint16_t byteIdx = w + (h/8)*OLED_SUGAR_WIDTH;
    int8_t byteMask = 1<<(h%8);
    bool pix =  (pixels[byteIdx] & byteMask) != 0;
    if(pixelInvert) pix = !pix;
    return pix;
}

uint32_t rand_basic(void) {
    static uint32_t seed = 0;
    seed = 1664525*seed + 1013904223;
    return seed;
}


void keyboard_post_init_user(void) {
    // Enable the LED layers
    // rgblight_layers = my_rgb_layers;

    // Call the keymap level matrix init.
  
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_PURPLE);
    rgblight_mode_noeeprom(0);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    //  rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_sethsv_noeeprom(HSV_PURPLE);
    rgblight_mode_noeeprom(0);
    return state;
}


layer_state_t layer_state_set_user(layer_state_t state) { 
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    // rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    // rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    // rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    // rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    switch (biton32(state)) {
    case _QWERTY:
      rgblight_sethsv_noeeprom(HSV_PURPLE);
      rgblight_mode_noeeprom(0);
      break;
    case _APEX:
      rgblight_sethsv_noeeprom(HSV_TURQUOISE);
      rgblight_mode_noeeprom(0);
      break;
    case _RAISE:
      rgblight_sethsv_noeeprom(HSV_RED);
      rgblight_mode_noeeprom(4);
      break;
    case _LOWER:
      rgblight_sethsv_noeeprom(HSV_YELLOW);
      rgblight_mode_noeeprom(4);
      break;
    case _ADJUST:
      rgblight_sethsv_noeeprom(HSV_BLUE);
      rgblight_mode_noeeprom(4);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_noeeprom(HSV_PURPLE);
      break;
    }



    // switch (get_highest_layer(state)) {
    //   case _QWERTY:
    //       break;
    //   case _APEX:
    //       break;
    //   case _RAISE:
    //         rgblight_mode_noeeprom(5);
    //       break;
    //   case _LOWER:
    //         rgblight_mode_noeeprom(6);
    //       break;
    //   case _ADJUST:
    //         rgblight_mode_noeeprom(7);
    //       break;
    //   }
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
    return state;
}




int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
      rgblight_enable();
      // rgblight_sethsv_noeeprom(HSV_PURPLE);
    #endif
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  // if (!is_keyboard_master())
  //   return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  if (true) { //is_keyboard_master()) {
      return OLED_ROTATION_270;
  } 
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);/

// void oled_task_user(void) {//
//   if (is_keyboard_master()) {
//     // If you want to change the display of OLED, you need to change here
//     oled_write_ln(read_layer_state(), false);
//     oled_write_ln(read_keylog(), false);
//     oled_write_ln(read_keylogs(), false);
//     //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
//     //oled_write_ln(read_host_led_state(), false);
//     //oled_write_ln(read_timelog(), false);
//   } else {
//     oled_write(read_logo(), false);
//   }
// }

void oled_sugar(void) {
    //return;

    if (activeSugar == NULL) {
        activeSugar = malloc(OLED_SUGAR_HEIGHT);
        if (activeSugar != NULL) {
            memset( activeSugar, -1, OLED_SUGAR_HEIGHT );
        } else {
  #ifdef PRINT_DB
              uprintf("activeSugar %X failed to inialise\n", activeSugar);
  #endif
              return;
          }
      }

      if (pixels == NULL) {
          pixels = malloc(OLED_SUGAR_BYTES);
          if (pixels != NULL) {
              memset( pixels, 0, OLED_SUGAR_BYTES );
          } else {
  #ifdef PRINT_DB
              uprintf("pixels %X failed to inialise\n", pixels);
  #endif
              return;
          }

      }

      static uint8_t sugarCntr = 0;

    for(int16_t h = OLED_SUGAR_HEIGHT-2; h >= 0; h--) {
          lineIdx_t w = activeSugar[h];

          if(w < 0 || w >= OLED_SUGAR_WIDTH) {
              continue;
          }
          lineIdx_t wn = -1;
          bool left;
          bool right;
  #ifdef OLED_SUGAR_WITH_DOWN 
          uint32_t r = rand_basic();
          const uint32_t thresh1 = UINT32_MAX/3;
          const uint32_t thresh2 = UINT32_MAX-thresh1;
          left  = r < thresh1;
          right = r > thresh2;
  #else
          left = ((int32_t) rand_basic())<0;
          right = !left;
  #endif
          if ( left ) {
              if( w > 0 ) {
                  if(!getPixel(pixels, h+1, w-1)) {
                      wn = w - 1;
                  }
              }
          } else if (right) {
              if ( w < OLED_SUGAR_WIDTH-1) {
                  if(!getPixel(pixels, h+1, w+1)) {
                      wn = w + 1;
                  }
              }
          } else { //centre
              if(!getPixel(pixels, h+1, w)) {
                  wn = w ;
              }
          }
          if(wn == -1) {
              if(!getPixel(pixels, h+1, w)) {
                  wn = w;
              }
          }
          if(wn != -1) {
              setPixel(pixels, h+1, wn, true);
              activeSugar[h+1] = wn;
              setPixel(pixels, h, w, false);
          }

          activeSugar[h] = -1;
      }
      if(sugarCntr != (keyCntr&0xFF)) {

          sugarCntr++;
          lineIdx_t w = OLED_SUGAR_WIDTH/2;
          bool left = false;
          if( ((int32_t) rand_basic())<0 ) {
              w--;
              left = true;
          }
          bool full = false;
          while(getPixel(pixels,0, w)) {
              if(left) {
                  if (w == 0) {
                      w = OLED_SUGAR_WIDTH-1;
                  } else if ( w == OLED_SUGAR_WIDTH/2) {
                      full = true;
                      break;
                  } else {
                      w--;
                  }
              } else {
                  if (w == OLED_SUGAR_WIDTH-1) {
                      w = 0;
                  } else if ( w == OLED_SUGAR_WIDTH/2-1) {
                      full = true;
                      break;
                  } else {
                      w++;
                  }
              }
          }

          if(!full) {
  //        if(!getPixel(pixels, 0, w)) {
              setPixel(pixels, 0, w, true);
              activeSugar[0] = w;
          } else {
              pixelInvert = !pixelInvert;
              // we where not able to add a pixel (we where full so add one now that we have inverted)
              sugarCntr--;
              oled_sugar();
          }
      }
      rand_basic(); //just here to rotate the seed
      if(!is_oled_on()) {
          //OLED timedout so we will clear everything and start fresh
          memset( pixels, 0, OLED_SUGAR_BYTES );
          memset( activeSugar, -1, OLED_SUGAR_HEIGHT );
          oled_clear();
          pixelInvert = false;
      } else {
          oled_write_raw(pixels, OLED_SUGAR_BYTES);
      }
      
  }


void oled_task_user(void) {
    // Host Keyboard Layer Status
    if (is_keyboard_master()) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWerty\n"), false);
            break;
        case _APEX:
            oled_write_P(PSTR("Apex\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
        }
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
    } else {
        oled_write(read_logo(), false);
        }
    return false;
}
#endif // OLED_DRIVER_ENABLE

void user_sync_a_update_keyCntr_on_other_board(uint8_t in_buflen, const void* in_data, uint8_t
        out_buflen, void* out_data) { keyCntr = *((const uint16_t *)in_data); }

#endif


void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
#ifdef OLED_ENABLE
    transaction_register_rpc(USER_SYNC_KEY_CNTR, user_sync_a_update_keyCntr_on_other_board);
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef OLED_DRIVER_ENABLE
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }
  #ifdef OLED_ENABLE
          keyCntr++;
          transaction_rpc_send(USER_SYNC_KEY_CNTR, sizeof(keyCntr), &keyCntr);
  #endif

  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        rgblight_mode_noeeprom(5); 
      } else {
        layer_off(_LOWER);
        rgblight_mode_noeeprom(0); 
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case SG:
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_SPC));
        wait_ms(6.94);
        SEND_STRING(SS_TAP(X_LALT)SS_UP(X_SPC)SS_DOWN(X_LALT));
      }
        else {
        SEND_STRING(SS_UP(X_LALT));
      }
      break;
  }
  return true;
}

static void volume_encoder(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}

static void brightneess_encoder(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_BRIGHTNESS_UP);
        } else {
            tap_code(KC_BRIGHTNESS_DOWN);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_BRIGHTNESS_DOWN);
        } else {
            tap_code(KC_BRIGHTNESS_UP);
        }
    }
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
      case _QWERTY:
          volume_encoder(index, clockwise);
          break;
      case _RAISE:
          // TODO: OLED swap screen?
          break;
      case _LOWER:
          brightneess_encoder(index, clockwise);
          break;
      case _ADJUST:
          
          break;
    }
    return true;
}
#endif

