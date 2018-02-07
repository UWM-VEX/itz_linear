#include "main.h"

AutoClaw* initAutoClaw(Claw* claw, int position)
{
	AutoClaw* newStep = (AutoClaw*) malloc(sizeof(AutoClaw));

	newStep->claw = claw;
	newStep->position = position;
	newStep->isFinished = false;

	return newStep;
}

void autoClaw(AutoClaw* step)
{
	clawToValue(step->claw, step->position);

	step->isFinished = 1;
}