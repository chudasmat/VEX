#include "main.h"
#include "globals.h"
Controller master(CONTROLLER_MASTER);

void initialize() {
	chassis.initialize();
	chassis.set_curve_default(3.5, 3.5);
	sylib::initialize();
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	oneTriball();
}

void opcontrol() {
	chassis.set_drive_brake(E_MOTOR_BRAKE_COAST);
	while (true) {
		chassisControl();
		kickerControl();
		intakeControl();
		liftControl();
		wingsControl();
		pros::delay(10);
	}
}
