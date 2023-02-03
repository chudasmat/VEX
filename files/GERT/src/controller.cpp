#include "main.h"
#include "pros/misc.h"

pros::Controller master (CONTROLLER_MASTER);

void printer(void) {
    while (true) {
        master.print(0, 0, "%d", fly.get_velocity());
        master.clear_line(0); 
        delay(60);
    }
}