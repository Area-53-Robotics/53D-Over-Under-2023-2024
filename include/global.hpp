extern pros::Controller controller;


extern pros::MotorGroup LMotors;
extern pros::MotorGroup RMotors;

extern pros::Motor FlywheelMotor;
extern pros::Motor ArmMotor;

extern pros::Motor IntakeMotor;

extern pros::adi::DigitalOut WingPistons;

extern pros::Rotation CataSensor;

extern std::array<std::string,3> MotorNameList;
extern std::array<pros::Motor,3> MotorObjectList;

extern void ControllerDisplay();

extern unsigned short int autonSelect;
extern unsigned short int GamePhase;