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

int lerErro() {
  if (todosPreto())  return 0;
  if (todosBranco()) return erroAnterior;

  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);

  int erro = 0;

  if (!s3 &&  s1 &&  s2 &&  s4 &&  s5) erro =  0;
  if (!s2 &&  s1 &&  s3 &&  s4 &&  s5) erro = -1;
  if (!s1 &&  s2 &&  s3 &&  s4 &&  s5) erro = -2;
  if (!s4 &&  s1 &&  s2 &&  s3 &&  s5) erro = +1;
  if (!s5 &&  s1 &&  s2 &&  s3 &&  s4) erro = +2;

  erroAnterior = erro;
  return erro;

}