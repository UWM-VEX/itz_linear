#include "main.h"

Roller* initRoller(PantherMotor leftMotor, PantherMotor rightMotor)
{
  Roller* newRoller = (Roller*) malloc(sizeof(Roller));

  newRoller->leftMotor = leftMotor;
  newRoller->rightMotor = rightMotor;

  return newRoller;
}

void rollerAtSpeed(Roller* roller, int speed)
{
  setPantherMotor(roller->leftMotor, speed);
  setPantherMotor(roller->rightMotor, speed);
}

void inRoller(Roller* roller)
{
  rollerAtSpeed(roller, 127);
}

void outRoller(Roller* roller)
{
  rollerAtSpeed(roller, -127);
}

void stopRoller(Roller* roller)
{
  rollerAtSpeed(roller, 0);
}
