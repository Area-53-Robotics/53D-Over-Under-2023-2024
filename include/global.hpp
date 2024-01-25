#include "main.h"

extern pros::Controller controller;

extern pros::MotorGroup LMotors;
extern pros::MotorGroup RMotors;

extern pros::Motor KickerMotor;

extern pros::Motor IntakeMotor;

extern pros::ADIDigitalOut HorizontalWingPistons;
extern pros::ADIDigitalOut VerticalWingPistons;

extern pros::IMU Inertial;

extern std::array<std::string,2> MotorNameList;
extern std::array<pros::Motor,2> MotorObjectList;

extern bool kickerOn;
extern bool drivetrainReversed;

extern void ControllerDisplay();

extern unsigned short int autonSelect;

extern unsigned short int GamePhase;