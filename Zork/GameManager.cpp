#include "pch.h"
#include "GameManager.h"
#include "World.h"
#include "OutputManager.h"

void GameManager::startGame()
{
	World::instance().initWorld();
	string welcomeMessage = "--ZORK--\n\nOnce upon a time, in a random memory direction of a computer, your story begins.\n\nAfter days of travelling finally you are here.\nThe Great Dungeon is the final destination for the adventurers worth their salt.\nYou have been training for this all your life, filled with determination you take your first step to prove what are you worth at...\n\n" + Player::instance().lookAround();
	OutputManager::instance().printOutput(welcomeMessage);
}

void GameManager::endGame() 
{
	string endingMessage;
	switch (reason) {
	case (end_game_reason::DEATH):
		endingMessage = "At the end all your efforts have been in vain.\nYou remember all the happy moments in your life while your vision slowly fades away.\nIt was worth it. Finally, you can embrace the cold arms of death...";
		break;
	case (end_game_reason::GOOD_ENDING):
		endingMessage = "You proved to be both brave and pure.\nA hallo of light goes across the room directly to you.\nYou feel a warm sensation while you ascend to the pantheon of ancient gods, your new home.";
		break;
	case (end_game_reason::BAD_ENDING):
		endingMessage = "You haven't proved to be neither brave nor pure.\nA breach scrambles the ground and you fall directly to hell.";
		break;
	case (end_game_reason::PURE_ENDING):
		endingMessage = "You proved to be prue.\nA You leave the Great Dungeon plenty of satisfaction and dedicate your life to gods.";
		break;
	case (end_game_reason::BRAVE_ENDING):
		endingMessage = "You proved to be brave.\nA You leave the Great Dungeon covered in the blood of your enemies. You have become the greatest warrior ever lived.";
		break;
	default:
		throw "Incorrect ending game reason. This should never happen.";
	}
	
	OutputManager::instance().printOutput(endingMessage);
}

void GameManager::triggerGameEnding(end_game_reason reason)
{
	this->reason = reason;
	gameOver = true;
}

bool GameManager::hasEnded()
{
	return gameOver;
}

bool GameManager::isEventPending() {
	return triggeredEvent != NULL;
}

void GameManager::executePendingEvent() {
	triggeredEvent->execute();
	delete triggeredEvent;
	triggeredEvent = NULL;
}

void GameManager::setTriggeredEvent(Action *event) {
	triggeredEvent = event;
}

