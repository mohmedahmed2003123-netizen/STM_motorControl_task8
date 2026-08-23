#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

class MotorDriver {
public:
    virtual void init() = 0;         
    virtual void drive(int speed) = 0; // speed: -255 
    virtual ~MotorDriver() {}
};

#endif
