#include "lib/displayHeartrate.h"
#include "lib/readHeartrate.h"
#include "lib/buzz.h"
#include "lib/displayTime.h"
#include "lib/time.h"

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
  rtc.set(2026, 11, 11, 23, 59, 40);   // y, m, d, h, min, s
}

void loop() {
  unsigned char heartRate = readHeartrate();

  if (heartRate > maxHeartrate || heartRate < minHeartrate) {
    buzz(5); // Pin D5
    Serial.println("Buzz");
  }
  Serial.println(heartRate);
  rtc.update();
  displayTime(rtc.year, rtc.month, rtc.day, rtc.hours, rtc.minutes, rtc.seconds);
  delay(500);
}
