#pragma once
#include "Action.h"
class TakeAction : public Action
{
public:
	TakeAction(common_defs::tokens item);
	
	void execute() override;
	string getGeneratedOutput() override;

private: 
	common_defs::tokens pickedItem;
};

