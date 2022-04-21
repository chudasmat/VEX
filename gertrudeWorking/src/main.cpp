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
// fourBarClamp         pneumatics    A
// rearMech             pneumatics  ` B
// goalCover            pneumatics    C              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;


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
  lockingClamp.open();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

bool lockingActivate = false;
bool rearActivate = false;
bool coverActivate = false;
bool ringactivate = false;
bool Controller1LeftShoulderControlMotorsStopped = true;

// Autonomous Settings //
int desiredValue = 200;
int desiredTurnValue = 0;

// PID Values //
double kP = 0.0;         /////////////////////
double kI = 0.0;         
double kD = 0.0;     //        Requires
double turnkP = 0.0; //         Tuning 
double turnkI = 0.0;
double turnkD = 0.0;     /////////////////////

int error;           // sensorValue - desiredValue (Position)
int prevError = 0;   // Position 20ms ago
int derivative;      // error - prevError (Speed)
int totalError = 0;  // totalError = totalError + error

int turnError;           // sensorValue - desiredValue (Position)
int turnPrevError = 0;   // Position 20ms ago
int turnDerivative;      // error - prevError (Speed)
int turnTotalError = 0;  // totalError = totalError + error

bool resetEncoders = false;

bool enableDrivePID = true;

int drivePID() {
  
  while(enableDrivePID) {
    
    if (resetEncoders) {
      resetEncoders = false;
      gearA.resetPosition();
      gearB.resetPosition();
      chainA1.resetPosition();
      chainA2.resetPosition();
      chainB1.resetPosition();
      chainB2.resetPosition();
    }
    
    int gearAPos = gearA.position(degrees);          /////////////////////////
    int gearBPos = gearB.position(degrees);
    int chainA1Pos = chainA1.position(degrees); //     Fetches position   
    int chainA2Pos = chainA2.position(degrees); //     of drivetrain motors
    int chainB1Pos = chainB1.position(degrees);
    int chainB2Pos = chainB2.position(degrees);      /////////////////////////

    /////////////////////////////////////////////////////// Lateral Movement PID /////////////////////////////////////////////////////////////
    int avgPos = (gearAPos + gearBPos + chainA1Pos + chainA2Pos + chainB1Pos + chainB2Pos) / 6;  // Calculates average position of motors

    error = avgPos - desiredValue;     // Potential
    derivative = error - prevError;    // Derivative
    totalError += error;               // Integral

    double lateralMotorPower = error * kP + derivative * kD + totalError * kI;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////////////////// Turning Movement PID /////////////////////////////////////////////////////////////
    int turnAvgPos = (gearAPos - gearBPos - chainA1Pos - chainA2Pos - chainB1Pos - chainB2Pos) / 6;  // Calculates average position of motors

    turnError = turnAvgPos - desiredTurnValue;    // Potential
    turnDerivative = turnError - turnPrevError;   // Derivative
    turnTotalError += turnError;                  // Integral  (Include to drivetrain PID with testing, otherwise use PD controller instead)

    double turnMotorPower = turnError * turnkP + turnDerivative * turnkD + turnTotalError * turnkI;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    gearA.spin(vex::directionType::fwd, lateralMotorPower + turnMotorPower, voltageUnits::volt); 
    chainA1.spin(vex::directionType::fwd, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    chainA2.spin(vex::directionType::fwd, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    gearB.spin(vex::directionType::fwd, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    chainB1.spin(vex::directionType::fwd, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    chainB2.spin(vex::directionType::fwd, lateralMotorPower + turnMotorPower, voltageUnits::volt);

    /* "prevError" is set to "error" and the program waits 20ms before running loop, when error is fetched again, 
        meaning that "prevError" is set to the value "error" was 20ms ago. Same logic applies to "turnPrevError" and "turnError"  */
    prevError = error;
    turnPrevError = turnError;
    vex::task::sleep(20);

  }
  
  return 1;
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
  vex::task PIDDY(drivePID);

  resetEncoders = true;
  desiredValue = 2000;
  desiredTurnValue = 10;
  vex::task::sleep(1000);

  /* Reset encoders after every action, by setting "resetEncoders" to true.
     Sleep after every action */

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
  
  enableDrivePID = false;

  while (1) {
    /////////////////////////////// Tank Controls (Start) /////////////////////////////////////
    gearA.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);                 
    chainA1.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);               
    chainA2.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);               
    
    gearB.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);                 
    chainB1.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);               
    chainB2.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);               
    ////////////////////////////// Tank Controls (End) ////////////////////////////////////////

    ////////////////////////////// Ring Intake (Start) ////////////////////////////
    if (Controller1.ButtonR2.pressing() && ringactivate == false) {
      ringactivate = true;
} 
    else if (Controller1.ButtonR2.pressing() && ringactivate == true) {
      ringactivate = false;}
    if (ringactivate == true) {
      ringIntake.setVelocity(100, pct);
      ringIntake.spin(forward);
    } else if (ringactivate == false) {
      ringIntake.setVelocity(0, percent);}
    ////////////////////////////// Ring Intake (End) ////////////////////////////

    ///////////////////////////// Locking Clamp (Start) ///////////////////////////
    if (Controller1.ButtonRight.pressing() && lockingActivate == false) {
      lockingActivate = true;} 
    else if (Controller1.ButtonRight.pressing() && lockingActivate == true) {
      lockingActivate = false;}
    if (lockingActivate == true) {
      lockingClamp.open();
    } else if (lockingActivate == false) {
      lockingClamp.close();}
    ///////////////////////////// Locking Clamp (End) ///////////////////////////

    ////////////////////////// Rear Clamp / Tilter (Start) //////////////////////
    if (Controller1.ButtonY.pressing() && rearActivate == false) {
      rearActivate = true;} 
    else if (Controller1.ButtonY.pressing() && rearActivate == true) {
      rearActivate = false;}
    if (rearActivate == true) {
      rearMech.close();
    } else if (rearActivate == false) {
      rearMech.open();}
    ////////////////////////// Rear Clamp / Tilter (End) ////////////////////////
    
    ////////////////////////// Four Bar Lift (Start) ///////////////////////////
    if (Controller1.ButtonL1.pressing()) {
      fourBar.setVelocity(100, percent);
      fourBar.spin(forward);
      Controller1LeftShoulderControlMotorsStopped = false;
    } else if (Controller1.ButtonL2.pressing()) {
      fourBar.spin(reverse);
      Controller1LeftShoulderControlMotorsStopped = false;
    } else if (!Controller1LeftShoulderControlMotorsStopped) {
      fourBar.stop();
      // set toggle so motor isn't always told to stop when buttons released                              
      Controller1LeftShoulderControlMotorsStopped = true;}
    ////////////////////////// Four Bar Lift (End) ////////////////////////////

    /////////////////////////// Goal Cover (Start) ////////////////////////////
    if (Controller1.ButtonA.pressing() && coverActivate == false) {
      coverActivate = true;} 
    else if (Controller1.ButtonA.pressing() && coverActivate == true) {
      coverActivate = false;}
    if (coverActivate == true) {
      goalCover.open();
    } else if (coverActivate == false) {
      goalCover.close();}

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
