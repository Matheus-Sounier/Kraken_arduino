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
