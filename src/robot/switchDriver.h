#ifndef SwitchDriver_h
#define SwitchDriver_h

#include "Arduino.h"

class SwitchDriver
{
  public:
    SwitchDriver(int pin);
    int getVal();
    bool isOn();
    void init();

  private:
    int pin;
};

#endif
