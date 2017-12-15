#include "main.h"

Wrist* initWristIO(int frontLimitSwitch, int rearLimitSwitch)
{
  Wrist* newWrist = (Wrist*) malloc(sizeof(Wrist));

  pinMode(frontLimitSwitch, INPUT);
  pinMode(rearLimitSwitch, INPUT);

  newWrist->frontLimitSwitch = frontLimitSwitch;
  newWrist->rearLimitSwitch = rearLimitSwitch;

  return newWrist;
}

void initWrist(Wrist* wrist, PantherMotor leftMotor, PantherMotor rightMotor, Encoder encoder, int middle)
{
  wrist->leftMotor = leftMotor;
  wrist->rightMotor = rightMotor;
  wrist->encoder = encoder;
  wrist->middle = middle;
}

bool wristToPosition(Wrist* wrist, int position)
{
  if(position == WRIST_FRONT)
  {
    wristAtSpeed(wrist, 127, false);
    return (digitalRead(wrist->frontLimitSwitch) == LOW);
  }
  else if(position == WRIST_REAR)
  {
    wristAtSpeed(wrist, -127, false);
    return (digitalRead(wrist->rearLimitSwitch) == LOW);
  }
  else if(position == WRIST_MIDDLE)
  {
    if(abs(encoderGet(wrist->encoder) - wrist->middle) < 50)
    {
	  lcdSetBacklight(uart1, true);
      wristAtSpeed(wrist, 0, false);
      return true;
    }
    else if(encoderGet(wrist->encoder) - wrist->middle > 200)
    {
	  lcdSetBacklight(uart1, false);
      wristAtSpeed(wrist, -70, false);
      return false;
    }
	else if(encoderGet(wrist->encoder) - wrist->middle > 0)
    {
	  lcdSetBacklight(uart1, false);
      wristAtSpeed(wrist, -50, false);
      return false;
    }
    else if(encoderGet(wrist->encoder) - wrist->middle < -200)
    {
	  lcdSetBacklight(uart1, false);
      wristAtSpeed(wrist, 70, false);
      return false;
    }
	else
	{
	  lcdSetBacklight(uart1, false);
	  wristAtSpeed(wrist, 50, false);
      return false;
	}
  }
  else
  {
    lcdSetBacklight(uart1, false);
    wristAtSpeed(wrist, 0, false);
    return false;
  }
}

void wristAtSpeed(Wrist* wrist, int speed, bool safetyOverride)
{
  if(digitalRead(wrist->frontLimitSwitch) == LOW)
  {
    encoderReset(wrist->encoder);
  }

  lcdPrint(uart1, 1, "Enc: %d", encoderGet(wrist->encoder));

  if( ! safetyOverride)
  {
    if(digitalRead(wrist->frontLimitSwitch) == LOW) // Front limit switch triggered
    {
      speed = limit(speed, 0, -127);
    }
    else if(digitalRead(wrist->rearLimitSwitch) == LOW) // Rear limit switch triggered
    {
      speed = limit(speed, 127, 0);
    }
  }

  setPantherMotor(wrist->leftMotor, speed);
  setPantherMotor(wrist->rightMotor, speed);
}
