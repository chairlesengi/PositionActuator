#pragma once
#include <Arduino.h>
#include "AngleSensor.h"
#include "Motor.h"

class Actuator{
    private:
        float _position;
        float _target;
        float _home;
        float _ratio;
        float _minAngle;
        float _maxAngle;
        AngleSensor* _angle;
        Motor* _motor;
    public:
        Actuator(Motor* motor, AngleSensor* angle, float ratio, float home);
        Actuator(Motor* motor, AngleSensor* angle, float ratio, float home, float min, float max);
        void zero();
        void goHome();
        void setPosition(float pos);
        void setTarget(float target);
        void setSpeed(float speed);
        void setAccel(float accel);
        void update();
        bool begin();
        float getPosition();
        float getError();
        AngleSensor* getSensor();
        Motor* getMotor();
};