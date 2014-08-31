#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;

/** \brief the base class of Player and Enemy
 */     


class Character{
protected:
	int health;
	
	int strength;
	int dexterity;
	int wits;
	int sanity;
	int stamina;
	int charisma;
	int awareness;
	int luck;
	int id;
	
	int coord[2];
public: 
	void set_stats(int healths,int strengths,int dexteritys,int witss,int sanitys,int staminas,int charismas,int awarenesss,int lucks,int ID);
	
	int Health(void);
	bool Health(int);
	
	int getID();
	
	void setCoords(int,int);
	int* getCoords();
	
	int Strength();
	int Dexterity();
	int Wits();
	int Sanity();
	int Stamina();
	int Charisma();
	int Awareness();
	int Luck();
	
	~Character();
};
#endif
