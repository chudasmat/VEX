#pragma once
#include "main.h"

extern bool flySpinning;
extern int fwSpeeds[4];
extern int fwIndex;
extern sylib::SpeedControllerInfo flyController;
extern sylib::Motor fly;
extern void setFW (int power);
extern void flywheel (void);