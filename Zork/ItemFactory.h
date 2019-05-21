#pragma once
#include "Item.h"
static class ItemFactory
{
public:
	static Item createCursedApple();
	static Item createBlessedApple();
	static Item createKey();
	static Item createDragonsHeart();
};

