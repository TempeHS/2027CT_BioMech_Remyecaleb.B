#pragma once

#include "Arduino_SensorKit.h"

int BUTTON_PIN = 4;

bool holdingButton() {
  int timeSincePressed = millis();
  while (digitalRead(BUTTON_PIN)) {
    if (millis() - timeSincePressed >= 300){
      return true;
    }
  }
  return false;
}

void displayHeartrate(int heartRate) {
  Oled.clearLine(3);
  Oled.clearLine(4);
  Oled.clearLine(5);
  Oled.clearLine(6);

  Oled.setCursor(0, 1);
  Oled.print("HEART RATE:");

  char reading[12];
  snprintf(reading, sizeof(reading), "%d", heartRate);
  Oled.draw2x2String(6, 4, reading);
}
