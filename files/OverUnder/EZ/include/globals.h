#pragma once
#include "globals.h"
#include "main.h"

// controller
extern pros::Controller master;

// chassis
extern void chassisControl(void);
extern Drive chassis;

// autons
extern void oneTriball(void);
extern void nearThreeTriball(void);
extern void farThreeTriball(void);
extern void partialAWP(void);
extern void farFiveTriball(void);

// kicker
extern void kickerControl(void);
extern void kickMacro(void);
extern Motor kicker;
extern Optical optical;

// intake
extern void intakeControl(void);
extern MotorGroup intake;

// lift
extern void liftControl(void);
extern Motor lift;

// wings
extern void wingsControl(void);
extern ADIDigitalOut bigWings;
extern ADIDigitalOut miniWing;
extern ADIDigitalOut beach;

// rgb
extern void rgb(void);
