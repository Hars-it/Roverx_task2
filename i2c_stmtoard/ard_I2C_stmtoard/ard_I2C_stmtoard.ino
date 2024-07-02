#include <Wire.h>

int ledPin = 13;
uint8_t data[6];

void setup() {
  pinMode(ledPin, OUTPUT);
  Wire.begin(0x04); 
  Wire.onReceive(receiveEvent);
  Serial.begin(9600); 
}

void loop() {
  
}

void receiveEvent(int howMany) {
  for (int i = 0; i < howMany; i++) {
    if (i < sizeof(data)) {
      data[i] = Wire.read();
    } 
    else {
      Wire.read(); 
    }
  }
  int blinkCount = data[0]; 
  Serial.print("Data received: ");
  for (int i = 0; i < howMany; i++) {
    Serial.print(data[i]);
    Serial.print(" ");
  }
  Serial.println();
//   blinkLED(blinkCount);
//}

// void blinkLED(int count) {
//   for (int i = 0; i < count; i++) {
//     digitalWrite(ledPin, HIGH);
//     delay(500);
//     digitalWrite(ledPin, LOW);
//     delay(500);
  // }
}
