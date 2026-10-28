  // Grove Buzzer on D5 (PWM)

void setupBuzzer() {
  Serial.begin(115200);
}

void buzz(int BUZZER_PIN) {
  digitalWrite(BUZZER_PIN, HIGH);
}
