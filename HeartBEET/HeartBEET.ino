#include "displayHeartrate/displayHeartrate.h"
#include "readHeartrate/readHeartrate.h"
#include "buzz/buzz.h"

void setup() {
  Serial.begin(115200);
  setupHeartmonitor(); // Start I2C before initializing the OLED.
  #if defined(WIRE_HAS_TIMEOUT)
    Wire.setWireTimeout(25000, true);
  #endif
  Serial.println("I2C ready");
  setupOled();
  Serial.println("Setup complete");
}

void loop() {
  unsigned char heartRate = readHeartrate();

  Serial.println(heartRate);
  displayHeartrate(heartRate);

  delay(500);
}
