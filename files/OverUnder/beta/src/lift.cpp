#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"

bool liftOn = false;
bool macroOn = false;
ADIDigitalOut lift(1);

void liftControl(void) {
    if (master.get_digital(DIGITAL_R2)) {
        lift.set_value(!liftOn); 
        liftOn = !liftOn;}
    
    if (master.get_digital_new_press(DIGITAL_L2) && master.get_digital_new_press(DIGITAL_R2)) {
        macroOn = !macroOn;
        miniWing.set_value(macroOn);
        lift.set_value(macroOn);
        if (macroOn) {kicker.move(127);}
        else if (!macroOn) {kicker.brake();}

    }
}