#include "lib/displayHeartrate.h"
#include "lib/readHeartrate.h"
#include "lib/buzz.h"
#include "lib/displayTime.h"
#include "lib/time.h"
#include "lib/setupPieces.h"

int maxHeartrate;
int minHeartrate;

void setup() {
  Serial.begin(115200);
  setupPieces();

  #if defined(WIRE_HAS_TIMEOUT)
    Wire.setWireTimeout(25000, true);
  #endif

  maxHeartrate = 105;
  minHeartrate = 55;
  rtc.set(2026, 11, 11, 23, 59, 40);   // y, m, d, h, min, s
}

void loop() {
  unsigned char heartRate = readHeartrate();
  rtc.update();

  if (heartRate > maxHeartrate || heartRate < minHeartrate) {
    buzz(5); // Pin D5
    Serial.println("Buzz");
  }
  Serial.println(heartRate);
  while (holdingButton()) {
    displayHeartrate(readHeartrate());
  }
  displayTime(rtc.year, rtc.month, rtc.day, rtc.hours, rtc.minutes, rtc.seconds);
  delay(500);
}
