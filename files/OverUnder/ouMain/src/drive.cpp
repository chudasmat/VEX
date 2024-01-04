#include "main.h"

float leftInput; float rightInput;
float leftPower; float rightPower;

Motor rightA(8, E_MOTOR_GEARSET_06, true);
Motor rightB(9, E_MOTOR_GEARSET_06, true);
Motor rightC(10, E_MOTOR_GEARSET_06, true);
Motor leftA(2, E_MOTOR_GEARSET_06, true);
Motor leftB(3, E_MOTOR_GEARSET_06, true);
Motor leftC(4, E_MOTOR_GEARSET_06, true);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
Imu imu(16);

void chassisControl (void) {
    leftInput = master.get_analog(ANALOG_LEFT_Y) / 127.0;
    rightInput = master.get_analog(ANALOG_RIGHT_Y) / 127.0;
	leftPower = (atan((2 * leftInput - (leftInput / std::abs(leftInput))) * 5.5) / (2 * atan(5.5))) + (leftInput / (2 * std::abs(leftInput))) * 127;
	rightPower = (atan((2 * rightInput - (rightInput / std::abs(rightInput))) * 5.5) / (2 * atan(5.5))) + (rightInput / (2 * std::abs(rightInput))) * 127;
	
	leftA.move(leftPower * 127);
	leftB.move(leftPower * 127);
	leftC.move(leftPower * 127);
	rightA.move(rightPower * 127);
	rightB.move(rightPower * 127);
	rightC.move(rightPower * 127);}