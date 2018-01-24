#include "main.h"

AutoLift* initAutoLift(Lift* lift, int position)
{
	AutoLift* newStep = (AutoLift*) malloc(sizeof(AutoLift));

	newStep->lift = lift;
	newStep->position = position;
	newStep->isFinished = false;

	return newStep;
}

void autoLift(AutoLift* step)
{
	int isFirstTime = (autonomousInfo.step != autonomousInfo.lastStep);
	step->isFinished = liftToPosition(step->lift, step->position, isFirstTime);
}