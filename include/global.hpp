extern pros::Controller Controller;

extern pros::Motor BLMotor;
extern pros::Motor FLMotor;
extern pros::Motor BRMotor;
extern pros::Motor FRMotor;

extern pros::MotorGroup LMotors;
extern pros::MotorGroup RMotors;

extern pros::Motor CataMotor1;
extern pros::Motor CataMotor2;

extern pros::MotorGroup CataMotors;

extern pros::Motor IntakeMotor;

extern pros::adi::DigitalOut WingPistons;

extern pros::Rotation CataSensor;

extern std::array<std::string,7> MotorNameList;
extern std::array<pros::Motor,7> MotorObjectList;

extern void ControllerDisplay();

extern unsigned short int autonSelect;
extern unsigned short int GamePhase;