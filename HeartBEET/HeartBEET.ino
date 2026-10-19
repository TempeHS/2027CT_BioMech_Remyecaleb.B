#include "Arduino_SensorKit.h"
#include "displayHeartrate/displayHeartrate.h"
#include "readHeartrate/readHeartrate.h"

void setup() {
  setupOled();
  setupHeartmonitor();
}

void loop() {
  readHeartrate();
}
