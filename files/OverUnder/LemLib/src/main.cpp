#include "main.h"
#include "globals.h"
Controller master(CONTROLLER_MASTER);

void initialize() {
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
//	farFiveTriball();
//	nearOneTriball();
//	farOneTriball();
//	nearThreeTriball();
//	farThreeTriball();
//	partialAWP();
}

void opcontrol() {
	sylib::initialize(); rgb();
	kaboom.set_value(0);
	while (1) {
		chassisControl();
		kickerControl();
		intakeControl();
		liftControl();
		wingsControl();
		pros::delay(10);
		}
	}

