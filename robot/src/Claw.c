#include "main.h"

Claw* initClaw(PantherMotor motor)
{
  Claw* newClaw = (Claw*) malloc(sizeof(Claw));

  newClaw->motor = motor;

  return newClaw;
}

void clawToValue(Claw* claw, int value)
{
  value = limit(value, 127, -127);

  setPantherMotor(claw->motor, value);
}

void clawOpen(Claw* claw)
{
	clawToValue(claw, CLAW_OPEN);
}

void clawClose(Claw* claw)
{
	clawToValue(claw, CLAW_CLOSE);
}
