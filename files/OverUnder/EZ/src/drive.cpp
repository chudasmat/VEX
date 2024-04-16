#include "main.h"

float leftInput; float rightInput;
float leftPower; float rightPower;
bool holdOn = false;

Motor leftA(11, E_MOTOR_GEARSET_06, true);
Motor leftB(12, E_MOTOR_GEARSET_06, true);
Motor leftC(13, E_MOTOR_GEARSET_06, true);
Motor rightA(20, E_MOTOR_GEARSET_06, false);
Motor rightB(19, E_MOTOR_GEARSET_06, false);
Motor rightC(18, E_MOTOR_GEARSET_06, false);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
Imu imu(10);

Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-11, -12, -13}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{20, 19, 18}

  // IMU Port
  ,10

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
  chassis.tank();
  // weirdly formatted drive hold + controller screen update [midnight antics]
  if (master.get_digital_new_press(DIGITAL_UP)) {
    holdOn = !holdOn;
    if (!holdOn) {chassis.set_drive_brake(E_MOTOR_BRAKE_COAST); delay(50);
      if (ptoOn) {master.print(0, 0, "COAST - PTO ENGAGED   ");}
      else {master.print(0, 0, "COAST - PTO DISENGAGED");}}
    else if (holdOn) {chassis.set_drive_brake(E_MOTOR_BRAKE_HOLD); delay(50); 
      if (ptoOn) {master.print(0, 0, "HOLD - PTO ENGAGED    ");}
      else {master.print(0, 0, "HOLD - PTO DISENGAGED ");}}
    
    }
}

void setDrive(int volt) {leftDrive.move(volt); rightDrive.move(volt);}