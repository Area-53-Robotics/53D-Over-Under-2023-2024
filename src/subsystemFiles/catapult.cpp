#include "main.h"

extern void CatapultLoad() {
    CatapultMotor.move_velocity(200);
    if(CataLimitSwitch.get_new_press()) CatapultMotor.brake();
}