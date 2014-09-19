#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "Character.h"
using namespace std;

/** \brief The Enemy entity, that contains all of the data relevant to it  
 *
 */     


class Enemy : public Character{
	protected:
		///the level of the Enemy
		int level;
		Item *weapon=new Item(0);
	
	public:
		Enemy();
		virtual void setPrimaryWeapon(Item* item);
		virtual void set_level(int level);
		virtual int get_level();
		virtual ~Enemy();
};

#endif
