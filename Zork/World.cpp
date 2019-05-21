#include "pch.h"
#include "World.h"


void World::initWorld() {
	spawnRooms();
	spawnConnections();
	spawnItems();
	spawnEnemies();
	spawnPlayer();
}

void World::spawnRooms() {
	rooms = map<room, Room>();

	// DUNGEON ENTRANCE
	Room dungeonEntrance("Dungeon Entrance");
	dungeonEntrance.setDescription("A big dungeon entrance stands in front of you.");
	rooms[DUNGEON_ENTRANCE] = dungeonEntrance;

	// DUNGEON HALL
	Room dungeonHall("Dungeon Hall");
	dungeonHall.setDescription("You are in the dungeon hall. Two torches emit a dimming light.\nYou can see doors in all directions.");
	rooms[DUNGEON_HALL] = dungeonHall;

	// WOLFS DEN
	Room wolfDen("Wolf's Den");
	wolfDen.setDescription("The smell of decomposition indicates that this is the den of a wild animal.\nThere are scratches all over the walls, and fur of dead rabbits everywhere.");
	rooms[WOLF_DEN] = wolfDen;

	// CURSED APPLE TREE
	Room cursedAppleTree("Cursed Apple Tree");
	cursedAppleTree.setDescription("A mysterious apple tree grows surronded by fog.\nYou can sense a presence observing you.");
	rooms[CURSED_APPLE_TREE] = cursedAppleTree;

}

void World::spawnConnections() {
	// DUNGEON ENTRANCE
	map<common_defs::tokens, Room::Connection> dungeonEntranceConnections = {
		{common_defs::NORTH, Room::Connection("", &rooms[DUNGEON_HALL], true, false)},
		{common_defs::EAST, Room::Connection("There is an impenetrable darkness.", NULL, false, false)},
		{common_defs::WEST, Room::Connection("There is an impenetrable darkness.", NULL, false, false)},
		{common_defs::SOUTH, Room::Connection("There is an impenetrable darkness.", NULL, false, false)},
	};
	rooms[DUNGEON_ENTRANCE].setConnections(dungeonEntranceConnections);


	// DUNGEON HALL
	map<common_defs::tokens, Room::Connection> dungeonHallConnections = {
		{common_defs::NORTH, Room::Connection("There is a locked door. It seems that it can be opened using a key.", &rooms[DUNGEON_HALL], false, true)},
		{common_defs::EAST, Room::Connection("",  &rooms[CURSED_APPLE_TREE], true, false)},
		{common_defs::WEST, Room::Connection("",  &rooms[WOLF_DEN], true, false)},
		{common_defs::SOUTH, Room::Connection("", &rooms[DUNGEON_ENTRANCE], true, false)},
	};
	rooms[DUNGEON_HALL].setConnections(dungeonHallConnections);


	// WOLF DEN
	map<common_defs::tokens, Room::Connection> wolfDenConnections = {
		{common_defs::NORTH, Room::Connection("A scratched wall stands in your way.", NULL, false, false)},
		{common_defs::EAST, Room::Connection("",  &rooms[DUNGEON_HALL], true, false)},
		{common_defs::WEST, Room::Connection("A scratched wall stands in your way.",  NULL, false, false)},
		{common_defs::SOUTH, Room::Connection("A scratched wall stands in your way.", NULL, false, false)},
	};
	rooms[WOLF_DEN].setConnections(wolfDenConnections);


	// CURSED APPLE TREE
	map<common_defs::tokens, Room::Connection> cursedAppleTreeConnections = {
		{common_defs::NORTH, Room::Connection("You cannot traspass the fog.", NULL, false, false)},
		{common_defs::EAST, Room::Connection("You cannot traspass the fog.", NULL, false, false)},
		{common_defs::WEST, Room::Connection("", &rooms[DUNGEON_HALL], true, false)},
		{common_defs::SOUTH, Room::Connection("You cannot traspass the fog.", NULL, false, false)},
	};
	rooms[CURSED_APPLE_TREE].setConnections(cursedAppleTreeConnections);	
}

void World::spawnItems() {
	// DUNGEON HALL
	Weapon knife("knife", common_defs::KNIFE, 1);
	knife.setDescription("An rusty knife. Stick enemies with the pointy end.\nATTACK POWER: 1");
	rooms[DUNGEON_HALL].putWeapon(knife);

	// CURSED APPLE TREE
	Item cursedApple("cursed apple", common_defs::CURSED_APPLE);
	cursedApple.setDescription("A mysterious apple. Eating it does not seems the best thing to do.");
	rooms[CURSED_APPLE_TREE].putItem(cursedApple);
}

void World::spawnEnemies() {
	// WOLF DEN
	Enemy wolf("wolf", common_defs::WOLF, 1);
	Item key("key", common_defs::KEY);
	wolf.addLoot(key);
	rooms[WOLF_DEN].spawnEnemy(wolf);
}

void World::spawnPlayer() {
	Player::instance().spawnPlayer();
	Player::instance().moveToRoom(&rooms[DUNGEON_ENTRANCE]);
}