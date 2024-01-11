#include "globals.h"
#include "main.h"

void simpleAuton(void) {
    chassis.set_drive_pid(24, 100, true);
    chassis.wait_drive();
    chassis.set_turn_pid(90, 90);
}