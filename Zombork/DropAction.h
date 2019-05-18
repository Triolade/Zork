#pragma once
#include "Action.h"
class DropAction : public Action
{
public:
	DropAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

