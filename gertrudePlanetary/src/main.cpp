/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// gears                motor_group   1, 2            
// chain                motor_group   3, 4, 5, 6            
// fourBar              motor         7               
// ringIntake           motor         8               
// Controller1          controller                    
// fourBarClamp         digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    gearA.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct); //(Axis3+Axis4)/2                Left Side
    chainA1.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct); //(Axis3+Axis4)/2              Tank Control
    chainA2.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct); //(Axis3+Axis4)/2              Left Stick
    
    gearB.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);//(Axis3-Axis4)/2           Right Side
    chainB1.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);//(Axis3-Axis4)/2          Tank Control
    chainB2.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);//(Axis3-Axis4)/2          Right Stick


    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
