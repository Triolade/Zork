#pragma once
#include "Room.h"
static class RoomFactory
{
public:
	static Room createDungeonEntrance();
	static Room createDungeonHall();
	static Room createWolfDen();
	static Room createCursedAppleTree();
	static Room createDarkRoom();
	static Room createSphinxTrial();
	static Room createElfCamp();
	static Room createElfChurch();
	static Room createDragonsLair();
	static Room createEndRoom();
};

