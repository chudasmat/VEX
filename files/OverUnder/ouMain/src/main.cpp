#include "main.h"
Controller master(CONTROLLER_MASTER);

void initialize() {
	sylib::initialize();
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while (1) {
		chassisControl();
		kickerControl();
		intakeControl();
		liftControl();
		wingsControl();
		pros::delay(10);
	}
}
