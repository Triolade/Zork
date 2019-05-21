#pragma once
#include "Item.h"

class Enemy
{
public:
	Enemy(string name, common_defs::tokens associatedToken, int defense);

	common_defs::tokens getAssociatedToken();

	string getName();
	int getDefense();
	list<Item> getLoot();
	void addLoot(Item i);

private:
	common_defs::tokens associatedToken;
	
	string name;
	int defense;
	list<Item> loot;
};

