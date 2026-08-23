#ifndef CYTRON_H
#define CYTRON_H

#include "MotorDriver.h"
#include <Arduino.h>

class CytronMD10A : public MotorDriver {
private:
    int _dir, _pwm;

public:
    CytronMD10A(int dir, int pwm);

    void init() override;
    void drive(int speed) override;

    static void Cytron_init(int DIR, int PWM);
    static void Cytron_drive(int DIR, int PWM, int speed_in_pwm);
};

#endif
