#include "main.h"
#include "pneumatics.h"

void rollerAuton(void) {
    chassisDrive->moveDistance(-3_in);
    intake.move_voltage(12000);
    delay(769);
    chassisDrive->moveDistance(6_in);
    setFW(2700);
    delay(5000);
    indexToggle();
    delay(2500);
    indexToggle();
}

void awpAuton(void) {

}

void skillsAuton(void) {

}