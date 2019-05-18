#include "pch.h"
#include "Utils.h"



vector<string> Utils::split(const string &s, char delimiter) {
	stringstream ss(s);
	string item;
	vector<string> elems;
	while (getline(ss, item, delimiter)) {
		elems.push_back(std::move(item));
	}
	return elems;
}

bool Utils::isDirection(const common_defs::tokens token) {
	vector<common_defs::tokens> directions = {
		common_defs::NORTH,
		common_defs::SOUTH,
		common_defs::EAST,
		common_defs::WEST,
		common_defs::UP,
		common_defs::DOWN
	};

	return find(directions.begin(), directions.end(), token) != directions.end();
}

bool Utils::isItem(const common_defs::tokens token) {
	vector<common_defs::tokens> items = {
		common_defs::CURE,
		common_defs::DOOR,
		common_defs::REVOLVER
	};

	return find(items.begin(), items.end(), token) != items.end();
}

bool Utils::isAction(const common_defs::tokens token) {
	vector<common_defs::tokens> actions = {
		common_defs::ATTACK,
		common_defs::CHECK,
		common_defs::DROP,
		common_defs::GO,
		common_defs::HELP,
		common_defs::LOOK,
		common_defs::OPEN,
		common_defs::PUT,
		common_defs::TAKE
	};

	return find(actions.begin(), actions.end(), token) != actions.end();
}

bool Utils::isEntity(const common_defs::tokens token) {
	vector<common_defs::tokens> entities = {
		common_defs::ZOMBI
	};

	return find(entities.begin(), entities.end(), token) != entities.end();
}







