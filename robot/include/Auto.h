/*
 * Auto.h
 *
 *  Created on: Feb 25, 2015
 *      Author: Erik
 */

#ifndef AUTO_H_
#define AUTO_H_

/**
 * Reference type for information about the progress of autonomous mode.
 * the only instance of this type that should be used is autonomousInfo.
 */
struct AutonomousInfo{

	int step;
	int lastStep;
	int elapsedTime;
	int isFinished;

}typedef AutonomousInfo;

/**
 * Struct containing information about the autonomous mode.
 */
AutonomousInfo autonomousInfo;

int alliance;

#define RED 0
#define BLUE 1

#define red_(x) (alliance == RED) ? (x) : (-x)
#define blue_(x) (alliance == BLUE) ? (x) : (-x)
#define always_(x) x

// START OF MODES
#define DO_NOTHING 0
#define AL_20_L 1
#define AL_20_R 2
#define STRAIGHT 3
#define TEST 4
// END OF MODES

int autonomousSelection;

#endif /* AUTO_H_ */
