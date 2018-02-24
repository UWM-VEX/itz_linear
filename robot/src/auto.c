/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions

related to it.
 *
 * Copyright (c) 2011-2014, Purdue University ACM SIG BOTS.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Purdue University ACM SIG BOTS nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source

code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task

with the default
 * priority and stack size whenever the robot is enabled via the Field Management

System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or

communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot

will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX

Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition

Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit.

If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */

/**
 * This is where you declare all of the actions the robot will take.
 * The options are DriveForTime which is useful for driving into something
 * but shouldn't be used elsewhere, DriveToWayPoint, which will handle
 * driving forward and back, strafing, and turning (turning must be in
 * its own step) and AutoLiftToHeight which will bring the lift to a
 * specified height (Note: Once the step where this function is used has
 * completed, the lift will move down due to gravity. To avoid this,
 * create a new AutoLiftToHeight function to keep the lift at the desired
 * height. Also, the lift to height code isn't perfectly tuned yet,
 * if the autonomous stalls with the autoLiftToHeight function, help the
 * lift up.)
 *
 * Running the pickup or spinner does not require an object to be declared
 * or instantiated, an example is shown below.
 */

int isAuto = 1;

long int stepStartTime;

int globalTimeout;

/**
 * Runs at the start of autonomous. Steps should be initialized here.
 */

DriveToWPProperties * defaultProps;
DriveToWPProperties * fastForward;

// START OF DECLARATIONS

AutoClaw * command1;
AutoGoalIntake * command2;

AutoClawHolder * command3;
Timeout * command4;
Timeout * command5;

DriveToWP * command6;
AutoLift * command7;
AutoClawHolder * command8;
Timeout * command9;

AutoClaw * command10;
Timeout * command11;
AutoLift * command12;
AutoClawHolder * command13;
Timeout * command14;
Timeout * command15;

DriveToWP * command16;
DriveToWP * command17;
DriveToWP * command18;
DriveToWP * command19;
DriveToWP * command20;
AutoGoalIntake * command21;
Timeout * command22;

DriveToWP * command23;
Timeout * command24;

DriveToWP * command25;
Timeout * command26;

AutoGoalIntake * command27;
Timeout * command28;

DriveToWP * command29;
Timeout * command30;

AutoGoalIntake * command31;
Timeout * command32;

Timeout * command33;
AutoGoalIntake * command34;
Timeout * command35;

DriveToWP * command36;
Timeout * command37;

DriveToWP * command38;
Timeout * command39;

DriveToWP * command40;
Timeout * command41;

DriveToWP * command42;
Timeout * command43;

DriveToWP * command44;
Timeout * command45;

AutoGoalIntake * command46;
Timeout * command47;

AutoGoalIntake * command48;
Timeout * command49;

AutoGoalIntake * command50;
Timeout * command51;

DriveToWP * command52;
Timeout * command53;


AutoClaw * command54;
AutoGoalIntake * command55;

AutoClawHolder * command56;
Timeout * command57;
Timeout * command58;

DriveToWP * command59;
AutoLift * command60;
AutoClawHolder * command61;
Timeout * command62;

AutoClaw * command63;
Timeout * command64;
AutoLift * command65;
AutoClawHolder * command66;
Timeout * command67;
Timeout * command68;

DriveToWP * command69;
DriveToWP * command70;
DriveToWP * command71;
DriveToWP * command72;
DriveToWP * command73;
AutoGoalIntake * command74;
Timeout * command75;

DriveToWP * command76;
Timeout * command77;

DriveToWP * command78;
Timeout * command79;

AutoGoalIntake * command80;
Timeout * command81;

DriveToWP * command82;
Timeout * command83;

AutoGoalIntake * command84;
Timeout * command85;

Timeout * command86;
AutoGoalIntake * command87;
Timeout * command88;

DriveToWP * command89;
Timeout * command90;

DriveToWP * command91;
Timeout * command92;

DriveToWP * command93;
Timeout * command94;

