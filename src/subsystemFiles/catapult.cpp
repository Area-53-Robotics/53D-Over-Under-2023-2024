#include "main.h"

/*
    1: Resetting
    2: Ready
    3: Pre-Launch
    4: Launching
*/
unsigned short int cataStatus = 2;

double cataPosition = CataSensor.get_position() / 100;
double cataVelocity = CataSensor.get_velocity() * 100;

bool manualCata = true;
bool cataMoving = false;

void runCatapult() {
    // int count = 0;
    while(true) {
        cataPosition = CataSensor.get_position() / 100;
        cataVelocity = CataSensor.get_velocity() * 100;
        
        // if(count % 7 == 0) std::cout << "Pos:" << cataPosition << ", Status: " << cataStatus << std::endl;
		// count++;

        if(manualCata) {
            if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) CataMotors.move(100);
            else CataMotors.brake();
        } else if(!manualCata) {
            if (cataPosition > 5) cataStatus = 1;

            if(cataStatus == 1) {
                if (cataPosition > 5) CataMotors.move(100);
                else cataStatus = 2;
            }

            if(cataStatus == 2) {
                CataMotors.brake();
            }

            if(cataStatus == 3) {
                if(cataVelocity <= 0) CataMotors.move(100);
                else if (cataVelocity > 0) cataStatus = 4;
            }

            if(cataStatus == 4) {
                if(cataVelocity < 1) cataStatus = 1;
            }

            if(Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) FireCatapult();
        }
        pros::delay(20);
    }
}

void SwitchCatapultMode() {
    manualCata = !manualCata;
    ControllerDisplay();
}

void FireCatapult() {
    if(!manualCata) {
        if(cataStatus == 2) cataStatus = 3;
    }
}