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
// gearDrive            motor_group   1, 2            
// bottomChainDrive     motor_group   3, 4            
// topChainDrive        motor_group   5, 6            
// fourBar              motor         7               
// ringIntake           motor         8               
// Controller1          controller                    
// fourBarClamp         digital_out   A               
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
  FILE* rerun = fopen("rerun.txt", "w");
	fprintf(rerun, "");
	fclose(rerun);

  while (1) {
    wait(20, msec);
    int LFspeed = leftMotorA.velocity(percent);
    int LMspeed = leftMotorB.velocity(percent);
    int LRspeed = leftMotorC.velocity(percent);
    int RFspeed = rightMotorA.velocity(percent);
    int RMspeed = rightMotorB.velocity(percent);
    int RRspeed = rightMotorC.velocity(percent);
    int fourBarspeed = fourBar.velocity(percent);

    FILE* rerun = fopen("rerun.txt", "a");
		fprintf(rerun, "leftMotorA.spin(%i, percent); \n", LFspeed);
		fprintf(rerun, "leftMotorB.spin(%i, percent); \n", LMspeed);
		fprintf(rerun, "leftMotorC.spin(%i, percent); \n", LRspeed);
		fprintf(rerun, "rightMotorA.spin(%i, percent); \n", RFspeed);
    fprintf(rerun, "rightMotorB.spin(%i, percent); \n", RMspeed);
    fprintf(rerun, "rightMotorC.spin(%i, percent); \n", RRspeed);
		fprintf(rerun, "fourBar.spin(%i, percent); \n", fourBarspeed);
 
    int timeNew = *(int*) timer().system;
    int timeOld = *(int*) timer().system;
    int deltaTime = timeNew - timeOld; 

    fprintf(rerun, "delay(%i); \n", deltaTime);

    fclose(rerun);
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
