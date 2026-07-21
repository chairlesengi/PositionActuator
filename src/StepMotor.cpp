#include "StepMotor.h"
#include "Helper.h"

StepMotor::StepMotor(uint8_t stepPin, uint8_t dirPin, uint16_t stepsRev, float speed, float accel): stepper_(AccelStepper::DRIVER, stepPin, dirPin), stepsRev_(stepsRev){
    stepper_.setMaxSpeed(Helper::convertToSteps(speed,stepsRev));
    stepper_.setSpeed(Helper::convertToSteps(speed,stepsRev));
    stepper_.setAcceleration(Helper::convertToSteps(accel,stepsRev));
}

StepMotor::StepMotor(uint8_t stepPin, uint8_t dirPin, uint16_t stepsRev):StepMotor(stepPin,dirPin,stepsRev,15.0f,15.0f){}

bool StepMotor::begin(){
    return true; //not needed here
}

void StepMotor::setAccel(float accel){
    stepper_.setAcceleration(Helper::convertToSteps(accel,stepsRev_));
}

void StepMotor::setSpeed(float speed){
    stepper_.setMaxSpeed(Helper::convertToSteps(speed,stepsRev_));
    stepper_.setSpeed(Helper::convertToSteps(speed,stepsRev_));
}

void StepMotor::setTarget(float target){
    stepper_.move(Helper::convertToSteps(target, stepsRev_));
}
void StepMotor::update(){
    stepper_.run();
}
float StepMotor::distanceToGo(){
    return Helper::convertFromSteps(stepper_.distanceToGo(),stepsRev_);
}