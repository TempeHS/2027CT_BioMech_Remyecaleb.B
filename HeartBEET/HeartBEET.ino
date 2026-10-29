#include "displayHeartrate/displayHeartrate.h"
#include "readHeartrate/readHeartrate.h"
#include "buzz/buzz.h"

void setup() {
  button_setup()
  
  
  
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
  get_button_data()
  unsigned char heartRate = readHeartrate();

  if (heartRate > 5) {
    buzz(5); // Pin D5
    Serial.println("Should Buzz");
  }

  Serial.println(heartRate);
  displayHeartrate(heartRate);

  delay(500);
}
