#include "Battle.h"

Battle::Battle(){
}

// all of these are the same, but act as hints for the programmer 
int Battle::Sword(int strength, int dexterity, int stamina, int dmg_nhancement, int armor_deduction){
	int dice=strength+(dexterity/5)+(stamina/15)-armor_deduction;					//the primary secondary and tertiary traits for this attack determine the max possible roll
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));				//rolls the 'die' to give the damage dealt
	return damage;
}

int Battle::Mace(int strength, int stamina, int awareness,int dmg_nhancement){
	int dice=strength+(stamina/5)+(awareness/15);
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));
	return damage;
}

int Battle::Bow(int dexterity, int awareness, int luck,int dmg_nhancement){ 
	int dice=dexterity+(awareness/5)+(luck/15);
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));
	return damage;
}

int Battle::Crossbow(int dexterity, int stamina, int luck,int dmg_nhancement){
	int dice=dexterity+(stamina/5)+(luck/15);
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));
	return damage;
}

int Battle::Spell(int wits, int sanity, int charisma,int dmg_nhancement){
	int dice=wits+(sanity/5)+(charisma/15);
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));
	return damage;
}

Battle::~Battle(){
}
