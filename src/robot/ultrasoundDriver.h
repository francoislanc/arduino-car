#ifndef UltrasoundDriver_h
#define UltrasoundDriver_h

#include "Arduino.h"

class UltrasoundDriver
{
  public:
    UltrasoundDriver(int pin_ultrasonic);
    int getValUltrason();
    void init();

  private:
    int val_ultrason;
    int pin_ultrason;
};

#endif
