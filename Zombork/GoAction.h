#pragma once
#include "Action.h"
class GoAction : public Action
{
public:
	GoAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

