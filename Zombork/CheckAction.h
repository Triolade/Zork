#pragma once
#include "Action.h"
class CheckAction : public Action
{
public:
	CheckAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

