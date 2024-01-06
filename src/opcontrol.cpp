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
void opcontrol()
{
	// if(!pros::competition::is_connected) autonomous(); -- this line of code doesn't work for some reason
	// autonomous();
	ControllerDisplay();
	bool chassisReversed = false;
	while (true)
	{
		int left = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int right = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
		{
			controller.rumble(".");
			chassisReversed = !chassisReversed;
		}
		if (chassisReversed){
			RMotors.move(GetCurveOutput(-left));
			LMotors.move(GetCurveOutput(-right));
		} else {
		LMotors.move(GetCurveOutput(left));
		RMotors.move(GetCurveOutput(right));
		}
		//	SetDriveMotors();

		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
			DirectionToggle();
		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT))
			PneumaticWings();

		// Allows L1 and L2 to move the intake forward and backwards.
		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
			IntakeMotor.move(127);
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
			IntakeMotor.move(-127);
		else
			IntakeMotor.brake();

		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
			FlywheelMotor.move(127);
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
			FlywheelMotor.move(-127);
		else
			FlywheelMotor.brake();

		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
			ArmMotor.move(100);
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
			ArmMotor.move(-100);
		else
			ArmMotor.brake();

		pros::delay(20);
	}
}