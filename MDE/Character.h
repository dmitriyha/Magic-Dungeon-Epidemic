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

	
	virtual int fight(Character * character);

	virtual void set_stats(int healths,int strengths,int dexteritys,int witss,int sanitys,int staminas,int charismas,int awarenesss,int lucks,int ID);
	
	virtual int Health(void);
	virtual bool Health(int);
	
	virtual int getID();
	
	virtual void setCoords(int, int);
	virtual int* getCoords();
	
	virtual int Strength();
	virtual int Dexterity();
	virtual int Wits();
	virtual int Sanity();
	virtual int Stamina();
	virtual int Charisma();
	virtual int Awareness();
	virtual int Luck();
	
	virtual ~Character();
};
#endif
