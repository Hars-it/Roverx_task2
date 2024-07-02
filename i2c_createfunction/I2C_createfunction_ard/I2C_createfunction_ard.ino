#include <Wire.h>

uint8_t datatoSend[] = {1,2,3,4,5};

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x08);
  Wire.write(datatoSend, sizeof(datatoSend));
  Wire.endTransmission();

  delay(1000);
}
