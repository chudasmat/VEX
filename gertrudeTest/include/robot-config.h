using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;
extern drivetrain Drivetrain;
extern motor fourBar;
extern motor ringIntake;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );