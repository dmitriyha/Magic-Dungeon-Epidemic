#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "Character.h"
using namespace std;

/** \brief The Enemy entity, that contains all of the data relevant to it  
 *
 */     


class Enemy : public Character{
	///the level of the Enemy
	int level;
	
	public:
		//Enemy() : Character();
		void set_level(int level);
		int get_level();
};

#endif
