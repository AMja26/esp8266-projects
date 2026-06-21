#include <Arduino.h>

  int lastbuttonState = HIGH;
  int phase = 0;
  unsigned long lastpressTime;

void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, INPUT);
}

void loop() {
  bool buttonState = digitalRead(D3);

  if (buttonState != lastbuttonState && millis() - lastpressTime > 50) {
    if (buttonState == LOW) {
      phase = (phase + 1)%3;
      lastpressTime = millis();
    }
  }
  lastbuttonState = buttonState;
    
  if (phase == 0){
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);
    }
  else if (phase == 1){
      digitalWrite(D1, HIGH);
      digitalWrite(D2, LOW);
    }
  else if (phase == 2){
      digitalWrite(D1, LOW);
      digitalWrite(D2, HIGH);
    }
}