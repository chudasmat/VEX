#include "main.h"
#include "roller.h"

// 0 = RED 
// 1 = BLUE

bool rollerSpinning = false;
bool colour;
bool teamCol = 0;
double prox = 0;
double hoo = 0;
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
			if (colour != 0 && prox < 100) {roller.move_velocity(100);}}
		if (teamCol == 1) {
			if (colour != 1 && prox < 100) {roller.move_velocity(100);}}
		delay(10);}}

void rollerControl (void) {
    while (true) {
		if (master.get_digital_new_press(DIGITAL_Y)){
			if (rollerSpinning) {roller.move_velocity(0);}
			else {roller.move_voltage(12);}
			rollerSpinning = !rollerSpinning;}
		if (master.get_digital_new_press(DIGITAL_B)) {rollerSpinning = true; roller.move_voltage(-12);}  
    delay(10);     
    }
}

