# ATtiny Candle project files

![Open Source Hardware](/images/open-source-hardware-logo.png)
![Open Source Software](/images/open-source-software-logo.png)

ATtiny Candle is a small development kit that is based on Microchip [ATtiny85](https://www.microchip.com/en-us/product/ATTINY85) and [ATtiny13](https://www.microchip.com/en-us/product/ATtiny13) MCU. 

ATtiny85 boards are based on [Micronucleos](https://github.com/micronucleus/micronucleus) bootloader, that allows USB communication for both flashing and user code communication. It is fully compatible with [Digispark Digistump](http://digistump.com/products/1) board and works seamlessly with [Digistump Arduino](https://github.com/digistump/DigistumpArduino) and [Digistump Examples](https://github.com/digistump/DigisparkExamplePrograms).

ATtiny13 board in turn requires bare-chip code and external programmer, in general much more demanding, since it has a fraction of ATtiny85's resources.

![image](https://user-images.githubusercontent.com/5459747/151707251-51a888a1-b9d6-4f83-a34f-62eab09ccd76.png)

## Main features

It has three flavors: T13 RGB, T85 RGB, T85 OLED

|   | T13 RGB  | T85 RGB  | T85 OLED  |
|---|---|---|---|
| MCU  | ATtiny13A  | ATTiny85 | ATtiny85  | 
| Voltage | +5V | +5V | +5V |
| RAM  | 64 B | 512 B  | 512 B  |
| FLASH  | 1 KB  | 8 KB  | 8 KB  |
| EEPROM  | 64 B  | 512 B  | 512 B |
| Bootloader  | None  | Micronucleos  | Micronucleos  | 
| USB  | Power only  | USB communication for flashing and user code  | USB communication for flashing and user code  | 
| USB Programming | No | Yes | Yes |
| ISP Header | Yes | Yes | Yes |
| Inputs  | 2 buttons  | 2 buttons  | 1 button  |
| RESET button  | No  | Yes  | Yes  | 
| Outputs  | 4 individually controlled RGB leds  | 6 individually controlled RGB leds  | 32x128 Monochrome OLED screen | 
| Additional Peripheral | - | - | PCF8563 RTC clock with CR2012 battery | 

## How to use it

### Using Platformio and included samples

All samples in this repo are provided as Platformio projects, please follow the official Platformio [installation guide](https://platformio.org/install) first.

Open any of the included firware samples and build project using `Platformio: Build` task. Upload to target using `Platformio: Upload` task. Platformio will handle all the framework and library dependencies automatically.

![Programming via Pltformio IDE](/firmware/attiny-candle/images/simplescreenrecorder-2022-01-29_21.14.58.mkv.gif)

### Using Arduino

Please follow [Digispark tutorial](http://digistump.com/wiki/digispark/tutorials/connecting)

### Standalone, using onboard ISP Header 

You can use [USBASP](https://www.fischl.de/usbasp/) or aby other AVR chip programmer to flash ATTINY85 chip directly using onboard ISP connector

![image](https://user-images.githubusercontent.com/5459747/151520622-ce635541-6a04-4b6d-98e0-ca0ace2ba5b7.png)

## Hardware

Please find hardware schematics in the [hardware](/hardware) folder

### T13 RGB Flavor

![image](https://user-images.githubusercontent.com/5459747/151707337-ce46ca04-491c-408e-a4f3-72cd2d1642c1.png)

- ![image](https://user-images.githubusercontent.com/5459747/151518836-28a5a8f1-82a3-4762-ad94-a7ed43a5d9cf.png) ATTINY13 MCU
- ![image](https://user-images.githubusercontent.com/5459747/151518872-c2e90082-bbfe-489d-924d-f8ae88180231.png) USB conenction (For power only)
- ![image](https://user-images.githubusercontent.com/5459747/151518917-84c9b826-9375-43b6-9d1d-6bb9fdaeb50d.png) User-programmable buttons with de-bounce filters
- ![image](https://user-images.githubusercontent.com/5459747/151518934-36d695a7-d2d1-4932-be82-0e4f6e6d1977.png) 4x WS2812 addressable LEDs
- ![image](https://user-images.githubusercontent.com/5459747/151518956-53783cce-99a6-4c30-965a-5d6ef105ddc5.png) ISP programming header (for flashing)

### T85 RGB Flavor

![image](https://user-images.githubusercontent.com/5459747/151518970-5fff1eeb-1583-44b2-a5eb-14ba637d89f3.png)

- ![image](https://user-images.githubusercontent.com/5459747/151518836-28a5a8f1-82a3-4762-ad94-a7ed43a5d9cf.png) ATTINY85 MCU
- ![image](https://user-images.githubusercontent.com/5459747/151518872-c2e90082-bbfe-489d-924d-f8ae88180231.png) USB conenction (with ESD protection)
- ![image](https://user-images.githubusercontent.com/5459747/151518899-f664732f-85cf-4f11-bc08-f04d78e741fb.png) RESET button
- ![image](https://user-images.githubusercontent.com/5459747/151518917-84c9b826-9375-43b6-9d1d-6bb9fdaeb50d.png) User-programmable buttons with de-bounce filters
- ![image](https://user-images.githubusercontent.com/5459747/151518934-36d695a7-d2d1-4932-be82-0e4f6e6d1977.png) 6x WS2812 addressable LEDs
- ![image](https://user-images.githubusercontent.com/5459747/151518956-53783cce-99a6-4c30-965a-5d6ef105ddc5.png) ISP programming header (for advanced scenarios)

### T85 OLED Flavor

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

| Link  | Desc  | T13 RGB  | T85 RGB  | T85 OLED  |
|---|---|---|---|---|
| [attiny-candle](/firmware/attiny-candle)  | RGB visual effects demonstration  | Yes  | Yes  | Yes |
| [attiny-candle-keyboard](/firmware/attiny-candle-keyboard) | Device acts as a keyboard, sending keystokes to the HOST. Button used as a switch. | No | Yes | Yes |
| [attiny-candle-mouse](/firmware/attiny-candle-mouse) | Device acts as a mouse shaking the cursor. Button used as a switch. | No | Yes | Yes |
| [attiny-candle-red-green-light](/firmware/attiny-candle-red-green-light) | Go-No-Go game using RGB leds  | Yes  | Yes  | Yes |
| [attiny-candle-rtc-clock](/firmware/attiny-candle-rtc-clock) | Sample digital clock project | No | No | Yes |
| [attiny-oled-test](/firmware/attiny-oled-test) | Sample OLED programm using Wire or TinyWire library | No | No | Yes |

## Where to buy

Order at [Tindie](https://www.tindie.com/products/sonocotta/attiny-candle/)

## Demo

![Candle light](/firmware/attiny-candle/images/VID_20220129_211015.mp4.gif)

## Links

- [Microship ATTINY85](https://www.microchip.com/en-us/product/ATTINY85)
- [Micronucleos](https://github.com/micronucleus/micronucleus)
- [ATtiny Flasher - Product site](https://sonocotta.com/attiny-candle/)
