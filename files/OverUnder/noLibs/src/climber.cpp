#include "main.h"

Motor roll(12, false);
ADIDigitalOut wheelExtend(6);
bool isExtend = false;

void climberControl(void) {
    roll.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    if (master.get_digital(DIGITAL_UP)) {roll.move(127);}
    else if (master.get_digital(DIGITAL_LEFT)) {roll.move(-127);}
    else {roll.brake();}

    if (master.get_digital_new_press(DIGITAL_X)) {
        wheelExtend.set_value(!isExtend);
        isExtend = !isExtend;
    }
}