#include "main.h"
#include "pneumatics.h"

bool lipBool = false;
ADIDigitalOut indexer({{13, 8}});
ADIDigitalOut lip({{13, 7}});
ADIDigitalOut stringS({{13, 6}});

void indexToggle (void) {
    indexer.set_value(true);
    delay(120);
    indexer.set_value(false);
}

void lipToggle (void) {
    if (lipBool == true) {lip.set_value(false); flyPower = 9.5;}
    else if (lipBool == false) {lip.set_value(true); flyPower = 8;}
    if (flySpinning) {fly.stop(); setFW(flyPower);}
    lipBool = !lipBool;
}

void pneumatics (void) {
    while (true) {
        if (master.get_digital_new_press(DIGITAL_R2)) {indexToggle();}
        if (master.get_digital_new_press(DIGITAL_R1)) {indexToggle(); delay(240); indexToggle(); delay(249); indexToggle();}
        if (master.get_digital_new_press(DIGITAL_Y)) {lipToggle();}
        
        if (master.get_digital(DIGITAL_X)) {stringS.set_value(true); delay(200); stringS.set_value(false);}
        delay(10);
    }}