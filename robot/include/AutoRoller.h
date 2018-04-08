#ifndef INCLUDE_AUTOROLLER_H_
#define INCLUDE_AUTOROLLER_H_

#include "main.h"

struct AutoRoller{
	Roller* roller;
	int position;
	int isFinished;
}typedef AutoRoller;

AutoRoller* initAutoRoller(Roller* roller, int position);
void autoRoller(AutoRoller* step);

#endif