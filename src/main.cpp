#include <Arduino.h>
#include <Servo.h>

Servo servo;

int const SERVO_PIN = 9;
int const POTENTIMETER = A0;
int const MOVE_DELAY = 15;

void setup() {
  servo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  servo.write(map(analogRead(potentimeter), 0, 1023, 0, 179));
  delay(MOVE_DELAY);
}
