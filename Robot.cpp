/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc2/command/CommandScheduler.h>

#include <rev/ColorSensorV3.h>

void Robot::RobotInit() {}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
	m_autonomousCommand = m_container.GetAutonomousCommand();

	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Schedule();
	}
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
	if(joystick->GetRawButton(11)){
		m_colorWheel->Clockwise(0.2);
	}
	else if(joystick->GetRawButton(12)){
		m_colorWheel->Counterclockwise(0.2);
	}
	else{
		m_colorWheel->Stop();
	}
	frc::SmartDashboard::PutString("DB/String 0", "RGB " + std::to_string(m_colorSensor->GetRed()) + " " + std::to_string(m_colorSensor->GetGreen()) + " " + std::to_string(m_colorSensor->GetBlue()));
	switch (m_colorSensor->GetHue()){
	case ColorSensor::hues::kRed:
		frc::SmartDashboard::PutString("DB/String 4", "Color: red");
		break;
	case ColorSensor::hues::kYellow:
		frc::SmartDashboard::PutString("DB/String 4", "Color: yellow");
		break;
	case ColorSensor::hues::kGreen:
		frc::SmartDashboard::PutString("DB/String 4", "Color: green");
		break;
	case ColorSensor::hues::kBlue:
		frc::SmartDashboard::PutString("DB/String 4", "Color: blue");
		break;
	default:
		frc::SmartDashboard::PutString("DB/String 4", "Color: none");
		break;
	}
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
