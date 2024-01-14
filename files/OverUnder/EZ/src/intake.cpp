#include "main.h"
bool intakeOn = false;
Motor intakeA(20, false);
Motor intakeB(19, true);
MotorGroup intake({intakeA, intakeB});

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