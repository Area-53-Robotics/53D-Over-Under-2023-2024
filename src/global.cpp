#include "main.h"

pros::Controller Controller(pros::E_CONTROLLER_MASTER);

/*
    Dead Ports: 3, 5, 7, 11, 12, 16, 19
    Best Battery: 13
*/

pros::MotorGroup LMotors({-18, -19}, pros::v5::Motor_Gears::blue);
pros::MotorGroup RMotors({6, 7}, pros::v5::Motor_Gears::blue);

pros::Motor CatapultMotor(-20, pros::v5::Motor_Gears::red, pros::v5::Motor_Encoder_Units::degrees);
pros::Motor IntakeMotor(4, pros::v5::Motor_Gears::blue);

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