#ifndef GOAL_INTAKE_H_
#define GOAL_INTAKE_H_

#include "main.h"

struct GoalIntake{
  PantherMotor leftMotor;
  PantherMotor rightMotor;
} typedef GoalIntake;

GoalIntake* initGoalIntake(PantherMotor leftMotor, PantherMotor rightMotor);
void goalIntakeAtSpeed(GoalIntake* goalIntake, int speed);

#endif
