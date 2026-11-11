#include "Arduino_SensorKit.h"

void displayTime(int years, int months, int days, int hours, int minutes, int seconds) {
  char timeText[9];
  snprintf(timeText, sizeof(timeText), "%02d:%02d:%02d",
          hours, minutes, seconds);

  char dateText[11];
  snprintf(dateText, sizeof(dateText), "%04d:%02d:%02d",
          years, months, days);

  Oled.setCursor(0, 1);
  Oled.print("Time:");

  Oled.draw2x2String(0, 3, timeText);
  Oled.setCursor(0, 5);
  Oled.print(dateText);
}
