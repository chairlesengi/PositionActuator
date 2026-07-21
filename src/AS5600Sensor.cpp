#include "AS5600Sensor.h"

AS5600Sensor::AS5600Sensor(TwoWire& wire): interface_(wire){
    angle_ = 0.0f;
    rotations_ = 0;
    offset_ = 0.0f;
    lastCounts_ = 0;
}

bool AS5600Sensor::begin(){
    if(!as5600.begin(AS5600_DEFAULT_ADDR, &interface_)){
        return false;
    }
    //setup from example code from this library
    as5600.enableWatchdog(false);
    // Normal (high) power mode
    as5600.setPowerMode(AS5600_POWER_MODE_NOM);
    // No Hysteresis
    as5600.setHysteresis(AS5600_HYSTERESIS_OFF);
    // setup filters
    as5600.setSlowFilter(AS5600_SLOW_FILTER_16X);
    as5600.setFastFilterThresh(AS5600_FAST_FILTER_THRESH_SLOW_ONLY);

    // Reset position settings to defaults
    as5600.setZPosition(0);
    as5600.setMPosition(4095);
    as5600.setMaxAngle(4095);
    lastCounts_ = 0;
    return true;
}

void AS5600Sensor::update(){
    uint16_t currentCounts = as5600.getRawAngle();
    int16_t dCounts = currentCounts-lastCounts_;
    angle_ = Helper::convertFrom12bit(currentCounts);
    if(dCounts < -2048){rotations_++;} //cross from 4095 to 10 for example
    else if(dCounts > 2048){rotations_--;} //cross from 10 to 4095
    lastCounts_ = currentCounts;
}   

void AS5600Sensor::reset(){
    rotations_ = 0;
    offset_ = 0.0f;
    lastCounts_ = as5600.getRawAngle();
}

float AS5600Sensor::readAngle(){
    return (angle_+(2*PI*rotations_)+offset_);
}

void AS5600Sensor::setOffset(float offset){
    offset_ = offset;
}