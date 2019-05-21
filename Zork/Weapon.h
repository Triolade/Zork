#pragma once
class Weapon 
{
public:
	Weapon() {};
	Weapon(string name, common_defs::tokens token, int attack);
	~Weapon();

	string getName();
	common_defs::tokens getAssociatedToken();

	string getDescription();
	void setDescription(string description);
	int getAttack();

private:
	string name;
	string description;

	common_defs::tokens associatedToken;
	int attack;
};

