#pragma once
#include "Item.h"
class Container
{
public:
	Container() {};
	Container(string name, common_defs::tokens associatedToken);
	
	string getName();
	string getDescription();
	common_defs::tokens getAssociatedToken();

	void insertItem(Item item);
	Item extractItem(common_defs::tokens item);
private:
	string name;
	common_defs::tokens associatedToken;
	list<Item> containedItems;
};

