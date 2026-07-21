#pragma once
#include <Adafruit_AS5600.h>
#include "AngleSensor.h"
#include "Helper.h"

class AS5600Sensor : public AngleSensor{
    private:
        float angle_; //monitors angle of sensor absolutely
        float offset_; //offset within a rotation of the angle
        TwoWire& interface_;
        int32_t rotations_; //monitors rotations of sensor
        uint16_t lastCounts_;
        Adafruit_AS5600 as5600;
    public:
        explicit AS5600Sensor(TwoWire& wire = Wire);
        bool begin() override;
        float readAngle() override;
        void update() override;
        void setOffset(float offset) override;
        void reset() override; //resets to zero position
};