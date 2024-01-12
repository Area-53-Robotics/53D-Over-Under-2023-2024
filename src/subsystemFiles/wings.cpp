#include "main.h"
// Boolean variable to store whether the wings' pneumatic pistons have been activated, it is initialized as false
bool wingPistonsActivated = false;
// if then sentence to set the activation value between true and false
void PneumaticWings() {
    // When this function is called...
    if (!wingPistonsActivated) {
        // if the pneumatic pistons were not activated before, they become activated
        WingPistons.set_value(1);
        wingPistonsActivated = true;
    } else {
        // if the pneumatic pistons were activated before, they become deactivated
        WingPistons.set_value(0);
        wingPistonsActivated = false;
    }
}