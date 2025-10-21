#pragma once
#include <Arduino.h>
#include <FastLED.h>
#include <vector>
#include "LedDriver.h"

// ---------------------------
// Board-specific safe pins
// ---------------------------
#if defined(ESP8266)
constexpr uint8_t SAFE_PINS[] = {1, 3, 4, 5, 12, 13, 14, 15, 16};
#elif defined(ESP32)
constexpr uint8_t SAFE_PINS[] = {0,  2,  4,  5,  12, 13, 14, 15, 18,
                                 19, 21, 22, 23, 25, 26, 27, 32, 33};
#elif defined(__AVR__)  // Arduino AVR (Uno, Nano, Mega, etc.)
constexpr uint8_t SAFE_PINS[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
#else
constexpr uint8_t SAFE_PINS[] = {};  // Unknown board
#endif

// ---------------------------
// FastLEDDriver class (dynamic pin)
// ---------------------------
class FastLEDDriver : public LEDDriver {
   private:
    size_t ledCount;
    uint8_t pin;
    std::vector<CRGB> leds;

    bool isPinSafe(uint8_t p) {
        for (auto sp : SAFE_PINS) {
            if (sp == p) return true;
        }
        return false;
    }

   public:
    FastLEDDriver(size_t ledCount_, uint8_t pin_)
        : ledCount(ledCount_), pin(pin_), leds(ledCount_) {}

    void begin() override {
        if (!isPinSafe(pin)) {
            Serial.printf("Error: Pin %d is not safe for FastLED!\n", pin);
            return;
        }

        // Add LEDs based on runtime pin
        switch (pin) {
#if defined(ESP8266)
            case 1:
                FastLED.addLeds<WS2812B, 1, GRB>(leds.data(), ledCount);
                break;
            case 3:
                FastLED.addLeds<WS2812B, 3, GRB>(leds.data(), ledCount);
                break;
            case 4:
                FastLED.addLeds<WS2812B, 4, GRB>(leds.data(), ledCount);
                break;
            case 5:
                FastLED.addLeds<WS2812B, 5, GRB>(leds.data(), ledCount);
                break;
            case 12:
                FastLED.addLeds<WS2812B, 12, GRB>(leds.data(), ledCount);
                break;
            case 13:
                FastLED.addLeds<WS2812B, 13, GRB>(leds.data(), ledCount);
                break;
            case 14:
                FastLED.addLeds<WS2812B, 14, GRB>(leds.data(), ledCount);
                break;
            case 15:
                FastLED.addLeds<WS2812B, 15, GRB>(leds.data(), ledCount);
                break;
            case 16:
                FastLED.addLeds<WS2812B, 16, GRB>(leds.data(), ledCount);
                break;
#elif defined(ESP32)
            case 0:
                FastLED.addLeds<WS2812B, 0, GRB>(leds.data(), ledCount);
                break;
            case 2:
                FastLED.addLeds<WS2812B, 2, GRB>(leds.data(), ledCount);
                break;
            case 4:
                FastLED.addLeds<WS2812B, 4, GRB>(leds.data(), ledCount);
                break;
            case 5:
                FastLED.addLeds<WS2812B, 5, GRB>(leds.data(), ledCount);
                break;
            case 12:
                FastLED.addLeds<WS2812B, 12, GRB>(leds.data(), ledCount);
                break;
            case 13:
                FastLED.addLeds<WS2812B, 13, GRB>(leds.data(), ledCount);
                break;
            case 14:
                FastLED.addLeds<WS2812B, 14, GRB>(leds.data(), ledCount);
                break;
            case 15:
                FastLED.addLeds<WS2812B, 15, GRB>(leds.data(), ledCount);
                break;
            case 18:
                FastLED.addLeds<WS2812B, 18, GRB>(leds.data(), ledCount);
                break;
            case 19:
                FastLED.addLeds<WS2812B, 19, GRB>(leds.data(), ledCount);
                break;
            case 21:
                FastLED.addLeds<WS2812B, 21, GRB>(leds.data(), ledCount);
                break;
            case 22:
                FastLED.addLeds<WS2812B, 22, GRB>(leds.data(), ledCount);
                break;
            case 23:
                FastLED.addLeds<WS2812B, 23, GRB>(leds.data(), ledCount);
                break;
            case 25:
                FastLED.addLeds<WS2812B, 25, GRB>(leds.data(), ledCount);
                break;
            case 26:
                FastLED.addLeds<WS2812B, 26, GRB>(leds.data(), ledCount);
                break;
            case 27:
                FastLED.addLeds<WS2812B, 27, GRB>(leds.data(), ledCount);
                break;
            case 32:
                FastLED.addLeds<WS2812B, 32, GRB>(leds.data(), ledCount);
                break;
            case 33:
                FastLED.addLeds<WS2812B, 33, GRB>(leds.data(), ledCount);
                break;
#elif defined(__AVR__)
            case 2:
                FastLED.addLeds<WS2812B, 2, GRB>(leds.data(), ledCount);
                break;
            case 3:
                FastLED.addLeds<WS2812B, 3, GRB>(leds.data(), ledCount);
                break;
            case 4:
                FastLED.addLeds<WS2812B, 4, GRB>(leds.data(), ledCount);
                break;
            case 5:
                FastLED.addLeds<WS2812B, 5, GRB>(leds.data(), ledCount);
                break;
            case 6:
                FastLED.addLeds<WS2812B, 6, GRB>(leds.data(), ledCount);
                break;
            case 7:
                FastLED.addLeds<WS2812B, 7, GRB>(leds.data(), ledCount);
                break;
            case 8:
                FastLED.addLeds<WS2812B, 8, GRB>(leds.data(), ledCount);
                break;
            case 9:
                FastLED.addLeds<WS2812B, 9, GRB>(leds.data(), ledCount);
                break;
            case 10:
                FastLED.addLeds<WS2812B, 10, GRB>(leds.data(), ledCount);
                break;
            case 11:
                FastLED.addLeds<WS2812B, 11, GRB>(leds.data(), ledCount);
                break;
            case 12:
                FastLED.addLeds<WS2812B, 12, GRB>(leds.data(), ledCount);
                break;
            case 13:
                FastLED.addLeds<WS2812B, 13, GRB>(leds.data(), ledCount);
                break;
#endif
            default:
                Serial.printf("Error: Unsupported pin %d\n", pin);
                return;
        }

        pinMode(pin, OUTPUT);
        FastLED.clear();
        FastLED.show();
    }

    void show(const std::vector<uint32_t> &frame) override {
        size_t n = std::min(frame.size(), leds.size());
        for (size_t i = 0; i < n; ++i) {
            uint32_t c = frame[i];
            leds[i] = CRGB((c >> 16) & 0xFF, (c >> 8) & 0xFF, c & 0xFF);
        }
        FastLED.show();
    }

    size_t getLedCount() override { return ledCount; }
};
