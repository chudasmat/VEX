#include "main.h"
#include "controller.h"
#include "pros/rtos.hpp"

// L2 = RED
// R2 = BLUE

void disabled() {}
void competition_initialize() {}

void initialize() {
	sylib::initialize();
	//okapiController.setText(0, 0, "SELECT COLOUR");
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
}

void autonomous() {
	//okapiController.clearLine(0);
	chassisDrive->setState({0_in, 0_in, 0_deg});
	rollerAuton();
}

void opcontrol() {
	lip.set_value(true);
	lipToggle = true;
	fwPower = 2400;

	Task chassisControl_(chassisControl);
	Task flywheel_(flywheel);
	Task intakeControl_(intakeControl);
	Task pneumatics_(pneumatics);
//	Task printer_(printer);
	
	while (true) {
		printf("%d,%f,%f,%f,%d\n", sylib::millis(), fly.get_velocity(), fly.get_velocity_error(), fly.get_acceleration(), fly.get_efficiency());
		delay(10);
	}}