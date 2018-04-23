#ifndef GOAL_INTAKE_H_
#define GOAL_INTAKE_H_

#include "main.h"

#define GOAL_INTAKE_DOWN 1550
#define GOAL_INTAKE_UP 2650
#define GOAL_INTAKE_STOP 0
#define GOAL_INTAKE_OPEN LOW
#define GOAL_INTAKE_CLOSE HIGH
#define GOAL_INTAKE_SCORE 1

struct GoalIntake{
  PantherMotor motor;
  int solenoid;
  int topLimitSwitch;
  int bottomLimitSwitch;
} typedef GoalIntake;

GoalIntake* initGoalIntakeIO(int solenoid);
void initGoalIntake(GoalIntake* goalIntake, PantherMotor motor, int topLimitSwitch, int bottomLimitSwitch);
void goalIntakeAtSpeed(GoalIntake* goalIntake, int speed);
bool goalIntakeToPosition(GoalIntake* goalIntake, int position);
bool goalIntakeUp(GoalIntake* goalIntake);
bool goalIntakeDown(GoalIntake* goalIntake);
void goalIntakePneumatics(GoalIntake* goalIntake, int position);
void goalIntakeOpen(GoalIntake* goalIntake);
void goalIntakeClose(GoalIntake* goalIntake);

#endif
