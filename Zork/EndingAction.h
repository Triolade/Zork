#pragma once
#include "Action.h"
class EndingAction : public Action {
public:
	EndingAction();
	void execute() override;
	string getGeneratedOutput() override;
};

