#include "main.h"

/**
 * Initializes a new drive object composed of six PantherMotors, two encoders and a gyro.
 */
Drive* initDrive(PantherMotor frontLeftMotor, PantherMotor frontRightMotor,
		PantherMotor rearLeftMotor, PantherMotor rearRightMotor,
		Encoder leftEncoder, Encoder rightEncoder, Gyro gyro)
{
	Drive* newDrive = (Drive*) malloc(sizeof(Drive));

	newDrive->frontLeftMotor = frontLeftMotor;
	newDrive->frontRightMotor = frontRightMotor;
	newDrive->rearLeftMotor = rearLeftMotor;
	newDrive->rearRightMotor = rearRightMotor;
	newDrive->leftEncoder = leftEncoder;
	newDrive->rightEncoder = rightEncoder;
	newDrive->gyro = gyro;

	return newDrive;
}

void tankDrive(Drive* drive, int left, int right)
{
	setPantherMotor(drive->frontLeftMotor, left);
	setPantherMotor(drive->frontRightMotor, right);
	setPantherMotor(drive->rearLeftMotor, left);
	setPantherMotor(drive->rearRightMotor, right);
}

void arcadeDrive(Drive* drive, int magnitude, int rotation)
{
	int left = magnitude + rotation;
	int right = magnitude - rotation;
	left = limit(left, 127, -127);
	right = limit(right, 127, -127);

	tankDrive(drive, left, right);
}
