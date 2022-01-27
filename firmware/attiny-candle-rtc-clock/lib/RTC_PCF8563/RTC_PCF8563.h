/**************************************************************************/
/*!
  @file     RTClib.h

  Original library by JeeLabs http://news.jeelabs.org/code/, released to the
  public domain

  License: MIT (see LICENSE)

  This is a fork of JeeLab's fantastic real time clock library for Arduino.

  For details on using this library with an RTC module like the DS1307, PCF8523,
  or DS3231, see the guide at:
  https://learn.adafruit.com/ds1307-real-time-clock-breakout-board-kit/overview

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!
*/
/**************************************************************************/

#ifndef _RTC_PCF8563_H_
#define _RTC_PCF8563_H_

#include <RTClib.h>
#include <Adafruit_I2CDevice.h>
#include <Arduino.h>

/** PCF8563 CLKOUT pin mode settings */
enum Pcf8563SqwPinMode {
  PCF8563_SquareWaveOFF = 0x00,  /**< Off */
  PCF8563_SquareWave1Hz = 0x83,  /**< 1Hz square wave */
  PCF8563_SquareWave32Hz = 0x82, /**< 32Hz square wave */
  PCF8563_SquareWave1kHz = 0x81, /**< 1kHz square wave */
  PCF8563_SquareWave32kHz = 0x80 /**< 32kHz square wave */
};

/**************************************************************************/
/*!
    @brief  RTC based on the PCF8563 chip connected via I2C and the Wire library
*/
/**************************************************************************/
class RTC_PCF8563 : RTC_I2C {
public:
  boolean begin(TwoWire *wireInstance);
  boolean lostPower(void);
  void adjust(const DateTime &dt);
  DateTime now();
  void raw(uint8_t*);
  void start(void);
  void stop(void);
  uint8_t isrunning();
  Pcf8563SqwPinMode readSqwPinMode();
  void writeSqwPinMode(Pcf8563SqwPinMode mode);
};

#endif // _RTCLIB_H_
