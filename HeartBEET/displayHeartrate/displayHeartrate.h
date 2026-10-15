#include "Arduino_SensorKit.h"

#define Environment Environment_I2C

void setupOled() {
  Oled.begin();
}

void displayHeartrate(int heartRate){
  Oled.setFont(u8x8_font_chroma48medium8_r);
  Oled.setCursor(0, 33);
  Oled.print(String(heartRate));
}
