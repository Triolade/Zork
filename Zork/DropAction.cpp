#include "pch.h"
#include "DropAction.h"
#include "Player.h"


DropAction::DropAction(common_defs::tokens item)
{
	droppedItem = item;
}

void DropAction::execute()
{
	if (Player::instance().isInInventory(droppedItem)) {
		string itemName = Player::instance().dropItem(droppedItem);
		generatedOutput = "You dropped the " + itemName + '.';
	}
	else {
		generatedOutput = "That is not in your inventory.";
	}
	
}

string DropAction::getGeneratedOutput()
{
	return generatedOutput;
}