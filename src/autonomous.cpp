#include "main.h"

ASSET(init_to_goal_txt)

//* The robot drives the given length at the given velocity
void drive(double length) {
	drive(length, 600);
}

void drive(double length, unsigned short int velocity) {
	// while(LMotors.get_actual_velocities().begin() > 0 || RMotors.get_actual_velocities().begin() > 0) pros::delay(1);
	LMotors.move_relative(length, velocity);
	RMotors.move_relative(length, velocity);
}

//* The robot turns in the given direction at the given length
void turn(char direction, double length) {
    turn(direction, length, 600);
}

void turn(char direction, double length, unsigned short int velocity) {
	// while(LMotors.get_actual_velocities().begin() > 0 || RMotors.get_actual_velocities().begin() > 0) pros::delay(1);
    if(direction == 'L') {
		LMotors.move_relative(length * -1, velocity);
		RMotors.move_relative(length, velocity);
    } else if(direction == 'R') {
		LMotors.move_relative(length, velocity);
		RMotors.move_relative(length * -1, velocity);
    }
}

// Activates the intake for the given amount of milliseconds in either the forward or reverse direction
void AutonIntake(unsigned short int msec, bool isReverse) {
	if(!isReverse) {
		IntakeMotor.move(115);
		pros::delay(msec);
		IntakeMotor.brake();
	} else if(isReverse) {
		IntakeMotor.move(-115);
		pros::delay(msec);
		IntakeMotor.brake();
	}
}

// Toggles the activation of the horizontal wings
void AutonWings(unsigned short int msec, bool activateWings){
	if(!activateWings){
		HorizontalWingPistons.set_value(1);
		pros::delay(msec);
		HorizontalWingPistons.set_value(0);
	} else{
		HorizontalWingPistons.set_value(0);
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
	// Informs the program that the robot is in the autonomous phase
	GamePhase = 3;
	// Sets the auton to the "Left Quals" auton
	// autonSelect = 1;
	
	switch (autonSelect) {
		case 0:
			chassis.setPose(0, 0, 0); // X, Y, Heading (degrees)
			chassis.moveToPoint(0, 30, 50000);
			// chassis.turnTo(45, 45, 5000);
			break;
		case 1:
			controller.print(0, 0, "Left Quals Auton");
			chassis.setPose(-48, -60, 135); // X, Y, Heading (degrees)
			ToggleVerticalPneumaticWings();
			pros::delay(500);
			chassis.turnTo(0, 0, 2000);
			pros::delay(500);
			chassis.turnTo(0, -60, 2000);
			pros::delay(500);
			ToggleVerticalPneumaticWings();
			pros::delay(500);
			chassis.moveToPoint(-5, -53, 5000);
			controller.print(1, 0, "Auton Completed");
			break;
		case 2:
			// Single triball using  PID (made at Gateway)
			controller.print(0, 0, "Right Quals Auton");
			chassis.setPose(0, 0, 0); // X, Y, Heading (degrees)
			// ToggleVerticalPneumaticWings();
			 pros::delay(1000);
			// chassis.turnTo(0,-30,2000);
			// ToggleVerticalPneumaticWings();
			chassis.moveToPoint(0, -18, 3000, false, 75);
			// ToggleVerticalPneumaticWings();
			// chassis.moveToPoint(0,-20,3000,false,75);
			chassis.moveToPoint(0, -36, 3000, false, 75);
			pros::delay(1000);
			chassis.moveToPoint(0, -15, 3000, true, 75);
			pros::delay(1000);
			chassis.moveToPoint(0, -48, 3000, false, 127);
			pros::delay(1000);
			chassis.moveToPoint(0, -15, 3000, true, 75);
			controller.print(1, 0, "Auton Completed");
			break;
		case 3:
			// Left Side Half AWP
			controller.print(0, 0, "Left Elims Auton");
			chassis.setPose(-48 - (7.0 / 2), -60, 135); // X, Y, Heading (degrees)
			//ToggleVerticalPneumaticWings();
			pros::delay(250);
			chassis.turnTo(0, -60, 2000);
			pros::delay(250);
			chassis.moveToPoint(-45, -60, 2000);
			//ToggleVerticalPneumaticWings();
			pros::delay(250);
			chassis.turnTo(0, -60 - 2, 2000);
			pros::delay(250);
			chassis.moveToPoint(0 - 20, -60 - 2, 2000);
			pros::delay(250);
			AutonIntake(1000, true);
			controller.print(1, 0, "Auton Completed");
			break;
		case 4:
			// in progress in-depth auton
			controller.print(0, 0, "Right Elims Auton");
			chassis.setPose(-48 - (7.0 / 2), -60, 135); // X, Y, Heading (degrees)
			ToggleVerticalPneumaticWings();
			chassis.turnTo(0, -18, 2000);
			ToggleVerticalPneumaticWings();
			chassis.moveToPoint(-30, -18, 2000);
			AutonIntake(1000,false);
			chassis.moveToPoint(-30,-40,2000,false);
			/*
			pros::delay(500);
			chassis.turnTo(24, -48, 5000, false);
			chassis.moveToPoint(24, -48, 5000, false);
			controller.print(1, 0, "Auton Completed");
			*/
			break;
		case 5:
			controller.print(0, 0, "Full AWP");
			chassis.setPose(0, 0, 0); // X, Y, Heading (degrees)
			controller.print(1, 0, "Auton Completed");
			break;
		case 6:
			controller.print(0, 0, "No Auton Selected");
			chassis.setPose(0, 0, 0); // X, Y, Heading (degrees)
			break;
		case 7:
			// Currently curves the robot to push a triball into the goal
			controller.print(0, 0, "Programming Skills - New Version");

			chassis.setPose(-72 + 26.5, -60, 133); // X, Y, Heading (degrees)
			chassis.moveToPose(-60 + 5, -24 + 24, 180, 2500, {.forwards = false, .chasePower = 8});
			chassis.waitUntilDone();
			chassis.setPose(-72 + 26.5, -29.25, 180); // X, Y, Heading (degrees)
			chassis.moveToPose(-48, -48 + 8, 60, 2500, {.forwards = false, .chasePower = 8});
			// chassis.moveToPose(-48 - 5, -48 + 8, 70, 2500, {.forwards = false, .chasePower = 8});
			// TODO: Ishika, test line 192 (directly above) to see if it gets the bot closer to the match load position than line 191

			controller.print(1, 0, "Skills Complete");
			break;
		case 8:
			// Currently gets the kicker into position
			controller.print(0, 0, "Programming Skills - Old Version");
			chassis.setPose(-39.75, -64.975, 0); // X, Y, Heading (degrees)
			chassis.moveToPoint(-40.75, -40.975, 2000);
			pros::delay(500);
			chassis.turnTo(-60, -40.975, 2000, false);
			pros::delay(500);
			chassis.moveToPoint(-58, -40.975, 2000, false);
			pros::delay(500);
			ToggleVerticalPneumaticWings();
			pros::delay(500);
			//chassis.turnTo(0, -12, 2000 * 10000);
			pros::delay(500);
			//chassis.turnTo(-60, -40.975, 2000,false);
			//pros::delay(500);
			//chassis.moveToPoint(-80,-100,2000);
			// chassis.turnTo(-60, -36, 2000);
			//pros::delay(500);
			kickerOn=true;
			// chassis.moveToPoint(-60, -36, 2000);
			// KickerMotor.move(127);
			// pros::delay(45000);

			controller.print(1, 0, "Skills Complete");
			break;
	}
	
}