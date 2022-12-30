#include "main.h"

bool flySpinning = false;
sylib::SpeedControllerInfo flyController (
        [](double rpm){return 5;}, // kV function
        0, // kP
        0, // kI
        0, // kD
        0.245 // kH
);

sylib::Motor fly(15, 3600, false, flyController);

void flywheel (void) {
    while (true) {
        if (master.get_digital_new_press(DIGITAL_L2)){
			if (flySpinning) {fly.stop();}
			else {fly.set_velocity_custom_controller(3000);}
			flySpinning = !flySpinning;}
        delay(10);}}