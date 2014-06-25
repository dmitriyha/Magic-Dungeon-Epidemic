#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <SDL2/SDL.h>
#include"ReadFile.h"
using namespace std;

class Item{
	int itemStat;
	int ID;
	string name;
	string description;
	int maxStack;
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
