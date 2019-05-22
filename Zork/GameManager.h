#pragma once
#include "Action.h"

class GameManager
{
public:
	enum end_game_reason {
		DEATH,
		GOOD_ENDING,
		BAD_ENDING,
		PURE_ENDING,
		BRAVE_ENDING
	};

	static GameManager &instance()
	{
		static GameManager instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	};

	void startGame();
	void endGame();
	bool hasEnded();
	void triggerGameEnding(end_game_reason reason);


	bool isEventPending();
	void executePendingEvent();
	void setTriggeredEvent(Action *event);

private:
	end_game_reason reason;
	bool gameOver;
	
	Action *triggeredEvent;
};

