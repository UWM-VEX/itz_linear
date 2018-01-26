#ifndef GOAL_INTAKE_H_
#define GOAL_INTAKE_H_

#include "main.h"

#define GOAL_INTAKE_DOWN 100
#define GOAL_INTAKE_UP 3000

struct GoalIntake{
  PantherMotor motor;
  int solenoid;
  int pot;
} typedef GoalIntake;

GoalIntake* initGoalIntakeIO(int solenoid);
void initGoalIntake(GoalIntake* goalIntake, PantherMotor motor, int pot);
void goalIntakeAtSpeed(GoalIntake* goalIntake, int speed);
bool goalIntakeToPosition(GoalIntake* goalIntake, int position);

#endif
