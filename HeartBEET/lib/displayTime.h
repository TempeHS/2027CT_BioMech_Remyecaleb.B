#include "Arduino_SensorKit.h"

void displayTime(int hours, int minutes, int seconds) {
  char timeText[9];
  snprintf(timeText, sizeof(timeText), "%02d:%02d:%02d",
          hours, minutes, seconds);

  Oled.setCursor(0, 1);
  Oled.print("Time:");

  Oled.draw2x2String(0, 4, timeText);
}
