
#pragma once

#include "frc/commands/Command.h"
#include "frc/commands/Subsystem.h"
#include "Robot.h"

class AutoTurn: public frc::Command {
public:
    AutoTurn();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:

};
