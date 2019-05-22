#include "pch.h"
#include "BlessedAppleAction.h"
#include "ItemFactory.h"
#include "Player.h"

BlessedAppleAction::BlessedAppleAction()
{
}

void BlessedAppleAction::execute() {
	Item blessedApple = ItemFactory::createBlessedApple();
	Player::instance().pickItem(blessedApple);
}

string BlessedAppleAction::getGeneratedOutput() {
	return "You put the cursed apple in the chalice.\nIt emmits a blinding light, and transforms it.\nYou received the blessed apple!";
}
