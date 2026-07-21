#pragma once
#include <Arduino.h>
#include "Motor.h"
#include <AccelStepper.h>

class StepMotor : public Motor{
    private:
        AccelStepper stepper_;
        uint16_t stepsRev_;
    public: 
        explicit StepMotor(uint8_t stepPin, uint8_t dirPin, uint16_t stepsRev);
        explicit StepMotor(uint8_t stepPin, uint8_t dirPin, uint16_t stepsRev, float speed, float accel);
        bool begin() override; //inits motor (with pre given parameters like pin, whatever defined by subclass)
        void setAccel(float accel) override; //sets acceleration of motor in rad/s
        void setSpeed(float speed) override; //sets target speed of motor in rad/s
        void setTarget(float target) override; //sets target position (relative to current)
        void update() override; //non-blocking update function
        float distanceToGo() override; //counts down (or up) towards zero distance to go based on where it was set
};