#ifndef ENGINE_H
#define ENGINE_H

#include "Arduino.h"
#include "pins.h"

void engineSetup();
void engineMove(int leftSpeed, int rightSpeed);
void engineStop();

#endif