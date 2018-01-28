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
		goalIntakeAtSpeed(goalIntake, -127);
		return false;
	}
	else
	{
		goalIntakeAtSpeed(goalIntake, 127);
		return false;
	}
}

bool goalIntakeUp(GoalIntake* goalIntake)
{
	return goalIntakeToPosition(goalIntake, GOAL_INTAKE_UP);
}

bool goalIntakeDown(GoalIntake* goalIntake)
{
	return goalIntakeToPosition(goalIntake, GOAL_INTAKE_DOWN);
}

void goalIntakePneumatics(GoalIntake* goalIntake, int position)
{
	digitalWrite(goalIntake->solenoid, position);
}

void goalIntakeOpen(GoalIntake* goalIntake)
{
	goalIntakePneumatics(goalIntake, GOAL_INTAKE_OPEN);
}

void GoalIntakeClose(GoalIntake* goalIntake)
{
	goalIntakePneumatics(goalIntake, GOAL_INTAKE_CLOSE);
}