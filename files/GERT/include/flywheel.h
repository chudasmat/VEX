#pragma once
#include "main.h"

extern bool flySpinning;

extern sylib::SpeedControllerInfo flyController;
extern sylib::Motor fly;
extern void setFW (int power);
extern void flywheel (void);
// extern int fwSpeeds[3];
// extern int fwIndex;
extern int fwPower;