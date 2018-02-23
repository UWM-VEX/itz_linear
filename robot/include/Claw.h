#ifndef INCLUDE_CLAW_H_
#define INCLUDE_CLAW_H_

#include "main.h"

#define CLAW_OPEN 80
#define CLAW_CLOSE -50

struct Claw{
  PantherMotor motor;
} typedef Claw;

Claw* initClaw(PantherMotor motor);
void clawToValue(Claw* claw, int value);
void clawOpen(Claw* claw);
void clawClose(Claw* claw);

#endif
