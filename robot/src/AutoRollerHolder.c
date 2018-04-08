#include "main.h"

AutoRollerHolder* initAutoRollerHolder(RollerHolder* rollerHolder, int position)
{
	AutoRollerHolder* newStep = (AutoRollerHolder*) malloc(sizeof(AutoRollerHolder));

	newStep->rollerHolder = rollerHolder;
	newStep->position = position;
	newStep->isFinished = false;

	return newStep;
}

void autoRollerHolder(AutoRollerHolder* step)
{
	int isFirstTime = (autonomousInfo.step != autonomousInfo.lastStep);
	step->isFinished = (rollerHolderToPosition(step->rollerHolder, step->position, isFirstTime)
		&& autonomousInfo.elapsedTime > 250);
}