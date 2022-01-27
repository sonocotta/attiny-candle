#pragma once

#include "effect.h"
#include <light_ws2812.h>

#define STEP_WAIT_TIME 25

class RainBowLed : public LedEffect
{
public:
    RainBowLed(uint8_t count, cRGB * leds) : LedEffect(count, leds) {}
    void loop();
private:
    void wheel(uint8_t, uint8_t);
};