#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(); 
  Serial.begin(9600);
  Serial.println("I2C Master ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t dataToSend[4] = {2, 5, 6, 3}; 

  Wire.beginTransmission(0x12); 
  Wire.write(dataToSend, 4); 
  Wire.endTransmission(); 
  delay(1000); 
}

