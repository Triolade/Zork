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
	bool hasEnded();
	void setGameOver();

private:

	bool gameOver;
};
