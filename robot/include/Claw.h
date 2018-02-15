#ifndef INCLUDE_CLAW_H_
#define INCLUDE_CLAW_H_

#include "main.h"

#define CLAW_OPEN 0
#define CLAW_CLOSE -127

struct Claw{
  PantherMotor motor;
} typedef Claw;

Claw* initClaw(PantherMotor motor);
void clawToValue(Claw* claw, int value);
void clawOpen(Claw* claw);
void clawClose(Claw* claw);

#endif
