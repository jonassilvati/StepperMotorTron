#include "Arduino.h"
#include "StepperMotorTron.h"

StepperMotorTron::StepperMotorTron(int port_1, int port_2, int port_3, int port_4){
  this->port_1 = port_1;
  this->port_2 = port_2;
  this->port_3 = port_3;
  this->port_4 = port_4;
}

void StepperMotorTron::start(){
  pinMode(this->port_1,OUTPUT);
  pinMode(this->port_2,OUTPUT);
  pinMode(this->port_3,OUTPUT);
  pinMode(this->port_4,OUTPUT);
}

void StepperMotorTron::go(int steps){
  for(int i=0;i<steps;i++){
    doStep();
    delay(this->delay_step);
  } 
  stopMotor();
}

void StepperMotorTron::back(int steps){
  for(int i=0;i<steps;i++){
    doStepBack();
    delay(this->delay_step);
  }
  stopMotor();
}

void StepperMotorTron::stopMotor(){
  digitalWrite(this->port_1,LOW);
  digitalWrite(this->port_2,LOW);
  digitalWrite(this->port_3,LOW);
  digitalWrite(this->port_4,LOW);
}

void StepperMotorTron::doStep(){
  for(int j=0;j<=7;j++){
    makeMotorStep(j);
    delay(this->delay_phase);
  }
}

void StepperMotorTron::doStepBack(){
  for(int j=7;j>=0;j--){
    makeMotorStep(j);
    delay(this->delay_phase);
  } 
}

void StepperMotorTron::makeMotorStep(int positionStep){
  switch(positionStep){
    case 0://0001
      digitalWrite(this->port_1,1);
      digitalWrite(this->port_2,0);
      digitalWrite(this->port_3,0);
      digitalWrite(this->port_4,0);
      break;
    case 1://0011
      digitalWrite(this->port_1,1);
      digitalWrite(this->port_2,1);
      digitalWrite(this->port_3,0);
      digitalWrite(this->port_4,0);
      break;
    case 2://0010
      digitalWrite(this->port_1,0);
      digitalWrite(this->port_2,1);
      digitalWrite(this->port_3,0);
      digitalWrite(this->port_4,0);
      break;
    case 3://0110
      digitalWrite(this->port_1,0);
      digitalWrite(this->port_2,1);
      digitalWrite(this->port_3,1);
      digitalWrite(this->port_4,0);
      break;
    case 4://0100
      digitalWrite(this->port_1,0);
      digitalWrite(this->port_2,0);
      digitalWrite(this->port_3,1);
      digitalWrite(this->port_4,0);
      break;
    case 5://1100
      digitalWrite(this->port_1,0);
      digitalWrite(this->port_2,0);
      digitalWrite(this->port_3,1);
      digitalWrite(this->port_4,1);
      break;
    case 6://1000
      digitalWrite(this->port_1,0);
      digitalWrite(this->port_2,0);
      digitalWrite(this->port_3,0);
      digitalWrite(this->port_4,1);
      break;
    case 7://1001
      digitalWrite(this->port_1,1);
      digitalWrite(this->port_2,0);
      digitalWrite(this->port_3,0);
      digitalWrite(this->port_4,1);
      break;
  }
}
