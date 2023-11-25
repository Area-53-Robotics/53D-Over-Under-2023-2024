extern void drive(double length);
extern void drive(double length, unsigned short int velocity);
extern void turn(char direction, double length);
extern void turn(char direction, double length, unsigned short int velocity);
extern void AutonIntake(unsigned short int msec, bool isReverse);
extern void AutonCatapult();