#ifndef INCLUDE_WRIST_H_
#define INCLUDE_WRIST_H_

#include "main.h"

#define ROLLER_HOLDER_LOAD 0
#define ROLLER_HOLDER_STACK 260
#define ROLLER_HOLDER_STACKING_THRESHOLD 210
#define ROLLER_HOLDER_TO_LIMIT_SWITCH 1

struct RollerHolder{
  PantherMotor leftMotor;
  PantherMotor rightMotor;
  Encoder encoder;
  int limitSwitch;
  PIDController* pid;
} typedef RollerHolder;

RollerHolder* initRollerHolderIO(int limitSwitch);
void initRollerHolder(RollerHolder* rollerHolder, PantherMotor leftMotor, PantherMotor rightMotor, Encoder encoder);
void rollerHolderAtSpeed(RollerHolder* rollerHolder, int speed);
void rollerHolderProcess(RollerHolder* rollerHolder);
bool rollerHolderToPosition(RollerHolder* rollerHolder, int position, bool isFirstTime);
bool rollerHolderLoadPosition(RollerHolder* rollerHolder, bool isFirstTime);
bool rollerHolderStackPosition(RollerHolder* rollerHolder, bool isFirstTime);
bool rollerHodlerPastStackingThreshold(RollerHolder* rollerHolder);

#endif
