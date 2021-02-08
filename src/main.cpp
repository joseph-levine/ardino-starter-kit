#include <Arduino.h>

#ifndef PIEZO_PIN
#define PIEZO_PIN 8
#endif

const int notes[4] = {262, 294, 330, 349};
void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(A0);
  if (keyVal == 1023) {
    tone(PIEZO_PIN, notes[0]);
  } else if (keyVal >= 990 && keyVal <= 1010) {
    tone(PIEZO_PIN, notes[1]);
  } else if (keyVal >= 505 && keyVal < 515) {
    tone(PIEZO_PIN, notes[2]);
  } else if (keyVal >= 5 && keyVal <= 10) {
    tone(PIEZO_PIN, notes[3]);
  } else {
    noTone(PIEZO_PIN);
  }
}
