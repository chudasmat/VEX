#pragma once
#include "main.h"

// controller
extern pros::Controller master;

// chassis
extern void chassisControl(void);

// kicker
extern void kickerControl(void);

// intake
extern void intakeControl(void);

// lift
extern void liftControl(void);

// wings
extern void wingsControl(void);

// climber
extern void climberControl(void);

// rgb
extern void rgb(void);