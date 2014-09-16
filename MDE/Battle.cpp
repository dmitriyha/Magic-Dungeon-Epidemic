#include "Battle.h"

Battle::Battle(){
}

/** \brief For now, only the sword method is being used, regardless of the weapon
 *	
 *  The primary attribute goes as it it towards the dice, 
 *  the secondary is divided by 5,
 *  and the tertiary by 15.
 *  Once that is done the, armor_deduction is still deducted from the sides of the dice.
 * 
 *
 * \param strength The primary attribute
 * \param dexterity The secondary attribute
 * \param stamina The tertiary attribute
 * \param dmg_nhancement The amount the maximum and minimum damage are increased by
 * \param armor_deduction The penalty the dice suffers
 * \return the calculated damage 
 *
 */     
// all of these are the same, but act as hints for the programmer 
int Battle::Sword(int strength, int dexterity, int stamina, int dmg_nhancement, int armor_deduction){
	RNG random;
	int dice=strength+(dexterity/5)+(stamina/15)-armor_deduction;					//the primary secondary and tertiary traits for this attack determine the max possible roll
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));				//rolls the 'die' to give the damage dealt
	return damage;
}

int Battle::Mace(int strength, int stamina, int awareness,int dmg_nhancement){
	RNG random;
	int dice=strength+(stamina/5)+(awareness/15);
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));
	return damage;
}

int Battle::Bow(int dexterity, int awareness, int luck,int dmg_nhancement){ 
	RNG random;
	int dice=dexterity+(awareness/5)+(luck/15);
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));
	return damage;
}

int Battle::Crossbow(int dexterity, int stamina, int luck,int dmg_nhancement){
	RNG random;
	int dice=dexterity+(stamina/5)+(luck/15);
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));
	return damage;
}

int Battle::Spell(int wits, int sanity, int charisma,int dmg_nhancement){
	RNG random;
	int dice=wits+(sanity/5)+(charisma/15);
	if(dmg_nhancement >= dice){
		return dice;
	}
	int damage=random.generate(dmg_nhancement,(dice+1-dmg_nhancement));
	return damage;
}

Battle::~Battle(){
}
