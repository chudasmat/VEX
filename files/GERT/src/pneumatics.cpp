#include "main.h"
#include "pneumatics.h"

ADIDigitalOut indexer({{13, 1}});
ADIDigitalOut lip({{13, 2}});
ADIDigitalOut stringS({{13, 3}});

void pneumatics (void) {
    while (true) {
        if (master.get_digital(DIGITAL_R1)) {indexer.set_value(true); delay(200);} else {indexer.set_value(false);}
        if (master.get_digital(DIGITAL_Y)) {lip.set_value(true); delay(200);} else {lip.set_value(false);}
        if (master.get_digital(DIGITAL_X)) {stringS.set_value(true); delay(200); stringS.set_value(false);}
        delay(10);
    }}


