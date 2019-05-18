#pragma once
#include "Action.h"
class EmptyAction : public Action
{
public:
	EmptyAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

