#ifndef INCLUDE_AUTOCLAWHOLDER_H_
#define INCLUDE_AUTOCLAWHOLDER_H_

#include "main.h"

struct AutoClawHolder{
	ClawHolder* clawHolder;
	int position;
	int isFinished;
}typedef AutoClawHolder;

AutoClawHolder* initAutoClawHolder(ClawHolder* clawHolder, int position);
void autoClawHolder(AutoClawHolder* step);

#endif