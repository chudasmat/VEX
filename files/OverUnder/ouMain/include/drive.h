#pragma once
#include "main.h"

extern pros::Controller master;

extern pros::Motor leftA;
extern pros::Motor leftB;
extern pros::Motor leftC;
extern pros::Motor rightA;
extern pros::Motor rightB;
extern pros::Motor rightC;
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;
extern lemlib::Chassis chassis;
extern pros::Imu inertial;

extern void drive (void);