#include "main.h"
#include "pneumatics.h"

double robotAngleRatio = 5.277777778;

// Right = positive
// Left = negative
void turnRobot(double angle) {
    double robotAngle = angle * robotAngleRatio;
    leftDrive.move_relative(robotAngle, 600);
    rightDrive.move_relative(-(robotAngle), 600);  
}

void experimentalAuton(void) {
    chassisDrive->moveDistance(-3_in);
    intake.move_voltage(12000);
    delay(769);
    intake.move_voltage(0);
    chassisDrive->moveDistance(6_in);
    setFW(10000);
    delay(5000);
    indexToggle();
    delay(2500);
    indexToggle();
}

void rollerAuton(void) {
    setFW(9500);
    drive.move_relative(-70, 600);
    intake.move_voltage(-12000);
    delay(350);
    intake.move_voltage(0);
    drive.move_velocity(0);
    drive.move_relative(140, 600);
    delay(5400);
    indexToggle();
    delay(2500);
    indexToggle();
    delay(1000);
    setFW(0);
}

void awpAuton(void) {

}

void adjAuton(void) {
}

void skillsAuton(void) {
    setFW(10000);
    drive.move_relative(-70, 600);
    intake.move_voltage(-12000);
    delay(350);
    intake.move_voltage(0);
    drive.move_velocity(0);
    drive.move_relative(140, 600);
    delay(5400);
    indexToggle();
    delay(2500);
    indexToggle();
    delay(1000);
    turnRobot(250);
    // around 450 = 90 deg
    stringS.set_value(true); 
    delay(200); 
    stringS.set_value(false);
}