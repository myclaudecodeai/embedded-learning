// Lesson 8: SPI - read a register from a generic SPI device
#include <Arduino.h>
#include <SPI.h>

#define CS_PIN PA4 // Chip Select - pick any free GPIO pin, board-independent

void setup() {
  Serial.begin(115200);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH); // Idle state: NOT selected (active LOW like the button)

  SPI.begin();
}

byte readRegister(byte regAddress) {
  byte value;

  digitalWrite(CS_PIN, LOW);        // Select the device: "I'm talking to you now"
  SPI.transfer(regAddress);         // Send: which register do we want to read?
  value = SPI.transfer(0x00);       // Send a dummy byte, receive the actual reply
  digitalWrite(CS_PIN, HIGH);       // Deselect: "done talking to you"

  return value;
}

void loop() {
  byte result = readRegister(0x0F); // Example: many sensors use 0x0F as a "WHO_AM_I" ID register

  Serial.print("Register 0x0F value: 0x");
  Serial.println(result, HEX);

  delay(1000);
}
