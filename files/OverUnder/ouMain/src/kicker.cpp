#include "main.h"
bool kickerOn = false;
Motor kicker(7, false);

void kickerControl(void) {
    if (master.get_digital_new_press(DIGITAL_B)) {
        if (kickerOn) {kicker.brake();}
        else {kicker.move(127);}
        kickerOn = !kickerOn;
    }
}