#include "EZ-Template/util.hpp"
#include "globals.h"
#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

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
    bigWings.set_value(1);
    delay(150);
    bigWings.set_value(0);
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    chassis.set_drive_pid(25, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(45, 100); chassis.wait_drive();
    chassis.set_drive_pid(24, 127); chassis.wait_drive();
    chassis.set_drive_pid(-24, 110); chassis.wait_drive();
    chassis.set_turn_pid(130, 100); chassis.wait_drive();
    chassis.set_drive_pid(50, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(-40, 110); chassis.wait_drive();
    kicker.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    chassis.set_drive_pid(30, 110); chassis.wait_drive();
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}

void farFiveTriball(void) {
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
    bigWings.set_value(1);
    delay(150);
    chassis.set_swing_pid(ez::RIGHT_SWING, 45, 127); chassis.wait_drive();
    intake.move(-127);
    delay(150);
    chassis.set_drive_pid(40, 127); chassis.wait_drive();
    chassis.set_drive_pid(-24, 110); chassis.wait_drive();
    intake.brake();
    chassis.set_turn_pid(-40, 100); chassis.wait_drive();
    intake.move(127);
    chassis.set_drive_pid(86, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-30, 100); chassis.wait_drive();
    chassis.set_turn_pid(100, 100); chassis.wait_drive();
    chassis.set_drive_pid(20, 127);
    intake.move(-120); chassis.wait_drive();
    chassis.set_turn_pid(-80, 110); chassis.wait_drive();
    chassis.set_drive_pid(30, 110, true); intake.move(127); chassis.wait_drive();
    chassis.set_turn_pid(120, 110);
    bigWings.set_value(1);
    chassis.set_drive_pid(65, 127); chassis.wait_drive();
    chassis.set_drive_pid(-30, 127); chassis.wait_drive();
    chassis.set_drive_pid(30, 127); chassis.wait_drive();
    chassis.set_drive_pid(-30, 127); chassis.wait_drive();
    bigWings.set_value(0);
    chassis.set_turn_pid(90, 115); chassis.wait_drive();
    chassis.set_drive_pid(70, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(90, 110); chassis.wait_drive();
    kicker.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    chassis.set_drive_pid(40, 127); chassis.wait_drive();
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}