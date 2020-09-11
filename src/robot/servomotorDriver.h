#ifndef ServomotorDriver_h
#define ServomotorDriver_h

#include <Servo.h>
#include "Arduino.h"

class ServomotorDriver
{
  public:
    ServomotorDriver(int pinservo);
    void front();
    void back();
    void switch_orientation();
    int getAngle();
    void init();

  private:
    Servo servo;
    int angle_servo;
    int pin_servo;
};

#endif
