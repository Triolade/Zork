#include "pch.h"
#include "EndingAction.h"
#include "Player.h"
#include "GameManager.h"

EndingAction::EndingAction() {};

void EndingAction::execute() {
	if (!Player::instance().isInInventory(common_defs::BLESSED_APPLE) & !Player::instance().isInInventory(common_defs::DRAGONS_HEART)) {
		GameManager::instance().triggerGameEnding(GameManager::end_game_reason::BAD_ENDING);
	}
	else if (Player::instance().isInInventory(common_defs::BLESSED_APPLE) & !Player::instance().isInInventory(common_defs::DRAGONS_HEART)) {
		GameManager::instance().triggerGameEnding(GameManager::end_game_reason::PURE_ENDING);
	}
	else if (!Player::instance().isInInventory(common_defs::BLESSED_APPLE) & Player::instance().isInInventory(common_defs::DRAGONS_HEART)) {
		GameManager::instance().triggerGameEnding(GameManager::end_game_reason::BRAVE_ENDING);
	}
	else {
		GameManager::instance().triggerGameEnding(GameManager::end_game_reason::GOOD_ENDING);
	}

}

string EndingAction::getGeneratedOutput() {
	return "";
}


