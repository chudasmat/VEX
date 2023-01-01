#include "main.h"

Controller master(CONTROLLER_MASTER);
okapi::Controller okapiController;
std::string printSpeed;

void printer(void) {
    okapiController.clearLine(0);
    while (true) {
        printSpeed = to_string(fly.get_velocity());
        okapiController.setText(0, 0, printSpeed + " " + driveCurrent);
        delay(20);
    }
}