#include "main.h"
bool intakeOn = false;
Motor intake(19, false);

void intakeControl(void) {
    if (master.get_digital_new_press(DIGITAL_R2)) {
        if (intakeOn) {intake.brake();}
        else {intake.move(127);}
        intakeOn = !intakeOn;
    }
    if (master.get_digital_new_press(DIGITAL_L2)) {
        if (intakeOn) {intake.brake();}
        else {intake.move(-127);}
        intakeOn = !intakeOn;
    }

}