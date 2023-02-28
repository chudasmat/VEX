#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include <cmath>

int leftTarget; int rightTarget;
int leftPower; int rightPower;
int leftPrev; int rightPrev;

bool driveInvert = false;
bool brakeHold = false;
std::string driveCurrent = "FW";
std::string brakeCurrent = "NB";

Motor leftA(1, E_MOTOR_GEARSET_06, false);
Motor leftB(2, E_MOTOR_GEARSET_06, false);
Motor leftC(3, E_MOTOR_GEARSET_06, false);
Motor rightA(4, E_MOTOR_GEARSET_06, true);
Motor rightB(5, E_MOTOR_GEARSET_06, true);
Motor rightC(6, E_MOTOR_GEARSET_06, true);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
MotorGroup drive({leftA, leftB, leftC, rightA, rightB, rightC});

// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {1, 2, 3}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{-4, -5, -6}

  // IMU Port
  ,16

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,4.125

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,360

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,0.6

  // Uncomment if using tracking wheels
  
  // Left Tracking Wheel Ports (negative port will reverse it!)
  ,{3, 4}

  // Right Tracking Wheel Ports (negative port will reverse it!)
  ,{5, 6}


  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,9
);

float gradient = 0.5;
float scaledInput = 127;
float scaledOutput = 12000;

void chassisControl (void) {
	leftTarget = master.get_analog(ANALOG_LEFT_Y);
	rightTarget = master.get_analog(ANALOG_RIGHT_Y);
	leftPower = (scaledOutput * tan((leftTarget / scaledInput) * atan(gradient))) / gradient;
	rightPower = (scaledOutput * tan((rightTarget / scaledInput) * atan(gradient))) / gradient;
	
//	leftA.move_voltage(leftPower);
//	leftB.move_voltage(leftPower);
//	leftC.move_voltage(leftPower);
//	rightA.move_voltage(rightPower);
//	rightB.move_voltage(rightPower);
//	rightC.move_voltage(rightPower);
	
	leftA.move_voltage((leftPower + leftPrev) / 2);
	leftB.move_voltage((leftPower + leftPrev) / 2);
	leftC.move_voltage((leftPower + leftPrev) / 2);
	rightA.move_voltage((rightPower + rightPrev) / 2);
	rightB.move_voltage((rightPower + rightPrev) / 2);
	rightC.move_voltage((rightPower + rightPrev) / 2);
	
	leftPrev = leftPower;
	rightPrev = rightPower;}