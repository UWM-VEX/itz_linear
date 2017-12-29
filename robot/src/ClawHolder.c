#include "main.h"

ClawHolder* initClawHolder(PantherMotor leftMotor, PantherMotor rightMotor)
{
  ClawHolder* newClawHolder = (ClawHolder*) malloc(sizeof(ClawHolder));

  newClawHolder->leftMotor = leftMotor;
  newClawHolder->rightMotor = rightMotor;

  return newClawHolder;
}

void clawHolderAtSpeed(ClawHolder* clawHolder, int speed)
{
  speed = limit(speed, 127, -127);

  setPantherMotor(clawHolder->leftMotor, speed);
  setPantherMotor(clawHolder->rightMotor, speed);
}
