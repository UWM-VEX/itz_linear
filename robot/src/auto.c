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

// START OF DECLARATIONS

AutoClaw * command1;
AutoGoalIntake * command2;

DriveToWP * command3;
AutoLift * command4;
AutoClawHolder * command5;
Timeout * command6;

AutoClaw * command7;
AutoLift * command8;
AutoClawHolder * command9;
Timeout * command10;

DriveToWP * command11;
DriveToWP * command12;
DriveToWP * command13;
DriveToWP * command14;
DriveToWP * command15;
AutoGoalIntake * command16;
Timeout * command17;

DriveToWP * command18;
AutoGoalIntake * command19;
Timeout * command20;

AutoGoalIntake * command21;
Timeout * command22;

DriveToWP * command23;
Timeout * command24;

DriveToWP * command25;
Timeout * command26;

DriveToWP * command27;
Timeout * command28;

DriveToWP * command29;
Timeout * command30;

DriveToWP * command31;
Timeout * command32;

AutoGoalIntake * command33;
Timeout * command34;

AutoGoalIntake * command35;
Timeout * command36;

DriveToWP * command37;
Timeout * command38;


DriveToWP * command39;
DriveToWP * command40;
DriveToWP * command41;
DriveToWP * command42;
DriveToWP * command43;
DriveToWP * command44;

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
			2, 20, 70, 35, 4, 1, 250); //ROT

	// START OF INSTANTIATIONS
if(autonomousSelection == DO_NOTHING)
{
}
if(autonomousSelection == AL_20)
{
	command1 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command2 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_OPEN);

	command3 = initDriveToWP(defaultProps, 12, 0);
	command4 = initAutoLift(robotLift, LIFT_STATIONARY_STACK);
	command5 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_STACK);
	command6 = initTimeout(5000);

	command7 = initAutoClaw(robotClaw, CLAW_OPEN);
	command8 = initAutoLift(robotLift, LIFT_FLOOR_LOAD);
	command9 = initAutoClawHolder(robotClawHolder, CLAW_HOLDER_LOAD);
	command10 = initTimeout(3000);

	command11 = initDriveToWP(defaultProps, -6, 0);
	command12 = initDriveToWP(defaultProps, 0, -90);
	command13 = initDriveToWP(defaultProps, 20, 0);
	command14 = initDriveToWP(defaultProps, 0, 45);
	command15 = initDriveToWP(defaultProps, 24, 0);
	command16 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_CLOSE);
	command17 = initTimeout(5000);

	command18 = initDriveToWP(defaultProps, 24, 0);
	command19 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command20 = initTimeout(4000);

	command21 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_UP, GOAL_INTAKE_CLOSE);
	command22 = initTimeout(5000);

	command23 = initDriveToWP(defaultProps, -48, 0);
	command24 = initTimeout(5000);

	command25 = initDriveToWP(defaultProps, 0, -40);
	command26 = initTimeout(5000);

	command27 = initDriveToWP(defaultProps, -18, 0);
	command28 = initTimeout(3000);

	command29 = initDriveToWP(defaultProps, 0, -90);
	command30 = initTimeout(5000);

	command31 = initDriveToWP(defaultProps, 18, 0);
	command32 = initTimeout(2000);

	command33 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_CLOSE);
	command34 = initTimeout(1000);

	command35 = initAutoGoalIntake(robotGoalIntake, GOAL_INTAKE_DOWN, GOAL_INTAKE_OPEN);
	command36 = initTimeout(3000);

	command37 = initDriveToWP(defaultProps, -20, 0);
	command38 = initTimeout(2000);

}
if(autonomousSelection == TEST)
{
	command39 = initDriveToWP(defaultProps, 24, 0);
	command40 = initDriveToWP(defaultProps, -24, 0);
	command41 = initDriveToWP(defaultProps, 0, 90);
	command42 = initDriveToWP(defaultProps, 0, -90);
	command43 = initDriveToWP(defaultProps, 48, 0);
	command44 = initDriveToWP(defaultProps, -48, 0);
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
				driveToWP(command3);

				autonomousInfo.isFinished = (*command3).isFinished;
				break;
			case(3):
				autoLift(command4);
				autoClawHolder(command5);
				timeout(command6);
				autonomousInfo.isFinished = (*command4).isFinished && (*command5).isFinished || (*command6).isFinished;
				break;
			case(4):
				autoClaw(command7);

				autonomousInfo.isFinished = (*command7).isFinished;
				break;
			case(5):
				autoLift(command8);
				autoClawHolder(command9);
				timeout(command10);
				autonomousInfo.isFinished = (*command8).isFinished && (*command9).isFinished || (*command10).isFinished;
				break;
			case(6):
				driveToWP(command11);

				autonomousInfo.isFinished = (*command11).isFinished;
				break;
			case(7):
				driveToWP(command12);

				autonomousInfo.isFinished = (*command12).isFinished;
				break;
			case(8):
				driveToWP(command13);

				autonomousInfo.isFinished = (*command13).isFinished;
				break;
			case(9):
				driveToWP(command14);

				autonomousInfo.isFinished = (*command14).isFinished;
				break;
			case(10):
				driveToWP(command15);
				autoGoalIntake(command16);
				timeout(command17);
				autonomousInfo.isFinished = (*command15).isFinished && (*command16).isFinished || (*command17).isFinished;
				break;
			case(11):
				driveToWP(command18);
				autoGoalIntake(command19);
				timeout(command20);
				autonomousInfo.isFinished = (*command18).isFinished && (*command19).isFinished || (*command20).isFinished;
				break;
			case(12):
				autoGoalIntake(command21);
				timeout(command22);
				autonomousInfo.isFinished = (*command21).isFinished || (*command22).isFinished;
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
				driveToWP(command27);
				timeout(command28);
				autonomousInfo.isFinished = (*command27).isFinished || (*command28).isFinished;
				break;
			case(16):
				driveToWP(command29);
				timeout(command30);
				autonomousInfo.isFinished = (*command29).isFinished || (*command30).isFinished;
				break;
			case(17):
				driveToWP(command31);
				timeout(command32);
				autonomousInfo.isFinished = (*command31).isFinished || (*command32).isFinished;
				break;
			case(18):
				autoGoalIntake(command33);
				timeout(command34);
				autonomousInfo.isFinished = (*command33).isFinished || (*command34).isFinished;
				break;
			case(19):
				autoGoalIntake(command35);
				timeout(command36);
				autonomousInfo.isFinished = (*command35).isFinished || (*command36).isFinished;
				break;
			case(20):
				driveToWP(command37);
				timeout(command38);
				autonomousInfo.isFinished = (*command37).isFinished || (*command38).isFinished;
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
				driveToWP(command39);

				autonomousInfo.isFinished = (*command39).isFinished;
				break;
			case(2):
				driveToWP(command40);

				autonomousInfo.isFinished = (*command40).isFinished;
				break;
			case(3):
				driveToWP(command41);

				autonomousInfo.isFinished = (*command41).isFinished;
				break;
			case(4):
				driveToWP(command42);

				autonomousInfo.isFinished = (*command42).isFinished;
				break;
			case(5):
				driveToWP(command43);

				autonomousInfo.isFinished = (*command43).isFinished;
				break;
			case(6):
				driveToWP(command44);

				autonomousInfo.isFinished = (*command44).isFinished;
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
