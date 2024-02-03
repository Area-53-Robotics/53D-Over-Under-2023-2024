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
	autonomous();
	/*
	ControllerDisplay();
	short int leftAxis;
	short int rightAxis;

	int count = 0;

	Optical.set_led_pwm(100);

	while (true)
	{
		// Update Joysticks
		leftAxis = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		rightAxis = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

		// Deadzone
		if(abs(leftAxis) <= 10) leftAxis = 0;
		if(abs(rightAxis) <= 10) rightAxis = 0;
		
		// When the A button is pressed, the drivetrain controls are reversed
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
		{
			controller.rumble(".");
			drivetrainReversed = !drivetrainReversed;
			ControllerDisplay();
		}

		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
			controller.rumble(".");
			manualKicker = !manualKicker;
			ControllerDisplay();
		}

		if(!drivetrainReversed) {
			LMotors.move(GetCurveOutput(leftAxis));
			RMotors.move(GetCurveOutput(rightAxis));
		} else {
			RMotors.move(GetCurveOutput(-leftAxis));
			LMotors.move(GetCurveOutput(-rightAxis));
		}
		
		// When LEFT is pressed, toggles the activation of the wings
		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2))
			ToggleHorizontalPneumaticWings();

		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1))
			ToggleVerticalPneumaticWings();

		if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT))
			ToggleHangingMech();

		// Allows L1 and L2 to move the intake forward and backwards respectively
		if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
			IntakeMotor.move(127);
		else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
			IntakeMotor.move(-127);
		else
			IntakeMotor.brake();
		
		// When R2 is pressed, the activation of the kicker is toggled
		if(manualKicker) {
			if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
				kickerOn = !kickerOn;
		} else {
			if(Optical.get_hue() > 65 && Optical.get_hue() < 80) kickerOn = true;
			// else if(KickerMotor.get_position() < 1280) kickerOn = true;
			else kickerOn = false;
		}

		// If the kicker is supposed to be on...
		if(kickerOn) {
			// Then the kicker motor continuously rotates downwards at 87% speed (so that it can hit the slip gear to shoot)
			KickerMotor.move(127);
		// If the kicker is supposed to be off...
		} else {
			// Then the kicker brakes and holds its current position
			KickerMotor.brake();
		}

		count++;

		if (count % 40 == 0) {
			std::cout << "Hue: " << Optical.get_hue() << std::endl;
			std::cout << "Saturation: " << Optical.get_saturation() << std::endl;
			std::cout << "Brightness: " << Optical.get_brightness() << std::endl;
			std::cout << "manualKicker: ";
			std::cout << "-----------------------" << std::endl;
		}

		// Creates a 20 millisecond delay between each loop of the driver control code to prevent the starving of PROS kernel resources
		pros::delay(20);
	}
	*/
}