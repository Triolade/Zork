#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(string name, common_defs::tokens associatedToken, int defense) {
	this->name = name;
	this->associatedToken = associatedToken;
	this->defense = defense;
}

common_defs::tokens Enemy::getAssociatedToken() {
	return associatedToken;
}

string Enemy::getName() {
	return name;
}

int Enemy::getDefense() {
	return defense;
}

list<Item> Enemy::getLoot() {
	return loot;
}

void Enemy::addLoot(Item i) {
	loot.push_back(i);
}
