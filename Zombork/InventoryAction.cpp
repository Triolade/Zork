#include "pch.h"
#include "InventoryAction.h"
#include "Player.h"


void InventoryAction::execute()
{
	generatedOutput = Player::instance().describeInventory();
}

string InventoryAction::getGeneratedOutput()
{
	return generatedOutput;
}