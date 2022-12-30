#include "main.h"

bool complete = false;

void initialize() {
	okapiController.setText(0,0, "RED");
	sylib::initialize();
	rgb();
	arms::init();
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	Task autoRoll_(autoRoll);
	while (complete == false) {if (master.get_digital_new_press(DIGITAL_A)) {if (teamCol == 0) {teamCol = 1;} else {teamCol = 0;} complete = true;}}
	okapiController.clearLine(0);
	if (teamCol == 0) {okapiController.setText(0,0, "RED");} else {okapiController.setText(0,0,"BLUE");}
//	Task TBH_(tbhCntrl);
//	Task PID_(drivePID);
}

void disabled() {}
void competition_initialize() {}

void autonomous() {
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