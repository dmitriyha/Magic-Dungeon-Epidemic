#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <cstdlib>
#include <chrono>
#include "RNG.h"
#include "Character.h"
using namespace std;

class Battle{
	RNG random;
public: 
	Battle();
	int Sword(int strength, int dexterity, int stamina,int dmg_nhancement,int armor_deduction);
	int Mace(int strength, int stamina, int awareness,int dmg_nhancement);
	int Bow(int dexterity, int awareness, int luck,int dmg_nhancement);
	int Crossbow(int dexterity, int stamina, int luck,int dmg_nhancement);
	int Spell(int wits, int sanity, int charisma,int dmg_nhancement);
	
	~Battle();
};
#endif
