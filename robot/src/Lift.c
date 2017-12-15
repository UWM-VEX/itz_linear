#include "main.h"

Lift* initLift(PantherMotor leftMotor, PantherMotor rightMotor)
{
  Lift* newLift = (Lift*) malloc(sizeof(Lift));

  newLift->leftMotor = leftMotor;
  newLift->rightMotor = rightMotor;

  return newLift;
}

void liftAtSpeed(Lift* lift, int speed)
{
  setPantherMotor(lift->leftMotor, speed);
  setPantherMotor(lift->rightMotor, speed);
}
