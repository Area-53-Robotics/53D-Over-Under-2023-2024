#include "main.h"

// Returns the curved output based off of the joystick value input as a parameter
float GetCurveOutput(int input) {
    return (std::exp(-20/12.7)+std::exp((std::abs(input)-127)/12.7)*(1-std::exp(-20/12.7))) * input;
}

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
//	autonomous();
	ControllerDisplay();
	short int leftAxis;
	short int rightAxis;

	int count = 0;

	while (true)
	{
		// Update Joysticks
		leftAxis = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		rightAxis = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

		// Deadzone
		if(abs(leftAxis) <= 10) leftAxis = 0;
		if(abs(rightAxis) <= 10) rightAxis = 0;
		
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
		{
			controller.rumble(".");
			drivetrainReversed = !drivetrainReversed;
		}

		if(drivetrainReversed) {
			RMotors.move(GetCurveOutput(-leftAxis));
			LMotors.move(GetCurveOutput(-rightAxis));
		} else {
			LMotors.move(GetCurveOutput(leftAxis));
			RMotors.move(GetCurveOutput(rightAxis));
		}
			
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2))
			ToggleHorizontalPneumaticWings();
		
		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1))
		ToggleVerticalPneumaticWings();

		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) and controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
		ToggleHangingMech();

		// Allows L1 and L2 to move the intake forward and backwards.
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
			IntakeMotor.move(127);
		else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
			IntakeMotor.move(-127);
		else
			IntakeMotor.brake();

		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
			kickerOn = !kickerOn;

		if(kickerOn) {
			KickerMotor.move(110);
		} else {
			KickerMotor.brake();
		}

		count++;
		/*
		if (count % 40 == 0) {
			// std::cout << "Orientation:" << (360 - Inertial.get_heading()) << std::endl;
			// std::cout << "totalDeltaL" << totalDeltaL << std::endl;
			// std::cout << "totalDeltaR" << totalDeltaR << std::endl;
			std::cout << LMotors.get_position(0) << std::endl;
			std::cout << LMotors.get_position(1) << std::endl;
			std::cout << LMotors.get_position(2) << std::endl;
			std::cout << "---" << std::endl;
			std::cout << RMotors.get_position(0) << std::endl;
			std::cout << RMotors.get_position(1) << std::endl;
			std::cout << RMotors.get_position(2) << std::endl;
			std::cout << "---------------------------" << std::endl;
		}
		*/

		// Creates a 20 millisecond delay between each loop of the driver control code to prevent the starving of PROS kernel resources
		pros::delay(20);
	}
}