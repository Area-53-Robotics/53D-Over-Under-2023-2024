#include "main.h"
pros:: Controller Controller;
pros:: Motor BLMotor;
pros:: Motor BRMotor;
pros:: Motor FLMotor;
pros:: Motor FRMotor;
void ControllerDisplay(){

    if(!isReverse) Controller.print(0, 0, "is Reversed: false" );
    else if (isReverse)  Controller.print(0, 0, "is Reversed: true" );
}
