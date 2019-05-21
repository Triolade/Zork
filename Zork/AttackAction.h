#pragma once
#include "Action.h"
class AttackAction : public Action
{
public:
	AttackAction(common_defs::tokens enemy);
	
	void execute() override;
	string getGeneratedOutput() override;

private:
	common_defs::tokens enemy;
};

