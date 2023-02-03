#include "flywheel.h"
#include "main.h"
#include "pros/misc.h"
#include "sylib/pros_includes.h"

sylib::SpeedControllerInfo flyController (
        [](double rpm){return 5;}, // kV function
        0,          // P disabled
        0,          // I disabled
        0,          // D disabled   
        0.001);     // TBH gain

sylib::Motor fly(15, 3600, false, flyController);

double flyPower = 10.5;
bool flySpinning = false;

void setFW (double power) {fly.set_voltage((power * 10000));}
void setTunedFW (double power) {fly.set_velocity_custom_controller(power);}

void flywheel (void) {
    fly.set_braking_mode(kV5MotorBrakeModeBrake);
    while (true) {
        if (master.get_digital_new_press(DIGITAL_L2)) {
            if (flySpinning == true) {fly.stop();}
            else {setFW(flyPower);}
            flySpinning = !flySpinning;
        }
        delay(10);
    }
}