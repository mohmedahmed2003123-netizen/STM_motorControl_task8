#ifndef L298N_H
#define L298N_H

#include "MotorDriver.h"
#include <Arduino.h>

class L298N : public MotorDriver {
private:
    int _in1, _in2, _ena;

public:
    L298N(int in1, int in2, int ena);

    void init() override;
    void drive(int speed) override;

    
    static void L298N_init(int IN1, int IN2, int ENA);
    static void L298N_drive(int IN1, int IN2, int ENA, int speed_in_pwm);
};

#endif
