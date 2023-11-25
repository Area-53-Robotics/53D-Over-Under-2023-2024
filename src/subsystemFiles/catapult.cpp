#include "main.h"

/*
    1: Resetting
    2: Ready
    3: Pre-Launch
    4: Launching
*/
unsigned short int cataStatus = 2;

double cataPosition = 0;
double cataVelocity = 0;

void runCatapult() {
    while(true) {
        cataPosition = CataSensor.get_angle() / 100;
        cataVelocity = CataSensor.get_velocity() * 100;

        if(cataStatus == 1) {
            if (cataPosition > 5) CataMotors.move(127);
            else cataStatus == 2;
        }

        if(cataStatus == 2) {
            CataMotors.brake();
        }

        if(cataStatus == 3) {
            if(cataVelocity >= 0) CataMotors.move(127);
            else if (cataVelocity < 0) cataStatus = 4;
        }

        if(cataStatus == 4) {
            if(cataVelocity < 1) cataStatus = 1;
        }

        pros::delay(20);
    }
}

void FireCatapult() {
    if(cataStatus == 2) cataStatus = 3;
}