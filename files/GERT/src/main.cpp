#include "main.h"
#include "controller.h"
#include "pros/rtos.hpp"
#include "roller.h"

// L2 = RED
// R2 = BLUE

void disabled() {}
void competition_initialize() {}

static Task bobby(initColTog);

void initialize() {
	sylib::initialize();
	okapiController.setText(0, 0, "SELECT COLOUR");
	Task autoRoll_(autoRoll);
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
	arms::init();
}

void autonomous() {
	bobby.remove();
	okapiController.clearLine(0);
	chassisDrive->setState({0_in, 0_in, 0_deg});
	//  chassis->moveDistance(-12_in);
	//  chassis->moveDistance(12_in);
	//  chassis->turnAngle(45_deg);
	//  chassis->moveDistance(8_ft);
	//  chassis->waitUntilSettled();
	chassisDrive->driveToPoint({12_in, 12_in});
	chassisDrive->moveDistance(-16.97_in);
	chassisDrive->driveToPoint({0_in, 0_in}  );
	chassisDrive->turnToAngle(0_deg);
}

void opcontrol() {
	Task chassisControl_(chassisControl);
	Task flywheel_(flywheel);
	Task intakeControl_(intakeControl);
	Task rollerControl_(rollerControl);
	Task pneumatics_(pneumatics);
	Task printer_(printer);
	
	while (true) {
		printf("%d,%f,%f,%f,%d\n", sylib::millis(), fly.get_velocity(), fly.get_velocity_error(), fly.get_acceleration(), fly.get_efficiency());
		delay(10);
	}}