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
	//okapiController.setText(0, 0, "SELECT COLOUR");
	Task autoRoll_(autoRoll);
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
}

void experimentalAuton() {
	drive.move_voltage(12000); // Drive back towards roller
	intake.move_voltage(12000); // Start roller
	delay(750); // Time to wait for roller to finish
	intake.move_voltage(0); // Stop roller
	drive.move_voltage(0); // Stop driving back

	chassisDrive->moveDistance(1_in); // Drive forward before turning
	chassisDrive->turnAngle(45_deg); // Turning around to pick up discs
	intake.move_voltage(12000); // Start intake
	chassisDrive->moveDistance(15_in); // Move forward to pick up discs
	chassisDrive->turnAngle(-90_deg); // Turn towards goal
	fly.set_velocity_custom_controller(1600); // Start flywheel

	chassisDrive->turnAngle(90_deg);
	
}

void workingAuton() {


	//  chassis->moveDistance(-12_in);
	//  chassis->moveDistance(12_in);
	//  chassis->turnAngle(45_deg);
	//  chassis->moveDistance(8_ft);
	//  chassis->waitUntilSettled();
	// chassisDrive->driveToPoint({12_in, 12_in});
	// chassisDrive->moveDistance(-16.97_in);
	// chassisDrive->driveToPoint({0_in, 0_in}  );
	// chassisDrive->turnToAngle(0_deg);
}

void autonomous() {
	bobby.remove();
	//okapiController.clearLine(0);
	chassisDrive->setState({0_in, 0_in, 0_deg});

	workingAuton();
}

void opcontrol() {
	lip.set_value(true);

	Task chassisControl_(chassisControl);
	Task flywheel_(flywheel);
	Task intakeControl_(intakeControl);
	Task rollerControl_(rollerControl);
	Task pneumatics_(pneumatics);
//	Task printer_(printer);
	
	while (true) {
		printf("%d,%f,%f,%f,%d\n", sylib::millis(), fly.get_velocity(), fly.get_velocity_error(), fly.get_acceleration(), fly.get_efficiency());
		delay(10);
	}}