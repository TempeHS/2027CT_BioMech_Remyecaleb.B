
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

// ...existing code...

void displayTime(int hours, int minutes, int seconds) {
  char timeText[9];
  snprintf(timeText, sizeof(timeText), "%02d:%02d:%02d",
          hours, minutes, seconds);

  Oled.setCursor(0, 1);
  Oled.print("Time:");

  Oled.draw2x2String(0, 4, timeText);
}
