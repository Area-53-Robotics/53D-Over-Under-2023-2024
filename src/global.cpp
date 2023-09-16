#include "main.h"

pros:: Controller Controller(pros::E_CONTROLLER_MASTER);
pros:: Motor BLMotor(10, pros::v5::Motor_Gears::green);
pros:: Motor BRMotor(20, pros::v5::Motor_Gears::green);
pros:: Motor FLMotor(18, pros::v5::Motor_Gears::green);
pros:: Motor FRMotor(8, pros::v5::Motor_Gears::green);

void ControllerDisplay(){
    if(!isReverse) Controller.print(0, 0, "is Reversed: false" );
    else if (isReverse)  Controller.print(0, 0, "is Reversed: true" );
}
