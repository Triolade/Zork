#include "pch.h"
#include "World.h"
#include "RoomFactory.h"

void World::initWorld() {
	spawnRooms();
	spawnConnections();
	spawnPlayer();
}

void World::spawnRooms() {
	rooms = map<room, Room>();
	
	rooms[DUNGEON_ENTRANCE] = RoomFactory::createDungeonEntrance();
	rooms[DUNGEON_HALL] = RoomFactory::createDungeonHall();
	rooms[WOLF_DEN] = RoomFactory::createWolfDen();
	rooms[CURSED_APPLE_TREE] = RoomFactory::createCursedAppleTree();
	rooms[DARK_ROOM] = RoomFactory::createDarkRoom();
	rooms[SPHINX_TRIAL] = RoomFactory::createSphinxTrial();
	rooms[ELF_CAMP] = RoomFactory::createElfCamp();
	rooms[ELF_CHURCH] = RoomFactory::createElfChurch();
	rooms[DRAGONS_LAIR] = RoomFactory::createDragonsLair();
	rooms[END] = RoomFactory::createEndRoom();
}

void World::spawnConnections() {
	// DUNGEON ENTRANCE
	map<common_defs::tokens, Room::Connection> dungeonEntranceConnections = {
		{common_defs::NORTH, Room::Connection("", &rooms[DUNGEON_HALL], true, false)},
		{common_defs::EAST, Room::Connection("There is an impenetrable forest.", NULL, false, false)},
		{common_defs::WEST, Room::Connection("There is an impenetrable forest.", NULL, false, false)},
		{common_defs::SOUTH, Room::Connection("There is a road leading to your natal home. You are not gonna return with empty hands.", NULL, false, false)},
	};
	rooms[DUNGEON_ENTRANCE].setConnections(dungeonEntranceConnections);


	// DUNGEON HALL
	map<common_defs::tokens, Room::Connection> dungeonHallConnections = {
		{common_defs::NORTH, Room::Connection("There is a locked door. It seems that it can be opened using a key.", &rooms[DARK_ROOM], false, true)},
		{common_defs::EAST, Room::Connection("", &rooms[CURSED_APPLE_TREE], true, false)},
		{common_defs::WEST, Room::Connection("", &rooms[WOLF_DEN], true, false)},
		{common_defs::SOUTH, Room::Connection("", &rooms[DUNGEON_ENTRANCE], true, false)},
	};
	rooms[DUNGEON_HALL].setConnections(dungeonHallConnections);


	// WOLF DEN
	map<common_defs::tokens, Room::Connection> wolfDenConnections = {
		{common_defs::NORTH, Room::Connection("A scratched wall stands in your way.", NULL, false, false)},
		{common_defs::EAST, Room::Connection("", &rooms[DUNGEON_HALL], true, false)},
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


	// DARK ROOM
	map<common_defs::tokens, Room::Connection> darkRoomConnections = {
		{common_defs::NORTH, Room::Connection("You bump into another closed door.", &rooms[SPHINX_TRIAL], false, true)},
		{common_defs::EAST, Room::Connection("", &rooms[ELF_CAMP], true, false)},
		{common_defs::WEST, Room::Connection("Your hands touch a cold wall. There is no way in this direction", NULL, false, false)},
		{common_defs::SOUTH, Room::Connection("", &rooms[DUNGEON_HALL], true, false)},
	};
	rooms[DARK_ROOM].setConnections(darkRoomConnections);

	// SPHINX TRIAL
	map<common_defs::tokens, Room::Connection> sphinxTrialConnections = {
		{common_defs::NORTH, Room::Connection("The body of the sphinx blocks the way.", NULL, false, false)},
		{common_defs::EAST, Room::Connection("The left wing of the sphinx blocks the way.", NULL, false, false)},
		{common_defs::WEST, Room::Connection("The right wing of the sphinx blocks the way.", NULL, false, false)},
		{common_defs::SOUTH, Room::Connection("", &rooms[DARK_ROOM], true, false)},
	};
	rooms[SPHINX_TRIAL].setConnections(sphinxTrialConnections);

	// ELF CAMP
	map<common_defs::tokens, Room::Connection> elfCampConnections = {
		{common_defs::NORTH, Room::Connection("", &rooms[ELF_CHURCH], true, false)},
		{common_defs::EAST, Room::Connection("Guardian elfs flank the road. They are not gonna let you pass.", NULL, false, false)},
		{common_defs::WEST, Room::Connection("", &rooms[DARK_ROOM], true, false)},
		{common_defs::SOUTH, Room::Connection("Guardian elfs flank the road. They are not gonna let you pass.", NULL, false, false)},
	};
	rooms[ELF_CAMP].setConnections(elfCampConnections);


	// ELF CHURCH
	map<common_defs::tokens, Room::Connection> elfChurchConnections = {
		{common_defs::NORTH, Room::Connection("", &rooms[DRAGONS_LAIR], true, false)},
		{common_defs::EAST, Room::Connection("You can read a inscription in the base of the statue: 'Only braves will find glory'.", NULL, false, false)},
		{common_defs::WEST, Room::Connection("You can read a inscription in the chalice: 'This chalice can purify the most terrible sins'.", NULL, false, false)},
		{common_defs::SOUTH, Room::Connection("", &rooms[ELF_CAMP], true, false)},
	};
	rooms[ELF_CHURCH].setConnections(elfChurchConnections);

	// DRAGONS LAIR
	map<common_defs::tokens, Room::Connection> dragonsLairConnections = {
		{common_defs::NORTH, Room::Connection("", &rooms[END], true, false)},
		{common_defs::EAST, Room::Connection("A bottomless pit lies next to your feet.", NULL, false, false)},
		{common_defs::WEST, Room::Connection("A bottomless pit lies next to your feet.", NULL, false, false)},
		{common_defs::SOUTH, Room::Connection("", &rooms[ELF_CHURCH], true, false)},
	};
	rooms[DRAGONS_LAIR].setConnections(dragonsLairConnections);
}


void World::spawnPlayer() {
	Player::instance().spawnPlayer();
	Player::instance().moveToRoom(&rooms[DUNGEON_ENTRANCE]);
}