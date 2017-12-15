#ifndef AUTO_WRIST_H_
#define AUTO_WRIST_H_

#include "main.h"

struct AutoWrist{
	Wrist* wrist;
	int position;
	bool isFinished;
} typedef AutoWrist;

AutoWrist * initAutoWrist(Wrist* wrist, int position);
void autoWrist(AutoWrist* step);

#endif