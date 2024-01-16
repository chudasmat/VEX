#include "main.h"
#include "pros/motors.h"
bool kickerOn = false;
Motor kicker(9, E_MOTOR_GEAR_200, true);
Optical optical(2);

void kickerControl(void) {
    if (master.get_digital_new_press(DIGITAL_X)) {
        if (kickerOn) {kicker.brake();}
        else {kicker.move_velocity(120);}
        kickerOn = !kickerOn;
    }
}
