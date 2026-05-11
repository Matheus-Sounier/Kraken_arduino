#include "Arduino.h"
#include "engine.h"

void engineSetup () {
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT); 
  pinMode (IN2, OUTPUT); 
  pinMode (IN3, OUTPUT); 
  pinMode (IN4, OUTPUT);
}
void engineStop () {
  analogWrite (ENA, 0); 
  analogWrite (ENB, 0); 
  digitalWrite (IN1, LOW); 
  digitalWrite (IN2, LOW); 
  digitalWrite (IN3, LOW); 
  digitalWrite (IN4, LOW);
}

void engineMove (int leftSpeed, int rightSpeed) {
  leftSpeed = constrain(leftSpeed, -255, 255);
  rightSpeed = constrain(rightSpeed, -255, 255);

  if (leftSpeed >= 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    leftSpeed = -leftSpeed;
  }
  analogWrite(ENA, leftSpeed);

  if (rightSpeed >= 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    rightSpeed = -rightSpeed;
  }
  analogWrite(ENB, rightSpeed);
 
}