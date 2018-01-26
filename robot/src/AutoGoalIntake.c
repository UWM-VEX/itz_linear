#include "main.h"

AutoGoalIntake* initAutoGoalIntake(GoalIntake* goalIntake, int position)
{
	AutoGoalIntake* newStep = (AutoGoalIntake*) malloc(sizeof(AutoGoalIntake));

	newStep->goalIntake = goalIntake;
	newStep->position = position;
	newStep->isFinished = false;

	return newStep;
}

void autoGoalIntake(AutoGoalIntake* step)
{
	step->isFinished = goalIntakeToPosition(step->goalIntake, step->position);
}