#include "pch.h"
#include "WeaponFactory.h"


Weapon WeaponFactory::createKnife() {
	Weapon knife("knife", common_defs::KNIFE, 1);
	knife.setDescription("An rusty knife. Stick enemies with the pointy end.\nATTACK POWER: 1");

	return knife;
}

Weapon WeaponFactory::createBow() {
	Weapon bow("bow", common_defs::BOW, 2);
	bow.setDescription("An elven bow. It's said that arrows fired by this bow can fly over a kilometer away.\nATTACK POWER: 2");

	return bow;
}

Weapon WeaponFactory::createSword() {
	Weapon sword("magic sword", common_defs::SWORD, 42);
	sword.setDescription("The legendary magic sword Naratia. It was belived to be lost in the Great War.\nATTACK POWER: 42");

	return sword;
}
