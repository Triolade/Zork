#include "pch.h"
#include "RoomFactory.h"
#include "WeaponFactory.h"
#include "EnemyFactory.h"
#include "ItemFactory.h"
#include "Container.h"
#include "SphinxAction.h"
#include "EndingAction.h"

Room RoomFactory::createDungeonEntrance() {
	Room dungeonEntrance("Dungeon Entrance");
	dungeonEntrance.setDescription("A big dungeon entrance stands in front of you.");
	return dungeonEntrance;
}

Room RoomFactory::createDungeonHall() {
	Room dungeonHall("Dungeon Hall");
	dungeonHall.setDescription("You are in the dungeon hall. Two torches emit a dimming light.\nYou can see doors in all directions.");
	dungeonHall.putWeapon(WeaponFactory::createKnife());
	return dungeonHall;
}

Room RoomFactory::createWolfDen() {
	Room wolfDen("Wolf's Den");
	wolfDen.setDescription("The smell of decomposition indicates that this is the den of a wild animal.\nThere are scratches all over the walls, and fur of dead rabbits everywhere.");
	wolfDen.spawnEnemy(EnemyFactory::createWolf());
	return wolfDen;
}

Room RoomFactory::createCursedAppleTree() {
	Room cursedAppleTree("Cursed Apple Tree");
	cursedAppleTree.setDescription("A mysterious apple tree grows surronded by fog.\nYou can sense a presence observing you.");
	cursedAppleTree.putItem(ItemFactory::createCursedApple());
	return cursedAppleTree;
}

Room RoomFactory::createDarkRoom() {
	Room darkRoom("Dark Room");
	darkRoom.setDescription("The room is inmersed in absolute darkness. It's pitch black in here.");
	return darkRoom;
}

Room RoomFactory::createSphinxTrial() {
	Room sphinxTrial("Sphinx Trial");
	sphinxTrial.setDescription("An enormous sphinx fullfils the room. It is looking directly at your soul.");
	sphinxTrial.setTriggeredEvent(new SphinxAction());
	return sphinxTrial;
}

Room RoomFactory::createElfCamp() {
	Room elfCamp("Elf Camp");
	elfCamp.setDescription("Elves from the deep forest established their new home in the dungeon centuries ago.\nThere is no trace left of their well-known kindness.");
	Enemy elf = EnemyFactory::createElf();
	elfCamp.spawnEnemy(elf);
	return elfCamp;
}

Room RoomFactory::createElfChurch() {
	Room elfChurch("Elf Church");
	elfChurch.setDescription("Room dedicated to the deity of the elves, the great dragon.\nThere is a statue to venerate it.");
	Weapon bow = WeaponFactory::createBow();
	elfChurch.putWeapon(bow);
	Container chalice("chalice", common_defs::CHALICE);
	elfChurch.putContainer(chalice);
	return elfChurch;
}

Room RoomFactory::createDragonsLair() {
	Room dragonsLair("Dragon's Lair");
	dragonsLair.setDescription("The master of the Great Dungeon stands in front of you. There is door behind it.\nThis is your last trial.");
	Enemy dragon = EnemyFactory::createDragon();
	dragonsLair.spawnEnemy(dragon);
	return dragonsLair;
}

Room RoomFactory::createEndRoom() {
	Room end("The End");
	end.setDescription("A voice resonates all across the room:\nHere you will be judged.");
	end.setTriggeredEvent(new EndingAction());
	return end;
}
