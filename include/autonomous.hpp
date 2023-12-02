extern void drive(double length);
extern void drive(double length, unsigned short int velocity);
extern void turn(char direction, double length);
extern void turn(char direction, double length, unsigned short int velocity);
extern void AutonIntake(unsigned short int msec, bool isReverse);
extern void AutonCatapult();

// Temporary Drivetrain Auton Functions
extern void AutonDrive(double length, unsigned short int velocity, unsigned short int delay);
extern void AutonDrive(double length, unsigned short int delay);
extern void AutonTurn(char direction, double length, unsigned short int velocity, unsigned short int delay);
extern void AutonTurn(char direction, double length, unsigned short int delay);
// Temporary Drivetrain Auton Functions