DriveToWP * command95;
Timeout * command96;

DriveToWP * command97;
Timeout * command98;

AutoGoalIntake * command99;
Timeout * command100;

AutoGoalIntake * command101;
Timeout * command102;

AutoGoalIntake * command103;
Timeout * command104;

DriveToWP * command105;
Timeout * command106;


AutoClaw * command107;
AutoGoalIntake * command108;

AutoClawHolder * command109;
Timeout * command110;
Timeout * command111;

DriveToWP * command112;
AutoGoalIntake * command113;
Timeout * command114;

AutoGoalIntake * command115;
Timeout * command116;

AutoGoalIntake * command117;
Timeout * command118;

DriveToWP * command119;


DriveToWP * command120;
DriveToWP * command121;
DriveToWP * command122;
DriveToWP * command123;
DriveToWP * command124;
DriveToWP * command125;

// END OF DECLARATIONS

void autonomousInit()
{
	/**
	 * Here, the different steps are instantiated and details are
	 * given about them. By hovering over the function name, you can see a
	 * list of the arguments to pass in.
	 */

	defaultProps = initDriveToWPProperties(robotDrive,
			0.5, 9, 1000, 127, 40, // MAG
			2, 20, 70, 30, 4, 1, 250); //ROT

	fastForward = initDriveToWPProperties(robotDrive,
			3, 1, 250, 127, 40, // MAG
			90, 10, 0, 0, 4, 1, 250); //ROT

	// START OF INSTANTIATIONS
if(autonomousSelection == DO_NOTHING)
{
}
if(autonomousSelection == AL_20_L)
{
	command1 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command2 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_OPEN);

	command3 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_TO_LIMIT_SWITCH);
	command4 = initTimeout(2000);
	command5 = initTimeout(4000);

	command6 = initDriveToWP(defaultProps, 14, 0);
	command7 = initAutoLift(robotLift, LIFT_STATIONARY_STACK);
	command8 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_STACK);
	command9 = initTimeout(3000);

	command10 = initAutoClaw(robotClaw, CLAW_OPEN);
	command11 = initTimeout(1000);
	command12 = initAutoLift(robotLift, LIFT_FLOOR_LOAD);
	command13 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_LOAD);
	command14 = initTimeout(1000);
	command15 = initTimeout(2000);

	command16 = initDriveToWP(defaultProps, -8, 0);
	command17 = initDriveToWP(defaultProps, 0, -80);
	command18 = initDriveToWP(defaultProps, 12, 0);
	command19 = initDriveToWP(defaultProps, 0, 45);
	command20 = initDriveToWP(defaultProps, 52, 0);
	command21 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command22 = initTimeout(4000);

	command23 = initDriveToWP(defaultProps, -18, 0);
	command24 = initTimeout(2000);

	command25 = initDriveToWP(defaultProps, 0, -20);
	command26 = initTimeout(2000);

	command27 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command28 = initTimeout(3000);

	command29 = initDriveToWP(defaultProps, 21, 0);
	command30 = initTimeout(2000);

	command31 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_CLOSE);
	command32 = initTimeout(1000);

	command33 = initTimeout(1000);
	command34 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_CLOSE);
	command35 = initTimeout(5000);

	command36 = initDriveToWP(defaultProps, -25, 0);
	command37 = initTimeout(1000);

	command38 = initDriveToWP(defaultProps, 0, -180);
	command39 = initTimeout(5000);

	command40 = initDriveToWP(fastForward, 42, 0);
	command41 = initTimeout(5000);

	command42 = initDriveToWP(defaultProps, 0, 50);
	command43 = initTimeout(3000);

	command44 = initDriveToWP(fastForward, 20, 0);
	command45 = initTimeout(5000);

	command46 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_CLOSE);
	command47 = initTimeout(1000);

	command48 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command49 = initTimeout(1000);

	command50 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_OPEN);
	command51 = initTimeout(3000);

	command52 = initDriveToWP(defaultProps, -20, 0);
	command53 = initTimeout(2000);

}
if(autonomousSelection == AL_20_R)
{
	command54 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command55 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_OPEN);

	command56 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_TO_LIMIT_SWITCH);
	command57 = initTimeout(2000);
	command58 = initTimeout(4000);

	command59 = initDriveToWP(defaultProps, 14, 0);
	command60 = initAutoLift(robotLift, LIFT_STATIONARY_STACK);
	command61 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_STACK);
	command62 = initTimeout(3000);

	command63 = initAutoClaw(robotClaw, CLAW_OPEN);
	command64 = initTimeout(1000);
	command65 = initAutoLift(robotLift, LIFT_FLOOR_LOAD);
	command66 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_LOAD);
	command67 = initTimeout(1000);
	command68 = initTimeout(2000);

	command69 = initDriveToWP(defaultProps, -8, 0);
	command70 = initDriveToWP(defaultProps, 0, 80);
	command71 = initDriveToWP(defaultProps, 12, 0);
	command72 = initDriveToWP(defaultProps, 0, -40);
	command73 = initDriveToWP(defaultProps, 52, 0);
	command74 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command75 = initTimeout(4000);

	command76 = initDriveToWP(defaultProps, -18, 0);
	command77 = initTimeout(2000);

	command78 = initDriveToWP(defaultProps, 0, 20);
	command79 = initTimeout(2000);

	command80 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command81 = initTimeout(3000);

	command82 = initDriveToWP(defaultProps, 21, 0);
	command83 = initTimeout(2000);

	command84 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_CLOSE);
	command85 = initTimeout(1000);

	command86 = initTimeout(1000);
	command87 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_CLOSE);
	command88 = initTimeout(5000);

	command89 = initDriveToWP(defaultProps, -25, 0);
	command90 = initTimeout(1000);

	command91 = initDriveToWP(defaultProps, 0, 180);
	command92 = initTimeout(5000);

	command93 = initDriveToWP(fastForward, 42, 0);
	command94 = initTimeout(5000);

	command95 = initDriveToWP(defaultProps, 0, -50);
	command96 = initTimeout(3000);

	command97 = initDriveToWP(fastForward, 20, 0);
	command98 = initTimeout(3000);

	command99 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_CLOSE);
	command100 = initTimeout(1000);

	command101 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command102 = initTimeout(1000);

	command103 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_OPEN);
	command104 = initTimeout(3000);

	command105 = initDriveToWP(defaultProps, -20, 0);
	command106 = initTimeout(2000);

}
if(autonomousSelection == STRAIGHT)
{
	command107 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command108 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_OPEN);

	command109 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_TO_LIMIT_SWITCH);
	command110 = initTimeout(2000);
	command111 = initTimeout(4000);

	command112 = initDriveToWP(defaultProps, 60, 0);
	command113 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command114 = initTimeout(5000);

	command115 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_CLOSE);
	command116 = initTimeout(1000);

	command117 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_CLOSE);
	command118 = initTimeout(3000);

	command119 = initDriveToWP(defaultProps, -36, 0);

}
if(autonomousSelection == TEST)
{
	command120 = initDriveToWP(defaultProps, 24, 0);
	command121 = initDriveToWP(defaultProps, -24, 0);
	command122 = initDriveToWP(defaultProps, 0, 90);
	command123 = initDriveToWP(defaultProps, 0, -90);
	command124 = initDriveToWP(defaultProps, 48, 0);
	command125 = initDriveToWP(defaultProps, -48, 0);
}
	// END OF INSTANTIATIONS

	autonomousInfo.lastStep = 0;
	autonomousInfo.step = 1;
	autonomousInfo.isFinished = 0;

	stepStartTime = millis();
}

