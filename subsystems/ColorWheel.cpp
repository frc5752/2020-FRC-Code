/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ColorWheel.h"

ColorWheel::ColorWheel() {
	motorController = new TalonSRX(0);
}
bool ColorWheel::IsAtTarget(){
	ticks >= targetTicks;
}
void ColorWheel::SetTargetRev(int r){
	targetTicks = r * TICKS_PER_REVOLUTION * (COLOR_WHEEL_DIAMETER / MOTOR_WHEEL_DIAMETER);
}
void ColorWheel::ResetTicks(){
	ticks = 0;
}
void ColorWheel::Clockwise(double speed){
	motorController->SetInverted(false);
	motorController->Set(ControlMode::PercentOutput, speed);
}
void ColorWheel::Counterclockwise(double speed){
	motorController->SetInverted(true);
	motorController->Set(ControlMode::PercentOutput, speed);
}
void ColorWheel::Stop(){
	motorController->Set(ControlMode::PercentOutput, 0);
}




// This method will be called once per scheduler run
void ColorWheel::Periodic() {}
