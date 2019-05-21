#pragma once
#include "Item.h"
#include "Weapon.h"
#include "Enemy.h"

class Room
{
public:
	struct Connection {
		Connection() {};
		Connection(string description, Room* adjacentRoom, bool accessible, bool canBeOpened) {
			this->description = description;
			this->adjacentRoom = adjacentRoom;
			this->accessible = accessible;
			this->canBeOpened = canBeOpened;
		}

		string description;
		Room* adjacentRoom;
		
		bool accessible;
		bool canBeOpened;
	};

	Room();
	Room(string name);

	void setConnections(map<common_defs::tokens, Connection> connections);
	bool isAccessibleConnection(common_defs::tokens direction);
	string getDirectionInfo(common_defs::tokens direction);
	Room* getRoomInDirection(common_defs::tokens direction);

	bool hasLockedDoor();
	void openLockedDoor();

	string getDescription();
	void setDescription(string description);

	void putItem(Item item);
	Item takeItem(common_defs::tokens item);
	bool containsItem(common_defs::tokens item);

	void putWeapon(Weapon weapon);
	Weapon takeWeapon(common_defs::tokens weapon);
	bool containsWeapon(common_defs::tokens weapon);

	bool containsEnemy(common_defs::tokens enemy);
	Enemy getEnemy(common_defs::tokens enemy);
	void spawnEnemy(Enemy enemy);
	void killEnemy(common_defs::tokens enemy);
	void dropEnemyLoot(common_defs::tokens enemy);


private:
	string name;
	string description;

	map<common_defs::tokens, Connection> connections;

	list<Item> items;
	list<Weapon> weapons;
	list<Enemy> enemies;

	string getRandomLocator();

};

