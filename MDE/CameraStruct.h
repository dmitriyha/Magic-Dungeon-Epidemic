#ifndef CAMERASTRUCT_H
#define CAMERASTRUCT_H
#include "MapDataStructs.h"
#include "player.h"
#include "BuildingStruct.h"

/** \brief contains the data required to render the map
 */     


struct MapStruct{
	/// the 2d array with the player location
	LocationCoordinates  playerLoc;
	/// the 2d array with the location of the up stairs
	LocationCoordinates  stairsUp;
	/// the 2d array with the down stairs
	LocationCoordinates  stairsDown;
	///contains the data of the map
	MapData mapData;
	///contains the data of the enemies
	EntityData entityData;
	///contains the data of the buildings
	EntityDataOfBuildings entityDataBuildings;
	///contains the data of the items
	ItemData itemData;
};

/** \brief the struct used to render the inventory
 */     


struct InventoryStruct{
	///the players inventory
	deque<Item> inventory;
	///the items on the player
	deque<Item> equippedItems;
	///the current location of the cursor in the inventory
	int inventory_cursor;
	///how the inventory should work
	bool inventoryMode;
};

/** \brief the struct used in the rendering of the user interface.
 */     


struct UserInterfaceStruct{
	/// the player object
	Player* player;
	///the damage inflicted on the player
	int playerDamage;
	///the damage inflicted by the player
	int enemyDamage;
};

/** \brief the struct used to render the whole screen. Used as a container for easier transportation
 *  Used as a container for easier transportation of data around the game
 */     


struct CameraStruct{
	MapStruct mapStruct[MAX_DEPTH];
	InventoryStruct inventoryStruct;
	UserInterfaceStruct userInterfaceStruct;
	BuildingData buildData;
	int leftCornerX;
	int leftCornerY;
	int currentLevel;
};


#endif // CAMERASTRUCT_H
