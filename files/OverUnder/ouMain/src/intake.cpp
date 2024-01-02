#include "main.h"
bool intakeOn = false;
Motor intake(20, false);

void intakeControl(void) {
    if (master.get_digital_new_press(DIGITAL_R1)) {
        if (intakeOn) {intake.brake();}
        else {intake.move(127);}
        intakeOn = !intakeOn;
    }
    if (master.get_digital_new_press(DIGITAL_L1)) {
        if (intakeOn) {intake.brake();}
        else {intake.move(-127);}
        intakeOn = !intakeOn;
    }

}