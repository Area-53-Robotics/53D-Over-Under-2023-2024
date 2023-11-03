#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	while (true) {
		SetDriveMotors();

		if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) DirectionToggle();
		if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) PneumaticWings();

		if(Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) CatapultMotor.move(115);
		else CatapultMotor.brake();

		if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) IntakeMotor.move(127);
		else if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) IntakeMotor.move(-127);
		else IntakeMotor.brake();

		pros::delay(20);
	}
}