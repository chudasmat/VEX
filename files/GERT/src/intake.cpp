#include "main.h"

bool intakeSpinning = false;
Motor intake(20, MOTOR_GEAR_200, true);

void intakeControl (void) {
    while (true) {
		if (master.get_digital_new_press(DIGITAL_RIGHT)){
			if (intakeSpinning) {intake.move_voltage(0);}
			else {intake.move_voltage(12000);}
			intakeSpinning = !intakeSpinning;}
		if (master.get_digital_new_press(DIGITAL_DOWN)) {intakeSpinning = true; intake.move_voltage(-12000);;}
    delay(10);}}