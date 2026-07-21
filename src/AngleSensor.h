#pragma once
#include <Arduino.h>

class AngleSensor{
    public:
        virtual ~AngleSensor() = default;
        virtual bool init() = 0;
        virtual void update() = 0; //to update the rolling position
        virtual float readAngle() = 0; //reads angle in radians absolutely, monitors rollover as well
        virtual void setAngle(float angle) = 0; //sets current angle to a set value
        virtual void reset() = 0; //resets to zero position
};