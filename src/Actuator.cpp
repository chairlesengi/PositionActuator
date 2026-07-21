#include "Actuator.h"
#include "Helper.h"

#define DEADZONE 0.0025f
#define MAX_ERROR PI/2f;


Actuator::Actuator(Motor* motor, AngleSensor* angle, float ratio, float home, float min, float max): _motor(motor), _angle(angle), _ratio(ratio), _home(home), _minAngle(min), _maxAngle(max) {
    _position = _home;
    _target = _home;
}
Actuator::Actuator(Motor* motor, AngleSensor* angle, float ratio, float home):Actuator(motor, angle, ratio, home, 1e10f, -1e10f){} //set really big limits if none specified

void Actuator::setPosition(float pos){
    _position = pos;
    _angle->setAngle(pos);
}

void Actuator::setAccel(float accel){
    _motor->setAccel(accel);
}

void Actuator::setSpeed(float speed){
    _motor->setSpeed(speed);
}

void Actuator::setTarget(float target){
    _target = Helper::clampFloat(target, _minAngle, _maxAngle);
}

float Actuator::getPosition(){return _position;}

float Actuator::getError(){return (_target-_position);} //if position greater than target, error is negative

AngleSensor* Actuator::getSensor(){return _angle;}

Motor* Actuator::getMotor(){return _motor;}

bool Actuator::begin(){
    _angle->setAngle(_position);
}

void Actuator::goHome(){
    setTarget(_home);
}

void Actuator::zero(){
    setTarget(0.0f);
    setPosition(0.0f);
    _angle->reset();
    _motor->setTarget(0.0f);
}

void Actuator::update(){
    _angle->update();
    _position = _angle->readAngle();
    float error = getError();
    if(fabs(error-_motor->distanceToGo()) < DEADZONE){ //avoid reupdate if error is tolerable
        return;
    }
    else{
        _motor->setTarget(error); //otherwise, recalibrate motor's target distance to go
    }
    _motor->update();
}
