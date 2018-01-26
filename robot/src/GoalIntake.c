#include "main.h"

GoalIntake* initGoalIntakeIO(int solenoid)
{
  GoalIntake* newIntake = (GoalIntake*) malloc(sizeof(GoalIntake));

  newIntake->solenoid = solenoid;

  pinMode(solenoid, OUTPUT);

  return newIntake;
}

void initGoalIntake(GoalIntake* goalIntake, PantherMotor motor, int pot)
{
  goalIntake->motor = motor;
  goalIntake->pot = pot;
}

void goalIntakeAtSpeed(GoalIntake* goalIntake, int speed)
{
  speed = limit(speed, 127, -127);

  setPantherMotor(goalIntake->motor, speed);
}
