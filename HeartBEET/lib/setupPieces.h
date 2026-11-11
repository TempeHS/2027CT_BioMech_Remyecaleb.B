#pragma once

#include "Arduino_SensorKit.h"
#include <Wire.h>

void setupOled() {
  Serial.println("Setting Up OLED...");
  Serial.flush();

  Oled.begin();

  Serial.println("OLED begun");
  Oled.setFont(u8x8_font_chroma48medium8_r);
  Oled.setCursor(0, 5);
  Oled.print("OLED ready");
}

void setupHeartmonitor() {
  Wire.begin();
}

void setupPieces() {
  setupHeartmonitor();
  setupOled();
}
