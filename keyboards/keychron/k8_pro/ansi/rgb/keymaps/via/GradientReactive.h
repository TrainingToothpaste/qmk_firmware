#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

RGB_MATRIX_EFFECT(GradientReactive)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

 static HSV reactive_Math(HSV hsv_r, uint16_t offset) {

    hsv_r.s = scale8(0 + offset, hsv_r.s);
    return hsv_r;
    }

bool GradientReactive (effect_params_t* params) {
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


        return runner_gradReact(params, &reactive_Math);


 //   return rgb_matrix_check_finished_leds(led_max);

}

#    endif         // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
