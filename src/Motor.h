#pragma once
#include <Arduino.h>

class Motor{
    public:
        virtual ~Motor() = default;
        virtual bool init() = 0; //inits motor (with pre given parameters like pin, whatever defined by subclass)
        virtual void setAccel(float accel) = 0; //sets acceleration of motor in rad/s
        virtual void setSpeed(float speed) = 0; //sets target speed of motor in rad/s
        virtual void setTarget(float target) = 0; //sets target position (relative to current)
        virtual void update() = 0; //non-blocking update function
        virtual float distanceToGo() = 0; //counts down (or up) towards zero distance to go based on where it was set
};