#include "main.h"

Claw* initClaw(PantherMotor motor)
{
  Claw* newClaw = (Claw*) malloc(sizeof(Claw));

  newClaw->motor = motor;

  return newClaw;
}

void clawAtSpeed(Claw* claw, int speed)
{
  speed = limit(speed, 127, -127);

  setPantherMotor(claw->motor, speed);
}
