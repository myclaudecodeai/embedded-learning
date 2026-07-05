// Lesson 7: I2C - scan the bus and report any connected device addresses
#include <Arduino.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(); // Join the I2C bus as the "controller" (master)
  Serial.println("I2C scanner starting...");
}

void loop() {
  int devicesFound = 0;

  for (byte address = 1; address < 127; address++) {
    // beginTransmission/endTransmission attempts to talk to 'address'.
    // endTransmission() returns 0 only if a device actually acknowledged it.
    Wire.beginTransmission(address);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device found at address 0x");
      Serial.println(address, HEX);
      devicesFound++;
    }
  }

  if (devicesFound == 0) {
    Serial.println("No I2C devices found.");
  }

  delay(3000); // Re-scan every 3 seconds
}
