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
	return joystickGetAnalog(2,3);
}

int OIGetLiftFloorLoad()
{
	return joystickGetDigital(2, 7, JOY_DOWN);
}

int OIGetLiftAutoLoad()
{
	return joystickGetDigital(2, 7, JOY_UP);
}

int OIGetLiftLowStack()
{
	return joystickGetDigital(2, 8, JOY_DOWN);
}

int OIGetLiftMidStack()
{
	return joystickGetDigital(2, 8, JOY_LEFT);
}

int OIGetLiftHighStack()
{
	return joystickGetDigital(2, 8, JOY_RIGHT);
}

int OIGetLiftStationaryStack()
{
	return joystickGetDigital(2, 8, JOY_UP);
}

int OIGetClawHolder()
{
	return joystickGetAnalog(2,2);
}

int OIGetClawHolderLoad()
{
	return joystickGetDigital(2, 5, JOY_DOWN);
}

int OIGetClawHolderStack()
{
	return joystickGetDigital(2, 5, JOY_UP);
}

int OIGetClawOpen()
{
	return joystickGetDigital(1, 5, JOY_UP);
}

int OIGetClawClose()
{
	return joystickGetDigital(1, 6, JOY_UP);
}

int OIGetGoalIntakeRelease()
{
	return joystickGetDigital(2, 6, JOY_DOWN);
}

int OIGetGoalIntakeCarry()
{
	return joystickGetDigital(2, 6, JOY_UP);
}

int OIGetGoalIntakeScore()
{
	return joystickGetDigital(1, 6, JOY_DOWN);
}