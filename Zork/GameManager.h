#pragma once
class GameManager
{
public:

	static GameManager &instance()
	{
		static GameManager instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	};

	void startGame();
	void endGame();
	bool hasEnded();
	void setGameOver(bool deadPlayer);

private:
	bool playerIsDead;
	bool gameOver;
};

