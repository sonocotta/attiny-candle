#pragma once

#include <light_ws2812.h>
#include "effect.h"

struct LedSet {
    uint32_t time;
    cRGB color;
};

class PoliceLight: public LedEffect
{
public:
    PoliceLight(uint8_t count, cRGB * leds): LedEffect(count, leds) {}
    void loop();
private:
    uint32_t seq = 0;
    volatile uint32_t now = 0;
    volatile uint32_t next_seq_at = 0;
    LedSet s;
};