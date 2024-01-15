#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

bool liftOn = false; bool macroOn = false;
int liftHeight = 0;

Motor liftA(15, E_MOTOR_GEARSET_06, true);
Motor liftB(16, E_MOTOR_GEARSET_06, true);
MotorGroup lift({liftA, liftB});
// ADIDigitalIn lift(1);

void liftControl(void) {
//    if (master.get_digital_new_press(DIGITAL_R1)) {
//        lift.set_value(!liftOn); 
//        liftOn = !liftOn;}
//    
//    if (master.get_digital_new_press(DIGITAL_L2) && master.get_digital_new_press(DIGITAL_R2)) {
//        macroOn = !macroOn;
//        miniWing.set_value(macroOn);
//        lift.set_value(macroOn);
//        if (macroOn) {kicker.move(127);}
//        else if (!macroOn) {kicker.brake();}}

    if (master.get_digital_new_press(DIGITAL_R1)) {lift.move(127);}
    if (master.get_digital_new_press(DIGITAL_L1)) {lift.move(-127);}
    if (master.get_digital_new_press(DIGITAL_A)) {
        liftHeight++;
        if (liftHeight == 1) {lift.move_absolute(100, 127);}
        else if (liftHeight == 2) {lift.move_absolute(200, 127);}
        else if (liftHeight == 3) {liftHeight = 0; lift.move_absolute(0, 127);}
    }
}