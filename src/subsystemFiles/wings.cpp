#include "main.h"
//sets the activation variable to false
bool wingPistonsActivated = false;
// if then sentence to set the activation value between true and false
void PneumaticWings() {
    if (!wingPistonsActivated) {
        WingPistons.set_value(1);
        wingPistonsActivated = true;
    } else {
        WingPistons.set_value(0);
        wingPistonsActivated = false;
    }
}