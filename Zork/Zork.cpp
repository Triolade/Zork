#include "pch.h"
#include "GameManager.h"
#include "InputManager.h"
#include "OutputManager.h"

#include "Action.h"

int main() {
	GameManager::instance().startGame();

	while (!GameManager::instance().hasEnded()) {
		Action* introducedAction = InputManager::instance().getActionFromInput();
		introducedAction->execute();
		OutputManager::instance().printOutput(introducedAction->getGeneratedOutput());
		delete introducedAction;
		if (GameManager::instance().isEventPending()) {
			GameManager::instance().executePendingEvent();
		}
	}

	GameManager::instance().endGame();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
