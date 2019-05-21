#include "pch.h"
#include "OpenAction.h"
#include "Player.h"

OpenAction::OpenAction()
{

}

void OpenAction::execute()
{
	if (Player::instance().canSeeLockedDoor()) {
		if (Player::instance().isInInventory(common_defs::KEY)) {
			Player::instance().openLockedDoor();
			generatedOutput = "You opened the locked door. Key was broken in the process.";
		}
		else {
			generatedOutput = "You don't have a key to open the door.";
		}
	}
	else {
		generatedOutput = "There are no locked doors in this room.";
	}
}

string OpenAction::getGeneratedOutput()
{
	return generatedOutput;
}