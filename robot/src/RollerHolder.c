#include "main.h"

RollerHolder* initRollerHolderIO(int limitSwitch)
{
  pinMode(limitSwitch, INPUT);

  RollerHolder* newRollerHolder = (RollerHolder*) malloc(sizeof(RollerHolder));

  newRollerHolder->limitSwitch = limitSwitch;

  return newRollerHolder;
}

void initRollerHolder(RollerHolder* rollerHolder, PantherMotor leftMotor, PantherMotor rightMotor, Encoder encoder)
{
  rollerHolder->leftMotor = leftMotor;
  rollerHolder->rightMotor = rightMotor;
  rollerHolder->encoder = encoder;
  rollerHolder->pid = initPIDController(0.5, 0, 0, 0, 0, 10);
}

void rollerHolderAtSpeed(RollerHolder* rollerHolder, int speed)
{
  speed = limit(speed, 127, -127);

  if(digitalRead(rollerHolder->limitSwitch) == LOW)
  {
    speed = limit(speed, 127, 0);
  }

  setPantherMotor(rollerHolder->leftMotor, speed);
  setPantherMotor(rollerHolder->rightMotor, speed);

  lcdPrint(uart1, 2, "CH: %d", encoderGet(rollerHolder->encoder));
}

void rollerHolderProcess(RollerHolder* rollerHolder)
{
  if(digitalRead(rollerHolder->limitSwitch) == LOW)
  {
    encoderReset(rollerHolder->encoder);
  }
}

bool rollerHolderToPosition(RollerHolder* rollerHolder, int position, bool isFirstTime)
{
  if(position == ROLLER_HOLDER_TO_LIMIT_SWITCH)
  {
    if( ! (digitalRead(rollerHolder->limitSwitch) == LOW))
    {
      rollerHolderAtSpeed(rollerHolder, -127);
      return false;
    }
    else
    {
      rollerHolderAtSpeed(rollerHolder, 0);
      return true;
    }
  }
  else
  {
    PIDsetSetPoint(rollerHolder->pid, position);

    int deadband = 10;

    if(isFirstTime)
    {
      PIDReset(rollerHolder->pid);
    }

    int pidProcessVariable = encoderGet(rollerHolder->encoder);
    int output = PIDRunController(rollerHolder->pid, (double) pidProcessVariable);

    output = enforceDeadband(output, 0, deadband);

    rollerHolderAtSpeed(rollerHolder, output);

    return (output == 0);
  }
}

bool rollerHolderLoadPosition(RollerHolder* rollerHolder, bool isFirstTime)
{
  return rollerHolderToPosition(rollerHolder, ROLLER_HOLDER_LOAD, isFirstTime);
}

bool rollerHolderStackPosition(RollerHolder* rollerHolder, bool isFirstTime)
{
  return rollerHolderToPosition(rollerHolder, ROLLER_HOLDER_STACK, isFirstTime);
} 

bool rollerHodlerPastStackingThreshold(RollerHolder* rollerHolder)
{
  return encoderGet(rollerHolder->encoder) > ROLLER_HOLDER_STACKING_THRESHOLD;
}