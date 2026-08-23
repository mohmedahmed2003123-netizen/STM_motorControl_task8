#ifndef BTS7960_H
#define BTS7960_H

#include "MotorDriver.h"
#include <Arduino.h>

class BTS7960 : public MotorDriver {
private:
    int _rpwm, _lpwm;

public:
    BTS7960(int rpwm, int lpwm);

    void init() override;
    void drive(int speed) override;

    static void BTS_init(int RPWM, int LPWM);
    static void BTS_drive(int RPWM, int LPWM, int speed_in_pwm);
};

#endif
