#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

/*
    Dead Ports: 5, 10, 16, 17 (last updated 12/9/23)
    Best Battery: 13
*/

//creates motor groups
pros::MotorGroup LMotors({-8, -9, -10}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::rotations);
pros::MotorGroup RMotors({18, 19, 20}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::rotations);

pros::MotorGroup Drivetrain({-8, -9, -10, 18, 19, 20}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::rotations);
pros::MotorGroup LTDrivetrain({-8, -9, -10, -18, -19, -20}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::rotations);
pros::MotorGroup RTDrivetrain({8, 9, 10, 18, 19, 20}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::rotations);

//creates the motors for op control
pros::Motor KickerMotor(11, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);

pros::Motor IntakeMotor(7, pros::v5::MotorGears::blue);

// Initializes a DigitalOut object to control the pneumatic wings.
pros::adi::DigitalOut HorizontalWingPistons('a');
pros::adi::DigitalOut VerticalWingPistons('b');

pros::IMU Inertial(1);

// std::array<std::string,3> MotorNameList = {"BLM", "FLM", "TLM", "BRM", "FRM", "TRM", "Intake", "Kicker"};
std::array<std::string,2> MotorNameList = {"Kicker", "Intake"};
std::array<pros::Motor,2> MotorObjectList = {KickerMotor, IntakeMotor};

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