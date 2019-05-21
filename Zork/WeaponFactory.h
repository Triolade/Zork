#pragma once
#include "Weapon.h"
static class WeaponFactory
{
public:
	static Weapon createKnife();
	static Weapon createBow();
	static Weapon createSword();
};

