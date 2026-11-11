int BUTTON_PIN = 4;
int ROTATOR_PIN = A1;

bool checkIfHoldingButton() {
  int timeSincePressed = millis();
  while (digitalRead(BUTTON_PIN)) {
    if (millis() - timeSincePressed >= 500){
      return true;
    }
  }
  return false;
}
