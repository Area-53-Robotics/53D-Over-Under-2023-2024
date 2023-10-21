#include "api.h"

extern pros::Controller Controller;

extern pros::Motor BLMotor;
extern pros::Motor BRMotor;
extern pros::Motor FLMotor;
extern pros::Motor FRMotor;
extern pros::Motor CatapultMotor;

extern pros::MotorGroup LMotors;
extern pros::MotorGroup RMotors;

extern pros::ADIDigitalOut WingPistons;

extern pros::ADIDigitalIn CataLimitSwitch;

extern void ControllerDisplay();
unsigned short int GamePhase;