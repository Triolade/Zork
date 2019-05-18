#pragma once
#include "Action.h"
class InvalidAction : public Action
{
public:
	InvalidAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

