#include "BTS7960.h"

BTS7960::BTS7960(int rpwm, int lpwm) : _rpwm(rpwm), _lpwm(lpwm) {}

void BTS7960::init() {
    BTS_init(_rpwm, _lpwm);
}

void BTS7960::drive(int speed) {
    BTS_drive(_rpwm, _lpwm, speed);
}

void BTS7960::BTS_init(int RPWM, int LPWM) {
    pinMode(RPWM, OUTPUT);
    pinMode(LPWM, OUTPUT);
}

void BTS7960::BTS_drive(int RPWM, int LPWM, int speed_in_pwm) {
    if (speed_in_pwm > 0) {         
        analogWrite(RPWM, speed_in_pwm);
        analogWrite(LPWM, 0);
    } else if (speed_in_pwm < 0) {  
        analogWrite(RPWM, 0);
        analogWrite(LPWM, -speed_in_pwm);
    } else {                         
        analogWrite(RPWM, 0);
        analogWrite(LPWM, 0);
    }
}
