#include "main.h"
#include "pneumatics.h"

bool lipToggle = false;
ADIDigitalOut indexer({{13, 8}});
ADIDigitalOut lip({{13, 7}});
ADIDigitalOut stringS({{13, 6}});

void pneumatics (void) {
    while (true) {
        if (master.get_digital(DIGITAL_R2)) {indexer.set_value(true); delay(200);} else {indexer.set_value(false);}
        if (master.get_digital(DIGITAL_Y)) {
            if (lipToggle) {
                lip.set_value(false);
            }
            else {
                lip.set_value(true);
            }
            lipToggle = !lipToggle;
        }
        
        if (master.get_digital(DIGITAL_X)) {stringS.set_value(true); delay(200); stringS.set_value(false);}
        delay(10);
    }}


