#include QMK_KEYBOARD_H

#define _MAIN 0

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { 
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } 
}

enum {
  TD_RGB = 0,
  TD_AT = 0,
  AT_ADN = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case AT_ADN:
        if (record->event.pressed) {
            // when keycode AT_ADN is pressed
            SEND_STRING("");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

void dance_rgb_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_MEDIA_NEXT_TRACK);
	  unregister_code (KC_MEDIA_NEXT_TRACK);
  } else if (state->count == 2) {
    rgblight_toggle();
  } else if (state->count == 3) {
    rgblight_step();
  }
}
void dance_rgb_finished2 (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_MEDIA_NEXT_TRACK);
	  unregister_code (KC_MEDIA_NEXT_TRACK);
  } else if (state->count == 2) {
    rgblight_toggle();
  } else if (state->count == 3) {
    rgblight_step();
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_RGB] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rgb_finished, NULL),
 [TD_AT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rgb_finished2, NULL)
};

//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //buttion closest to usb is first
  [_MAIN] = LAYOUT(
     KC_MUTE, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, AT_ADN, TD(TD_RGB)
  )
};
