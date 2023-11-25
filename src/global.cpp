#include "main.h"

pros::Controller Controller(pros::E_CONTROLLER_MASTER);

/*
    Dead Ports: 5, 17 (last updated 11/17/23)
    Best Battery: 13
*/

pros::Motor BLMotor(-10, pros::v5::MotorGears::blue);
pros::Motor FLMotor(-9, pros::v5::MotorGears::blue);
pros::Motor BRMotor(18, pros::v5::MotorGears::blue);
pros::Motor FRMotor(19, pros::v5::MotorGears::blue);

pros::MotorGroup LMotors({-10, -9}, pros::v5::MotorGears::blue);
pros::MotorGroup RMotors({18, 19}, pros::v5::MotorGears::blue);

pros::Motor CataMotor1(-20, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);
pros::Motor CataMotor2(8, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);

pros::MotorGroup CataMotors({-20, 8}, pros::v5::MotorGears::red, pros::v5::MotorUnits::degrees);

pros::Motor IntakeMotor(11, pros::v5::MotorGears::blue);

pros::adi::DigitalOut WingPistons(1);

pros::Rotation CataSensor(1);

void ControllerDisplay() {
    if(!isReverse) Controller.print(0, 0, "Reversed: false");
    else if(isReverse) Controller.print(0, 0, "Reversed: true");
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
unsigned short int autonSelect;

/*
*   Integer variable to represent the current game phase: 
    1: Pre-Autonomous
    2: Autonomous
    3: Driver Control
*/
unsigned short int GamePhase = 1;

bool cataMoving = false;