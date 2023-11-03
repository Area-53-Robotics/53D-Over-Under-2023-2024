#include "main.h"

//* The robot drives the given length at the given velocity
void drive(double length) {
	drive(length, 200);
}

void drive(double length, int velocity) {
	LMotors.move_relative(length, velocity);
	RMotors.move_relative(length, velocity);
}

//* The robot turns in the given direction at the given length
void turn(char direction, double length) {
    turn(direction, length, 200);
}

void turn(char direction, double length, int velocity) {
    if (direction == 'L') {
		LMotors.move_relative(length * -1, velocity);
		RMotors.move_relative(length, velocity);
    } else if (direction == 'R') {
		LMotors.move_relative(length, velocity);
		RMotors.move_relative(length * -1, velocity);
    }
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	GamePhase = 2;
	autonSelect = 6;
	// if (!pros::competition::is_connected) autonSelect = 1;
	// if (pros::competition::is_connected()) autonSelect = 1;
	// setStartingOdomValues();
	Controller.clear();
	switch (autonSelect) {
		case 1:
			Controller.print(0, 0, "Left Quals Auton");
			turn('R', 0.2);
			CatapultMotor.move_velocity(200);
			pros::delay(150);
			CatapultMotor.brake();
			Controller.print(1, 0, "Auton Completed");
			break;
		case 2:
			Controller.print(0, 0, "Right Quals Auton");
			CatapultMotor.move_velocity(200);
			pros::delay(150);
			CatapultMotor.brake();
			Controller.print(1, 0, "Auton Completed");
			break;
		case 3:
			Controller.print(0, 0, "Left Elims Auton");
			Controller.print(1, 0, "Auton Completed");
			break;
		case 4:
			Controller.print(0, 0, "Right Elims Auton");
			Controller.print(1, 0, "Auton Completed");
			break;
		case 5:
			Controller.print(0, 0, "Full AWP");
			Controller.print(1, 0, "Auton Completed");
			break;
		case 6:
			Controller.print(0, 0, "No Auton Selected");
			break;
		case 7:
			Controller.print(0, 0, "Programming Skills");
			Controller.print(1, 0, "Skills Complete");
			break;
	}
}