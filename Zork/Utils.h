#pragma once
static class Utils
{
public:
	static vector<string> split(const string &s, char delimiter);

	static bool isDirection(const common_defs::tokens token);
	static bool isItem(const common_defs::tokens token);
	static bool isWeapon(const common_defs::tokens token);
;	static bool isAction(const common_defs::tokens token);
	static bool isEnemy(const common_defs::tokens token);

};
