#pragma once
#include "Action.h"
class AttackAction : public Action
{
public:
	AttackAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

