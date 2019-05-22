#pragma once
#include "Action.h"
class PutAction : public Action
{
public:
	PutAction(common_defs::tokens item, common_defs::tokens container);
	
	void execute() override;
	string getGeneratedOutput() override;

private:
	common_defs::tokens item;
	common_defs::tokens container;
};

