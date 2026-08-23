#include "L298N.h"
#include "CytronMD10A.h"
#include "BTS7960.h"

#define L298N_IN1  PA0
#define L298N_IN2  PA1
#define L298N_ENA  PA2

#define CYTRON_DIR PA3
#define CYTRON_PWM PA6

#define BTS_RPWM   PA7
#define BTS_LPWM   PB0


L298N motor1(L298N_IN1, L298N_IN2, L298N_ENA);
CytronMD10A motor2(CYTRON_DIR, CYTRON_PWM);
BTS7960 motor3(BTS_RPWM, BTS_LPWM);

void setup() {
    motor1.init();
    motor2.init();
    motor3.init();
}

void loop() {
     motor1.drive(180);
    motor2.drive(180);
    motor3.drive(180);
    delay(3000);

    // 2) توقف
    motor1.drive(0);
    motor2.drive(0);
    motor3.drive(0);
    delay(2000);

    
    motor1.drive(-128);
    motor2.drive(-128);
    motor3.drive(-128);
    delay(3000);

    
    motor1.drive(0);
    motor2.drive(0);
    motor3.drive(0);
    delay(2000);

    
    motor1.drive(64);   // 25%
    motor2.drive(128);  // 50%
    motor3.drive(255);  // 100%
    delay(3000);

   
    motor1.drive(0);
    motor2.drive(0);
    motor3.drive(0);
    delay(2000);
}
