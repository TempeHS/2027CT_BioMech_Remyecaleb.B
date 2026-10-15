#include "Arduino_SensorKit.h"
#include "displayHeartrate/displayHeartrate.h"

void setup() {
  setupOled();
}

void loop() {
  displayHeartrate(65);
}
