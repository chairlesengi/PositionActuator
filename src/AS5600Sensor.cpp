#include "AS5600Sensor.h"

AS5600Sensor::AS5600Sensor(){
    _position = 0.0f;
    _lastCounts = 0;
}

bool AS5600Sensor::init(){
    if(!as5600.begin()){
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
    _lastCounts = 0;
}

void AS5600Sensor::update(){
    uint16_t currentCounts = as5600.getRawAngle();
    uint16_t dCounts = currentCounts-_lastCounts;
    if(abs(dCounts) > 2048){dCounts *= -1;} //invert signal if over 50% rotation(assume shorter movement)
    _position += Helper::convertFrom12bit(dCounts); //update position with change
    _lastCounts = currentCounts;
}   

void AS5600Sensor::reset(){
    _position = 0.0f;
    _lastCounts = as5600.getRawAngle();
}

void AS5600Sensor::setAngle(float angle){
    _position = angle;
}

float AS5600Sensor::readAngle(){
    return _position;
}