// Grove Buzzer on D5 (PWM)

void buzz(int BUZZER_PIN) {
  tone(BUZZER_PIN, 700);
  delay(300);
  noTone(BUZZER_PIN);
}

void no_buzz(int BUZZ_NOW) {
  tone(BUZZ_NOW, 700);
delay (355);
noTone(BUZZ_NOW);
}
