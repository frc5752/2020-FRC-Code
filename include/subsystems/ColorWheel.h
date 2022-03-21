/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <units/units.h>

class ColorWheel : public frc2::SubsystemBase {
	public:
	ColorWheel();
	bool IsAtTarget();
	int SetTargetRev(int r);
	void ResetTicks();
	void Clockwise(double speed);
	void Counterclockwise(double speed);
	void Stop();
	void Periodic();

	private:
	const static units::length COLOR_WHEEL_DIAMETER = 32_in;
	const static units::length MOTOR_WHEEL_DIAMETER = 4_in;
	const static int TICKS_PER_REVOLUTION = 12;
	int ticks = 0;
	int targetTicks = 0;
	TalonSRX* motorController;
};
