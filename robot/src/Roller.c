#include "main.h"

Roller* initRoller(PantherMotor motor)
{
  Roller* newRoller = (Roller*) malloc(sizeof(Roller));

  newRoller->motor = motor;

  return newRoller;
}

void rollerToValue(Roller* roller, int value)
{
  value = limit(value, 127, -127);

  setPantherMotor(roller->motor, value);
}

void rollerIn(Roller* roller)
{
	rollerToValue(roller, ROLLER_IN);
}

void rollerOut(Roller* roller)
{
	rollerToValue(roller, ROLLER_OUT);
}

void rollerStop(Roller* roller)
{
	rollerToValue(roller, ROLLER_STOP);
}
