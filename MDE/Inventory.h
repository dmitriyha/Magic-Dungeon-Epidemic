#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include<deque>
#include <SDL.h>
#include"Item.h"
using namespace std;

/** \brief stores the data of, and co controls the inventory of the player
 */     


class Inventory{
	///the list if items in the inventory
	deque<Item> inventory;
	///the item in the main hand
	Item main_hand=Item(0);
	///the item in the off hand
	Item off_hand=Item(0);
	///the item on the chest
	Item chest=Item(0);
	///the item that was dropped
	Item dropped_Item=Item(0);
	///the current inventory place
	int inventory_cursor = 1;
	
public:
	Inventory();
	int inventory_control(int mode, int inventory_cursor);
	int storeItem(Item item);
	Item dropped_item();
	deque<Item> getList();
	deque<Item> equippedList();
	~Inventory();
private:
	void removeItem(int rmItem);
};
#endif
