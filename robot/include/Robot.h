/*
 * Robot.h
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#ifndef INCLUDE_ROBOT_H_
#define INCLUDE_ROBOT_H_

#include "main.h"

#define WHEEL_DIAMETER 2.5
#define IN 0
#define OUT 1

Drive * robotDrive;
Lift * robotLift;
Wrist * robotWrist;
Roller * robotRoller;
GoalIntake * robotGoalIntake;

#endif /* INCLUDE_ROBOT_H_ */
