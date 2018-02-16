#ifndef INCLUDE_LIFT_H_
#define INCLUDE_LIFT_H_

#include "main.h"

#define LIFT_FLOOR_LOAD 0
#define LIFT_AUTO_LOAD 125
#define LIFT_LOW_STACK 275
#define LIFT_MID_STACK 1471
#define LIFT_HIGH_STACK 2000
#define LIFT_STATIONARY_STACK 2000

struct Lift{
  PantherMotor leftMotor;
  PantherMotor rightMotor;
  Encoder encoder;
  int limitSwitch;
  PIDController* pid;
} typedef Lift;

Lift* initLiftIO(int limitSwitch);
void initLift(Lift* lift, PantherMotor leftMotor, PantherMotor rightMotor, Encoder encoder);
void liftAtSpeed(Lift* lift, int speed);
void liftProcess(Lift* lift);
bool liftToPosition(Lift* lift, int position, bool isFirstTime);
bool liftFloorLoadPosition(Lift* lift, bool isFirstTime);
bool liftAutoLoadPosition(Lift* lift, bool isFirstTime);
bool liftLowStackPosition(Lift* lift, bool isFirstTime);
bool liftMidStackPosition(Lift* lift, bool isFirstTime);
bool liftHighStackPosition(Lift* lift, bool isFirstTime);
bool liftStationaryStackPosition(Lift* lift, bool isFirstTime);

#endif
