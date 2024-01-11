#include "main.h"

float leftInput; float rightInput;
float leftPower; float rightPower;

Motor leftA(2, E_MOTOR_GEARSET_06, true);
Motor leftB(3, E_MOTOR_GEARSET_06, true);
Motor leftC(4, E_MOTOR_GEARSET_06, true);
Motor rightA(5, E_MOTOR_GEARSET_06, false);
Motor rightB(6, E_MOTOR_GEARSET_06, false);
Motor rightC(10, E_MOTOR_GEARSET_06, false);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
Imu imu(11);

Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-2, -3, -4}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{5, 6, 10}

  // IMU Port
  ,11

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  ,2.75

  // Cartridge RPM
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,0.75
);

void chassisControl (void) {
    leftInput = master.get_analog(ANALOG_LEFT_Y);
    rightInput = master.get_analog(ANALOG_RIGHT_Y);

//	leftPower = (atan((2 * leftInput - (leftInput / std::abs(leftInput))) * 5.5) / (2 * atan(5.5))) + (leftInput / (2 * std::abs(leftInput))) * 127;
//	rightPower = (atan((2 * rightInput - (rightInput / std::abs(rightInput))) * 5.5) / (2 * atan(5.5))) + (rightInput / (2 * std::abs(rightInput))) * 127;
	
	leftA.move(leftInput);
	leftB.move(leftInput);
	leftC.move(leftInput);
	rightA.move(rightInput);
	rightB.move(rightInput);
	rightC.move(rightInput);}