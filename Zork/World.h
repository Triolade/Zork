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
		DUNGEON_ENTRANCE,
		DUNGEON_HALL,
		WOLF_DEN,
		CURSED_APPLE_TREE,
		DARK_ROOM,
		SPHINX_TRIAL,
		ELF_CAMP,
		ELF_CHURCH,
		DRAGONS_LAIR,
		END
	};

	map<room, Room> rooms;

	void spawnRooms();
	void spawnConnections();
	void spawnPlayer();
};

