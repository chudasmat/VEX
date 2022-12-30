#include "main.h"

bool intakeSpinning = false;
Motor intake(20, MOTOR_GEAR_200, true);

void intakeControl (void) {
    while (true) {
		if (master.get_digital_new_press(DIGITAL_RIGHT)){
			if (intakeSpinning) {intake.move_velocity(0);}
			else {intake.move_velocity(200);}
			intakeSpinning = !intakeSpinning;}
		if (master.get_digital_new_press(DIGITAL_DOWN)) {intakeSpinning = true; move_velocity(-200);;}
    delay(10);}}