#include "CytronMD10A.h"

CytronMD10A::CytronMD10A(int dir, int pwm) : _dir(dir), _pwm(pwm) {}

void CytronMD10A::init() {
    Cytron_init(_dir, _pwm);
}

void CytronMD10A::drive(int speed) {
    Cytron_drive(_dir, _pwm, speed);
}

void CytronMD10A::Cytron_init(int DIR, int PWM) {
    pinMode(DIR, OUTPUT);
    pinMode(PWM, OUTPUT);
}

void CytronMD10A::Cytron_drive(int DIR, int PWM, int speed_in_pwm) {
    if (speed_in_pwm > 0) {          // أمامي
        digitalWrite(DIR, HIGH);
        analogWrite(PWM, speed_in_pwm);
    } else if (speed_in_pwm < 0) {   // خلفي
        digitalWrite(DIR, LOW);
        analogWrite(PWM, -speed_in_pwm);
    } else {                         // توقف
        digitalWrite(DIR, LOW);
        analogWrite(PWM, 0);
    }
}
