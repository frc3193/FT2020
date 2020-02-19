// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "frc/smartdashboard/SmartDashboard.h"
#include "Subsystems/DriveTrain.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/Drive.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
shiftSolenoid.reset(new frc::DoubleSolenoid(0, 4, 5));
AddChild("ShiftSolenoid", shiftSolenoid);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftA.reset(new rev::CANSparkMax(2,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
    leftB.reset(new rev::CANSparkMax(3,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
    rightA.reset(new rev::CANSparkMax(4,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
    rightB.reset(new rev::CANSparkMax(5,rev::CANSparkMaxLowLevel::MotorType::kBrushless));
    groupLeft.reset(new frc::SpeedControllerGroup(*leftA, *leftB));
    groupRight.reset(new frc::SpeedControllerGroup(*rightA, *rightB));

    diffDrive.reset(new frc::DifferentialDrive(*groupLeft, *groupRight));
    shiftSolenoid.reset(new frc::DoubleSolenoid(4, 5));
    shiftSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
    imu.reset(new frc::ADIS16448_IMU());
    imu->SetYawAxis(frc::ADIS16448_IMU::IMUAxis::kY);
    GyroMotor.reset(new WPI_TalonFX(12));
}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new Drive());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveTrain::Periodic() {
    // Put code here to be run every loop
    frc::SmartDashboard::PutNumber("GyroValue", imu->GetAngle());
    frc::SmartDashboard::PutNumber("MotorSpeedOutput", GyroMotor->GetSelectedSensorVelocity());
    frc::SmartDashboard::PutNumber("D leftA Pos", leftA->GetEncoder().GetPosition());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

