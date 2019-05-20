#pragma once
class Item
{
public:
	Item(string name, common_defs::tokens token);

	string getName();
	common_defs::tokens getAssociatedToken();

	string getDescription();
	void setDescription(string description);

private:
	string name;
	string description;

	common_defs::tokens associatedToken;
};

