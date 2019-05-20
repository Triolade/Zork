#include "pch.h"
#include "LookAction.h"
#include "Player.h"

LookAction::LookAction()
{

}

void LookAction::execute()
{
	generatedOutput = Player::instance().lookAround();
}

string LookAction::getGeneratedOutput()
{
	return generatedOutput;
}