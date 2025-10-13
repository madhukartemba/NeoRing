# NeoRing

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)  
A lightweight and flexible C++ library for controlling LED rings and strips with **smooth, advanced animations**, compatible with both **FastLED** and **Adafruit NeoPixel**.

---

## Overview

NeoRing is designed to simplify LED animation development on Arduino and PlatformIO platforms. It provides:

- **Hardware abstraction**: Easily switch between FastLED and NeoPixel drivers.  
- **Modular animations**: Pre-built effects like solid colors, rainbow, breathe, wave, spinner, and blink.  
- **Non-blocking updates**: Animations run smoothly using `update()` without delays.  
- **Dynamic frame rate control**: Adjust FPS at runtime for optimal performance.  
- **Custom animation support**: Push your own animations directly into the engine.

---

## Features

| Feature                  | Description                                                                 |
|--------------------------|-----------------------------------------------------------------------------|
| Multi-driver support      | Works with **FastLED** or **Adafruit NeoPixel** seamlessly.                |
| Smooth animations         | Engine handles transitions and blending for a polished visual effect.      |
| Multiple effects          | Solid, Rainbow, Breathe, Wave, Spinner, Blink, and Blank.                  |
| Non-blocking design       | Uses `update()` and timers instead of `delay()` for responsive behavior.   |
| FPS control               | Easily set frames per second with `setFPS()`.                               |
| Extensible                | Add custom animations with `addAnimation()`.                                |

---

## Installation

### Arduino IDE

1. Download the latest release from [GitHub](https://github.com/madhukartemba/NeoRing).  
2. Extract the folder into your Arduino `libraries` directory.  
3. Include in your sketch:

```cpp
#include <NeoRing.h>
```

### PlatformIO

Add the following to your `platformio.ini`:

```
lib_deps =
    madhukartemba/NeoRing
```

PlatformIO will automatically install FastLED and Adafruit NeoPixel if not already installed.

---

## Quick Start Example

```cpp
#include <NeoRing.h>

#define LED_PIN     6
#define LED_COUNT   24
#define DRIVER      DisplayDriver::NEOPIXEL
#define FPS         60.0
#define ANIM_DELAY  3000

NeoRing ring;
unsigned long lastSwitch = 0;
int currentAnim = 0;

void setup() {
    ring.begin(LED_COUNT, LED_PIN, DRIVER);
    ring.setFPS(FPS);

    ring.solid(0xFF0000);   // Start with red
    ring.finishTransition();
    lastSwitch = millis();
}

void loop() {
    ring.update();

    unsigned long now = millis();
    if (now - lastSwitch >= ANIM_DELAY) {
        lastSwitch = now;
        currentAnim = (currentAnim + 1) % 6;

        switch(currentAnim) {
            case 0: ring.solid(0x00FF00); break;
            case 1: ring.rainbow(1.0f); break;
            case 2: ring.breathe(0x0000FF, 0.2f, 1.0f); break;
            case 3: ring.wave(0xFFFF00, 8.0f); break;
            case 4: ring.spinner(5, 0xFF00FF, 1.5f); break;
            case 5: ring.blink(0xFFFFFF, 3); break;
        }
    }
}
```

This example demonstrates non-blocking animation switching, FPS control, and multiple built-in effects.

---

## Usage

### Basic Animations

```cpp
ring.solid(0xFF0000);               // Solid red
ring.rainbow(1.0f);                 // Rainbow cycle
ring.breathe(0x0000FF, 0.5f, 1.0f); // Breathing effect
ring.wave(0xFFFF00, 10.0f);         // Wave animation
ring.spinner(5, 0xFF00FF, 1.0f);    // Spinner with trail
ring.blink(0xFFFFFF, 3);            // Blink a color multiple times
ring.blank();                       // Turn off LEDs
```

### Custom Animations

You can push your own animation object directly:

```cpp
std::unique_ptr<Animation> myAnim = std::make_unique<MyCustomAnimation>(...);
ring.addAnimation(std::move(myAnim));
```

### Adjusting FPS

```cpp
ring.setFPS(120.0); // Increase update speed
```

---

## Supported Hardware

- **LED Types:** WS2812, WS2812B, WS2813, SK6812, etc. (NeoPixel-compatible)
- **Drivers:** FastLED or Adafruit NeoPixel
- **Platforms:** Arduino boards, ESP32, ESP8266, and other Arduino-compatible boards

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Author

Madhukar Temba


