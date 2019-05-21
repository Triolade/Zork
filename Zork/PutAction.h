#pragma once
#include "Action.h"
class PutAction : public Action
{
public:
	PutAction();
	
	void execute() override;
	string getGeneratedOutput() override;
};

