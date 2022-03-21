/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/ColorSensorV3.h>

class ColorSensor : public frc2::SubsystemBase {
	public:
	ColorSensor();
	frc::Color GetColor();
	int GetRed();
	int GetGreen();
	int GetBlue();
	int GetHue();
	double GetProximity();
	bool GetWithinRange();
	void Periodic();
	enum hues {kNone = -1, kRed = 0, kYellow = 1, kGreen = 2, kBlue = 3};

	private:
	rev::ColorSensorV3* colorSensor;
	rev::ColorSensorV3::RawColor* rawColor;
	frc::Color* color;
	int hue;
};
