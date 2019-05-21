#pragma once
#include "Enemy.h"
static class EnemyFactory
{
public:
	static Enemy createWolf();
	static Enemy createElf();
	static Enemy createDragon();
};

