/**
 * File for operator control code.
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Copyright (c) 2011-2014, Purdue University ACM SIG BOTS. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of Purdue University ACM SIG BOTS nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 ********************************************************************************/

#include "main.h"

void teleopInit()
{
}

/**
 * Runs the user operator control code.
 *
 * This function will be started in its own task with the default priority and stack size whenever the robot is enabled via the Field Management System or the VEX Competition Switch in the operator control mode. If the robot is disabled or communications is lost, the operator control task will be stopped by the kernel. Re-enabling the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will run the operator control task. Be warned that this will also occur if the VEX Cortex is tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
void operatorControl()
{
	bool rollerHolderAutoMode = false;
	int rollerHolderPosition = ROLLER_HOLDER_LOAD;
	bool lastRollerHolderAutoMode = false;
	int lastRollerHolderPosition = ROLLER_HOLDER_LOAD;

	bool liftAutoMode = false;
	int liftPosition = LIFT_FLOOR_LOAD;
	bool lastLiftAutoMode = false;
	int lastLiftPosition = LIFT_FLOOR_LOAD;

	int goalIntakeState = GOAL_INTAKE_STOP;

	int rollerState = ROLLER_STOP;

	bool lastRollerIn = false;
	bool lastRollerOut = false;

	long goalIntakeUpTime = 0;

	teleopInit();

	while (true)
	{
		rollerHolderProcess(robotRollerHolder);
		liftProcess(robotLift);

		tankDrive(robotDrive, OIGetDriveLeft(), OIGetDriveRight());
		
		if(abs(OIGetLift()) > 20)
		{
			liftAutoMode = false;
			liftAtSpeed(robotLift, OIGetLift());
		}
		else
		{
			if(OIGetLiftFloorLoad())
			{
				liftAutoMode = true;
				liftPosition = LIFT_FLOOR_LOAD;

				rollerHolderPosition = ROLLER_HOLDER_LOAD;
				rollerHolderAutoMode = true;

				bool firstTime = ( ! lastLiftAutoMode) || (lastLiftPosition != LIFT_FLOOR_LOAD);

				liftFloorLoadPosition(robotLift, firstTime);
			}
			else if(OIGetLiftAutoLoad())
			{
				liftAutoMode = true;
				liftPosition = LIFT_AUTO_LOAD;

				rollerHolderPosition = ROLLER_HOLDER_LOAD;
				rollerHolderAutoMode = true;

				bool firstTime = ( ! lastLiftAutoMode) || (lastLiftPosition != LIFT_AUTO_LOAD);

				liftAutoLoadPosition(robotLift, firstTime);
			}
			else if(OIGetLiftLowStack())
			{
				liftAutoMode = true;
				liftPosition = LIFT_LOW_STACK;

				rollerHolderPosition = ROLLER_HOLDER_STACK;
				rollerHolderAutoMode = true;

				bool firstTime = ( ! lastLiftAutoMode) || (lastLiftPosition != LIFT_LOW_STACK);

				liftLowStackPosition(robotLift, firstTime);
			}
			else if(OIGetLiftMidStack())
			{
				liftAutoMode = true;
				liftPosition = LIFT_MID_STACK;

				rollerHolderPosition = ROLLER_HOLDER_STACK;
				rollerHolderAutoMode = true;

				bool firstTime = ( ! lastLiftAutoMode) || (lastLiftPosition != LIFT_MID_STACK);

				liftMidStackPosition(robotLift, firstTime);
			}
			else if(OIGetLiftHighStack())
			{
				liftAutoMode = true;
				liftPosition = LIFT_HIGH_STACK;

				rollerHolderPosition = ROLLER_HOLDER_STACK;
				rollerHolderAutoMode = true;

				bool firstTime = ( ! lastLiftAutoMode) || (lastLiftPosition != LIFT_HIGH_STACK);

				liftHighStackPosition(robotLift, firstTime);
			}
			else if(OIGetLiftStationaryStack())
			{
				liftAutoMode = true;
				liftPosition = LIFT_STATIONARY_STACK;

				rollerHolderPosition = ROLLER_HOLDER_STACK;
				rollerHolderAutoMode = true;

				bool firstTime = ( ! lastLiftAutoMode) || (lastLiftPosition != LIFT_STATIONARY_STACK);

				liftStationaryStackPosition(robotLift, firstTime);
			}
			else
			{
				if(liftAutoMode)
				{
					liftToPosition(robotLift, liftPosition, false);

					if(rollerHodlerPastStackingThreshold(robotRollerHolder))
					{
						rollerState = ROLLER_OUT;
					}
					else if(liftPosition == LIFT_LOW_STACK || liftPosition == LIFT_MID_STACK ||
						liftPosition == LIFT_HIGH_STACK || liftPosition == LIFT_STATIONARY_STACK)
					{
						rollerState = ROLLER_STOP;
					}
				}
				else
				{
					liftAtSpeed(robotLift, OIGetLift());
				}
			}
		}
		
		if(abs(OIGetRollerHolder()) > 20)
		{
			rollerHolderAutoMode = false;
			rollerHolderAtSpeed(robotRollerHolder, OIGetRollerHolder());
		}
		else
		{
			if(OIGetRollerHolderLoad())
			{
				rollerHolderAutoMode = true;
				rollerHolderPosition = ROLLER_HOLDER_LOAD;

				bool firstTime = ( ! lastRollerHolderAutoMode) || (lastRollerHolderPosition != ROLLER_HOLDER_LOAD);

				rollerHolderLoadPosition(robotRollerHolder, firstTime);
			}
			else if(OIGetRollerHolderStack())
			{
				rollerHolderAutoMode = true;
				rollerHolderPosition = ROLLER_HOLDER_STACK;

				bool firstTime = ( ! lastRollerHolderAutoMode) || (lastRollerHolderPosition != ROLLER_HOLDER_STACK);

				rollerHolderStackPosition(robotRollerHolder, firstTime);
			}
			else
			{
				if(rollerHolderAutoMode)
				{
					rollerHolderToPosition(robotRollerHolder, rollerHolderPosition, false);
				}
				else
				{
					rollerHolderAtSpeed(robotRollerHolder, OIGetRollerHolder());
				}
			}
		}

		if(OIGetGoalIntakeCarry())
		{
			//goalIntakeAtSpeed(robotGoalIntake, 127);
			goalIntakeState = GOAL_INTAKE_UP;
		}
		else if(OIGetGoalIntakeRelease())
		{
			//goalIntakeAtSpeed(robotGoalIntake, -127);
			goalIntakeState = GOAL_INTAKE_DOWN;
		}
		else if(OIGetGoalIntakeScore())
		{
			goalIntakeState = GOAL_INTAKE_SCORE;
		}

		if(goalIntakeState == GOAL_INTAKE_UP)
		{
			if(goalIntakeUpTime == 0)
			{
				goalIntakeUpTime = millis();
			}

			if(millis() - goalIntakeUpTime > 500)
			{
				goalIntakeUp(robotGoalIntake);
			}
			
			goalIntakeClose(robotGoalIntake);
		}
		else if(goalIntakeState == GOAL_INTAKE_DOWN)
		{
			goalIntakeUpTime = 0;

			if(goalIntakeDown(robotGoalIntake))
			{
				goalIntakeOpen(robotGoalIntake);
			}
		}
		else if(goalIntakeState == GOAL_INTAKE_SCORE)
		{
			goalIntakeUpTime = 0;

			goalIntakeUp(robotGoalIntake);
			goalIntakeOpen(robotGoalIntake);
		}
		else
		{
			goalIntakeUpTime = 0;
			
			goalIntakeAtSpeed(robotGoalIntake, 0);
		}

		if(OIGetRollerIn())
		{
			if(lastRollerIn)
			{
				rollerStop(robotRoller);
				rollerState = ROLLER_STOP;
			}
			else
			{
				rollerState = ROLLER_IN;
				rollerIn(robotRoller);
			}
			lastRollerIn = true;
			lastRollerOut = false;
		}
		else if(OIGetRollerOut())
		{
			if(lastRollerOut)
			{
				rollerStop(robotRoller);
				rollerState = ROLLER_STOP;
			}
			else
			{
				rollerState = ROLLER_OUT;
				rollerOut(robotRoller);
			}
			lastRollerIn = false;
			lastRollerOut = true;
		}
		else
		{
			rollerToValue(robotRoller, rollerState);
			lastRollerIn = false;
			lastRollerOut = false;
		}

		delay(25);
	}
}
