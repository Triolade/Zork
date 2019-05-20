#pragma once
#include "Item.h"
#include "Zombi.h"

class Room
{
public:
	Room();
	Room(string name);

	void setConnections(map<common_defs::tokens, Room*> connectedRooms);
	void setConnectionsAvailability(map<common_defs::tokens, string> connectionAvailability);
	string getDirectionInfo(common_defs::tokens direction);
	Room* getRoomInDirection(common_defs::tokens direction);

	string getDescription();
	void setDescription(string description);

	void putItem(Item item);
	Item takeItem(common_defs::tokens item);
	bool containsItem(common_defs::tokens item);

private:
	string name;
	string description;

	map<common_defs::tokens, Room*> connectedRooms;
	map<common_defs::tokens, string> connectionAvailability;

	list<Item> items;
	list<Zombi> zombies;

	string getRandomLocator();

};

