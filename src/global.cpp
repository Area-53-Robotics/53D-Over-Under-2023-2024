#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

/*
    Dead Ports: 5, 10, 16, 17 (last updated 12/9/23)
    Best Battery: 13
*/

//creates motor groups
pros::MotorGroup LMotors({-8, -9,-17}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::rotations);
pros::MotorGroup RMotors({18, 19,20}, pros::v5::MotorGears::blue, pros::v5::MotorEncoderUnits::rotations);

//creates the motors for op control
pros::Motor FlywheelMotor(15, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);
pros::Motor ArmMotor(7, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);

pros::Motor IntakeMotor(11, pros::v5::MotorGears::blue);

pros::adi::DigitalOut WingPistons(2);

std::array<std::string,3> MotorNameList = { "Arm", "Flywheel", "Intake"};
std::array<pros::Motor,3> MotorObjectList = {ArmMotor, FlywheelMotor, IntakeMotor};
//Rptation sensor
pros::Rotation CataSensor(4);
//Reverse function
void ControllerDisplay() {
    if(!isReverse) controller.print(0, 0, "Reversed: false");
    else if(isReverse) controller.print(0, 0, "Reversed: true");
    pros::delay(50);
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