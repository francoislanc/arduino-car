
#include "constantes.h"
#include "motionDriver.h"
#include "ultrasoundDriver.h"
#include "servomotorDriver.h"
#include "switchDriver.h"

MotionDriver motionDriver(motor_front[0], motor_front[1], motor_back[0], motor_back[1], pin_potentiometer_robot_direction, pwm_motor);
UltrasoundDriver ultrasoundDriver(pin_ultrasound);
ServomotorDriver servomotorDriver(pin_servomotor);
SwitchDriver switchDriver(pin_switch_button);

void setup() {

  Serial.begin(9600);

  ultrasoundDriver.init();
  servomotorDriver.init();
  motionDriver.init();
  switchDriver.init();
}

void loop() {
  if (switchDriver.isOn() &&
      ultrasoundDriver.getValUltrason() < ULTRASOUND_THRESHOLD) {
    servomotorDriver.switch_orientation();
    motionDriver.turn_left();
    delay(DELAY_MOVE_MS);
    motionDriver.turn_right();
    delay(DELAY_MOVE_MS);
  }
  motionDriver.motor_stop();
  delay(DELAY_MOVE_MS);

}
