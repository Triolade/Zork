#include "pch.h"
#include "PutAction.h"
#include "Player.h"


PutAction::PutAction(common_defs::tokens item, common_defs::tokens container)
{
	this->item = item;
	this->container = container;
}

void PutAction::execute()
{
	if (!Player::instance().isInInventory(item)) {
		generatedOutput = "You don't have that item in the inventory.";
	}
	else {
		if (!Player::instance().canFindContainer(container)) {
			generatedOutput = "You can't find that container in the room.";
		}
		else {
			generatedOutput = Player::instance().putItemIntoContainer(item, container);
		}
	}
}

string PutAction::getGeneratedOutput()
{
	return generatedOutput;
}