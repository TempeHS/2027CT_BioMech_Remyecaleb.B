#include <Wire.h>

void setup() {
  setupHeartmonitor();
}

void loop() {
  Serial.println(readHeartrate(), DEC);
  delay(500);
}

void setupHeartmonitor() {
  Serial.begin(115200);
  Serial.println("=======================================");
  Serial.println("heart rate sensor:");
  Wire.begin();
}

unsigned char readHeartrate() {
  Wire.requestFrom(0xA0 >> 1, 1);    // request 1 bytes from slave device
  while(Wire.available()) {          // slave may send less than requested
    unsigned char c = Wire.read();   // receive heart rate value (a byte)
    return c;         // print heart rate value
  }
  return 0;
}
