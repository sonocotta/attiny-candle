#include <util/delay.h>
#include "rainbowled.h"

void RainBowLed::wheel(uint8_t WheelPos, uint8_t i)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85)
    {
        leds[i].r = 255 - WheelPos * 3;
        leds[i].g = 0;
        leds[i].b = WheelPos * 3;
        //return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
        return;
    }
    if (WheelPos < 170)
    {
        WheelPos -= 85;
        //return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
        leds[i].r = 0;
        leds[i].g = WheelPos * 3;
        leds[i].b = 255 - WheelPos * 3;
        return;
    }
    WheelPos -= 170;
    // return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);

    leds[i].r = WheelPos * 3;
    leds[i].g = 255 - WheelPos * 3;
    leds[i].b = 0;
    return;
}

void RainBowLed::loop()
{
    uint16_t i, j;

    for (j = 0; j < 256 * 5; j++)
    { // 5 cycles of all colors on wheel
        for (i = 0; i < count; i++)
        {
            wheel(((i * 256 / count) + j) & 255, i);
        }
        //strip.show();
        ws2812_setleds(leds, count);
        _delay_ms(STEP_WAIT_TIME);
    }
}