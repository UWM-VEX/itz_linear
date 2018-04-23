#include "main.h"

GoalIntake* initGoalIntakeIO(int solenoid)
{
  GoalIntake* newIntake = (GoalIntake*) malloc(sizeof(GoalIntake));

  newIntake->solenoid = solenoid;

  pinMode(solenoid, OUTPUT);

  return newIntake;
}

void initGoalIntake(GoalIntake* goalIntake, PantherMotor motor, int topLimitSwitch, int bottomLimitSwitch)
{
  goalIntake->motor = motor;
  goalIntake->topLimitSwitch = topLimitSwitch;
  goalIntake->bottomLimitSwitch = bottomLimitSwitch;
}

void goalIntakeAtSpeed(GoalIntake* goalIntake, int speed)
{
  speed = limit(speed, 127, -127);

  setPantherMotor(goalIntake->motor, speed);

  lcdPrint(uart1, 1, "TopLS: %d", analogRead(goalIntake->topLimitSwitch));
}

bool goalIntakeToPosition(GoalIntake* goalIntake, int position)
{
	bool topLimitSwitchHit = (analogRead(goalIntake->topLimitSwitch) < 100);
	bool bottomLimitSwitchHit = (analogRead(goalIntake->bottomLimitSwitch) < 100);

	if(position == GOAL_INTAKE_UP)
	{
		if(topLimitSwitchHit)
		{
			goalIntakeAtSpeed(goalIntake, 0);
			return true;
		}
		else
		{
			goalIntakeAtSpeed(goalIntake, 127);
			return false;
		}
	}
	else if(position == GOAL_INTAKE_DOWN)
	{
		if(bottomLimitSwitchHit)
		{
			goalIntakeAtSpeed(goalIntake, 0);
			return true;
		}
		else
		{
			goalIntakeAtSpeed(goalIntake, -127);
			return false;
		}
	}

	return false; // Should never reach this
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

void goalIntakeClose(GoalIntake* goalIntake)
{
	goalIntakePneumatics(goalIntake, GOAL_INTAKE_CLOSE);
}