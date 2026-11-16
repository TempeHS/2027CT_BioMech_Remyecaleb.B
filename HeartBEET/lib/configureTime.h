#pragma once

#include "Arduino_SensorKit.h"
#include "time.h"

const int ROTATOR_PIN = A1;
const int TIME_BUTTON_PIN = 4;
const int TIME_FIELD_COUNT = 6;
const unsigned long BUTTON_DEBOUNCE_MS = 30;

int currentNumber = 0;

void changeSelectedNumber() {
  static bool lastReading = false;
  static bool stablePressed = false;
  static unsigned long changedAt = 0;

  bool pressed = digitalRead(TIME_BUTTON_PIN) == HIGH;
  unsigned long now = millis();

  if (pressed != lastReading) {
    changedAt = now;
    lastReading = pressed;
  }

  if (now - changedAt < BUTTON_DEBOUNCE_MS) {
    return;
  }

  if (pressed != stablePressed) {
    stablePressed = pressed;

    if (stablePressed) {
      currentNumber = (currentNumber + 1) % TIME_FIELD_COUNT;
    }
  }
}

void highlightSelectedNumber() {
  if (currentNumber < 0 || currentNumber >= TIME_FIELD_COUNT) {
    Serial.println("Invalid time field");
    return;
  }

  // Seconds, minutes, hours, day, month, year.
  const int columns[] = {12, 6, 0, 8, 5, 0};
  const int rows[] = {2, 2, 2, 6, 6, 6};

  Oled.clearLine(2);
  Oled.clearLine(6);

  Oled.setCursor(columns[currentNumber], rows[currentNumber]);
  Oled.print('*');
}
