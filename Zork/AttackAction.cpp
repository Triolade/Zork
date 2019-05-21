#include "pch.h"
#include "AttackAction.h"
#include "Player.h"
#include "Utils.h"

AttackAction::AttackAction(common_defs::tokens enemy)
{
	this->enemy = enemy;
}

void AttackAction::execute()
{
	if (!Player::instance().canFindEnemy(enemy)) {
		generatedOutput = "That enemy is not in the current room.";
		return;
	}

	generatedOutput = Player::instance().attack(enemy);

}

string AttackAction::getGeneratedOutput()
{
	return generatedOutput;
}