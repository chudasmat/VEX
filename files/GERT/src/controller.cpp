#include "main.h"

Controller master(CONTROLLER_MASTER);
okapi::Controller okapiController;
double currFWSpeed = 0.0;
std::string printSpeed;

void printer(void) {
    while (true) {
        currFWSpeed = fly.get_velocity();
        printSpeed = to_string(currFWSpeed);
        okapiController.setText(0,0, printSpeed);
        delay(20);
    }
}