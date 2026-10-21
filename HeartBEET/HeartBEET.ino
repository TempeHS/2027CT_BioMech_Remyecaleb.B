#include "Arduino_SensorKit.h"
#include "displayHeartrate/displayHeartrate.h"
#include "readHeartrate/readHeartrate.h"

void setup() {
  // setupOled();
  Serial.begin(115200);
  setupHeartmonitor();
}

void loop() {
  Serial.println(readHeartrate(), DEC);
  delay(500);
}
