#include "Arduino_SensorKit.h"

#define Environment Environment_I2C

void setupOled() {
  Oled.begin();
  Oled.setFont(u8x8_font_chroma48medium8_r);
  Oled.setCursor(0, 5);
  Oled.println("OLED");
}

void displayHeartrate(int heartRate){
  Oled.setFont(u8x8_font_chroma48medium8_r);
  Oled.setCursor(0, 5);
  Oled.println(String(heartRate));
}
