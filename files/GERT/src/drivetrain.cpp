#include "main.h"

bool driveInvert = false;
bool brakeHold = false;
std::string driveCurrent = "FW";
std::string brakeCurrent = "NB";

Motor leftA(1, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
Motor leftB(2, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
Motor leftC(3, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
Motor rightA(4, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
Motor rightB(5, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
Motor rightC(6, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
MotorGroup drive({leftA, leftB, leftC, rightA, rightB, rightC});

std::shared_ptr<okapi::OdomChassisController> chassisDrive = okapi::ChassisControllerBuilder()
.withMotors({1, 2, 3}, {4, 5, 6})
// .withGains({0.001, 0, 0.0001},
//          {0.001, 0, 0.0001},
//          {0.001, 0, 0.0001})
.withSensors(okapi::ADIEncoder{'C', 'D'}, 
 		okapi::ADIEncoder{'E', 'F', true}, 
 		okapi::ADIEncoder{'G', 'H'})
.withDimensions({okapi::AbstractMotor::gearset::blue, (36.0/60.0)}, {{4.125_in, 15_in}, okapi::imev5BlueTPR})
.withOdometry({{2.75_in, 10.45_in, 6.5_in, 2.75_in}, okapi::quadEncoderTPR}, okapi::StateMode::FRAME_TRANSFORMATION)  // Add ADI Encoders after Gains and add tracking wheel size with track width
.buildOdometry();

void chassisControl (void) {
    while (true) {
		
		// chassisDrive->getModel()->tank(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_Y));
		
		if (!driveInvert) {
			leftA.move(master.get_analog(ANALOG_LEFT_Y));
			leftB.move(master.get_analog(ANALOG_LEFT_Y));
			leftC.move(master.get_analog(ANALOG_LEFT_Y));
			rightA.move(master.get_analog(ANALOG_RIGHT_Y));
			rightB.move(master.get_analog(ANALOG_RIGHT_Y));
			rightC.move(master.get_analog(ANALOG_RIGHT_Y));}
		else {
			leftA.move(-(master.get_analog(ANALOG_RIGHT_Y)));
			leftB.move(-(master.get_analog(ANALOG_RIGHT_Y)));
			leftC.move(-(master.get_analog(ANALOG_RIGHT_Y)));
			rightA.move(-(master.get_analog(ANALOG_LEFT_Y)));
			rightB.move(-(master.get_analog(ANALOG_LEFT_Y)));
			rightC.move(-(master.get_analog(ANALOG_LEFT_Y)));}


		if (master.get_digital_new_press(DIGITAL_L1)) {
			if (driveInvert) {driveCurrent = "FW";} else {driveCurrent = "IT";}
			driveInvert = !driveInvert;
			lightDirec = !lightDirec;}

//		if (master.get_digital_new_press(DIGITAL_LEFT)){
//			if (brakeHold) {drive.set_brake_modes(MOTOR_BRAKE_COAST);}
//			else {drive.set_brake_modes(MOTOR_BRAKE_HOLD);}
//			brakeHold = !brakeHold;
//			if (brakeHold) {brakeCurrent = "BR";} else {brakeCurrent = "NB";}}

		delay(10);}}