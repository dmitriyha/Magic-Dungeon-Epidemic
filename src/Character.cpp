#include "Character.h"
#include "GlobalDef.h"


void Character::set_stats(int healths,int strengths,int dexteritys,int witss,int sanitys,int staminas,int charismas,int awarenesss,int lucks,int ID){
	health=healths;
	strength=strengths;
	dexterity=dexteritys;
	wits=witss;
	sanity=sanitys;
	stamina=staminas;
	charisma=charismas;
	awareness=awarenesss;
	luck=lucks;
	id=ID;
}

int Character::Health(void){
	return health;
}

bool Character::Health(int damage){
	health=health-damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

int Character::getID(){
	return id;
}

void Character::setCoords(int x,int y){
	coord[0]=x;
	coord[1]=y;
}

int* Character::getCoords(){
	return coord;
}

	
int Character::Strength(){
	return strength;
}

int Character::Dexterity(){
	return dexterity;
}

int Character::Wits(){
	return wits;
}

int Character::Sanity(){
	return sanity;
}

int Character::Stamina(){
	return stamina;
}

int Character::Charisma(){
	return charisma;
}

int Character::Awareness(){
	return awareness;
}

int Character::Luck(){
	return luck;
}

Character::~Character(){
}
