#ifndef INCLUDE_WRIST_H_
#define INCLUDE_WRIST_H_

#include "main.h"

#define CLAW_HOLDER_LOAD 100
#define CLAW_HOLDER_STACK 200

struct ClawHolder{
  PantherMotor leftMotor;
  PantherMotor rightMotor;
  Encoder encoder;
  int limitSwitch;
  PIDController* pid;
} typedef ClawHolder;

ClawHolder* initClawHolderIO(int limitSwitch);
void initClawHolder(ClawHolder* clawHolder, PantherMotor leftMotor, PantherMotor rightMotor, Encoder encoder);
void clawHolderAtSpeed(ClawHolder* clawHolder, int speed);
void clawHolderProcess(ClawHolder* clawHolder);
bool clawHolderToPosition(ClawHolder* clawHolder, int position, bool isFirstTime);
bool clawHolderLoadPosition(ClawHolder* clawHolder, bool isFirstTime);
bool clawHolderStackPosition(ClawHolder* clawHolder, bool isFirstTime);

#endif
