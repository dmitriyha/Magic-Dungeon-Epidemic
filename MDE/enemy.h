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
	
	public:
		//Enemy() : Character();
		virtual void set_level(int level);
		virtual int get_level();
		virtual ~Enemy();
};

#endif
