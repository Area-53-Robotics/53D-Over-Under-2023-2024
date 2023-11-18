#include "main.h"

pros::Controller Controller(pros::E_CONTROLLER_MASTER);

/*
    Dead Ports: 5, 17 (last updated 11/17/23)
    Best Battery: 13
*/

pros::MotorGroup LMotors({-10, -9}, pros::v5::Motor_Gears::blue);
pros::MotorGroup RMotors({18, 19}, pros::v5::Motor_Gears::blue);

pros::MotorGroup CatapultMotors({-20, 8}, pros::v5::Motor_Gears::red, pros::v5::Motor_Encoder_Units::degrees);

pros::Motor IntakeMotor(11, pros::v5::Motor_Gears::blue);

pros::adi::DigitalOut WingPistons(1);

void ControllerDisplay() {
    if(!isReverse) Controller.print(0, 0, "Reversed: false");
    else if(isReverse) Controller.print(0, 0, "Reversed: true");
}

/*
*   Integer variable to represent the current game phase: 
    1: Pre-Autonomous
    2: Autonomous
    3: Driver Control
*/
unsigned short int GamePhase = 1;

bool cataMoving = false;