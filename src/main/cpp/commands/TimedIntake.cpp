// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Commands/TimedIntake.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

TimedIntake::TimedIntake(double timeout) : frc::TimedCommand(timeout) {
    // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    Requires(Robot::intake.get());
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
TimedIntake::TimedIntake(double timeout, double speed) : frc::TimedCommand(timeout) {
    IntakeSpeed = speed;
    Requires(Robot::intake.get());



}
// Called just before this Command runs the first time
void TimedIntake::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TimedIntake::Execute() {
    Robot::intake->intakeMotor->Set(IntakeSpeed);
}

// Called once after command times out
void TimedIntake::End() {
Robot::intake->intakeMotor->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedIntake::Interrupted() {

}
