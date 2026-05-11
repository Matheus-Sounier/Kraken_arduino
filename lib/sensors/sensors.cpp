// sensors.cpp
#include "Arduino.h"
#include "sensors.h"

int previousError = 0;

void sensorsSetup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
}

bool allWhite() {
  return (
      digitalRead(S1) &&
      digitalRead(S2) &&
      digitalRead(S3) &&
      digitalRead(S4) &&
      digitalRead(S5)
    );
}

bool allBlack() {
  return (
      !digitalRead(S1) &&
      !digitalRead(S2) && 
      !digitalRead(S3) && 
      !digitalRead(S4) && 
      !digitalRead(S5)
    );
}

// Pegadinhas
int errorRead() {
  if (allBlack()) return 0;
  if (allWhite()) return previousError;

  
  int s1 = !digitalRead(S1);
  int s2 = !digitalRead(S2);
  int s3 = !digitalRead(S3);
  int s4 = !digitalRead(S4);
  int s5 = !digitalRead(S5);

  int activeSensors = s1 + s2 + s3 + s4 + s5;

  // Só mexe se entende de média ponderada, plis
  if (activeSensors == 0) return previousError;
  int weightedSum =
      (-2 * s1) +
      (-1 * s2) +
      ( 0 * s3) +
      ( 1 * s4) +
      ( 2 * s5);
  int error = weightedSum / activeSensors;

  previousError = error;
  return error;

}