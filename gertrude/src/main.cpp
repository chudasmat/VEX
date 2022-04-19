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
// LeftDriveSmart       motor_group   1, 2, 3            
// RightDriveSmart      motor_group   4, 5, 6                        
// fourBar              motor         21               
// ringIntake           motor         8               
// Controller1          controller                    
// lockingClamp         pneumatics    A     
// rearMech             pneumatics    B
// goalCover            pneumatics    C          
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <iostream>
#include <fstream>

using namespace vex;
using std::cout; using std::ofstream;
using std::endl; using std::string;

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

// Autonomous Settings //
int desiredValue = 0;
int desiredTurnValue = 0;

// PID Values //
double kP = 0.0;         /////////////////////
double kI = 0.0;     //        Requires
double kD = 0.0;     //         Proper        
double turnkP = 0.0; //         Tuning 
double turnkD = 0.0;     /////////////////////

int error;           // sensorValue - desiredValue (Position)
int prevError = 0;   // Position 20ms ago
int derivative;      // error - prevError (Speed)

int turnError;           // sensorValue - desiredValue (Position)
int turnPrevError = 0;   // Position 20ms ago
int turnDerivative;      // error - prevError (Speed)

bool resetEncoders = false;

bool enableDrivePID = true;

int drivePID() {
  
  while(enableDrivePID) {
    
    if (resetEncoders) {
      resetEncoders = false;
      leftFront.resetPosition();
      leftMid.resetPosition();
      leftRear.resetPosition();
      rightFront.resetPosition();
      rightMid.resetPosition();
      rightRear.resetPosition();
    }
    
    int leftFrontPos = leftFront.position(degrees);          /////////////////////////
    int leftMidPos = leftMid.position(degrees);
    int leftRearPos = leftRear.position(degrees);        //      Fetch positions   
    int rightFrontPos = rightFront.position(degrees);    //    of drivetrain motors
    int rightMidPos = rightMid.position(degrees);
    int rightRearPos = rightRear.position(degrees);          /////////////////////////

    /////////////////////////////////////////////////////// Lateral Movement PID /////////////////////////////////////////////////////////////
    int avgPos = (leftFrontPos + leftMidPos + leftRearPos + rightFrontPos + rightMidPos + rightRearPos) / 6;  // Calculates average position of motors

    error = avgPos - desiredValue;     // Potential
    derivative = error - prevError;    // Derivative

    double lateralMotorPower = error * kP + derivative * kD;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////////////////// Turning Movement PID /////////////////////////////////////////////////////////////
    int turnAvgPos = (leftFrontPos + leftMidPos + leftRearPos + rightFrontPos + rightMidPos + rightRearPos) / 6;  // Calculates average position of motors

    turnError = turnAvgPos - desiredTurnValue;    // Potential
    turnDerivative = turnError - turnPrevError;   // Derivative

    double turnMotorPower = turnError * turnkP + turnDerivative * turnkD;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    leftFront.spin(vex::directionType::fwd, lateralMotorPower + turnMotorPower, voltageUnits::volt); 
    leftMid.spin(vex::directionType::fwd, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    leftRear.spin(vex::directionType::fwd, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    rightFront.spin(vex::directionType::fwd, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    rightMid.spin(vex::directionType::fwd, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    rightRear.spin(vex::directionType::fwd, lateralMotorPower - turnMotorPower, voltageUnits::volt);

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
  vex::task piddy(drivePID);
  

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
  FILE* rerun = fopen("rerun.txt", "w");
	fprintf(rerun, "");
	fclose(rerun);

  while (1) {
    
    leftFront.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct); //(Axis3+Axis4)/2                Left Side
    leftMid.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct); //(Axis3+Axis4)/2              Tank Control
    leftRear.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct); //(Axis3+Axis4)/2              Left Stick
    
    rightFront.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);//(Axis3-Axis4)/2                 Right Side
    rightMid.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);//(Axis3-Axis4)/2               Tank Control
    rightRear.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);//(Axis3-Axis4)/2               Right Stick
    
    int LFspeed = leftFront.velocity(percent);
    int LMspeed = leftMid.velocity(percent);
    int LRspeed = leftRear.velocity(percent);
    int RFspeed = rightFront.velocity(percent);
    int RMspeed = rightMid.velocity(percent);
    int RRspeed = rightRear.velocity(percent);
    int fourBarspeed = fourBar.velocity(percent);

    FILE* rerun = fopen("rerun.txt", "a");
		fprintf(rerun, "leftFront.spin(%i, percent); \n", LFspeed);
		fprintf(rerun, "leftMid.spin(%i, percent); \n", LMspeed);
		fprintf(rerun, "leftRear.spin(%i, percent); \n", LRspeed);
		fprintf(rerun, "rightFront.spin(%i, percent); \n", RFspeed);
    fprintf(rerun, "rightMid.spin(%i, percent); \n", RMspeed);
    fprintf(rerun, "rightRear.spin(%i, percent); \n", RRspeed);
		fprintf(rerun, "fourBar.spin(%i, percent); \n", fourBarspeed);
 
    int timeNew = vex::timer::system();
    int timeOld = vex::timer::system();
    int deltaTime = timeNew - timeOld; 

    fprintf(rerun, "delay(%i); \n", deltaTime);

    fclose(rerun);

    wait(20, msec);
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
