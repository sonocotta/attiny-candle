#include <Arduino.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include <light_ws2812.h>
#include <light_random.h>

#define PIN_BTN_1 0
#define PIN_BTN_2 1

#ifdef EFFECT_RAINBOW
#include "effects/rainbowled.h"
#define Effect RainBowLed
#endif

#ifdef EFFECT_RANDOM
#include "effects/randomled.h"
#define Effect RandomLed
#endif

#ifdef EFFECT_CANDLE
#include "effects/candleled.h"
#define Effect CandleLed
#endif

cRGB leds[NUM_PIXELS];
Effect effect(NUM_PIXELS, leds);

void setup()
{
    pinMode(PIN_BTN_1, INPUT);
    pinMode(PIN_BTN_2, INPUT);

    random_init(0x2934);
}

void loop()
{
    effect.loop();
}