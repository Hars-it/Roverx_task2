//==================================================================================//

#include <CAN.h>
uint8_t i=0;
#define TX_GPIO_NUM   21 // Connects to CTX
#define RX_GPIO_NUM   22 // Connects to CRX

//==================================================================================//

void setup() {
  Serial.begin (115200);
  while (!Serial);
  delay (1000);

  Serial.println ("CAN Receiver/Receiver");

  // Set the pins
  CAN.setPins (RX_GPIO_NUM, TX_GPIO_NUM);

  // start the CAN bus at 500 kbps
  if (!CAN.begin (500E3)) {
    Serial.println ("Starting CAN failed!");
    while (1);
  }
  else {
    Serial.println ("CAN Initialized");
  }
}

//==================================================================================//

void loop() {
  // canSender();
  // i++;
  canReceiver();
}

//==================================================================================//

void canSender() {
  // send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print ("Sending packet ... ");

  CAN.beginPacket (0x14);  //sets the ID and clears the transmit buffer
  // CAN.beginExtendedPacket(0xabcdef);

  CAN.write (2+i);
  CAN.write (3+i);
  CAN.write (4+i);
  CAN.write (5+i);
  CAN.write (6+i);
  CAN.write (7+i);
  CAN.write (8+i);
  CAN.write (9+i); //write data to buffer. data is not sent until endPacket() is called.
  CAN.endPacket();

  //RTR packet with a requested data length
  // CAN.beginPacket (0x12, 3, true);
  // CAN.endPacket();

  Serial.println ("done");

  delay (1000);
}

//==================================================================================//

void canReceiver() {
  // try to parse packet
  int packetSize = CAN.parsePacket();

  if (packetSize) {
    // received a packet
    Serial.print ("Received ");

    if (CAN.packetExtended()) {
      Serial.print ("extended ");
    }

    if (CAN.packetRtr()) {
      // Remote transmission request, packet contains no data
      Serial.print ("RTR ");
    }

    Serial.print ("packet with id 0x");
    Serial.print (CAN.packetId(), HEX);

    if (CAN.packetRtr()) {
      Serial.print (" and requested length ");
      Serial.println (CAN.packetDlc());
    } else {
      Serial.print (" and length ");
      Serial.println (packetSize);

      // only print packet data for non-RTR packets
      while (CAN.available()) {
        Serial.print (CAN.read());
        Serial.print(" ");
      }
      Serial.println();
    }

    Serial.println();
  }
}