#pragma once

#include "Arduino_SensorKit.h"

int BUTTON_PIN = 4;

bool holdingButton() {
  unsigned long pressedAt = millis();
  while (digitalRead(BUTTON_PIN)) {
    if (millis() - pressedAt >= 300) {
      return true;
    }
  }
  return false;
}

void displayHeartrate(int heartRate, bool forceRedraw = false) {
  static int lastHeartRate = -1;
  static unsigned long lastDraw = 0;

  if (forceRedraw) {
    Oled.clear();
    Oled.setCursor(0, 1);
    Oled.print("HEART RATE:");
    lastHeartRate = -1;
  }

  if (heartRate == lastHeartRate || millis() - lastDraw < 250) {
    return;
  }
  lastHeartRate = heartRate;
  lastDraw = millis();

  char reading[12];
  snprintf(reading, sizeof(reading), "%-3d", heartRate);
  Oled.draw2x2String(6, 4, reading);
}