/**
 * Runs continuously during autonomous, should exit relatively promptly.
 */
void autonomousPeriodic()
{
	if(autonomousInfo.step != autonomousInfo.lastStep)
	{
		stepStartTime = millis();
	}

	autonomousInfo.elapsedTime = millis() - stepStartTime;

	liftProcess(robotLift);
	clawHolderProcess(robotClawHolder);

	//lcdPrint(uart1, 1, "Step: %d", autonomousInfo.step);

	switch(autonomousSelection)
	{
	// START OF EXECUTIONS
		case(DO_NOTHING):
		switch(autonomousInfo.step)
		{


			default:
				isAuto = 0;
				break;
		}
		break;
		case(AL_20_L):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command1);
				autoGoalIntake(command2);
				autonomousInfo.isFinished = (*command1).isFinished && (*command2).isFinished;
				break;
			case(2):
				autoClawHolder(command3);
				timeout(command4);
				timeout(command5);
				autonomousInfo.isFinished = (*command3).isFinished && (*command4).isFinished || (*command5).isFinished;
				break;
			case(3):
				driveToWP(command6);

				autonomousInfo.isFinished = (*command6).isFinished;
				break;
			case(4):
				autoLift(command7);
				autoClawHolder(command8);
				timeout(command9);
				autonomousInfo.isFinished = (*command7).isFinished && (*command8).isFinished || (*command9).isFinished;
				break;
			case(5):
				autoClaw(command10);

				autonomousInfo.isFinished = (*command10).isFinished;
				break;
			case(6):
				timeout(command11);

				autonomousInfo.isFinished = (*command11).isFinished;
				break;
			case(7):
				autoLift(command12);
				autoClawHolder(command13);
				timeout(command14);
				timeout(command15);
				autonomousInfo.isFinished = (*command12).isFinished && (*command13).isFinished && (*command14).isFinished || (*command15).isFinished;
				break;
			case(8):
				driveToWP(command16);

				autonomousInfo.isFinished = (*command16).isFinished;
				break;
			case(9):
				driveToWP(command17);

				autonomousInfo.isFinished = (*command17).isFinished;
				break;
			case(10):
				driveToWP(command18);

				autonomousInfo.isFinished = (*command18).isFinished;
				break;
			case(11):
				driveToWP(command19);

				autonomousInfo.isFinished = (*command19).isFinished;
				break;
			case(12):
				driveToWP(command20);
				autoGoalIntake(command21);
				timeout(command22);
				autonomousInfo.isFinished = (*command20).isFinished && (*command21).isFinished || (*command22).isFinished;
				break;
			case(13):
				driveToWP(command23);
				timeout(command24);
				autonomousInfo.isFinished = (*command23).isFinished || (*command24).isFinished;
				break;
			case(14):
				driveToWP(command25);
				timeout(command26);
				autonomousInfo.isFinished = (*command25).isFinished || (*command26).isFinished;
				break;
			case(15):
				autoGoalIntake(command27);
				timeout(command28);
				autonomousInfo.isFinished = (*command27).isFinished || (*command28).isFinished;
				break;
			case(16):
				driveToWP(command29);
				timeout(command30);
				autonomousInfo.isFinished = (*command29).isFinished || (*command30).isFinished;
				break;
			case(17):
				autoGoalIntake(command31);
				timeout(command32);
				autonomousInfo.isFinished = (*command31).isFinished || (*command32).isFinished;
				break;
			case(18):
				timeout(command33);

				autonomousInfo.isFinished = (*command33).isFinished;
				break;
			case(19):
				autoGoalIntake(command34);
				timeout(command35);
				autonomousInfo.isFinished = (*command34).isFinished || (*command35).isFinished;
				break;
			case(20):
				driveToWP(command36);
				timeout(command37);
				autonomousInfo.isFinished = (*command36).isFinished || (*command37).isFinished;
				break;
			case(21):
				driveToWP(command38);
				timeout(command39);
				autonomousInfo.isFinished = (*command38).isFinished || (*command39).isFinished;
				break;
			case(22):
				driveToWP(command40);
				timeout(command41);
				autonomousInfo.isFinished = (*command40).isFinished || (*command41).isFinished;
				break;
			case(23):
				driveToWP(command42);
				timeout(command43);
				autonomousInfo.isFinished = (*command42).isFinished || (*command43).isFinished;
				break;
			case(24):
				driveToWP(command44);
				timeout(command45);
				autonomousInfo.isFinished = (*command44).isFinished || (*command45).isFinished;
				break;
			case(25):
				autoGoalIntake(command46);
				timeout(command47);
				autonomousInfo.isFinished = (*command46).isFinished || (*command47).isFinished;
				break;
			case(26):
				autoGoalIntake(command48);
				timeout(command49);
				autonomousInfo.isFinished = (*command48).isFinished || (*command49).isFinished;
				break;
			case(27):
				autoGoalIntake(command50);
				timeout(command51);
				autonomousInfo.isFinished = (*command50).isFinished || (*command51).isFinished;
				break;
			case(28):
				driveToWP(command52);
				timeout(command53);
				autonomousInfo.isFinished = (*command52).isFinished || (*command53).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(AL_20_R):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command54);
				autoGoalIntake(command55);
				autonomousInfo.isFinished = (*command54).isFinished && (*command55).isFinished;
				break;
			case(2):
				autoClawHolder(command56);
				timeout(command57);
				timeout(command58);
				autonomousInfo.isFinished = (*command56).isFinished && (*command57).isFinished || (*command58).isFinished;
				break;
			case(3):
				driveToWP(command59);

				autonomousInfo.isFinished = (*command59).isFinished;
				break;
			case(4):
				autoLift(command60);
				autoClawHolder(command61);
				timeout(command62);
				autonomousInfo.isFinished = (*command60).isFinished && (*command61).isFinished || (*command62).isFinished;
				break;
			case(5):
				autoClaw(command63);

				autonomousInfo.isFinished = (*command63).isFinished;
				break;
			case(6):
				timeout(command64);

				autonomousInfo.isFinished = (*command64).isFinished;
				break;
			case(7):
				autoLift(command65);
				autoClawHolder(command66);
				timeout(command67);
				timeout(command68);
				autonomousInfo.isFinished = (*command65).isFinished && (*command66).isFinished && (*command67).isFinished || (*command68).isFinished;
				break;
			case(8):
				driveToWP(command69);

				autonomousInfo.isFinished = (*command69).isFinished;
				break;
			case(9):
				driveToWP(command70);

				autonomousInfo.isFinished = (*command70).isFinished;
				break;
			case(10):
				driveToWP(command71);

				autonomousInfo.isFinished = (*command71).isFinished;
				break;
			case(11):
				driveToWP(command72);

				autonomousInfo.isFinished = (*command72).isFinished;
				break;
			case(12):
				driveToWP(command73);
				autoGoalIntake(command74);
				timeout(command75);
				autonomousInfo.isFinished = (*command73).isFinished && (*command74).isFinished || (*command75).isFinished;
				break;
			case(13):
				driveToWP(command76);
				timeout(command77);
				autonomousInfo.isFinished = (*command76).isFinished || (*command77).isFinished;
				break;
			case(14):
				driveToWP(command78);
				timeout(command79);
				autonomousInfo.isFinished = (*command78).isFinished || (*command79).isFinished;
				break;
			case(15):
				autoGoalIntake(command80);
				timeout(command81);
				autonomousInfo.isFinished = (*command80).isFinished || (*command81).isFinished;
				break;
			case(16):
				driveToWP(command82);
				timeout(command83);
				autonomousInfo.isFinished = (*command82).isFinished || (*command83).isFinished;
				break;
			case(17):
				autoGoalIntake(command84);
				timeout(command85);
				autonomousInfo.isFinished = (*command84).isFinished || (*command85).isFinished;
				break;
			case(18):
				timeout(command86);

				autonomousInfo.isFinished = (*command86).isFinished;
				break;
			case(19):
				autoGoalIntake(command87);
				timeout(command88);
				autonomousInfo.isFinished = (*command87).isFinished || (*command88).isFinished;
				break;
			case(20):
				driveToWP(command89);
				timeout(command90);
				autonomousInfo.isFinished = (*command89).isFinished || (*command90).isFinished;
				break;
			case(21):
				driveToWP(command91);
				timeout(command92);
				autonomousInfo.isFinished = (*command91).isFinished || (*command92).isFinished;
				break;
			case(22):
				driveToWP(command93);
				timeout(command94);
				autonomousInfo.isFinished = (*command93).isFinished || (*command94).isFinished;
				break;
			case(23):
				driveToWP(command95);
				timeout(command96);
				autonomousInfo.isFinished = (*command95).isFinished || (*command96).isFinished;
				break;
			case(24):
				driveToWP(command97);
				timeout(command98);
				autonomousInfo.isFinished = (*command97).isFinished || (*command98).isFinished;
				break;
			case(25):
				autoGoalIntake(command99);
				timeout(command100);
				autonomousInfo.isFinished = (*command99).isFinished || (*command100).isFinished;
				break;
			case(26):
				autoGoalIntake(command101);
				timeout(command102);
				autonomousInfo.isFinished = (*command101).isFinished || (*command102).isFinished;
				break;
			case(27):
				autoGoalIntake(command103);
				timeout(command104);
				autonomousInfo.isFinished = (*command103).isFinished || (*command104).isFinished;
				break;
			case(28):
				driveToWP(command105);
				timeout(command106);
				autonomousInfo.isFinished = (*command105).isFinished || (*command106).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(STRAIGHT):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command107);
				autoGoalIntake(command108);
				autonomousInfo.isFinished = (*command107).isFinished && (*command108).isFinished;
				break;
			case(2):
				autoClawHolder(command109);
				timeout(command110);
				timeout(command111);
				autonomousInfo.isFinished = (*command109).isFinished && (*command110).isFinished || (*command111).isFinished;
				break;
			case(3):
				driveToWP(command112);
				autoGoalIntake(command113);
				timeout(command114);
				autonomousInfo.isFinished = (*command112).isFinished && (*command113).isFinished || (*command114).isFinished;
				break;
			case(4):
				autoGoalIntake(command115);
				timeout(command116);
				autonomousInfo.isFinished = (*command115).isFinished || (*command116).isFinished;
				break;
			case(5):
				autoGoalIntake(command117);
				timeout(command118);
				autonomousInfo.isFinished = (*command117).isFinished || (*command118).isFinished;
				break;
			case(6):
				driveToWP(command119);
				autonomousInfo.isFinished = (*command119).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(TEST):
		switch(autonomousInfo.step)
		{
			case(1):
				driveToWP(command120);

				autonomousInfo.isFinished = (*command120).isFinished;
				break;
			case(2):
				driveToWP(command121);

				autonomousInfo.isFinished = (*command121).isFinished;
				break;
			case(3):
				driveToWP(command122);

				autonomousInfo.isFinished = (*command122).isFinished;
				break;
			case(4):
				driveToWP(command123);

				autonomousInfo.isFinished = (*command123).isFinished;
				break;
			case(5):
				driveToWP(command124);

				autonomousInfo.isFinished = (*command124).isFinished;
				break;
			case(6):
				driveToWP(command125);

				autonomousInfo.isFinished = (*command125).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
	// END OF EXECUTIONS

		default:
			isAuto = 0;
			break;
	}

	autonomousInfo.lastStep = autonomousInfo.step;

	//lcdPrint(uart1, 1, "Step: %d", autonomousInfo.step);

	if(autonomousInfo.isFinished)
	{
		autonomousInfo.step ++;
		autonomousInfo.isFinished = 0;
	}

}

void autonomous()
{
	lcdSetText(uart1, 1, "started");

	autonomousInit();

	//lcdSetText(uart1, 1, "initialized");

	while(isAuto)
	{
		autonomousPeriodic();

		if(isOnline())
		{
			if(!isAutonomous() || !isEnabled()) isAuto = 0;
		}

		delay(20);

		//puts("Autonomous");
	}
}
