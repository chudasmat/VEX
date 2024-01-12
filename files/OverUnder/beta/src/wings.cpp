#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

bool bigOn = false;
bool miniOn = false;
ADIDigitalOut bigWings(1);
ADIDigitalOut miniWing(2);

void wingsControl(void) {
    if (master.get_digital_new_press(DIGITAL_Y)) {
        bigWings.set_value(!bigOn);
        bigOn = !bigOn;
    }
    if (master.get_digital_new_press(DIGITAL_RIGHT)) {
        miniWing.set_value(!miniOn);
        miniOn = !miniOn;
    }
}
