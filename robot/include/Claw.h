#ifndef INCLUDE_CLAW_H_
#define INCLUDE_CLAW_H_

#include "main.h"

struct Claw{
  PantherMotor motor;
} typedef Claw;

Claw* initClaw(PantherMotor motor);
void clawAtSpeed(Claw* claw, int speed);

#endif
