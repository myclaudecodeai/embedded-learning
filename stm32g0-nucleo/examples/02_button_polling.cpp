// Lesson 2: GPIO input - read the onboard button (B1, active LOW on PC13)
#include <Arduino.h>

#define LED_PIN PA5
#define BUTTON_PIN PC13

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT); // Board already has an external pull-up resistor
}

void loop() {
  bool pressed = (digitalRead(BUTTON_PIN) == LOW);

  if (pressed) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
