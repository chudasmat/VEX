#include "main.h"

float leftInput; float rightInput;
float leftPower; float rightPower;

Motor rightA(1, E_MOTOR_GEARSET_06, true);
Motor rightB(2, E_MOTOR_GEARSET_06, true);
Motor rightC(3, E_MOTOR_GEARSET_06, true);
Motor leftA(8, E_MOTOR_GEARSET_06, false);
Motor leftB(9, E_MOTOR_GEARSET_06, false);
Motor leftC(10, E_MOTOR_GEARSET_06, false);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
Imu imu(16);

void chassisControl (void) {
    leftInput = master.get_analog(ANALOG_LEFT_Y);
    rightInput = master.get_analog(ANALOG_RIGHT_Y);
//	leftPower = (atan((2 * leftInput - (leftInput / std::abs(leftInput))) * 5.5) / (2 * atan(5.5))) + (leftInput / (2 * std::abs(leftInput)));
//	rightPower = (atan((2 * rightInput - (rightInput / std::abs(rightInput))) * 5.5) / (2 * atan(5.5))) + (rightInput / (2 * std::abs(rightInput)));
	
	leftDrive.move(leftInput);
	rightDrive.move(rightInput);}