#pragma once
#include <Arduino.h>
#include "AngleSensor.h"
#include "Motor.h"

class Actuator{
    private:
        float _position = 0.0f;
        float _target;
        float _home;
        float _ratio;
        //of output, not input
        float _minAngle;
        float _maxAngle;
        AngleSensor& _angle;
        Motor& _motor;
    public:
        explicit Actuator(Motor& motor, AngleSensor& angle, float ratio, float home);
        explicit Actuator(Motor& motor, AngleSensor& angle, float ratio, float home, float min, float max);
        void zero();
        void goHome();
        void setTarget(float target);
        void setSpeed(float speed);
        void setAccel(float accel);
        void setHome(float home);
        void update();
        bool begin();
        float getPosition();
        float getError();
};