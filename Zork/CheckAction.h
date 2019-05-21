#pragma once
#include "Action.h"
class CheckAction : public Action
{
public:
	CheckAction(common_defs::tokens item);
	
	void execute() override;
	string getGeneratedOutput() override;

private:
	common_defs::tokens checkedItem;
};

