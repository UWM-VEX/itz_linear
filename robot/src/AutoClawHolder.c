#include "main.h"

AutoClawHolder* initAutoClawHolder(ClawHolder* clawHolder, int position)
{
	AutoClawHolder* newStep = (AutoClawHolder*) malloc(sizeof(AutoClawHolder));

	newStep->clawHolder = clawHolder;
	newStep->position = position;
	newStep->isFinished = false;

	return newStep;
}

void autoClawHolder(AutoClawHolder* step)
{
	int isFirstTime = (autonomousInfo.step != autonomousInfo.lastStep);
	step->isFinished = (clawHolderToPosition(step->clawHolder, step->position, isFirstTime)
		&& autonomousInfo.elapsedTime > 250);
}