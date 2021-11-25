#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial apc(10, 11); // RX, TX

int stopBytes = 0;

void setup() {
  Serial.begin(9600);

  apc.begin(9600);
  Serial.println("CANsat Ground Station Ready!");
}

void loop() {
  if (apc.available()) {
    Serial.write(apc.read());
  }

  if (Serial.available()) {
    stopBytes = Serial.read();
    apc.write(stopBytes);
    Serial.write(stopBytes);
  }
}


// IF USING ARDUINO DUE:
// void setup() {
//   Serial.begin(9600);
//   Serial2.begin(9600);

// }

// void loop() {
//   if (Serial2.available()) {
//     Serial.write(Serial2.read());
//   }

//   if (Serial.available()) {
//     Serial2.write(Serial.read());
//   }
  
// }