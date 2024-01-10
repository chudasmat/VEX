#include "main.h"

float leftInput; float rightInput;
float leftPower; float rightPower;

Motor rightA(5, E_MOTOR_GEARSET_06, false);
Motor rightB(6, E_MOTOR_GEARSET_06, false);
Motor rightC(10, E_MOTOR_GEARSET_06, false);
Motor leftA(2, E_MOTOR_GEARSET_06, true);
Motor leftB(3, E_MOTOR_GEARSET_06, true);
Motor leftC(4, E_MOTOR_GEARSET_06, true);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
Imu imu(11);

void chassisControl (void) {
    leftInput = master.get_analog(ANALOG_LEFT_Y) / 127.0;
    rightInput = master.get_analog(ANALOG_RIGHT_Y) / 127.0;
	leftPower = (atan((2 * leftInput - (leftInput / std::abs(leftInput))) * 5.5) / (2 * atan(5.5))) + (leftInput / (2 * std::abs(leftInput))) * 127;
	rightPower = (atan((2 * rightInput - (rightInput / std::abs(rightInput))) * 5.5) / (2 * atan(5.5))) + (rightInput / (2 * std::abs(rightInput))) * 127;
	
	leftA.move(leftInput * 127);
	leftB.move(leftInput * 127);
	leftC.move(leftInput * 127);
	rightA.move(rightInput * 127);
	rightB.move(rightInput * 127);
	rightC.move(rightInput * 127);}