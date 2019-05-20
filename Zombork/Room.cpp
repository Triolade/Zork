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
	return extendedDescription;
}

void Room::setDescription(string description) {
	this->description = description;
}

void Room::putItem(Item item) {
	items.push_back(item);
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

bool Room::containsItem(common_defs::tokens item) {
	for (Item i : items) {
		if (i.getAssociatedToken() == item) {
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

void Room::setConnections(map<common_defs::tokens, Room*> connectedRooms) {
	this->connectedRooms = connectedRooms;
}

void Room::setConnectionsAvailability(map<common_defs::tokens, string> connectionAvailability) {
	this->connectionAvailability = connectionAvailability;
}

string Room::getDirectionInfo(common_defs::tokens direction) {
	return connectionAvailability[direction];
}

Room* Room::getRoomInDirection(common_defs::tokens direction) {
	return connectedRooms[direction];
}

