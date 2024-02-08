#include "EZ-Template/util.hpp"
#include "globals.h"
#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void default_constants() {
  // PID Constants
  chassis.pid_drive_constants_set(10, 0, 100); // Sets forward and backward
  chassis.pid_heading_constants_set(3, 0, 20);
  chassis.pid_turn_constants_set(3, 0, 20);
  chassis.pid_swing_constants_set(5, 0, 30); // Sets forward and backward

  // Swing Constants
  chassis.slew_drive_constants_set(7_in, 80); // Sets forward and backward
  chassis.slew_turn_constants_set(5_deg, 50);
  chassis.slew_swing_constants_set(5_deg, 50); // Sets forward and backward
}

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
    kicker.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    chassis.set_drive_pid(-45, 115, true); chassis.wait_drive();
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);  
}

void farFiveTriball(void) {
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);

    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}
