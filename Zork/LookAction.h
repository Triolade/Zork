#pragma once
#include "Action.h"
class LookAction : public Action
{
public:
	LookAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

