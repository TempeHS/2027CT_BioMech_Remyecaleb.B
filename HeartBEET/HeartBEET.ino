#include "lib/displayHeartrate.h"
#include "lib/readHeartrate.h"
#include "lib/buzz.h"

int maxHeartrate;
int minHeartrate;

void setup() {
  Serial.begin(115200);
  setupHeartmonitor(); // Start I2C before initializing the OLED.
  #if defined(WIRE_HAS_TIMEOUT)
    Wire.setWireTimeout(25000, true);
  #endif
  setupOled();

  maxHeartrate = 105;
  minHeartrate = 55;
}

void loop() {
  unsigned char heartRate = readHeartrate();

  if (heartRate > maxHeartrate || heartRate < minHeartrate) {
    buzz(5); // Pin D5
    Serial.println("Buzz");
  }
  Serial.println(heartRate);
  displayHeartrate(heartRate);

  delay(500);
}
