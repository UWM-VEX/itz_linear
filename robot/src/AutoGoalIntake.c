#include "main.h"

AutoGoalIntake* initAutoGoalIntake(GoalIntake* goalIntake, int upOrDown, int openOrClose)
{
	AutoGoalIntake* newStep = (AutoGoalIntake*) malloc(sizeof(AutoGoalIntake));

	newStep->goalIntake = goalIntake;
	newStep->upOrDown = upOrDown;
	newStep->openOrClose = openOrClose;
	newStep->isFinished = false;

	return newStep;
}

void autoGoalIntake(AutoGoalIntake* step)
{
	goalIntakePneumatics(step->goalIntake, step->openOrClose);
	step->isFinished = goalIntakeToPosition(step->goalIntake, step->upOrDown);
}