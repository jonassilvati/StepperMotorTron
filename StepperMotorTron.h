#include "Arduino.h"

#ifndef StepperMotorTron_h
#define StepperMotorTron_h

class StepperMotorTron{
  private:
    int port_1;
    int port_2;
    int port_3;
    int port_4;
    int delay_phase = 2;
    int delay_step = 10;
    void makeMotorStep(int positionStep);
    void stopMotor();
    void doStep();
    void doStepBack();

  public:
    StepperMotorTron(int port_1, int port_2, int port_3, int port_4);
    void start();
    void go(int steps);
    void back(int steps);
    
};
#endif
