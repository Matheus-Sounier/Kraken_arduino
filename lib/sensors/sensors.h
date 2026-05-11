#ifndef SENSORS_H
#define SENSORS_H

#include "Arduino.h"
#include "pins.h"

extern int previousError;

void sensorsSetup();   
int  errorRead();        
bool allWhite();    
bool allBlack();     

#endif