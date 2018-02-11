#ifndef GOAL_INTAKE_H_
#define GOAL_INTAKE_H_

#include "main.h"

#define GOAL_INTAKE_DOWN 1670
#define GOAL_INTAKE_UP 2900
#define GOAL_INTAKE_STOP 0
#define GOAL_INTAKE_OPEN LOW
#define GOAL_INTAKE_CLOSE HIGH

struct GoalIntake{
  PantherMotor motor;
  int solenoid;
  int pot;
} typedef GoalIntake;

GoalIntake* initGoalIntakeIO(int solenoid);
void initGoalIntake(GoalIntake* goalIntake, PantherMotor motor, int pot);
void goalIntakeAtSpeed(GoalIntake* goalIntake, int speed);
bool goalIntakeToPosition(GoalIntake* goalIntake, int position);
bool goalIntakeUp(GoalIntake* goalIntake);
bool goalIntakeDown(GoalIntake* goalIntake);
void goalIntakePneumatics(GoalIntake* goalIntake, int position);
void goalIntakeOpen(GoalIntake* goalIntake);
void goalIntakeClose(GoalIntake* goalIntake);

#endif
