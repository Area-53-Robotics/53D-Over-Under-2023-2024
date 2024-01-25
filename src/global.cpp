#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

/*
    Dead Ports: 5, 10, 16, 17 (last updated 12/9/23)
    Best Battery: 13
*/

pros::Motor BLMotor(-8, pros::E_MOTOR_GEAR_BLUE);
pros::Motor MLMotor(-9, pros::E_MOTOR_GEAR_BLUE);
pros::Motor FLMotor(-10, pros::E_MOTOR_GEAR_BLUE);

pros::Motor BRMotor(18, pros::E_MOTOR_GEAR_BLUE);
pros::Motor MRMotor(19, pros::E_MOTOR_GEAR_BLUE);
pros::Motor FRMotor(20, pros::E_MOTOR_GEAR_BLUE);

//creates motor groups
pros::Motor_Group LMotors({BLMotor, MLMotor, FLMotor});
pros::Motor_Group RMotors({BRMotor, MRMotor, FRMotor});

//creates the motors for op control
pros::Motor KickerMotor(11, pros::E_MOTOR_GEAR_RED, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor IntakeMotor(7,pros::E_MOTOR_GEAR_BLUE);

// Initializes a DigitalOut object to control the pneumatic wings.
pros::ADIDigitalOut HorizontalWingPistons('a');
pros::ADIDigitalOut VerticalWingPistons('b');

pros::IMU Inertial(1);

bool kickerOn = false;
bool drivetrainReversed = false;

void ControllerDisplay() {
    if(!drivetrainReversed) controller.print(0, 0, "Reversed: false");
    else if(drivetrainReversed) controller.print(0, 0, "Reversed: true");
    pros::delay(50);
    if(!kickerOn) controller.print(1, 0, "Kicker: Deactivated");
    else if(kickerOn) controller.print(1, 0, "Kicker: Activated");
}

/*
    1: Left Quals
    2: Right Quals
    3: Left Elims
    4: Right Elims
    5: Full Autonomous Win Point
    6: No Auton
    7: Programming Skills
*/
unsigned short int autonSelect = 2;

/*
*   Integer variable to represent the current game phase: 
    1: Pre-Autonomous
    2: Autonomous
    3: Driver Control
*/
unsigned short int GamePhase = 1;