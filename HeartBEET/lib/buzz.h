// Grove Buzzer on D5 (PWM)

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
