#pragma once
#include "main.h"

extern sylib::SpeedControllerInfo flyController;
extern sylib::Motor fly;
extern double flyPower;
extern bool flySpinning;
extern void setFW (double power);
extern void setTunedFW (double power);
extern void flywheel (void);