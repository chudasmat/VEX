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
extern controller Controller1;
extern pneumatics fourBarClamp;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );