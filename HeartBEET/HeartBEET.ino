#include "Arduino_SensorKit.h"
#include "displayHeartrate/displayHeartrate.h"
#include "readHeartrate/readHeartrate.h"
#include "buzz/buzz.h"

void setup() {
  setupOled();
  Serial.begin(115200);
  setupHeartmonitor();
}

void loop() {
  if (readHeartrate() > 5) {
    buzz(5);
  }
  delay(500);
}
