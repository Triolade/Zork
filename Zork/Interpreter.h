#pragma once
#include "Action.h"

class Interpreter
{
public:
	Interpreter(vector<common_defs::tokens> tokens);

	Action* interpret();

private:
	vector<common_defs::tokens> tokens;

	Action* interpretOneTokenAction();
	Action* interpretTwoTokensAction();
	Action* interpretFourTokensAction();
};

