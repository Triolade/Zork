#include "pch.h"
#include "CheckAction.h"
#include "Player.h"


CheckAction::CheckAction(common_defs::tokens item)
{
	checkedItem = item;
}

void CheckAction::execute()
{
	if (Player::instance().isInInventory(checkedItem)) {
		generatedOutput = Player::instance().describeItemFromInventory(checkedItem);
	}
	else {
		generatedOutput = "That is not in your inventory.";
	}
	
}

string CheckAction::getGeneratedOutput()
{
	return generatedOutput;
}