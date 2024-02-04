#pragma once
#include "globals.h"
#include "main.h"
#include "pros/motors.hpp"

// controller
extern pros::Controller master;

// chassis
extern void chassisControl(void);
extern Drive chassis;

// autons
extern void nearOneTriball(void);
extern void farOneTriball();
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
extern Motor intake;

// lift
extern void liftControl(void);
extern MotorGroup lift;
extern ADIDigitalOut liftLock;

// wings
extern void wingsControl(void);
extern ADIDigitalOut bigWings;
extern ADIDigitalOut miniWing;
extern ADIDigitalOut beach;

// rgb
extern void rgb(void);
