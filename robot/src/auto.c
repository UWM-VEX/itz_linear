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

Timeout * command3;
AutoClawHolder * command4;
Timeout * command5;

DriveToWP * command6;
AutoLift * command7;
AutoClawHolder * command8;
Timeout * command9;

AutoClaw * command10;
AutoLift * command11;
AutoClawHolder * command12;
Timeout * command13;

DriveToWP * command14;
DriveToWP * command15;
DriveToWP * command16;
DriveToWP * command17;
AutoGoalIntake * command18;
DriveToWP * command19;
Timeout * command20;

DriveToWP * command21;
Timeout * command22;

DriveToWP * command23;
Timeout * command24;

AutoGoalIntake * command25;
DriveToWP * command26;
Timeout * command27;

AutoGoalIntake * command28;
Timeout * command29;

DriveToWP * command30;
Timeout * command31;

DriveToWP * command32;
Timeout * command33;

DriveToWP * command34;
Timeout * command35;

DriveToWP * command36;
Timeout * command37;

DriveToWP * command38;
Timeout * command39;

AutoGoalIntake * command40;
Timeout * command41;

AutoGoalIntake * command42;
Timeout * command43;

DriveToWP * command44;
Timeout * command45;


DriveToWP * command46;
DriveToWP * command47;
DriveToWP * command48;
DriveToWP * command49;
DriveToWP * command50;
DriveToWP * command51;

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
if(autonomousSelection == AL_20)
{
	command1 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command2 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_OPEN);

	command3 = initTimeout(1000);
	command4 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_TO_LIMIT_SWITCH);
	command5 = initTimeout(2000);

	command6 = initDriveToWP(defaultProps, 12, 0);
	command7 = initAutoLift(robotLift, LIFT_STATIONARY_STACK);
	command8 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_STACK);
	command9 = initTimeout(5000);

	command10 = initAutoClaw(robotClaw, CLAW_OPEN);
	command11 = initAutoLift(robotLift, LIFT_FLOOR_LOAD);
	command12 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_LOAD);
	command13 = initTimeout(3000);

	command14 = initDriveToWP(defaultProps, -6, 0);
	command15 = initDriveToWP(defaultProps, 0, -90);
	command16 = initDriveToWP(defaultProps, 20, 0);
	command17 = initDriveToWP(defaultProps, 0, 57);
	command18 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_CLOSE);
	command19 = initDriveToWP(defaultProps, 52, 0);
	command20 = initTimeout(4000);

	command21 = initDriveToWP(defaultProps, -18, 0);
	command22 = initTimeout(2000);

	command23 = initDriveToWP(defaultProps, 0, -30);
	command24 = initTimeout(2000);

	command25 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command26 = initDriveToWP(defaultProps, 14, 0);
	command27 = initTimeout(2000);

	command28 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_CLOSE);
	command29 = initTimeout(5000);

	command30 = initDriveToWP(defaultProps, -14, 0);
	command31 = initTimeout(2000);

	command32 = initDriveToWP(defaultProps, 0, 30);
	command33 = initTimeout(2000);

	command34 = initDriveToWP(defaultProps, -48, 0);
	command35 = initTimeout(5000);

	command36 = initDriveToWP(defaultProps, 0, -130);
	command37 = initTimeout(5000);

	command38 = initDriveToWP(fastForward, 24, 0);
	command39 = initTimeout(2000);

	command40 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_CLOSE);
	command41 = initTimeout(1000);

	command42 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command43 = initTimeout(3000);

	command44 = initDriveToWP(defaultProps, -20, 0);
	command45 = initTimeout(2000);

}
if(autonomousSelection == TEST)
{
	command46 = initDriveToWP(defaultProps, 24, 0);
	command47 = initDriveToWP(defaultProps, -24, 0);
	command48 = initDriveToWP(defaultProps, 0, 90);
	command49 = initDriveToWP(defaultProps, 0, -90);
	command50 = initDriveToWP(defaultProps, 48, 0);
	command51 = initDriveToWP(defaultProps, -48, 0);
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
		case(AL_20):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command1);
				autoGoalIntake(command2);
				autonomousInfo.isFinished = (*command1).isFinished && (*command2).isFinished;
				break;
			case(2):
				timeout(command3);

				autonomousInfo.isFinished = (*command3).isFinished;
				break;
			case(3):
				autoClawHolder(command4);
				timeout(command5);
				autonomousInfo.isFinished = (*command4).isFinished || (*command5).isFinished;
				break;
			case(4):
				driveToWP(command6);

				autonomousInfo.isFinished = (*command6).isFinished;
				break;
			case(5):
				autoLift(command7);
				autoClawHolder(command8);
				timeout(command9);
				autonomousInfo.isFinished = (*command7).isFinished && (*command8).isFinished || (*command9).isFinished;
				break;
			case(6):
				autoClaw(command10);

				autonomousInfo.isFinished = (*command10).isFinished;
				break;
			case(7):
				autoLift(command11);
				autoClawHolder(command12);
				timeout(command13);
				autonomousInfo.isFinished = (*command11).isFinished && (*command12).isFinished || (*command13).isFinished;
				break;
			case(8):
				driveToWP(command14);

				autonomousInfo.isFinished = (*command14).isFinished;
				break;
			case(9):
				driveToWP(command15);

				autonomousInfo.isFinished = (*command15).isFinished;
				break;
			case(10):
				driveToWP(command16);

				autonomousInfo.isFinished = (*command16).isFinished;
				break;
			case(11):
				driveToWP(command17);

				autonomousInfo.isFinished = (*command17).isFinished;
				break;
			case(12):
				autoGoalIntake(command18);

				autonomousInfo.isFinished = (*command18).isFinished;
				break;
			case(13):
				driveToWP(command19);
				timeout(command20);
				autonomousInfo.isFinished = (*command19).isFinished || (*command20).isFinished;
				break;
			case(14):
				driveToWP(command21);
				timeout(command22);
				autonomousInfo.isFinished = (*command21).isFinished || (*command22).isFinished;
				break;
			case(15):
				driveToWP(command23);
				timeout(command24);
				autonomousInfo.isFinished = (*command23).isFinished || (*command24).isFinished;
				break;
			case(16):
				autoGoalIntake(command25);

				autonomousInfo.isFinished = (*command25).isFinished;
				break;
			case(17):
				driveToWP(command26);
				timeout(command27);
				autonomousInfo.isFinished = (*command26).isFinished || (*command27).isFinished;
				break;
			case(18):
				autoGoalIntake(command28);
				timeout(command29);
				autonomousInfo.isFinished = (*command28).isFinished || (*command29).isFinished;
				break;
			case(19):
				driveToWP(command30);
				timeout(command31);
				autonomousInfo.isFinished = (*command30).isFinished || (*command31).isFinished;
				break;
			case(20):
				driveToWP(command32);
				timeout(command33);
				autonomousInfo.isFinished = (*command32).isFinished || (*command33).isFinished;
				break;
			case(21):
				driveToWP(command34);
				timeout(command35);
				autonomousInfo.isFinished = (*command34).isFinished || (*command35).isFinished;
				break;
			case(22):
				driveToWP(command36);
				timeout(command37);
				autonomousInfo.isFinished = (*command36).isFinished || (*command37).isFinished;
				break;
			case(23):
				driveToWP(command38);
				timeout(command39);
				autonomousInfo.isFinished = (*command38).isFinished || (*command39).isFinished;
				break;
			case(24):
				autoGoalIntake(command40);
				timeout(command41);
				autonomousInfo.isFinished = (*command40).isFinished || (*command41).isFinished;
				break;
			case(25):
				autoGoalIntake(command42);
				timeout(command43);
				autonomousInfo.isFinished = (*command42).isFinished || (*command43).isFinished;
				break;
			case(26):
				driveToWP(command44);
				timeout(command45);
				autonomousInfo.isFinished = (*command44).isFinished || (*command45).isFinished;
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
				driveToWP(command46);

				autonomousInfo.isFinished = (*command46).isFinished;
				break;
			case(2):
				driveToWP(command47);

				autonomousInfo.isFinished = (*command47).isFinished;
				break;
			case(3):
				driveToWP(command48);

				autonomousInfo.isFinished = (*command48).isFinished;
				break;
			case(4):
				driveToWP(command49);

				autonomousInfo.isFinished = (*command49).isFinished;
				break;
			case(5):
				driveToWP(command50);

				autonomousInfo.isFinished = (*command50).isFinished;
				break;
			case(6):
				driveToWP(command51);

				autonomousInfo.isFinished = (*command51).isFinished;
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
