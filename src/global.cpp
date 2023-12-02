#include "main.h"

pros::Controller Controller(pros::E_CONTROLLER_MASTER);

/*
    Dead Ports: 5, 16, 17 (last updated 12/1/23)
    Best Battery: 13
*/

pros::Motor BLMotor(-10, pros::v5::MotorGears::blue);
pros::Motor FLMotor(-9, pros::v5::MotorGears::blue);
pros::Motor BRMotor(18, pros::v5::MotorGears::blue);
pros::Motor FRMotor(19, pros::v5::MotorGears::blue);

pros::MotorGroup LMotors({-10, -9}, pros::v5::MotorGears::blue);
pros::MotorGroup RMotors({18, 19}, pros::v5::MotorGears::blue);

pros::Motor CataMotor1(-20, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);
pros::Motor CataMotor2(3, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);

pros::MotorGroup CataMotors({-20, 3}, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);

pros::Motor IntakeMotor(11, pros::v5::MotorGears::blue);

pros::adi::DigitalOut WingPistons(1);

std::array<std::string,7> MotorNameList = {"BL", "FL", "BR", "FR", "Cata1", "Cata2", "Intake"};
std::array<pros::Motor,7> MotorObjectList = {BLMotor, FLMotor, BRMotor, FRMotor, CataMotor1, CataMotor2, IntakeMotor};

pros::Rotation CataSensor(4);

void ControllerDisplay() {
    if(!isReverse) Controller.print(0, 0, "Reversed: false");
    else if(isReverse) Controller.print(0, 0, "Reversed: true");
    pros::delay(50);
    if (manualCata) Controller.print(1, 0, "Catapult: Manual");
    else if (!manualCata) Controller.print(1, 0, "Catapult: Auto");
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
unsigned short int autonSelect = 6;

/*
*   Integer variable to represent the current game phase: 
    1: Pre-Autonomous
    2: Autonomous
    3: Driver Control
*/
unsigned short int GamePhase = 1;