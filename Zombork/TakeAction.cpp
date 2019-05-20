#include "pch.h"
#include "TakeAction.h"
#include "Player.h"


TakeAction::TakeAction(common_defs::tokens item)
{
	pickedItem = item;
}

void TakeAction::execute()
{
	if (Player::instance().canFindItem(pickedItem)) {
		string itemName = Player::instance().pickItem(pickedItem);
		generatedOutput = "You picked the " + itemName + ".";
	}
	else {
		generatedOutput = "There is no such thing here.";
	}
}

string TakeAction::getGeneratedOutput()
{
	return generatedOutput;
}