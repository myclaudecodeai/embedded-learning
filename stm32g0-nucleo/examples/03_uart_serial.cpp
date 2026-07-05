// Lesson 3: UART/Serial - print button state changes over USB serial
#include <Arduino.h>

#define LED_PIN PA5
#define BUTTON_PIN PC13

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  Serial.begin(115200);
  Serial.println("Board booted up. Waiting for button presses...");
}

void loop() {
  static bool lastPressed = false;
  bool pressed = (digitalRead(BUTTON_PIN) == LOW);

  digitalWrite(LED_PIN, pressed ? HIGH : LOW);

  if (pressed != lastPressed) {
    if (pressed) {
      Serial.println("Button PRESSED");
    } else {
      Serial.println("Button RELEASED");
    }
    lastPressed = pressed;
  }
}
