#include "globals.h"
#include "main.h"
#include "pros/motors.h"

void simpleAuton(void) {
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
    chassis.set_drive_pid(24, 100, true);
    chassis.wait_drive();
    chassis.set_turn_pid(90, 90);
    chassis.wait_drive();
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}