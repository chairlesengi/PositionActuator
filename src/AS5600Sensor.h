#pragma once
#include <Adafruit_AS5600.h>
#include "AngleSensor.h"
#include "Helper.h"

class AS5600Sensor : public AngleSensor{
    private:
        float _angle; //monitors angle of sensor absolutely
        float _offset; //offset within a rotation of the angle
        int16_t _rotations; //monitors rotations of sensor
        uint16_t _lastCounts;
        Adafruit_AS5600 as5600;
    public:
        explicit AS5600Sensor(TwoWire& wire = Wire);
        bool begin() override;
        float readAngle() override;
        void update() override;
        void setOffset(float offset) override;
        void reset() override; //resets to zero position
};