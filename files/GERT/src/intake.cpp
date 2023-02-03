#include "intake.h"
#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"

Motor intake(20, MOTOR_GEAR_200, true);
bool intakeSpinning = false;

void intakeControl (void) {
    while (true) {
        if (master.get_digital_new_press(DIGITAL_RIGHT)) {
            if (intakeSpinning) {intake.move_voltage(0);}
            else {intake.move_voltage(12000);}
            intakeSpinning = !intakeSpinning;}
        if (master.get_digital_new_press(DIGITAL_DOWN)) {
            if (intakeSpinning) {intake.move_voltage(0);}
            else {(intake.move_voltage(-12000));}
            intakeSpinning = !intakeSpinning;}
        delay(20);}
}
