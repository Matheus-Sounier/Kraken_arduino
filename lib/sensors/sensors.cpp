// sensors.cpp
#include <Arduino.h>
#include <sensors.h>

int erroAnterior = 0;

void sensorsSetup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
}

bool todosBranco() {
  return (digitalRead(S1) && digitalRead(S2) && digitalRead(S3)
       && digitalRead(S4) && digitalRead(S5));
}

bool todosPreto() {
  return (!digitalRead(S1) && !digitalRead(S2) && !digitalRead(S3)
       && !digitalRead(S4) && !digitalRead(S5));
}