#include "pch.h"
#include "TakeAction.h"
#include "Player.h"
#include "Utils.h"


TakeAction::TakeAction(common_defs::tokens item)
{
	pickedItem = item;
}

void TakeAction::execute()
{
	if (Player::instance().canFindItem(pickedItem)) {
		if (Utils::isWeapon(pickedItem)) {
			bool hadWeaponEquipped = Player::instance().hasWeaponEquipped();
			string weaponName = Player::instance().pickWeapon(pickedItem);
			generatedOutput = "You equipped the " + weaponName;

			if (hadWeaponEquipped) {
				generatedOutput = generatedOutput + " and you dropped your previous weapon.";
			}
			else {
				generatedOutput = generatedOutput + ".";
			}
		}
		else if (Utils::isItem(pickedItem)) {
			string itemName = Player::instance().pickItem(pickedItem);
			generatedOutput = "You picked the " + itemName + ".";		
		}
		else {
			throw "Incorrect picked item type, this should never happen";
		}
		
	}
	else {
		generatedOutput = "There is no such thing here.";
	}
}

string TakeAction::getGeneratedOutput()
{
	return generatedOutput;
}