#include "main.h"
#include "pros/motors.h"
bool kickerOn = false;
Motor kicker(7, E_MOTOR_GEAR_200, true);
ADIDigitalIn kickLimit(5);
Optical optical(18);

void kickerControl(void) {
    if (master.get_digital_new_press(DIGITAL_B)) {
        if (kickerOn) {kicker.brake();}
        else {kicker.move_velocity(200);}
        kickerOn = !kickerOn;
    }
    if (master.get_digital(DIGITAL_A)) {
        if (optical.get_proximity() > 150) {kicker.move(90);}
        else {kicker.brake();}
    }
}