#include "main.h"
#include "globals.h"
Controller master(CONTROLLER_MASTER);

void initialize() {
	chassis.initialize();
	chassis.set_curve_default(3.5, 3.5);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
//	farFiveTriball();
	nearOneTriball();
//	farOneTriball();
//	nearThreeTriball();
//	farThreeTriball();
//	partialAWP();
}

void opcontrol() {
	sylib::initialize();
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
	
	liftLock.set_value(1);
	kicker.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	int count = 0;
	chassis.set_drive_brake(E_MOTOR_BRAKE_COAST);
	while (true) {

		if (!(count % 25)) {
      		master.print(0, 0, "Optical: %d", optical.get_proximity());
    	}
    	count++;

		chassisControl();
		kickerControl();
		intakeControl();
		liftControl();
		wingsControl();
		pros::delay(10);
	}
}
