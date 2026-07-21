#pragma once
#include <Arduino.h>

class AngleSensor{
    public:
        virtual ~AngleSensor() = default;
        virtual bool begin() = 0;
        virtual void update() = 0; //to update the rolling position
        virtual float readAngle() = 0; //reads angle in radians absolutely, monitors rollover as well
        virtual void setOffset(float offset) = 0; //sets offset for readout, in radians
        virtual void reset() = 0; //resets to zero position
};