#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

RGB_MATRIX_EFFECT(GradientWide)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS


//#define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE

 static HSV wideReactive_Math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;

#            ifdef RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
    hsv.h += qsub8(130, offset);
#            endif

    hsv.s = scale8(0 + effect, hsv.s);
    return hsv;
    }

bool GradientWide (effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // Background code
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        // get current HSV config
        HSV hsv  = rgb_matrix_config.hsv;

        // update color for each key
        uint8_t scale = scale8(64, rgb_matrix_config.speed);
        hsv.h   = rgb_matrix_config.hsv.h + scale * (g_led_config.point[i].y >> 4);

        // set LED to that color
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }


        runner_wideGrad(0, params, &wideReactive_Math);


    return rgb_matrix_check_finished_leds(led_max);

}

#    endif         // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
