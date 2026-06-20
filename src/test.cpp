#include <Arduino.h>

void setup() {
  pinMode(D1, OUTPUT);
}

void loop() {
   for (int i = 0; i <= 255; i++) {
    analogWrite(D1, i);
    delay (5);
   }
   for (int i = 255; i >= 0; i--) {
    analogWrite(D1, i);
    delay (5);
   }
}