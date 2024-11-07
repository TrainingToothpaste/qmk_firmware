#pragma once

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

typedef HSV (*reactive_splash_f)(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick);

bool runner_wideGrad(uint8_t start, effect_params_t* params, reactive_splash_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t count = g_last_hit_tracker.count;

    //for
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;

        //for the last key pressed:
        for (uint8_t j = start; j < count; j++) {
            //setting effect spread:
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            //getting time since last key hit:
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], 40);
            //use the above math to change hsv value
            hsv           = effect_func(hsv, dx, dy, dist, tick);
        }

        //code for all keys, not just those affected by above effect:

        //here I'm setting the "base color" so the below code knows what to set the HSV value to after the
        uint8_t scale = scale8(64, rgb_matrix_config.speed);
        hsv.h   = rgb_matrix_config.hsv.h + scale * (g_led_config.point[i].y >> 4);

        //converting hsv from above to rgb and setting rgb values
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
