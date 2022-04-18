using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftFront;
extern motor leftMid;
extern motor leftRear;
extern motor rightFront;
extern motor rightMid;
extern motor rightRear;
extern drivetrain Drivetrain;
extern motor fourBar;
extern motor ringIntake;
extern pneumatics lockingClamp;
extern pneumatics rearMechA;
extern pneumatics rearMechB;
extern pneumatics goalCover;
extern controller Controller1;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );