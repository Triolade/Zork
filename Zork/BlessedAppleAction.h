#pragma once
#include "Action.h"
class BlessedAppleAction : public Action
{
public:
	BlessedAppleAction();

	void execute() override;
	string getGeneratedOutput() override;
};

