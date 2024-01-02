#include "main.h"
bool kickerOn = false;
Motor kicker(7, false);
ADIDigitalIn kickLimit(5);

void kickerControl(void) {
    if (master.get_digital_new_press(DIGITAL_B)) {
        if (kickerOn) {kicker.brake();}
        else {kicker.move(127);}
        kickerOn = !kickerOn;
    }
    if (master.get_digital_new_press(DIGITAL_A)) {
        if (kickLimit.get_value() == 0) {kicker.move(90);}
        else if (kickLimit.get_value() == 1) {kicker.brake();}
    }
}