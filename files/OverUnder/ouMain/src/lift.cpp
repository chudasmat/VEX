#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"

bool liftOn = false;
ADIDigitalOut lift(1);

void liftControl(void) {
    if (master.get_digital(DIGITAL_R2)) {
        lift.set_value(!liftOn); 
        liftOn = !liftOn;}
}