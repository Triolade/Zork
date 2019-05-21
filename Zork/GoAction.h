#pragma once
#include "Action.h"
class GoAction : public Action
{
public:
	GoAction(common_defs::tokens direction);
	
	void execute() override;
	string getGeneratedOutput() override;

private:
	common_defs::tokens direction;
};

