#pragma once

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

typedef HSV (*reactive_f)(HSV hsv, uint16_t offset);

bool runner_gradReact(effect_params_t* params, reactive_f effect_func) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        HSV hsv  = rgb_matrix_config.hsv;
        uint8_t scale = scale8(64, rgb_matrix_config.speed);
        hsv.h   = rgb_matrix_config.hsv.h + scale * (g_led_config.point[i].y >> 4);


        uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
        RGB      rgb    = rgb_matrix_hsv_to_rgb(effect_func(hsv, offset));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
