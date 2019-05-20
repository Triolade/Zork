#pragma once
#include "Room.h"
#include "Player.h"

class World
{
public:
	static World &instance()
	{
		static World instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	};

	void initWorld();

private:
	enum room {
		FORGOTTEN_ROOM,
		NORTH_CORRIDOR_2ND_FLOOR
	};

	map<room, Room> rooms;

	void spawnRooms();
	void spawnConnections();
	void spawnItems();
	void spawnZombies();
	void spawnPlayer();
};

