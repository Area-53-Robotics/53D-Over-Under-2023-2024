#include "main.h"
short int LYAxis;
short int RYAxis;
void SetDriveMotors(){
    LYAxis = Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    RYAxis = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    if(abs(LYAxis) <= 10) LYAxis = 0;
    if(abs(RYAxis) <= 10) RYAxis = 0;
    BLMotor.move(GetCurveOutput(LYAxis));
    BRMotor.move(GetCurveOutput(RYAxis));
    FRMotor.move(GetCurveOutput(RYAxis));
    FLMotor.move(GetCurveOutput(LYAxis));
}
float GetCurveOutput(int input){
    return (std::exp(-20/12.7) + std::exp((std::abs(input) - 127) / 12.7) * (1 - std::exp(-20 / 12.7)));
}