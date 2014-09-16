#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <cstdlib>
#include <chrono>
#include "RNG.h"
#include "Character.h"
using namespace std;

/** \brief Used by both the player and the enemies to do damage to one another
 *
 */     


class Battle{
	
public: 
	Battle();
	static int Sword(int strength, int dexterity, int stamina,int dmg_nhancement,int armor_deduction);
	static int Mace(int strength, int stamina, int awareness,int dmg_nhancement);
	static int Bow(int dexterity, int awareness, int luck,int dmg_nhancement);
	static int Crossbow(int dexterity, int stamina, int luck, int dmg_nhancement);
	static int Spell(int wits, int sanity, int charisma, int dmg_nhancement);
	
	~Battle();
};
#endif
