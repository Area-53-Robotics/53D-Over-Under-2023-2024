#include "main.h"

extern pros::Controller controller;

extern pros::MotorGroup LMotors;
extern pros::MotorGroup RMotors;

extern pros::MotorGroup Drivetrain;
extern pros::MotorGroup LTDrivetrain;
extern pros::MotorGroup RTDrivetrain;

extern pros::Motor KickerMotor;

extern pros::Motor IntakeMotor;

extern pros::adi::DigitalOut HorizontalWingPistons;
extern pros::adi::DigitalOut VerticalWingPistons;

extern pros::IMU Inertial;

extern pros::Optical Optical;

extern std::array<std::string,2> MotorNameList;
extern std::array<pros::Motor,2> MotorObjectList;

extern bool kickerOn;
extern bool drivetrainReversed;
extern bool manualKicker;

extern void ControllerDisplay();

extern unsigned short int autonSelect;

extern unsigned short int GamePhase;