#pragma once

#include <Wire.h>

void setupHeartmonitor() {
  Wire.begin();
}

unsigned char readHeartrate() {
  Wire.requestFrom(0xA0 >> 1, 1);

  if (Wire.available()) {
    return Wire.read();
  }

  return 0; // No reading received.
}
