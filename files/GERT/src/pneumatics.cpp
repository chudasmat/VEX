#include "main.h"
#include "pneumatics.h"

ADIDigitalOut disc1(1);
ADIDigitalOut disc3(2);
ADIDigitalOut stringS({{13, 3}});

void pneumatics (void) {
    while (true) {
        if (master.get_digital(DIGITAL_R2)) {disc1.set_value(true); delay(200);} else {disc1.set_value(false);}
        if (master.get_digital(DIGITAL_R1)) {disc3.set_value(true); delay(200);} else {disc3.set_value(false);}
        if (master.get_digital(DIGITAL_X)) {stringS.set_value(true); delay(200); stringS.set_value(false);}
        delay(10);
    }}


