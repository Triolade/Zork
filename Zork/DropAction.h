#pragma once
#include "Action.h"
class DropAction : public Action
{
public:
	DropAction(common_defs::tokens item);
	
	void execute() override;
	string getGeneratedOutput() override;

private:
	common_defs::tokens droppedItem;
};

