#include "ultrasoundDriver.h"

UltrasoundDriver::UltrasoundDriver(int pin_ultrasonic)
{
  pin_ultrason= pin_ultrasonic;
}

void UltrasoundDriver::init() {
}

int UltrasoundDriver::getValUltrason() {
  int val = 0;
  
  for (int i=0; i<10; i++) {
    val += analogRead(pin_ultrason);
    delay(10);
  }
  
  return val / 10;
}
