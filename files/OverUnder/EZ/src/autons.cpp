#include "EZ-Template/util.hpp"
#include "globals.h"
#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"


void nearOneTriball(void) {
    chassis.set_drive_pid(-45, 110, true); delay(1200);
    chassis.set_turn_pid(40, 100); delay(1200);
    chassis.set_drive_pid(-20, 110, true); delay(1200);
    chassis.set_drive_pid(30, 100, true); delay(1200);
    chassis.set_drive_pid(-30, 127, false); delay(1200);
    chassis.set_drive_pid(20, 110, true); delay(1200);
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}
void farOneTriball(void) {
    chassis.set_drive_pid(55, 110, true); delay(1200);
    chassis.set_turn_pid(-40, 100); delay(1200);
    chassis.set_drive_pid(20, 110, true); delay(1200);
    chassis.set_drive_pid(-30, 100, true); delay(1200);
    chassis.set_drive_pid(30, 127, false); delay(1200);
    chassis.set_drive_pid(-20, 110, true); delay(1200);
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}

void nearThreeTriball(void) {
    chassis.set_drive_pid(75, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(-90, 100); chassis.wait_drive();
    intake.move_relative(-1000, 200);
    chassis.set_drive_pid(20, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-15, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(90, 100); chassis.wait_drive();
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
    chassis.set_drive_pid(-55, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(40, 100); chassis.wait_drive();
    chassis.set_drive_pid(-20, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(30, 100, true); chassis.wait_drive();
    chassis.set_drive_pid(-30, 127, false); chassis.wait_drive();
    delay(150);
    chassis.set_turn_pid(180, 100);
    chassis.set_drive_pid(-40, 110, true); chassis.wait_drive();
    delay(500);
    bigWings.set_value(1);
    delay(500);
    chassis.set_turn_pid(-90, 100); chassis.wait_drive();
    delay(500);
    bigWings.set_value(0);
    delay(500);
    kicker.set_brake_modes(E_MOTOR_BRAKE_HOLD);
    chassis.set_drive_pid(-45, 115, true); chassis.wait_drive();
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);  
}

void farFiveTriball(void) {
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);

    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}
