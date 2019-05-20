#include "pch.h"
#include "InvalidAction.h"


InvalidAction::InvalidAction()
{

}

void InvalidAction::execute()
{
	generatedOutput = "I didn't understand you. You can see all the commands with the command 'HELP'.";
}

string InvalidAction::getGeneratedOutput()
{
	return generatedOutput;
}