/*
 * Robot.h
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_ROBOT_H_
#define INCLUDE_ROBOT_H_

#include "main.h"

#define WHEEL_DIAMETER 2.33
#define IN 0
#define OUT 1

Drive * robotDrive;
Lift * robotLift;
ClawHolder * robotClawHolder;
Claw * robotClaw;
GoalIntake * robotGoalIntake;

#endif /* INCLUDE_ROBOT_H_ */
