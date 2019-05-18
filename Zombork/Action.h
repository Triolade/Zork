#pragma once

class Action
{
public:
	
	virtual void execute() = 0;
	virtual string getGeneratedOutput() = 0;

protected:
	string generatedOutput;
};

