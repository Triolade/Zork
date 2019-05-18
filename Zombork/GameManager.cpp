#include "pch.h"
#include "GameManager.h"


void GameManager::setGameOver()
{
	gameOver = true;
}


bool GameManager::hasEnded()
{
	return gameOver;
}
