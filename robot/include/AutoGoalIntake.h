#ifndef AUTO_GOAL_INTAKE_H_
#define AUTO_GOAL_INTAKE_H_

#include "main.h"

struct AutoGoalIntake{
  bool isFinished;
  bool elevatorUp;
  bool elevatorDown;
  bool puncherOut;
  bool puncherIn;
  GoalIntake * goalIntake;
} typedef AutoGoalIntake;

AutoGoalIntake * initAutoGoalIntake(GoalIntake* goalIntake, bool elevatorUp, bool elevatorDown, bool puncherOut, bool puncherIn);
void autoGoalIntake(AutoGoalIntake* step);

#endif
