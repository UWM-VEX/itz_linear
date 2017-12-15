#include "main.h"

GoalIntake* initGoalIntake(int elevatorSol, int puncherSol)
{
  GoalIntake* newIntake = (GoalIntake*) malloc(sizeof(GoalIntake));

  pinMode(elevatorSol, OUTPUT);
  pinMode(puncherSol, OUTPUT);

  newIntake->elevatorSol = elevatorSol;
  newIntake->puncherSol = puncherSol;

  elevatorDown(newIntake);
  puncherIn(newIntake);

  return newIntake;
}

void elevatorUp(GoalIntake* goalIntake)
{
  elevatorSet(goalIntake, LOW);
}

void elevatorDown(GoalIntake* goalIntake)
{
  elevatorSet(goalIntake, HIGH);
}

void puncherOut(GoalIntake* goalIntake)
{
  puncherSet(goalIntake, HIGH);
}

void puncherIn(GoalIntake* goalIntake)
{
  puncherSet(goalIntake, LOW);
}

void elevatorSet(GoalIntake* goalIntake, int value)
{
  digitalWrite(goalIntake->elevatorSol, value);
}

void puncherSet(GoalIntake* goalIntake, int value)
{
  digitalWrite(goalIntake->puncherSol, value);
}
