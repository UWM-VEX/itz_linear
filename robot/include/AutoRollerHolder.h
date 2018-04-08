#ifndef INCLUDE_AUTOROLLERHOLDER_H_
#define INCLUDE_AUTOROLLERHOLDER_H_

#include "main.h"

struct AutoRollerHolder{
	RollerHolder* rollerHolder;
	int position;
	int isFinished;
}typedef AutoRollerHolder;

AutoRollerHolder* initAutoRollerHolder(RollerHolder* rollerHolder, int position);
void autoRollerHolder(AutoRollerHolder* step);

#endif