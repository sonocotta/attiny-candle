#include <Arduino.h>
#include <Wire.h>

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#include "RTC_PCF8563.h"
RTC_PCF8563 rtc;

#ifdef LIB_TINYWIRE
#include <TinyWireM.h>
#else
#include <Wire.h>
#endif

#ifdef OLED_ENABLED
#ifdef LIB_TINYWIRE
#include <Tiny4kOLED_TinyWireM.h>
#else
#include <Tiny4kOLED_Wire.h>
#endif
#ifdef OLED_LARGE
#include "font8x16digitssymbols.h"
#endif
#define OLED_WIDTH 128
#define OLED_WIDTH_COLS (OLED_WIDTH >> 2)
#define OLED_HEIGHT 32
#define OLED_HEIGHT_ROWS (OLED_HEIGHT >> 3)
#endif

void setup()
{
#ifdef LIB_TINYWIRE
    TinyWireM.begin();
#else
    Wire.begin();
#endif

#ifdef OLED_ENABLED
    oled.begin(OLED_WIDTH, OLED_HEIGHT, sizeof(tiny4koled_init_128x32br), tiny4koled_init_128x32br);
    #ifdef OLED_LARGE
    oled.setRotation(0);
    oled.setFontX2(FONT8X16DIGITSPLUS);
    #else
    oled.setFont(FONT6X8);
    #endif
    oled.clear();
    oled.on();
    
#endif

    //oled.setCursor((OLED_WIDTH_COLS >> 1) << 2, OLED_HEIGHT_ROWS >> 1);

#ifdef LIB_TINYWIRE
    uint8_t result = rtc.begin(&TinyWireM);
#else
    uint8_t result = rtc.begin(&Wire);
#endif

    if (!result)
    {
#ifdef OLED_ENABLED
        oled.println("RTC failed");
#endif
    }
    else
    {
#ifdef OLED_ENABLED
        oled.println("RTC init okay");
#endif
    }

    if (rtc.lostPower())
    {
#ifdef OLED_ENABLED
        oled.println(F("RTC calibration..."));
        oled.println(F(__DATE__));
        oled.println(F(__TIME__));
#endif
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    rtc.start();

    // delay(3000);

#ifdef OLED_ENABLED
    oled.switchRenderFrame();
#endif
}

void loop()
{
    DateTime now = rtc.now();

#ifdef OLED_ENABLED
    oled.clear();
    // oled.setCursor((OLED_WIDTH_COLS >> 1) << 2, OLED_HEIGHT_ROWS >> 1);
    #ifdef OLED_LARGE
    oled.print(now.hour(), DEC);
    oled.print('/');
    if (now.minute() < 10)
        oled.print('0');
    oled.print(now.minute(), DEC);
    oled.print('/');
    if (now.second() < 10)
        oled.print('0');
    oled.print(now.second(), DEC);
    #else
    oled.print(now.year(), DEC);
    oled.print('/');
    oled.print(now.month(), DEC);
    oled.print('/');
    oled.print(now.day(), DEC);
    oled.print(" (");
    oled.print(daysOfTheWeek[now.dayOfTheWeek()]);
    oled.println(") ");

    oled.print(now.hour(), DEC);
    oled.print(':');
    oled.print(now.minute(), DEC);
    oled.print(':');
    oled.print(now.second(), DEC);
    oled.println();
    #endif
#endif

    // uint8_t buffer[7];
    // rtc.raw(buffer);

// #ifdef OLED_ENABLED
//     for (uint8_t x = 0; x < 7; x++)
//     {
//         oled.print(buffer[x], DEC);
//         oled.print(' ');
//     }
// #endif

#ifdef OLED_ENABLED
    oled.switchFrame();
#endif

    delay(1000);
}
