#include "pch.h"
#include "GoAction.h"
#include "Player.h"

GoAction::GoAction(common_defs::tokens direction) {
	this->direction = direction;
}

void GoAction::execute()
{
	if (Player::instance().canGoToDirection(direction)) {
		Player::instance().moveToDirection(direction);
		generatedOutput = Player::instance().lookAround();
	}
	else {
		generatedOutput = Player::instance().lookAtDirection(direction);
	}
}

string GoAction::getGeneratedOutput()
{
	return generatedOutput;
}