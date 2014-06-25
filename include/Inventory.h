#ifndef INVENTORY_H
#define INVENTORY_H

#include<iostream>
#include<deque>
#include <SDL2/SDL.h>
#include"Item.h"
using namespace std;

class Inventory{
	deque<Item> inventory;
	Item main_hand=Item(0);
	Item off_hand=Item(0);
	Item chest=Item(0);
	Item dropped_Item=Item(0);
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
