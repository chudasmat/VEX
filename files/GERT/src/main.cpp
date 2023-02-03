#include "main.h"
#include "ARMS/config.h"

int desiredVal = 3000;

void initialize() {
	sylib::initialize();
	arms::init();
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
}

void disabled() {}


void competition_initialize() {}


void autonomous() {
	experimentalAuton();
}


void opcontrol() {
	lip.set_value(true);
	lipBool = true;
	flyPower = 8;

	Task drive_(drive);
	Task fly_(flywheel);
	Task intake_(intakeControl);
	Task pneumatics_(pneumatics);

	while (true) {
		printf("%d,%d,%f,%f,%f,%d\n", sylib::millis(), desiredVal, fly.get_velocity(), fly.get_velocity_error(), fly.get_acceleration(), fly.get_efficiency());
		delay(10);
	}
}
