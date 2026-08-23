#include "L298N.h"

L298N::L298N(int in1, int in2, int ena) : _in1(in1), _in2(in2), _ena(ena) {}

void L298N::init() {
    L298N_init(_in1, _in2, _ena);
}

void L298N::drive(int speed) {
    L298N_drive(_in1, _in2, _ena, speed);
}

void L298N::L298N_init(int IN1, int IN2, int ENA) {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
}

void L298N::L298N_drive(int IN1, int IN2, int ENA, int speed_in_pwm) {
    if (speed_in_pwm > 0) {        
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, speed_in_pwm);
    } else if (speed_in_pwm < 0) {  
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, -speed_in_pwm); 
    } else {                         
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, 0);
    }
}
