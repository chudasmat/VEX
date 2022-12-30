#pragma once
#include "main.h"

extern bool rollerSpinning;
extern bool colour;
extern bool teamCol;
extern double prox;
extern double hoo;
extern pros::Motor roller;
extern pros::Optical optical;
extern int getColour();
extern void autoRoll(void);
extern void rollerControl(void);
