#pragma once
#include "Action.h"
class OpenAction : public Action
{
public:
	OpenAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

