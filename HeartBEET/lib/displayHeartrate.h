#pragma once

#include "Arduino_SensorKit.h"

void setupOled() {
  Serial.println("Setting Up OLED...");
  Serial.flush();

  Oled.begin();

  Serial.println("OLED begun");
  Oled.setFont(u8x8_font_chroma48medium8_r);
  Oled.setCursor(0, 5);
  Oled.print("OLED ready");
}

void displayHeartrate(int heartRate) {
  Oled.clearLine(4);
  Oled.clearLine(5);
  Oled.clearLine(6);

  Oled.setCursor(0, 1);
  Oled.print("HEART RATE:");

  char reading[12];
  snprintf(reading, sizeof(reading), "%d", heartRate);
  Oled.draw2x2String(6, 4, reading);
}
