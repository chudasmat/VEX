#ifndef ODOMETRY_HPP
#define ODOMETRY_HPP

#include "api.h"

extern pros::ADIEncoder leftEnc;
extern pros::ADIEncoder rightEnc;
extern pros::ADIEncoder midEnc;

extern void updatePosition();
extern float getX();
extern float getY();
extern float getAngle();
extern float getAngleDegrees();
extern float modulo(float a, float b);


#endif