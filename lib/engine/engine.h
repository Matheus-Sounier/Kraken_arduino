#ifndef ENGINE_H
#define ENGINE_H

#include "Arduino.h"
#include "pins.h"

void engineSetup();
void moveEngine(int leftSpeed, int rightSpeed);