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

bool goalIntakeToPosition(GoalIntake* goalIntake, int position)
{
	int currentPosition = analogRead(goalIntake->pot);
	if (abs(currentPosition - position) < 20)
	{
		goalIntakeAtSpeed(goalIntake, 0);
		return true;
	}
	else if (currentPosition > position)
	{
		goalIntakeAtSpeed(goalIntake, -50);
		return false;
	}
	else if (currentPosition < position)
	{
		goalIntakeAtSpeed(goalIntake, 50);
		return false;
	}
}