#include "pch.h"
#include "InventoryAction.h"
#include "Player.h"


void InventoryAction::execute()
{
	generatedOutput = Player::instance().describeSelf();
}

string InventoryAction::getGeneratedOutput()
{
	return generatedOutput;
}