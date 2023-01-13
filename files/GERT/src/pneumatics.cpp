#include "main.h"
#include "pneumatics.h"

bool lipToggle = false;

ADIDigitalOut indexer({{13, 1}});
ADIDigitalOut lip({{13, 2}});
ADIDigitalOut stringS({{13, 3}});

void indexToggle (void) {
    indexer.set_value(true);
    delay(150);
    indexer.set_value(false);
}

void pneumatics (void) {
    while (true) {
        if (master.get_digital(DIGITAL_R1)) {indexToggle();}
        
        if (master.get_digital(DIGITAL_Y)) {
            if (lipToggle == true) {
                lip.set_value(false);
            }
            else {
                lip.set_value(true);
            }
            lipToggle = !lipToggle;
        }
        if (master.get_digital(DIGITAL_X)) {stringS.set_value(true); delay(200); stringS.set_value(false);}
        delay(10);}
    }


