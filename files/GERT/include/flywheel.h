#pragma once
#include "main.h"

extern bool flySpinning;
extern std::vector <int> fwSpeeds;
extern int fwIndex;
extern sylib::SpeedControllerInfo flyController;
extern sylib::Motor fly;
extern void setFW (int power);
extern void flywheel (void);