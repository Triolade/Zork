#include "pch.h"
#include "Room.h"


Room::Room() {

}

Room::Room(string name) {
	this->name = name;
}

string Room::getDescription() {
	string extendedDescription = "--" + name + "--" + "\n" + description;
	for (Item i : items) {
		
		extendedDescription = extendedDescription + "\n" + getRandomLocator() + i.getName() + " here.";
	}
	for (Weapon w : weapons) {

		extendedDescription = extendedDescription + "\n" + getRandomLocator() + w.getName() + " here.";
	}
	for (Enemy e : enemies) {
		extendedDescription = extendedDescription + "\nA " + e.getName() + " looks at you menacingly.";
	}
	return extendedDescription;
}

void Room::setDescription(string description) {
	this->description = description;
}

void Room::putItem(Item item) {
	items.push_back(item);
}

void Room::putWeapon(Weapon w) {
	weapons.push_back(w);
}

Item Room::takeItem(common_defs::tokens item) {
	std::list<Item>::iterator it;
	for (it = items.begin(); it != items.end(); ++it) {
		if (it->getAssociatedToken() == item) {
			Item returnedItem = *it;
			items.erase(it);
			return returnedItem;
		}
	}
	
	throw "Item not found in room, this should never happen.";
}

Weapon Room::takeWeapon(common_defs::tokens weapon) {
	std::list<Weapon>::iterator it;
	for (it = weapons.begin(); it != weapons.end(); ++it) {
		if (it->getAssociatedToken() == weapon) {
			Weapon returnedItem = *it;
			weapons.erase(it);
			return returnedItem;
		}
	}

	throw "Item not found in room, this should never happen.";
}

bool Room::containsItem(common_defs::tokens item) {
	for (Item i : items) {
		if (i.getAssociatedToken() == item) {
			return true;
		}
	}
	return false;
}

bool Room::containsWeapon(common_defs::tokens weapon) {
	for (Weapon w : weapons) {
		if (w.getAssociatedToken() == weapon) {
			return true;
		}
	}
	return false;
}

string Room::getRandomLocator() {
	string locator;
	int randomNumber = rand() % 100 + 1;
	if (randomNumber < 50) {
		locator = "There is a ";
	}
	else {
		locator = "You can see a ";
	}
	return locator;
}

void Room::setConnections(map<common_defs::tokens, Connection> connections) {
	this->connections = connections;
}

bool Room::isAccessibleConnection(common_defs::tokens direction) {
	return connections[direction].accessible;
}

string Room::getDirectionInfo(common_defs::tokens direction) {
	return connections[direction].description;
}

Room* Room::getRoomInDirection(common_defs::tokens direction) {
	return connections[direction].adjacentRoom;
}

bool Room::containsEnemy(common_defs::tokens enemy) {
	for (Enemy e : enemies) {
		if (e.getAssociatedToken() == enemy) {
			return true;
		}
	}
	return false;
}

Enemy Room::getEnemy(common_defs::tokens enemy) {
	for (Enemy e : enemies) {
		if (e.getAssociatedToken() == enemy) {
			return e;
		}
	}
	throw "Enemy not found, this should never happen";
}

void Room::dropEnemyLoot(common_defs::tokens enemy) {
	for (Enemy e : enemies) {
		if (e.getAssociatedToken() == enemy) {
			list<Item> droppedItems = e.getLoot();

			for (Item i : droppedItems) {
				items.push_back(i);
			}

			return;
		}
	}
	throw "Enemy not found, this should never happen";
}

void Room::spawnEnemy(Enemy enemy) {
	enemies.push_back(enemy);
}

void Room::killEnemy(common_defs::tokens enemy) {
	std::list<Enemy>::iterator it;
	for (it = enemies.begin(); it != enemies.end(); ++it) {
		if (it->getAssociatedToken() == enemy) {
			enemies.erase(it);
			return;
		}
	}

	throw "Enemy not found, this should never happen";
}

bool Room::hasLockedDoor() {
	map<common_defs::tokens, Connection>::iterator it = connections.begin();
	for (pair<common_defs::tokens, Connection> conenction : connections) {
		if (conenction.second.canBeOpened) {
			return true;
		}
	}

	return false;
}

void Room::openLockedDoor() {
	map<common_defs::tokens, Connection>::iterator it = connections.begin();
	while (it != connections.end()) {
		if (it->second.canBeOpened) {
			it->second.canBeOpened = false;
			it->second.accessible = true;
			return;
		}
		++it;
	}
	throw "Locked connection not found, this should never happen.";
}