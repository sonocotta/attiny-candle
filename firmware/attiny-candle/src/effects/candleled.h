#pragma once

#include <light_ws2812.h>
#include "effect.h"

// #define STEP_WAIT_TIME 8
#define STEPS_REP_CHANGE 256
#define COLOR_CHANGE_TIME (1 << 5)
// #define STEP_WAIT_TIME (COLOR_CHANGE_TIME / STEPS_REP_CHANGE)

class CandleLed: public LedEffect
{
public:
    CandleLed(uint8_t count, cRGB * leds): LedEffect(count, leds) {}
    void loop();
private:
    cRGB prev_color = (cRGB) {0, 0, 0};
    cRGB curr_color = (cRGB) {0, 0, 0};
    cRGB next_color = (cRGB) {0, 0, 0};

    uint8_t seq = 0;
    uint8_t wait_time = 0;
    volatile uint32_t now = 0;
    // volatile uint32_t since_change = 0;
    // volatile uint32_t changed_color_at = 0;
    volatile uint32_t change_color_at = 0;
    volatile uint32_t next_loop = 0;
};