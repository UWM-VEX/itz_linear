#include "main.h"

AutoWrist * initAutoWrist(Wrist* wrist, int position)
{
	AutoWrist* newStep = (AutoWrist*) malloc(sizeof(AutoWrist));
	
	newStep->wrist = wrist;
	newStep->position = position;
	newStep->isFinished = false;
	
	return newStep;
}

void autoWrist(AutoWrist* step)
{
	step->isFinished = wristToPosition(step->wrist, step->position);
}