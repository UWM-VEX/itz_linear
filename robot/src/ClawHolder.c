#include "main.h"

ClawHolder* initClawHolderIO(int limitSwitch)
{
  pinMode(limitSwitch, INPUT);

  ClawHolder* newClawHolder = (ClawHolder*) malloc(sizeof(ClawHolder));

  newClawHolder->limitSwitch = limitSwitch;

  return newClawHolder;
}

void initClawHolder(ClawHolder* clawHolder, PantherMotor leftMotor, PantherMotor rightMotor, Encoder encoder)
{
  clawHolder->leftMotor = leftMotor;
  clawHolder->rightMotor = rightMotor;
  clawHolder->encoder = encoder;
  clawHolder->pid = initPIDController(1.0, 0, 0, 0, 0, 20);
}

void clawHolderAtSpeed(ClawHolder* clawHolder, int speed)
{
  speed = limit(speed, 127, -127);

  setPantherMotor(clawHolder->leftMotor, speed);
  setPantherMotor(clawHolder->rightMotor, speed);
}

void clawHolderProcess(ClawHolder* clawHolder)
{
  if(digitalRead(clawHolder->limitSwitch) == HIGH)
  {
    encoderReset(clawHolder->encoder);
  }
}

bool clawHolderToPosition(ClawHolder* clawHolder, int position, bool isFirstTime)
{
  int deadband = 10;

  if(isFirstTime)
  {
    PIDReset(clawHolder->pid);
  }

  int pidProcessVariable = encoderGet(clawHolder->encoder);
  int output = PIDRunController(clawHolder->pid, (double) pidProcessVariable);

  output = enforceDeadband(output, 0, deadband);

  clawHolderAtSpeed(clawHolder, output);

  return (output == 0);
}

bool clawHolderLoadPosition(ClawHolder* clawHolder, bool isFirstTime)
{
  return clawHolderToPosition(clawHolder, CLAW_HOLDER_LOAD, isFirstTime);
}

bool clawHolderStackPosition(ClawHolder* clawHolder, bool isFirstTime)
{
  return clawHolderToPosition(clawHolder, CLAW_HOLDER_STACK, isFirstTime);
} 