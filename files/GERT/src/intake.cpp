#include "main.h"
#include "pros/misc.h"

bool intakeSpinning = false;
Motor intake(20, MOTOR_GEAR_200, true);

void intakeControl (void) {
    while (true) {
		if (master.get_digital_new_press(DIGITAL_RIGHT)){
			if (intakeSpinning) {intake.move_voltage(0);}
			else {intake.move_voltage(12000);}
			intakeSpinning = !intakeSpinning;}
		
		if (master.get_digital_new_press(DIGITAL_UP)){
			if (intakeSpinning) {intake.move_voltage(0);}
			else {intake.move_voltage(7000);}
			intakeSpinning = !intakeSpinning;}

//		Flex wheel indexer		
		if (master.get_digital_new_press(DIGITAL_DOWN)) {
			if (intakeSpinning) {intake.move_voltage(0);}
			else {intake.move_voltage(-12000);}
			intakeSpinning = !intakeSpinning;}
    delay(10);}}
