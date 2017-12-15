#ifndef GOAL_INTAKE_H_
#define GOAL_INTAKE_H_

#include "main.h"

struct GoalIntake{
  int elevatorSol;
  int puncherSol;
} typedef GoalIntake;

GoalIntake* initGoalIntake(int elevatorSol, int puncherSol);
void elevatorUp(GoalIntake* goalIntake);
void elevatorDown(GoalIntake* goalIntake);
void puncherOut(GoalIntake* goalIntake);
void puncherIn(GoalIntake* goalIntake);
void elevatorSet(GoalIntake* goalIntake, int value);
void puncherSet(GoalIntake* goalIntake, int value);

#endif
