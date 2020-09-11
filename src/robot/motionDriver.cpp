#include "Arduino.h"
#include "motionDriver.h"

MotionDriver::MotionDriver(int front1, int front2, int back1, int back2, int pin_pot, int pwm_motor)
{
  motor_front[0] = front1;
  motor_front[1] = front2;
  motor_back[0] = back1;
  motor_back[1] = back2;
  pin_potentiometer = pin_pot;
  pwm = pwm_motor;

  pinMode(front1, OUTPUT);
  pinMode(front2, OUTPUT);
  pinMode(back1, OUTPUT);
  pinMode(back2, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void MotionDriver::init()
{
  motor_stop();
  set_speed(95);
}

void MotionDriver::set_speed(int pourcentage)
{
  analogWrite(pwm, 255 * pourcentage / 100);
}

int MotionDriver::get_dir()
{
  return dir;
}

void MotionDriver::motor_stop()
{
  digitalWrite(motor_front[0], LOW);
  digitalWrite(motor_front[1], LOW);

  digitalWrite(motor_back[0], LOW);
  digitalWrite(motor_back[1], LOW);

  delay(25);
}

void MotionDriver::slow_done(int initial_speed, int final_speed)
{
  int val = initial_speed;
  while (val > final_speed) {
    if (val + 10 > final_speed) {
      val = val - 10;
      set_speed(val);
    } else {
      val = final_speed;
      set_speed(val);
    }
    delay(150);
  }
}

void MotionDriver::drive_forward()
{
  digitalWrite(motor_back[0], LOW);
  digitalWrite(motor_back[1], HIGH);
  delay(50);
}

void MotionDriver::drive_backward()
{
  digitalWrite(motor_back[0], HIGH);
  digitalWrite(motor_back[1], LOW);
  delay(50);
}

void MotionDriver::center() {

  int val = average_potar();    // read the value from the sensor
  while (val > 430 || val < 400) {
    if (val > 420) {
      digitalWrite(motor_front[0], LOW);
      digitalWrite(motor_front[1], HIGH);
    } else {
      digitalWrite(motor_front[0], HIGH);
      digitalWrite(motor_front[1], LOW);
    }
    delay(20);
    front_motor_stop();
    val = average_potar();
  }
  dir = 1;

}

int MotionDriver::average_potar() {
  int temp_val = 0;

  for (int i = 0; i < 5; i++) {
    temp_val += analogRead(pin_potentiometer);
    delay(10);
  }

  return temp_val / 5;

}

void MotionDriver::turn_left() {

  int val = average_potar();    // read the value from the sensor

  while (val < 470) {
    digitalWrite(motor_front[0], HIGH);
    digitalWrite(motor_front[1], LOW);
    delay(20);
    front_motor_stop();
    val = average_potar();
  }
  dir = 0;
}

void MotionDriver::turn_right() {

  int val = average_potar();    // read the value from the sensor

  while (val > 320) {
    digitalWrite(motor_front[0], LOW);
    digitalWrite(motor_front[1], HIGH);
    delay(20);
    front_motor_stop();
    val = average_potar();
  }
  dir = 2;
}

void MotionDriver::front_motor_stop() {
  digitalWrite(motor_front[0], LOW);
  digitalWrite(motor_front[1], LOW);
  delay(20);
}
