// Lesson 6: Interrupts - toggle the LED on button press without polling
#include <Arduino.h>

#define LED_PIN PA5
#define BUTTON_PIN PC13

// 'volatile' tells the compiler this value can change at any time
// (from the ISR), so it must always re-read it from memory.
volatile bool ledState = false;

void onButtonPress() {
  // Keep ISRs short and fast: no Serial.print(), no delay() here.
  ledState = !ledState;
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButtonPress, FALLING);
}

void loop() {
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}
