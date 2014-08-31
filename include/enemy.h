#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "Character.h"
using namespace std;

class Enemy : public Character{
	///the level of the Enemy
	int level;
	
	public:
		//Enemy() : Character();
		void set_level(int level);
		int get_level();
};

#endif
