#include <Wire.h>

void setupHeartmonitor() {
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
