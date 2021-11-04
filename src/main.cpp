#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial apc(6, 7); // RX, TX

void setup() {
  Serial.begin(9600);

  apc.begin(9600);
}

void loop() {
  if (apc.available()) {
    Serial.write(apc.read());
  }
}
