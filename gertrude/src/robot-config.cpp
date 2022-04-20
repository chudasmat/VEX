#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftFront = motor(PORT1, ratio18_1, false);
motor leftMid = motor(PORT2, ratio18_1, true);
motor leftRear = motor(PORT3, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftFront, leftMid, leftRear);
motor rightFront = motor(PORT4, ratio18_1, true);
motor rightMid = motor(PORT5, ratio18_1, false);
motor rightRear = motor(PORT6, ratio18_1, true);
motor_group RightDriveSmart = motor_group(rightFront, rightMid, rightRear);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1.4);
motor fourBar = motor(PORT21, ratio36_1, false);
motor ringIntake = motor(PORT8, ratio18_1, false);
pneumatics lockingClamp = pneumatics(Brain.ThreeWirePort.A);
pneumatics rearMech = pneumatics(Brain.ThreeWirePort.B);
pneumatics goalCover = pneumatics(Brain.ThreeWirePort.C);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on 
controller inputs;
bool Controller1LeftShoulderControlMotorsStopped = true;

bool drivetrainHold = false;
bool goalCoverUp = false;
bool whyyoucominfas = true;

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

      if (Controller1.ButtonR2.pressing()) {
        ringIntake.setVelocity(100, percent);
        ringIntake.spin(forward);
      }
      else if (Controller1.ButtonUp.pressing()) {
        ringIntake.setVelocity(100, percent);
        ringIntake.spin(reverse);
      }
      else if (Controller1.ButtonR1.pressing()) {
        ringIntake.setVelocity(0, percent);
        ringIntake.stop(coast);
      }

      if (Controller1.ButtonDown.pressing()) {
        lockingClamp.open();
      }

      else if (Controller1.ButtonRight.pressing()) {
        lockingClamp.close();
      }

      if (Controller1.ButtonY.pressing()) {
        rearMech.open();
      }

      else if (Controller1.ButtonB.pressing()) {
        rearMech.close();
      }

      if (drivetrainHold) {
        leftFront.setStopping(hold);
        leftMid.setStopping(hold);
        leftRear.setStopping(hold);
        rightFront.setStopping(hold);
        rightMid.setStopping(hold);
        rightRear.setStopping(hold);
      }
      
      else if (!drivetrainHold) {
        leftFront.setStopping(coast);
        leftMid.setStopping(coast);
        leftRear.setStopping(coast);
        rightFront.setStopping(coast);
        rightMid.setStopping(coast);
        rightRear.setStopping(coast);
      }

      if (goalCoverUp) {
        goalCover.close();
      }

      else if (!goalCoverUp) {
        goalCover.open();
      }

      if (whyyoucominfas) {
        leftFront.setVelocity(100, percent);
        leftMid.setVelocity(100, percent);
        leftRear.setVelocity(100, percent);
        rightFront.setVelocity(100, percent);
        rightMid.setVelocity(100, percent);
        rightRear.setVelocity(100, percent);
      }

      else if (!whyyoucominfas) {
        leftFront.setVelocity(80, percent);
        leftMid.setVelocity(80, percent);
        leftRear.setVelocity(80, percent);
        rightFront.setVelocity(80, percent);
        rightMid.setVelocity(80, percent);
        rightRear.setVelocity(80, percent);
      }

      if ((Controller1.ButtonX.pressing()) && (drivetrainHold == false)) {
        drivetrainHold = true;
      }
      
      else if ((Controller1.ButtonX.pressing()) && (drivetrainHold == true)) {
        drivetrainHold = false;
      }

      if ((Controller1.ButtonA.pressing()) && (goalCoverUp == false)) {
        goalCoverUp = true;
      }
      
      else if ((Controller1.ButtonA.pressing()) && (goalCoverUp == true)) {
        goalCoverUp = false;
      }
      
      if ((Controller1.ButtonLeft.pressing()) && (whyyoucominfas == false)) {
        whyyoucominfas = true;
      }
      
      else if ((Controller1.ButtonLeft.pressing()) && (whyyoucominfas == true)) {
        whyyoucominfas = false;
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