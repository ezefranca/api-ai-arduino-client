/*
  APIAIArduino.h - Library for flashing APIAIArduino code.
  Created by Ezequiel Franca, May 9, 2017.
  Released into the public domain.
*/

#ifndef APIAIArduino_h
#define APIAIArduino_h

#include "Arduino.h"

class APIAIArduino
{
  public:
    APIAIArduino(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};

#endif

