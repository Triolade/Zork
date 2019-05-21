#include "pch.h"
#include "EmptyAction.h"


EmptyAction::EmptyAction()
{

}

void EmptyAction::execute()
{
	generatedOutput = "Pardon?";
}

string EmptyAction::getGeneratedOutput()
{
	return generatedOutput;
}