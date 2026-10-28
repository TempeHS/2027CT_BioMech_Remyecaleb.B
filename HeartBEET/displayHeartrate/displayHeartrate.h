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
  Oled.setCursor(0, 5);
  Oled.print("                "); // Clear the previous reading.
  Oled.setCursor(0, 5);
  Oled.print(heartRate);
}
