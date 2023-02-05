#include "controller.h"
#include "main.h"
#include <string>

bool flySpinning = false;
// int fwSpeeds[3] = {2000, 3000, 3600};
// int fwIndex = 0;

double fwPower = 10.5; 

sylib::SpeedControllerInfo flyController (
        [](double rpm){return 5;}, // kV function
        0,
        0,
        0,
        0.245
);

sylib::Motor fly(15, 3600, true, flyController);
void setFW (double power) {
    fly.set_voltage((power * -1));
}

void flywheel (void) {
    fly.set_braking_mode(kV5MotorBrakeModeBrake);
    while (true) {
        if (master.get_digital_new_press(DIGITAL_L2)) {
            if (flySpinning == true) {
                fly.stop();
            }
            else {
                // fly.set_velocity_custom_controller(3000);
                setFW(fwPower);
            }
            flySpinning = !flySpinning;
        }

        /* if (master.get_digital_new_press(DIGITAL_LEFT)) {
            if (flySpinning == true) {
                if ((fwIndex + 1) != (3)) {
                    fwIndex = fwIndex + 1;
                    fly.set_velocity_custom_controller(fwSpeeds[fwIndex]);
                }
                else {
                    fwIndex = 0;
                    fly.set_velocity_custom_controller(fwSpeeds[fwIndex]);
                }
            }
            else {
                if ((fwIndex + 1) != (3)) {
                    fwIndex = fwIndex + 1;
                }
                else {
                    fwIndex = 0;
                }
            }
        } */
        delay(10);
    }
}
        

