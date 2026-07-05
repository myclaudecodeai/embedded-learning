// Lesson 5: ADC - read a potentiometer on A0 and print raw value + voltage
#include <Arduino.h>

#define POT_PIN A0

void setup() {
  Serial.begin(115200);
}

void loop() {
  int raw = analogRead(POT_PIN);           // 0 - 1023 (10-bit resolution by default)
  float voltage = (raw / 1023.0) * 3.3;    // Board runs at 3.3V

  Serial.print("Raw ADC: ");
  Serial.print(raw);
  Serial.print("  Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(200);
}
