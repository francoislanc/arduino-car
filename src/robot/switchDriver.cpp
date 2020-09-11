#include "switchDriver.h"

SwitchDriver::SwitchDriver(int pinNumber)
{
  pin = pinNumber;
  pinMode(pinNumber, INPUT);
}

void SwitchDriver::init() {
}

bool SwitchDriver::isOn() {
  return getVal() == 1;
}

int SwitchDriver::getVal() {
  return digitalRead(pin);
}
