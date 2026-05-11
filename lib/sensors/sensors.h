#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>
#include <pins.h>

extern int erroAnterior;

void sensorsSetup();   
int  lerErro();        
bool todosBranco();    
bool todosPreto();     

#endif