/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       James                                                     */
/*    Created:      Thu Mar 21 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "gifclass.h"
competition Competition;
using namespace vex;

// Toggle Variables //
bool intakeSpinning = false;
bool rollerSpinning = false;
bool flySpinning = false;
bool driveInvert = false;

// Driver + Team Variables //
bool emilian = false;
bool blueAlliance = false;

/////////////////////////////////////////////////////////////////////////////// Take Back Half (Start) ///////////////////////////////////////////////////////////////////////
int tbhError;
int tbhGoal = 500;
int tbhPrevError;
int tbhOutput;
int tbh;
double tbhGain = 0.003;

bool resetFlyEncoders = false;
bool enableTBH = false;

int TBH() {
  while (enableTBH) {
    if (resetFlyEncoders) {
      resetFlyEncoders = false;
      flywheel.resetPosition();}
    
    double currentSpeed = (flywheelMotorA.velocity(rpm) + flywheelMotorB.velocity(rpm)) / 2;      // Fetch motor speeds
    tbhError = tbhGoal - currentSpeed;                                                            // Calculate the difference between desired and current speeds
    if (tbhOutput + (tbhGain * tbhError) < (tbhGoal + 20)) {                                      // Checks if integration is less than desired speed + margin 
      tbhOutput = tbhOutput + (tbhGain * tbhError);}                                              // Integrates into output if condition is met
    if (signbit(tbhError) != signbit(tbhPrevError)) {                                             // Checks if errors are zero-crossing
      tbhOutput = 0.5 * (tbhOutput + tbh);                                                        // If they add then "Take Back Half"
      tbh = tbhOutput;}                                                                           // Update Take Back Half variable
    tbhPrevError = tbhError;                                                                      // Saves the previous error
    vex::task::sleep(10);                                                                         // Wait for 10ms to save CPU resources
  }
  return 1;
}
/////////////////////////////////////////////////////////////////////////////// Take Back Half (End) ///////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////// Positional PID (Start) ////////////////////////////////////////////////////////////////////
// Autonomous Settings //
int desiredValue = 200;    // Straight-Line Value
int desiredTurnValue = 0;  // Spin Value

// PID Values //
double kP = 0.0;        //////////////////////
double kI = 0.0;        //                  //
double kD = 0.0;        //      Requires    //
double turnkP = 0.0;    //      Tuning      //
double turnkI = 0.0;    //                  //
double turnkD = 0.0;    //////////////////////

int pidError;           // sensorValue - desiredValue (Position)
int pidPrevError = 0;   // Position 20ms ago
int derivative;         // pidError - pidPrevError (Speed)
int totalError = 0;     // totalError = totalError + pidError

int turnError;          // sensorValue - desiredValue (Position)
int turnPrevError = 0;  // Position 20ms ago
int turnDerivative;     // pidError - pidPrevError (Speed)
int turnTotalError = 0; // totalError = totalError + pidError

bool resetEncoders = false;
bool enableDrivePID = true;

int drivePID() {
  
  while (enableDrivePID) {
    
    if (resetEncoders) {
      resetEncoders = false;
      leftMotorA.resetPosition();
      leftMotorB.resetPosition();
      rightMotorA.resetPosition();
      rightMotorB.resetPosition();
    }
    
    int leftAPos = leftMotorA.position(degrees);    //////////////////////////////
    int rightAPos = rightMotorA.position(degrees);  //    Fetches position      //
    int rightBPos = rightMotorB.position(degrees);  //    of drivetrain motors  // 
    int leftBPos = leftMotorB.position(degrees);    /////////////////////////////

    /////////////////////////////////////////////////////// Lateral Movement PID /////////////////////////////////////////////////////////////
    int avgPos = (leftAPos + leftBPos + rightAPos + rightBPos ) / 4;  // Calculates average position of motors

    pidError = avgPos - desiredValue;     // Potential
    derivative = pidError - pidPrevError;    // Derivative
    totalError += pidError;               // Integral

    double lateralMotorPower = (pidError * kP) + (derivative * kD) + (totalError * kI);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////////////////// Turning Movement PID /////////////////////////////////////////////////////////////
    int turnAvgPos = (leftAPos - leftBPos - rightAPos - rightBPos) / 4;  // Calculates average position of motors

    turnError = turnAvgPos - desiredTurnValue;    // Potential
    turnDerivative = turnError - turnPrevError;   // Derivative
    turnTotalError += turnError;                  // Integral  (Include to drivetrain PID with testing, otherwise use PD controller instead)

    double turnMotorPower = (turnError * turnkP) + (turnDerivative * turnkD) + (turnTotalError * turnkI);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    leftMotorA.spin(vex::directionType::fwd, lateralMotorPower + turnMotorPower, voltageUnits::volt); 
    leftMotorB.spin(vex::directionType::fwd, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    rightMotorA.spin(vex::directionType::fwd, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    rightMotorB.spin(vex::directionType::fwd, lateralMotorPower - turnMotorPower, voltageUnits::volt);
//////////////////////////////////////////////////////////////////////////////// Positional PID (End) ////////////////////////////////////////////////////////////////////

    /* "pidPrevError" is set to "pidError" and the program waits 20ms before running loop, when pidError is fetched again, 
        meaning that "pidPrevError" is set to the value "pidError" was 20ms ago. Same logic applies to "turnPrevError" and "turnError"  */
    pidPrevError = pidError;
    turnPrevError = turnError;
    vex::task::sleep(10);}
    return 1;}
    
