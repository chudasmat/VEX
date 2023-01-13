#include "drivetrain.h"
#include "intake.h"
#include "main.h"
#include "pneumatics.h"

void rollerAuton(void) {
    leftDrive.move_voltage(12000); // Moves robot back
    rightDrive.move_voltage(-12000); // Moves robot back
    intake.move_voltage(12000); // Starts roller
    delay(750); // Time for roller to spin
    intake.move_voltage(0); // Roller stop
    leftDrive.move_voltage(0); // Stop robot moving
    rightDrive.move_voltage(0); // Stop robot moving
}

void experimentalAuton(void) {
    chassisDrive->moveDistance(-12_in);
    intake.move_voltage(12000);
    delay(769);
    intake.move_voltage(0);
    chassisDrive->moveDistance(12_in);
    setFW(3000);
    indexToggle();
    delay(500);
    indexToggle();

}