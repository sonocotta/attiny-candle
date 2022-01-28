#include <Arduino.h>
#include <util/delay.h>

#ifdef LIB_TINYWIRE
#include <TinyWireM.h>
#include <Tiny4kOLED_TinyWireM.h>
#else
#include <Wire.h>
#include <Tiny4kOLED_Wire.h>
#endif

#ifdef __AVR_ATmega328P__
#define _SERIAL_
#endif

#define OLED_WIDTH 128
#define OLED_HEIGHT 32

void drawScreen() {
  // Set entire memory to hatched - if you see any of this hatching, then the display is not initialised correctly.
  for (uint8_t y = 0; y < 8; y++) {
    oled.setCursor(0, y);
    oled.startData();
    for (uint8_t x=0; x<128; x += 2) {
      oled.sendData(0b10101010);
      oled.sendData(0b01010101);
    }
    oled.endData();
  }

  oled.setCursor(0, 0);
  oled.startData();
  oled.sendData(0b11111111);
  oled.repeatData(0b00000001, OLED_WIDTH - 2);
  oled.sendData(0b11111111);
  oled.endData();

  for (uint8_t y = 1; y < (OLED_HEIGHT - 8) / 8; y++) {
    oled.setCursor(0, y);
    oled.startData();
    oled.sendData(0b11111111);
    oled.repeatData(0b00000000, OLED_WIDTH - 2);
    oled.sendData(0b11111111);
    oled.endData();
  }

  oled.setCursor(0, (OLED_HEIGHT - 8) / 8);
  oled.startData();
  oled.sendData(0b11111111);
  oled.repeatData(0b10000000, OLED_WIDTH - 2);
  oled.sendData(0b11111111);
  oled.endData();

  oled.setCursor(8, 1);
  oled.print(OLED_WIDTH);
  oled.print('x');
  oled.print(OLED_HEIGHT);
}

void scrollScreen() {
  uint8_t startScrollPage = 1;
  uint8_t endScrollPage = 2;
  uint8_t startScrollColumn = 8;
  uint8_t endScrollColumn = startScrollColumn + OLED_WIDTH - 16;
  for (uint8_t x = 0; x < OLED_WIDTH - 16; x++)
  {
    delay(50);
    oled.scrollContentRight(startScrollPage, endScrollPage, startScrollColumn, endScrollColumn);
  }
}

void setup()
{
  #ifdef _SERIAL_
  Serial.begin(115200);
  Serial.println("Waking up...");

  Serial.print("starting up oled... ");
  #endif

#ifdef LIB_TINYWIRE
  TinyWireM.begin();  
#endif

  oled.begin(OLED_WIDTH, OLED_HEIGHT, sizeof(tiny4koled_init_128x32br), tiny4koled_init_128x32br);
  oled.setFont(FONT8X16);
  drawScreen();
  oled.on();

  #ifdef _SERIAL_
  Serial.println("OK");
  #endif
}

void loop() {
  scrollScreen();
}