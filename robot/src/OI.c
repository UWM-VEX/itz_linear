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

int OIGetLiftFloorLoad()
{
	return joystickGetDigital(2, 7, JOY_DOWN);
}

int OIGetLiftAutoLoad()
{
	return joystickGetDigital(2, 7, JOY_DOWN);
}

int OIGetLiftLowStack()
{
	return joystickGetDigital(2, 7, JOY_DOWN);
}

int OIGetLiftMidStack()
{
	return joystickGetDigital(2, 7, JOY_DOWN);
}

int OIGetLiftHighStack()
{
	return joystickGetDigital(2, 7, JOY_DOWN);
}

int OIGetLiftStationaryStack()
{
	return joystickGetDigital(2, 7, JOY_DOWN);
}

int OIGetClawHolder()
{
	return -joystickGetAnalog(2,2);
}

int OIGetClawHolderLoad()
{
	return joystickGetDigital(2, 7, JOY_DOWN);
}

int OIGetClawHolderStack()
{
	return joystickGetDigital(2, 7, JOY_UP);
}

int OIGetClaw()
{
	return joystickGetAnalog(2,1);
}

int OIGetGoalIntakeUp()
{
	return joystickGetDigital(2, 5, JOY_UP);
}

int OIGetGoalIntakeDown()
{
	return joystickGetDigital(2, 5, JOY_DOWN);
}

int OIGetGoalIntakeOpen()
{
	return joystickGetDigital(2, 6, JOY_UP);
}

int OIGetGoalIntakeClose()
{
	return joystickGetDigital(2, 6, JOY_DOWN);
}