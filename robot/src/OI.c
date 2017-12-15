/*
 * OI.c
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#include "main.h"

int OIGetDriveLeft()
{
	return enforceDeadband(joystickGetAnalog(1, 3), 0, 20);
}

int OIGetDriveRight()
{
	return enforceDeadband(joystickGetAnalog(1, 2), 0, 20);
}

int OIGetDriveY()
{
	return joystickGetAnalog(1, 3);
}

int OIGetDriveX()
{
	return joystickGetAnalog(1, 4);
}

int OIGetLift()
{
	return joystickGetAnalog(1,3);
}

int OIGetWrist()
{
	return -joystickGetAnalog(2,2);
}

bool OIGetWristFront()
{
	return joystickGetDigital(2, 8, JOY_UP);
}

bool OIGetWristMiddle()
{
	return joystickGetDigital(2, 8, JOY_RIGHT);
}

bool OIGetWristRear()
{
	return joystickGetDigital(2, 8, JOY_DOWN);
}

bool OIGetWristSafetyOverride()
{
	return joystickGetDigital(2, 6, JOY_UP) && joystickGetDigital(2, 6, JOY_DOWN);
}

bool OIInRoller()
{
	return joystickGetDigital(2, 5, JOY_UP);
}

bool OIOutRoller()
{
	return joystickGetDigital(2, 5, JOY_DOWN);
}

bool OIElevatorUp()
{
	return joystickGetDigital(2, 7, JOY_UP);
}

bool OIElevatorDown()
{
	return joystickGetDigital(2, 7, JOY_DOWN);
}

bool OIPuncherOut()
{
	return joystickGetDigital(2, 7, JOY_RIGHT);
}

bool OIPuncherIn()
{
	return joystickGetDigital(2, 7, JOY_LEFT);
}
