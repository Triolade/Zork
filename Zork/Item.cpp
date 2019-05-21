#include "pch.h"
#include "Item.h"


Item::Item(string name, common_defs::tokens token) {
	this->name = name;
	associatedToken = token;
}

string Item::getName() {
	return name;
}

common_defs::tokens Item::getAssociatedToken() {
	return associatedToken;
}

string Item::getDescription() {
	return description;
}

void Item::setDescription(string description) {
	this->description = description;
}