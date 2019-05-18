#pragma once
#include "Action.h"
class TakeAction : public Action
{
public:
	TakeAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

