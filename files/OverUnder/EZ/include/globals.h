#pragma once
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
extern MotorGroup lift;

// wings
extern void wingsControl(void);
extern ADIDigitalOut bigWings;
extern ADIDigitalOut miniWing;

// climber
extern void climberControl(void);
extern Motor roll;
extern ADIDigitalOut wheelExtend;

// rgb
extern void rgb(void);