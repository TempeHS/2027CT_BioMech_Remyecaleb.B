// Grove Buzzer on D5 (PWM)

void setupBuzzer() {
  Serial.begin(115200);
}

void buzz(int BUZZER_PIN) {
  tone(BUZZER_PIN, 700);
  delay(300);
  noTone(BUZZER_PIN);
}
