#ifndef INCLUDE_ROLLER_H_
#define INCLUDE_ROLLER_H_

#include "main.h"

struct Roller{
  PantherMotor leftMotor;
  PantherMotor rightMotor;
} typedef Roller;

Roller* initRoller(PantherMotor leftMotor, PantherMotor rightMotor);
void inRoller(Roller* roller);
void outRoller(Roller* roller);
void stopRoller(Roller* roller);
void rollerAtSpeed(Roller* roller, int speed);

#endif
