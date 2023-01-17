#include "main.h"
#include "pneumatics.h"

bool lipToggle = false;
ADIDigitalOut indexer({{13, 8}});
ADIDigitalOut lip({{13, 7}});
ADIDigitalOut stringS({{13, 6}});

void indexToggle (void) {
    indexer.set_value(true);
    delay(100);
    indexer.set_value(false);
}

void pneumatics (void) {
    while (true) {
        if (master.get_digital(DIGITAL_R2)) {indexer.set_value(true); delay(100);} else {indexer.set_value(false);}
        if (master.get_digital(DIGITAL_Y)) {
            if (lipToggle) {
                lip.set_value(false);
                fwPower = 3000;
            }
            else {
                lip.set_value(true);
                fwPower = 2400;
            }
            if (flySpinning) {
                fly.set_velocity_custom_controller(fwPower);
            }
            lipToggle = !lipToggle;
        }
        
        if (master.get_digital(DIGITAL_X)) {stringS.set_value(true); delay(200); stringS.set_value(false);}
        delay(10);
    }}


