#pragma once
#include "Action.h"
#include "pch.h"

class InputManager
{
public:
	static InputManager &instance()
	{
		static InputManager instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	};

	Action* getActionFromInput();

private:
	struct InvalidInputException : public exception {
		const char * what() const throw () {
			return "Invalid input.";
		}
	};

	vector<common_defs::tokens> tokenize(string input);
	bool isValidToken(string token);

	map<string, common_defs::tokens> tokens_mapping = {
		// ACTIONS
		{"ATTACK", common_defs::ATTACK},
		{"CHECK", common_defs::CHECK},
		{"DROP", common_defs::DROP},
		{"GO", common_defs::GO},
		{"HELP", common_defs::HELP},
		{"SELF", common_defs::INVENTORY},
		{"LOOK", common_defs::LOOK},
		{"OPEN", common_defs::OPEN},
		{"PUT", common_defs::PUT},
		{"TAKE", common_defs::TAKE},
		{"PICK", common_defs::TAKE},


		// DIRECTIONS
		{"NORTH", common_defs::NORTH},
		{"SOUTH", common_defs::SOUTH},
		{"EAST", common_defs::EAST},
		{"WEST", common_defs::WEST},

		// ITEMS
		{"HEART", common_defs::DRAGONS_HEART},
		{"KEY", common_defs::KEY},
		{"APPLE", common_defs::CURSED_APPLE},

		// CONTAINERS
		{"CHALICE", common_defs::CHALICE},

		// WEAPONS
		{"SWORD", common_defs::SWORD},
		{"BOW", common_defs::BOW},
		{"KNIFE", common_defs::KNIFE},

		// ENEMIES
		{"WOLF", common_defs::WOLF},
		{"ELF", common_defs::ELF},
		{"DRAGON", common_defs::DRAGON},

		// CONNECTORS
		{"DOOR", common_defs::DOOR},
		{"INTO", common_defs::INTO}
	};


};

