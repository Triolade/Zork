#include "pch.h"
#include "Player.h"


string Player::lookAround() {
	return currentRoom->getDescription();
}

bool Player::canGoToDirection(common_defs::tokens direction) {
	return currentRoom->getDirectionInfo(direction) == "";
}

string Player::lookAtDirection(common_defs::tokens direction) {
	return currentRoom->getDirectionInfo(direction);
}

void Player::moveToDirection(common_defs::tokens direction) {
	moveToRoom(currentRoom->getRoomInDirection(direction));
}

void Player::moveToRoom(Room* nextRoom) {
	// TODO: Possible memory leak? Need to check
	currentRoom = nextRoom; 
}

bool Player::canFindItem(common_defs::tokens item) {
	return currentRoom->containsItem(item);
}

string Player::pickItem(common_defs::tokens item) {
	Item pickedItem = currentRoom->takeItem(item);
	inventory.push_back(pickedItem);

	return pickedItem.getName();
}

bool Player::isInInventory(common_defs::tokens item) {
	for (Item i : inventory) {
		if (i.getAssociatedToken() == item) {
			return true;
		}
	}
	return false;
}

string Player::dropItem(common_defs::tokens item) {
	std::list<Item>::iterator it;
	for (it = inventory.begin(); it != inventory.end(); ++it) {
		if (it->getAssociatedToken() == item) {
			Item droppedItem = *it;
			currentRoom->putItem(droppedItem);
			inventory.erase(it);
			return droppedItem.getName();
		}
	}

	throw "Item not found in inventory, this should never happen.";
}

string Player::describeInventory() {
	if (inventory.size() == 0) {
		return "Your inventory is empty.";
	}

	string inventoryDescription = "Your bag contains:";
	for (Item i : inventory) {
		inventoryDescription = inventoryDescription + "\n- " + i.getName();
	}

	return inventoryDescription;
}

string Player::describeItemFromInventory(common_defs::tokens item) {
	std::list<Item>::iterator it;
	for (it = inventory.begin(); it != inventory.end(); ++it) {
		if (it->getAssociatedToken() == item) {
			return it->getDescription();
		}
	}

	throw "Item not found in inventory, this should never happen.";

}