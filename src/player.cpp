#include "player.h"

void Player::set_xp(int creature_level){
	if (level == creature_level){
		xp=xp+(10*level);
	}
	else if(level > creature_level){
		xp=xp+((10 * level)*(0.6/(level - creature_level)));
	}
	else {
		xp=xp+((10 * level)*(1 + (0.4*(creature_level - level))));
	}
	if (xp >= next_level){
		level++;
		lvl_points=2;
		xp=xp - next_level;
		//next_level = next_level + (10 * level *40); //next level xp calculated as previous requirement added to the product of this level's xp gained per kill multiplied by the amount bad guys to kill
		next_level= (10 * level *40);
	}
	//cout<<"Level: "<<level<<endl<<"xp: "<<xp<<endl;
}


int Player::get_level_progress(){
	float prog = ((float)xp / (float)next_level)*100;
	int progress = prog;
	return progress;
}

int Player::get_level(){
	return level;
}
