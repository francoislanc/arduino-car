
#ifndef MotionDriver_h
#define MotionDriver_h


class MotionDriver
{
  public:
    MotionDriver(int front1, int front2, int back1, int back2, int pin_potentiometer, int pwm_motor);
    void init();
    void motor_stop();
    void slow_done(int initialSpeed, int finalSpeed);
    void drive_forward();
    void drive_backward();
    void center();
    void turn_right();
    void turn_left();
    int average_potar();
    void front_motor_stop();
    void set_speed(int pourcentage);
    int get_dir();
  private:
    int motor_front[2];
    int motor_back[2];
    int pwm;
    int pin_potentiometer;
    int dir;
};

#endif