//////////////////////// Brain Slideshow (Start) ////////////////////
int slideshow() {
  while (true) {
    Brain.Screen.drawImageFromFile("alexx.png", 0, 0);
    vex::task::sleep(10000);
    Brain.Screen.clearScreen();
    Brain.Screen.drawImageFromFile("dairytrishy.png", 0, 0);
    vex::task::sleep(10000);
    Brain.Screen.clearScreen();
    Brain.Screen.drawImageFromFile("emiliano.png", 0, 0);
    vex::task::sleep(10000);
    Brain.Screen.clearScreen();
    Brain.Screen.drawImageFromFile("scaryalex.png", 0, 0);
    vex::task::sleep(10000);
    Brain.Screen.clearScreen();
    Brain.Screen.drawImageFromFile("daroos.png", 0, 0);
    vex::task::sleep(10000);
    Brain.Screen.clearScreen();
    vex::task::sleep(10);}
  return 1;}
//////////////////////// Brain Slideshow (End) //////////////////////


/////////////// Driver + Aliiance Switching (Start) ///////////////
void driverToggle() {
  emilian = !emilian;
  if (emilian) {
    Controller1.Screen.setCursor(0, 0);
    Controller1.Screen.print("Emilian");  
  }
  else {
    Controller1.Screen.setCursor(0, 0);
    Controller1.Screen.print("Trishan");
  }
}

void allianceToggle() {
  blueAlliance = !blueAlliance;
  if (blueAlliance) {
    Controller1.Screen.setCursor(1, 0);
    Controller1.Screen.print("Blue");
  }
  else {
    Controller1.Screen.setCursor(1, 0);
    Controller1.Screen.print("Red");
  }
}
/////////////// Driver + Aliiance Switching (End) ///////////////

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
  // Brain.Screen.drawImageFromFile("alexx.png", 0, 0);    
  vex::task TBH_(TBH);
  vex::task pics(slideshow);

  /////////////////// Team + Driver Switching (Start) ///////////////////////
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(0, 0);
  Controller1.Screen.print("Trishan");
  Controller1.Screen.setCursor(1, 0);
  Controller1.Screen.print("Red");

  Controller1.ButtonL2.pressed(allianceToggle);
  Controller1.ButtonR2.pressed(driverToggle);
  ///////////////////// Team + Driver Switching (End) /////////////////////////

}

//////////  Toggle Functions (Start) ///////////
void intakeToggle(void) {
  if (intakeSpinning) {
    intake.stop();}
  else {
    intake.spin(forward, 12, volt);}
  intakeSpinning = !intakeSpinning;}

void rollerToggle(void) {
  if (rollerSpinning) {
    roller.stop();}
  else {
    roller.spin(forward, 10, volt);}
  rollerSpinning = !rollerSpinning;}

void flyToggle(void) {
  if (flySpinning) {
    flywheel.stop();}
  else {
    flywheel.spin(forward, tbhOutput / 50, volt);}
  flySpinning = !flySpinning;}

void driveToggle(void) {
  if (!driveInvert) {
    driveInvert = true;
    Controller1.Screen.setCursor(3, 0);
    Controller1.Screen.clearLine();
    Controller1.Screen.print("Orientation: Intake");}
  else if (driveInvert) {
    driveInvert = false;
    Controller1.Screen.setCursor(3, 0);
    Controller1.Screen.clearLine();
    Controller1.Screen.print("Orientation: Flywheel");}}
  
  // driveInvert = !driveInvert;}
