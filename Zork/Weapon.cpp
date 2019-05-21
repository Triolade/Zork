#include "pch.h"
#include "Weapon.h"


Weapon::Weapon(string name, common_defs::tokens token, int attack) {
	this->name = name;
	associatedToken = token;
	this->attack = attack;
}


Weapon::~Weapon()
{
}

string Weapon::getName() {
	return name;
}

common_defs::tokens Weapon::getAssociatedToken() {
	return associatedToken;
}

string Weapon::getDescription() {
	return description;
}

void Weapon::setDescription(string description) {
	this->description = description;
}

int Weapon::getAttack() {
	return attack;
}
