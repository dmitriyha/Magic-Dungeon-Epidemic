#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <iostream>
using namespace std;

class Player : public Character{
protected:
	int xp=0;
	int level=1;
	int next_level=400;
	int lvl_points=0;
public:
	void set_xp(int creature_level);
	int get_level_progress();
	int get_level();
};

#endif
