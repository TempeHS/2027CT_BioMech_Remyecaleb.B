// Grove Buzzer on D5 (PWM)
int maxHeartrate;
int minHeartrate;

void buzz1(int BUZZER_PIN) {
  tone(BUZZER_PIN, 700);
  delay(300);
  noTone(BUZZER_PIN);
}

void buzz2(int BUZZ_NOW) {
  tone(BUZZ_NOW, 700);
  delay(300);
  noTone(BUZZ_NOW);
  delay(300);
}

void buzzing(int BUZZ_NOW, int heartRate, int minHeartrate, int maxHeartrate, int buzzerPin) {
    if (heartRate > maxHeartrate || heartRate < minHeartrate) {
    buzz1(5); // Pin D5
    Serial.println("Buzz1");
  }
  Serial.println(heartRate);
}
