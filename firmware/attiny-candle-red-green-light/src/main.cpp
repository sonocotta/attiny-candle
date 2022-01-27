// #include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <light_ws2812.h>
#include <light_random.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <util/delay.h>

#define TIMEOUT_TRANSITION 2000
#define TIMEOUT_SWITCH 5000

enum State
{
  IDLE,
  GREEN_LIGHT,
  GREEN_TO_RED,
  GREEN_TO_GREEN,
  RED_LIGHT,
  RED_TO_GREEN,
  RED_TO_RED
};

State state = IDLE;

struct cRGB leds[NUM_PIXELS];

#define MAX_BRT 0x40

cRGB COLOR_RED = { MAX_BRT, 0, 0 };
cRGB COLOR_WHITE = { MAX_BRT, MAX_BRT, MAX_BRT };
cRGB COLOR_BLACK = { 0, 0, 0 };
cRGB COLOR_BLUE = { 0, 0, MAX_BRT };
cRGB COLOR_GREEN = { 0, MAX_BRT, 0 };

uint32_t status_switched_at = 0;

void setAllLedsColor(cRGB color)
{
  for (uint8_t i = 0; i < NUM_PIXELS; i++)
    // strip.setPixelColor(i, color);
    leds[i] = color;
}

void blink_led_loop(cRGB color, uint16_t all_time, uint16_t on_time)
{
  if (millis() % all_time < on_time)
    setAllLedsColor(color);
  else
    setAllLedsColor(COLOR_BLACK);
  // strip.show();
  ws2812_setleds(leds, NUM_PIXELS);
}

void setup()
{
  pinMode(PIN_BTN_1, INPUT);
  pinMode(PIN_BTN_2, INPUT);

  random_init(0x9354);

  setAllLedsColor(COLOR_GREEN);
  ws2812_setleds(leds, NUM_PIXELS);
  _delay_ms(128);
  setAllLedsColor(COLOR_BLACK);
  ws2812_setleds(leds, NUM_PIXELS);
}

void loop()
{
  if (digitalRead(PIN_BTN_1) == LOW)
  {
    state = GREEN_LIGHT;
    status_switched_at = millis();
  }
  else if (digitalRead(PIN_BTN_2) == LOW)
  {
    state = RED_LIGHT;
    status_switched_at = millis();
  }
  // else
  // {
  //   state = IDLE;
  // }

  switch (state)
  {
  case IDLE:
    setAllLedsColor(COLOR_BLACK);
    // strip.show();
    ws2812_setleds(leds, NUM_PIXELS);
    break;

  case RED_LIGHT:
    setAllLedsColor(COLOR_RED);
    // strip.show();
    ws2812_setleds(leds, NUM_PIXELS);
    if (millis() > status_switched_at + TIMEOUT_SWITCH)
    {
      state = (random_get() & 0x1) ? RED_TO_GREEN : RED_TO_RED;
      status_switched_at = millis();
    }
    break;

  case GREEN_LIGHT:
    setAllLedsColor(COLOR_GREEN);
    // strip.show();
    ws2812_setleds(leds, NUM_PIXELS);
    if (millis() > status_switched_at + TIMEOUT_SWITCH)
    {
      state = (random_get() & 0x1) ? GREEN_TO_RED : GREEN_TO_GREEN;
      status_switched_at = millis();
    }
    break;

  case GREEN_TO_RED:
    blink_led_loop(COLOR_GREEN, 512, 256);
    // strip.show();
    ws2812_setleds(leds, NUM_PIXELS);
    if (millis() > status_switched_at + TIMEOUT_TRANSITION)
    {
      state = RED_LIGHT;
      status_switched_at = millis();
    }
    break;

  case GREEN_TO_GREEN:
    blink_led_loop(COLOR_GREEN, 512, 256);
    // strip.show();
    ws2812_setleds(leds, NUM_PIXELS);
    if (millis() > status_switched_at + TIMEOUT_TRANSITION)
    {
      state = GREEN_LIGHT;
      status_switched_at = millis();
    }
    break;

  case RED_TO_GREEN:
    setAllLedsColor(COLOR_RED);
    blink_led_loop(COLOR_RED, 512, 256);
    // strip.show();
    ws2812_setleds(leds, NUM_PIXELS);
    if (millis() > status_switched_at + TIMEOUT_TRANSITION)
    {
      state = GREEN_LIGHT;
      status_switched_at = millis();
    }
    break;

  case RED_TO_RED:
    setAllLedsColor(COLOR_RED);
    blink_led_loop(COLOR_RED, 512, 256);
    // strip.show();
    ws2812_setleds(leds, NUM_PIXELS);
    if (millis() > status_switched_at + TIMEOUT_TRANSITION)
    {
      state = RED_LIGHT;
      status_switched_at = millis();
    }
    break;
  }
}
