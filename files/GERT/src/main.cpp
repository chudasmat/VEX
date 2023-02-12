#include "main.h"
#include "controller.h"
#include "flywheel.h"
#include "intake.h"
#include "pros/rtos.hpp"

// L2 = RED
// R2 = BLUE

int desiredVal = 3000;

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
	lipBool = true;
	fwPower = 9000;
	
	while (true) {
		chassisControl();
		flywheel();
		intakeControl();
		pneumatics();
//		printf("%d,%d,%f\n", sylib::millis(), desiredVal,fly.get_velocity();
		delay(10);
	}}