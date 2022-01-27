#pragma once

#include <light_ws2812.h>
#include "effect.h"

#define STEP_WAIT_TIME 500

class RandomLed: public LedEffect
{
public:
    RandomLed(uint8_t count, cRGB * leds): LedEffect(count, leds) {}
    void loop();
};