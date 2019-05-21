#include "pch.h"
#include "ItemFactory.h"


Item ItemFactory::createCursedApple() {
	Item cursedApple("cursed apple", common_defs::CURSED_APPLE);
	cursedApple.setDescription("A mysterious apple. Eating it does not seems the best thing to do.");
	return cursedApple;
}

Item ItemFactory::createBlessedApple() {
	Item blessedApple("blessed apple", common_defs::BLESSED_APPLE);
	blessedApple.setDescription("An apple blessed by heavens. It proves the purity of its owner.");
	return blessedApple;
}


Item ItemFactory::createKey() {
	Item key("key", common_defs::KEY);
	key.setDescription("A golden key. It can be used to open locked doors.");
	return key;
}

Item ItemFactory::createDragonsHeart() {
	Item heart("dragon's heart", common_defs::DRAGONS_HEART);
	heart.setDescription("Heart of the master of the Greatest Dungeon. It proves the bravery of its owner.");
	return heart;
}
