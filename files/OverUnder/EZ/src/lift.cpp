#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

bool liftOn = false; bool macroOn = false; bool lockOn = false;
int liftHeight = 0;

/*Motor liftA(15, E_MOTOR_GEARSET_36, false);
/Motor liftB(20, E_MOTOR_GEARSET_36, false);
MotorGroup lift({liftA, liftB});*/
ADIDigitalOut liftPiston(7);
ADIDigitalOut liftLock(1);

void liftControl(void) {
    if (master.get_digital(DIGITAL_R1)) {
        liftPiston.set_value(!liftOn); 
        liftOn = !liftOn;
        ledStrip1.pulse(0x43B5F7, 22, 10);
        ledStrip2.pulse(0x43B5F7, 22, 10);
    }
    /*lift.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    if (master.get_digital(DIGITAL_R1)) {lift.move(127);} 
    else if (master.get_digital(DIGITAL_L1)) {lift.move(-127);}
    else {lift.brake();}*/
    /*if (master.get_digital_new_press(DIGITAL_A)) {
        liftHeight++;
        if (liftHeight == 1) {lift.move_absolute(100, 127);}
        else if (liftHeight == 2) {lift.move_absolute(200, 127);}
        else if (liftHeight == 3) {liftHeight = 0; lift.move_absolute(0, 127);}
    }*/
    if (master.get_digital_new_press(DIGITAL_DOWN)) {
        liftLock.set_value(!lockOn);
        lockOn = !lockOn;
    }}
