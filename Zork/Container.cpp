#include "pch.h"
#include "Container.h"


Container::Container(string name, common_defs::tokens associatedToken)
{
	this->name = name;
	this->associatedToken = associatedToken;
}

string Container::getName() {
	return name;
}

string Container::getDescription() {
	string description = "a";
	if (containedItems.size() == 0) {
		description = description + "n empty " + name + ".";
	}
	else {
		description = description + " " + name + ". It contains:";
		for (Item i : containedItems) {
			description = description + "\n- " + i.getName();
		}
	}

	return description;
} 

common_defs::tokens Container::getAssociatedToken() {
	return associatedToken;
}

void Container::insertItem(Item item) {
	containedItems.push_back(item);
}

Item Container::extractItem(common_defs::tokens item) {

	std::list<Item>::iterator it;
	for (it = containedItems.begin(); it != containedItems.end(); ++it) {
		if (it->getAssociatedToken() == item) {
			Item returnedItem = *it;
			containedItems.erase(it);
			return returnedItem;
		}
	}
}