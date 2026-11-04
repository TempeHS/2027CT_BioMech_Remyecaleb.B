int seconds = 50;
int minutes = 59;
int hours = 0;
int days = 0;


void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Date: ");
  Serial.print(days);
  Serial.print("  hours: ");
  Serial.print(hours);
  Serial.print("  minutes: ");
  Serial.print(minutes);
  Serial.print("  seconds: ");
  Serial.println(seconds);

  seconds = seconds + 1;

  if (seconds == 60) {
    seconds = 0;
    minutes = minutes + 1;
  }

  if (minutes == 60) {
    minutes = 0;
    hours = hours + 1;
  }

  if (hours == 24) {
    hours = 0;
    days = days + 1;
  }

  delay(1000);
}
