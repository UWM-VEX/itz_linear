#include "main.h"

GoalIntake* initGoalIntake(PantherMotor leftMotor, PantherMotor rightMotor)
{
  GoalIntake* newIntake = (GoalIntake*) malloc(sizeof(GoalIntake));

  newIntake->leftMotor = leftMotor;
  newIntake->rightMotor = rightMotor;

  return newIntake;
}

void goalIntakeAtSpeed(GoalIntake* goalIntake, int speed)
{
  speed = limit(speed, 127, -127);

  setPantherMotor(goalIntake->leftMotor, speed);
  setPantherMotor(goalIntake->rightMotor, speed);
}
