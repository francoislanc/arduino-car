#include "ServomotorDriver.h"

ServomotorDriver::ServomotorDriver(int pinservo)
{
  pin_servo = pinservo;
}

void ServomotorDriver::init() {
  servo.attach(pin_servo);
  front();
}

void ServomotorDriver::front() {
  servo.write(0);
  angle_servo = 0;
}

void ServomotorDriver::back() {
  servo.write(180);
  angle_servo = 180;
}

void ServomotorDriver::switch_orientation() {
  if (angle_servo == 180) {
    front();
  } else if (angle_servo == 0) {
    back();
  }
}

int ServomotorDriver::getAngle() {
  return servo.read();
}
