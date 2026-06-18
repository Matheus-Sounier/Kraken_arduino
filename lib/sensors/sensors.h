#ifndef SENSORS_H
#define SENSORS_H

#include "Arduino.h"
#include "pins.h"

extern float previousError;

void sensorsSetup();

float errorRead();
float getLastError();

bool allWhite();
bool allBlack();

#endif