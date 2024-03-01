#include "main.h"
bool intakeOn = false;
Motor intakeA(19, false);
Motor intakeB(20, true);
MotorGroup intake({intakeA, intakeB});

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