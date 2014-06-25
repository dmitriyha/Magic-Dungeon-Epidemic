#ifndef CAMERASTRUCT_H
#define CAMERASTRUCT_H
#include "MapDataStructs.h"
struct MapStruct{
	int* playerLoc;
	int* stairsUp;
	int* stairsDown;
	MapData mapData;
	EntityData entityData;
	ItemData itemData;
};

struct InventoryStruct{
	deque<Item> inventory;
	deque<Item> equippedItems;
	int inventory_cursor;
	bool inventoryMode;
};

struct UserInterfaceStruct{
	Player* player;
	int playerDamage;
	int enemyDamage;
};

struct CameraStruct{
	MapStruct mapStruct;
	InventoryStruct inventoryStruct;
	UserInterfaceStruct userInterfaceStruct;
};


#endif // CAMERASTRUCT_H
