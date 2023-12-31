#include "main.h"

void initialize() {
    sylib::initialize();
	// static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while (true) {
		std::uint32_t now = millis();
		chassisControl();
		intakeControl();
		pneumatics();
		Task::delay_until(&now, 10);}
}
