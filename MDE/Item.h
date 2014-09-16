#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <SDL.h>
#include"ReadFile.h"
using namespace std;

/** \brief the item class, which has all the required data to function as an item
 */     


class Item{
	///the armor or damage enhancement, based on item type
	int itemStat;
	/// the item id of the item
	int ID;
	///the name of the item
	string name;
	/// the item description
	string description;
	///the maximum amount items of this type that can be stacked in the inventory
	int maxStack;
	///the type of the item
	string type;
public:
	Item(int id);
	int getItemStat();
	string Name();
	string Descriprion();
	int getID();
	string getType();
	~Item();
};
#endif
