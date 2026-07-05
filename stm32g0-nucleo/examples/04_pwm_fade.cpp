// Lesson 4: Timers & PWM - fade the LED brightness up and down
#include <Arduino.h>

#define LED_PIN PA5

void setup() {
  // No pinMode() needed for analogWrite() - it configures the pin
  // internally to route it to a hardware timer channel.
}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(LED_PIN, brightness);
    delay(5);
  }

  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(LED_PIN, brightness);
    delay(5);
  }
}