/////////////// Toggle Functions (End) //////////////

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
  Controller1.Screen.clearScreen();

  Drivetrain.drive(reverse);
  roller.spinFor(reverse, 0.75, sec);
  vexDelay(750);
  Drivetrain.stop();
  flywheel.spin(forward, 12, volt);
  vexDelay(1000);
  indexer.set(true);
  vexDelay(1000);
  indexer.set(false);
  vexDelay(1000);
  indexer.set(true);
  vexDelay(1000);
  indexer.set(false);
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
  
  Controller1.Screen.setCursor(3, 0);
  Controller1.Screen.print("Orientation: Flywheel");
  
  resetEncoders = true;
  enableTBH = true;
  
  if (!emilian) {
    Controller1.ButtonRight.pressed(intakeToggle);
    Controller1.ButtonY.pressed(rollerToggle);
    Controller1.ButtonL2.pressed(flyToggle);
    Controller1.ButtonL1.pressed(driveToggle);  
  }
  else {
    // whatever emilian wants
  }



  while (1) {
    ///////////////////////////////////////// Driver Controls (Start) ////////////////////////////////////
    if (!driveInvert) {
      leftMotorA.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::voltageUnits::volt);                 
      leftMotorB.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::voltageUnits::volt);                     
      rightMotorA.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::voltageUnits::volt);                 
      rightMotorB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::voltageUnits::volt);
    } else {
      leftMotorA.spin(vex::directionType::fwd, -(Controller1.Axis3.value()), vex::voltageUnits::volt);                 
      leftMotorB.spin(vex::directionType::fwd, -(Controller1.Axis3.value()), vex::voltageUnits::volt);                       
      rightMotorA.spin(vex::directionType::fwd, -(Controller1.Axis2.value()), vex::voltageUnits::volt);                 
      rightMotorB.spin(vex::directionType::fwd, -(Controller1.Axis2.value()), vex::voltageUnits::volt);}
    ///////////////////////////////////////// Driver Controls (End) //////////////////////////////////////

    if (!emilian) {
      ///////////////////////////////////////// Intake Controls (Start) ////////////////////////////////////
      if (Controller1.ButtonDown.pressing()){
        intakeSpinning = true;
        intake.spin(reverse, 12, volt);}
      ///////////////////////////////////////// Intake Controls (End) ////////////////////////////////////


      ///////////////////////////////////////// Roller Controls (Start) //////////////////////////////////
      if (Controller1.ButtonB.pressing()){
        rollerSpinning = true;
        roller.spin(reverse, 12, volt);}
      ///////////////////////////////////////// Roller Controls (End) ////////////////////////////////////


      ////////////////////////////////////////  Indexer Controls (Start) /////////////////////////////////
      if (Controller1.ButtonR2.pressing()) {
        indexer.set(true);}
      else {indexer.set(false);}
      ///////////////////////////////////////// Indexer Controls (End) ///////////////////////////////////
      

      ////////////////////////////////////////  Endgame Controls (Start) /////////////////////////////////
      if (Controller1.ButtonA.pressing()) {
        endgame.set(true);}
      ////////////////////////////////////////  Endgame Controls (End) ///////////////////////////////////
    }
    else {
      /////////////////////////////////////// EMILIAN SPECIAL CODE //////////////////////////////////////////////////////////

      //////////////////////////////////////////////// Flywheel Controls (Start) /////////////////////////////////////////////////
      if (Controller1.ButtonL2.pressing()) {
        flywheel.spin(forward, tbhOutput / 50, volt);
      }
      else if (Controller1.ButtonL1.pressing()) {
        flywheel.spin(forward, 0, volt);
      }
      //////////////////////////////////////////////// Flywheel Controls (End) /////////////////////////////////////////////////




      //////////////////////////////////////////////// Intake Controls (Start) /////////////////////////////////////////////////
      if (Controller1.ButtonR1.pressing()) {
        intake.stop();
      }
      else if (Controller1.ButtonR2.pressing()) {
        intake.spin(forward, 100, pct);
      }
      //////////////////////////////////////////////// Intake Controls (End) /////////////////////////////////////////////////




      //////////////////////////////////////////////// Indexer Controls (Start) /////////////////////////////////////////////////
      if (Controller1.ButtonX.pressing()) {
        indexer.set(true);
      }
      else {
        indexer.set(false);
      }
      //////////////////////////////////////////////// Indexer Controls (End) /////////////////////////////////////////////////




      //////////////////////////////////////////////// Roller Controls (Start) /////////////////////////////////////////////////
      if (Controller1.ButtonY.pressing()) {
        roller.spin(reverse, 65, pct);
      }
      else if (Controller1.ButtonB.pressing()) {
        roller.stop();
      }

      // Note: This is for automatic roller controls, but this can be incosistent, so is not being used right now

      //if ((opticalSensor.hue() <= 90) && (opticalSensor.hue() >= 0) && (opticalSensor.isNearObject())) {
        //rollerSpinningDone = false;
        //roller.spin(reverse, 100, pct);
      //}
      //else if ((opticalSensor.hue() <= 255) && (opticalSensor.hue() >= 120) && (opticalSensor.isNearObject())) {
        //if (rollerSpinningDone == false) {
          //roller.setVelocity(100, pct);
          //roller.spinFor(reverse, 0.5, sec);
          //roller.stop();
          //rollerSpinningDone = true;
        //}
      //}

      //////////////////////////////////////////////// Roller Controls (End) /////////////////////////////////////////////////

    


      //////////////////////////////////////////////// Expansion Controls (Start) /////////////////////////////////////////////////

      if (Controller1.ButtonA.pressing()) {
        endgame.set(true);
      }
      //////////////////////////////////////////////// Expansion Controls (End) /////////////////////////////////////////////////

    }      
    }

    wait(10, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  vex::Gif gif("slideshow.gif", 0, 0 );
  
  while(1) {
    Brain.Screen.printAt( 5, 230, "frame %3d", gif.getFrameIndex() );
    this_thread::sleep_for(10);
  }

  while (true) {
    wait(100, msec);
  }
}
