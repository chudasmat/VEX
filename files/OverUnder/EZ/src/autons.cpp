#include "globals.h"
#include "main.h"
#include "pros/motors.h"

void oneTriball(void) {
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
    chassis.set_drive_pid(55, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(-40, 100); chassis.wait_drive();
    intake.move(-127);
    chassis.set_drive_pid(20, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-30, 100, true); chassis.wait_drive();
    chassis.set_drive_pid(40, 127, false); chassis.wait_drive();
    chassis.set_drive_pid(-30, 110, true);
    intake.brake();
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}

void nearThreeTriball(void) {
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
    chassis.set_drive_pid(75, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(-90, 100); chassis.wait_drive();
    chassis.set_drive_pid(20, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-15, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.move(127);
    chassis.set_drive_pid(20, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.brake();
    chassis.set_drive_pid(20, 110, false); chassis.wait_drive();
    chassis.set_drive_pid(-15, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.move(127);
    chassis.set_drive_pid(50, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-5, 110, false); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.brake();
    chassis.set_drive_pid(50, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-10, 110, false); chassis.wait_drive();
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}

void farThreeTriball(void) {
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
    chassis.set_drive_pid(75, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(90, 100); chassis.wait_drive();
    chassis.set_drive_pid(20, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-15, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.move(127);
    chassis.set_drive_pid(20, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.brake();
    chassis.set_drive_pid(20, 110, false); chassis.wait_drive();
    chassis.set_drive_pid(-15, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.move(127);
    chassis.set_drive_pid(50, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-5, 110, false); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.brake();
    chassis.set_drive_pid(50, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-10, 110, false); chassis.wait_drive();
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}

void partialAWP(void) {
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}