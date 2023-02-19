#include "main.h"
#include "controller.h"
#include "flywheel.h"
#include "intake.h"
#include "pneumatics.h"
#include "pros/rtos.hpp"

// L2 = RED
// R2 = BLUE

int totalTime = -10;
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
		std::uint32_t now = millis();
		totalTime += 10;
		chassisControl();
		flywheel();
		intakeControl();
		pneumatics();
		if (totalTime >= 94000) {endgame = true;}
//		printf("%d,%d,%f\n", sylib::millis(), desiredVal,fly.get_velocity();
		Task::delay_until(&now, 10);
	}}