/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

bool driveToggle = false;
bool driveLatch = false;
bool intakeToggle = false;
bool intakeLatch = false;
bool rollerToggle = false;
bool rollerLatch = false;

int error;
int goal = 400;
int prevError;
int output;
int tbh;
double gain = 0.03;

bool resetEncoders = false;
bool enableTBH = true;

int TBH() {
  while (enableTBH) {
    if (resetEncoders) {
      resetEncoders = false;
      flywheel.resetPosition();
    }

    double currentSpeed = flywheel.velocity(rpm);

    error = goal - currentSpeed;                // calculate the error;
    output += gain * error;                     // integrate the output;
    if (signbit(error)!= signbit(prevError)) {  // if zero crossing,
      output = 0.5 * (output + tbh);            // then Take Back Half
      tbh = output;                             // update Take Back Half variable
      prevError = error;                       // and save the previous error
      vex::task::sleep(10);                     // then wait for 20ms
    }
  }
  return 1;
}


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
  Brain.Screen.drawImageFromFile("alexx.png", 0, 0);
  vex::task TBH_(TBH);

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
    ///////////////////////////////////////// Driver Controls (Start) ////////////////////////////////////
    if (driveToggle) {
      leftMotorA.spin(vex::directionType::fwd, -(Controller1.Axis2.value()), vex::velocityUnits::pct);                 
      leftMotorB.spin(vex::directionType::fwd, -(Controller1.Axis2.value()), vex::velocityUnits::pct);                       
      rightMotorA.spin(vex::directionType::fwd, -(Controller1.Axis3.value()), vex::velocityUnits::pct);                 
      rightMotorB.spin(vex::directionType::fwd, -(Controller1.Axis3.value()), vex::velocityUnits::pct);                 
    } else {
      leftMotorA.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);                 
      leftMotorB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);                     
      rightMotorA.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);                 
      rightMotorB.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);}
    if (Controller1.ButtonR1.pressing()) {
      if (!driveLatch) {
        driveToggle = !driveToggle;
        driveLatch = true;
      } else {driveLatch = false;}}
    ///////////////////////////////////////// Driver Controls (End) //////////////////////////////////////
    
    ///////////////////////////////////////// Flywheel Controls (Start) ////////////////////////////////////
    if (Controller1.ButtonL2.pressing()) {
      flywheel.spin(forward, (output / 50), volt);
    }
    else if (Controller1.ButtonL1.pressing()) {
      flywheel.spin(forward, 0, volt);
    }
    ///////////////////////////////////////// Flywheel Controls (End) //////////////////////////////////////

    ///////////////////////////////////////// Intake Controls (Start) ////////////////////////////////////
    if (intakeToggle) {
      intake.spin(forward);
    } else {intake.stop();}
    if (Controller1.ButtonRight.pressing()) {
      if (!intakeLatch) {
        intakeToggle = !intakeToggle;
        intakeLatch = true;
      } else {intakeLatch = false;}}
    if (Controller1.ButtonDown.pressing()) {
      intake.spin(reverse);}
    ///////////////////////////////////////// Intake Controls (End) ////////////////////////////////////

    ///////////////////////////////////////// Roller Controls (Start) //////////////////////////////////
    if (rollerToggle) {
      roller.spin(forward);
    } else {roller.stop();}
    if (Controller1.ButtonY.pressing()) {
      if (!rollerLatch) {
        rollerToggle = !rollerToggle;
        rollerLatch = true;
      } else {rollerLatch = false;}}
    if (Controller1.ButtonB.pressing()) {
      roller.spin(reverse);}
    ///////////////////////////////////////// Roller Controls (End) ////////////////////////////////////

    ////////////////////////////////////////  Indexer Controls (Start) /////////////////////////////////
    if (Controller1.ButtonR2.pressing()) {
    indexer.set(true);}
    else {indexer.set(false);}
    ///////////////////////////////////////// Indexer Controls (End) ///////////////////////////////////

    ////////////////////////////////////////  Endgame Controls (Start) /////////////////////////////////
    if (Controller1.ButtonA.pressing()) {
      endgame.set(true);
    }
    ////////////////////////////////////////  Indexer Controls (End) ///////////////////////////////////

    wait(10, msec); // Sleep the task for a short amount of time to
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
