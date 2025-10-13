/*******************************************************
  NeoRing Timer-Based Demo
  Demonstrates non-blocking animation switching using update().
  https://github.com/madhukartemba/NeoRing
*******************************************************/

#include <NeoRing.h>

// -------------------- Configuration --------------------
#define LED_PIN     6               // Pin where the LED ring is connected
#define LED_COUNT   30              // Number of LEDs in the ring
#define DRIVER      DisplayDriver::NEOPIXEL
#define FPS         60.0                // Frames per second (default 60)
#define ANIM_DELAY  3000               // Time to show each animation (ms)

// -------------------- Create NeoRing instance --------------------
NeoRing ring;

// Track time for animation switching
unsigned long lastSwitch = 0;
int currentAnim = 0;

void setup() {
  // Initialize the ring
  ring.begin(LED_COUNT, LED_PIN, DRIVER);
  
  // Optional: Set custom FPS
  ring.setFPS(FPS);

  // Start with a solid green color and finish transition
  ring.solid(0x00FF00); // Green

  // Blocking update which waits until the transition completes
  ring.finishTransition();

}

void loop() {
  // Call update() frequently to drive animations
  ring.update();

  // Non-blocking animation switch
  unsigned long now = millis();
  if (now - lastSwitch >= ANIM_DELAY) {
    lastSwitch = now;
    currentAnim = (currentAnim + 1) % 6; // Cycle through 6 animations

    switch (currentAnim) {
      case 0:
        ring.solid(0x00FF00); // Green
        break;
      case 1:
        ring.rainbow(1.0f);
        break;
      case 2:
        ring.breathe(0x0000FF, 0.2f, 1.0f); // Blue
        break;
      case 3:
        ring.wave(0xFFFF00, 8.0f); // Yellow
        break;
      case 4:
        ring.spinner(5, 0xFF00FF, 1.5f); // Magenta
        break;
      case 5:
        ring.blink(0xFFFFFF, 3); // White
        break;
    }
  }
}
