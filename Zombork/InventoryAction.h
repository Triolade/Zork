#pragma once
#include "Action.h"
class InventoryAction : public Action
{

public:
	void execute() override;
	string getGeneratedOutput() override;
};

