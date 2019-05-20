#pragma once
#include "Room.h"
#include "Item.h"

class Player
{
public:
	static Player &instance()
	{
		static Player instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	};

	string lookAround();
	bool canGoToDirection(common_defs::tokens direction);
	string lookAtDirection(common_defs::tokens direction);
	void moveToDirection(common_defs::tokens direction);
	void moveToRoom(Room* nextRoom);

	bool canFindItem(common_defs::tokens item);
	string pickItem(common_defs::tokens item);

	bool isInInventory(common_defs::tokens item);
	string dropItem(common_defs::tokens item);

	string describeInventory();
	string describeItemFromInventory(common_defs::tokens item);

private:
	Room* currentRoom;
	list<Item> inventory;

};

