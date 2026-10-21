#include <Wire.h>

unsigned char heartRate = 'a';

void setup() {
  setupHeartmonitor();
}

void loop() {
  readHeartrate();
  Serial.println(heartRate, DEC);
  delay(500);
}

void setupHeartmonitor() {
  Serial.begin(115200);
  Serial.println("=======================================");
  Serial.println("heart rate sensor:");
  Wire.begin();
}

void readHeartrate() {
  Serial.println("Enter");
  Wire.requestFrom(0xA0 >> 1, 1);    // request 1 bytes from slave device
  Serial.println("Wire requested");
  while(Wire.available()) {          // slave may send less than requested
    Serial.println("Wire Availbile");
    unsigned char c = Wire.read();
    Serial.println("Return C");   // receive heart rate value (a byte)
    heartRate = c;         // print heart rate value
  }
  Serial.println("Exit loop");
}
