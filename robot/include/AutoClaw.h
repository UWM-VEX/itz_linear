#ifndef INCLUDE_AUTOCLAW_H_
#define INCLUDE_AUTOCLAW_H_

#include "main.h"

struct AutoClaw{
	Claw* claw;
	int position;
	int isFinished;
}typedef AutoClaw;

AutoClaw* initAutoClaw(Claw* claw, int position);
void autoClaw(AutoClaw* step);

#endif