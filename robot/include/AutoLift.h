#ifndef INCLUDE_AUTOLIFT_H_
#define INCLUDE_AUTOLIFT_H_

#include "main.h"

struct AutoLift{
	Lift* lift;
	int position;
	int isFinished;
}typedef AutoLift;

AutoLift* initAutoLift(Lift* lift, int position);
void autoLift(AutoLift* step);

#endif