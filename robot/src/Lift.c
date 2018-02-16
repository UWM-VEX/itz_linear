#include "main.h"

Lift* initLiftIO(int limitSwitch)
{
  Lift* newLift = (Lift*) malloc(sizeof(Lift));

  newLift->limitSwitch = limitSwitch;

  pinMode(limitSwitch, INPUT);

  return newLift;	
}

void initLift(Lift* lift, PantherMotor leftMotor, PantherMotor rightMotor, Encoder encoder)
{
  lift->leftMotor = leftMotor;
  lift->rightMotor = rightMotor;
  lift->encoder = encoder;
  lift->pid = initPIDController(1.0, 0, 0, 0, 0, 20);
}

void liftAtSpeed(Lift* lift, int speed)
{
  setPantherMotor(lift->leftMotor, speed);
  setPantherMotor(lift->rightMotor, speed);

  lcdPrint(uart1, 1, "Lift: %d", encoderGet(lift->encoder));
}

void liftProcess(Lift* lift)
{
  if(digitalRead(lift->limitSwitch) == LOW)
  {
    encoderReset(lift->encoder);
  }
}

bool liftToPosition(Lift* lift, int position, bool isFirstTime)
{
  PIDsetSetPoint(lift->pid, position);

  int deadband = 10;

  if(isFirstTime)
  {
    PIDReset(lift->pid);
  }

  int pidProcessVariable = encoderGet(lift->encoder);
  int output = PIDRunController(lift->pid, (double) pidProcessVariable);

  output = enforceDeadband(output, 0, deadband);

  liftAtSpeed(lift, output);

  return (output == 0);
}

bool liftFloorLoadPosition(Lift* lift, bool isFirstTime)
{
  return liftToPosition(lift, LIFT_FLOOR_LOAD, isFirstTime);
}

bool liftAutoLoadPosition(Lift* lift, bool isFirstTime)
{
  return liftToPosition(lift, LIFT_AUTO_LOAD, isFirstTime);
}

bool liftLowStackPosition(Lift* lift, bool isFirstTime)
{
  return liftToPosition(lift, LIFT_LOW_STACK, isFirstTime);
}

bool liftMidStackPosition(Lift* lift, bool isFirstTime)
{
  return liftToPosition(lift, LIFT_MID_STACK, isFirstTime);
}

bool liftHighStackPosition(Lift* lift, bool isFirstTime)
{
  return liftToPosition(lift, LIFT_HIGH_STACK, isFirstTime);
}

bool liftStationaryStackPosition(Lift* lift, bool isFirstTime)
{
  return liftToPosition(lift, LIFT_STATIONARY_STACK, isFirstTime);
}