#include "pch.h"
#include "GameManager.h"
#include "World.h"
#include "OutputManager.h"

void GameManager::startGame()
{
	World::instance().initWorld();
	string welcomeMessage = "Welcome to Zombork!\n\n" + Player::instance().lookAround();
	OutputManager::instance().printOutput(welcomeMessage);
}

void GameManager::setGameOver()
{
	gameOver = true;
}

bool GameManager::hasEnded()
{
	return gameOver;
}
