#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

bool liftOn = false; bool macroOn = false;
int liftHeight = 0;

Motor lift(15, E_MOTOR_GEARSET_36, true);

void liftControl(void) {
    lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    if (master.get_digital_new_press(DIGITAL_R1)) {lift.move(127);}
    if (master.get_digital_new_press(DIGITAL_L1)) {lift.move(-127);}
    if (master.get_digital_new_press(DIGITAL_A)) {
        liftHeight++;
        if (liftHeight == 1) {lift.move_absolute(100, 127);}
        else if (liftHeight == 2) {lift.move_absolute(200, 127);}
        else if (liftHeight == 3) {liftHeight = 0; lift.move_absolute(0, 127);}
    }
}