#include <util/delay.h>
#include <light_random.h>
#include "randomled.h"

uint8_t seq = 0;

#define SHIFT_1 2
#define SHIFT_2 4

void RandomLed::loop()
{

    for (uint8_t i = 0; i < count; i++)
    {
        uint8_t chg = 64 + (random_get() & 0xbf);
        switch (seq++ % 6)
        {
        case 0:
            leds[i].r = chg;
            leds[i].g = chg >> SHIFT_1;
            leds[i].b = chg >> SHIFT_2;
            break;

        case 1:
            leds[i].r = chg;
            leds[i].b = chg >> SHIFT_1;
            leds[i].g = chg >> SHIFT_2;
            break;

        case 2:
            leds[i].g = chg;
            leds[i].r = chg >> SHIFT_1;
            leds[i].b = chg >> SHIFT_2;
            break;

        case 3:
            leds[i].g = chg;
            leds[i].b = chg >> SHIFT_1;
            leds[i].r = chg >> SHIFT_2;
            break;

        case 4:
            leds[i].b = chg;
            leds[i].g = chg >> SHIFT_1;
            leds[i].r = chg >> SHIFT_2;
            break;

        case 5:
            leds[i].b = chg;
            leds[i].r = chg >> SHIFT_1;
            leds[i].g = chg >> SHIFT_2;
            break;
        }

        // leds[i].r = random_get() & 0xff;
        // leds[i].g = random_get() & 0xff;
        // leds[i].b = random_get() & 0xff;
    }

    ws2812_setleds(leds, count);
    _delay_ms(STEP_WAIT_TIME);
}