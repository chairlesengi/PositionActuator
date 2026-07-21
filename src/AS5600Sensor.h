#pragma once
#include <Adafruit_AS5600.h>
#include "AngleSensor.h"
#include "Helper.h"

class AS5600Sensor : public AngleSensor{
    private:
        float _position;
        uint16_t _lastCounts;
        Adafruit_AS5600 as5600;
    public:
        AS5600Sensor();
        bool init() override;
        float readAngle() override;
        void update() override;
        void setAngle(float angle) override; //sets current angle to a set value
        void reset() override; //resets to zero position
};