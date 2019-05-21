#include "pch.h"
#include "GameManager.h"
#include "World.h"
#include "OutputManager.h"

void GameManager::startGame()
{
	World::instance().initWorld();
	string welcomeMessage = "--ZORK--\n\nOnce upon a time, in a random memory direction of a computer, your story begins.\n\nAfter days of travelling finally you are here.\nThe Great Dungeon is the final destination for the adventurers worth their salt.\nYou have been training for this all your life, filled with determination you take your first step to reach fame and glory...\n\n" + Player::instance().lookAround();
	OutputManager::instance().printOutput(welcomeMessage);
}

void GameManager::endGame() 
{
	string endingMessage;
	if (playerIsDead) {
		endingMessage = "At the end all your efforts have been in vain.\nYou remember all the happy moments in your life while your vision slowly fades away.\nIt was worth it. Finally, you can embrace the cold arms of death...";
	}
	else {
		endingMessage = "YEAH!";
	}
	OutputManager::instance().printOutput(endingMessage);
}

void GameManager::setGameOver(bool deadPlayer)
{
	playerIsDead = deadPlayer;
	gameOver = true;
}

bool GameManager::hasEnded()
{
	return gameOver;
}


