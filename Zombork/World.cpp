#include "pch.h"
#include "World.h"


void World::initWorld() {
	spawnRooms();
	spawnConnections();
	spawnItems();
	spawnZombies();
	spawnPlayer();
}

void World::spawnRooms() {
	rooms = map<room, Room>();

	// INITAL ROOM
	Room forgottenRoom("Forgotten Hospital Room");
	forgottenRoom.setDescription("There is a bed where you've been lying.");
	rooms[FORGOTTEN_ROOM] = forgottenRoom;

	// 2ND FLOOR NORTH CORRIDOR
	Room northCorridor2Floor("2nd Floor - North Corridor");
	northCorridor2Floor.setDescription(".");
	rooms[NORTH_CORRIDOR_2ND_FLOOR] = northCorridor2Floor;
}

void World::spawnConnections() {
	//INITIAL ROOM
	map<common_defs::tokens, Room*>  forgottenRoomConnections = {
		{common_defs::EAST, &rooms[NORTH_CORRIDOR_2ND_FLOOR]}
	};
	map<common_defs::tokens, string> forgottenRoomConnectionsAvailability = {
		{common_defs::NORTH, "Nope"},
		{common_defs::EAST, ""},
		{common_defs::WEST, "Nope"},
		{common_defs::SOUTH, "Nope"}
	};
	rooms[FORGOTTEN_ROOM].setConnections(forgottenRoomConnections);
	rooms[FORGOTTEN_ROOM].setConnectionsAvailability(forgottenRoomConnectionsAvailability);

	// 2ND FLOOR NORTH CORRIDOR
	map<common_defs::tokens, Room*>  northCorridor2FloorConnections = {
		{common_defs::WEST, &rooms[FORGOTTEN_ROOM]}
	};
	map<common_defs::tokens, string> northCorridor2FloorConnectionsAvailability = {
		{common_defs::NORTH, "Nope"},
		{common_defs::EAST, "Nope"},
		{common_defs::WEST, ""},
		{common_defs::SOUTH, "Nope"}
	};
	rooms[NORTH_CORRIDOR_2ND_FLOOR].setConnections(northCorridor2FloorConnections);
	rooms[NORTH_CORRIDOR_2ND_FLOOR].setConnectionsAvailability(northCorridor2FloorConnectionsAvailability);
}

void World::spawnItems() {
	// INITIAL ROOM
	Item casette("casette", common_defs::CASETTE);
	casette.setDescription("An old casette. Is empty.");
	rooms[FORGOTTEN_ROOM].putItem(casette);
}

void World::spawnZombies() {
}

void World::spawnPlayer() {
	Player::instance().moveToRoom(&rooms[FORGOTTEN_ROOM]);
}