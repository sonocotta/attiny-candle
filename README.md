# ATtiny Candle project files

![Open Source Hardware](/images/open-source-hardware-logo.png)
![Open Source Software](/images/open-source-software-logo.png)

ATtiny Candle is a small development kit that is based on [Microship ATtiny85](https://www.microchip.com/en-us/product/ATTINY85) MCU and [Micronucleos](https://github.com/micronucleus/micronucleus) bootloader, that allows USB communication for both flashing and communication. It is fully compatible with [Digispark Digistump](http://digistump.com/products/1) board and works seamlessly with [Digistump Arduino](https://github.com/digistump/DigistumpArduino) and [Digistump Examples](https://github.com/digistump/DigisparkExamplePrograms).

![image](https://user-images.githubusercontent.com/5459747/151518458-3be742e7-5b9d-4d59-91a2-0ebae36c39b3.png)

## Main features

- Direct programming via built-in USB port, no external programmers needed
- Onboard RESET button
- Onboard user programmable buttons
- 8 KB Flash memory, 512B EEPROM, 512B SRAM
- Onboard ISP header with the possibility to play around bootloader

It has two flawors: OLED and RGB

1. RGB
  - 6x onboard individually addressable RGB leds
1. OLED
  - 32x128 OLED screen 
  - PCF8563 RTC clock with CR2012 battery

## How to use it

### Using Platformio and included samples

All samples in this repo are provided as Platformio projects, please follow the official Platformio [installation guide](https://platformio.org/install) first.

Open any of the included firware samples and build project using `Platformio: Build` task. Upload to target using `Platformio: Upload` task. Platformio will handle all the framework and library dependencies automatically.

...

### Using Arduino

Please follow [Digispark tutorial](http://digistump.com/wiki/digispark/tutorials/connecting)

### Standalone, using onboard ISP Header 

You can use [USBASP](https://www.fischl.de/usbasp/) or aby other AVR chip programmer to flash ATTINY85 chip directly using onboard ISP connector

![image](https://user-images.githubusercontent.com/5459747/151520622-ce635541-6a04-4b6d-98e0-ca0ace2ba5b7.png)

## Hardware

Please find hardware schematics in the [hardware](/hardware) folder

### RGB Flavor

![image](https://user-images.githubusercontent.com/5459747/151518970-5fff1eeb-1583-44b2-a5eb-14ba637d89f3.png)

- ![image](https://user-images.githubusercontent.com/5459747/151518836-28a5a8f1-82a3-4762-ad94-a7ed43a5d9cf.png) ATTINY85 MCU
- ![image](https://user-images.githubusercontent.com/5459747/151518872-c2e90082-bbfe-489d-924d-f8ae88180231.png) USB conenction (with ESD protection)
- ![image](https://user-images.githubusercontent.com/5459747/151518899-f664732f-85cf-4f11-bc08-f04d78e741fb.png) RESET button
- ![image](https://user-images.githubusercontent.com/5459747/151518917-84c9b826-9375-43b6-9d1d-6bb9fdaeb50d.png) User-programmable buttons with de-bounce filters
- ![image](https://user-images.githubusercontent.com/5459747/151518934-36d695a7-d2d1-4932-be82-0e4f6e6d1977.png) 6x WS2812 addressable LEDs
- ![image](https://user-images.githubusercontent.com/5459747/151518956-53783cce-99a6-4c30-965a-5d6ef105ddc5.png) ISP programming header (for advanced scenarios)

### OLED Flavor

![image](https://user-images.githubusercontent.com/5459747/151519275-4a7a43c0-7668-4325-ba49-9541b8632519.png)
![image](https://user-images.githubusercontent.com/5459747/151519947-02fbf1aa-5088-4b12-8a90-ee8d6ef9bbc0.png)

- ![image](https://user-images.githubusercontent.com/5459747/151518836-28a5a8f1-82a3-4762-ad94-a7ed43a5d9cf.png) ATTINY85 MCU
- ![image](https://user-images.githubusercontent.com/5459747/151518872-c2e90082-bbfe-489d-924d-f8ae88180231.png) USB conenction (with ESD protection)
- ![image](https://user-images.githubusercontent.com/5459747/151518899-f664732f-85cf-4f11-bc08-f04d78e741fb.png) RESET button
- ![image](https://user-images.githubusercontent.com/5459747/151518917-84c9b826-9375-43b6-9d1d-6bb9fdaeb50d.png) User-programmable button with de-bounce filters
- ![image](https://user-images.githubusercontent.com/5459747/151518934-36d695a7-d2d1-4932-be82-0e4f6e6d1977.png) SSD1306 32x128 OLED screen
- ![image](https://user-images.githubusercontent.com/5459747/151518956-53783cce-99a6-4c30-965a-5d6ef105ddc5.png) ISP programming header (for advanced scenarios)
- (under the screen) PCF8563 RTC clock chip and backup battery

## Firmware

Please find more info in the each of the project's readme

- [attiny-candle](/firmware/attiny-candle) - RGB visual effects demonstration 
- [attiny-candle-keyboard](/firmware/attiny-candle-keyboard) - Device acts as a keyboard, sending keystokes to the HOST. Button used as a switch.
- [attiny-candle-mouse](/firmware/attiny-candle-mouse) - Device acts as a mouse shaking the cursor. Button used as a switch.
- [attiny-candle-red-green-light](/firmware/attiny-candle-red-green-light) - Go-No-Go game using RGB leds
- [attiny-candle-rtc-clock](/firmware/attiny-candle-rtc-clock) - Sample digital clock project
- [attiny-oled-test](/firmware/attiny-oled-test) - Simple demonstration of OLED working with both standard and light TwoWire implementation.

## Where to buy

Shortly on [Tindie](https://www.tindie.com/) store.

## Links

- [Microship ATTINY85](https://www.microchip.com/en-us/product/ATTINY85)
- [Micronucleos](https://github.com/micronucleus/micronucleus)
- [ATtiny Flasher - Product site](https://sonocotta.com/attiny-candle/)
