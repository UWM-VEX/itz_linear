#ifndef INCLUDE_ROLLER_H_
#define INCLUDE_ROLLER_H_

#include "main.h"

#define ROLLER_IN 127
#define ROLLER_OUT -50
#define ROLLER_STOP 0

struct Roller{
  PantherMotor motor;
} typedef Roller;

Roller* initRoller(PantherMotor motor);
void rollerToValue(Roller* roller, int value);
void rollerIn(Roller* roller);
void rollerOut(Roller* roller);
void rollerStop(Roller* roller);

#endif
