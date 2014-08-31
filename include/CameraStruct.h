#ifndef CAMERASTRUCT_H
#define CAMERASTRUCT_H
#include "MapDataStructs.h"

/** \brief contains the data required to render the map
 */     


struct MapStruct{
	/// the 2d array with the player location
	int* playerLoc;
	/// the 2d array with the location of the up stairs
	int* stairsUp;
	/// the 2d array with the down stairs
	int* stairsDown;
	///contains the data of the map
	MapData mapData;
	///contains the data of the enemies
	EntityData entityData;
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
	MapStruct mapStruct;
	InventoryStruct inventoryStruct;
	UserInterfaceStruct userInterfaceStruct;
};


#endif // CAMERASTRUCT_H
