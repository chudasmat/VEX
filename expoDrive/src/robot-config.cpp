#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor gearA = motor(PORT1, ratio18_1, false);
motor gearB = motor(PORT2, ratio18_1, true);
motor_group gears = motor_group(gearA, gearB);
motor chainA1 = motor(PORT3, ratio18_1, true);
motor chainA2 = motor(PORT4, ratio18_1, true);
motor chainB1 = motor(PORT5, ratio18_1, false);
motor chainB2 = motor(PORT6, ratio18_1, false);
motor_group chain = motor_group(chainA1, chainA2, chainB1, chainB2);
motor fourBar = motor(PORT18, ratio36_1, false);
motor ringIntake = motor(PORT8, ratio18_1, false);
controller Controller1 = controller(primary);
pneumatics lockingClamp = pneumatics(Brain.ThreeWirePort.A);
pneumatics rearMech = pneumatics(Brain.ThreeWirePort.B);
pneumatics goalCover = pneumatics(Brain.ThreeWirePort.C);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonL1/ButtonL2 status to control fourBar
    return 1;


    // wait before repeating the process
    wait(20, msec);
    }
  return 0;
  }
}
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}