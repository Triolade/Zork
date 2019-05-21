#include "pch.h"
#include "EnemyFactory.h"
#include "ItemFactory.h"

Enemy EnemyFactory::createWolf() {
	Enemy wolf("wolf", common_defs::WOLF, 1);
	wolf.addLoot(ItemFactory::createKey());
	return wolf;
}

Enemy EnemyFactory::createElf() {
	Enemy elf("elf", common_defs::ELF, 2);
	elf.addLoot(ItemFactory::createKey());
	return elf;
}

Enemy EnemyFactory::createDragon() {
	Enemy dragon("dragon", common_defs::DRAGON, 3);
	dragon.addLoot(ItemFactory::createDragonsHeart());
	return dragon;
}