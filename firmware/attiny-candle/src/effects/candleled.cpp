#include <Arduino.h>
#include <util/delay.h>
#include <light_random.h>
#include "candleled.h"

void CandleLed::loop()
{
    now = millis();
    // since_change = now - changed_color_at;
    if (now < next_loop)
        return;

    next_loop = now + wait_time;

    // change color after COLOR_CHANGE_TIME milliseconds
    if (now > change_color_at)
    {
        // changed_color_at = now;
        change_color_at = now + COLOR_CHANGE_TIME;
        prev_color = next_color;

        uint8_t chg = (random_get() & 0x40) + 0x80;

        // switch (seq++ % 3)
        // {
        // case 0:
        //     next_color = (cRGB){chg, 0, 0};
        //     break;
        // case 1:
        //     next_color = (cRGB){0, 0, chg};
        //     break;
        // default:
        //     next_color = (cRGB){0, chg, 0};
        // }

        next_color = (cRGB){(chg >> 3) * 3, (chg), (chg >> 4)};

        wait_time = COLOR_CHANGE_TIME / chg;
    }

    // if (next_color.r != prev_color.r)
    // {
    //     if (next_color.r > prev_color.r)
    //     {
    //         if (curr_color.r < 0xff)
    //             curr_color.r++;
    //     }
    //     else
    //     {
    //         if (curr_color.r > 0)
    //             curr_color.r--;
    //     }
    // }

    // if (next_color.g != prev_color.g)
    // {
    //     if (next_color.g > prev_color.g)
    //     {
    //         if (curr_color.g < 0xff)
    //             curr_color.g++;
    //     }
    //     else
    //     {
    //         if (curr_color.g > 0)
    //             curr_color.g--;
    //     }
    // }

    // if (next_color.b != prev_color.b)
    // {
    //     if (next_color.b > prev_color.b)
    //     {
    //         if (curr_color.b < 0xff)
    //             curr_color.b++;
    //     }
    //     else
    //     {
    //         if (curr_color.b > 0)
    //             curr_color.b--;
    //     }
    // }

    curr_color = next_color;

    for (uint8_t i = 0; i < count; i++)
    {
        // leds[i] = curr_color;
        leds[i].r = curr_color.r >> i; // + (random_get() & 0x03);
        leds[i].g = curr_color.g >> i; // + (random_get() & 0x03);
        leds[i].b = curr_color.b >> i; // + (random_get() & 0x03);
    }

    ws2812_setleds(leds, count);
    // _delay_ms(wait_time);
}