#include "main.h"

AutoGoalIntake* initAutoGoalIntake(GoalIntake* goalIntake, bool elevatorUp, bool elevatorDown, bool puncherOut, bool puncherIn)
{
  AutoGoalIntake* newStep = (AutoGoalIntake*) malloc(sizeof(AutoGoalIntake));

  newStep->goalIntake = goalIntake;
  newStep->elevatorUp = elevatorUp;
  newStep->elevatorDown = elevatorDown;
  newStep->puncherOut = puncherOut;
  newStep->puncherIn = puncherIn;
  newStep->isFinished = false;

  return newStep;
}

void autoGoalIntake(AutoGoalIntake* step)
{
	if(step->elevatorUp)
	{
		elevatorUp(step->goalIntake);
	}
	else if(step->elevatorDown)
	{
		elevatorDown(step->goalIntake);
	}
	
	if(step->puncherOut)
	{
		puncherOut(step->goalIntake);
	}
	else if(step->puncherIn)
	{
		puncherIn(step->goalIntake);
	}
	
	step->isFinished = true;
}