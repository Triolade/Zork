#pragma once
#include "Room.h"
#include "Item.h"
#include "Weapon.h"

class Player
{
public:
	static Player &instance()
	{
		static Player instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	};

	void spawnPlayer();

	string lookAround();
	bool canGoToDirection(common_defs::tokens direction);
	string lookAtDirection(common_defs::tokens direction);
	void moveToDirection(common_defs::tokens direction);
	void moveToRoom(Room* nextRoom);

	bool canFindItem(common_defs::tokens item);
	string pickItem(common_defs::tokens item);

	bool isInInventory(common_defs::tokens item);
	string dropItem(common_defs::tokens item);

	string describeSelf();
	string describeItemFromInventory(common_defs::tokens item);

	bool currentWeaponIs(common_defs::tokens weapon);
	bool hasWeaponEquipped();
	void dropCurrentWeapon();
	string pickWeapon(common_defs::tokens weapon);
	
	bool canFindEnemy(common_defs::tokens item);
	string attack(common_defs::tokens enemy);


private:
	Room* currentRoom;
	list<Item> inventory;
	Weapon equippedWeapon;
	int lifeCounter;
	bool hasEquippedWeapon;
};

