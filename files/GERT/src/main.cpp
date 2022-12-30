#include "main.h"
#include "controller.h"
#include "pros/rtos.hpp"
#include "roller.h"

// L2 = RED
// R2 = BLUE

void initialize() {
	sylib::initialize();
	okapiController.setText(0, 0, "SELECT COLOUR");
	Task initColTog_(initColTog);
	Task autoRoll_(autoRoll);
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
	arms::init();
}

void disabled() {}
void competition_initialize() {}

void autonomous() {
	initColTog_.remove();
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
	Task pneumatics_(pneumatics);}