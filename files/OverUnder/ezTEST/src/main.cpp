#include "main.h"
Controller master(CONTROLLER_MASTER);

void initialize() {
	chassis.initialize();
	sylib::initialize();
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
	chassis.set_curve_default(3.5, 3.5);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	master.print(0, 0, "COAST - PTO DRIVE");
	while (true) {
		chassisControl();
		intakeControl();
		wingsControl();
		pros::delay(10);
	}
}
