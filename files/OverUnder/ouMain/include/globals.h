#pragma once
#include "main.h"

// controller
extern pros::Controller master;

// chassis
extern void chassisControl(void);

// kicker
extern void kickerControl(void);
extern void kickMacro(void);
extern Motor kicker;

// intake
extern void intakeControl(void);
extern Motor intake;

// lift
extern void liftControl(void);
extern ADIDigitalOut lift;

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