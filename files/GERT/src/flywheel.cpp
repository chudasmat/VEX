#include "controller.h"
#include "main.h"
#include <string>

bool flySpinning = false;
int fwSpeeds[4] = {0, 2000, 3000, 3600};
int fwIndex = 0;

sylib::SpeedControllerInfo flyController (
        [](double rpm){return 5;}, // kV function
        0,
        0,
        0,
        0.245
);

sylib::Motor fly(15, 3600, true, flyController);

void setFW (int power) {
    fly.set_velocity_custom_controller(power);}

void flywheel (void) {
    while (true) {
        if (master.get_digital_new_press(DIGITAL_L2)){
			if (flySpinning) {fly.stop();}
			else {setFW(fwSpeeds[fwIndex]);}
			flySpinning = !flySpinning;}
        if (master.get_digital_new_press(DIGITAL_LEFT)) {
            fwIndex++;
            if (fwIndex >= (sizeof(fwSpeeds) / sizeof(int))) {
                fwIndex = 0;};}
        delay(10);}}