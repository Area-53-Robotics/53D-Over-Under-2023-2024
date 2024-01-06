#include "main.h"

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
	/*
	GamePhase = 2;
	// autonSelect = 2;
	// if (pros::competition::is_connected()) autonSelect = 1;
	// setStartingOdomValues();
	// pros::delay(500);
	// Controller.clear();
	switch (autonSelect) {
		case 1:
			// Controller.print(0, 0, "Left Quals Auton");
			AutonDrive(8, 2000);
			AutonTurn('R', 5, 2000);
			AutonDrive(1, 2000);
			AutonIntake(1000, true);
			AutonDrive(-1, 2000);
			AutonDrive(1, 2000);
			AutonDrive(-1, 2000);
			AutonTurn('R', 1, 2000);
			AutonDrive(-5, 2000);
			// Controller.print(1, 0, "Auton Completed");
			break;
		case 2:
			// Controller.print(0, 0, "Right Quals Auton");
			// Pushes triball
			AutonDrive(7.5, 1300);
			AutonTurn('R', 1.5, 1300);
			AutonIntake(1000, true);
			AutonDrive(1.2, 1300);
			AutonDrive(-1, 1300);
			AutonTurn('R',3.2,1600);
			AutonDrive(3.3, 1300);
			AutonIntake(1000, false);
			AutonTurn('R',3.2,1300);
			AutonDrive(3.3, 1300);
			AutonIntake(1000, true);
			AutonDrive(0.5, 1300);
			AutonDrive(-1.5, 1300);
			// Controller.print(1, 0, "Auton Completed");
			break;
		case 3:
			// Controller.print(0, 0, "Left Elims Auton");
			AutonDrive(4.5,2000);
			AutonIntake(1000, true);
			AutonDrive(1,2000);
			AutonDrive(-1.5,2000);
			AutonDrive(2,2000);
			AutonDrive(-1.5,2000);
			// Controller.print(1, 0, "Auton Completed");
			break;
		case 4:
			// Controller.print(0, 0, "Right Elims Auton");
			// Controller.print(1, 0, "Auton Completed");
			break;
		case 5:
			// Controller.print(0, 0, "Full AWP");
			// Controller.print(1, 0, "Auton Completed");
			break;
		case 6:
			// Controller.print(0, 0, "No Auton Selected");
			break;
		case 7:
			// Controller.print(0, 0, "Programming Skills");
			ArmMotor.move_absolute(45, 100);
			FlywheelMotor.move(127);
			// pros::delay(45000);
			// FlywheelMotor.brake();
			// Controller.print(1, 0, "Skills Complete");
			break;
	}
	*/
}