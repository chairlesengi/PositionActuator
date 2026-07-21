#pragma once
#include <Arduino.h>

namespace Helper{
    inline float clampFloat(float val, float min, float max){
        if(val > max){val = max;}
        else if (val < min){val = min;}
        return val;
    }
    constexpr uint16_t convertTo12bit(float angle){
        return (int)((angle/(2*PI))*4096);
    }
    constexpr float convertFrom12bit(uint16_t counts){
        return ((counts/4096.0f)*(2*PI));
    }
}