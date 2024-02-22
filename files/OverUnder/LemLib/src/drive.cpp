#include "main.h"

float leftInput; float rightInput;
float leftPower; float rightPower;
bool holdOn = false;

Motor leftA(20, E_MOTOR_GEARSET_06, false);
Motor leftB(6, E_MOTOR_GEARSET_06, false);
Motor leftC(9, E_MOTOR_GEARSET_06, false);
Motor rightA(12, E_MOTOR_GEARSET_06, false);
Motor rightB(13, E_MOTOR_GEARSET_06, false);
Motor rightC(18, E_MOTOR_GEARSET_06, false);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
Imu imu(19);


void chassisControl (void) {

/*  leftInput = master.get_analog(ANALOG_LEFT_Y);
    rightInput = master.get_analog(ANALOG_RIGHT_Y);

    leftPower = (atan((2 * leftInput - (leftInput / std::abs(leftInput))) * 5.5) / (2 * atan(5.5))) + (leftInput / (2 * std::abs(leftInput))) * 127;
	  rightPower = (atan((2 * rightInput - (rightInput / std::abs(rightInput))) * 5.5) / (2 * atan(5.5))) + (rightInput / (2 * std::abs(rightInput))) * 127;
	
	  leftA.move(leftInput);
	  leftB.move(leftInput);
	  leftC.move(leftInput);
	  rightA.move(rightInput);
	  rightB.move(rightInput);
	  rightC.move(rightInput);
*/
}