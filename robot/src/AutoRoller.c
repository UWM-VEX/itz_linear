#include "main.h"

AutoRoller* initAutoRoller(Roller* roller, int position)
{
	AutoRoller* newStep = (AutoRoller*) malloc(sizeof(AutoRoller));

	newStep->roller = roller;
	newStep->position = position;
	newStep->isFinished = false;

	return newStep;
}

void autoRoller(AutoRoller* step)
{
	rollerToValue(step->roller, step->position);

	step->isFinished = 1;
}