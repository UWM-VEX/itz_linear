#ifndef INCLUDE_AUTOGOALINTAKE_H_
#define INCLUDE_AUTOGOALINTAKE_H_

#include "main.h"

struct AutoGoalIntake{
	GoalIntake* goalIntake;
	int position;
	int isFinished;
}typedef AutoGoalIntake;

AutoGoalIntake* initAutoGoalIntake(GoalIntake* goalIntake, int position);
void autoGoalIntake(AutoGoalIntake* step);

#endif