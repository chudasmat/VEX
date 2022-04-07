#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotorA = motor(PORT1, ratio18_1, true);
motor leftMotorB = motor(PORT2, ratio18_1, true);
motor leftMotorC = motor(PORT3, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor rightMotorA = motor(PORT4, ratio18_1, false);
motor rightMotorB = motor(PORT5, ratio18_1, false);
motor rightMotorC = motor(PORT6, ratio18_1, false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB, rightMotorC);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1.4);
motor fourBar = motor(PORT7, ratio36_1, false);
motor ringIntake = motor(PORT8, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {


    if(RemoteControlCodeEnabled) {
      // check the ButtonL1/ButtonL2 status to control fourBar
      if (Controller1.ButtonL1.pressing()) {
        fourBar.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        fourBar.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        fourBar.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }

      if (Controller1.ButtonB.pressing()) {
        ringIntake.spin(forward);
      }
      else if (Controller1.ButtonY.pressing()) {
        ringIntake.spin(reverse);
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}