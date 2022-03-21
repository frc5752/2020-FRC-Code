/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ColorSensor.h"

#include <iostream>

ColorSensor::ColorSensor(){
	colorSensor = new rev::ColorSensorV3(frc::I2C::Port::kOnboard);
	rawColor = new rev::ColorSensorV3::RawColor(0, 0, 0, 0);
	color = new frc::Color();
}
frc::Color ColorSensor::GetColor(){
	return *color;
}
int ColorSensor::GetRed(){
	return rawColor->red;
}
int ColorSensor::GetGreen(){
	return rawColor->green;
}
int ColorSensor::GetBlue(){
	return rawColor->blue;
}
int ColorSensor::GetHue(){
	return hue;
}
double ColorSensor::GetProximity(){
	return colorSensor->GetProximity();
}
// This method will be called once per scheduler run
void ColorSensor::Periodic(){
	rawColor->red = colorSensor->GetRawColor().red;
	rawColor->green = colorSensor->GetRawColor().green;
	rawColor->blue = colorSensor->GetRawColor().blue;
	color->red = colorSensor->GetColor().red;
	color->green = colorSensor->GetColor().green;
	color->blue = colorSensor->GetColor().blue;

	double rg = (double)rawColor->red / rawColor->green;
	double gr = (double)rawColor->green / rawColor->red;
	double gb = (double)rawColor->green / rawColor->blue;
	double bg = (double)rawColor->blue / rawColor->green;
	if(rawColor->red < 350 && rawColor->green < 520 && rawColor->blue < 300){
	 	hue = hues::kNone;
	}
	else if(gr / gb < 0.9){
		//green or blue
		if(rg > 0.7){
			hue = hues::kRed;
		}
		else{
			hue = hues::kYellow;
		}
	}
	else{
		//red or yellow
		if(bg > 0.53){
			hue = hues::kBlue;
		}
		else{
			hue = hues::kGreen;
		}
	}
}
