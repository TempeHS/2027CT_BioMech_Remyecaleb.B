#include <TimeLib.h>

char date_buffer[] = "YYYY-MM-DD";
char time_buffer[] = "HH:MM:SS";

void setup() {
  Serial.begin(115200);
  while (!Serial); // Wait for the serial monitor to open (mainly for native USB boards)
}

void loop() {
  Serial.println(second());

  delay(1000); // Check time once per second
}
