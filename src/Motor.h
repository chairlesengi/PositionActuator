#pragma once
#include <Arduino.h>

class Motor{
    public:
        virtual ~Motor() = default;
        virtual bool init() {} //inits motor (with pre given parameters like pin, whatever defined by subclass)
        virtual void setAccel(float accel) {} //sets acceleration of motor in rad/s
        virtual void setSpeed(float speed) {} //sets target speed of motor in rad/s
        virtual void setTarget(float target) {} //sets target position (relative to current)
        virtual void update() {} //non-blocking update function
        virtual float distanceToGo() {} //counts down (or up) towards zero distance to go based on where it was set
};