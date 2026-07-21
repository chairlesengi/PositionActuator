#pragma once
#include <Arduino.h>

namespace Helper{
    inline float clampFloat(float val, float min, float max){
        if(val > max){val = max;}
        else if (val < min){val = min;}
        return val;
    }
    inline uint32_t convertTo12bit(float angle){
        return lroundf((angle/(2*PI))*4096);
    }
    constexpr float convertFrom12bit(uint32_t counts){
        return ((counts/4096.0f)*(2*PI));
    }
    inline int32_t convertToSteps(float angle, uint32_t stepsRev){
        return lroundf((angle/(2*PI))*stepsRev);
    }
    constexpr float convertFromSteps(int32_t steps, uint32_t stepsRev){
        return (steps/((float)stepsRev))*(2*PI);
    }
};