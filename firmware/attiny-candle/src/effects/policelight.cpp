#include <Arduino.h>
#include <util/delay.h>
#include <light_random.h>
#include "policelight.h"

#define POLICE_STATES_COUNT 16
#define POLICE_LIGHT_ON 50
#define POLICE_LIGHT_OFF 50
#define POLICE_LIGHT_SPACER_1 250
#define POLICE_LIGHT_SPACER_2 750

const LedSet states[POLICE_STATES_COUNT] PROGMEM = {
    { POLICE_LIGHT_ON, (cRGB) {0, 255, 0} },
    { POLICE_LIGHT_OFF, (cRGB) {0, 0, 0} },
    { POLICE_LIGHT_ON, (cRGB) {0, 255, 0} },
    { POLICE_LIGHT_OFF, (cRGB) {0, 0, 0} },
    { POLICE_LIGHT_ON, (cRGB) {0, 255, 0} },
    { POLICE_LIGHT_OFF, (cRGB) {0, 0, 0} },
    { POLICE_LIGHT_ON, (cRGB) {0, 255, 0} },
    { POLICE_LIGHT_SPACER_1, (cRGB) {0, 0, 0} },
    { POLICE_LIGHT_ON, (cRGB) {0, 0, 255} },
    { POLICE_LIGHT_OFF, (cRGB) {0, 0, 0} },
    { POLICE_LIGHT_ON, (cRGB) {0, 0, 255} },
    { POLICE_LIGHT_OFF, (cRGB) {0, 0, 0} },
    { POLICE_LIGHT_ON, (cRGB) {0, 0, 255} },
    { POLICE_LIGHT_OFF, (cRGB) {0, 0, 0} },
    { POLICE_LIGHT_ON, (cRGB) {0, 0, 255} },
    { POLICE_LIGHT_SPACER_2, (cRGB) {0, 0, 0} },
};

void PoliceLight::loop()
{
    now = millis();
    if (now > next_seq_at) {
        seq++;
        // s = states[seq % POLICE_STATES_COUNT];
        memcpy_P( &s, &states[seq % POLICE_STATES_COUNT], sizeof(LedSet));
        next_seq_at = now + s.time;

        for (uint8_t i = 0; i < count; i++)
            leds[i] = s.color;

        ws2812_setleds(leds, count);
    }
    
}