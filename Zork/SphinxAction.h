#pragma once
#include "Action.h"

class SphinxAction : public Action
{
public:
	SphinxAction();

	void execute() override;
	string getGeneratedOutput() override;
};

