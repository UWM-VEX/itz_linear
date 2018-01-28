#ifndef INCLUDE_AUTOGOALINTAKE_H_
#define INCLUDE_AUTOGOALINTAKE_H_

#include "main.h"

struct AutoGoalIntake{
	GoalIntake* goalIntake;
	int upOrDown;
	int openOrClose;
	int isFinished;
}typedef AutoGoalIntake;

AutoGoalIntake* initAutoGoalIntake(GoalIntake* goalIntake, int upOrDown, int openOrClose);
void autoGoalIntake(AutoGoalIntake* step);

#endif