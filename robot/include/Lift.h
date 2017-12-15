#ifndef INCLUDE_LIFT_H_
#define INCLUDE_LIFT_H_

#include "main.h"

struct Lift{
  PantherMotor leftMotor;
  PantherMotor rightMotor;
} typedef Lift;

Lift* initLift(PantherMotor leftMotor, PantherMotor rightMotor);
void liftAtSpeed(Lift* lift, int speed);

#endif
