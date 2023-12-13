#include "main.h"
#include <iostream>
#include <cmath>

float leftTarget; float rightTarget;
float leftPower; float rightPower;
float leftPrev; float rightPrev;


Controller master(E_CONTROLLER_MASTER);

Motor leftA(1, MOTOR_GEAR_600, false);
Motor leftB(2, MOTOR_GEAR_200, false);
Motor leftC(3, MOTOR_GEAR_600, false);
Motor rightA(4, MOTOR_GEAR_600, true);
Motor rightB(5, MOTOR_GEAR_200, true);
Motor rightC(6, MOTOR_GEAR_600, true);

MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});

Imu inertial(7);

lemlib::Drivetrain drivetrain(&leftDrive, &rightDrive, 10, lemlib::Omniwheel::NEW_275, 450, 8);

lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            30, // derivative gain (kD)
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                             10, // derivative gain (kD)
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             20 // maximum acceleration (slew)
);

lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to nullptr as we don't have one
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have one
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertial // inertial sensor
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);

void chassisControl (void) {
    // thanks for the curve eden
	leftTarget = master.get_analog(ANALOG_LEFT_Y);
	rightTarget = master.get_analog(ANALOG_RIGHT_Y);
	leftPower = (atan((2 * leftTarget - (leftTarget / abs(leftTarget))) * 5.5) / (2 * atan(5.5))) + (leftTarget / (2 * abs(leftTarget))) * 127;
	rightPower = (atan((2 * rightTarget - (rightTarget / abs(rightTarget))) * 5.5) / (2 * atan(5.5))) + (rightTarget / (2 * abs(rightTarget))) * 127;
	
	leftDrive.move(leftPower);
	rightDrive.move(rightPower);}




