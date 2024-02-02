extern pros::Controller controller;
extern pros::Motor BLMotor;
extern pros::Motor MLMotor;
extern pros::Motor FLMotor;

extern pros::Motor BRMotor;
extern pros::Motor MRMotor;
extern pros::Motor FRMotor;

extern pros::Motor_Group LMotors;
extern pros::Motor_Group RMotors;

extern pros::Motor KickerMotor;
extern pros::Motor IntakeMotor;

extern pros::ADIDigitalOut HorizontalWingPistons;
extern pros::ADIDigitalOut VerticalWingPistons;
extern pros::ADIDigitalOut HangingMech;

extern pros::IMU Inertial;
extern pros::Optical Optical;

extern bool kickerOn;
extern bool drivetrainReversed;
extern bool manualKicker;

extern void ControllerDisplay();

extern unsigned short int autonSelect;

extern unsigned short int GamePhase;

extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings linearController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;