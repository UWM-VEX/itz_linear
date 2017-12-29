#ifndef INCLUDE_WRIST_H_
#define INCLUDE_WRIST_H_

#include "main.h"

struct ClawHolder{
  PantherMotor leftMotor;
  PantherMotor rightMotor;
} typedef ClawHolder;

ClawHolder* initClawHolder(PantherMotor leftMotor, PantherMotor rightMotor);
void clawHolderAtSpeed(ClawHolder* clawHolder, int speed);

#endif
