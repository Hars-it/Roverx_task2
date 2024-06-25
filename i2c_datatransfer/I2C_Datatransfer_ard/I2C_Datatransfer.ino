#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(); // Join the I2C bus as master
  Serial.begin(9600); // Start serial communication at 9600 baud
  while (!Serial); // Wait for serial port to connect
  Serial.println("I2C Master ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t dataToSend[6] = {1, 2, 3, 4, 5, 6}; // 4 bytes of data to send

  Wire.beginTransmission(0x12); // Address of the STM32 I2C slave
  Wire.write(dataToSend, 6); // Send 4 bytes of data to the STM32
  Wire.endTransmission(); // End transmission

  delay(1000); // Wait for a second before repeating
}
