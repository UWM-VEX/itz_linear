#ifndef INCLUDE_WRIST_H_
#define INCLUDE_WRIST_H_

#include "main.h"

struct Wrist{
  PantherMotor leftMotor;
  PantherMotor rightMotor;
  int frontLimitSwitch;
  int rearLimitSwitch;
  Encoder encoder;
  int middle;
} typedef Wrist;

#define WRIST_FRONT 0
#define WRIST_MIDDLE 1
#define WRIST_REAR 2

Wrist* initWristIO(int frontLimitSwitch, int rearLimitSwitch);
void initWrist(Wrist* wrist, PantherMotor leftMotor, PantherMotor rightMotor, Encoder encoder, int middle);
bool wristToPosition(Wrist* wrist, int position);
void wristAtSpeed(Wrist* wrist, int speed, bool safetyOverride);

#endif
