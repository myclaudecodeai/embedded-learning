#include <Arduino.h>

#define LED_PIN PA5
#define BUTTON_PIN PC13

// 'volatile' tells the compiler this value can change at any time
// (from the ISR), so it must always re-read it from memory, never
// cache it in a register.
volatile bool ledState = false;

void onButtonPress() {
  // Kept SHORT and FAST on purpose: no Serial.print(), no delay()
  // inside an ISR - it must return quickly so normal code can resume.
  ledState = !ledState;
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  // Call onButtonPress() automatically whenever BUTTON_PIN goes from
  // HIGH to LOW (FALLING), i.e. the moment the button is pressed.
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButtonPress, FALLING);
}

void loop() {
  // main loop is completely free to do other work - it just reflects
  // whatever state the ISR last set.
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}
