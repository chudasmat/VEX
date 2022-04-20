using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor gearA;
extern motor gearB;
extern motor chainA1;
extern motor chainA2;
extern motor chainB1;
extern motor chainB2;
extern motor_group gears;
extern motor_group chain;
extern motor fourBar;
extern motor ringIntake;
extern controller Controller1;
extern pneumatics fourBarClamp;
extern pneumatics rearMech;
extern pneumatics goalCover;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );