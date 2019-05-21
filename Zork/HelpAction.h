#pragma once
#include "Action.h"
class HelpAction : public Action
{
public:
	HelpAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

