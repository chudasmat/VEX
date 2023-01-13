#include "controller.h"
#include "main.h"
#include "roller.h"

// 0 = RED.
// 1 = BLUE

bool taskTog = true;
bool colourToggle = false;
bool rollerSpinning = false;
bool colour;
bool teamCol = 0;
double prox = 0;
double hoo = 0;
std::string textColour = "RED";
Motor roller(12, MOTOR_GEAR_100);
Optical optical(11);

int getColour() {
	optical.set_led_pwm(100);
	hoo = optical.get_hue();
	if (hoo > 340 || hoo < 14) {return 0;}
	else if (hoo > 140 && hoo < 260) {return 1;}
	else {return 2;}}

void autoRoll() {
	while (true) {
		colour = getColour();
		prox = optical.get_proximity();
		if (teamCol == 0) {
			if (colour != 0 && prox < 100) {roller.move_voltage(12000);}}
		if (teamCol == 1) {
			if (colour != 1 && prox < 100) {roller.move_voltage(12000);}}
		delay(10);}}

void rollerControl (void) {
    while (true) {
		// if (master.get_digital_new_press(DIGITAL_Y)){
			// if (rollerSpinning) {roller.move_voltage(0);}
			// else {roller.move_voltage(12000);}
			// rollerSpinning = !rollerSpinning;}
		
		// if (master.get_digital_new_press(DIGITAL_B)) {rollerSpinning = true; roller.move_voltage(-12000);}
		
		if (master.get_digital_new_press(DIGITAL_A)){
			if (colourToggle) {teamCol = 0;}
			else {teamCol = 1;}
			colourToggle = !colourToggle;}
    delay(10);     
    }
}

int initColTog() {
	while (taskTog) {
		if (master.get_digital_new_press(DIGITAL_L2)) {teamCol = 0; textColour = "RED"; okapiController.clearLine(0);}
		else if (master.get_digital_new_press(DIGITAL_R2)) {teamCol = 1; textColour = "BLUE"; okapiController.clearLine(0);}
		okapiController.setText(0, 0, textColour);
	delay(30);
	}
	return 1;
}

