#include "main.h"

Motor leftA(1, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
Motor leftB(2, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
Motor leftC(3, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
Motor rightA(4, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
Motor rightB(5, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
Motor rightC(6, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
MotorGroup drivetrain({leftA, leftB, leftC, rightA, rightB, rightC});

void drive (void) {
    while (true) {
        leftA.move(master.get_analog(ANALOG_LEFT_Y));
		leftB.move(master.get_analog(ANALOG_LEFT_Y));
		leftC.move(master.get_analog(ANALOG_LEFT_Y));
		rightA.move(master.get_analog(ANALOG_RIGHT_Y));
		rightB.move(master.get_analog(ANALOG_RIGHT_Y));
		rightC.move(master.get_analog(ANALOG_RIGHT_Y));
    	delay(10);
	}
}